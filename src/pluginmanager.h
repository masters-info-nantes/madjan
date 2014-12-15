#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QVector>
#include "plugin.h"
#include "abstractoperator.h"
#include "equaloperator.h"
#include "loweroperator.h"
#include "greateroperator.h"
#include <QDir>
#include <QDomDocument>
#include <QCoreApplication>

/**
 * @class PluginManager
 * @brief manage plugins
 */
class PluginManager
{
    /**
     * @brief List of plugins
     */
    QVector<Plugin*>* plugins;
    /**
     * @brief Current plugin
     */
    Plugin* currentPlugin;
public:
    /**
     * @brief Default constructor
     */
    PluginManager();
    /**
     * @brief getPlugins
     * @return plugin list
     */
    QVector<Plugin*>* getPlugins();
    /**
     * @brief getCurrentPlugin
     * @return plugin object
     */
    Plugin* getCurrentPlugin();
    /**
     * @brief getName
     * @param index : index of plugins list
     */
    void setCurrentPlugin(int index);
    /**
     * @brief updatePlugins
     */
    void updatePlugins();
    /**
     * @brief addPlugin
     * @param dir : plugin directory
     */
    void addPlugin(QDir* dir);
};

#endif // PLUGINMANAGER_H
