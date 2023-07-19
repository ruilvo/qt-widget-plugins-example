#pragma once

#include <QObject>
#include <QPluginLoader>

#include <vector>

namespace qtwpe
{

class PluginLoader : public QObject
{
    Q_OBJECT
  public:
    PluginLoader(QObject *parent = nullptr);

    template <typename T> std::vector<T *> getInterfacePlugins()
    {
        std::vector<T *> result;
        result.reserve(pluginLoaders_.size());

        for (auto &loader : pluginLoaders_)
        {
            if (auto *castedInstance{qobject_cast<T *>(loader->instance())})
            {
                result.push_back(castedInstance);
            }
        }
        return result;
    }

  private:
    std::vector<QPluginLoader *> pluginLoaders_;
};

} // namespace qtwpe
