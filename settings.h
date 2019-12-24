#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QFile>
#include <QMap>
#include <QDebug>
#include <QStringList>

class Settings
{
public:
    Settings();

    QMap<QString, QString> getSettingsList();

     QMap<QString, QString> settingsMap;
private:
    QMap<QString, QString> convertListToQMap(QString fileText);

};

#endif // SETTINGS_H
