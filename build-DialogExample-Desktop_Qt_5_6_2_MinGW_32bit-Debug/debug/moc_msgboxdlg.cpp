/****************************************************************************
** Meta object code from reading C++ file 'msgboxdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DialogExample/msgboxdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'msgboxdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MsgBoxDlg_t {
    QByteArrayData data[8];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MsgBoxDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MsgBoxDlg_t qt_meta_stringdata_MsgBoxDlg = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MsgBoxDlg"
QT_MOC_LITERAL(1, 10, 12), // "showQuestion"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "showInfomation"
QT_MOC_LITERAL(4, 39, 11), // "showWarning"
QT_MOC_LITERAL(5, 51, 12), // "showCritical"
QT_MOC_LITERAL(6, 64, 9), // "showAbout"
QT_MOC_LITERAL(7, 74, 11) // "showAboutQt"

    },
    "MsgBoxDlg\0showQuestion\0\0showInfomation\0"
    "showWarning\0showCritical\0showAbout\0"
    "showAboutQt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MsgBoxDlg[] = {

 // content:
       7,       // revision
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
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MsgBoxDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MsgBoxDlg *_t = static_cast<MsgBoxDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showQuestion(); break;
        case 1: _t->showInfomation(); break;
        case 2: _t->showWarning(); break;
        case 3: _t->showCritical(); break;
        case 4: _t->showAbout(); break;
        case 5: _t->showAboutQt(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MsgBoxDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MsgBoxDlg.data,
      qt_meta_data_MsgBoxDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MsgBoxDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MsgBoxDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MsgBoxDlg.stringdata0))
        return static_cast<void*>(const_cast< MsgBoxDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int MsgBoxDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
