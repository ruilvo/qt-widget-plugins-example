#pragma once

#include "plugin_factory.hpp"

#include <QList>
#include <QString>

namespace qtwpe
{

class App final : public QObject
{
    Q_OBJECT
  public:
    App(QObject *parent = nullptr);
    ~App() final = default;

    QList<QString> getAvailablePlugins();
    QWidget *getCurrentPluginUi();
    bool doPluginWork();
    bool changePlugin(const QString &pluginName);

  private:
    QPointer<PluginLoader> pluginLoader_;
    QPointer<PluginFactory> pluginFactory_;
    QPointer<QObject> currentPlugin_{nullptr};

    Plugin *getCurrentPlugin();
};

} // namespace qtwpe
