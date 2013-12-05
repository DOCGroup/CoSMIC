

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Sep 04 08:48:26 2013
 */
/* Compiler settings for .\ConnectorInstance_Decorator.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ConnectorInstance_Decorator_h__
#define __ConnectorInstance_Decorator_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMgaDataSource_FWD_DEFINED__
#define __IMgaDataSource_FWD_DEFINED__
typedef interface IMgaDataSource IMgaDataSource;
#endif 	/* __IMgaDataSource_FWD_DEFINED__ */


#ifndef __IGMEOLEApp_FWD_DEFINED__
#define __IGMEOLEApp_FWD_DEFINED__
typedef interface IGMEOLEApp IGMEOLEApp;
#endif 	/* __IGMEOLEApp_FWD_DEFINED__ */


#ifndef __IGMEOLEIt_FWD_DEFINED__
#define __IGMEOLEIt_FWD_DEFINED__
typedef interface IGMEOLEIt IGMEOLEIt;
#endif 	/* __IGMEOLEIt_FWD_DEFINED__ */


#ifndef __IGMEOLEModel_FWD_DEFINED__
#define __IGMEOLEModel_FWD_DEFINED__
typedef interface IGMEOLEModel IGMEOLEModel;
#endif 	/* __IGMEOLEModel_FWD_DEFINED__ */


#ifndef __IGMEOLEAspect_FWD_DEFINED__
#define __IGMEOLEAspect_FWD_DEFINED__
typedef interface IGMEOLEAspect IGMEOLEAspect;
#endif 	/* __IGMEOLEAspect_FWD_DEFINED__ */


#ifndef __IGMEOLEPanel_FWD_DEFINED__
#define __IGMEOLEPanel_FWD_DEFINED__
typedef interface IGMEOLEPanel IGMEOLEPanel;
#endif 	/* __IGMEOLEPanel_FWD_DEFINED__ */


#ifndef __IGMEOLEColl_FWD_DEFINED__
#define __IGMEOLEColl_FWD_DEFINED__
typedef interface IGMEOLEColl IGMEOLEColl;
#endif 	/* __IGMEOLEColl_FWD_DEFINED__ */


#ifndef __IMgaDecorator_FWD_DEFINED__
#define __IMgaDecorator_FWD_DEFINED__
typedef interface IMgaDecorator IMgaDecorator;
#endif 	/* __IMgaDecorator_FWD_DEFINED__ */


#ifndef __IMgaCommonDecoratorEvents_FWD_DEFINED__
#define __IMgaCommonDecoratorEvents_FWD_DEFINED__
typedef interface IMgaCommonDecoratorEvents IMgaCommonDecoratorEvents;
#endif 	/* __IMgaCommonDecoratorEvents_FWD_DEFINED__ */


#ifndef __IMgaDecoratorCommon_FWD_DEFINED__
#define __IMgaDecoratorCommon_FWD_DEFINED__
typedef interface IMgaDecoratorCommon IMgaDecoratorCommon;
#endif 	/* __IMgaDecoratorCommon_FWD_DEFINED__ */


#ifndef __IMgaElementDecoratorEvents_FWD_DEFINED__
#define __IMgaElementDecoratorEvents_FWD_DEFINED__
typedef interface IMgaElementDecoratorEvents IMgaElementDecoratorEvents;
#endif 	/* __IMgaElementDecoratorEvents_FWD_DEFINED__ */


#ifndef __IMgaElementDecorator_FWD_DEFINED__
#define __IMgaElementDecorator_FWD_DEFINED__
typedef interface IMgaElementDecorator IMgaElementDecorator;
#endif 	/* __IMgaElementDecorator_FWD_DEFINED__ */


#ifndef __ICoreMetaProject_FWD_DEFINED__
#define __ICoreMetaProject_FWD_DEFINED__
typedef interface ICoreMetaProject ICoreMetaProject;
#endif 	/* __ICoreMetaProject_FWD_DEFINED__ */


#ifndef __ICoreMetaObject_FWD_DEFINED__
#define __ICoreMetaObject_FWD_DEFINED__
typedef interface ICoreMetaObject ICoreMetaObject;
#endif 	/* __ICoreMetaObject_FWD_DEFINED__ */


#ifndef __ICoreMetaAttribute_FWD_DEFINED__
#define __ICoreMetaAttribute_FWD_DEFINED__
typedef interface ICoreMetaAttribute ICoreMetaAttribute;
#endif 	/* __ICoreMetaAttribute_FWD_DEFINED__ */


#ifndef __ICoreStorage_FWD_DEFINED__
#define __ICoreStorage_FWD_DEFINED__
typedef interface ICoreStorage ICoreStorage;
#endif 	/* __ICoreStorage_FWD_DEFINED__ */


#ifndef __ICoreProject_FWD_DEFINED__
#define __ICoreProject_FWD_DEFINED__
typedef interface ICoreProject ICoreProject;
#endif 	/* __ICoreProject_FWD_DEFINED__ */


#ifndef __ICoreObject_FWD_DEFINED__
#define __ICoreObject_FWD_DEFINED__
typedef interface ICoreObject ICoreObject;
#endif 	/* __ICoreObject_FWD_DEFINED__ */


#ifndef __ICoreAttribute_FWD_DEFINED__
#define __ICoreAttribute_FWD_DEFINED__
typedef interface ICoreAttribute ICoreAttribute;
#endif 	/* __ICoreAttribute_FWD_DEFINED__ */


#ifndef __ICoreTerritory_FWD_DEFINED__
#define __ICoreTerritory_FWD_DEFINED__
typedef interface ICoreTerritory ICoreTerritory;
#endif 	/* __ICoreTerritory_FWD_DEFINED__ */


#ifndef __ICoreMetaObjects_FWD_DEFINED__
#define __ICoreMetaObjects_FWD_DEFINED__
typedef interface ICoreMetaObjects ICoreMetaObjects;
#endif 	/* __ICoreMetaObjects_FWD_DEFINED__ */


#ifndef __ICoreMetaAttributes_FWD_DEFINED__
#define __ICoreMetaAttributes_FWD_DEFINED__
typedef interface ICoreMetaAttributes ICoreMetaAttributes;
#endif 	/* __ICoreMetaAttributes_FWD_DEFINED__ */


#ifndef __ICoreObjects_FWD_DEFINED__
#define __ICoreObjects_FWD_DEFINED__
typedef interface ICoreObjects ICoreObjects;
#endif 	/* __ICoreObjects_FWD_DEFINED__ */


#ifndef __ICoreAttributes_FWD_DEFINED__
#define __ICoreAttributes_FWD_DEFINED__
typedef interface ICoreAttributes ICoreAttributes;
#endif 	/* __ICoreAttributes_FWD_DEFINED__ */


#ifndef __IGMEVersionInfo_FWD_DEFINED__
#define __IGMEVersionInfo_FWD_DEFINED__
typedef interface IGMEVersionInfo IGMEVersionInfo;
#endif 	/* __IGMEVersionInfo_FWD_DEFINED__ */


#ifndef __ICoreDictionaryAttributeValue_FWD_DEFINED__
#define __ICoreDictionaryAttributeValue_FWD_DEFINED__
typedef interface ICoreDictionaryAttributeValue ICoreDictionaryAttributeValue;
#endif 	/* __ICoreDictionaryAttributeValue_FWD_DEFINED__ */


#ifndef __ConnectorInstance_Decorator_FWD_DEFINED__
#define __ConnectorInstance_Decorator_FWD_DEFINED__

#ifdef __cplusplus
typedef class ConnectorInstance_Decorator ConnectorInstance_Decorator;
#else
typedef struct ConnectorInstance_Decorator ConnectorInstance_Decorator;
#endif /* __cplusplus */

#endif 	/* __ConnectorInstance_Decorator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "Meta.h"
#include "Mga.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ConnectorInstance_Decorator_0000_0000 */
/* [local] */ 

#ifndef INTERFACECOLL_INCLUDED
#define INTERFACECOLL_INCLUDED
extern "C++"											
{														
	template<class COLL> struct TypeName_MgaColl2Elem		
	{														
		typedef IUnknown element_type;						
		typedef IUnknown collection_type;					
	};														
	template<class ELEM> struct TypeName_MgaElem2Coll		
	{														
		typedef IUnknown element_type;						
		typedef IUnknown collection_type;					
	};														
}														
#define TYPENAME_COLL2ELEM(COLL) typename ::TypeName_MgaColl2Elem<COLL>::element_type
#define TYPENAME_ELEM2COLL(ELEM) typename ::TypeName_MgaElem2Coll<ELEM>::collection_type
#endif
#ifndef INTERFACE_VERSION
#define INTERFACE_VERSION 0x000200E6
#endif //INTERFACE_VERSION

typedef 
enum msgtype_enum
    {	MSG_NORMAL	= 0,
	MSG_INFO	= 1,
	MSG_WARNING	= 2,
	MSG_ERROR	= 3
    } 	msgtype_enum;

typedef 
enum editmode_enum
    {	MODE_EDIT	= 0,
	MODE_CONNECT	= 1,
	MODE_DISCONNECT	= 2,
	MODE_SET	= 3,
	MODE_ZOOM	= 4,
	MODE_VISUALIZE	= 5
    } 	editmode_enum;

typedef 
enum bar_enum
    {	BAR_HORIZ	= 0,
	BAR_VERTI	= 1
    } 	bar_enum;

typedef 
enum scroll_enum
    {	SCROL_UP	= 0,
	SCROL_DOWN	= 1,
	SCROL_PGUP	= 2,
	SCROL_PGDN	= 3,
	SCROL_HOME	= 4,
	SCROL_END	= 5
    } 	scroll_enum;

typedef 
enum attribpanel_page
    {	PAGE_ATTRIB	= 0,
	PAGE_PREF	= 1,
	PAGE_PROP	= 2
    } 	attribpanel_page;



extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0000_v0_0_s_ifspec;

#ifndef __IMgaDataSource_INTERFACE_DEFINED__
#define __IMgaDataSource_INTERFACE_DEFINED__

/* interface IMgaDataSource */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IMgaDataSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9FF8F4E0-E0C9-11d3-B376-005004D38590")
    IMgaDataSource : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [retval][out] */ IUnknown **p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Folders( 
            /* [retval][out] */ IUnknown **p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegistryData( 
            /* [retval][out] */ IUnknown **p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Project( 
            /* [retval][out] */ IUnknown **p) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMgaDataSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMgaDataSource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMgaDataSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMgaDataSource * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMgaDataSource * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMgaDataSource * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMgaDataSource * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMgaDataSource * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IMgaDataSource * This,
            /* [retval][out] */ IUnknown **p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Folders )( 
            IMgaDataSource * This,
            /* [retval][out] */ IUnknown **p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegistryData )( 
            IMgaDataSource * This,
            /* [retval][out] */ IUnknown **p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Project )( 
            IMgaDataSource * This,
            /* [retval][out] */ IUnknown **p);
        
        END_INTERFACE
    } IMgaDataSourceVtbl;

    interface IMgaDataSource
    {
        CONST_VTBL struct IMgaDataSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMgaDataSource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMgaDataSource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMgaDataSource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMgaDataSource_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMgaDataSource_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMgaDataSource_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMgaDataSource_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMgaDataSource_get_Data(This,p)	\
    ( (This)->lpVtbl -> get_Data(This,p) ) 

#define IMgaDataSource_get_Folders(This,p)	\
    ( (This)->lpVtbl -> get_Folders(This,p) ) 

#define IMgaDataSource_get_RegistryData(This,p)	\
    ( (This)->lpVtbl -> get_RegistryData(This,p) ) 

#define IMgaDataSource_get_Project(This,p)	\
    ( (This)->lpVtbl -> get_Project(This,p) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMgaDataSource_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ConnectorInstance_Decorator_0000_0001 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0001_v0_0_s_ifspec;

#ifndef __IGMEOLEApp_INTERFACE_DEFINED__
#define __IGMEOLEApp_INTERFACE_DEFINED__

/* interface IGMEOLEApp */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IGMEOLEApp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81191A44-B898-4143-BF8B-CA7501FEC19A")
    IGMEOLEApp : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL isVisible) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *isVisible) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR *versionStr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_VersionMajor( 
            /* [retval][out] */ short *n) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_VersionMinor( 
            /* [retval][out] */ short *n) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_VersionPatchLevel( 
            /* [retval][out] */ short *n) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Models( 
            /* [retval][out] */ IGMEOLEColl **coll) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MgaProject( 
            /* [retval][out] */ IMgaProject **p) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Panels( 
            /* [retval][out] */ IGMEOLEColl **coll) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ConsoleContents( 
            /* [in] */ BSTR contents) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ConsoleContents( 
            /* [retval][out] */ BSTR *contents) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateProject( 
            /* [in] */ BSTR metaname,
            /* [in] */ BSTR ConnStr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenProject( 
            /* [in] */ BSTR ConnStr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateProjectDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenProjectDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CloseProject( 
            /* [in] */ VARIANT_BOOL saveOnClose) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SaveProject( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SaveProjectAs( 
            /* [in] */ BSTR ConnStr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SaveProjectAsDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExportProject( 
            /* [in] */ BSTR ConnStr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ImportProject( 
            /* [in] */ BSTR ConnStr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConstraintsDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CheckAllConstraints( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterParagimsDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterComponentsDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RunComponent( 
            /* [in] */ BSTR progID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RunComponentDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SettingsDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Undo( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Redo( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearUndoQueue( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ProjectPropertiesDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowHelpContents( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowAbout( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowFCO( 
            /* [in] */ IMgaFCO *mgaFCO,
            /* [defaultvalue][in] */ VARIANT_BOOL inParent = 0) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConsoleMessage( 
            /* [in] */ BSTR msg,
            /* [in] */ msgtype_enum type) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConsoleClear( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConsoleNavigateTo( 
            /* [in] */ BSTR url) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeEditmode( 
            /* [in] */ editmode_enum mode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GridShow( 
            /* [in] */ VARIANT_BOOL show) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AttributepanelPage( 
            /* [in] */ attribpanel_page page) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_OleIt( 
            /* [retval][out] */ IGMEOLEIt **mgamodel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableComp( 
            /* [in] */ BSTR pCompProgID,
            /* [in] */ VARIANT_BOOL pDisable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableCompForKinds( 
            /* [in] */ BSTR pCompProgID,
            /* [in] */ BSTR pKindSequenceDelimitedBySemicolon) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCompFiltering( 
            /* [in] */ VARIANT_BOOL pTurnOn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCompFiltering( 
            /* [retval][out] */ VARIANT_BOOL *pPtrTurnedOn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWorkingDirectory( 
            /* [in] */ BSTR pDirPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshLib( 
            /* [in] */ BSTR pLibName,
            /* [in] */ VARIANT_BOOL ungroup,
            /* [retval][out] */ long *numOfErrors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGMEOLEAppVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGMEOLEApp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGMEOLEApp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGMEOLEApp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGMEOLEApp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGMEOLEApp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGMEOLEApp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGMEOLEApp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGMEOLEApp * This,
            /* [in] */ VARIANT_BOOL isVisible);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGMEOLEApp * This,
            /* [retval][out] */ VARIANT_BOOL *isVisible);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IGMEOLEApp * This,
            /* [retval][out] */ BSTR *versionStr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VersionMajor )( 
            IGMEOLEApp * This,
            /* [retval][out] */ short *n);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VersionMinor )( 
            IGMEOLEApp * This,
            /* [retval][out] */ short *n);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VersionPatchLevel )( 
            IGMEOLEApp * This,
            /* [retval][out] */ short *n);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Models )( 
            IGMEOLEApp * This,
            /* [retval][out] */ IGMEOLEColl **coll);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MgaProject )( 
            IGMEOLEApp * This,
            /* [retval][out] */ IMgaProject **p);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Panels )( 
            IGMEOLEApp * This,
            /* [retval][out] */ IGMEOLEColl **coll);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ConsoleContents )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR contents);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConsoleContents )( 
            IGMEOLEApp * This,
            /* [retval][out] */ BSTR *contents);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateProject )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR metaname,
            /* [in] */ BSTR ConnStr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenProject )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR ConnStr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateProjectDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenProjectDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CloseProject )( 
            IGMEOLEApp * This,
            /* [in] */ VARIANT_BOOL saveOnClose);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SaveProject )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SaveProjectAs )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR ConnStr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SaveProjectAsDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExportProject )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR ConnStr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ImportProject )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR ConnStr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConstraintsDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CheckAllConstraints )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterParagimsDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterComponentsDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RunComponent )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR progID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RunComponentDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SettingsDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Undo )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Redo )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearUndoQueue )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ProjectPropertiesDialog )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowHelpContents )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowAbout )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowFCO )( 
            IGMEOLEApp * This,
            /* [in] */ IMgaFCO *mgaFCO,
            /* [defaultvalue][in] */ VARIANT_BOOL inParent);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConsoleMessage )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR msg,
            /* [in] */ msgtype_enum type);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConsoleClear )( 
            IGMEOLEApp * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConsoleNavigateTo )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR url);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeEditmode )( 
            IGMEOLEApp * This,
            /* [in] */ editmode_enum mode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GridShow )( 
            IGMEOLEApp * This,
            /* [in] */ VARIANT_BOOL show);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AttributepanelPage )( 
            IGMEOLEApp * This,
            /* [in] */ attribpanel_page page);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OleIt )( 
            IGMEOLEApp * This,
            /* [retval][out] */ IGMEOLEIt **mgamodel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableComp )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR pCompProgID,
            /* [in] */ VARIANT_BOOL pDisable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableCompForKinds )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR pCompProgID,
            /* [in] */ BSTR pKindSequenceDelimitedBySemicolon);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCompFiltering )( 
            IGMEOLEApp * This,
            /* [in] */ VARIANT_BOOL pTurnOn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCompFiltering )( 
            IGMEOLEApp * This,
            /* [retval][out] */ VARIANT_BOOL *pPtrTurnedOn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWorkingDirectory )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR pDirPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exit )( 
            IGMEOLEApp * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshLib )( 
            IGMEOLEApp * This,
            /* [in] */ BSTR pLibName,
            /* [in] */ VARIANT_BOOL ungroup,
            /* [retval][out] */ long *numOfErrors);
        
        END_INTERFACE
    } IGMEOLEAppVtbl;

    interface IGMEOLEApp
    {
        CONST_VTBL struct IGMEOLEAppVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGMEOLEApp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGMEOLEApp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGMEOLEApp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGMEOLEApp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGMEOLEApp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGMEOLEApp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGMEOLEApp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGMEOLEApp_put_Visible(This,isVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,isVisible) ) 

#define IGMEOLEApp_get_Visible(This,isVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,isVisible) ) 

#define IGMEOLEApp_get_Version(This,versionStr)	\
    ( (This)->lpVtbl -> get_Version(This,versionStr) ) 

#define IGMEOLEApp_get_VersionMajor(This,n)	\
    ( (This)->lpVtbl -> get_VersionMajor(This,n) ) 

#define IGMEOLEApp_get_VersionMinor(This,n)	\
    ( (This)->lpVtbl -> get_VersionMinor(This,n) ) 

#define IGMEOLEApp_get_VersionPatchLevel(This,n)	\
    ( (This)->lpVtbl -> get_VersionPatchLevel(This,n) ) 

#define IGMEOLEApp_get_Models(This,coll)	\
    ( (This)->lpVtbl -> get_Models(This,coll) ) 

#define IGMEOLEApp_get_MgaProject(This,p)	\
    ( (This)->lpVtbl -> get_MgaProject(This,p) ) 

#define IGMEOLEApp_get_Panels(This,coll)	\
    ( (This)->lpVtbl -> get_Panels(This,coll) ) 

#define IGMEOLEApp_put_ConsoleContents(This,contents)	\
    ( (This)->lpVtbl -> put_ConsoleContents(This,contents) ) 

#define IGMEOLEApp_get_ConsoleContents(This,contents)	\
    ( (This)->lpVtbl -> get_ConsoleContents(This,contents) ) 

#define IGMEOLEApp_CreateProject(This,metaname,ConnStr)	\
    ( (This)->lpVtbl -> CreateProject(This,metaname,ConnStr) ) 

