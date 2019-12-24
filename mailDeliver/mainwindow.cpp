#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowTitle("Рассылка сообщений");
    settingsMap = settings->getSettingsList();
    db = new DataBase(settingsMap);

    db->connectToDataBase();

    setupMailModel(MAIL_TABLE_NAME, MAIL_TABLE_COLUMN_NAME);

    updateDataOnTables();

}

MainWindow::~MainWindow(){
    db->closeDataBase();
    delete ui;
}

void MainWindow::setupMailModel(const QString &tableName, const QStringList &headers){
    mailModel = new QSqlTableModel(this);
    mailModel->setTable(tableName);
    for(int i = 0, j = 0; i < mailModel->columnCount(); i++, j++){
            mailModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }

    mailModel->setSort(0,Qt::AscendingOrder);
    ui->tableView->setModel(mailModel);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditMailRecord(QModelIndex)));
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotMailMenuRequested(QPoint)));
}


void MainWindow::slotEditMailRecord(QModelIndex index){
    AppendMailWindow *addDeviceDialog = new AppendMailWindow(db, settingsMap, index.row());
    addDeviceDialog->setWindowFlags (addDeviceDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(addDeviceDialog, SIGNAL(signalMailUpdate()), this, SLOT(slotMailUpdateModels()));
    addDeviceDialog->setWindowTitle("Редактировать письмо");
    addDeviceDialog->exec();
}

void MainWindow::slotMailMenuRequested(QPoint pos){
    QMenu * menu = new QMenu(this);
    QAction * deleteDevice = new QAction("Удалить", this);
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecordFromMail()));
    menu->addAction(deleteDevice);
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

void MainWindow::slotRemoveRecordFromMail(){
    int row = ui->tableView->selectionModel()->currentIndex().row();
     if(row >= 0){
        if (QMessageBox::warning(this,
                              "Удаление записи",
                              "Вы уверены, что хотите удалить эту запись?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){
                QSqlDatabase::database().rollback();
                return;
                } else {
                    if(!mailModel->removeRow(row)){
                        QMessageBox::warning(this,"Уведомление",
                        "Не удалось удалить запись\n"
                        "Возможно она используется другими таблицами\n"
                        "Проверьте все зависимости и повторите попытку");
                    }
                        slotMailUpdateModels();
                        ui->tableView->setCurrentIndex(mailModel->index(-1, -1));
         }
     }
}

void MainWindow::resizeContent(){
     ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::slotMailUpdateModels(){
    this->updateDataOnTables();
}

void MainWindow::updateDataOnTables(){
    mailModel->select();
    this->resizeContent();
}

void MainWindow::on_updateButton_clicked(){
    this->updateDataOnTables();
}

void MainWindow::on_appendButton_clicked()
{
    AppendMailWindow *addAppendMailDialog = new AppendMailWindow(db, settingsMap);
    addAppendMailDialog->setWindowFlags (addAppendMailDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addAppendMailDialog->setModal(true);
    connect(addAppendMailDialog, SIGNAL(signalMailUpdate()), this, SLOT(slotMailUpdateModels()));
    addAppendMailDialog->setWindowTitle("Добавить письмо");
    addAppendMailDialog->exec();
}
void MainWindow::on_actionMailGroupSettings_triggered()
{
    MailGroupSettings *addAppendMailDialog = new MailGroupSettings(db);
    addAppendMailDialog->setWindowFlags (addAppendMailDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addAppendMailDialog->setModal(true);
    addAppendMailDialog->setWindowTitle("Добавить настройки групп");
    addAppendMailDialog->exec();
}
