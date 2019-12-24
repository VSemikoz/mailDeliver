/****************************************************************************
** Meta object code from reading C++ file 'mailgroupsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mailDeliver/mailgroupsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mailgroupsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MailGroupSettings_t {
    QByteArrayData data[11];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MailGroupSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MailGroupSettings_t qt_meta_stringdata_MailGroupSettings = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MailGroupSettings"
QT_MOC_LITERAL(1, 18, 31), // "on_AppendSettingsButton_clicked"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(4, 75, 23), // "slotEditMailGroupRecord"
QT_MOC_LITERAL(5, 99, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 111, 5), // "index"
QT_MOC_LITERAL(7, 117, 26), // "slotMailGroupMenuRequested"
QT_MOC_LITERAL(8, 144, 3), // "pos"
QT_MOC_LITERAL(9, 148, 20), // "slotMailUpdateModels"
QT_MOC_LITERAL(10, 169, 28) // "slotRemoveRecordFromSettings"

    },
    "MailGroupSettings\0on_AppendSettingsButton_clicked\0"
    "\0on_cancelButton_clicked\0"
    "slotEditMailGroupRecord\0QModelIndex\0"
    "index\0slotMailGroupMenuRequested\0pos\0"
    "slotMailUpdateModels\0slotRemoveRecordFromSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MailGroupSettings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,
       9,    0,   52,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MailGroupSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MailGroupSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_AppendSettingsButton_clicked(); break;
        case 1: _t->on_cancelButton_clicked(); break;
        case 2: _t->slotEditMailGroupRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->slotMailGroupMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->slotMailUpdateModels(); break;
        case 5: _t->slotRemoveRecordFromSettings(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MailGroupSettings::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_MailGroupSettings.data,
    qt_meta_data_MailGroupSettings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MailGroupSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MailGroupSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MailGroupSettings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MailGroupSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
