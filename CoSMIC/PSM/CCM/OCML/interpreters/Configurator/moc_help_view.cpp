/****************************************************************************
** Help_View meta object code from reading C++ file 'help_view.h'
**
** Created: Tue Jan 6 12:24:50 2004
**      by: The Qt MOC ($Id$)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_Help_View
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "help_view.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *Help_View::className() const
{
    return "Help_View";
}

QMetaObject *Help_View::metaObj = 0;

void Help_View::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QTextBrowser::className(), "QTextBrowser") != 0 )
	badSuperclassWarning("Help_View","QTextBrowser");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Help_View::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Help_View",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Help_View::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QTextBrowser::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"Help_View", "QTextBrowser",
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
