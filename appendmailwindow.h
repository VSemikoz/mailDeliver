#ifndef APPENDMAILWINDOW_H
#define APPENDMAILWINDOW_H

#include <QDialog>
#include <database.h>
#include <QDataWidgetMapper>
#include <QFileDialog>
#include <QTreeView>


namespace Ui {
class AppendMailWindow;
}

class AppendMailWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AppendMailWindow(DataBase *db, QMap<QString, QString> settingsMap, int index = -1, QWidget *parent = nullptr);
    ~AppendMailWindow();

signals:
    void signalMailUpdate();

private slots:
    void on_appendPushButton_clicked();
    void on_selectFilePushButton_clicked();
    void on_cancelPushButton_clicked();

    void on_appendGroupButton_clicked();

    void on_selectDateRadioButton_clicked();

    void on_selectDayOfWeekRadioButton_clicked();

private:
    Ui::AppendMailWindow *ui;
    DataBase *DataBaseConnection;
    QMap<QString, QString> settMap;
    QSqlTableModel  *model;
    QDataWidgetMapper *mapper;
    QStringList *incomeCategoryList;

    bool dateIsWeekDay;

    void setupModel();
    void setupUI();
    void setupMaper();
    bool checkTypeOfDate(int row);

    QStringList daysOfWeek = {"Понедельник",
                              "Вторник",
                              "Среда",
                              "Четверг",
                              "Пятница",
                              "Суббота",
                              "Воскресенье"};
};

#endif // APPENDMAILWINDOW_H
