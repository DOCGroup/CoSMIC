/****************************************************************************
** Category_List_View meta object code from reading C++ file 'category_list_view.h'
**
** Created: Tue Jan 6 12:24:50 2004
**      by: The Qt MOC ($Id$)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_Category_List_View
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "category_list_view.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *Category_List_View::className() const
{
    return "Category_List_View";
}

QMetaObject *Category_List_View::metaObj = 0;

void Category_List_View::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QListView::className(), "QListView") != 0 )
	badSuperclassWarning("Category_List_View","QListView");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Category_List_View::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Category_List_View",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Category_List_View::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QListView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Category_List_View::*m1_t0)(QListViewItem*);
    m1_t0 v1_0 = Q_AMPERSAND Category_List_View::slot_category_changed;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "slot_category_changed(QListViewItem*)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"Category_List_View", "QListView",
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
