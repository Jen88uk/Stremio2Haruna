/****************************************************************************
** Meta object code from reading C++ file 'stremio2haruna.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../stremio2haruna.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stremio2haruna.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14Stremio2HarunaE_t {};
} // unnamed namespace

template <> constexpr inline auto Stremio2Haruna::qt_create_metaobjectdata<qt_meta_tag_ZN14Stremio2HarunaE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Stremio2Haruna",
        "onClipboardChanged",
        "",
        "onToggleEnabled",
        "enabled",
        "onQuit",
        "checkClipboard"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onClipboardChanged'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onToggleEnabled'
        QtMocHelpers::SlotData<void(bool)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Slot 'onQuit'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'checkClipboard'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Stremio2Haruna, qt_meta_tag_ZN14Stremio2HarunaE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Stremio2Haruna::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14Stremio2HarunaE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14Stremio2HarunaE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14Stremio2HarunaE_t>.metaTypes,
    nullptr
} };

void Stremio2Haruna::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Stremio2Haruna *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onClipboardChanged(); break;
        case 1: _t->onToggleEnabled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->onQuit(); break;
        case 3: _t->checkClipboard(); break;
        default: ;
        }
    }
}

const QMetaObject *Stremio2Haruna::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stremio2Haruna::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14Stremio2HarunaE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Stremio2Haruna::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
