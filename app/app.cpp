#include "app.hpp"

#include <algorithm>

namespace qtwpe
{

App::App(QObject *parent)
    : QObject(parent), pluginLoader_{new PluginLoader(this)},
      pluginFactory_{new PluginFactory(pluginLoader_, this)}
{
}

QList<QString> App::getAvailablePlugins()
{
    const auto avPlugins = pluginFactory_->getAvailablePlugins();

    QList<QString> result;
    // NOLINTNEXTLINE(bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions)
    result.reserve(avPlugins.size());

    std::transform(avPlugins.begin(), avPlugins.end(), std::back_inserter(result),
                   [](auto elem) { return QString::fromStdString(elem); });

    return result;
}

QWidget *App::getCurrentPluginUi()
{
    if (auto *plugin = getCurrentPlugin())
    {
        return plugin->getWidget();
    }
    return nullptr;
}

bool App::doPluginWork()
{
    if (auto *plugin = getCurrentPlugin())
    {
        plugin->doWork();
        return true;
    }
    return false;
}

bool App::changePlugin(const QString &pluginName)
{

    if (auto *plugin = pluginFactory_->createPluginInstance(pluginName.toStdString()))
    {
        currentPlugin_->deleteLater();
        currentPlugin_ = dynamic_cast<QObject *>(plugin);
        return true;
    }
    return false;
}

Plugin *App::getCurrentPlugin()
{
    return qobject_cast<Plugin *>(currentPlugin_.get());
}

} // namespace qtwpe
