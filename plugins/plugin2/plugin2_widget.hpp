#pragma once

#include <QLabel>
#include <QPointer>
#include <QVBoxLayout>
#include <QWidget>

class Plugin2Widget final : public QWidget
{
    Q_OBJECT
  public:
    Plugin2Widget(QWidget *parent = nullptr) : QWidget(parent)
    {
        setLayout(new QVBoxLayout());
        layout()->addWidget(new QLabel("Here is plugin 2!"));
        layout()->addWidget(new QLabel("With another widget"));
        layout()->addWidget(new QLabel("Just to be different"));
    };
    ~Plugin2Widget() final = default;
};
