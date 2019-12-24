/********************************************************************************
** Form generated from reading UI file 'mailgroupsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILGROUPSETTINGS_H
#define UI_MAILGROUPSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MailGroupSettings
{
public:
    QTableView *tableView;
    QPushButton *AppendSettingsButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *MailGroupSettings)
    {
        if (MailGroupSettings->objectName().isEmpty())
            MailGroupSettings->setObjectName(QString::fromUtf8("MailGroupSettings"));
        MailGroupSettings->resize(668, 278);
        MailGroupSettings->setMinimumSize(QSize(668, 278));
        MailGroupSettings->setMaximumSize(QSize(668, 278));
        tableView = new QTableView(MailGroupSettings);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 50, 421, 192));
        AppendSettingsButton = new QPushButton(MailGroupSettings);
        AppendSettingsButton->setObjectName(QString::fromUtf8("AppendSettingsButton"));
        AppendSettingsButton->setGeometry(QRect(470, 220, 75, 23));
        cancelButton = new QPushButton(MailGroupSettings);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(570, 220, 75, 23));

        retranslateUi(MailGroupSettings);

        QMetaObject::connectSlotsByName(MailGroupSettings);
    } // setupUi

    void retranslateUi(QDialog *MailGroupSettings)
    {
        MailGroupSettings->setWindowTitle(QCoreApplication::translate("MailGroupSettings", "Dialog", nullptr));
        AppendSettingsButton->setText(QCoreApplication::translate("MailGroupSettings", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("MailGroupSettings", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MailGroupSettings: public Ui_MailGroupSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILGROUPSETTINGS_H
