#pragma once

#include "app.hpp"

#include <QComboBox>
#include <QPointer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

namespace qtwpe
{

class MainWindow final : public QWidget
{
    Q_OBJECT
  public:
    MainWindow(App *app, QWidget *parent = nullptr);
    ~MainWindow() final = default;

  private slots:
    void onPluginComboBoxIndexChanged(int idx);

  private: // NOLINT(readability-redundant-access-specifiers)
    QPointer<App> app_;
    QPointer<QPushButton> workerButton_;
    QPointer<QComboBox> pluginsComboBox_;
    QPointer<QVBoxLayout> layout_;

    bool isHostingWidget_{false};
};

} // namespace qtwpe