#define IGMEOLEApp_OpenProject(This,ConnStr)	\
    ( (This)->lpVtbl -> OpenProject(This,ConnStr) ) 

#define IGMEOLEApp_CreateProjectDialog(This)	\
    ( (This)->lpVtbl -> CreateProjectDialog(This) ) 

#define IGMEOLEApp_OpenProjectDialog(This)	\
    ( (This)->lpVtbl -> OpenProjectDialog(This) ) 

#define IGMEOLEApp_CloseProject(This,saveOnClose)	\
    ( (This)->lpVtbl -> CloseProject(This,saveOnClose) ) 

#define IGMEOLEApp_SaveProject(This)	\
    ( (This)->lpVtbl -> SaveProject(This) ) 

#define IGMEOLEApp_SaveProjectAs(This,ConnStr)	\
    ( (This)->lpVtbl -> SaveProjectAs(This,ConnStr) ) 

#define IGMEOLEApp_SaveProjectAsDialog(This)	\
    ( (This)->lpVtbl -> SaveProjectAsDialog(This) ) 

#define IGMEOLEApp_ExportProject(This,ConnStr)	\
    ( (This)->lpVtbl -> ExportProject(This,ConnStr) ) 

#define IGMEOLEApp_ImportProject(This,ConnStr)	\
    ( (This)->lpVtbl -> ImportProject(This,ConnStr) ) 

#define IGMEOLEApp_ConstraintsDialog(This)	\
    ( (This)->lpVtbl -> ConstraintsDialog(This) ) 

#define IGMEOLEApp_CheckAllConstraints(This)	\
    ( (This)->lpVtbl -> CheckAllConstraints(This) ) 

#define IGMEOLEApp_RegisterParagimsDialog(This)	\
    ( (This)->lpVtbl -> RegisterParagimsDialog(This) ) 

#define IGMEOLEApp_RegisterComponentsDialog(This)	\
    ( (This)->lpVtbl -> RegisterComponentsDialog(This) ) 

#define IGMEOLEApp_RunComponent(This,progID)	\
    ( (This)->lpVtbl -> RunComponent(This,progID) ) 

#define IGMEOLEApp_RunComponentDialog(This)	\
    ( (This)->lpVtbl -> RunComponentDialog(This) ) 

#define IGMEOLEApp_SettingsDialog(This)	\
    ( (This)->lpVtbl -> SettingsDialog(This) ) 

#define IGMEOLEApp_Undo(This)	\
    ( (This)->lpVtbl -> Undo(This) ) 

#define IGMEOLEApp_Redo(This)	\
    ( (This)->lpVtbl -> Redo(This) ) 

#define IGMEOLEApp_ClearUndoQueue(This)	\
    ( (This)->lpVtbl -> ClearUndoQueue(This) ) 

#define IGMEOLEApp_ProjectPropertiesDialog(This)	\
    ( (This)->lpVtbl -> ProjectPropertiesDialog(This) ) 

#define IGMEOLEApp_ShowHelpContents(This)	\
    ( (This)->lpVtbl -> ShowHelpContents(This) ) 

#define IGMEOLEApp_ShowAbout(This)	\
    ( (This)->lpVtbl -> ShowAbout(This) ) 

#define IGMEOLEApp_ShowFCO(This,mgaFCO,inParent)	\
    ( (This)->lpVtbl -> ShowFCO(This,mgaFCO,inParent) ) 

#define IGMEOLEApp_ConsoleMessage(This,msg,type)	\
    ( (This)->lpVtbl -> ConsoleMessage(This,msg,type) ) 

#define IGMEOLEApp_ConsoleClear(This)	\
    ( (This)->lpVtbl -> ConsoleClear(This) ) 

#define IGMEOLEApp_ConsoleNavigateTo(This,url)	\
    ( (This)->lpVtbl -> ConsoleNavigateTo(This,url) ) 

#define IGMEOLEApp_ChangeEditmode(This,mode)	\
    ( (This)->lpVtbl -> ChangeEditmode(This,mode) ) 

#define IGMEOLEApp_GridShow(This,show)	\
    ( (This)->lpVtbl -> GridShow(This,show) ) 

#define IGMEOLEApp_AttributepanelPage(This,page)	\
    ( (This)->lpVtbl -> AttributepanelPage(This,page) ) 

#define IGMEOLEApp_get_OleIt(This,mgamodel)	\
    ( (This)->lpVtbl -> get_OleIt(This,mgamodel) ) 

#define IGMEOLEApp_DisableComp(This,pCompProgID,pDisable)	\
    ( (This)->lpVtbl -> DisableComp(This,pCompProgID,pDisable) ) 

#define IGMEOLEApp_DisableCompForKinds(This,pCompProgID,pKindSequenceDelimitedBySemicolon)	\
    ( (This)->lpVtbl -> DisableCompForKinds(This,pCompProgID,pKindSequenceDelimitedBySemicolon) ) 

#define IGMEOLEApp_SetCompFiltering(This,pTurnOn)	\
    ( (This)->lpVtbl -> SetCompFiltering(This,pTurnOn) ) 

#define IGMEOLEApp_GetCompFiltering(This,pPtrTurnedOn)	\
    ( (This)->lpVtbl -> GetCompFiltering(This,pPtrTurnedOn) ) 

#define IGMEOLEApp_SetWorkingDirectory(This,pDirPath)	\
    ( (This)->lpVtbl -> SetWorkingDirectory(This,pDirPath) ) 

#define IGMEOLEApp_Exit(This)	\
    ( (This)->lpVtbl -> Exit(This) ) 

