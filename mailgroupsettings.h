#ifndef MAILGROUPSETTINGS_H
#define MAILGROUPSETTINGS_H

#include <QDialog>
#include <appendmailgroup.h>
#include <database.h>
#include <QDataWidgetMapper>
#include <QMessageBox>
#include <QMenu>


namespace Ui {
class MailGroupSettings;
}

class MailGroupSettings : public QDialog
{
    Q_OBJECT

public:
    explicit MailGroupSettings(DataBase *db ,QWidget *parent = nullptr);
    ~MailGroupSettings();

private slots:
    void on_AppendSettingsButton_clicked();
    void on_cancelButton_clicked();

    void slotEditMailGroupRecord(QModelIndex index);
    void slotMailGroupMenuRequested(QPoint pos);
    void slotMailUpdateModels();
    void slotRemoveRecordFromSettings();

private:
    Ui::MailGroupSettings *ui;
    DataBase *DataBaseConnection;
    QMap<QString, QString> settMap;
    QSqlTableModel  *model;
    QDataWidgetMapper *mapper;

    void setupModel(const QString &tableName, const QStringList &headers);
    void updateDataOnTables();
    void resizeContent();

    const QString MAIL_GROUP_TABLE_NAME = "mail_group_table";
    const QStringList MAIL_GROUP_TABLE_COLUMN_NAME ={   "ID",
                                                        "Название группы",
                                                        "Email адреса"};
};

#endif // MAILGROUPSETTINGS_H
