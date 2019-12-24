#include "settings.h"

Settings::Settings(){

}

QMap<QString, QString> Settings::getSettingsList(){
    QFile file("..//..//Settings.txt");
//    QFile file("D://mail/Settings.txt"); uncommit for debug

    if ((file.exists())&&(file.open(QIODevice::ReadOnly))){
        QString fileText =  file.readAll();
        file.close();
        return convertListToQMap(fileText);
    }
    else {
        qDebug() << "file Settings.txt not found";
    }
}

 QMap<QString, QString> Settings::convertListToQMap(QString fileText){
    QStringList fileTextList = fileText.split('\n');

    for (int i = 0; i < fileTextList.count(); i++){

        fileTextList[i].chop(1);}

    QMap<QString, QString> settingsMap;

    for (int i = 0; i < fileTextList.count(); i++){
        if (fileTextList[i].isEmpty())
            continue;
        QStringList settingStringList = fileTextList[i].split(' ');

        if (settingsMap[settingStringList[0]].isEmpty()){
            settingsMap[settingStringList[0]] = settingStringList[1];}

    }

    return settingsMap;
}
