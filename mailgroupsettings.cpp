#include "mailgroupsettings.h"
#include "ui_mailgroupsettings.h"

MailGroupSettings::MailGroupSettings(DataBase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MailGroupSettings){
    ui->setupUi(this);
    DataBaseConnection = db;
    setupModel(MAIL_GROUP_TABLE_NAME, MAIL_GROUP_TABLE_COLUMN_NAME);
    updateDataOnTables();
}

MailGroupSettings::~MailGroupSettings(){
    delete ui;
}

void MailGroupSettings::setupModel(const QString &tableName, const QStringList &headers){
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
            model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }

    model->setSort(0,Qt::AscendingOrder);
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditMailGroupRecord(QModelIndex)));
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotMailGroupMenuRequested(QPoint)));
}

void MailGroupSettings::slotEditMailGroupRecord(QModelIndex index){
    AppendMailGroup *addDeviceDialog = new AppendMailGroup(DataBaseConnection, index.row());
    addDeviceDialog->setWindowFlags (addDeviceDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(addDeviceDialog, SIGNAL(signalMailGroupUpdate()), this, SLOT(slotMailUpdateModels()));
    addDeviceDialog->setWindowTitle("Редактировать настройки");
    addDeviceDialog->exec();
}

void MailGroupSettings::slotMailGroupMenuRequested(QPoint pos){
    QMenu * menu = new QMenu(this);
    QAction * deleteDevice = new QAction("Удалить", this);
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecordFromSettings()));
    menu->addAction(deleteDevice);
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

void MailGroupSettings::slotRemoveRecordFromSettings(){
    int row = ui->tableView->selectionModel()->currentIndex().row();
     if(row >= 0){
        if (QMessageBox::warning(this,
                              "Удаление записи",
                              "Вы уверены, что хотите удалить эту запись?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){
                QSqlDatabase::database().rollback();
                return;
                } else {
                    if(!model->removeRow(row)){
                        QMessageBox::warning(this,"Уведомление",
                        "Не удалось удалить запись\n"
                        "Возможно она используется другими таблицами\n"
                        "Проверьте все зависимости и повторите попытку");
                    }
                        slotMailUpdateModels();
                        ui->tableView->setCurrentIndex(model->index(-1, -1));
         }
     }
}


void MailGroupSettings::resizeContent(){
     ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void MailGroupSettings::slotMailUpdateModels(){
    this->updateDataOnTables();
}


void MailGroupSettings::updateDataOnTables(){
    model->select();
    this->resizeContent();
}

void MailGroupSettings::on_AppendSettingsButton_clicked(){
    AppendMailGroup *addAppendMailDialog = new AppendMailGroup(DataBaseConnection);
    addAppendMailDialog->setWindowFlags (addAppendMailDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addAppendMailDialog->setModal(true);
    connect(addAppendMailDialog, SIGNAL(signalMailGroupUpdate()), this, SLOT(slotMailUpdateModels()));
    addAppendMailDialog->setWindowTitle("Добавить настройки групп");
    addAppendMailDialog->exec();
}

void MailGroupSettings::on_cancelButton_clicked(){
    this->~MailGroupSettings();
}
