

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sat Mar 05 21:06:02 2011
 */
/* Compiler settings for c:\Program Files\GME\Interfaces\MgaDecorator.idl:
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

#ifndef __MgaDecorator_h__
#define __MgaDecorator_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

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


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "mga.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_MgaDecorator_0000_0000 */
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



extern RPC_IF_HANDLE __MIDL_itf_MgaDecorator_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MgaDecorator_0000_0000_v0_0_s_ifspec;

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
            /* [in] */ IMgaProject *project,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMnemonic( 
            /* [out] */ BSTR *mnemonic) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFeatures( 
            /* [out] */ feature_code *features) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetParam( 
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParam( 
            /* [in] */ BSTR name,
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
            /* [in] */ HDC hdc) = 0;
        
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
            /* [in] */ IMgaProject *project,
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
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            IMgaDecorator * This,
            /* [in] */ BSTR name,
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
            /* [in] */ HDC hdc);
        
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


#define IMgaDecorator_Initialize(This,project,meta,obj)	\
    ( (This)->lpVtbl -> Initialize(This,project,meta,obj) ) 

#define IMgaDecorator_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IMgaDecorator_GetMnemonic(This,mnemonic)	\
    ( (This)->lpVtbl -> GetMnemonic(This,mnemonic) ) 

#define IMgaDecorator_GetFeatures(This,features)	\
    ( (This)->lpVtbl -> GetFeatures(This,features) ) 

#define IMgaDecorator_SetParam(This,name,value)	\
    ( (This)->lpVtbl -> SetParam(This,name,value) ) 

#define IMgaDecorator_GetParam(This,name,value)	\
    ( (This)->lpVtbl -> GetParam(This,name,value) ) 

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
            /* [in] */ IMgaProject *project,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj,
            /* [in] */ IMgaCommonDecoratorEvents *eventSink,
            /* [in] */ ULONGLONG parentWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawEx( 
            /* [in] */ HDC hdc,
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
            /* [in] */ IMgaProject *project,
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
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            IMgaDecoratorCommon * This,
            /* [in] */ BSTR name,
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
            /* [in] */ HDC hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveState )( 
            IMgaDecoratorCommon * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeEx )( 
            IMgaDecoratorCommon * This,
            /* [in] */ IMgaProject *project,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj,
            /* [in] */ IMgaCommonDecoratorEvents *eventSink,
            /* [in] */ ULONGLONG parentWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawEx )( 
            IMgaDecoratorCommon * This,
            /* [in] */ HDC hdc,
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


#define IMgaDecoratorCommon_Initialize(This,project,meta,obj)	\
    ( (This)->lpVtbl -> Initialize(This,project,meta,obj) ) 

#define IMgaDecoratorCommon_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IMgaDecoratorCommon_GetMnemonic(This,mnemonic)	\
    ( (This)->lpVtbl -> GetMnemonic(This,mnemonic) ) 

#define IMgaDecoratorCommon_GetFeatures(This,features)	\
    ( (This)->lpVtbl -> GetFeatures(This,features) ) 

#define IMgaDecoratorCommon_SetParam(This,name,value)	\
    ( (This)->lpVtbl -> SetParam(This,name,value) ) 

#define IMgaDecoratorCommon_GetParam(This,name,value)	\
    ( (This)->lpVtbl -> GetParam(This,name,value) ) 

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


#define IMgaDecoratorCommon_InitializeEx(This,project,meta,obj,eventSink,parentWnd)	\
    ( (This)->lpVtbl -> InitializeEx(This,project,meta,obj,eventSink,parentWnd) ) 

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
            /* [in] */ IMgaProject *project,
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
            /* [in] */ BSTR name,
            /* [in] */ VARIANT value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            IMgaElementDecorator * This,
            /* [in] */ BSTR name,
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
            /* [in] */ HDC hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveState )( 
            IMgaElementDecorator * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeEx )( 
            IMgaElementDecorator * This,
            /* [in] */ IMgaProject *project,
            /* [in] */ IMgaMetaPart *meta,
            /* [in] */ IMgaFCO *obj,
            /* [in] */ IMgaCommonDecoratorEvents *eventSink,
            /* [in] */ ULONGLONG parentWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawEx )( 
            IMgaElementDecorator * This,
            /* [in] */ HDC hdc,
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


#define IMgaElementDecorator_Initialize(This,project,meta,obj)	\
    ( (This)->lpVtbl -> Initialize(This,project,meta,obj) ) 

#define IMgaElementDecorator_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IMgaElementDecorator_GetMnemonic(This,mnemonic)	\
    ( (This)->lpVtbl -> GetMnemonic(This,mnemonic) ) 

#define IMgaElementDecorator_GetFeatures(This,features)	\
    ( (This)->lpVtbl -> GetFeatures(This,features) ) 

#define IMgaElementDecorator_SetParam(This,name,value)	\
    ( (This)->lpVtbl -> SetParam(This,name,value) ) 

#define IMgaElementDecorator_GetParam(This,name,value)	\
    ( (This)->lpVtbl -> GetParam(This,name,value) ) 

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


#define IMgaElementDecorator_InitializeEx(This,project,meta,obj,eventSink,parentWnd)	\
    ( (This)->lpVtbl -> InitializeEx(This,project,meta,obj,eventSink,parentWnd) ) 

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


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HDC_UserSize(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree(     unsigned long *, HDC * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


