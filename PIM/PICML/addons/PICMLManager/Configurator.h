

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Jun 18 07:37:40 2013
 */
/* Compiler settings for .\Configurator.idl:
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

#ifndef __Configurator_h__
#define __Configurator_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IConfigurator_FWD_DEFINED__
#define __IConfigurator_FWD_DEFINED__
typedef interface IConfigurator IConfigurator;
#endif 	/* __IConfigurator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IConfigurator_INTERFACE_DEFINED__
#define __IConfigurator_INTERFACE_DEFINED__

/* interface IConfigurator */
/* [uuid][object] */ 


EXTERN_C const IID IID_IConfigurator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E638B71-4CC7-49CD-9C0D-6F051233D524")
    IConfigurator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setImplementationFolder( 
            /* [in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setArtifactFolder( 
            /* [in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE resetConfiguration( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConfiguratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConfigurator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConfigurator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConfigurator * This);
        
        HRESULT ( STDMETHODCALLTYPE *setImplementationFolder )( 
            IConfigurator * This,
            /* [in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *setArtifactFolder )( 
            IConfigurator * This,
            /* [in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *resetConfiguration )( 
            IConfigurator * This);
        
        END_INTERFACE
    } IConfiguratorVtbl;

    interface IConfigurator
    {
        CONST_VTBL struct IConfiguratorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConfigurator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConfigurator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConfigurator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConfigurator_setImplementationFolder(This,name)	\
    ( (This)->lpVtbl -> setImplementationFolder(This,name) ) 

#define IConfigurator_setArtifactFolder(This,name)	\
    ( (This)->lpVtbl -> setArtifactFolder(This,name) ) 

#define IConfigurator_resetConfiguration(This)	\
    ( (This)->lpVtbl -> resetConfiguration(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConfigurator_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


