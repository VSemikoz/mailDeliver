#include "appendmailwindow.h"
#include "ui_appendmailwindow.h"

AppendMailWindow::AppendMailWindow(DataBase *db, QMap<QString, QString> settingsMap, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendMailWindow)
{
    DataBaseConnection = db;
    settMap = settingsMap;
    ui->setupUi(this);
    setupModel();
    dateIsWeekDay = checkTypeOfDate(row);
    setupUI();
    setupMaper();
    if (row == -1){
        model->insertRow(model->rowCount(QModelIndex()));
        mapper->toLast();
        ui->headerLineEdit->setText(settMap["DEFAULT_HEADER_TEXT"]);
    } else {
        mapper->setCurrentModelIndex(model->index(row,0));
    }

}

bool AppendMailWindow::checkTypeOfDate(int row){
    QString date = model->data(model->index(row,5)).toString();
    for(int i = 0; i < daysOfWeek.count(); i++){
         if(daysOfWeek[i] == date)
            return true;
    }
    return false;
}
void AppendMailWindow::setupUI(){

    QString spendingCategoryList = DataBaseConnection->getGroupsFromMailGroupTable();
    ui->dayOfWeekComboBox->addItems(daysOfWeek);
    ui->mailGroupComboBox->addItems(spendingCategoryList.split(','));
    ui->headerLineEdit->setText(settMap["DEFAULT_HEADER_TEXT"]);

    ui->dateEdit->setDate(QDate::currentDate());

    QString timeHourMinute = QString::number(QTime::currentTime().hour()) + '.' +
            QString::number(QTime::currentTime().minute());

    ui->timeEdit->setTime(QTime::fromString(timeHourMinute, "h.m"));

}

void AppendMailWindow::setupMaper(){
    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->mailGroupComboBox, 1);
    mapper->addMapping(ui->reciverLineEdit, 2);
    mapper->addMapping(ui->headerLineEdit, 3);
    mapper->addMapping(ui->bodyTextEdit, 4);

    if (dateIsWeekDay){
        ui->selectDayOfWeekRadioButton->setChecked(true);
        ui->dateEdit->setEnabled(false);
        ui->dayOfWeekComboBox->setEnabled(true);
        mapper->addMapping(ui->dayOfWeekComboBox, 5);
    }
    else{
        ui->selectDateRadioButton->setChecked(true);
        ui->dateEdit->setEnabled(true);
        ui->dayOfWeekComboBox->setEnabled(false);
        mapper->addMapping(ui->dateEdit, 5);
    }
    mapper->addMapping(ui->timeEdit, 6);
    mapper->addMapping(ui->fileNameLineEdit, 7);

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}
void AppendMailWindow::setupModel(){
    model = new QSqlTableModel(this);
    model->setTable("mail_table");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
}

AppendMailWindow::~AppendMailWindow(){
    delete ui;
}

void AppendMailWindow::on_appendPushButton_clicked()
{
    if (!ui->selectDateRadioButton->isChecked() and
        !ui->selectDayOfWeekRadioButton->isChecked()){
        ui->invalidInputLabel->setText("Выберите день отправления сообщения");
        return;
    }
    if (ui->reciverLineEdit->text() != "" and
        ui->headerLineEdit->text() != "" ){
    mapper->submit();
    model->submitAll();
    emit signalMailUpdate();
    this->close();
    } else {
        ui->invalidInputLabel->setText("Поля получателя и заголовока пусты");
    }
}

void AppendMailWindow::on_selectFilePushButton_clicked(){
    qDebug() << "BrowseType: " << settMap["BROWSE_TYPE"];
    if (settMap["BROWSE_TYPE"] == "FIL"){

        QStringList fileName = QFileDialog::getOpenFileNames(this,"Добавить файлы",settMap["DEFAULT_FILE_PATH"]);
        QString filesString = "";
        for (int i = 0; i < fileName.count(); i++)
            filesString += fileName[i] + ", ";
        filesString.chop(2);
        QString previusText = ui->fileNameLineEdit->text();
        if (previusText != "")
            ui->fileNameLineEdit->setText(previusText + ", " + filesString);
        else
            ui->fileNameLineEdit->setText(filesString);
    }

    else if (settMap["BROWSE_TYPE"] == "DIRECTOR"){
        //Create browse Window
        QFileDialog *w = new QFileDialog(this, "Добавить папки с файлами",settMap["DEFAULT_FILE_PATH"] );
        w->setFileMode(QFileDialog::DirectoryOnly);
        w->setOption(QFileDialog::DontUseNativeDialog,true);
        QListView *l = w->findChild<QListView*>("listView");
        if (l) {
             l->setSelectionMode(QAbstractItemView::MultiSelection);
         }
        QTreeView *t = w->findChild<QTreeView*>();
         if (t) {
           t->setSelectionMode(QAbstractItemView::MultiSelection);
       }
         //If browse windows exec and then click choose button
         if (w->exec())
         {
         QStringList fnames = w->selectedFiles();
         QString allDirPaths = "";
         for (int i = 0; i < fnames.count(); i++)
             allDirPaths += fnames[i] + ", ";
         allDirPaths.chop(2);
         //Update text on widjet
         QString previusText = ui->fileNameLineEdit->text();
         if (previusText != "")
             ui->fileNameLineEdit->setText(previusText + ", " + allDirPaths);
         else
             ui->fileNameLineEdit->setText(allDirPaths);
         }
    }
     else
         ui->label_4->setText("Не верное значение параметра BROWSE_TYPE (FILE, DIRECTORY)");
}



void AppendMailWindow::on_cancelPushButton_clicked(){
    this->~AppendMailWindow();
}

void AppendMailWindow::on_appendGroupButton_clicked(){
    auto list = DataBaseConnection->getMailListByGroup(ui->mailGroupComboBox->currentText());
    ui->reciverLineEdit->setText(list);
}

void AppendMailWindow::on_selectDateRadioButton_clicked(){
        ui->dateEdit->setEnabled(true);
        ui->dayOfWeekComboBox->setEnabled(false);
        mapper->addMapping(ui->dateEdit, 5);
}

void AppendMailWindow::on_selectDayOfWeekRadioButton_clicked(){
    ui->dateEdit->setEnabled(false);
    ui->dayOfWeekComboBox->setEnabled(true);
    mapper->addMapping(ui->dayOfWeekComboBox, 5);

}
