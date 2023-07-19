#include "plugin_loader.hpp"

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QString>

namespace qtwpe
{

PluginLoader::PluginLoader(QObject *parent) : QObject{parent}
{
    // From https://doc.qt.io/qt-5/qtwidgets-tools-plugandpaint-app-example.html

    QDir pluginsDir{QCoreApplication::applicationDirPath()};
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
    pluginsDir.cd(QStringLiteral("plugins")); // Use the plugins folder for all plugins

    const auto entryList{// clazy:exclude=inefficient-qlist
                         pluginsDir.entryList(QDir::Files)};

    for (const QString &fileName : entryList)
    {
        auto *loader{new QPluginLoader(pluginsDir.absoluteFilePath(fileName), this)};

        QObject *plugin{loader->instance()};

        if (plugin == nullptr)
        {
            qDebug() << "Module " << fileName << " is not a module";
            if (loader->isLoaded())
            {
                loader->unload();
            }
            loader->deleteLater();

            continue;
        }

        pluginLoaders_.push_back(loader);
    }
}

} // namespace qtwpe
