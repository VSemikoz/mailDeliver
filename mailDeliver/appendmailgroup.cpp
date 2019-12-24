#include "appendmailgroup.h"
#include "ui_appendmailgroup.h"

AppendMailGroup::AppendMailGroup(DataBase *db, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendMailGroup){
    DataBaseConnection = db;
    ui->setupUi(this);
    setupModel();
    if (row == -1){
        model->insertRow(model->rowCount(QModelIndex()));
        mapper->toLast();
    } else {
        mapper->setCurrentModelIndex(model->index(row,0));
    }
}


void AppendMailGroup::setupModel(){
    model = new QSqlTableModel(this);
    model->setTable("mail_group_table");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->groupNameLineEdit, 1);
    mapper->addMapping(ui->mailListPlainTextEdit, 2);


    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

AppendMailGroup::~AppendMailGroup(){
    delete ui;
}

void AppendMailGroup::on_cancelButton_clicked(){
    this->~AppendMailGroup();
}

void AppendMailGroup::on_appendMailButton_clicked(){
    if (ui->groupNameLineEdit->text() != ""){
    mapper->submit();
    model->submitAll();
    emit signalMailGroupUpdate();
    this->close();
    } else {
        ui->invalidInputLabel->setText("Название группы не может быть пустым");
    }
}
