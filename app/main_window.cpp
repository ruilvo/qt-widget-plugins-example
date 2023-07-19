#include "main_window.hpp"

#include <QFormLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QString>
#include <QStringList>

namespace qtwpe
{

MainWindow::MainWindow(App *app, QWidget *parent)
    : QWidget(parent), app_{app},
      // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
      workerButton_{new QPushButton(QStringLiteral("Do plugin work"))},
      pluginsComboBox_{new QComboBox()}, layout_{new QVBoxLayout()}
{
    setMinimumWidth(1);

    layout_->addWidget(workerButton_);

    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    auto *form{new QFormLayout()};
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
    form->addRow(QStringLiteral("Plugin"), pluginsComboBox_);
    layout_->addItem(form);

    auto *bottomSpacer{new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding,
                                       QSizePolicy::MinimumExpanding)};
    layout_->addItem(bottomSpacer);

    setLayout(layout_);

    connect(pluginsComboBox_, QOverload<int>::of(&QComboBox::currentIndexChanged), //
            this, &MainWindow::onPluginComboBoxIndexChanged);

    pluginsComboBox_->blockSignals(true);
    pluginsComboBox_->addItems(app->getAvailablePlugins());
    pluginsComboBox_->setEnabled(pluginsComboBox_->count() > 1);
    pluginsComboBox_->blockSignals(false);
    if (pluginsComboBox_->count() > 0)
    {
        emit pluginsComboBox_->currentIndexChanged(pluginsComboBox_->currentIndex());
    }

    connect(workerButton_, &QPushButton::clicked, this, [this](bool checked) {
        Q_UNUSED(checked);
        app_->doPluginWork();
    });
}

void MainWindow::onPluginComboBoxIndexChanged(int idx)
{
    Q_UNUSED(idx)

    if (isHostingWidget_)
    {
        auto *widget = app_->getCurrentPluginUi();
        layout_->removeWidget(widget);
        widget->hide();
        widget->deleteLater();

        isHostingWidget_ = false;
    }

    auto result = app_->changePlugin(pluginsComboBox_->currentText());

    if (result)
    {
        layout_->insertWidget(layout_->count() - 1, app_->getCurrentPluginUi());
        isHostingWidget_ = true;
    }
}

} // namespace qtwpe
