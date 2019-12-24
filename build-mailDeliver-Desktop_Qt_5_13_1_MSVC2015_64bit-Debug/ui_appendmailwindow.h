/********************************************************************************
** Form generated from reading UI file 'appendmailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPENDMAILWINDOW_H
#define UI_APPENDMAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AppendMailWindow
{
public:
    QLineEdit *headerLineEdit;
    QLineEdit *fileNameLineEdit;
    QPushButton *selectFilePushButton;
    QPushButton *appendPushButton;
    QPushButton *cancelPushButton;
    QLineEdit *reciverLineEdit;
    QLabel *invalidInputLabel;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QPlainTextEdit *bodyTextEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *mailGroupComboBox;
    QPushButton *appendGroupButton;
    QRadioButton *selectDateRadioButton;
    QRadioButton *selectDayOfWeekRadioButton;
    QComboBox *dayOfWeekComboBox;

    void setupUi(QDialog *AppendMailWindow)
    {
        if (AppendMailWindow->objectName().isEmpty())
            AppendMailWindow->setObjectName(QString::fromUtf8("AppendMailWindow"));
        AppendMailWindow->resize(739, 496);
        AppendMailWindow->setMinimumSize(QSize(739, 496));
        AppendMailWindow->setMaximumSize(QSize(739, 496));
        headerLineEdit = new QLineEdit(AppendMailWindow);
        headerLineEdit->setObjectName(QString::fromUtf8("headerLineEdit"));
        headerLineEdit->setGeometry(QRect(40, 60, 411, 20));
        fileNameLineEdit = new QLineEdit(AppendMailWindow);
        fileNameLineEdit->setObjectName(QString::fromUtf8("fileNameLineEdit"));
        fileNameLineEdit->setGeometry(QRect(30, 460, 321, 20));
        selectFilePushButton = new QPushButton(AppendMailWindow);
        selectFilePushButton->setObjectName(QString::fromUtf8("selectFilePushButton"));
        selectFilePushButton->setGeometry(QRect(360, 460, 75, 23));
        appendPushButton = new QPushButton(AppendMailWindow);
        appendPushButton->setObjectName(QString::fromUtf8("appendPushButton"));
        appendPushButton->setGeometry(QRect(520, 460, 75, 23));
        cancelPushButton = new QPushButton(AppendMailWindow);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));
        cancelPushButton->setGeometry(QRect(620, 460, 75, 23));
        reciverLineEdit = new QLineEdit(AppendMailWindow);
        reciverLineEdit->setObjectName(QString::fromUtf8("reciverLineEdit"));
        reciverLineEdit->setGeometry(QRect(40, 20, 211, 20));
        invalidInputLabel = new QLabel(AppendMailWindow);
        invalidInputLabel->setObjectName(QString::fromUtf8("invalidInputLabel"));
        invalidInputLabel->setGeometry(QRect(140, 90, 361, 20));
        dateEdit = new QDateEdit(AppendMailWindow);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(40, 350, 110, 22));
        timeEdit = new QTimeEdit(AppendMailWindow);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(270, 400, 118, 22));
        bodyTextEdit = new QPlainTextEdit(AppendMailWindow);
        bodyTextEdit->setObjectName(QString::fromUtf8("bodyTextEdit"));
        bodyTextEdit->setGeometry(QRect(40, 120, 411, 211));
        label = new QLabel(AppendMailWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 31, 20));
        label_2 = new QLabel(AppendMailWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 47, 13));
        label_3 = new QLabel(AppendMailWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 330, 211, 16));
        label_4 = new QLabel(AppendMailWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 440, 661, 16));
        label_5 = new QLabel(AppendMailWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 100, 71, 16));
        mailGroupComboBox = new QComboBox(AppendMailWindow);
        mailGroupComboBox->setObjectName(QString::fromUtf8("mailGroupComboBox"));
        mailGroupComboBox->setGeometry(QRect(300, 20, 111, 22));
        appendGroupButton = new QPushButton(AppendMailWindow);
        appendGroupButton->setObjectName(QString::fromUtf8("appendGroupButton"));
        appendGroupButton->setGeometry(QRect(440, 20, 121, 23));
        selectDateRadioButton = new QRadioButton(AppendMailWindow);
        selectDateRadioButton->setObjectName(QString::fromUtf8("selectDateRadioButton"));
        selectDateRadioButton->setGeometry(QRect(170, 350, 82, 17));
        selectDayOfWeekRadioButton = new QRadioButton(AppendMailWindow);
        selectDayOfWeekRadioButton->setObjectName(QString::fromUtf8("selectDayOfWeekRadioButton"));
        selectDayOfWeekRadioButton->setGeometry(QRect(170, 400, 101, 17));
        dayOfWeekComboBox = new QComboBox(AppendMailWindow);
        dayOfWeekComboBox->setObjectName(QString::fromUtf8("dayOfWeekComboBox"));
        dayOfWeekComboBox->setGeometry(QRect(40, 400, 111, 22));

        retranslateUi(AppendMailWindow);

        QMetaObject::connectSlotsByName(AppendMailWindow);
    } // setupUi

    void retranslateUi(QDialog *AppendMailWindow)
    {
        AppendMailWindow->setWindowTitle(QCoreApplication::translate("AppendMailWindow", "Dialog", nullptr));
        selectFilePushButton->setText(QCoreApplication::translate("AppendMailWindow", "\320\236\320\261\320\267\320\276\321\200...", nullptr));
        appendPushButton->setText(QCoreApplication::translate("AppendMailWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("AppendMailWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        invalidInputLabel->setText(QString());
        label->setText(QCoreApplication::translate("AppendMailWindow", "\320\232\320\276\320\274\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("AppendMailWindow", "\320\242\320\265\320\274\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("AppendMailWindow", "\320\222\321\200\320\265\320\274\321\217 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("AppendMailWindow", "\320\237\321\200\320\270\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label_5->setText(QCoreApplication::translate("AppendMailWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        appendGroupButton->setText(QCoreApplication::translate("AppendMailWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        selectDateRadioButton->setText(QCoreApplication::translate("AppendMailWindow", "\320\224\320\260\321\202\320\260", nullptr));
        selectDayOfWeekRadioButton->setText(QCoreApplication::translate("AppendMailWindow", "\320\224\320\265\320\275\321\214 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppendMailWindow: public Ui_AppendMailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPENDMAILWINDOW_H
