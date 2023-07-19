#pragma once

#include "plugin2.hpp"
#include "plugin_interface.hpp"

#include <QObject>

class Plugin2Loader final : public QObject, public qtwpe::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QTWPE_PluginInterface_iid)
    Q_INTERFACES(qtwpe::PluginInterface)

  public:
    Plugin2Loader(QObject *parent = nullptr) : QObject(parent){};
    ~Plugin2Loader() final = default;

    std::string getName() final
    {
        return "Plugin 2";
    }

    qtwpe::Plugin *createInstance(QObject *parent) final
    {
        return new Plugin2(parent);
    }
};
