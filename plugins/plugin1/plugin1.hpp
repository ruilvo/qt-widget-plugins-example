#pragma once

#include "plugin1_widget.hpp"
#include "plugin_interface.hpp"

#include <QDebug>
#include <QObject>
#include <QPointer>

class Plugin1 final : public QObject, public qtwpe::Plugin
{
    Q_OBJECT
    Q_INTERFACES(qtwpe::Plugin)

  public:
    Plugin1(QObject *parent = nullptr) : QObject(parent), widget_{new Plugin1Widget()} {};
    ~Plugin1() final = default;

    QWidget *getWidget() final
    {
        return widget_;
    }

    void doWork() final
    {
        qDebug() << "Plugin 1 did some work!";
    };

  private:
    QPointer<Plugin1Widget> widget_;
};