#define IGMEOLEApp_RefreshLib(This,pLibName,ungroup,numOfErrors)	\
    ( (This)->lpVtbl -> RefreshLib(This,pLibName,ungroup,numOfErrors) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGMEOLEApp_INTERFACE_DEFINED__ */


#ifndef __IGMEOLEIt_INTERFACE_DEFINED__
#define __IGMEOLEIt_INTERFACE_DEFINED__

/* interface IGMEOLEIt */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IGMEOLEIt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F2181278-749F-459d-8700-92F088B80D72")
    IGMEOLEIt : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Valid( 
            /* [retval][out] */ VARIANT_BOOL *isValid) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Aspects( 
            /* [retval][out] */ IGMEOLEColl **coll) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MgaModel( 
            /* [retval][out] */ IMgaModel **model) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Print( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PrintDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DumpWindowsMetaFile( 
            /* [in] */ BSTR filePath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CheckConstraints( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RunComponent( 
            /* [in] */ BSTR appID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RunComponentDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GrayOutFCO( 
            /* [in] */ VARIANT_BOOL bGray,
            /* [in] */ VARIANT_BOOL bNeighbours,
            /* [in] */ IMgaFCOs *mgaFCO) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GrayOutHide( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowSetMembers( 
            /* [in] */ IMgaFCO *mgaFCO) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE HideSetMembers( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Zoom( 
            /* [in] */ DWORD percent) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ZoomTo( 
            /* [in] */ IMgaFCOs *mgaFCOs) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Scroll( 
            /* [in] */ bar_enum __MIDL__IGMEOLEIt0000,
            /* [in] */ scroll_enum __MIDL__IGMEOLEIt0001) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DumpModelGeometryXML( 
            /* [in] */ BSTR filePath) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ShowFCO( 
            /* [in] */ BSTR path,
            /* [defaultvalue][in] */ VARIANT_BOOL inParent = 0) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ShowFCOPtr( 
            /* [in] */ IMgaFCO *fco,
            /* [defaultvalue][in] */ VARIANT_BOOL inParent = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Child( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IMgaFCO **child_fco) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ BSTR part,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IMgaFCO **new_fco) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateInChild( 
            /* [in] */ BSTR child_as_parent,
            /* [in] */ BSTR part,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IMgaFCO **new_fco) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateInChildFCO( 
            /* [in] */ IMgaFCO *child_as_parent,
            /* [in] */ BSTR part,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IMgaFCO **new_fco) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Duplicate( 
            /* [in] */ BSTR existing_fco_name,
            /* [in] */ BSTR new_fco_name,
            /* [retval][out] */ IMgaFCO **new_fco) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DuplicateFCO( 
            /* [in] */ IMgaFCO *existing_fco,
            /* [in] */ BSTR new_fco_name,
            /* [retval][out] */ IMgaFCO **new_fco) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ BSTR oldname,
            /* [in] */ BSTR newname) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ IMgaFCO *__MIDL__IGMEOLEIt0002,
            /* [in] */ BSTR Name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Include( 
            /* [in] */ BSTR setname,
            /* [in] */ BSTR Name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Exclude( 
            /* [in] */ BSTR setname,
            /* [in] */ BSTR membername) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IncludeFCO( 
            /* [in] */ IMgaSet *p_set,
            /* [in] */ IMgaFCO *fco) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExcludeFCO( 
            /* [in] */ IMgaSet *p_set,
            /* [in] */ IMgaFCO *fco) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ BSTR src_part,
            /* [in] */ BSTR dst_part,
            /* [in] */ BSTR connection_role,
            /* [retval][out] */ IMgaConnection **conn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [in] */ BSTR src_part,
            /* [in] */ BSTR dst_part,
            /* [in] */ BSTR connection_name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ConnectThruPort( 
            /* [in] */ BSTR src_part_1,
            /* [in] */ BSTR src_part_2,
            /* [in] */ BSTR dst_part_1,
            /* [in] */ BSTR dst_part_2,
            /* [in] */ BSTR connection_role,
            /* [retval][out] */ IMgaConnection **conn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConnectThruPortFCO( 
            /* [in] */ IMgaFCO *src_part_1,
            /* [in] */ IMgaFCO *src_part_2,
            /* [in] */ IMgaFCO *dst_part_1,
            /* [in] */ IMgaFCO *dst_part_2,
            /* [in] */ BSTR connection_role,
            /* [retval][out] */ IMgaConnection **conn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisconnectThruPort( 
            /* [in] */ BSTR src_part_1,
            /* [in] */ BSTR src_part_2,
            /* [in] */ BSTR dst_part_1,
            /* [in] */ BSTR dst_part_2,
            /* [in] */ BSTR connection_name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConnectFCOs( 
            /* [in] */ IMgaFCO *src_part,
            /* [in] */ IMgaFCO *dst_part,
            /* [in] */ BSTR connection_role,
            /* [retval][out] */ IMgaConnection **conn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisconnectFCOs( 
            /* [in] */ IMgaFCO *src_part,
            /* [in] */ IMgaFCO *dst_part,
            /* [in] */ BSTR connection_name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Refer( 
            /* [in] */ BSTR reference,
            /* [in] */ BSTR Referred) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearRef( 
            /* [in] */ BSTR reference) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FollowRef( 
            /* [in] */ BSTR reference) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReferFCO( 
            /* [in] */ IMgaReference *reference,
            /* [in] */ IMgaFCO *Referred) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearRefFCO( 
            /* [in] */ IMgaReference *reference) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FollowRefFCO( 
            /* [in] */ IMgaReference *reference) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NullFCO( 
            /* [retval][out] */ IMgaFCO **nullobj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttribute( 
            /* [in] */ BSTR Name,
            /* [in] */ BSTR attr_name,
            /* [in] */ VARIANT value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttribute( 
            /* [in] */ BSTR Name,
            /* [in] */ BSTR attr_name,
            /* [retval][out] */ VARIANT *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttributeFCO( 
            /* [in] */ IMgaFCO *fco,
            /* [in] */ BSTR attr_name,
            /* [in] */ VARIANT value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeFCO( 
            /* [in] */ IMgaFCO *fco,
            /* [in] */ BSTR attr_name,
            /* [retval][out] */ VARIANT *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubType( 
            /* [in] */ BSTR base,
            /* [in] */ BSTR name_of_subtype,
            /* [retval][out] */ IMgaFCO **subtype) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Instantiate( 
            /* [in] */ BSTR base,
            /* [in] */ BSTR name_of_instance,
            /* [retval][out] */ IMgaFCO **instance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubTypeFCO( 
            /* [in] */ IMgaFCO *base,
            /* [in] */ BSTR name_of_subtype,
            /* [retval][out] */ IMgaFCO **subtype) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InstantiateFCO( 
            /* [in] */ IMgaFCO *base,
            /* [in] */ BSTR name_of_instance,
            /* [retval][out] */ IMgaFCO **instance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginTransaction( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitTransaction( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AbortTransaction( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsInTransaction( 
            /* [retval][out] */ VARIANT_BOOL *intrans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutInTerritory( 
            /* [in] */ IMgaFCO *fco,
            /* [retval][out] */ IMgaFCO **newfco) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Help( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSelected( 
            /* [in] */ BSTR space_delimited_string) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSelected( 
            /* [retval][out] */ BSTR *space_delimited_string) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSelectedFCOs( 
            /* [in] */ IMgaFCOs *fcos_to_select) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSelectedFCOs( 
            /* [retval][out] */ IMgaFCOs **selected_fcos) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentAspect( 
            /* [retval][out] */ BSTR *aspectName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCurrentAspect( 
            /* [in] */ BSTR aspectName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE NextAspect( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PrevAspect( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Next( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Prev( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Position( 
            /* [in] */ BSTR child,
            /* [in] */ BSTR aspect,
            /* [in] */ long parX,
            /* [in] */ long parY) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PositionFCO( 
            /* [in] */ IMgaFCO *fco,
            /* [in] */ BSTR aspect,
            /* [in] */ long parX,
            /* [in] */ long parY) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGMEOLEItVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGMEOLEIt * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGMEOLEIt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGMEOLEIt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGMEOLEIt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGMEOLEIt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGMEOLEIt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGMEOLEIt * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Valid )( 
            IGMEOLEIt * This,
            /* [retval][out] */ VARIANT_BOOL *isValid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Aspects )( 
            IGMEOLEIt * This,
            /* [retval][out] */ IGMEOLEColl **coll);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MgaModel )( 
            IGMEOLEIt * This,
            /* [retval][out] */ IMgaModel **model);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Print )( 
            IGMEOLEIt * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PrintDialog )( 
            IGMEOLEIt * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DumpWindowsMetaFile )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR filePath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CheckConstraints )( 
            IGMEOLEIt * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RunComponent )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR appID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RunComponentDialog )( 
            IGMEOLEIt * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IGMEOLEIt * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GrayOutFCO )( 
            IGMEOLEIt * This,
            /* [in] */ VARIANT_BOOL bGray,
            /* [in] */ VARIANT_BOOL bNeighbours,
            /* [in] */ IMgaFCOs *mgaFCO);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GrayOutHide )( 
            IGMEOLEIt * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowSetMembers )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *mgaFCO);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *HideSetMembers )( 
            IGMEOLEIt * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Zoom )( 
            IGMEOLEIt * This,
            /* [in] */ DWORD percent);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ZoomTo )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCOs *mgaFCOs);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Scroll )( 
            IGMEOLEIt * This,
            /* [in] */ bar_enum __MIDL__IGMEOLEIt0000,
            /* [in] */ scroll_enum __MIDL__IGMEOLEIt0001);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DumpModelGeometryXML )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR filePath);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ShowFCO )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR path,
            /* [defaultvalue][in] */ VARIANT_BOOL inParent);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ShowFCOPtr )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *fco,
            /* [defaultvalue][in] */ VARIANT_BOOL inParent);
        
        HRESULT ( STDMETHODCALLTYPE *Child )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IMgaFCO **child_fco);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR part,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IMgaFCO **new_fco);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateInChild )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR child_as_parent,
            /* [in] */ BSTR part,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IMgaFCO **new_fco);
        
        HRESULT ( STDMETHODCALLTYPE *CreateInChildFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *child_as_parent,
            /* [in] */ BSTR part,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IMgaFCO **new_fco);
        
        HRESULT ( STDMETHODCALLTYPE *Duplicate )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR existing_fco_name,
            /* [in] */ BSTR new_fco_name,
            /* [retval][out] */ IMgaFCO **new_fco);
        
        HRESULT ( STDMETHODCALLTYPE *DuplicateFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *existing_fco,
            /* [in] */ BSTR new_fco_name,
            /* [retval][out] */ IMgaFCO **new_fco);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR oldname,
            /* [in] */ BSTR newname);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *__MIDL__IGMEOLEIt0002,
            /* [in] */ BSTR Name);
        
        HRESULT ( STDMETHODCALLTYPE *Include )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR setname,
            /* [in] */ BSTR Name);
        
        HRESULT ( STDMETHODCALLTYPE *Exclude )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR setname,
            /* [in] */ BSTR membername);
        
        HRESULT ( STDMETHODCALLTYPE *IncludeFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaSet *p_set,
            /* [in] */ IMgaFCO *fco);
        
        HRESULT ( STDMETHODCALLTYPE *ExcludeFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaSet *p_set,
            /* [in] */ IMgaFCO *fco);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR src_part,
            /* [in] */ BSTR dst_part,
            /* [in] */ BSTR connection_role,
            /* [retval][out] */ IMgaConnection **conn);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR src_part,
            /* [in] */ BSTR dst_part,
            /* [in] */ BSTR connection_name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConnectThruPort )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR src_part_1,
            /* [in] */ BSTR src_part_2,
            /* [in] */ BSTR dst_part_1,
            /* [in] */ BSTR dst_part_2,
            /* [in] */ BSTR connection_role,
            /* [retval][out] */ IMgaConnection **conn);
        
        HRESULT ( STDMETHODCALLTYPE *ConnectThruPortFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *src_part_1,
            /* [in] */ IMgaFCO *src_part_2,
            /* [in] */ IMgaFCO *dst_part_1,
            /* [in] */ IMgaFCO *dst_part_2,
            /* [in] */ BSTR connection_role,
            /* [retval][out] */ IMgaConnection **conn);
        
        HRESULT ( STDMETHODCALLTYPE *DisconnectThruPort )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR src_part_1,
            /* [in] */ BSTR src_part_2,
            /* [in] */ BSTR dst_part_1,
            /* [in] */ BSTR dst_part_2,
            /* [in] */ BSTR connection_name);
        
        HRESULT ( STDMETHODCALLTYPE *ConnectFCOs )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *src_part,
            /* [in] */ IMgaFCO *dst_part,
            /* [in] */ BSTR connection_role,
            /* [retval][out] */ IMgaConnection **conn);
        
        HRESULT ( STDMETHODCALLTYPE *DisconnectFCOs )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *src_part,
            /* [in] */ IMgaFCO *dst_part,
            /* [in] */ BSTR connection_name);
        
        HRESULT ( STDMETHODCALLTYPE *Refer )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR reference,
            /* [in] */ BSTR Referred);
        
        HRESULT ( STDMETHODCALLTYPE *ClearRef )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR reference);
        
        HRESULT ( STDMETHODCALLTYPE *FollowRef )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR reference);
        
        HRESULT ( STDMETHODCALLTYPE *ReferFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaReference *reference,
            /* [in] */ IMgaFCO *Referred);
        
        HRESULT ( STDMETHODCALLTYPE *ClearRefFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaReference *reference);
        
        HRESULT ( STDMETHODCALLTYPE *FollowRefFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaReference *reference);
        
        HRESULT ( STDMETHODCALLTYPE *NullFCO )( 
            IGMEOLEIt * This,
            /* [retval][out] */ IMgaFCO **nullobj);
        
        HRESULT ( STDMETHODCALLTYPE *SetAttribute )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR attr_name,
            /* [in] */ VARIANT value);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttribute )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR attr_name,
            /* [retval][out] */ VARIANT *value);
        
        HRESULT ( STDMETHODCALLTYPE *SetAttributeFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *fco,
            /* [in] */ BSTR attr_name,
            /* [in] */ VARIANT value);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttributeFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *fco,
            /* [in] */ BSTR attr_name,
            /* [retval][out] */ VARIANT *value);
        
        HRESULT ( STDMETHODCALLTYPE *SubType )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR base,
            /* [in] */ BSTR name_of_subtype,
            /* [retval][out] */ IMgaFCO **subtype);
        
        HRESULT ( STDMETHODCALLTYPE *Instantiate )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR base,
            /* [in] */ BSTR name_of_instance,
            /* [retval][out] */ IMgaFCO **instance);
        
        HRESULT ( STDMETHODCALLTYPE *SubTypeFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *base,
            /* [in] */ BSTR name_of_subtype,
            /* [retval][out] */ IMgaFCO **subtype);
        
        HRESULT ( STDMETHODCALLTYPE *InstantiateFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *base,
            /* [in] */ BSTR name_of_instance,
            /* [retval][out] */ IMgaFCO **instance);
        
        HRESULT ( STDMETHODCALLTYPE *BeginTransaction )( 
            IGMEOLEIt * This);
        
        HRESULT ( STDMETHODCALLTYPE *CommitTransaction )( 
            IGMEOLEIt * This);
        
        HRESULT ( STDMETHODCALLTYPE *AbortTransaction )( 
            IGMEOLEIt * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsInTransaction )( 
            IGMEOLEIt * This,
            /* [retval][out] */ VARIANT_BOOL *intrans);
        
        HRESULT ( STDMETHODCALLTYPE *PutInTerritory )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *fco,
            /* [retval][out] */ IMgaFCO **newfco);
        
        HRESULT ( STDMETHODCALLTYPE *Help )( 
            IGMEOLEIt * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSelected )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR space_delimited_string);
        
        HRESULT ( STDMETHODCALLTYPE *GetSelected )( 
            IGMEOLEIt * This,
            /* [retval][out] */ BSTR *space_delimited_string);
        
        HRESULT ( STDMETHODCALLTYPE *SetSelectedFCOs )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCOs *fcos_to_select);
        
        HRESULT ( STDMETHODCALLTYPE *GetSelectedFCOs )( 
            IGMEOLEIt * This,
            /* [retval][out] */ IMgaFCOs **selected_fcos);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentAspect )( 
            IGMEOLEIt * This,
            /* [retval][out] */ BSTR *aspectName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCurrentAspect )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR aspectName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *NextAspect )( 
            IGMEOLEIt * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PrevAspect )( 
            IGMEOLEIt * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IGMEOLEIt * This);
        
        HRESULT ( STDMETHODCALLTYPE *Prev )( 
            IGMEOLEIt * This);
        
        HRESULT ( STDMETHODCALLTYPE *Position )( 
            IGMEOLEIt * This,
            /* [in] */ BSTR child,
            /* [in] */ BSTR aspect,
            /* [in] */ long parX,
            /* [in] */ long parY);
        
        HRESULT ( STDMETHODCALLTYPE *PositionFCO )( 
            IGMEOLEIt * This,
            /* [in] */ IMgaFCO *fco,
            /* [in] */ BSTR aspect,
            /* [in] */ long parX,
            /* [in] */ long parY);
        
        END_INTERFACE
    } IGMEOLEItVtbl;

    interface IGMEOLEIt
    {
        CONST_VTBL struct IGMEOLEItVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGMEOLEIt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGMEOLEIt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGMEOLEIt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGMEOLEIt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGMEOLEIt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGMEOLEIt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGMEOLEIt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGMEOLEIt_get_Valid(This,isValid)	\
    ( (This)->lpVtbl -> get_Valid(This,isValid) ) 

#define IGMEOLEIt_get_Aspects(This,coll)	\
    ( (This)->lpVtbl -> get_Aspects(This,coll) ) 

#define IGMEOLEIt_get_MgaModel(This,model)	\
    ( (This)->lpVtbl -> get_MgaModel(This,model) ) 

#define IGMEOLEIt_Print(This)	\
    ( (This)->lpVtbl -> Print(This) ) 

#define IGMEOLEIt_PrintDialog(This)	\
    ( (This)->lpVtbl -> PrintDialog(This) ) 

#define IGMEOLEIt_DumpWindowsMetaFile(This,filePath)	\
    ( (This)->lpVtbl -> DumpWindowsMetaFile(This,filePath) ) 

#define IGMEOLEIt_CheckConstraints(This)	\
    ( (This)->lpVtbl -> CheckConstraints(This) ) 

#define IGMEOLEIt_RunComponent(This,appID)	\
    ( (This)->lpVtbl -> RunComponent(This,appID) ) 

#define IGMEOLEIt_RunComponentDialog(This)	\
    ( (This)->lpVtbl -> RunComponentDialog(This) ) 

#define IGMEOLEIt_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IGMEOLEIt_GrayOutFCO(This,bGray,bNeighbours,mgaFCO)	\
    ( (This)->lpVtbl -> GrayOutFCO(This,bGray,bNeighbours,mgaFCO) ) 

#define IGMEOLEIt_GrayOutHide(This)	\
    ( (This)->lpVtbl -> GrayOutHide(This) ) 

#define IGMEOLEIt_ShowSetMembers(This,mgaFCO)	\
    ( (This)->lpVtbl -> ShowSetMembers(This,mgaFCO) ) 

#define IGMEOLEIt_HideSetMembers(This)	\
    ( (This)->lpVtbl -> HideSetMembers(This) ) 

#define IGMEOLEIt_Zoom(This,percent)	\
    ( (This)->lpVtbl -> Zoom(This,percent) ) 

#define IGMEOLEIt_ZoomTo(This,mgaFCOs)	\
    ( (This)->lpVtbl -> ZoomTo(This,mgaFCOs) ) 

#define IGMEOLEIt_Scroll(This,__MIDL__IGMEOLEIt0000,__MIDL__IGMEOLEIt0001)	\
    ( (This)->lpVtbl -> Scroll(This,__MIDL__IGMEOLEIt0000,__MIDL__IGMEOLEIt0001) ) 

#define IGMEOLEIt_DumpModelGeometryXML(This,filePath)	\
    ( (This)->lpVtbl -> DumpModelGeometryXML(This,filePath) ) 

#define IGMEOLEIt_ShowFCO(This,path,inParent)	\
    ( (This)->lpVtbl -> ShowFCO(This,path,inParent) ) 

#define IGMEOLEIt_ShowFCOPtr(This,fco,inParent)	\
    ( (This)->lpVtbl -> ShowFCOPtr(This,fco,inParent) ) 

#define IGMEOLEIt_Child(This,Name,child_fco)	\
    ( (This)->lpVtbl -> Child(This,Name,child_fco) ) 

#define IGMEOLEIt_Create(This,part,Name,new_fco)	\
    ( (This)->lpVtbl -> Create(This,part,Name,new_fco) ) 

#define IGMEOLEIt_CreateInChild(This,child_as_parent,part,Name,new_fco)	\
    ( (This)->lpVtbl -> CreateInChild(This,child_as_parent,part,Name,new_fco) ) 

#define IGMEOLEIt_CreateInChildFCO(This,child_as_parent,part,Name,new_fco)	\
    ( (This)->lpVtbl -> CreateInChildFCO(This,child_as_parent,part,Name,new_fco) ) 

#define IGMEOLEIt_Duplicate(This,existing_fco_name,new_fco_name,new_fco)	\
    ( (This)->lpVtbl -> Duplicate(This,existing_fco_name,new_fco_name,new_fco) ) 

#define IGMEOLEIt_DuplicateFCO(This,existing_fco,new_fco_name,new_fco)	\
    ( (This)->lpVtbl -> DuplicateFCO(This,existing_fco,new_fco_name,new_fco) ) 

#define IGMEOLEIt_Rename(This,oldname,newname)	\
    ( (This)->lpVtbl -> Rename(This,oldname,newname) ) 

#define IGMEOLEIt_SetName(This,__MIDL__IGMEOLEIt0002,Name)	\
    ( (This)->lpVtbl -> SetName(This,__MIDL__IGMEOLEIt0002,Name) ) 

#define IGMEOLEIt_Include(This,setname,Name)	\
    ( (This)->lpVtbl -> Include(This,setname,Name) ) 

#define IGMEOLEIt_Exclude(This,setname,membername)	\
    ( (This)->lpVtbl -> Exclude(This,setname,membername) ) 

#define IGMEOLEIt_IncludeFCO(This,p_set,fco)	\
    ( (This)->lpVtbl -> IncludeFCO(This,p_set,fco) ) 

#define IGMEOLEIt_ExcludeFCO(This,p_set,fco)	\
    ( (This)->lpVtbl -> ExcludeFCO(This,p_set,fco) ) 

#define IGMEOLEIt_Connect(This,src_part,dst_part,connection_role,conn)	\
    ( (This)->lpVtbl -> Connect(This,src_part,dst_part,connection_role,conn) ) 

#define IGMEOLEIt_Disconnect(This,src_part,dst_part,connection_name)	\
    ( (This)->lpVtbl -> Disconnect(This,src_part,dst_part,connection_name) ) 

#define IGMEOLEIt_ConnectThruPort(This,src_part_1,src_part_2,dst_part_1,dst_part_2,connection_role,conn)	\
    ( (This)->lpVtbl -> ConnectThruPort(This,src_part_1,src_part_2,dst_part_1,dst_part_2,connection_role,conn) ) 

#define IGMEOLEIt_ConnectThruPortFCO(This,src_part_1,src_part_2,dst_part_1,dst_part_2,connection_role,conn)	\
    ( (This)->lpVtbl -> ConnectThruPortFCO(This,src_part_1,src_part_2,dst_part_1,dst_part_2,connection_role,conn) ) 

#define IGMEOLEIt_DisconnectThruPort(This,src_part_1,src_part_2,dst_part_1,dst_part_2,connection_name)	\
    ( (This)->lpVtbl -> DisconnectThruPort(This,src_part_1,src_part_2,dst_part_1,dst_part_2,connection_name) ) 

#define IGMEOLEIt_ConnectFCOs(This,src_part,dst_part,connection_role,conn)	\
    ( (This)->lpVtbl -> ConnectFCOs(This,src_part,dst_part,connection_role,conn) ) 

#define IGMEOLEIt_DisconnectFCOs(This,src_part,dst_part,connection_name)	\
    ( (This)->lpVtbl -> DisconnectFCOs(This,src_part,dst_part,connection_name) ) 

#define IGMEOLEIt_Refer(This,reference,Referred)	\
    ( (This)->lpVtbl -> Refer(This,reference,Referred) ) 

#define IGMEOLEIt_ClearRef(This,reference)	\
    ( (This)->lpVtbl -> ClearRef(This,reference) ) 

#define IGMEOLEIt_FollowRef(This,reference)	\
    ( (This)->lpVtbl -> FollowRef(This,reference) ) 

#define IGMEOLEIt_ReferFCO(This,reference,Referred)	\
    ( (This)->lpVtbl -> ReferFCO(This,reference,Referred) ) 

#define IGMEOLEIt_ClearRefFCO(This,reference)	\
    ( (This)->lpVtbl -> ClearRefFCO(This,reference) ) 

#define IGMEOLEIt_FollowRefFCO(This,reference)	\
    ( (This)->lpVtbl -> FollowRefFCO(This,reference) ) 

#define IGMEOLEIt_NullFCO(This,nullobj)	\
    ( (This)->lpVtbl -> NullFCO(This,nullobj) ) 

#define IGMEOLEIt_SetAttribute(This,Name,attr_name,value)	\
    ( (This)->lpVtbl -> SetAttribute(This,Name,attr_name,value) ) 

#define IGMEOLEIt_GetAttribute(This,Name,attr_name,value)	\
    ( (This)->lpVtbl -> GetAttribute(This,Name,attr_name,value) ) 

#define IGMEOLEIt_SetAttributeFCO(This,fco,attr_name,value)	\
    ( (This)->lpVtbl -> SetAttributeFCO(This,fco,attr_name,value) ) 

#define IGMEOLEIt_GetAttributeFCO(This,fco,attr_name,value)	\
    ( (This)->lpVtbl -> GetAttributeFCO(This,fco,attr_name,value) ) 

#define IGMEOLEIt_SubType(This,base,name_of_subtype,subtype)	\
    ( (This)->lpVtbl -> SubType(This,base,name_of_subtype,subtype) ) 

#define IGMEOLEIt_Instantiate(This,base,name_of_instance,instance)	\
    ( (This)->lpVtbl -> Instantiate(This,base,name_of_instance,instance) ) 

#define IGMEOLEIt_SubTypeFCO(This,base,name_of_subtype,subtype)	\
    ( (This)->lpVtbl -> SubTypeFCO(This,base,name_of_subtype,subtype) ) 

#define IGMEOLEIt_InstantiateFCO(This,base,name_of_instance,instance)	\
    ( (This)->lpVtbl -> InstantiateFCO(This,base,name_of_instance,instance) ) 

#define IGMEOLEIt_BeginTransaction(This)	\
    ( (This)->lpVtbl -> BeginTransaction(This) ) 

#define IGMEOLEIt_CommitTransaction(This)	\
    ( (This)->lpVtbl -> CommitTransaction(This) ) 

#define IGMEOLEIt_AbortTransaction(This)	\
    ( (This)->lpVtbl -> AbortTransaction(This) ) 

#define IGMEOLEIt_IsInTransaction(This,intrans)	\
    ( (This)->lpVtbl -> IsInTransaction(This,intrans) ) 

#define IGMEOLEIt_PutInTerritory(This,fco,newfco)	\
    ( (This)->lpVtbl -> PutInTerritory(This,fco,newfco) ) 

#define IGMEOLEIt_Help(This)	\
    ( (This)->lpVtbl -> Help(This) ) 

#define IGMEOLEIt_SetSelected(This,space_delimited_string)	\
    ( (This)->lpVtbl -> SetSelected(This,space_delimited_string) ) 

#define IGMEOLEIt_GetSelected(This,space_delimited_string)	\
    ( (This)->lpVtbl -> GetSelected(This,space_delimited_string) ) 

#define IGMEOLEIt_SetSelectedFCOs(This,fcos_to_select)	\
    ( (This)->lpVtbl -> SetSelectedFCOs(This,fcos_to_select) ) 

#define IGMEOLEIt_GetSelectedFCOs(This,selected_fcos)	\
    ( (This)->lpVtbl -> GetSelectedFCOs(This,selected_fcos) ) 

#define IGMEOLEIt_GetCurrentAspect(This,aspectName)	\
    ( (This)->lpVtbl -> GetCurrentAspect(This,aspectName) ) 

#define IGMEOLEIt_SetCurrentAspect(This,aspectName)	\
    ( (This)->lpVtbl -> SetCurrentAspect(This,aspectName) ) 

#define IGMEOLEIt_NextAspect(This)	\
    ( (This)->lpVtbl -> NextAspect(This) ) 

#define IGMEOLEIt_PrevAspect(This)	\
    ( (This)->lpVtbl -> PrevAspect(This) ) 

#define IGMEOLEIt_Next(This)	\
    ( (This)->lpVtbl -> Next(This) ) 

#define IGMEOLEIt_Prev(This)	\
    ( (This)->lpVtbl -> Prev(This) ) 

#define IGMEOLEIt_Position(This,child,aspect,parX,parY)	\
    ( (This)->lpVtbl -> Position(This,child,aspect,parX,parY) ) 

#define IGMEOLEIt_PositionFCO(This,fco,aspect,parX,parY)	\
    ( (This)->lpVtbl -> PositionFCO(This,fco,aspect,parX,parY) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGMEOLEIt_INTERFACE_DEFINED__ */


#ifndef __IGMEOLEModel_INTERFACE_DEFINED__
#define __IGMEOLEModel_INTERFACE_DEFINED__

/* interface IGMEOLEModel */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IGMEOLEModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("399A16A0-D209-4d00-9BDF-858D87EC4641")
    IGMEOLEModel : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL isActive) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *isActive) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Aspects( 
            /* [retval][out] */ IGMEOLEColl **coll) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MgaModel( 
            /* [retval][out] */ IMgaModel **model) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Valid( 
            /* [retval][out] */ VARIANT_BOOL *isValid) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Print( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PrintDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DumpWindowsMetaFile( 
            /* [in] */ BSTR filePath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CheckConstraints( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RunComponent( 
            /* [in] */ BSTR appID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RunComponentDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GrayOutFCO( 
            /* [in] */ VARIANT_BOOL bGray,
            /* [in] */ VARIANT_BOOL bNeighbours,
            /* [in] */ IMgaFCOs *mgaFCO) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GrayOutHide( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowSetMembers( 
            /* [in] */ IMgaFCO *mgaFCO) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE HideSetMembers( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Zoom( 
            /* [in] */ DWORD percent) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ZoomTo( 
            /* [in] */ IMgaFCOs *mgaFCOs) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Scroll( 
            /* [in] */ bar_enum __MIDL__IGMEOLEModel0000,
            /* [in] */ scroll_enum __MIDL__IGMEOLEModel0001) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DumpModelGeometryXML( 
            /* [in] */ BSTR filePath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurrentAspect( 
            /* [retval][out] */ BSTR *aspectName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCurrentAspect( 
            /* [in] */ BSTR aspectName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGMEOLEModelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGMEOLEModel * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGMEOLEModel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGMEOLEModel * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGMEOLEModel * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGMEOLEModel * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGMEOLEModel * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGMEOLEModel * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IGMEOLEModel * This,
            /* [in] */ VARIANT_BOOL isActive);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IGMEOLEModel * This,
            /* [retval][out] */ VARIANT_BOOL *isActive);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Aspects )( 
            IGMEOLEModel * This,
            /* [retval][out] */ IGMEOLEColl **coll);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MgaModel )( 
            IGMEOLEModel * This,
            /* [retval][out] */ IMgaModel **model);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Valid )( 
            IGMEOLEModel * This,
            /* [retval][out] */ VARIANT_BOOL *isValid);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Print )( 
            IGMEOLEModel * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PrintDialog )( 
            IGMEOLEModel * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DumpWindowsMetaFile )( 
            IGMEOLEModel * This,
            /* [in] */ BSTR filePath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CheckConstraints )( 
            IGMEOLEModel * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RunComponent )( 
            IGMEOLEModel * This,
            /* [in] */ BSTR appID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RunComponentDialog )( 
            IGMEOLEModel * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IGMEOLEModel * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GrayOutFCO )( 
            IGMEOLEModel * This,
            /* [in] */ VARIANT_BOOL bGray,
            /* [in] */ VARIANT_BOOL bNeighbours,
            /* [in] */ IMgaFCOs *mgaFCO);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GrayOutHide )( 
            IGMEOLEModel * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowSetMembers )( 
            IGMEOLEModel * This,
            /* [in] */ IMgaFCO *mgaFCO);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *HideSetMembers )( 
            IGMEOLEModel * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Zoom )( 
            IGMEOLEModel * This,
            /* [in] */ DWORD percent);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ZoomTo )( 
            IGMEOLEModel * This,
            /* [in] */ IMgaFCOs *mgaFCOs);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Scroll )( 
            IGMEOLEModel * This,
            /* [in] */ bar_enum __MIDL__IGMEOLEModel0000,
            /* [in] */ scroll_enum __MIDL__IGMEOLEModel0001);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DumpModelGeometryXML )( 
            IGMEOLEModel * This,
            /* [in] */ BSTR filePath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentAspect )( 
            IGMEOLEModel * This,
            /* [retval][out] */ BSTR *aspectName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCurrentAspect )( 
            IGMEOLEModel * This,
            /* [in] */ BSTR aspectName);
        
        END_INTERFACE
    } IGMEOLEModelVtbl;

    interface IGMEOLEModel
    {
        CONST_VTBL struct IGMEOLEModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGMEOLEModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGMEOLEModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGMEOLEModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGMEOLEModel_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGMEOLEModel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGMEOLEModel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGMEOLEModel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGMEOLEModel_put_Active(This,isActive)	\
    ( (This)->lpVtbl -> put_Active(This,isActive) ) 

#define IGMEOLEModel_get_Active(This,isActive)	\
    ( (This)->lpVtbl -> get_Active(This,isActive) ) 

#define IGMEOLEModel_get_Aspects(This,coll)	\
    ( (This)->lpVtbl -> get_Aspects(This,coll) ) 

#define IGMEOLEModel_get_MgaModel(This,model)	\
    ( (This)->lpVtbl -> get_MgaModel(This,model) ) 

#define IGMEOLEModel_get_Valid(This,isValid)	\
    ( (This)->lpVtbl -> get_Valid(This,isValid) ) 

#define IGMEOLEModel_Print(This)	\
    ( (This)->lpVtbl -> Print(This) ) 

#define IGMEOLEModel_PrintDialog(This)	\
    ( (This)->lpVtbl -> PrintDialog(This) ) 

#define IGMEOLEModel_DumpWindowsMetaFile(This,filePath)	\
    ( (This)->lpVtbl -> DumpWindowsMetaFile(This,filePath) ) 

#define IGMEOLEModel_CheckConstraints(This)	\
    ( (This)->lpVtbl -> CheckConstraints(This) ) 

#define IGMEOLEModel_RunComponent(This,appID)	\
    ( (This)->lpVtbl -> RunComponent(This,appID) ) 

#define IGMEOLEModel_RunComponentDialog(This)	\
    ( (This)->lpVtbl -> RunComponentDialog(This) ) 

#define IGMEOLEModel_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IGMEOLEModel_GrayOutFCO(This,bGray,bNeighbours,mgaFCO)	\
    ( (This)->lpVtbl -> GrayOutFCO(This,bGray,bNeighbours,mgaFCO) ) 

#define IGMEOLEModel_GrayOutHide(This)	\
    ( (This)->lpVtbl -> GrayOutHide(This) ) 

#define IGMEOLEModel_ShowSetMembers(This,mgaFCO)	\
    ( (This)->lpVtbl -> ShowSetMembers(This,mgaFCO) ) 

#define IGMEOLEModel_HideSetMembers(This)	\
    ( (This)->lpVtbl -> HideSetMembers(This) ) 

#define IGMEOLEModel_Zoom(This,percent)	\
    ( (This)->lpVtbl -> Zoom(This,percent) ) 

#define IGMEOLEModel_ZoomTo(This,mgaFCOs)	\
    ( (This)->lpVtbl -> ZoomTo(This,mgaFCOs) ) 

#define IGMEOLEModel_Scroll(This,__MIDL__IGMEOLEModel0000,__MIDL__IGMEOLEModel0001)	\
    ( (This)->lpVtbl -> Scroll(This,__MIDL__IGMEOLEModel0000,__MIDL__IGMEOLEModel0001) ) 

#define IGMEOLEModel_DumpModelGeometryXML(This,filePath)	\
    ( (This)->lpVtbl -> DumpModelGeometryXML(This,filePath) ) 

#define IGMEOLEModel_GetCurrentAspect(This,aspectName)	\
    ( (This)->lpVtbl -> GetCurrentAspect(This,aspectName) ) 

#define IGMEOLEModel_SetCurrentAspect(This,aspectName)	\
    ( (This)->lpVtbl -> SetCurrentAspect(This,aspectName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGMEOLEModel_INTERFACE_DEFINED__ */


#ifndef __IGMEOLEAspect_INTERFACE_DEFINED__
#define __IGMEOLEAspect_INTERFACE_DEFINED__

/* interface IGMEOLEAspect */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IGMEOLEAspect;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EDEEB1F8-BC44-40d2-BE91-83E8CCD59845")
    IGMEOLEAspect : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MgaAspect( 
            /* [retval][out] */ IMgaMetaAspect **aspect) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL isActive) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *isActive) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Valid( 
            /* [retval][out] */ VARIANT_BOOL *isValid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGMEOLEAspectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGMEOLEAspect * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGMEOLEAspect * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGMEOLEAspect * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGMEOLEAspect * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGMEOLEAspect * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGMEOLEAspect * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGMEOLEAspect * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MgaAspect )( 
            IGMEOLEAspect * This,
            /* [retval][out] */ IMgaMetaAspect **aspect);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IGMEOLEAspect * This,
            /* [in] */ VARIANT_BOOL isActive);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IGMEOLEAspect * This,
            /* [retval][out] */ VARIANT_BOOL *isActive);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Valid )( 
            IGMEOLEAspect * This,
            /* [retval][out] */ VARIANT_BOOL *isValid);
        
        END_INTERFACE
    } IGMEOLEAspectVtbl;

    interface IGMEOLEAspect
    {
        CONST_VTBL struct IGMEOLEAspectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGMEOLEAspect_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGMEOLEAspect_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGMEOLEAspect_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGMEOLEAspect_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGMEOLEAspect_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGMEOLEAspect_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGMEOLEAspect_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGMEOLEAspect_get_MgaAspect(This,aspect)	\
    ( (This)->lpVtbl -> get_MgaAspect(This,aspect) ) 

#define IGMEOLEAspect_put_Active(This,isActive)	\
    ( (This)->lpVtbl -> put_Active(This,isActive) ) 

#define IGMEOLEAspect_get_Active(This,isActive)	\
    ( (This)->lpVtbl -> get_Active(This,isActive) ) 

#define IGMEOLEAspect_get_Valid(This,isValid)	\
    ( (This)->lpVtbl -> get_Valid(This,isValid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGMEOLEAspect_INTERFACE_DEFINED__ */


#ifndef __IGMEOLEPanel_INTERFACE_DEFINED__
#define __IGMEOLEPanel_INTERFACE_DEFINED__

/* interface IGMEOLEPanel */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IGMEOLEPanel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C047FAEB-7AE7-40fb-8C5C-90C73DAD4BC6")
    IGMEOLEPanel : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *Name) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL isVisible) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *isVisible) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Interface( 
            /* [retval][out] */ IDispatch **interf) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGMEOLEPanelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGMEOLEPanel * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGMEOLEPanel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGMEOLEPanel * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGMEOLEPanel * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGMEOLEPanel * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGMEOLEPanel * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGMEOLEPanel * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGMEOLEPanel * This,
            /* [retval][out] */ BSTR *Name);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGMEOLEPanel * This,
            /* [in] */ VARIANT_BOOL isVisible);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGMEOLEPanel * This,
            /* [retval][out] */ VARIANT_BOOL *isVisible);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Interface )( 
            IGMEOLEPanel * This,
            /* [retval][out] */ IDispatch **interf);
        
        END_INTERFACE
    } IGMEOLEPanelVtbl;

    interface IGMEOLEPanel
    {
        CONST_VTBL struct IGMEOLEPanelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGMEOLEPanel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGMEOLEPanel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGMEOLEPanel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGMEOLEPanel_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGMEOLEPanel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGMEOLEPanel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGMEOLEPanel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGMEOLEPanel_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IGMEOLEPanel_put_Visible(This,isVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,isVisible) ) 

