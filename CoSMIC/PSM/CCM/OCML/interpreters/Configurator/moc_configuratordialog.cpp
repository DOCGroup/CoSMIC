/****************************************************************************
** ConfiguratorDialog meta object code from reading C++ file 'configuratordialog.h'
**
** Created: Tue Jan 6 12:24:50 2004
**      by: The Qt MOC ($Id$)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_ConfiguratorDialog
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "configuratordialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *ConfiguratorDialog::className() const
{
    return "ConfiguratorDialog";
}

QMetaObject *ConfiguratorDialog::metaObj = 0;

void ConfiguratorDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("ConfiguratorDialog","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString ConfiguratorDialog::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("ConfiguratorDialog",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* ConfiguratorDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(ConfiguratorDialog::*m1_t0)();
    m1_t0 v1_0 = Q_AMPERSAND ConfiguratorDialog::create_svc_conf;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "create_svc_conf()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"ConfiguratorDialog", "QDialog",
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
