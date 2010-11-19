

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Nov 17 10:07:54 2010
 */
/* Compiler settings for .\Extension_Classes_Component.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMgaDataSource,0x9FF8F4E0,0xE0C9,0x11d3,0xB3,0x76,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEApp,0x81191A44,0xB898,0x4143,0xBF,0x8B,0xCA,0x75,0x01,0xFE,0xC1,0x9A);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEIt,0xF2181278,0x749F,0x459d,0x87,0x00,0x92,0xF0,0x88,0xB8,0x0D,0x72);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEModel,0x399A16A0,0xD209,0x4d00,0x9B,0xDF,0x85,0x8D,0x87,0xEC,0x46,0x41);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEAspect,0xEDEEB1F8,0xBC44,0x40d2,0xBE,0x91,0x83,0xE8,0xCC,0xD5,0x98,0x45);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEPanel,0xC047FAEB,0x7AE7,0x40fb,0x8C,0x5C,0x90,0xC7,0x3D,0xAD,0x4B,0xC6);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEColl,0x36C7B797,0x6BDE,0x46d0,0x88,0x70,0x70,0x18,0x90,0x00,0xED,0xF9);


MIDL_DEFINE_GUID(IID, IID_IMgaVersionInfo,0x9A228010,0x020B,0x11d2,0xBB,0xB3,0x00,0x40,0x05,0x1F,0x71,0x17);


MIDL_DEFINE_GUID(IID, LIBID_Extension_Classes_Component,0xE846F962,0x9A92,0x4ab4,0xA6,0xD1,0x54,0x1B,0x94,0x9F,0x05,0x1C);


MIDL_DEFINE_GUID(CLSID, CLSID_Extension_Classes_Component,0x425C5DA2,0x876B,0x46e0,0x9B,0xE9,0x73,0xDD,0x70,0x09,0x67,0xD6);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