#define IGMEOLEPanel_get_Visible(This,isVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,isVisible) ) 

#define IGMEOLEPanel_get_Interface(This,interf)	\
    ( (This)->lpVtbl -> get_Interface(This,interf) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGMEOLEPanel_INTERFACE_DEFINED__ */


#ifndef __IGMEOLEColl_INTERFACE_DEFINED__
#define __IGMEOLEColl_INTERFACE_DEFINED__

/* interface IGMEOLEColl */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IGMEOLEColl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("36C7B797-6BDE-46d0-8870-70189000EDF9")
    IGMEOLEColl : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            IDispatch *newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Find( 
            IDispatch *findValue,
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            VARIANT removeValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            long nIndex,
            /* [retval][out] */ IDispatch **val) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Item( 
            long nIndex,
            IDispatch *newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **e) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGMEOLECollVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGMEOLEColl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGMEOLEColl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGMEOLEColl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGMEOLEColl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGMEOLEColl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGMEOLEColl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGMEOLEColl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGMEOLEColl * This,
            /* [retval][out] */ long *cnt);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IGMEOLEColl * This,
            IDispatch *newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            IGMEOLEColl * This,
            IDispatch *findValue,
            /* [retval][out] */ long *cnt);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IGMEOLEColl * This,
            VARIANT removeValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAll )( 
            IGMEOLEColl * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IGMEOLEColl * This,
            long nIndex,
            /* [retval][out] */ IDispatch **val);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Item )( 
            IGMEOLEColl * This,
            long nIndex,
            IDispatch *newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGMEOLEColl * This,
            /* [retval][out] */ IUnknown **e);
        
        END_INTERFACE
    } IGMEOLECollVtbl;

    interface IGMEOLEColl
    {
        CONST_VTBL struct IGMEOLECollVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGMEOLEColl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGMEOLEColl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGMEOLEColl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGMEOLEColl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGMEOLEColl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGMEOLEColl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGMEOLEColl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGMEOLEColl_get_Count(This,cnt)	\
    ( (This)->lpVtbl -> get_Count(This,cnt) ) 

#define IGMEOLEColl_Add(This,newValue)	\
    ( (This)->lpVtbl -> Add(This,newValue) ) 

#define IGMEOLEColl_Find(This,findValue,cnt)	\
    ( (This)->lpVtbl -> Find(This,findValue,cnt) ) 

#define IGMEOLEColl_Remove(This,removeValue)	\
    ( (This)->lpVtbl -> Remove(This,removeValue) ) 

#define IGMEOLEColl_RemoveAll(This)	\
    ( (This)->lpVtbl -> RemoveAll(This) ) 

#define IGMEOLEColl_get_Item(This,nIndex,val)	\
    ( (This)->lpVtbl -> get_Item(This,nIndex,val) ) 

#define IGMEOLEColl_put_Item(This,nIndex,newValue)	\
    ( (This)->lpVtbl -> put_Item(This,nIndex,newValue) ) 

#define IGMEOLEColl_get__NewEnum(This,e)	\
    ( (This)->lpVtbl -> get__NewEnum(This,e) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGMEOLEColl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ConnectorInstance_Decorator_0000_0007 */
/* [local] */ 

typedef 
enum decorator_error
    {	E_DECORATOR_UNKNOWN_PARAMETER	= 0x80737001,
	E_DECORATOR_INIT_WITH_NULL	= 0x80737002,
	E_DECORATOR_UNINITIALIZED	= 0x80737003,
	E_DECORATOR_LOCISNOTSET	= 0x80737004,
	E_DECORATOR_PORTNOTFOUND	= 0x80737005,
	E_DECORATOR_USING_DEPRECATED_FUNCTION	= 0x80737006,
	E_DECORATOR_NOT_IMPLEMENTED	= 0x80737007,
	S_DECORATOR_EVENT_HANDLED	= 0x737001,
	S_DECORATOR_EVENT_NOT_HANDLED	= 0x737002
    } 	decorator_error;

typedef unsigned long feature_code;

#define	F_RESIZABLE	( ( 1 << 0 )  )

#define	F_MOUSEEVENTS	( ( 1 << 1 )  )

#define	F_HASLABEL	( ( 1 << 2 )  )

#define	F_HASSTATE	( ( 1 << 3 )  )

#define	F_HASPORTS	( ( 1 << 4 )  )

#define	F_ANIMATION	( ( 1 << 5 )  )

#define	F_IMGPATH	( ( 1 << 6 )  )

#define	F_RESIZEAFTERMOD	( ( 1 << 7 )  )

typedef 
enum refresh_mode_enum
    {	RM_NOREFRESH	= 0,
	RM_REDRAW_SELF	= 1,
	RM_REGENERATE_SELF	= 2,
	RM_REGENERATE_PARENT_ALSO	= 3,
	RM_REGENERATE_ALL_VIEWS	= 4
    } 	refresh_mode_enum;



extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0007_v0_0_s_ifspec;

#ifndef __IMgaDecorator_INTERFACE_DEFINED__
#define __IMgaDecorator_INTERFACE_DEFINED__

/* interface IMgaDecorator */
/* [unique][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IMgaDecorator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1E13054E-5AD1-41EB-8FF1-C3901D99FDCC")
    IMgaDecorator : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IMgaProject *p,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMnemonic( 
            /* [out] */ BSTR *mnemonic) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFeatures( 
            /* [out] */ feature_code *features) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetParam( 
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParam( 
            /* [in] */ BSTR Name,
            /* [out] */ VARIANT *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetActive( 
            /* [in] */ VARIANT_BOOL isActive) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPreferredSize( 
            /* [out] */ long *sizex,
            /* [out] */ long *sizey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLocation( 
            /* [in] */ long sx,
            /* [in] */ long sy,
            /* [in] */ long ex,
            /* [in] */ long ey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLocation( 
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLabelLocation( 
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPortLocation( 
            /* [in] */ IMgaFCO *fco,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPorts( 
            /* [retval][out] */ IMgaFCOs **portFCOs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Draw( 
            /* [in] */ ULONG hdc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveState( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMgaDecoratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMgaDecorator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMgaDecorator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMgaDecorator * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IMgaDecorator * This,
            /* [in] */ IMgaProject *p,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            IMgaDecorator * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMnemonic )( 
            IMgaDecorator * This,
            /* [out] */ BSTR *mnemonic);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeatures )( 
            IMgaDecorator * This,
            /* [out] */ feature_code *features);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetParam )( 
            IMgaDecorator * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            IMgaDecorator * This,
            /* [in] */ BSTR Name,
            /* [out] */ VARIANT *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetActive )( 
            IMgaDecorator * This,
            /* [in] */ VARIANT_BOOL isActive);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredSize )( 
            IMgaDecorator * This,
            /* [out] */ long *sizex,
            /* [out] */ long *sizey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLocation )( 
            IMgaDecorator * This,
            /* [in] */ long sx,
            /* [in] */ long sy,
            /* [in] */ long ex,
            /* [in] */ long ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLocation )( 
            IMgaDecorator * This,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLabelLocation )( 
            IMgaDecorator * This,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPortLocation )( 
            IMgaDecorator * This,
            /* [in] */ IMgaFCO *fco,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPorts )( 
            IMgaDecorator * This,
            /* [retval][out] */ IMgaFCOs **portFCOs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IMgaDecorator * This,
            /* [in] */ ULONG hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveState )( 
            IMgaDecorator * This);
        
        END_INTERFACE
    } IMgaDecoratorVtbl;

    interface IMgaDecorator
    {
        CONST_VTBL struct IMgaDecoratorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMgaDecorator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMgaDecorator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMgaDecorator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMgaDecorator_Initialize(This,p,meta,obj)	\
    ( (This)->lpVtbl -> Initialize(This,p,meta,obj) ) 

#define IMgaDecorator_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IMgaDecorator_GetMnemonic(This,mnemonic)	\
    ( (This)->lpVtbl -> GetMnemonic(This,mnemonic) ) 

#define IMgaDecorator_GetFeatures(This,features)	\
    ( (This)->lpVtbl -> GetFeatures(This,features) ) 

#define IMgaDecorator_SetParam(This,Name,value)	\
    ( (This)->lpVtbl -> SetParam(This,Name,value) ) 

#define IMgaDecorator_GetParam(This,Name,value)	\
    ( (This)->lpVtbl -> GetParam(This,Name,value) ) 

#define IMgaDecorator_SetActive(This,isActive)	\
    ( (This)->lpVtbl -> SetActive(This,isActive) ) 

#define IMgaDecorator_GetPreferredSize(This,sizex,sizey)	\
    ( (This)->lpVtbl -> GetPreferredSize(This,sizex,sizey) ) 

#define IMgaDecorator_SetLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> SetLocation(This,sx,sy,ex,ey) ) 

#define IMgaDecorator_GetLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetLocation(This,sx,sy,ex,ey) ) 

#define IMgaDecorator_GetLabelLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetLabelLocation(This,sx,sy,ex,ey) ) 

#define IMgaDecorator_GetPortLocation(This,fco,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetPortLocation(This,fco,sx,sy,ex,ey) ) 

#define IMgaDecorator_GetPorts(This,portFCOs)	\
    ( (This)->lpVtbl -> GetPorts(This,portFCOs) ) 

#define IMgaDecorator_Draw(This,hdc)	\
    ( (This)->lpVtbl -> Draw(This,hdc) ) 

#define IMgaDecorator_SaveState(This)	\
    ( (This)->lpVtbl -> SaveState(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMgaDecorator_INTERFACE_DEFINED__ */


#ifndef __IMgaCommonDecoratorEvents_INTERFACE_DEFINED__
#define __IMgaCommonDecoratorEvents_INTERFACE_DEFINED__

/* interface IMgaCommonDecoratorEvents */
/* [unique][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IMgaCommonDecoratorEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D25188F5-3ECF-433e-85C5-8B9574CA264C")
    IMgaCommonDecoratorEvents : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ refresh_mode_enum refreshMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OperationCanceled( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CursorChanged( 
            /* [in] */ LONG newCursorID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CursorRestored( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelEditingStarted( 
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelEditingFinished( 
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelChanged( 
            /* [in] */ BSTR newLabel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelMovingStarted( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelMoving( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelMovingFinished( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelMoved( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelResizingStarted( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelResizing( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelResizingFinished( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LabelResized( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GeneralOperationStarted( 
            /* [in] */ ULONGLONG operationData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GeneralOperationFinished( 
            /* [out] */ ULONGLONG *operationData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMgaCommonDecoratorEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMgaCommonDecoratorEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMgaCommonDecoratorEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ refresh_mode_enum refreshMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OperationCanceled )( 
            IMgaCommonDecoratorEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CursorChanged )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG newCursorID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CursorRestored )( 
            IMgaCommonDecoratorEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelEditingStarted )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelEditingFinished )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelChanged )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ BSTR newLabel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelMovingStarted )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelMoving )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelMovingFinished )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelMoved )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelResizingStarted )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelResizing )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelResizingFinished )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelResized )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GeneralOperationStarted )( 
            IMgaCommonDecoratorEvents * This,
            /* [in] */ ULONGLONG operationData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GeneralOperationFinished )( 
            IMgaCommonDecoratorEvents * This,
            /* [out] */ ULONGLONG *operationData);
        
        END_INTERFACE
    } IMgaCommonDecoratorEventsVtbl;

    interface IMgaCommonDecoratorEvents
    {
        CONST_VTBL struct IMgaCommonDecoratorEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMgaCommonDecoratorEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMgaCommonDecoratorEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMgaCommonDecoratorEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMgaCommonDecoratorEvents_Refresh(This,refreshMode)	\
    ( (This)->lpVtbl -> Refresh(This,refreshMode) ) 

#define IMgaCommonDecoratorEvents_OperationCanceled(This)	\
    ( (This)->lpVtbl -> OperationCanceled(This) ) 

#define IMgaCommonDecoratorEvents_CursorChanged(This,newCursorID)	\
    ( (This)->lpVtbl -> CursorChanged(This,newCursorID) ) 

#define IMgaCommonDecoratorEvents_CursorRestored(This)	\
    ( (This)->lpVtbl -> CursorRestored(This) ) 

#define IMgaCommonDecoratorEvents_LabelEditingStarted(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelEditingStarted(This,left,top,right,bottom) ) 

#define IMgaCommonDecoratorEvents_LabelEditingFinished(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelEditingFinished(This,left,top,right,bottom) ) 

#define IMgaCommonDecoratorEvents_LabelChanged(This,newLabel)	\
    ( (This)->lpVtbl -> LabelChanged(This,newLabel) ) 

#define IMgaCommonDecoratorEvents_LabelMovingStarted(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelMovingStarted(This,nFlags,left,top,right,bottom) ) 

#define IMgaCommonDecoratorEvents_LabelMoving(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelMoving(This,nFlags,left,top,right,bottom) ) 

#define IMgaCommonDecoratorEvents_LabelMovingFinished(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelMovingFinished(This,nFlags,left,top,right,bottom) ) 

#define IMgaCommonDecoratorEvents_LabelMoved(This,nFlags,x,y)	\
    ( (This)->lpVtbl -> LabelMoved(This,nFlags,x,y) ) 

#define IMgaCommonDecoratorEvents_LabelResizingStarted(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelResizingStarted(This,nFlags,left,top,right,bottom) ) 

#define IMgaCommonDecoratorEvents_LabelResizing(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelResizing(This,nFlags,left,top,right,bottom) ) 

#define IMgaCommonDecoratorEvents_LabelResizingFinished(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelResizingFinished(This,nFlags,left,top,right,bottom) ) 

#define IMgaCommonDecoratorEvents_LabelResized(This,nFlags,cx,cy)	\
    ( (This)->lpVtbl -> LabelResized(This,nFlags,cx,cy) ) 

#define IMgaCommonDecoratorEvents_GeneralOperationStarted(This,operationData)	\
    ( (This)->lpVtbl -> GeneralOperationStarted(This,operationData) ) 

#define IMgaCommonDecoratorEvents_GeneralOperationFinished(This,operationData)	\
    ( (This)->lpVtbl -> GeneralOperationFinished(This,operationData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMgaCommonDecoratorEvents_INTERFACE_DEFINED__ */


#ifndef __IMgaDecoratorCommon_INTERFACE_DEFINED__
#define __IMgaDecoratorCommon_INTERFACE_DEFINED__

/* interface IMgaDecoratorCommon */
/* [unique][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IMgaDecoratorCommon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91004115-2D1F-44a8-B6A0-09A2750BF278")
    IMgaDecoratorCommon : public IMgaDecorator
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitializeEx( 
            /* [in] */ IMgaProject *p,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj,
            /* [in] */ IMgaCommonDecoratorEvents *eventSink,
            /* [in] */ ULONGLONG parentWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawEx( 
            /* [in] */ ULONG hdc,
            /* [in] */ ULONGLONG gdip) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSelected( 
            /* [in] */ VARIANT_BOOL isSelected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseMoved( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseLeftButtonDown( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseLeftButtonUp( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseLeftButtonDoubleClick( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseRightButtonDown( 
            /* [in] */ ULONGLONG hCtxMenu,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseRightButtonUp( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseRightButtonDoubleClick( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseMiddleButtonDown( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseMiddleButtonUp( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseMiddleButtonDoubleClick( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MouseWheelTurned( 
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG distance,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MenuItemSelected( 
            /* [in] */ ULONG menuItemId,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OperationCanceled( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragEnter( 
            /* [out] */ ULONG *dropEffect,
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG keyState,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragOver( 
            /* [out] */ ULONG *dropEffect,
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG keyState,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Drop( 
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG dropEffect,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DropFile( 
            /* [in] */ ULONGLONG hDropInfo,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMgaDecoratorCommonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMgaDecoratorCommon * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMgaDecoratorCommon * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMgaDecoratorCommon * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IMgaDecoratorCommon * This,
            /* [in] */ IMgaProject *p,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            IMgaDecoratorCommon * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMnemonic )( 
            IMgaDecoratorCommon * This,
            /* [out] */ BSTR *mnemonic);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeatures )( 
            IMgaDecoratorCommon * This,
            /* [out] */ feature_code *features);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetParam )( 
            IMgaDecoratorCommon * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            IMgaDecoratorCommon * This,
            /* [in] */ BSTR Name,
            /* [out] */ VARIANT *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetActive )( 
            IMgaDecoratorCommon * This,
            /* [in] */ VARIANT_BOOL isActive);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredSize )( 
            IMgaDecoratorCommon * This,
            /* [out] */ long *sizex,
            /* [out] */ long *sizey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLocation )( 
            IMgaDecoratorCommon * This,
            /* [in] */ long sx,
            /* [in] */ long sy,
            /* [in] */ long ex,
            /* [in] */ long ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLocation )( 
            IMgaDecoratorCommon * This,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLabelLocation )( 
            IMgaDecoratorCommon * This,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPortLocation )( 
            IMgaDecoratorCommon * This,
            /* [in] */ IMgaFCO *fco,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPorts )( 
            IMgaDecoratorCommon * This,
            /* [retval][out] */ IMgaFCOs **portFCOs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveState )( 
            IMgaDecoratorCommon * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeEx )( 
            IMgaDecoratorCommon * This,
            /* [in] */ IMgaProject *p,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj,
            /* [in] */ IMgaCommonDecoratorEvents *eventSink,
            /* [in] */ ULONGLONG parentWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawEx )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG hdc,
            /* [in] */ ULONGLONG gdip);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSelected )( 
            IMgaDecoratorCommon * This,
            /* [in] */ VARIANT_BOOL isSelected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseMoved )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseLeftButtonDown )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseLeftButtonUp )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseLeftButtonDoubleClick )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseRightButtonDown )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONGLONG hCtxMenu,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseRightButtonUp )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseRightButtonDoubleClick )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseMiddleButtonDown )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseMiddleButtonUp )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseMiddleButtonDoubleClick )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseWheelTurned )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG distance,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MenuItemSelected )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONG menuItemId,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OperationCanceled )( 
            IMgaDecoratorCommon * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragEnter )( 
            IMgaDecoratorCommon * This,
            /* [out] */ ULONG *dropEffect,
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG keyState,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragOver )( 
            IMgaDecoratorCommon * This,
            /* [out] */ ULONG *dropEffect,
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG keyState,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Drop )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG dropEffect,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DropFile )( 
            IMgaDecoratorCommon * This,
            /* [in] */ ULONGLONG hDropInfo,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        END_INTERFACE
    } IMgaDecoratorCommonVtbl;

    interface IMgaDecoratorCommon
    {
        CONST_VTBL struct IMgaDecoratorCommonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMgaDecoratorCommon_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMgaDecoratorCommon_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMgaDecoratorCommon_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMgaDecoratorCommon_Initialize(This,p,meta,obj)	\
    ( (This)->lpVtbl -> Initialize(This,p,meta,obj) ) 

#define IMgaDecoratorCommon_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IMgaDecoratorCommon_GetMnemonic(This,mnemonic)	\
    ( (This)->lpVtbl -> GetMnemonic(This,mnemonic) ) 

#define IMgaDecoratorCommon_GetFeatures(This,features)	\
    ( (This)->lpVtbl -> GetFeatures(This,features) ) 

#define IMgaDecoratorCommon_SetParam(This,Name,value)	\
    ( (This)->lpVtbl -> SetParam(This,Name,value) ) 

#define IMgaDecoratorCommon_GetParam(This,Name,value)	\
    ( (This)->lpVtbl -> GetParam(This,Name,value) ) 

#define IMgaDecoratorCommon_SetActive(This,isActive)	\
    ( (This)->lpVtbl -> SetActive(This,isActive) ) 

#define IMgaDecoratorCommon_GetPreferredSize(This,sizex,sizey)	\
    ( (This)->lpVtbl -> GetPreferredSize(This,sizex,sizey) ) 

#define IMgaDecoratorCommon_SetLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> SetLocation(This,sx,sy,ex,ey) ) 

#define IMgaDecoratorCommon_GetLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetLocation(This,sx,sy,ex,ey) ) 

#define IMgaDecoratorCommon_GetLabelLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetLabelLocation(This,sx,sy,ex,ey) ) 

#define IMgaDecoratorCommon_GetPortLocation(This,fco,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetPortLocation(This,fco,sx,sy,ex,ey) ) 

#define IMgaDecoratorCommon_GetPorts(This,portFCOs)	\
    ( (This)->lpVtbl -> GetPorts(This,portFCOs) ) 

#define IMgaDecoratorCommon_Draw(This,hdc)	\
    ( (This)->lpVtbl -> Draw(This,hdc) ) 

#define IMgaDecoratorCommon_SaveState(This)	\
    ( (This)->lpVtbl -> SaveState(This) ) 


#define IMgaDecoratorCommon_InitializeEx(This,p,meta,obj,eventSink,parentWnd)	\
    ( (This)->lpVtbl -> InitializeEx(This,p,meta,obj,eventSink,parentWnd) ) 

#define IMgaDecoratorCommon_DrawEx(This,hdc,gdip)	\
    ( (This)->lpVtbl -> DrawEx(This,hdc,gdip) ) 

#define IMgaDecoratorCommon_SetSelected(This,isSelected)	\
    ( (This)->lpVtbl -> SetSelected(This,isSelected) ) 

#define IMgaDecoratorCommon_MouseMoved(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseMoved(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseLeftButtonDown(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseLeftButtonDown(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseLeftButtonUp(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseLeftButtonUp(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseLeftButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseLeftButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseRightButtonDown(This,hCtxMenu,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseRightButtonDown(This,hCtxMenu,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseRightButtonUp(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseRightButtonUp(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseRightButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseRightButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseMiddleButtonDown(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseMiddleButtonDown(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseMiddleButtonUp(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseMiddleButtonUp(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseMiddleButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseMiddleButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MouseWheelTurned(This,nFlags,distance,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseWheelTurned(This,nFlags,distance,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_MenuItemSelected(This,menuItemId,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MenuItemSelected(This,menuItemId,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_OperationCanceled(This)	\
    ( (This)->lpVtbl -> OperationCanceled(This) ) 

#define IMgaDecoratorCommon_DragEnter(This,dropEffect,pCOleDataObject,keyState,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> DragEnter(This,dropEffect,pCOleDataObject,keyState,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_DragOver(This,dropEffect,pCOleDataObject,keyState,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> DragOver(This,dropEffect,pCOleDataObject,keyState,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_Drop(This,pCOleDataObject,dropEffect,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> Drop(This,pCOleDataObject,dropEffect,pointx,pointy,transformHDC) ) 

#define IMgaDecoratorCommon_DropFile(This,hDropInfo,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> DropFile(This,hDropInfo,pointx,pointy,transformHDC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMgaDecoratorCommon_INTERFACE_DEFINED__ */


#ifndef __IMgaElementDecoratorEvents_INTERFACE_DEFINED__
#define __IMgaElementDecoratorEvents_INTERFACE_DEFINED__

/* interface IMgaElementDecoratorEvents */
/* [unique][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IMgaElementDecoratorEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1D63D045-28C9-4902-8E5F-46F4AC1F8C5B")
    IMgaElementDecoratorEvents : public IMgaCommonDecoratorEvents
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowMovingStarted( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowMoving( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowMovingFinished( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowMoved( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowResizingStarted( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowResizing( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowResizingFinished( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowResized( 
            /* [in] */ LONG nFlags,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMgaElementDecoratorEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMgaElementDecoratorEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMgaElementDecoratorEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ refresh_mode_enum refreshMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OperationCanceled )( 
            IMgaElementDecoratorEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CursorChanged )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG newCursorID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CursorRestored )( 
            IMgaElementDecoratorEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelEditingStarted )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelEditingFinished )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelChanged )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ BSTR newLabel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelMovingStarted )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelMoving )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelMovingFinished )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelMoved )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelResizingStarted )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelResizing )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelResizingFinished )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LabelResized )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GeneralOperationStarted )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ ULONGLONG operationData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GeneralOperationFinished )( 
            IMgaElementDecoratorEvents * This,
            /* [out] */ ULONGLONG *operationData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowMovingStarted )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowMoving )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowMovingFinished )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowMoved )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowResizingStarted )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowResizing )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowResizingFinished )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG left,
            /* [in] */ LONG top,
            /* [in] */ LONG right,
            /* [in] */ LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowResized )( 
            IMgaElementDecoratorEvents * This,
            /* [in] */ LONG nFlags,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy);
        
        END_INTERFACE
    } IMgaElementDecoratorEventsVtbl;

    interface IMgaElementDecoratorEvents
    {
        CONST_VTBL struct IMgaElementDecoratorEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMgaElementDecoratorEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMgaElementDecoratorEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMgaElementDecoratorEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMgaElementDecoratorEvents_Refresh(This,refreshMode)	\
    ( (This)->lpVtbl -> Refresh(This,refreshMode) ) 

#define IMgaElementDecoratorEvents_OperationCanceled(This)	\
    ( (This)->lpVtbl -> OperationCanceled(This) ) 

#define IMgaElementDecoratorEvents_CursorChanged(This,newCursorID)	\
    ( (This)->lpVtbl -> CursorChanged(This,newCursorID) ) 

#define IMgaElementDecoratorEvents_CursorRestored(This)	\
    ( (This)->lpVtbl -> CursorRestored(This) ) 

#define IMgaElementDecoratorEvents_LabelEditingStarted(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelEditingStarted(This,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_LabelEditingFinished(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelEditingFinished(This,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_LabelChanged(This,newLabel)	\
    ( (This)->lpVtbl -> LabelChanged(This,newLabel) ) 

#define IMgaElementDecoratorEvents_LabelMovingStarted(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelMovingStarted(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_LabelMoving(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelMoving(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_LabelMovingFinished(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelMovingFinished(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_LabelMoved(This,nFlags,x,y)	\
    ( (This)->lpVtbl -> LabelMoved(This,nFlags,x,y) ) 

#define IMgaElementDecoratorEvents_LabelResizingStarted(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelResizingStarted(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_LabelResizing(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelResizing(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_LabelResizingFinished(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> LabelResizingFinished(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_LabelResized(This,nFlags,cx,cy)	\
    ( (This)->lpVtbl -> LabelResized(This,nFlags,cx,cy) ) 

#define IMgaElementDecoratorEvents_GeneralOperationStarted(This,operationData)	\
    ( (This)->lpVtbl -> GeneralOperationStarted(This,operationData) ) 

#define IMgaElementDecoratorEvents_GeneralOperationFinished(This,operationData)	\
    ( (This)->lpVtbl -> GeneralOperationFinished(This,operationData) ) 


#define IMgaElementDecoratorEvents_WindowMovingStarted(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> WindowMovingStarted(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_WindowMoving(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> WindowMoving(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_WindowMovingFinished(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> WindowMovingFinished(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_WindowMoved(This,nFlags,x,y)	\
    ( (This)->lpVtbl -> WindowMoved(This,nFlags,x,y) ) 

#define IMgaElementDecoratorEvents_WindowResizingStarted(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> WindowResizingStarted(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_WindowResizing(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> WindowResizing(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_WindowResizingFinished(This,nFlags,left,top,right,bottom)	\
    ( (This)->lpVtbl -> WindowResizingFinished(This,nFlags,left,top,right,bottom) ) 

#define IMgaElementDecoratorEvents_WindowResized(This,nFlags,cx,cy)	\
    ( (This)->lpVtbl -> WindowResized(This,nFlags,cx,cy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMgaElementDecoratorEvents_INTERFACE_DEFINED__ */


#ifndef __IMgaElementDecorator_INTERFACE_DEFINED__
#define __IMgaElementDecorator_INTERFACE_DEFINED__

/* interface IMgaElementDecorator */
/* [unique][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IMgaElementDecorator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BEAD76C-126E-405D-AAC6-B9CA39067006")
    IMgaElementDecorator : public IMgaDecoratorCommon
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMgaElementDecoratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMgaElementDecorator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMgaElementDecorator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMgaElementDecorator * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IMgaElementDecorator * This,
            /* [in] */ IMgaProject *p,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            IMgaElementDecorator * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMnemonic )( 
            IMgaElementDecorator * This,
            /* [out] */ BSTR *mnemonic);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeatures )( 
            IMgaElementDecorator * This,
            /* [out] */ feature_code *features);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetParam )( 
            IMgaElementDecorator * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            IMgaElementDecorator * This,
            /* [in] */ BSTR Name,
            /* [out] */ VARIANT *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetActive )( 
            IMgaElementDecorator * This,
            /* [in] */ VARIANT_BOOL isActive);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPreferredSize )( 
            IMgaElementDecorator * This,
            /* [out] */ long *sizex,
            /* [out] */ long *sizey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLocation )( 
            IMgaElementDecorator * This,
            /* [in] */ long sx,
            /* [in] */ long sy,
            /* [in] */ long ex,
            /* [in] */ long ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLocation )( 
            IMgaElementDecorator * This,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLabelLocation )( 
            IMgaElementDecorator * This,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPortLocation )( 
            IMgaElementDecorator * This,
            /* [in] */ IMgaFCO *fco,
            /* [out] */ long *sx,
            /* [out] */ long *sy,
            /* [out] */ long *ex,
            /* [out] */ long *ey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPorts )( 
            IMgaElementDecorator * This,
            /* [retval][out] */ IMgaFCOs **portFCOs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveState )( 
            IMgaElementDecorator * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeEx )( 
            IMgaElementDecorator * This,
            /* [in] */ IMgaProject *p,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj,
            /* [in] */ IMgaCommonDecoratorEvents *eventSink,
            /* [in] */ ULONGLONG parentWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawEx )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG hdc,
            /* [in] */ ULONGLONG gdip);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSelected )( 
            IMgaElementDecorator * This,
            /* [in] */ VARIANT_BOOL isSelected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseMoved )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseLeftButtonDown )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseLeftButtonUp )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseLeftButtonDoubleClick )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseRightButtonDown )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONGLONG hCtxMenu,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseRightButtonUp )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseRightButtonDoubleClick )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseMiddleButtonDown )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseMiddleButtonUp )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseMiddleButtonDoubleClick )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MouseWheelTurned )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG distance,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MenuItemSelected )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONG menuItemId,
            /* [in] */ ULONG nFlags,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OperationCanceled )( 
            IMgaElementDecorator * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragEnter )( 
            IMgaElementDecorator * This,
            /* [out] */ ULONG *dropEffect,
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG keyState,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragOver )( 
            IMgaElementDecorator * This,
            /* [out] */ ULONG *dropEffect,
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG keyState,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Drop )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONGLONG pCOleDataObject,
            /* [in] */ ULONG dropEffect,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DropFile )( 
            IMgaElementDecorator * This,
            /* [in] */ ULONGLONG hDropInfo,
            /* [in] */ LONG pointx,
            /* [in] */ LONG pointy,
            /* [in] */ ULONGLONG transformHDC);
        
        END_INTERFACE
    } IMgaElementDecoratorVtbl;

    interface IMgaElementDecorator
    {
        CONST_VTBL struct IMgaElementDecoratorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMgaElementDecorator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMgaElementDecorator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMgaElementDecorator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMgaElementDecorator_Initialize(This,p,meta,obj)	\
    ( (This)->lpVtbl -> Initialize(This,p,meta,obj) ) 

#define IMgaElementDecorator_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IMgaElementDecorator_GetMnemonic(This,mnemonic)	\
    ( (This)->lpVtbl -> GetMnemonic(This,mnemonic) ) 

#define IMgaElementDecorator_GetFeatures(This,features)	\
    ( (This)->lpVtbl -> GetFeatures(This,features) ) 

#define IMgaElementDecorator_SetParam(This,Name,value)	\
    ( (This)->lpVtbl -> SetParam(This,Name,value) ) 

#define IMgaElementDecorator_GetParam(This,Name,value)	\
    ( (This)->lpVtbl -> GetParam(This,Name,value) ) 

#define IMgaElementDecorator_SetActive(This,isActive)	\
    ( (This)->lpVtbl -> SetActive(This,isActive) ) 

#define IMgaElementDecorator_GetPreferredSize(This,sizex,sizey)	\
    ( (This)->lpVtbl -> GetPreferredSize(This,sizex,sizey) ) 

#define IMgaElementDecorator_SetLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> SetLocation(This,sx,sy,ex,ey) ) 

#define IMgaElementDecorator_GetLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetLocation(This,sx,sy,ex,ey) ) 

#define IMgaElementDecorator_GetLabelLocation(This,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetLabelLocation(This,sx,sy,ex,ey) ) 

#define IMgaElementDecorator_GetPortLocation(This,fco,sx,sy,ex,ey)	\
    ( (This)->lpVtbl -> GetPortLocation(This,fco,sx,sy,ex,ey) ) 

#define IMgaElementDecorator_GetPorts(This,portFCOs)	\
    ( (This)->lpVtbl -> GetPorts(This,portFCOs) ) 

#define IMgaElementDecorator_Draw(This,hdc)	\
    ( (This)->lpVtbl -> Draw(This,hdc) ) 

#define IMgaElementDecorator_SaveState(This)	\
    ( (This)->lpVtbl -> SaveState(This) ) 


#define IMgaElementDecorator_InitializeEx(This,p,meta,obj,eventSink,parentWnd)	\
    ( (This)->lpVtbl -> InitializeEx(This,p,meta,obj,eventSink,parentWnd) ) 

#define IMgaElementDecorator_DrawEx(This,hdc,gdip)	\
    ( (This)->lpVtbl -> DrawEx(This,hdc,gdip) ) 

#define IMgaElementDecorator_SetSelected(This,isSelected)	\
    ( (This)->lpVtbl -> SetSelected(This,isSelected) ) 

#define IMgaElementDecorator_MouseMoved(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseMoved(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseLeftButtonDown(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseLeftButtonDown(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseLeftButtonUp(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseLeftButtonUp(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseLeftButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseLeftButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseRightButtonDown(This,hCtxMenu,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseRightButtonDown(This,hCtxMenu,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseRightButtonUp(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseRightButtonUp(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseRightButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseRightButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseMiddleButtonDown(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseMiddleButtonDown(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseMiddleButtonUp(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseMiddleButtonUp(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseMiddleButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseMiddleButtonDoubleClick(This,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MouseWheelTurned(This,nFlags,distance,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MouseWheelTurned(This,nFlags,distance,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_MenuItemSelected(This,menuItemId,nFlags,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> MenuItemSelected(This,menuItemId,nFlags,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_OperationCanceled(This)	\
    ( (This)->lpVtbl -> OperationCanceled(This) ) 

#define IMgaElementDecorator_DragEnter(This,dropEffect,pCOleDataObject,keyState,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> DragEnter(This,dropEffect,pCOleDataObject,keyState,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_DragOver(This,dropEffect,pCOleDataObject,keyState,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> DragOver(This,dropEffect,pCOleDataObject,keyState,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_Drop(This,pCOleDataObject,dropEffect,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> Drop(This,pCOleDataObject,dropEffect,pointx,pointy,transformHDC) ) 

#define IMgaElementDecorator_DropFile(This,hDropInfo,pointx,pointy,transformHDC)	\
    ( (This)->lpVtbl -> DropFile(This,hDropInfo,pointx,pointy,transformHDC) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMgaElementDecorator_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ConnectorInstance_Decorator_0000_0012 */
/* [local] */ 

typedef short metaid_type;

typedef long objid_type;

typedef short attrid_type;

typedef unsigned char valtype_type;

typedef unsigned char locking_type;

typedef short lockval_type;

typedef VARIANT guid_type;












#define	METAID_NONE	( 0 )

#define	METAID_ROOT	( 1 )

#define	OBJID_NONE	( 0 )

#define	OBJID_ROOT	( 1 )

#define	ATTRID_NONE	( 0 )

#define	ATTRID_LOCK	( 1 )

#define	ATTRID_NAME	( 2 )

#define	ATTRID_FATHER	( 3 )

#define	ATTRID_COLLECTION	( 10000 )

typedef 
enum locking_enum
    {	LOCKING_NONE	= 0,
	LOCKING_READ	= 1,
	LOCKING_WRITE	= 2,
	LOCKING_EXCLUSIVE	= 3
    } 	locking_enum;

typedef 
enum valtype_enum
    {	VALTYPE_NONE	= 0,
	VALTYPE_COLLECTION	= 1,
	VALTYPE_POINTER	= 2,
	VALTYPE_LOCK	= 3,
	VALTYPE_LONG	= 4,
	VALTYPE_STRING	= 5,
	VALTYPE_BINARY	= 6,
	VALTYPE_REAL	= 7,
	VALTYPE_DICT	= 8,
	VALTYPE_MAX	= 8
    } 	valtype_enum;

typedef 
enum transtype_enum
    {	TRANSTYPE_NONE	= 0,
	TRANSTYPE_FIRST	= 1,
	TRANSTYPE_NESTED	= 2,
	TRANSTYPE_ANY	= 3,
	TRANSTYPE_READ	= 4,
	TRANSTYPE_READFIRST	= 5,
	TRANSTYPE_READNESTED	= 6,
	TRANSTYPE_READANY	= 7
    } 	transtype_enum;



extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0012_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0012_v0_0_s_ifspec;

#ifndef __ICoreMetaProject_INTERFACE_DEFINED__
#define __ICoreMetaProject_INTERFACE_DEFINED__

/* interface ICoreMetaProject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreMetaProject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98AA02D9-2E2C-11D3-B36D-0060082DF884")
    ICoreMetaProject : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_GUID( 
            /* [retval][out] */ guid_type *p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_GUID( 
            /* [in] */ guid_type p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Token( 
            /* [retval][out] */ BSTR *p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Token( 
            /* [in] */ BSTR p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [in] */ metaid_type metaid,
            /* [retval][out] */ ICoreMetaObject **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetObjectDisp( 
            /* [in] */ metaid_type metaid,
            /* [retval][out] */ ICoreMetaObject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Objects( 
            /* [retval][out] */ ICoreMetaObjects **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddObject( 
            /* [in] */ metaid_type metaid,
            /* [in] */ BSTR token,
            /* [in] */ BSTR name,
            /* [out] */ ICoreMetaObject **p) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreMetaProjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreMetaProject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreMetaProject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreMetaProject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreMetaProject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreMetaProject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreMetaProject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreMetaProject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GUID )( 
            ICoreMetaProject * This,
            /* [retval][out] */ guid_type *p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GUID )( 
            ICoreMetaProject * This,
            /* [in] */ guid_type p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Token )( 
            ICoreMetaProject * This,
            /* [retval][out] */ BSTR *p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Token )( 
            ICoreMetaProject * This,
            /* [in] */ BSTR p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICoreMetaProject * This,
            /* [retval][out] */ BSTR *p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            ICoreMetaProject * This,
            /* [in] */ BSTR p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            ICoreMetaProject * This,
            /* [in] */ metaid_type metaid,
            /* [retval][out] */ ICoreMetaObject **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetObjectDisp )( 
            ICoreMetaProject * This,
            /* [in] */ metaid_type metaid,
            /* [retval][out] */ ICoreMetaObject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Objects )( 
            ICoreMetaProject * This,
            /* [retval][out] */ ICoreMetaObjects **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddObject )( 
            ICoreMetaProject * This,
            /* [in] */ metaid_type metaid,
            /* [in] */ BSTR token,
            /* [in] */ BSTR name,
            /* [out] */ ICoreMetaObject **p);
        
        END_INTERFACE
    } ICoreMetaProjectVtbl;

    interface ICoreMetaProject
    {
        CONST_VTBL struct ICoreMetaProjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreMetaProject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreMetaProject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreMetaProject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreMetaProject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreMetaProject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreMetaProject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreMetaProject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreMetaProject_get_GUID(This,p)	\
    ( (This)->lpVtbl -> get_GUID(This,p) ) 

#define ICoreMetaProject_put_GUID(This,p)	\
    ( (This)->lpVtbl -> put_GUID(This,p) ) 

#define ICoreMetaProject_get_Token(This,p)	\
    ( (This)->lpVtbl -> get_Token(This,p) ) 

#define ICoreMetaProject_put_Token(This,p)	\
    ( (This)->lpVtbl -> put_Token(This,p) ) 

#define ICoreMetaProject_get_Name(This,p)	\
    ( (This)->lpVtbl -> get_Name(This,p) ) 

#define ICoreMetaProject_put_Name(This,p)	\
    ( (This)->lpVtbl -> put_Name(This,p) ) 

#define ICoreMetaProject_get_Object(This,metaid,p)	\
    ( (This)->lpVtbl -> get_Object(This,metaid,p) ) 

#define ICoreMetaProject_GetObjectDisp(This,metaid,p)	\
    ( (This)->lpVtbl -> GetObjectDisp(This,metaid,p) ) 

#define ICoreMetaProject_get_Objects(This,p)	\
    ( (This)->lpVtbl -> get_Objects(This,p) ) 

#define ICoreMetaProject_AddObject(This,metaid,token,name,p)	\
    ( (This)->lpVtbl -> AddObject(This,metaid,token,name,p) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreMetaProject_INTERFACE_DEFINED__ */


#ifndef __ICoreMetaObject_INTERFACE_DEFINED__
#define __ICoreMetaObject_INTERFACE_DEFINED__

/* interface ICoreMetaObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreMetaObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98AA02DB-2E2C-11D3-B36D-0060082DF884")
    ICoreMetaObject : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Project( 
            /* [retval][out] */ ICoreMetaProject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MetaID( 
            /* [retval][out] */ metaid_type *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Token( 
            /* [retval][out] */ BSTR *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Attribute( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ ICoreMetaAttribute **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAttributeDisp( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ ICoreMetaAttribute **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [retval][out] */ ICoreMetaAttributes **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClassIDs( 
            /* [retval][out] */ SAFEARRAY * *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddAttribute( 
            /* [in] */ attrid_type attrid,
            /* [in] */ BSTR token,
            /* [in] */ BSTR name,
            /* [in] */ valtype_type valtype,
            /* [out] */ ICoreMetaAttribute **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddClassID( 
            /* [in] */ guid_type classid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreMetaObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreMetaObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreMetaObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreMetaObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreMetaObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreMetaObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreMetaObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreMetaObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Project )( 
            ICoreMetaObject * This,
            /* [retval][out] */ ICoreMetaProject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MetaID )( 
            ICoreMetaObject * This,
            /* [retval][out] */ metaid_type *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Token )( 
            ICoreMetaObject * This,
            /* [retval][out] */ BSTR *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICoreMetaObject * This,
            /* [retval][out] */ BSTR *p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attribute )( 
            ICoreMetaObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ ICoreMetaAttribute **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAttributeDisp )( 
            ICoreMetaObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ ICoreMetaAttribute **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            ICoreMetaObject * This,
            /* [retval][out] */ ICoreMetaAttributes **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassIDs )( 
            ICoreMetaObject * This,
            /* [retval][out] */ SAFEARRAY * *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddAttribute )( 
            ICoreMetaObject * This,
            /* [in] */ attrid_type attrid,
            /* [in] */ BSTR token,
            /* [in] */ BSTR name,
            /* [in] */ valtype_type valtype,
            /* [out] */ ICoreMetaAttribute **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddClassID )( 
            ICoreMetaObject * This,
            /* [in] */ guid_type classid);
        
        END_INTERFACE
    } ICoreMetaObjectVtbl;

    interface ICoreMetaObject
    {
        CONST_VTBL struct ICoreMetaObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreMetaObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreMetaObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreMetaObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreMetaObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreMetaObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreMetaObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreMetaObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreMetaObject_get_Project(This,p)	\
    ( (This)->lpVtbl -> get_Project(This,p) ) 

#define ICoreMetaObject_get_MetaID(This,p)	\
    ( (This)->lpVtbl -> get_MetaID(This,p) ) 

#define ICoreMetaObject_get_Token(This,p)	\
    ( (This)->lpVtbl -> get_Token(This,p) ) 

#define ICoreMetaObject_get_Name(This,p)	\
    ( (This)->lpVtbl -> get_Name(This,p) ) 

#define ICoreMetaObject_get_Attribute(This,attrid,p)	\
    ( (This)->lpVtbl -> get_Attribute(This,attrid,p) ) 

#define ICoreMetaObject_GetAttributeDisp(This,attrid,p)	\
    ( (This)->lpVtbl -> GetAttributeDisp(This,attrid,p) ) 

#define ICoreMetaObject_get_Attributes(This,p)	\
    ( (This)->lpVtbl -> get_Attributes(This,p) ) 

#define ICoreMetaObject_get_ClassIDs(This,p)	\
    ( (This)->lpVtbl -> get_ClassIDs(This,p) ) 

#define ICoreMetaObject_AddAttribute(This,attrid,token,name,valtype,p)	\
    ( (This)->lpVtbl -> AddAttribute(This,attrid,token,name,valtype,p) ) 

#define ICoreMetaObject_AddClassID(This,classid)	\
    ( (This)->lpVtbl -> AddClassID(This,classid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreMetaObject_INTERFACE_DEFINED__ */


#ifndef __ICoreMetaAttribute_INTERFACE_DEFINED__
#define __ICoreMetaAttribute_INTERFACE_DEFINED__

/* interface ICoreMetaAttribute */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreMetaAttribute;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98AA02E1-2E2C-11D3-B36D-0060082DF884")
    ICoreMetaAttribute : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [retval][out] */ ICoreMetaObject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AttrID( 
            /* [retval][out] */ attrid_type *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Token( 
            /* [retval][out] */ BSTR *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ValueType( 
            /* [retval][out] */ valtype_type *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LockAttrID( 
            /* [retval][out] */ attrid_type *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MaxSize( 
            /* [retval][out] */ long *p) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreMetaAttributeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreMetaAttribute * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreMetaAttribute * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreMetaAttribute * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreMetaAttribute * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreMetaAttribute * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreMetaAttribute * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreMetaAttribute * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            ICoreMetaAttribute * This,
            /* [retval][out] */ ICoreMetaObject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AttrID )( 
            ICoreMetaAttribute * This,
            /* [retval][out] */ attrid_type *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Token )( 
            ICoreMetaAttribute * This,
            /* [retval][out] */ BSTR *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICoreMetaAttribute * This,
            /* [retval][out] */ BSTR *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValueType )( 
            ICoreMetaAttribute * This,
            /* [retval][out] */ valtype_type *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LockAttrID )( 
            ICoreMetaAttribute * This,
            /* [retval][out] */ attrid_type *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxSize )( 
            ICoreMetaAttribute * This,
            /* [retval][out] */ long *p);
        
        END_INTERFACE
    } ICoreMetaAttributeVtbl;

    interface ICoreMetaAttribute
    {
        CONST_VTBL struct ICoreMetaAttributeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreMetaAttribute_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreMetaAttribute_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreMetaAttribute_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreMetaAttribute_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreMetaAttribute_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreMetaAttribute_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreMetaAttribute_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreMetaAttribute_get_Object(This,p)	\
    ( (This)->lpVtbl -> get_Object(This,p) ) 

#define ICoreMetaAttribute_get_AttrID(This,p)	\
    ( (This)->lpVtbl -> get_AttrID(This,p) ) 

#define ICoreMetaAttribute_get_Token(This,p)	\
    ( (This)->lpVtbl -> get_Token(This,p) ) 

#define ICoreMetaAttribute_get_Name(This,p)	\
    ( (This)->lpVtbl -> get_Name(This,p) ) 

#define ICoreMetaAttribute_get_ValueType(This,p)	\
    ( (This)->lpVtbl -> get_ValueType(This,p) ) 

#define ICoreMetaAttribute_get_LockAttrID(This,p)	\
    ( (This)->lpVtbl -> get_LockAttrID(This,p) ) 

#define ICoreMetaAttribute_get_MaxSize(This,p)	\
    ( (This)->lpVtbl -> get_MaxSize(This,p) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreMetaAttribute_INTERFACE_DEFINED__ */


#ifndef __ICoreStorage_INTERFACE_DEFINED__
#define __ICoreStorage_INTERFACE_DEFINED__

/* interface ICoreStorage */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD9DFA4E-3A3B-11D3-B36C-0060082DF884")
    ICoreStorage : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MetaProject( 
            /* [retval][out] */ ICoreMetaProject **p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MetaProject( 
            /* [in] */ ICoreMetaProject *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StorageType( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MetaObject( 
            /* [retval][out] */ ICoreMetaObject **p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MetaObject( 
            /* [in] */ ICoreMetaObject *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MetaID( 
            /* [retval][out] */ metaid_type *p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MetaID( 
            /* [in] */ metaid_type p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MetaAttribute( 
            /* [retval][out] */ ICoreMetaAttribute **p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MetaAttribute( 
            /* [in] */ ICoreMetaAttribute *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AttrID( 
            /* [retval][out] */ attrid_type *p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AttrID( 
            /* [in] */ attrid_type p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenProject( 
            /* [in] */ BSTR connection,
            /* [out] */ VARIANT_BOOL *ro_mode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseProject( 
            /* [in] */ VARIANT_BOOL abort) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SaveProject( 
            /* [in] */ BSTR save_as_conn,
            /* [defaultvalue][in] */ VARIANT_BOOL keepoldname = 0) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateProject( 
            /* [in] */ BSTR connection) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteProject( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeginTransaction( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommitTransaction( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortTransaction( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenObject( 
            /* [in] */ objid_type ObjID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseObject( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateObject( 
            /* [out] */ objid_type *ObjID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteObject( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LockObject( void) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AttributeValue( 
            /* [out][retval] */ VARIANT *p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AttributeValue( 
            /* [in] */ VARIANT p) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreStorage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreStorage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreStorage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreStorage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreStorage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreStorage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreStorage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MetaProject )( 
            ICoreStorage * This,
            /* [retval][out] */ ICoreMetaProject **p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MetaProject )( 
            ICoreStorage * This,
            /* [in] */ ICoreMetaProject *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StorageType )( 
            ICoreStorage * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MetaObject )( 
            ICoreStorage * This,
            /* [retval][out] */ ICoreMetaObject **p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MetaObject )( 
            ICoreStorage * This,
            /* [in] */ ICoreMetaObject *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MetaID )( 
            ICoreStorage * This,
            /* [retval][out] */ metaid_type *p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MetaID )( 
            ICoreStorage * This,
            /* [in] */ metaid_type p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MetaAttribute )( 
            ICoreStorage * This,
            /* [retval][out] */ ICoreMetaAttribute **p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MetaAttribute )( 
            ICoreStorage * This,
            /* [in] */ ICoreMetaAttribute *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AttrID )( 
            ICoreStorage * This,
            /* [retval][out] */ attrid_type *p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AttrID )( 
            ICoreStorage * This,
            /* [in] */ attrid_type p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenProject )( 
            ICoreStorage * This,
            /* [in] */ BSTR connection,
            /* [out] */ VARIANT_BOOL *ro_mode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CloseProject )( 
            ICoreStorage * This,
            /* [in] */ VARIANT_BOOL abort);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveProject )( 
            ICoreStorage * This,
            /* [in] */ BSTR save_as_conn,
            /* [defaultvalue][in] */ VARIANT_BOOL keepoldname);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProject )( 
            ICoreStorage * This,
            /* [in] */ BSTR connection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteProject )( 
            ICoreStorage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginTransaction )( 
            ICoreStorage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CommitTransaction )( 
            ICoreStorage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbortTransaction )( 
            ICoreStorage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenObject )( 
            ICoreStorage * This,
            /* [in] */ objid_type ObjID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CloseObject )( 
            ICoreStorage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateObject )( 
            ICoreStorage * This,
            /* [out] */ objid_type *ObjID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteObject )( 
            ICoreStorage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LockObject )( 
            ICoreStorage * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AttributeValue )( 
            ICoreStorage * This,
            /* [out][retval] */ VARIANT *p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AttributeValue )( 
            ICoreStorage * This,
            /* [in] */ VARIANT p);
        
        END_INTERFACE
    } ICoreStorageVtbl;

    interface ICoreStorage
    {
        CONST_VTBL struct ICoreStorageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreStorage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreStorage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreStorage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreStorage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreStorage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreStorage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreStorage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreStorage_get_MetaProject(This,p)	\
    ( (This)->lpVtbl -> get_MetaProject(This,p) ) 

#define ICoreStorage_put_MetaProject(This,p)	\
    ( (This)->lpVtbl -> put_MetaProject(This,p) ) 

#define ICoreStorage_get_StorageType(This,p)	\
    ( (This)->lpVtbl -> get_StorageType(This,p) ) 

#define ICoreStorage_get_MetaObject(This,p)	\
    ( (This)->lpVtbl -> get_MetaObject(This,p) ) 

#define ICoreStorage_put_MetaObject(This,p)	\
    ( (This)->lpVtbl -> put_MetaObject(This,p) ) 

#define ICoreStorage_get_MetaID(This,p)	\
    ( (This)->lpVtbl -> get_MetaID(This,p) ) 

#define ICoreStorage_put_MetaID(This,p)	\
    ( (This)->lpVtbl -> put_MetaID(This,p) ) 

#define ICoreStorage_get_MetaAttribute(This,p)	\
    ( (This)->lpVtbl -> get_MetaAttribute(This,p) ) 

#define ICoreStorage_put_MetaAttribute(This,p)	\
    ( (This)->lpVtbl -> put_MetaAttribute(This,p) ) 

#define ICoreStorage_get_AttrID(This,p)	\
    ( (This)->lpVtbl -> get_AttrID(This,p) ) 

#define ICoreStorage_put_AttrID(This,p)	\
    ( (This)->lpVtbl -> put_AttrID(This,p) ) 

#define ICoreStorage_OpenProject(This,connection,ro_mode)	\
    ( (This)->lpVtbl -> OpenProject(This,connection,ro_mode) ) 

#define ICoreStorage_CloseProject(This,abort)	\
    ( (This)->lpVtbl -> CloseProject(This,abort) ) 

#define ICoreStorage_SaveProject(This,save_as_conn,keepoldname)	\
    ( (This)->lpVtbl -> SaveProject(This,save_as_conn,keepoldname) ) 

#define ICoreStorage_CreateProject(This,connection)	\
    ( (This)->lpVtbl -> CreateProject(This,connection) ) 

#define ICoreStorage_DeleteProject(This)	\
    ( (This)->lpVtbl -> DeleteProject(This) ) 

#define ICoreStorage_BeginTransaction(This)	\
    ( (This)->lpVtbl -> BeginTransaction(This) ) 

#define ICoreStorage_CommitTransaction(This)	\
    ( (This)->lpVtbl -> CommitTransaction(This) ) 

#define ICoreStorage_AbortTransaction(This)	\
    ( (This)->lpVtbl -> AbortTransaction(This) ) 

#define ICoreStorage_OpenObject(This,ObjID)	\
    ( (This)->lpVtbl -> OpenObject(This,ObjID) ) 

#define ICoreStorage_CloseObject(This)	\
    ( (This)->lpVtbl -> CloseObject(This) ) 

#define ICoreStorage_CreateObject(This,ObjID)	\
    ( (This)->lpVtbl -> CreateObject(This,ObjID) ) 

#define ICoreStorage_DeleteObject(This)	\
    ( (This)->lpVtbl -> DeleteObject(This) ) 

#define ICoreStorage_LockObject(This)	\
    ( (This)->lpVtbl -> LockObject(This) ) 

#define ICoreStorage_get_AttributeValue(This,p)	\
    ( (This)->lpVtbl -> get_AttributeValue(This,p) ) 

#define ICoreStorage_put_AttributeValue(This,p)	\
    ( (This)->lpVtbl -> put_AttributeValue(This,p) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreStorage_INTERFACE_DEFINED__ */


#ifndef __ICoreProject_INTERFACE_DEFINED__
#define __ICoreProject_INTERFACE_DEFINED__

/* interface ICoreProject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreProject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD9DFA4E-2A3B-11D3-B36C-0060082DF884")
    ICoreProject : public IDispatch
    {
    public:
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Storage( 
            /* [in] */ ICoreStorage *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Storage( 
            /* [retval][out] */ ICoreStorage **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MetaProject( 
            /* [retval][out] */ ICoreMetaProject **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenProject( 
            /* [in] */ BSTR connection,
            /* [in] */ ICoreMetaProject *p,
            /* [defaultvalue][out] */ VARIANT_BOOL *ro_mode = 0) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseProject( 
            /* [defaultvalue][in] */ VARIANT_BOOL abort = ( VARIANT_BOOL  )0) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateProject( 
            /* [in] */ BSTR connection,
            /* [in] */ ICoreMetaProject *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SaveProject( 
            /* [defaultvalue][in] */ BSTR save_as_conn = L"",
            /* [defaultvalue][in] */ VARIANT_BOOL keepoldname = 0) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteProject( 
            /* [in] */ BSTR connection) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenProject2( 
            /* [in] */ BSTR connection,
            /* [in] */ long pUndoSize,
            /* [in] */ ICoreMetaProject *p,
            /* [defaultvalue][out] */ VARIANT_BOOL *ro_mode = 0) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateProject2( 
            /* [in] */ BSTR connection,
            /* [in] */ long pUndoSize,
            /* [in] */ ICoreMetaProject *p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [in] */ metaid_type metaid,
            /* [in] */ objid_type ObjID,
            /* [retval][out] */ ICoreObject **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetObjectDisp( 
            /* [in] */ metaid_type metaid,
            /* [in] */ objid_type ObjID,
            /* [retval][out] */ ICoreObject **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateObject( 
            /* [in] */ metaid_type metaid,
            /* [out] */ ICoreObject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RootObject( 
            /* [retval][out] */ ICoreObject **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeginTransaction( 
            /* [defaultvalue][in] */ transtype_enum transtype = TRANSTYPE_ANY) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommitTransaction( 
            /* [defaultvalue][in] */ transtype_enum transtype = TRANSTYPE_ANY) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortTransaction( 
            /* [defaultvalue][in] */ transtype_enum transtype = TRANSTYPE_ANY) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NestedTransactionCount( 
            /* [retval][out] */ short *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UndoTransaction( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RedoTransaction( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FlushUndoQueue( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FlushRedoQueue( void) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UndoQueueSize( 
            /* [retval][out] */ short *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RedoQueueSize( 
            /* [retval][out] */ short *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTerritory( 
            /* [out] */ ICoreTerritory **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PushTerritory( 
            /* [in] */ ICoreTerritory *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PopTerritory( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreProjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreProject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreProject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreProject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreProject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreProject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreProject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreProject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Storage )( 
            ICoreProject * This,
            /* [in] */ ICoreStorage *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            ICoreProject * This,
            /* [retval][out] */ ICoreStorage **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MetaProject )( 
            ICoreProject * This,
            /* [retval][out] */ ICoreMetaProject **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenProject )( 
            ICoreProject * This,
            /* [in] */ BSTR connection,
            /* [in] */ ICoreMetaProject *p,
            /* [defaultvalue][out] */ VARIANT_BOOL *ro_mode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CloseProject )( 
            ICoreProject * This,
            /* [defaultvalue][in] */ VARIANT_BOOL abort);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProject )( 
            ICoreProject * This,
            /* [in] */ BSTR connection,
            /* [in] */ ICoreMetaProject *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveProject )( 
            ICoreProject * This,
            /* [defaultvalue][in] */ BSTR save_as_conn,
            /* [defaultvalue][in] */ VARIANT_BOOL keepoldname);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteProject )( 
            ICoreProject * This,
            /* [in] */ BSTR connection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenProject2 )( 
            ICoreProject * This,
            /* [in] */ BSTR connection,
            /* [in] */ long pUndoSize,
            /* [in] */ ICoreMetaProject *p,
            /* [defaultvalue][out] */ VARIANT_BOOL *ro_mode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProject2 )( 
            ICoreProject * This,
            /* [in] */ BSTR connection,
            /* [in] */ long pUndoSize,
            /* [in] */ ICoreMetaProject *p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            ICoreProject * This,
            /* [in] */ metaid_type metaid,
            /* [in] */ objid_type ObjID,
            /* [retval][out] */ ICoreObject **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetObjectDisp )( 
            ICoreProject * This,
            /* [in] */ metaid_type metaid,
            /* [in] */ objid_type ObjID,
            /* [retval][out] */ ICoreObject **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateObject )( 
            ICoreProject * This,
            /* [in] */ metaid_type metaid,
            /* [out] */ ICoreObject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootObject )( 
            ICoreProject * This,
            /* [retval][out] */ ICoreObject **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginTransaction )( 
            ICoreProject * This,
            /* [defaultvalue][in] */ transtype_enum transtype);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CommitTransaction )( 
            ICoreProject * This,
            /* [defaultvalue][in] */ transtype_enum transtype);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbortTransaction )( 
            ICoreProject * This,
            /* [defaultvalue][in] */ transtype_enum transtype);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NestedTransactionCount )( 
            ICoreProject * This,
            /* [retval][out] */ short *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UndoTransaction )( 
            ICoreProject * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RedoTransaction )( 
            ICoreProject * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FlushUndoQueue )( 
            ICoreProject * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FlushRedoQueue )( 
            ICoreProject * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UndoQueueSize )( 
            ICoreProject * This,
            /* [retval][out] */ short *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedoQueueSize )( 
            ICoreProject * This,
            /* [retval][out] */ short *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTerritory )( 
            ICoreProject * This,
            /* [out] */ ICoreTerritory **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PushTerritory )( 
            ICoreProject * This,
            /* [in] */ ICoreTerritory *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PopTerritory )( 
            ICoreProject * This);
        
        END_INTERFACE
    } ICoreProjectVtbl;

    interface ICoreProject
    {
        CONST_VTBL struct ICoreProjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreProject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreProject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreProject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreProject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreProject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreProject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreProject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreProject_put_Storage(This,p)	\
    ( (This)->lpVtbl -> put_Storage(This,p) ) 

#define ICoreProject_get_Storage(This,p)	\
    ( (This)->lpVtbl -> get_Storage(This,p) ) 

#define ICoreProject_get_MetaProject(This,p)	\
    ( (This)->lpVtbl -> get_MetaProject(This,p) ) 

#define ICoreProject_OpenProject(This,connection,p,ro_mode)	\
    ( (This)->lpVtbl -> OpenProject(This,connection,p,ro_mode) ) 

#define ICoreProject_CloseProject(This,abort)	\
    ( (This)->lpVtbl -> CloseProject(This,abort) ) 

#define ICoreProject_CreateProject(This,connection,p)	\
    ( (This)->lpVtbl -> CreateProject(This,connection,p) ) 

#define ICoreProject_SaveProject(This,save_as_conn,keepoldname)	\
    ( (This)->lpVtbl -> SaveProject(This,save_as_conn,keepoldname) ) 

#define ICoreProject_DeleteProject(This,connection)	\
    ( (This)->lpVtbl -> DeleteProject(This,connection) ) 

#define ICoreProject_OpenProject2(This,connection,pUndoSize,p,ro_mode)	\
    ( (This)->lpVtbl -> OpenProject2(This,connection,pUndoSize,p,ro_mode) ) 

#define ICoreProject_CreateProject2(This,connection,pUndoSize,p)	\
    ( (This)->lpVtbl -> CreateProject2(This,connection,pUndoSize,p) ) 

#define ICoreProject_get_Object(This,metaid,ObjID,p)	\
    ( (This)->lpVtbl -> get_Object(This,metaid,ObjID,p) ) 

#define ICoreProject_GetObjectDisp(This,metaid,ObjID,p)	\
    ( (This)->lpVtbl -> GetObjectDisp(This,metaid,ObjID,p) ) 

#define ICoreProject_CreateObject(This,metaid,p)	\
    ( (This)->lpVtbl -> CreateObject(This,metaid,p) ) 

#define ICoreProject_get_RootObject(This,p)	\
    ( (This)->lpVtbl -> get_RootObject(This,p) ) 

#define ICoreProject_BeginTransaction(This,transtype)	\
    ( (This)->lpVtbl -> BeginTransaction(This,transtype) ) 

#define ICoreProject_CommitTransaction(This,transtype)	\
    ( (This)->lpVtbl -> CommitTransaction(This,transtype) ) 

#define ICoreProject_AbortTransaction(This,transtype)	\
    ( (This)->lpVtbl -> AbortTransaction(This,transtype) ) 

#define ICoreProject_get_NestedTransactionCount(This,p)	\
    ( (This)->lpVtbl -> get_NestedTransactionCount(This,p) ) 

#define ICoreProject_UndoTransaction(This)	\
    ( (This)->lpVtbl -> UndoTransaction(This) ) 

#define ICoreProject_RedoTransaction(This)	\
    ( (This)->lpVtbl -> RedoTransaction(This) ) 

#define ICoreProject_FlushUndoQueue(This)	\
    ( (This)->lpVtbl -> FlushUndoQueue(This) ) 

#define ICoreProject_FlushRedoQueue(This)	\
    ( (This)->lpVtbl -> FlushRedoQueue(This) ) 

#define ICoreProject_get_UndoQueueSize(This,p)	\
    ( (This)->lpVtbl -> get_UndoQueueSize(This,p) ) 

#define ICoreProject_get_RedoQueueSize(This,p)	\
    ( (This)->lpVtbl -> get_RedoQueueSize(This,p) ) 

#define ICoreProject_CreateTerritory(This,p)	\
    ( (This)->lpVtbl -> CreateTerritory(This,p) ) 

#define ICoreProject_PushTerritory(This,p)	\
    ( (This)->lpVtbl -> PushTerritory(This,p) ) 

#define ICoreProject_PopTerritory(This)	\
    ( (This)->lpVtbl -> PopTerritory(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreProject_INTERFACE_DEFINED__ */


#ifndef __ICoreObject_INTERFACE_DEFINED__
#define __ICoreObject_INTERFACE_DEFINED__

/* interface ICoreObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("826A8736-563B-11D3-B301-005004D38590")
    ICoreObject : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Project( 
            /* [retval][out] */ ICoreProject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MetaObject( 
            /* [retval][out] */ ICoreMetaObject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ObjID( 
            /* [retval][out] */ objid_type *p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Attribute( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ ICoreAttribute **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAttributeDisp( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ ICoreAttribute **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [retval][out] */ ICoreAttributes **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AttributeValue( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAttributeValueDisp( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AttributeValue( 
            /* [in] */ attrid_type attrid,
            /* [in] */ VARIANT p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAttributeValueDisp( 
            /* [in] */ attrid_type attrid,
            /* [in] */ VARIANT p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LoadedAttrValue( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLoadedAttrValueDisp( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreviousAttrValue( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPreviousAttrValueDisp( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PeerLockValue( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ locking_type *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPeerLockValueDisp( 
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ locking_type *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SearchCollection( 
            /* [in] */ attrid_type coll_attrid,
            /* [in] */ attrid_type search_attrid,
            /* [in] */ VARIANT search_value,
            /* [retval][out] */ ICoreObject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsDeleted( 
            /* [out] */ VARIANT_BOOL *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ ICoreObject **p) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Project )( 
            ICoreObject * This,
            /* [retval][out] */ ICoreProject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MetaObject )( 
            ICoreObject * This,
            /* [retval][out] */ ICoreMetaObject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjID )( 
            ICoreObject * This,
            /* [retval][out] */ objid_type *p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attribute )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ ICoreAttribute **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAttributeDisp )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ ICoreAttribute **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            ICoreObject * This,
            /* [retval][out] */ ICoreAttributes **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AttributeValue )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAttributeValueDisp )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AttributeValue )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [in] */ VARIANT p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAttributeValueDisp )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [in] */ VARIANT p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoadedAttrValue )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLoadedAttrValueDisp )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreviousAttrValue )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPreviousAttrValueDisp )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ VARIANT *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PeerLockValue )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ locking_type *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPeerLockValueDisp )( 
            ICoreObject * This,
            /* [in] */ attrid_type attrid,
            /* [retval][out] */ locking_type *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SearchCollection )( 
            ICoreObject * This,
            /* [in] */ attrid_type coll_attrid,
            /* [in] */ attrid_type search_attrid,
            /* [in] */ VARIANT search_value,
            /* [retval][out] */ ICoreObject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDeleted )( 
            ICoreObject * This,
            /* [out] */ VARIANT_BOOL *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            ICoreObject * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ICoreObject * This,
            /* [out] */ ICoreObject **p);
        
        END_INTERFACE
    } ICoreObjectVtbl;

    interface ICoreObject
    {
        CONST_VTBL struct ICoreObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreObject_get_Project(This,p)	\
    ( (This)->lpVtbl -> get_Project(This,p) ) 

#define ICoreObject_get_MetaObject(This,p)	\
    ( (This)->lpVtbl -> get_MetaObject(This,p) ) 

#define ICoreObject_get_ObjID(This,p)	\
    ( (This)->lpVtbl -> get_ObjID(This,p) ) 

#define ICoreObject_get_Attribute(This,attrid,p)	\
    ( (This)->lpVtbl -> get_Attribute(This,attrid,p) ) 

#define ICoreObject_GetAttributeDisp(This,attrid,p)	\
    ( (This)->lpVtbl -> GetAttributeDisp(This,attrid,p) ) 

#define ICoreObject_get_Attributes(This,p)	\
    ( (This)->lpVtbl -> get_Attributes(This,p) ) 

#define ICoreObject_get_AttributeValue(This,attrid,p)	\
    ( (This)->lpVtbl -> get_AttributeValue(This,attrid,p) ) 

#define ICoreObject_GetAttributeValueDisp(This,attrid,p)	\
    ( (This)->lpVtbl -> GetAttributeValueDisp(This,attrid,p) ) 

#define ICoreObject_put_AttributeValue(This,attrid,p)	\
    ( (This)->lpVtbl -> put_AttributeValue(This,attrid,p) ) 

#define ICoreObject_SetAttributeValueDisp(This,attrid,p)	\
    ( (This)->lpVtbl -> SetAttributeValueDisp(This,attrid,p) ) 

#define ICoreObject_get_LoadedAttrValue(This,attrid,p)	\
    ( (This)->lpVtbl -> get_LoadedAttrValue(This,attrid,p) ) 

#define ICoreObject_GetLoadedAttrValueDisp(This,attrid,p)	\
    ( (This)->lpVtbl -> GetLoadedAttrValueDisp(This,attrid,p) ) 

#define ICoreObject_get_PreviousAttrValue(This,attrid,p)	\
    ( (This)->lpVtbl -> get_PreviousAttrValue(This,attrid,p) ) 

#define ICoreObject_GetPreviousAttrValueDisp(This,attrid,p)	\
    ( (This)->lpVtbl -> GetPreviousAttrValueDisp(This,attrid,p) ) 

#define ICoreObject_get_PeerLockValue(This,attrid,p)	\
    ( (This)->lpVtbl -> get_PeerLockValue(This,attrid,p) ) 

#define ICoreObject_GetPeerLockValueDisp(This,attrid,p)	\
    ( (This)->lpVtbl -> GetPeerLockValueDisp(This,attrid,p) ) 

#define ICoreObject_SearchCollection(This,coll_attrid,search_attrid,search_value,p)	\
    ( (This)->lpVtbl -> SearchCollection(This,coll_attrid,search_attrid,search_value,p) ) 

#define ICoreObject_get_IsDeleted(This,p)	\
    ( (This)->lpVtbl -> get_IsDeleted(This,p) ) 

#define ICoreObject_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define ICoreObject_Clone(This,p)	\
    ( (This)->lpVtbl -> Clone(This,p) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreObject_INTERFACE_DEFINED__ */


#ifndef __ICoreAttribute_INTERFACE_DEFINED__
#define __ICoreAttribute_INTERFACE_DEFINED__

/* interface ICoreAttribute */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreAttribute;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("826A8738-563B-11D3-B301-005004D38590")
    ICoreAttribute : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [retval][out] */ ICoreObject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MetaAttribute( 
            /* [retval][out] */ ICoreMetaAttribute **p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *p) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LoadedValue( 
            /* [retval][out] */ VARIANT *p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreviousValue( 
            /* [retval][out] */ VARIANT *p) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreAttributeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreAttribute * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreAttribute * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreAttribute * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreAttribute * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreAttribute * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreAttribute * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreAttribute * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            ICoreAttribute * This,
            /* [retval][out] */ ICoreObject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MetaAttribute )( 
            ICoreAttribute * This,
            /* [retval][out] */ ICoreMetaAttribute **p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            ICoreAttribute * This,
            /* [retval][out] */ VARIANT *p);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            ICoreAttribute * This,
            /* [in] */ VARIANT p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoadedValue )( 
            ICoreAttribute * This,
            /* [retval][out] */ VARIANT *p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreviousValue )( 
            ICoreAttribute * This,
            /* [retval][out] */ VARIANT *p);
        
        END_INTERFACE
    } ICoreAttributeVtbl;

    interface ICoreAttribute
    {
        CONST_VTBL struct ICoreAttributeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreAttribute_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreAttribute_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreAttribute_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreAttribute_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreAttribute_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreAttribute_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreAttribute_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreAttribute_get_Object(This,p)	\
    ( (This)->lpVtbl -> get_Object(This,p) ) 

#define ICoreAttribute_get_MetaAttribute(This,p)	\
    ( (This)->lpVtbl -> get_MetaAttribute(This,p) ) 

#define ICoreAttribute_get_Value(This,p)	\
    ( (This)->lpVtbl -> get_Value(This,p) ) 

#define ICoreAttribute_put_Value(This,p)	\
    ( (This)->lpVtbl -> put_Value(This,p) ) 

#define ICoreAttribute_get_LoadedValue(This,p)	\
    ( (This)->lpVtbl -> get_LoadedValue(This,p) ) 

#define ICoreAttribute_get_PreviousValue(This,p)	\
    ( (This)->lpVtbl -> get_PreviousValue(This,p) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreAttribute_INTERFACE_DEFINED__ */


#ifndef __ICoreTerritory_INTERFACE_DEFINED__
#define __ICoreTerritory_INTERFACE_DEFINED__

/* interface ICoreTerritory */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreTerritory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C3A57C3-8DFF-11D3-B336-005004D38590")
    ICoreTerritory : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Project( 
            /* [retval][out] */ ICoreProject **p) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [retval][out] */ ICoreAttributes **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreTerritoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreTerritory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreTerritory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreTerritory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreTerritory * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreTerritory * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreTerritory * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreTerritory * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Project )( 
            ICoreTerritory * This,
            /* [retval][out] */ ICoreProject **p);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            ICoreTerritory * This,
            /* [retval][out] */ ICoreAttributes **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ICoreTerritory * This);
        
        END_INTERFACE
    } ICoreTerritoryVtbl;

    interface ICoreTerritory
    {
        CONST_VTBL struct ICoreTerritoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreTerritory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreTerritory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreTerritory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreTerritory_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreTerritory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreTerritory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreTerritory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreTerritory_get_Project(This,p)	\
    ( (This)->lpVtbl -> get_Project(This,p) ) 

#define ICoreTerritory_get_Attributes(This,p)	\
    ( (This)->lpVtbl -> get_Attributes(This,p) ) 

#define ICoreTerritory_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreTerritory_INTERFACE_DEFINED__ */


#ifndef __ICoreMetaObjects_INTERFACE_DEFINED__
#define __ICoreMetaObjects_INTERFACE_DEFINED__

/* interface ICoreMetaObjects */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreMetaObjects;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43D12111-12CA-11D3-A6EC-0060082DF884")
    ICoreMetaObjects : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long n,
            /* [retval][out] */ ICoreMetaObject **p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAll( 
            /* [in] */ long count,
            /* [size_is][out] */ ICoreMetaObject **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ ICoreMetaObject *p,
            /* [in] */ long at) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ ICoreMetaObject *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ ICoreMetaObject *p,
            /* [in] */ long start,
            /* [retval][out] */ long *res) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long n) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreMetaObjectsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreMetaObjects * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreMetaObjects * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreMetaObjects * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreMetaObjects * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreMetaObjects * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreMetaObjects * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreMetaObjects * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICoreMetaObjects * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ICoreMetaObjects * This,
            /* [in] */ long n,
            /* [retval][out] */ ICoreMetaObject **p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ICoreMetaObjects * This,
            /* [retval][out] */ IUnknown **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAll )( 
            ICoreMetaObjects * This,
            /* [in] */ long count,
            /* [size_is][out] */ ICoreMetaObject **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            ICoreMetaObjects * This,
            /* [in] */ ICoreMetaObject *p,
            /* [in] */ long at);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            ICoreMetaObjects * This,
            /* [in] */ ICoreMetaObject *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            ICoreMetaObjects * This,
            /* [in] */ ICoreMetaObject *p,
            /* [in] */ long start,
            /* [retval][out] */ long *res);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ICoreMetaObjects * This,
            /* [in] */ long n);
        
        END_INTERFACE
    } ICoreMetaObjectsVtbl;

    interface ICoreMetaObjects
    {
        CONST_VTBL struct ICoreMetaObjectsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreMetaObjects_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreMetaObjects_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreMetaObjects_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreMetaObjects_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreMetaObjects_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreMetaObjects_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreMetaObjects_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreMetaObjects_get_Count(This,p)	\
    ( (This)->lpVtbl -> get_Count(This,p) ) 

#define ICoreMetaObjects_get_Item(This,n,p)	\
    ( (This)->lpVtbl -> get_Item(This,n,p) ) 

#define ICoreMetaObjects_get__NewEnum(This,p)	\
    ( (This)->lpVtbl -> get__NewEnum(This,p) ) 

#define ICoreMetaObjects_GetAll(This,count,p)	\
    ( (This)->lpVtbl -> GetAll(This,count,p) ) 

#define ICoreMetaObjects_Insert(This,p,at)	\
    ( (This)->lpVtbl -> Insert(This,p,at) ) 

#define ICoreMetaObjects_Append(This,p)	\
    ( (This)->lpVtbl -> Append(This,p) ) 

#define ICoreMetaObjects_Find(This,p,start,res)	\
    ( (This)->lpVtbl -> Find(This,p,start,res) ) 

#define ICoreMetaObjects_Remove(This,n)	\
    ( (This)->lpVtbl -> Remove(This,n) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreMetaObjects_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ConnectorInstance_Decorator_0000_0021 */
/* [local] */ 

#ifdef __cplusplus
extern "C++"    
{            
template<> struct ::TypeName_MgaColl2Elem<ICoreMetaObjects>
{ typedef ICoreMetaObjects collection_type; typedef ICoreMetaObject element_type; };
template<> struct ::TypeName_MgaElem2Coll<ICoreMetaObject>
{ typedef ICoreMetaObjects collection_type; typedef ICoreMetaObject element_type; };
}            
#endif


extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0021_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0021_v0_0_s_ifspec;

#ifndef __ICoreMetaAttributes_INTERFACE_DEFINED__
#define __ICoreMetaAttributes_INTERFACE_DEFINED__

/* interface ICoreMetaAttributes */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreMetaAttributes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43D12127-12CA-11D3-A6EC-0060082DF884")
    ICoreMetaAttributes : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long n,
            /* [retval][out] */ ICoreMetaAttribute **p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAll( 
            /* [in] */ long count,
            /* [size_is][out] */ ICoreMetaAttribute **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ ICoreMetaAttribute *p,
            /* [in] */ long at) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ ICoreMetaAttribute *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ ICoreMetaAttribute *p,
            /* [in] */ long start,
            /* [retval][out] */ long *res) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long n) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreMetaAttributesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreMetaAttributes * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreMetaAttributes * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreMetaAttributes * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreMetaAttributes * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreMetaAttributes * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreMetaAttributes * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreMetaAttributes * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICoreMetaAttributes * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ICoreMetaAttributes * This,
            /* [in] */ long n,
            /* [retval][out] */ ICoreMetaAttribute **p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ICoreMetaAttributes * This,
            /* [retval][out] */ IUnknown **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAll )( 
            ICoreMetaAttributes * This,
            /* [in] */ long count,
            /* [size_is][out] */ ICoreMetaAttribute **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            ICoreMetaAttributes * This,
            /* [in] */ ICoreMetaAttribute *p,
            /* [in] */ long at);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            ICoreMetaAttributes * This,
            /* [in] */ ICoreMetaAttribute *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            ICoreMetaAttributes * This,
            /* [in] */ ICoreMetaAttribute *p,
            /* [in] */ long start,
            /* [retval][out] */ long *res);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ICoreMetaAttributes * This,
            /* [in] */ long n);
        
        END_INTERFACE
    } ICoreMetaAttributesVtbl;

    interface ICoreMetaAttributes
    {
        CONST_VTBL struct ICoreMetaAttributesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreMetaAttributes_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreMetaAttributes_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreMetaAttributes_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreMetaAttributes_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreMetaAttributes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreMetaAttributes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreMetaAttributes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreMetaAttributes_get_Count(This,p)	\
    ( (This)->lpVtbl -> get_Count(This,p) ) 

#define ICoreMetaAttributes_get_Item(This,n,p)	\
    ( (This)->lpVtbl -> get_Item(This,n,p) ) 

#define ICoreMetaAttributes_get__NewEnum(This,p)	\
    ( (This)->lpVtbl -> get__NewEnum(This,p) ) 

#define ICoreMetaAttributes_GetAll(This,count,p)	\
    ( (This)->lpVtbl -> GetAll(This,count,p) ) 

#define ICoreMetaAttributes_Insert(This,p,at)	\
    ( (This)->lpVtbl -> Insert(This,p,at) ) 

#define ICoreMetaAttributes_Append(This,p)	\
    ( (This)->lpVtbl -> Append(This,p) ) 

#define ICoreMetaAttributes_Find(This,p,start,res)	\
    ( (This)->lpVtbl -> Find(This,p,start,res) ) 

#define ICoreMetaAttributes_Remove(This,n)	\
    ( (This)->lpVtbl -> Remove(This,n) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreMetaAttributes_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ConnectorInstance_Decorator_0000_0022 */
/* [local] */ 

#ifdef __cplusplus
extern "C++"    
{            
template<> struct ::TypeName_MgaColl2Elem<ICoreMetaAttributes>
{ typedef ICoreMetaAttributes collection_type; typedef ICoreMetaAttribute element_type; };
template<> struct ::TypeName_MgaElem2Coll<ICoreMetaAttribute>
{ typedef ICoreMetaAttributes collection_type; typedef ICoreMetaAttribute element_type; };
}            
#endif


extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0022_v0_0_s_ifspec;

#ifndef __ICoreObjects_INTERFACE_DEFINED__
#define __ICoreObjects_INTERFACE_DEFINED__

/* interface ICoreObjects */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreObjects;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43D12111-22CA-11D3-A6EC-0060082DF884")
    ICoreObjects : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long n,
            /* [retval][out] */ ICoreObject **p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAll( 
            /* [in] */ long count,
            /* [size_is][out] */ ICoreObject **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ ICoreObject *p,
            /* [in] */ long at) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ ICoreObject *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ ICoreObject *p,
            /* [in] */ long start,
            /* [retval][out] */ long *res) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long n) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreObjectsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreObjects * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreObjects * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreObjects * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreObjects * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreObjects * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreObjects * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreObjects * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICoreObjects * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ICoreObjects * This,
            /* [in] */ long n,
            /* [retval][out] */ ICoreObject **p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ICoreObjects * This,
            /* [retval][out] */ IUnknown **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAll )( 
            ICoreObjects * This,
            /* [in] */ long count,
            /* [size_is][out] */ ICoreObject **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            ICoreObjects * This,
            /* [in] */ ICoreObject *p,
            /* [in] */ long at);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            ICoreObjects * This,
            /* [in] */ ICoreObject *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            ICoreObjects * This,
            /* [in] */ ICoreObject *p,
            /* [in] */ long start,
            /* [retval][out] */ long *res);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ICoreObjects * This,
            /* [in] */ long n);
        
        END_INTERFACE
    } ICoreObjectsVtbl;

    interface ICoreObjects
    {
        CONST_VTBL struct ICoreObjectsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreObjects_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreObjects_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreObjects_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreObjects_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreObjects_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreObjects_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreObjects_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreObjects_get_Count(This,p)	\
    ( (This)->lpVtbl -> get_Count(This,p) ) 

#define ICoreObjects_get_Item(This,n,p)	\
    ( (This)->lpVtbl -> get_Item(This,n,p) ) 

#define ICoreObjects_get__NewEnum(This,p)	\
    ( (This)->lpVtbl -> get__NewEnum(This,p) ) 

#define ICoreObjects_GetAll(This,count,p)	\
    ( (This)->lpVtbl -> GetAll(This,count,p) ) 

#define ICoreObjects_Insert(This,p,at)	\
    ( (This)->lpVtbl -> Insert(This,p,at) ) 

#define ICoreObjects_Append(This,p)	\
    ( (This)->lpVtbl -> Append(This,p) ) 

#define ICoreObjects_Find(This,p,start,res)	\
    ( (This)->lpVtbl -> Find(This,p,start,res) ) 

#define ICoreObjects_Remove(This,n)	\
    ( (This)->lpVtbl -> Remove(This,n) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreObjects_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ConnectorInstance_Decorator_0000_0023 */
/* [local] */ 

#ifdef __cplusplus
extern "C++"    
{            
template<> struct ::TypeName_MgaColl2Elem<ICoreObjects>
{ typedef ICoreObjects collection_type; typedef ICoreObject element_type; };
template<> struct ::TypeName_MgaElem2Coll<ICoreObject>
{ typedef ICoreObjects collection_type; typedef ICoreObject element_type; };
}            
#endif


extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0023_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0023_v0_0_s_ifspec;

#ifndef __ICoreAttributes_INTERFACE_DEFINED__
#define __ICoreAttributes_INTERFACE_DEFINED__

/* interface ICoreAttributes */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreAttributes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43D12127-22CA-11D3-A6EC-0060082DF884")
    ICoreAttributes : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long n,
            /* [retval][out] */ ICoreAttribute **p) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAll( 
            /* [in] */ long count,
            /* [size_is][out] */ ICoreAttribute **p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ ICoreAttribute *p,
            /* [in] */ long at) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ ICoreAttribute *p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ ICoreAttribute *p,
            /* [in] */ long start,
            /* [retval][out] */ long *res) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long n) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreAttributesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreAttributes * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreAttributes * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreAttributes * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreAttributes * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreAttributes * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreAttributes * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreAttributes * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICoreAttributes * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ICoreAttributes * This,
            /* [in] */ long n,
            /* [retval][out] */ ICoreAttribute **p);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ICoreAttributes * This,
            /* [retval][out] */ IUnknown **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAll )( 
            ICoreAttributes * This,
            /* [in] */ long count,
            /* [size_is][out] */ ICoreAttribute **p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            ICoreAttributes * This,
            /* [in] */ ICoreAttribute *p,
            /* [in] */ long at);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            ICoreAttributes * This,
            /* [in] */ ICoreAttribute *p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            ICoreAttributes * This,
            /* [in] */ ICoreAttribute *p,
            /* [in] */ long start,
            /* [retval][out] */ long *res);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ICoreAttributes * This,
            /* [in] */ long n);
        
        END_INTERFACE
    } ICoreAttributesVtbl;

    interface ICoreAttributes
    {
        CONST_VTBL struct ICoreAttributesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreAttributes_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreAttributes_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreAttributes_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreAttributes_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreAttributes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreAttributes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreAttributes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreAttributes_get_Count(This,p)	\
    ( (This)->lpVtbl -> get_Count(This,p) ) 

#define ICoreAttributes_get_Item(This,n,p)	\
    ( (This)->lpVtbl -> get_Item(This,n,p) ) 

#define ICoreAttributes_get__NewEnum(This,p)	\
    ( (This)->lpVtbl -> get__NewEnum(This,p) ) 

#define ICoreAttributes_GetAll(This,count,p)	\
    ( (This)->lpVtbl -> GetAll(This,count,p) ) 

#define ICoreAttributes_Insert(This,p,at)	\
    ( (This)->lpVtbl -> Insert(This,p,at) ) 

#define ICoreAttributes_Append(This,p)	\
    ( (This)->lpVtbl -> Append(This,p) ) 

#define ICoreAttributes_Find(This,p,start,res)	\
    ( (This)->lpVtbl -> Find(This,p,start,res) ) 

#define ICoreAttributes_Remove(This,n)	\
    ( (This)->lpVtbl -> Remove(This,n) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreAttributes_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ConnectorInstance_Decorator_0000_0024 */
/* [local] */ 

#ifdef __cplusplus
extern "C++"    
{            
template<> struct ::TypeName_MgaColl2Elem<ICoreAttributes>
{ typedef ICoreAttributes collection_type; typedef ICoreAttribute element_type; };
template<> struct ::TypeName_MgaElem2Coll<ICoreAttribute>
{ typedef ICoreAttributes collection_type; typedef ICoreAttribute element_type; };
}            
#endif
typedef 
enum GMEInterfaceVersion_enum
    {	GMEInterfaceVersion_None	= 0,
	GMEInterfaceVersion_Legacy	= 4,
	GMEInterfaceVersion_Current	= 0x200e6
    } 	GMEInterfaceVersion_enum;

#define GMEInterfaceVersion GMEInterfaceVersion_enum


extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ConnectorInstance_Decorator_0000_0024_v0_0_s_ifspec;

#ifndef __IGMEVersionInfo_INTERFACE_DEFINED__
#define __IGMEVersionInfo_INTERFACE_DEFINED__

/* interface IGMEVersionInfo */
/* [object][helpstring][uuid][oleautomation] */ 


EXTERN_C const IID IID_IGMEVersionInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9A228010-020B-11d2-BBB3-0040051F7117")
    IGMEVersionInfo : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_version( 
            /* [retval][out] */ GMEInterfaceVersion_enum *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGMEVersionInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGMEVersionInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGMEVersionInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGMEVersionInfo * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_version )( 
            IGMEVersionInfo * This,
            /* [retval][out] */ GMEInterfaceVersion_enum *pVal);
        
        END_INTERFACE
    } IGMEVersionInfoVtbl;

    interface IGMEVersionInfo
    {
        CONST_VTBL struct IGMEVersionInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGMEVersionInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGMEVersionInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGMEVersionInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGMEVersionInfo_get_version(This,pVal)	\
    ( (This)->lpVtbl -> get_version(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGMEVersionInfo_INTERFACE_DEFINED__ */


#ifndef __ICoreDictionaryAttributeValue_INTERFACE_DEFINED__
#define __ICoreDictionaryAttributeValue_INTERFACE_DEFINED__

/* interface ICoreDictionaryAttributeValue */
/* [unique][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoreDictionaryAttributeValue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FAB8C11E-747A-45A5-BF05-1A8FB353B03B")
    ICoreDictionaryAttributeValue : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [in] */ BSTR Key,
            /* [retval][out] */ BSTR *Value) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR Key,
            /* [in] */ BSTR Value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Keys( 
            /* [retval][out] */ VARIANT *Keys) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Map( 
            /* [retval][out] */ VARIANT *Map) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Map( 
            /* [in] */ VARIANT Map) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ ICoreDictionaryAttributeValue **ret) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoreDictionaryAttributeValueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreDictionaryAttributeValue * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreDictionaryAttributeValue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreDictionaryAttributeValue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoreDictionaryAttributeValue * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoreDictionaryAttributeValue * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoreDictionaryAttributeValue * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreDictionaryAttributeValue * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            ICoreDictionaryAttributeValue * This,
            /* [in] */ BSTR Key,
            /* [retval][out] */ BSTR *Value);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            ICoreDictionaryAttributeValue * This,
            /* [in] */ BSTR Key,
            /* [in] */ BSTR Value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Keys )( 
            ICoreDictionaryAttributeValue * This,
            /* [retval][out] */ VARIANT *Keys);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Map )( 
            ICoreDictionaryAttributeValue * This,
            /* [retval][out] */ VARIANT *Map);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Map )( 
            ICoreDictionaryAttributeValue * This,
            /* [in] */ VARIANT Map);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ICoreDictionaryAttributeValue * This,
            /* [out] */ ICoreDictionaryAttributeValue **ret);
        
        END_INTERFACE
    } ICoreDictionaryAttributeValueVtbl;

    interface ICoreDictionaryAttributeValue
    {
        CONST_VTBL struct ICoreDictionaryAttributeValueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreDictionaryAttributeValue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreDictionaryAttributeValue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreDictionaryAttributeValue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreDictionaryAttributeValue_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICoreDictionaryAttributeValue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICoreDictionaryAttributeValue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICoreDictionaryAttributeValue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICoreDictionaryAttributeValue_get_Value(This,Key,Value)	\
    ( (This)->lpVtbl -> get_Value(This,Key,Value) ) 

#define ICoreDictionaryAttributeValue_put_Value(This,Key,Value)	\
    ( (This)->lpVtbl -> put_Value(This,Key,Value) ) 

#define ICoreDictionaryAttributeValue_get_Keys(This,Keys)	\
    ( (This)->lpVtbl -> get_Keys(This,Keys) ) 

#define ICoreDictionaryAttributeValue_get_Map(This,Map)	\
    ( (This)->lpVtbl -> get_Map(This,Map) ) 

#define ICoreDictionaryAttributeValue_put_Map(This,Map)	\
    ( (This)->lpVtbl -> put_Map(This,Map) ) 

#define ICoreDictionaryAttributeValue_Clone(This,ret)	\
    ( (This)->lpVtbl -> Clone(This,ret) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreDictionaryAttributeValue_INTERFACE_DEFINED__ */



#ifndef __ConnectorInstance_DecoratorLib_LIBRARY_DEFINED__
#define __ConnectorInstance_DecoratorLib_LIBRARY_DEFINED__

/* library ConnectorInstance_DecoratorLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ConnectorInstance_DecoratorLib;

EXTERN_C const CLSID CLSID_ConnectorInstance_Decorator;

#ifdef __cplusplus

class DECLSPEC_UUID("EBC4DE1C-8C90-40C3-9C03-EF115D70D5BC")
ConnectorInstance_Decorator;
#endif
#endif /* __ConnectorInstance_DecoratorLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


