#pragma once

#include "plugin_interface.hpp"
#include "plugin_loader.hpp"

#include <QObject>
#include <QPointer>

namespace qtwpe
{

class PluginFactory final : public QObject
{
    Q_OBJECT
  public:
    PluginFactory(PluginLoader *pluginLoader, QObject *parent = nullptr);
    ~PluginFactory() final = default;

    std::vector<std::string> getAvailablePlugins();
    Plugin *createPluginInstance(const std::string &pluginName,
                                 QObject *parent = nullptr);

  private:
    QPointer<PluginLoader> pluginLoader_{nullptr};
};

} // namespace qtwpe
