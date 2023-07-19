#pragma once

#include <QWidget>

namespace qtwpe
{

class Plugin
{
  public:
    Plugin() = default;
    Q_DISABLE_COPY_MOVE(Plugin)
    virtual ~Plugin() = default;

    virtual QWidget *getWidget() = 0;
    virtual void doWork() = 0;
};

class PluginInterface
{
  public:
    PluginInterface() = default;
    Q_DISABLE_COPY_MOVE(PluginInterface)
    virtual ~PluginInterface() = default;

    virtual std::string getName() = 0;
    virtual qtwpe::Plugin *createInstance(QObject *parent) = 0;
};

} // namespace qtwpe

#define QTWPE_Plugin_iid "com.qtwpe.plugin"
// NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
Q_DECLARE_INTERFACE(qtwpe::Plugin, QTWPE_Plugin_iid)

#define QTWPE_PluginInterface_iid "com.qtwpe.PluginInterface"
// NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
Q_DECLARE_INTERFACE(qtwpe::PluginInterface, QTWPE_PluginInterface_iid)
