/****************************************************************************
** Meta object code from reading C++ file 'hstackview.h'
**
** Created: Mon May 21 18:21:19 2007
**      by: The Qt Meta Object Compiler version 59 (Qt 4.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widgets/hstack/hstackview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hstackview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_HStackView[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_HStackView[] = {
    "HStackView\0"
};

const QMetaObject HStackView::staticMetaObject = {
    { &ViewWidget::staticMetaObject, qt_meta_stringdata_HStackView,
      qt_meta_data_HStackView, 0 }
};

const QMetaObject *HStackView::metaObject() const
{
    return &staticMetaObject;
}

void *HStackView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HStackView))
	return static_cast<void*>(const_cast< HStackView*>(this));
    return ViewWidget::qt_metacast(_clname);
}

int HStackView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ViewWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
