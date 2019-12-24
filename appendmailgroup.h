#ifndef APPENDMAILGROUP_H
#define APPENDMAILGROUP_H

#include <QDialog>
#include <database.h>
#include <QDataWidgetMapper>

namespace Ui {
class AppendMailGroup;
}

class AppendMailGroup : public QDialog
{
    Q_OBJECT

public:
    explicit AppendMailGroup(DataBase *db, int row = -1, QWidget *parent = nullptr);
    ~AppendMailGroup();
signals:
    void signalMailGroupUpdate();

private slots:
    void on_cancelButton_clicked();
    void on_appendMailButton_clicked();

private:
    Ui::AppendMailGroup *ui;
    DataBase *DataBaseConnection;
    QMap<QString, QString> settMap;
    QSqlTableModel  *model;
    QDataWidgetMapper *mapper;

    void setupModel();
};

#endif // APPENDMAILGROUP_H
