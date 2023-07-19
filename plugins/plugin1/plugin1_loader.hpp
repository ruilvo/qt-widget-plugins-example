#pragma once

#include "plugin1.hpp"
#include "plugin_interface.hpp"

#include <QObject>

class Plugin1Loader final : public QObject, public qtwpe::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QTWPE_PluginInterface_iid)
    Q_INTERFACES(qtwpe::PluginInterface)

  public:
    Plugin1Loader(QObject *parent = nullptr) : QObject(parent){};
    ~Plugin1Loader() final = default;

    std::string getName() final
    {
        return "Plugin 1";
    }

    qtwpe::Plugin *createInstance(QObject *parent) final
    {
        return new Plugin1(parent);
    }
};
