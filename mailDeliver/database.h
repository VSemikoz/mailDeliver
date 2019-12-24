#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QSqlTableModel>
#include "QtSql"
#include <QSqlQuery>
#include <QApplication>
#include <QString>
#include <settings.h>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QMap<QString, QString> settingsMap, QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();
    void closeDataBase();

    QSqlQuery getDataFromMailGroupTable();
    QMap<QString, QString> getMapFromQuery();
    QString getGroupsFromMailGroupTable();
    QString getMailListByGroup(QString groupName);

private:
    QSqlDatabase    db;
    QMap<QString, QString> settMap;

    const QString createMailTableQuery = "CREATE TABLE  mail_table  ("
                                            "ID INTEGER PRIMARY KEY NOT NULL UNIQUE,"
                                            "recipient TEXT    NOT NULL,"
                                            "header    TEXT    NOT NULL,"
                                            "body      TEXT,"
                                            "date      DATE    NOT NULL,"
                                            "time      TIME    NOT NULL,"
                                            "file_name TEXT)";

    const QString createMailGroupTableTableQuery = "CREATE TABLE  mail_group_table  ("
                                            "ID INTEGER PRIMARY KEY NOT NULL UNIQUE,"
                                            "group_name TEXT UNIQUE NOT NULL,"
                                            "mail_list    TEXT    NOT NULL)";


    bool openDataBase();
    bool restoreDataBase();
    bool createTables();


};

#endif

