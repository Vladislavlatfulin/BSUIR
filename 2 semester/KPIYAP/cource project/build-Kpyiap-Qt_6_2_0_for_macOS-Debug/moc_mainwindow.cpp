/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Kpyiap/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[40];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 12), // "CreateFolder"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 8), // "fileName"
QT_MOC_LITERAL(34, 12), // "RenameFolder"
QT_MOC_LITERAL(47, 11), // "newFileName"
QT_MOC_LITERAL(59, 25), // "on_LvSource_doubleClicked"
QT_MOC_LITERAL(85, 11), // "QModelIndex"
QT_MOC_LITERAL(97, 5), // "index"
QT_MOC_LITERAL(103, 18), // "on_Desktop_clicked"
QT_MOC_LITERAL(122, 29), // "on_actionNew_Folder_triggered"
QT_MOC_LITERAL(152, 25), // "on_actionBackup_triggered"
QT_MOC_LITERAL(178, 16), // "slotShortcutCmdB"
QT_MOC_LITERAL(195, 16), // "slotShortcutCmdR"
QT_MOC_LITERAL(212, 16), // "slotShortcutCmdF"
QT_MOC_LITERAL(229, 16), // "slotShortcutCmdD"
QT_MOC_LITERAL(246, 19), // "on_LvSource_clicked"
QT_MOC_LITERAL(266, 25), // "on_actionRemove_triggered"
QT_MOC_LITERAL(292, 25), // "on_actionRename_triggered"
QT_MOC_LITERAL(318, 17) // "on_Search_clicked"

    },
    "MainWindow\0CreateFolder\0\0fileName\0"
    "RenameFolder\0newFileName\0"
    "on_LvSource_doubleClicked\0QModelIndex\0"
    "index\0on_Desktop_clicked\0"
    "on_actionNew_Folder_triggered\0"
    "on_actionBackup_triggered\0slotShortcutCmdB\0"
    "slotShortcutCmdR\0slotShortcutCmdF\0"
    "slotShortcutCmdD\0on_LvSource_clicked\0"
    "on_actionRemove_triggered\0"
    "on_actionRename_triggered\0on_Search_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x08,    1 /* Private */,
       4,    1,  101,    2, 0x08,    3 /* Private */,
       6,    1,  104,    2, 0x08,    5 /* Private */,
       9,    0,  107,    2, 0x08,    7 /* Private */,
      10,    0,  108,    2, 0x08,    8 /* Private */,
      11,    0,  109,    2, 0x08,    9 /* Private */,
      12,    0,  110,    2, 0x08,   10 /* Private */,
      13,    0,  111,    2, 0x08,   11 /* Private */,
      14,    0,  112,    2, 0x08,   12 /* Private */,
      15,    0,  113,    2, 0x08,   13 /* Private */,
      16,    1,  114,    2, 0x08,   14 /* Private */,
      17,    0,  117,    2, 0x08,   16 /* Private */,
      18,    0,  118,    2, 0x08,   17 /* Private */,
      19,    0,  119,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->CreateFolder((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->RenameFolder((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_LvSource_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_Desktop_clicked(); break;
        case 4: _t->on_actionNew_Folder_triggered(); break;
        case 5: _t->on_actionBackup_triggered(); break;
        case 6: _t->slotShortcutCmdB(); break;
        case 7: _t->slotShortcutCmdR(); break;
        case 8: _t->slotShortcutCmdF(); break;
        case 9: _t->slotShortcutCmdD(); break;
        case 10: _t->on_LvSource_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_actionRemove_triggered(); break;
        case 12: _t->on_actionRename_triggered(); break;
        case 13: _t->on_Search_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
