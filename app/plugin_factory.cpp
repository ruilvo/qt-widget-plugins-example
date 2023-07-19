#include "plugin_factory.hpp"

#include <QDebug>

#include <stdexcept>

namespace qtwpe
{

PluginFactory::PluginFactory(PluginLoader *pluginLoader, QObject *parent)
    : QObject{parent}, pluginLoader_{pluginLoader}
{
}

std::vector<std::string> PluginFactory::getAvailablePlugins()
{
    if (pluginLoader_.isNull())
    {
        throw std::logic_error{"The plugin loader went out of scope!"};
    }
    auto plugins{pluginLoader_->getInterfacePlugins<PluginInterface>()};
    std::vector<std::string> result;
    result.reserve(plugins.size());
    for (auto *const plugin : plugins)
    {
        result.push_back(plugin->getName());
    }
    return result;
}

Plugin *PluginFactory::createPluginInstance(const std::string &pluginName,
                                            QObject *parent)
{
    if (pluginLoader_.isNull())
    {
        throw std::logic_error{"The plugin loader went out of scope!"};
    }
    auto devicePlugins{pluginLoader_->getInterfacePlugins<PluginInterface>()};
    for (auto *const plugin : devicePlugins)
    {
        if (plugin->getName() == pluginName)
        {
            return plugin->createInstance(parent);
        }
    }
    throw std::invalid_argument{"No device with that name was found"};
}

} // namespace qtwpe
