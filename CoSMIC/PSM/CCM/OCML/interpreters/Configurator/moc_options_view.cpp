/****************************************************************************
** Option_Label meta object code from reading C++ file 'options_view.h'
**
** Created: Tue Jan 6 13:53:40 2004
**      by: The Qt MOC ($Id$)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_Option_Label
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "options_view.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *Option_Label::className() const
{
    return "Option_Label";
}

QMetaObject *Option_Label::metaObj = 0;

void Option_Label::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QLabel::className(), "QLabel") != 0 )
	badSuperclassWarning("Option_Label","QLabel");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Option_Label::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Option_Label",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Option_Label::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QLabel::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(Option_Label::*m2_t0)(Option_Label*);
    m2_t0 v2_0 = Q_AMPERSAND Option_Label::focus_gained;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "focus_gained(Option_Label*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Option_Label", "QLabel",
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL focus_gained
void Option_Label::focus_gained( Option_Label* t0 )
{
    // No builtin function for signal parameter type Option_Label*
    QConnectionList *clist = receivers("focus_gained(Option_Label*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(Option_Label*);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}


const char *Option_Check_Box::className() const
{
    return "Option_Check_Box";
}

QMetaObject *Option_Check_Box::metaObj = 0;

void Option_Check_Box::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QCheckBox::className(), "QCheckBox") != 0 )
	badSuperclassWarning("Option_Check_Box","QCheckBox");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Option_Check_Box::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Option_Check_Box",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Option_Check_Box::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QCheckBox::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(Option_Check_Box::*m2_t0)(Option_Check_Box*);
    m2_t0 v2_0 = Q_AMPERSAND Option_Check_Box::focus_gained;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "focus_gained(Option_Check_Box*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Option_Check_Box", "QCheckBox",
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL focus_gained
void Option_Check_Box::focus_gained( Option_Check_Box* t0 )
{
    // No builtin function for signal parameter type Option_Check_Box*
    QConnectionList *clist = receivers("focus_gained(Option_Check_Box*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(Option_Check_Box*);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}


const char *Option_Radio_Button::className() const
{
    return "Option_Radio_Button";
}

QMetaObject *Option_Radio_Button::metaObj = 0;

void Option_Radio_Button::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QRadioButton::className(), "QRadioButton") != 0 )
	badSuperclassWarning("Option_Radio_Button","QRadioButton");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Option_Radio_Button::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Option_Radio_Button",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Option_Radio_Button::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QRadioButton::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(Option_Radio_Button::*m2_t0)(Option_Radio_Button*);
    m2_t0 v2_0 = Q_AMPERSAND Option_Radio_Button::focus_gained;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "focus_gained(Option_Radio_Button*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Option_Radio_Button", "QRadioButton",
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL focus_gained
void Option_Radio_Button::focus_gained( Option_Radio_Button* t0 )
{
    // No builtin function for signal parameter type Option_Radio_Button*
    QConnectionList *clist = receivers("focus_gained(Option_Radio_Button*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(Option_Radio_Button*);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}


const char *Option_Line_Edit::className() const
{
    return "Option_Line_Edit";
}

QMetaObject *Option_Line_Edit::metaObj = 0;

void Option_Line_Edit::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QLineEdit::className(), "QLineEdit") != 0 )
	badSuperclassWarning("Option_Line_Edit","QLineEdit");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Option_Line_Edit::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Option_Line_Edit",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Option_Line_Edit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QLineEdit::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(Option_Line_Edit::*m2_t0)(Option_Line_Edit*);
    m2_t0 v2_0 = Q_AMPERSAND Option_Line_Edit::focus_gained;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "focus_gained(Option_Line_Edit*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Option_Line_Edit", "QLineEdit",
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL focus_gained
void Option_Line_Edit::focus_gained( Option_Line_Edit* t0 )
{
    // No builtin function for signal parameter type Option_Line_Edit*
    QConnectionList *clist = receivers("focus_gained(Option_Line_Edit*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(Option_Line_Edit*);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}


const char *Option_Spin_Box::className() const
{
    return "Option_Spin_Box";
}

QMetaObject *Option_Spin_Box::metaObj = 0;

void Option_Spin_Box::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QSpinBox::className(), "QSpinBox") != 0 )
	badSuperclassWarning("Option_Spin_Box","QSpinBox");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Option_Spin_Box::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Option_Spin_Box",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Option_Spin_Box::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QSpinBox::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(Option_Spin_Box::*m2_t0)(Option_Spin_Box*);
    m2_t0 v2_0 = Q_AMPERSAND Option_Spin_Box::focus_gained;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "focus_gained(Option_Spin_Box*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Option_Spin_Box", "QSpinBox",
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL focus_gained
void Option_Spin_Box::focus_gained( Option_Spin_Box* t0 )
{
    // No builtin function for signal parameter type Option_Spin_Box*
    QConnectionList *clist = receivers("focus_gained(Option_Spin_Box*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(Option_Spin_Box*);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}


const char *Option_Editor_NoLabel::className() const
{
    return "Option_Editor_NoLabel";
}

QMetaObject *Option_Editor_NoLabel::metaObj = 0;

void Option_Editor_NoLabel::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QHBox::className(), "QHBox") != 0 )
	badSuperclassWarning("Option_Editor_NoLabel","QHBox");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Option_Editor_NoLabel::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Option_Editor_NoLabel",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Option_Editor_NoLabel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QHBox::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"Option_Editor_NoLabel", "QHBox",
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *Option_Editor_Label::className() const
{
    return "Option_Editor_Label";
}

QMetaObject *Option_Editor_Label::metaObj = 0;

void Option_Editor_Label::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QHBox::className(), "QHBox") != 0 )
	badSuperclassWarning("Option_Editor_Label","QHBox");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Option_Editor_Label::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Option_Editor_Label",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Option_Editor_Label::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QHBox::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Option_Editor_Label::*m1_t0)(QWidget*);
    m1_t0 v1_0 = Q_AMPERSAND Option_Editor_Label::child_focus_gained;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "child_focus_gained(QWidget*)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    typedef void(Option_Editor_Label::*m2_t0)(Option_Editor*);
    m2_t0 v2_0 = Q_AMPERSAND Option_Editor_Label::focus_gained;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "focus_gained(Option_Editor*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Option_Editor_Label", "QHBox",
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL focus_gained
void Option_Editor_Label::focus_gained( Option_Editor* t0 )
{
    // No builtin function for signal parameter type Option_Editor*
    QConnectionList *clist = receivers("focus_gained(Option_Editor*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(Option_Editor*);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}


const char *Option_Editor_Box::className() const
{
    return "Option_Editor_Box";
}

QMetaObject *Option_Editor_Box::metaObj = 0;

void Option_Editor_Box::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QVButtonGroup::className(), "QVButtonGroup") != 0 )
	badSuperclassWarning("Option_Editor_Box","QVButtonGroup");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Option_Editor_Box::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Option_Editor_Box",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Option_Editor_Box::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QVButtonGroup::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Option_Editor_Box::*m1_t0)(QWidget*);
    m1_t0 v1_0 = Q_AMPERSAND Option_Editor_Box::child_focus_gained;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "child_focus_gained(QWidget*)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    typedef void(Option_Editor_Box::*m2_t0)(Option_Editor*);
    m2_t0 v2_0 = Q_AMPERSAND Option_Editor_Box::focus_gained;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "focus_gained(Option_Editor*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Option_Editor_Box", "QVButtonGroup",
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL focus_gained
void Option_Editor_Box::focus_gained( Option_Editor* t0 )
{
    // No builtin function for signal parameter type Option_Editor*
    QConnectionList *clist = receivers("focus_gained(Option_Editor*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(Option_Editor*);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}


const char *Integer_Option_Editor::className() const
{
    return "Integer_Option_Editor";
}

QMetaObject *Integer_Option_Editor::metaObj = 0;

void Integer_Option_Editor::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(Option_Editor_Label::className(), "Option_Editor_Label") != 0 )
	badSuperclassWarning("Integer_Option_Editor","Option_Editor_Label");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Integer_Option_Editor::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Integer_Option_Editor",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Integer_Option_Editor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) Option_Editor_Label::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Integer_Option_Editor::*m1_t0)(int);
    m1_t0 v1_0 = Q_AMPERSAND Integer_Option_Editor::set_value;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "set_value(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"Integer_Option_Editor", "Option_Editor_Label",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *String_Option_Editor::className() const
{
    return "String_Option_Editor";
}

QMetaObject *String_Option_Editor::metaObj = 0;

void String_Option_Editor::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(Option_Editor_Label::className(), "Option_Editor_Label") != 0 )
	badSuperclassWarning("String_Option_Editor","Option_Editor_Label");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString String_Option_Editor::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("String_Option_Editor",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* String_Option_Editor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) Option_Editor_Label::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(String_Option_Editor::*m1_t0)(const QString&);
    m1_t0 v1_0 = Q_AMPERSAND String_Option_Editor::set_value;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "set_value(const QString&)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"String_Option_Editor", "Option_Editor_Label",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *Flag_Option_Editor::className() const
{
    return "Flag_Option_Editor";
}

QMetaObject *Flag_Option_Editor::metaObj = 0;

void Flag_Option_Editor::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(Option_Editor_Label::className(), "Option_Editor_Label") != 0 )
	badSuperclassWarning("Flag_Option_Editor","Option_Editor_Label");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Flag_Option_Editor::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Flag_Option_Editor",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Flag_Option_Editor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) Option_Editor_Label::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Flag_Option_Editor::*m1_t0)(int);
    m1_t0 v1_0 = Q_AMPERSAND Flag_Option_Editor::set_value;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "set_value(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"Flag_Option_Editor", "Option_Editor_Label",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *Set_Option_Value_Editor::className() const
{
    return "Set_Option_Value_Editor";
}

QMetaObject *Set_Option_Value_Editor::metaObj = 0;

void Set_Option_Value_Editor::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(Option_Editor_Label::className(), "Option_Editor_Label") != 0 )
	badSuperclassWarning("Set_Option_Value_Editor","Option_Editor_Label");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Set_Option_Value_Editor::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Set_Option_Value_Editor",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Set_Option_Value_Editor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) Option_Editor_Label::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Set_Option_Value_Editor::*m1_t0)(int);
    m1_t0 v1_0 = Q_AMPERSAND Set_Option_Value_Editor::set_value;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "set_value(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"Set_Option_Value_Editor", "Option_Editor_Label",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *Enum_Option_Value_Editor::className() const
{
    return "Enum_Option_Value_Editor";
}

QMetaObject *Enum_Option_Value_Editor::metaObj = 0;

void Enum_Option_Value_Editor::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(Option_Editor_NoLabel::className(), "Option_Editor_NoLabel") != 0 )
	badSuperclassWarning("Enum_Option_Value_Editor","Option_Editor_NoLabel");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Enum_Option_Value_Editor::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Enum_Option_Value_Editor",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Enum_Option_Value_Editor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) Option_Editor_NoLabel::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Enum_Option_Value_Editor::*m1_t0)(int);
    m1_t0 v1_0 = Q_AMPERSAND Enum_Option_Value_Editor::set_value;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "set_value(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"Enum_Option_Value_Editor", "Option_Editor_NoLabel",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *Enum_Option_Editor::className() const
{
    return "Enum_Option_Editor";
}

QMetaObject *Enum_Option_Editor::metaObj = 0;

void Enum_Option_Editor::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(Option_Editor_Box::className(), "Option_Editor_Box") != 0 )
	badSuperclassWarning("Enum_Option_Editor","Option_Editor_Box");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Enum_Option_Editor::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Enum_Option_Editor",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Enum_Option_Editor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) Option_Editor_Box::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"Enum_Option_Editor", "Option_Editor_Box",
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *Set_Option_Editor::className() const
{
    return "Set_Option_Editor";
}

QMetaObject *Set_Option_Editor::metaObj = 0;

void Set_Option_Editor::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(Option_Editor_Box::className(), "Option_Editor_Box") != 0 )
	badSuperclassWarning("Set_Option_Editor","Option_Editor_Box");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Set_Option_Editor::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Set_Option_Editor",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Set_Option_Editor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) Option_Editor_Box::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"Set_Option_Editor", "Option_Editor_Box",
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *Options_View::className() const
{
    return "Options_View";
}

QMetaObject *Options_View::metaObj = 0;

void Options_View::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QScrollView::className(), "QScrollView") != 0 )
	badSuperclassWarning("Options_View","QScrollView");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Options_View::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Options_View",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Options_View::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QScrollView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Options_View::*m1_t0)(Option_Editor*);
    m1_t0 v1_0 = Q_AMPERSAND Options_View::focus_changed;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "focus_changed(Option_Editor*)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"Options_View", "QScrollView",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
