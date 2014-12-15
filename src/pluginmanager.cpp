#include "pluginmanager.h"

PluginManager::PluginManager()
{
  PluginManager::updatePlugins();
  if(this->getPlugins()->size()>0)
      this->currentPlugin= this->plugins->at(0);
  else
      this->currentPlugin=0;
}

QVector<Plugin*>* PluginManager::getPlugins()
{
    return this->plugins;
}

Plugin* PluginManager::getCurrentPlugin()
{
    return this->currentPlugin;
}

void PluginManager::setCurrentPlugin(int index)
{
	if(index >= 0 && index < this->plugins->size())
		this->currentPlugin = this->plugins->at(index);
}

void PluginManager::addPlugin(QDir* dir) {
    QDomDocument doc;
    QFile pluginXmlFile(dir->absolutePath()+QDir::separator()+"plugin.xml");
    if(!pluginXmlFile.exists()) {
        qDebug("error plugin.xml not exist "+dir->absolutePath().toUtf8());
        return;
    }
    pluginXmlFile.open(QIODevice::ReadOnly);
    doc.setContent(&pluginXmlFile);
    pluginXmlFile.close();
    QDomElement plugin = doc.documentElement();
    QString name = plugin.lastChildElement("name").text();
    QString version = plugin.lastChildElement("version").text();
    QString description = plugin.lastChildElement("description").text();
    QString cellBackground = dir->absolutePath()+QDir::separator()+plugin.lastChildElement("cellBackground").text();
    Plugin* p =  new Plugin(name, description,version);
    p->setCellBackground(cellBackground);
    qDebug("Plugin: "+name.toUtf8());
    QDomNodeList listPawns = plugin.lastChildElement("pawns").elementsByTagName("pawn");
    for(int i = 0;i < listPawns.count(); i++)
    {
        QString pid = listPawns.at(i).lastChildElement("id").text();
        QString pname = listPawns.at(i).lastChildElement("name").text();
        QString picon = dir->absolutePath()+QDir::separator()+listPawns.at(i).lastChildElement("icon").text();
        if(!p->existPawn(pid))
        {
            qDebug("  Pawn: "+pname.toUtf8()+" (id:"+pid.toUtf8()+", icon:"+picon.toUtf8()+")");
            Pawn* pawn =  new Pawn(pid, pname, picon);
            p->addPawn(pawn);
        }
        else
        {
            qDebug("  Pawn can't add");
        }
    }
    QDomNodeList listrules = plugin.lastChildElement("rules").elementsByTagName("rule");
    for(int i = 0;i < listrules.count(); i++)
    {
        QString from = listrules.at(i).attributes().namedItem("pawn").toAttr().value();
        QString to = listrules.at(i).attributes().namedItem("newPawn").toAttr().value();
        if(p->existPawn(from) && p->existPawn(to)) {
            Rule* r = new Rule(p->getPawn(from), p->getPawn(to));
            qDebug("  Rule: (from:"+from.toUtf8()+" to:"+to.toUtf8()+")");
            for(int j = 0;j < listrules.at(i).childNodes().count(); j++)
            {
                QString op = listrules.at(i).childNodes().at(j).nodeName();
                QString pawn = listrules.at(i).childNodes().at(j).attributes().namedItem("pawn").toAttr().value();
                QString value = listrules.at(i).childNodes().at(j).toElement().text();

                int intValue = value.toInt();
                AbstractOperator* o = NULL;
                if(op == "pawnNumberIsEqual")
                    o = new EqualOperator(intValue, pawn);
                if(op == "pawnNumberIsLower")
                    o = new LowerOperator(intValue, pawn);
                if(op == "pawnNumberIsGreater")
                    o = new GreaterOperator(intValue, pawn);

                if(o != NULL && p->existPawn(pawn))
                {
                    r->addOperator(o);
                    qDebug("    with "+pawn.toUtf8()+" "+op.toUtf8()+" "+value.toUtf8());
                }
                else
                {
                    qDebug("    Operator can't add");
                }

            }
            p->getPawn(from)->addRule(r);
        }
        else
        {
            qDebug("  Rule can't add");
        }
    }
    plugins->push_back(p);
}

void PluginManager::updatePlugins()
{
    this->plugins = new QVector<Plugin*>();
    QDir plugindir = QCoreApplication::applicationDirPath(); // current directory (build directory)
    #ifdef Q_OS_MAC
        plugindir=QCoreApplication::applicationDirPath()+"/../../.."; // to exit mac application package
    #endif
    QDir* dir = new QDir(plugindir.absolutePath()+QDir::separator()+"plugins");
    qDebug(dir->absolutePath().toUtf8());
    if (dir->exists())
    {
        QFileInfoList entries = dir->entryInfoList( QDir::Dirs | QDir::NoDotAndDotDot);
        foreach ( QFileInfo info, entries )
        {
            if (info.isDir()) {
                addPlugin(new QDir(info.absoluteFilePath()));
            }
        }
    }
    else
    {
        plugindir.mkdir("plugins");
    }

}
