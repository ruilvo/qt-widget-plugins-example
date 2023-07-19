#pragma once

#include "plugin2_widget.hpp"
#include "plugin_interface.hpp"

#include <QDebug>
#include <QObject>
#include <QPointer>

class Plugin2 final : public QObject, public qtwpe::Plugin
{
    Q_OBJECT
    Q_INTERFACES(qtwpe::Plugin)

  public:
    Plugin2(QObject *parent = nullptr) : QObject(parent), widget_{new Plugin2Widget()} {};
    ~Plugin2() final = default;

    QWidget *getWidget() final
    {
        return widget_;
    }

    void doWork() final
    {
        qDebug() << "Plugin 2 did some work!";
    };

  private:
    QPointer<Plugin2Widget> widget_;
};
