#pragma once

#include <QLabel>
#include <QPointer>
#include <QVBoxLayout>
#include <QWidget>

class Plugin1Widget final : public QWidget
{
    Q_OBJECT
  public:
    Plugin1Widget(QWidget *parent = nullptr) : QWidget(parent)
    {
        setLayout(new QVBoxLayout());
        layout()->addWidget(new QLabel("Here is plugin 1!"));
        layout()->addWidget(new QLabel("Completely loaded at runtime!"));
        layout()->addWidget(new QLabel("I was created by my plugin"));
        layout()->addWidget(new QLabel("Because it needs to know my pointer"));
        layout()->addWidget(new QLabel("To connect signals and slots"));
    };
    ~Plugin1Widget() final = default;
};
