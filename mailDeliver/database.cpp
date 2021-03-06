#include "database.h"

DataBase::DataBase(QMap<QString, QString> settingsMap, QObject *parent) : QObject(parent){

    settMap = settingsMap;
}

DataBase::~DataBase(){

}

void DataBase::connectToDataBase(){
    if(!QFile(settMap["DATABASE_LOCATION"]).exists()){
         this->restoreDataBase();
         qDebug() << "DataBase restored and conected";
    } else {
         this->openDataBase();
          qDebug() << "connection success";
    }
}

bool DataBase::restoreDataBase(){
    if(this->openDataBase()){
        if(!this->createTables()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
}

bool DataBase::openDataBase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(settMap["DATABASE_LOCATION"]);
    if (!db.open()){
        qDebug() << db.lastError().text();
        return false;
    } else {
        return true;
    }
}

void DataBase::closeDataBase(){
    db.close();
}


bool DataBase::createTables(){
    QSqlQuery query;
    if(query.exec(createMailTableQuery) ){
        qDebug() << "DataBase: error of create Tables";
        return true;
    } else {
        return false;
    }
}

QSqlQuery DataBase::getDataFromMailGroupTable(){
    QSqlQuery query;
    query.exec("SELECT * FROM mail_group_table");
    return query;
}

QMap<QString, QString>  DataBase::getMapFromQuery(){
    QSqlQuery query = getDataFromMailGroupTable();
    QMap<QString, QString> DataBaseMap;
    while (query.next()) {
        DataBaseMap[query.value(1).toString()] = query.value(2).toString();
    }
    return DataBaseMap;
}

QString  DataBase::getGroupsFromMailGroupTable(){
    return getMapFromQuery().keys().join(',');
}

QString  DataBase::getMailListByGroup(QString groupName){
    return getMapFromQuery().value(groupName);
}
