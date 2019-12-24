#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QDebug>
#include <database.h>
#include <appendmailwindow.h>
#include <mailgroupsettings.h>
#include <settings.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_updateButton_clicked();
    void slotEditMailRecord(QModelIndex index);
    void slotMailMenuRequested(QPoint pos);
    void slotMailUpdateModels();
    void slotRemoveRecordFromMail();

    void on_appendButton_clicked();
    void on_actionMailGroupSettings_triggered();

private:
    Ui::MainWindow *ui;
    Settings *settings;
    QMap<QString, QString> settingsMap;
    DataBase *db;
    QSqlTableModel *mailModel;

    void setupMailModel(const QString &tableName, const QStringList &headers);
    void updateDataOnTables();
    void resizeContent();

    const QString MAIL_TABLE_NAME = "mail_table";
    const QStringList MAIL_TABLE_COLUMN_NAME = {"ID",
                                                "Имя группы",
                                                "Получатель",
                                                "Заголовок",
                                                "Тело",
                                                "Дата",
                                                "Время",
                                                "Файл"};
};
#endif // MAINWINDOW_H
