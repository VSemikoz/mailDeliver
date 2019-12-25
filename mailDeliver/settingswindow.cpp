#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "QDir"

settingsWindow::settingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsWindow)
{
    checkBoxState = false;
    ui->setupUi(this);
}

settingsWindow::~settingsWindow()
{
    delete ui;
}

void settingsWindow::on_pushButton_clicked()
{
   //    QFile file("..//..//Settings.txt");
   QFile file("E://polovko/Settings.txt");
   if ((file.exists())&&(file.open(QIODevice::ReadOnly))){
       QString email = ui->lineEdit->text();
       QString pass = ui->lineEdit_2->text();
       QString smtp = ui->lineEdit_3->text();
       QString deleteAfterSending = getCheckboxState(checkBoxState);
       
       QString result = QString("%1\n %2\n %3\n DEFAULT_HEADER_TEXT NoReply\n %4\n BROWSE_TYPE DIRECTORY\n TIME_DELTA 5\n LOG_FILE_ATTACHED_FILES_SEPARATOR \n").arg(email, pass, smtp, deleteAfterSending);
      
       file.write(result.toUtf8());

       file.close();
   }   
}

void settingsWindow::on_pushButton_2_clicked()
{
    delete ui;
}

void settingsWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0) {
        checkBoxState = false;
    }
    else if (arg1 == 1) {
        checkBoxState = true;
    }
}

QString getCheckboxState(bool state) {
   if (state == false) {
       return "NO";
   }
   else if (state == true) {
       return "YES";
   }
}


