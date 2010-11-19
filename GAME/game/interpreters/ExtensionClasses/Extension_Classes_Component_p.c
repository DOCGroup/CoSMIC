

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "Extension_Classes_Component.h"

#define TYPE_FORMAT_STRING_SIZE   1419                              
#define PROC_FORMAT_STRING_SIZE   5743                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _Extension_Classes_Component_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } Extension_Classes_Component_MIDL_TYPE_FORMAT_STRING;

typedef struct _Extension_Classes_Component_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } Extension_Classes_Component_MIDL_PROC_FORMAT_STRING;

typedef struct _Extension_Classes_Component_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } Extension_Classes_Component_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const Extension_Classes_Component_MIDL_TYPE_FORMAT_STRING Extension_Classes_Component__MIDL_TypeFormatString;
extern const Extension_Classes_Component_MIDL_PROC_FORMAT_STRING Extension_Classes_Component__MIDL_ProcFormatString;
extern const Extension_Classes_Component_MIDL_EXPR_FORMAT_STRING Extension_Classes_Component__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMgaDataSource_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMgaDataSource_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGMEOLEApp_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IGMEOLEApp_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGMEOLEIt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IGMEOLEIt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGMEOLEModel_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IGMEOLEModel_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGMEOLEAspect_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IGMEOLEAspect_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGMEOLEPanel_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IGMEOLEPanel_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGMEOLEColl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IGMEOLEColl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMgaVersionInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMgaVersionInfo_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const Extension_Classes_Component_MIDL_PROC_FORMAT_STRING Extension_Classes_Component__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_Data */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter p */

/* 24 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Folders */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter p */

/* 60 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RegistryData */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 88 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter p */

/* 96 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Project */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0xa ),	/* 10 */
/* 116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter p */

/* 132 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Active */


	/* Procedure put_Visible */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x7 ),	/* 7 */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	NdrFcShort( 0x6 ),	/* 6 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isActive */


	/* Parameter isVisible */

/* 168 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Active */


	/* Procedure get_Visible */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x22 ),	/* 34 */
/* 194 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 196 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isActive */


	/* Parameter isVisible */

/* 204 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 208 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Version */

/* 216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x9 ),	/* 9 */
/* 224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 230 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 232 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 234 */	NdrFcShort( 0x1 ),	/* 1 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter versionStr */

/* 240 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 244 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Valid */


	/* Procedure get_VersionMajor */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0xa ),	/* 10 */
/* 260 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x22 ),	/* 34 */
/* 266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 268 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isValid */


	/* Parameter n */

/* 276 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 280 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Valid */


	/* Procedure get_VersionMinor */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0xb ),	/* 11 */
/* 296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x22 ),	/* 34 */
/* 302 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 304 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isValid */


	/* Parameter n */

/* 312 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 316 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_VersionPatchLevel */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0xc ),	/* 12 */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x22 ),	/* 34 */
/* 338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 340 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter n */

/* 348 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 352 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Models */

/* 360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0xd ),	/* 13 */
/* 368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 374 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 376 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter coll */

/* 384 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 388 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MgaProject */

/* 396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0xe ),	/* 14 */
/* 404 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 410 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 412 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter project */

/* 420 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 422 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 424 */	NdrFcShort( 0x5a ),	/* Type Offset=90 */

	/* Return value */

/* 426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Panels */

/* 432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0xf ),	/* 15 */
/* 440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 446 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 448 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter coll */

/* 456 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 458 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 460 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ConsoleContents */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x10 ),	/* 16 */
/* 476 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 482 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 484 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x1 ),	/* 1 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter contents */

/* 492 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 494 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 496 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 500 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ConsoleContents */

/* 504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x11 ),	/* 17 */
/* 512 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 520 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 522 */	NdrFcShort( 0x1 ),	/* 1 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter contents */

/* 528 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 530 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 532 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 536 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateProject */

/* 540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x12 ),	/* 18 */
/* 548 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 554 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 556 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter metaname */

/* 564 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 566 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 568 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter connstr */

/* 570 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 572 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 574 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenProject */

/* 582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x13 ),	/* 19 */
/* 590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 596 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 598 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x7 ),	/* 7 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter connstr */

/* 606 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 610 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GrayOutHide */


	/* Procedure HideSetMembers */


	/* Procedure CreateProjectDialog */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x14 ),	/* 20 */
/* 626 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 632 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenProjectDialog */

/* 648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x15 ),	/* 21 */
/* 656 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 664 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 674 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseProject */

/* 678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x16 ),	/* 22 */
/* 686 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 688 */	NdrFcShort( 0x6 ),	/* 6 */
/* 690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 692 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter saveOnClose */

/* 702 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 704 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 706 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 710 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveProject */

/* 714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x17 ),	/* 23 */
/* 722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 728 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 730 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DumpModelGeometryXML */


	/* Procedure SaveProjectAs */

/* 744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 750 */	NdrFcShort( 0x18 ),	/* 24 */
/* 752 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 758 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 760 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x7 ),	/* 7 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */


	/* Parameter connstr */

/* 768 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 770 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 772 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */


	/* Return value */

/* 774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 776 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveProjectAsDialog */

/* 780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x19 ),	/* 25 */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 794 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 796 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportProject */

/* 810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x1a ),	/* 26 */
/* 818 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 824 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 826 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x7 ),	/* 7 */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter connstr */

/* 834 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 836 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 838 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 842 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ImportProject */

/* 846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x1b ),	/* 27 */
/* 854 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 860 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 862 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x7 ),	/* 7 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter connstr */

/* 870 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 872 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 874 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 878 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConstraintsDialog */

/* 882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x1c ),	/* 28 */
/* 890 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 896 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 898 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckAllConstraints */

/* 912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x1d ),	/* 29 */
/* 920 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 926 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 928 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterParagimsDialog */

/* 942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x1e ),	/* 30 */
/* 950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 956 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 958 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 966 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 968 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterComponentsDialog */

/* 972 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 974 */	NdrFcLong( 0x0 ),	/* 0 */
/* 978 */	NdrFcShort( 0x1f ),	/* 31 */
/* 980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x8 ),	/* 8 */
/* 986 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 988 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 998 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunComponent */

/* 1002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1010 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1016 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1018 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter progID */

/* 1026 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1030 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 1032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunComponentDialog */

/* 1038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1046 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1052 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1054 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SettingsDialog */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1082 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1084 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Undo */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1106 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1112 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1114 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1122 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Redo */

/* 1128 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1130 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1134 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1136 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1142 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1144 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1154 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearUndoQueue */

/* 1158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1172 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1174 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1184 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProjectPropertiesDialog */

/* 1188 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1202 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1204 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1210 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1214 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowHelpContents */

/* 1218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1226 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1232 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1234 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1240 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1242 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1244 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowAbout */

/* 1248 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1250 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1256 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1262 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1264 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowFCO */

/* 1278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1286 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1288 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1292 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1294 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mgaFCO */

/* 1302 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1306 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter inParent */

/* 1308 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1312 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConsoleMessage */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1328 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1330 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1334 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1336 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter msg */

/* 1344 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter type */

/* 1350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 1356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConsoleClear */

/* 1362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1370 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1378 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConsoleNavigateTo */

/* 1392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1400 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1406 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1408 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter url */

/* 1416 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1420 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 1422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1424 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeEditmode */

/* 1428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1434 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1436 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1438 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1442 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1444 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mode */

/* 1452 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1454 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1456 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 1458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1460 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GridShow */

/* 1464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1472 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1474 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1476 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1478 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1480 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter show */

/* 1488 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1490 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1492 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1496 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AttributepanelPage */

/* 1500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1506 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1508 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1510 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1514 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1516 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter page */

/* 1524 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1526 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1528 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 1530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1532 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OleIt */

/* 1536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1542 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1544 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1550 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1552 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mgamodel */

/* 1560 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1562 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1564 */	NdrFcShort( 0x90 ),	/* Type Offset=144 */

	/* Return value */

/* 1566 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1568 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisableComp */

/* 1572 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1578 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1580 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1582 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1586 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1588 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1592 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1594 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCompProgID */

/* 1596 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1598 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1600 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter pDisable */

/* 1602 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1604 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1606 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1608 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1610 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisableCompForKinds */

/* 1614 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1616 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1622 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1628 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1630 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1634 */	NdrFcShort( 0xe ),	/* 14 */
/* 1636 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCompProgID */

/* 1638 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1640 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1642 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter pKindSequenceDelimitedBySemicolon */

/* 1644 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1646 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1648 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 1650 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1652 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCompFiltering */

/* 1656 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1658 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1664 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1666 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1670 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1672 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTurnOn */

/* 1680 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1682 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1684 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1688 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCompFiltering */

/* 1692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1700 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1706 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1708 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPtrTurnedOn */

/* 1716 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1718 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1720 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1722 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1724 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWorkingDirectory */

/* 1728 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1730 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1734 */	NdrFcShort( 0x35 ),	/* 53 */
/* 1736 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1742 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1744 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1748 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDirPath */

/* 1752 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1754 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1756 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 1758 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1760 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Exit */

/* 1764 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1766 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1770 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1772 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1778 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1780 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1786 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1788 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1790 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RefreshLib */

/* 1794 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1796 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1800 */	NdrFcShort( 0x37 ),	/* 55 */
/* 1802 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1804 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1806 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1808 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1810 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1814 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLibName */

/* 1818 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1820 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1822 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter ungroup */

/* 1824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1826 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1828 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter numOfErrors */

/* 1830 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1832 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1838 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Valid */

/* 1842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1848 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1850 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1856 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1858 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isValid */

/* 1866 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1868 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1870 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1874 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Aspects */

/* 1878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1886 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1892 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1894 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter coll */

/* 1902 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1904 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1906 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1910 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MgaModel */

/* 1914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1920 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1928 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1930 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter model */

/* 1938 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1940 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1942 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 1944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1946 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 1950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1956 */	NdrFcShort( 0xa ),	/* 10 */
/* 1958 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1964 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1966 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1976 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveAll */


	/* Procedure PrintDialog */

/* 1980 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0xb ),	/* 11 */
/* 1988 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1994 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1996 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2002 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 2004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2006 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DumpWindowsMetaFile */

/* 2010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0xc ),	/* 12 */
/* 2018 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2024 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2026 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 2034 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2036 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2038 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 2040 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2042 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrintDialog */


	/* Procedure CheckConstraints */

/* 2046 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2048 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0xd ),	/* 13 */
/* 2054 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2060 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2062 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 2070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2072 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunComponent */

/* 2076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0xe ),	/* 14 */
/* 2084 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2090 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2092 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2096 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter appID */

/* 2100 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2104 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 2106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckConstraints */


	/* Procedure RunComponentDialog */

/* 2112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0xf ),	/* 15 */
/* 2120 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2126 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2128 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 2136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2138 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */

/* 2142 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2156 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2158 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2168 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GrayOutFCO */

/* 2172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2180 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2182 */	NdrFcShort( 0xc ),	/* 12 */
/* 2184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2186 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2188 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bGray */

/* 2196 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2200 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bNeighbours */

/* 2202 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2204 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2206 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter mgaFCO */

/* 2208 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2210 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2212 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Return value */

/* 2214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2216 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */


	/* Procedure GrayOutHide */

/* 2220 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2226 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2234 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2236 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 2244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2246 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowSetMembers */

/* 2250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2256 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2258 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2264 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2266 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2272 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mgaFCO */

/* 2274 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2276 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2278 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 2280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2282 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Zoom */

/* 2286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2292 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2294 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2300 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2302 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter percent */

/* 2310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ZoomTo */

/* 2322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2328 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2330 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2336 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2338 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2344 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mgaFCOs */

/* 2346 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2348 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2350 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Return value */

/* 2352 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2354 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Scroll */

/* 2358 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2364 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2366 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2368 */	NdrFcShort( 0xc ),	/* 12 */
/* 2370 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2372 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2374 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter __MIDL__IGMEOLEIt0000 */

/* 2382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2384 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2386 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter __MIDL__IGMEOLEIt0001 */

/* 2388 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2390 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2392 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 2394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2396 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowFCO */

/* 2400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2408 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2410 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2414 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2416 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2424 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2426 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2428 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter inParent */

/* 2430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2434 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2436 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2438 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowFCOPtr */

/* 2442 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2448 */	NdrFcShort( 0x1a ),	/* 26 */
/* 2450 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2452 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2456 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2458 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2464 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fco */

/* 2466 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2468 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2470 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter inParent */

/* 2472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2474 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2476 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2480 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Child */

/* 2484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0x1b ),	/* 27 */
/* 2492 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2498 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2500 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2504 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2508 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2510 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2512 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter child_fco */

/* 2514 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2516 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2518 */	NdrFcShort( 0xd2 ),	/* Type Offset=210 */

	/* Return value */

/* 2520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2522 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create */

/* 2526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2534 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2540 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2542 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2546 */	NdrFcShort( 0xe ),	/* 14 */
/* 2548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter part */

/* 2550 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2552 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2554 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter name */

/* 2556 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2558 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2560 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter new_fco */

/* 2562 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2564 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2566 */	NdrFcShort( 0xd2 ),	/* Type Offset=210 */

	/* Return value */

/* 2568 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2570 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateInChild */

/* 2574 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2576 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2580 */	NdrFcShort( 0x1d ),	/* 29 */
/* 2582 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2588 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2590 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2594 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2596 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter child_as_parent */

/* 2598 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2600 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2602 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter part */

/* 2604 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2606 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2608 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter name */

/* 2610 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2612 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2614 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter new_fco */

/* 2616 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2618 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2620 */	NdrFcShort( 0xd2 ),	/* Type Offset=210 */

	/* Return value */

/* 2622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2624 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateInChildFCO */

/* 2628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2634 */	NdrFcShort( 0x1e ),	/* 30 */
/* 2636 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2642 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2644 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0xe ),	/* 14 */
/* 2650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter child_as_parent */

/* 2652 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2654 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2656 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter part */

/* 2658 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2660 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2662 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter name */

/* 2664 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2666 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2668 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter new_fco */

/* 2670 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2672 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2674 */	NdrFcShort( 0xd2 ),	/* Type Offset=210 */

	/* Return value */

/* 2676 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2678 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Duplicate */

/* 2682 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x1f ),	/* 31 */
/* 2690 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2694 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2696 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2698 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2702 */	NdrFcShort( 0xe ),	/* 14 */
/* 2704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter existing_fco_name */

/* 2706 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2708 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2710 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter new_fco_name */

/* 2712 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2714 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2716 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter new_fco */

/* 2718 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2720 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2722 */	NdrFcShort( 0xd2 ),	/* Type Offset=210 */

	/* Return value */

/* 2724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2726 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DuplicateFCO */

/* 2730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2736 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2738 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2744 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2746 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2750 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter existing_fco */

/* 2754 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2758 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter new_fco_name */

/* 2760 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2762 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2764 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter new_fco */

/* 2766 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2768 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2770 */	NdrFcShort( 0xd2 ),	/* Type Offset=210 */

	/* Return value */

/* 2772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2774 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Rename */

/* 2778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2786 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2792 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2794 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2798 */	NdrFcShort( 0xe ),	/* 14 */
/* 2800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter oldname */

/* 2802 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2804 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2806 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter newname */

/* 2808 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2810 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2812 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 2814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2816 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 2820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2826 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2828 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2834 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2836 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter __MIDL__IGMEOLEIt0002 */

/* 2844 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2846 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2848 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter name */

/* 2850 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2852 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2854 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 2856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2858 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Include */

/* 2862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2868 */	NdrFcShort( 0x23 ),	/* 35 */
/* 2870 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2876 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2878 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2882 */	NdrFcShort( 0xe ),	/* 14 */
/* 2884 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter setname */

/* 2886 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2888 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2890 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter name */

/* 2892 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2894 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2896 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 2898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Exclude */

/* 2904 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2910 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2912 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2918 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2920 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2924 */	NdrFcShort( 0xe ),	/* 14 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter setname */

/* 2928 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2930 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2932 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter membername */

/* 2934 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2936 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2938 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 2940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2942 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IncludeFCO */

/* 2946 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0x25 ),	/* 37 */
/* 2954 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2958 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2960 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2962 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter p_set */

/* 2970 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2972 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2974 */	NdrFcShort( 0xd6 ),	/* Type Offset=214 */

	/* Parameter fco */

/* 2976 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2978 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2980 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 2982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2984 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExcludeFCO */

/* 2988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2994 */	NdrFcShort( 0x26 ),	/* 38 */
/* 2996 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3002 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3004 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter p_set */

/* 3012 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3014 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3016 */	NdrFcShort( 0xd6 ),	/* Type Offset=214 */

	/* Parameter fco */

/* 3018 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3020 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3022 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 3024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3026 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Connect */

/* 3030 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3036 */	NdrFcShort( 0x27 ),	/* 39 */
/* 3038 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3044 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3046 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3050 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3052 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_part */

/* 3054 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3056 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3058 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter dst_part */

/* 3060 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3062 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3064 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter connection_role */

/* 3066 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3068 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3070 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter conn */

/* 3072 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3074 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3076 */	NdrFcShort( 0xe8 ),	/* Type Offset=232 */

	/* Return value */

/* 3078 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3080 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Disconnect */

/* 3084 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3086 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3090 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3092 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3098 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3100 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3104 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_part */

/* 3108 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3112 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter dst_part */

/* 3114 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3118 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter connection_name */

/* 3120 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3122 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3124 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 3126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3128 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConnectThruPort */

/* 3132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x29 ),	/* 41 */
/* 3140 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3146 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3148 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3152 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_part_1 */

/* 3156 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3160 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter src_part_2 */

/* 3162 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3164 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3166 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter dst_part_1 */

/* 3168 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3170 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3172 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter dst_part_2 */

/* 3174 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3176 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3178 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter connection_role */

/* 3180 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3182 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3184 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter conn */

/* 3186 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3188 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3190 */	NdrFcShort( 0xe8 ),	/* Type Offset=232 */

	/* Return value */

/* 3192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3194 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConnectThruPortFCO */

/* 3198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3204 */	NdrFcShort( 0x2a ),	/* 42 */
/* 3206 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3212 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3214 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3218 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_part_1 */

/* 3222 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3226 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter src_part_2 */

/* 3228 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3230 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3232 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter dst_part_1 */

/* 3234 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3238 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter dst_part_2 */

/* 3240 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3242 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3244 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter connection_role */

/* 3246 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3248 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3250 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter conn */

/* 3252 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3254 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3256 */	NdrFcShort( 0xe8 ),	/* Type Offset=232 */

	/* Return value */

/* 3258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3260 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisconnectThruPort */

/* 3264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3270 */	NdrFcShort( 0x2b ),	/* 43 */
/* 3272 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3278 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3280 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3284 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_part_1 */

/* 3288 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3292 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter src_part_2 */

/* 3294 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3298 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter dst_part_1 */

/* 3300 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3302 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3304 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter dst_part_2 */

/* 3306 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3308 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3310 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter connection_name */

/* 3312 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3314 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3316 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 3318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3320 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConnectFCOs */

/* 3324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3330 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3332 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3338 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3340 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3344 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_part */

/* 3348 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3352 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter dst_part */

/* 3354 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3358 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter connection_role */

/* 3360 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3362 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3364 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter conn */

/* 3366 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3368 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3370 */	NdrFcShort( 0xe8 ),	/* Type Offset=232 */

	/* Return value */

/* 3372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3374 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisconnectFCOs */

/* 3378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3384 */	NdrFcShort( 0x2d ),	/* 45 */
/* 3386 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3392 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3394 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3398 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_part */

/* 3402 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3406 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter dst_part */

/* 3408 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3412 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter connection_name */

/* 3414 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3418 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 3420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3422 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Refer */

/* 3426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3432 */	NdrFcShort( 0x2e ),	/* 46 */
/* 3434 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3440 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3442 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3446 */	NdrFcShort( 0xe ),	/* 14 */
/* 3448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reference */

/* 3450 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3452 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3454 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter referred */

/* 3456 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3458 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3460 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 3462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3464 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearRef */

/* 3468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3474 */	NdrFcShort( 0x2f ),	/* 47 */
/* 3476 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3482 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3484 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3488 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reference */

/* 3492 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3494 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3496 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 3498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3500 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FollowRef */

/* 3504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3510 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3512 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3518 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3520 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3524 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reference */

/* 3528 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3530 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3532 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 3534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3536 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReferFCO */

/* 3540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3546 */	NdrFcShort( 0x31 ),	/* 49 */
/* 3548 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3554 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3556 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reference */

/* 3564 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3566 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3568 */	NdrFcShort( 0xfe ),	/* Type Offset=254 */

	/* Parameter referred */

/* 3570 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3572 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3574 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 3576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3578 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearRefFCO */

/* 3582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3588 */	NdrFcShort( 0x32 ),	/* 50 */
/* 3590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3596 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3598 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reference */

/* 3606 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3610 */	NdrFcShort( 0xfe ),	/* Type Offset=254 */

	/* Return value */

/* 3612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FollowRefFCO */

/* 3618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3624 */	NdrFcShort( 0x33 ),	/* 51 */
/* 3626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3632 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reference */

/* 3642 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3646 */	NdrFcShort( 0xfe ),	/* Type Offset=254 */

	/* Return value */

/* 3648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NullFCO */

/* 3654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3660 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3668 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3670 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nullobj */

/* 3678 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3682 */	NdrFcShort( 0xd2 ),	/* Type Offset=210 */

	/* Return value */

/* 3684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAttribute */

/* 3690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3696 */	NdrFcShort( 0x35 ),	/* 53 */
/* 3698 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3704 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3706 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3710 */	NdrFcShort( 0xb9 ),	/* 185 */
/* 3712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3714 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3718 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter attr_name */

/* 3720 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3724 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter value */

/* 3726 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3730 */	NdrFcShort( 0x506 ),	/* Type Offset=1286 */

	/* Return value */

/* 3732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3734 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAttribute */

/* 3738 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3744 */	NdrFcShort( 0x36 ),	/* 54 */
/* 3746 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3752 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3754 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3756 */	NdrFcShort( 0xc7 ),	/* 199 */
/* 3758 */	NdrFcShort( 0xa ),	/* 10 */
/* 3760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3762 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3764 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3766 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter attr_name */

/* 3768 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3770 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3772 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter value */

/* 3774 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 3776 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3778 */	NdrFcShort( 0x518 ),	/* Type Offset=1304 */

	/* Return value */

/* 3780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3782 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAttributeFCO */

/* 3786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3792 */	NdrFcShort( 0x37 ),	/* 55 */
/* 3794 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3800 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3802 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3806 */	NdrFcShort( 0xe6 ),	/* 230 */
/* 3808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fco */

/* 3810 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3814 */	NdrFcShort( 0x522 ),	/* Type Offset=1314 */

	/* Parameter attr_name */

/* 3816 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3820 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter value */

/* 3822 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3826 */	NdrFcShort( 0x506 ),	/* Type Offset=1286 */

	/* Return value */

/* 3828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3830 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAttributeFCO */

/* 3834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3840 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3842 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3848 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3850 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3852 */	NdrFcShort( 0x105 ),	/* 261 */
/* 3854 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fco */

/* 3858 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3862 */	NdrFcShort( 0x522 ),	/* Type Offset=1314 */

	/* Parameter attr_name */

/* 3864 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3868 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter value */

/* 3870 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 3872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3874 */	NdrFcShort( 0x518 ),	/* Type Offset=1304 */

	/* Return value */

/* 3876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3878 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SubType */

/* 3882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3888 */	NdrFcShort( 0x39 ),	/* 57 */
/* 3890 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3896 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3898 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3902 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter base */

/* 3906 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3910 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter name_of_subtype */

/* 3912 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3914 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3916 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter subtype */

/* 3918 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3920 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3922 */	NdrFcShort( 0x534 ),	/* Type Offset=1332 */

	/* Return value */

/* 3924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3926 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Instantiate */

/* 3930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3936 */	NdrFcShort( 0x3a ),	/* 58 */
/* 3938 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3944 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3946 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3950 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3952 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter base */

/* 3954 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3956 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3958 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter name_of_instance */

/* 3960 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3962 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3964 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter instance */

/* 3966 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3968 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3970 */	NdrFcShort( 0x534 ),	/* Type Offset=1332 */

	/* Return value */

/* 3972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3974 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SubTypeFCO */

/* 3978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3984 */	NdrFcShort( 0x3b ),	/* 59 */
/* 3986 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3992 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3994 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3998 */	NdrFcShort( 0xf ),	/* 15 */
/* 4000 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter base */

/* 4002 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4004 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4006 */	NdrFcShort( 0x522 ),	/* Type Offset=1314 */

	/* Parameter name_of_subtype */

/* 4008 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4010 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4012 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter subtype */

/* 4014 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4016 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4018 */	NdrFcShort( 0x534 ),	/* Type Offset=1332 */

	/* Return value */

/* 4020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4022 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InstantiateFCO */

/* 4026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4032 */	NdrFcShort( 0x3c ),	/* 60 */
/* 4034 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4040 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4042 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4046 */	NdrFcShort( 0xf ),	/* 15 */
/* 4048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter base */

/* 4050 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4054 */	NdrFcShort( 0x522 ),	/* Type Offset=1314 */

	/* Parameter name_of_instance */

/* 4056 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4060 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter instance */

/* 4062 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4064 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4066 */	NdrFcShort( 0x534 ),	/* Type Offset=1332 */

	/* Return value */

/* 4068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4070 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BeginTransaction */

/* 4074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4080 */	NdrFcShort( 0x3d ),	/* 61 */
/* 4082 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4088 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4090 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4100 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CommitTransaction */

/* 4104 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4110 */	NdrFcShort( 0x3e ),	/* 62 */
/* 4112 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4118 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4120 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4130 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AbortTransaction */

/* 4134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4140 */	NdrFcShort( 0x3f ),	/* 63 */
/* 4142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4146 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4148 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4150 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4160 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsInTransaction */

/* 4164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4170 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4172 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4176 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4178 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4180 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter intrans */

/* 4188 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4192 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutInTerritory */

/* 4200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4206 */	NdrFcShort( 0x41 ),	/* 65 */
/* 4208 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4214 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4216 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fco */

/* 4224 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4226 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4228 */	NdrFcShort( 0x522 ),	/* Type Offset=1314 */

	/* Parameter newfco */

/* 4230 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4232 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4234 */	NdrFcShort( 0x534 ),	/* Type Offset=1332 */

	/* Return value */

/* 4236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4238 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Help */

/* 4242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4248 */	NdrFcShort( 0x42 ),	/* 66 */
/* 4250 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4256 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4258 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSelected */

/* 4272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4278 */	NdrFcShort( 0x43 ),	/* 67 */
/* 4280 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4286 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4288 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4292 */	NdrFcShort( 0xf ),	/* 15 */
/* 4294 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter space_delimited_string */

/* 4296 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4298 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4300 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 4302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4304 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSelected */

/* 4308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4314 */	NdrFcShort( 0x44 ),	/* 68 */
/* 4316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4322 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4324 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4326 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4330 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter space_delimited_string */

/* 4332 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4334 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4336 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 4338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4340 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSelectedFCOs */

/* 4344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4350 */	NdrFcShort( 0x45 ),	/* 69 */
/* 4352 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4358 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4360 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fcos_to_select */

/* 4368 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4372 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Return value */

/* 4374 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSelectedFCOs */

/* 4380 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4386 */	NdrFcShort( 0x46 ),	/* 70 */
/* 4388 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4392 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4394 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4396 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter selected_fcos */

/* 4404 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4406 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4408 */	NdrFcShort( 0x538 ),	/* Type Offset=1336 */

	/* Return value */

/* 4410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4412 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurrentAspect */

/* 4416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4422 */	NdrFcShort( 0x47 ),	/* 71 */
/* 4424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4430 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4432 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4434 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4438 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter aspectName */

/* 4440 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 4442 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4444 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 4446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4448 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCurrentAspect */

/* 4452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4458 */	NdrFcShort( 0x48 ),	/* 72 */
/* 4460 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4466 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4468 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4472 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter aspectName */

/* 4476 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4478 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4480 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 4482 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NextAspect */

/* 4488 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4490 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4494 */	NdrFcShort( 0x49 ),	/* 73 */
/* 4496 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4502 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4504 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4510 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4514 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrevAspect */

/* 4518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4524 */	NdrFcShort( 0x4a ),	/* 74 */
/* 4526 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4532 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4534 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 4548 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4554 */	NdrFcShort( 0x4b ),	/* 75 */
/* 4556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4562 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4564 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4570 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4574 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Prev */

/* 4578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4584 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4592 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4594 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4600 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4604 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Position */

/* 4608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4614 */	NdrFcShort( 0x4d ),	/* 77 */
/* 4616 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4618 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4622 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4624 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4628 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter child */

/* 4632 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4634 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4636 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter aspect */

/* 4638 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4640 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4642 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter parX */

/* 4644 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter parY */

/* 4650 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4652 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4658 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PositionFCO */

/* 4662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4668 */	NdrFcShort( 0x4e ),	/* 78 */
/* 4670 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4672 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4676 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4678 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4682 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fco */

/* 4686 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4688 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4690 */	NdrFcShort( 0x522 ),	/* Type Offset=1314 */

	/* Parameter aspect */

/* 4692 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4694 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4696 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Parameter parX */

/* 4698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4700 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter parY */

/* 4704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4706 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4712 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Aspects */

/* 4716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4722 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4724 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4730 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4732 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter coll */

/* 4740 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4742 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4744 */	NdrFcShort( 0x53c ),	/* Type Offset=1340 */

	/* Return value */

/* 4746 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4748 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MgaModel */

/* 4752 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4758 */	NdrFcShort( 0xa ),	/* 10 */
/* 4760 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4766 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4768 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4774 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter model */

/* 4776 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4778 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4780 */	NdrFcShort( 0x552 ),	/* Type Offset=1362 */

	/* Return value */

/* 4782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4784 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 4788 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4794 */	NdrFcShort( 0xc ),	/* 12 */
/* 4796 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4802 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4804 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4814 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DumpWindowsMetaFile */

/* 4818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4824 */	NdrFcShort( 0xe ),	/* 14 */
/* 4826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4832 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4834 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4838 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 4842 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4846 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 4848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunComponent */

/* 4854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4860 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4868 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4870 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4874 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter appID */

/* 4878 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4882 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 4884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunComponentDialog */

/* 4890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4896 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4898 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4904 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4906 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4914 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GrayOutFCO */

/* 4920 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4926 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4928 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4930 */	NdrFcShort( 0xc ),	/* 12 */
/* 4932 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4934 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4936 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4942 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bGray */

/* 4944 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4946 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4948 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bNeighbours */

/* 4950 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4952 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4954 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter mgaFCO */

/* 4956 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4958 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4960 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Return value */

/* 4962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4964 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowSetMembers */

/* 4968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4974 */	NdrFcShort( 0x15 ),	/* 21 */
/* 4976 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4982 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4984 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4990 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mgaFCO */

/* 4992 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4994 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4996 */	NdrFcShort( 0x522 ),	/* Type Offset=1314 */

	/* Return value */

/* 4998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HideSetMembers */

/* 5004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5010 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5012 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5018 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5020 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5030 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Zoom */

/* 5034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5040 */	NdrFcShort( 0x17 ),	/* 23 */
/* 5042 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5048 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5050 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter percent */

/* 5058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5060 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5064 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5066 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ZoomTo */

/* 5070 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5076 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5078 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5084 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5086 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mgaFCOs */

/* 5094 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5096 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5098 */	NdrFcShort( 0xc0 ),	/* Type Offset=192 */

	/* Return value */

/* 5100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5102 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Scroll */

/* 5106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5112 */	NdrFcShort( 0x19 ),	/* 25 */
/* 5114 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5116 */	NdrFcShort( 0xc ),	/* 12 */
/* 5118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5120 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5122 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter __MIDL__IGMEOLEModel0000 */

/* 5130 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5132 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5134 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter __MIDL__IGMEOLEModel0001 */

/* 5136 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5138 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5140 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 5142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5144 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DumpModelGeometryXML */

/* 5148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5154 */	NdrFcShort( 0x1a ),	/* 26 */
/* 5156 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5162 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5164 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5168 */	NdrFcShort( 0x11 ),	/* 17 */
/* 5170 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 5172 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5174 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5176 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 5178 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5180 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurrentAspect */

/* 5184 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5186 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5190 */	NdrFcShort( 0x1b ),	/* 27 */
/* 5192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5196 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5198 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5200 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 5202 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter aspectName */

/* 5208 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 5210 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5212 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 5214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5216 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCurrentAspect */

/* 5220 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5226 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5228 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5232 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5234 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5236 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5240 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter aspectName */

/* 5244 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5246 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5248 */	NdrFcShort( 0x74 ),	/* Type Offset=116 */

	/* Return value */

/* 5250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5252 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MgaAspect */

/* 5256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5262 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5264 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5270 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5272 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5278 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter aspect */

/* 5280 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5282 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5284 */	NdrFcShort( 0x568 ),	/* Type Offset=1384 */

	/* Return value */

/* 5286 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5288 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Visible */


	/* Procedure put_Active */

/* 5292 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5294 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5300 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5302 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5304 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5306 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5308 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5314 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isVisible */


	/* Parameter isActive */

/* 5316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5318 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5320 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5324 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Visible */


	/* Procedure get_Active */

/* 5328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5334 */	NdrFcShort( 0x9 ),	/* 9 */
/* 5336 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5340 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5342 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5344 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isVisible */


	/* Parameter isActive */

/* 5352 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5354 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5356 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5360 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */

/* 5364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5370 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5372 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5378 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5380 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 5382 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 5388 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 5390 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5392 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 5394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5396 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Interface */

/* 5400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5406 */	NdrFcShort( 0xa ),	/* 10 */
/* 5408 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5414 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5416 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter interf */

/* 5424 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5426 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5428 */	NdrFcShort( 0x57e ),	/* Type Offset=1406 */

	/* Return value */

/* 5430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */

/* 5436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5442 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5444 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5448 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5450 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5452 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cnt */

/* 5460 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5462 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5466 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5468 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 5472 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5480 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5484 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5486 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5488 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5494 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newValue */

/* 5496 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5498 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5500 */	NdrFcShort( 0x30e ),	/* Type Offset=782 */

	/* Return value */

/* 5502 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5504 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 5508 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5514 */	NdrFcShort( 0x9 ),	/* 9 */
/* 5516 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5520 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5522 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5524 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter findValue */

/* 5532 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5534 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5536 */	NdrFcShort( 0x30e ),	/* Type Offset=782 */

	/* Parameter cnt */

/* 5538 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5540 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5546 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */

/* 5550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5556 */	NdrFcShort( 0xa ),	/* 10 */
/* 5558 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5564 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5566 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5570 */	NdrFcShort( 0x136 ),	/* 310 */
/* 5572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter removeValue */

/* 5574 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5576 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5578 */	NdrFcShort( 0x506 ),	/* Type Offset=1286 */

	/* Return value */

/* 5580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5582 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 5586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5592 */	NdrFcShort( 0xc ),	/* 12 */
/* 5594 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5596 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5600 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5602 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5608 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 5610 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5612 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter val */

/* 5616 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5618 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5620 */	NdrFcShort( 0x57e ),	/* Type Offset=1406 */

	/* Return value */

/* 5622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5624 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Item */

/* 5628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5634 */	NdrFcShort( 0xd ),	/* 13 */
/* 5636 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5642 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5644 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 5652 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5654 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter newValue */

/* 5658 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5660 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5662 */	NdrFcShort( 0x30e ),	/* Type Offset=782 */

	/* Return value */

/* 5664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5666 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 5670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5676 */	NdrFcShort( 0xe ),	/* 14 */
/* 5678 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5682 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5684 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5686 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5692 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter e */

/* 5694 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5696 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5698 */	NdrFcShort( 0x582 ),	/* Type Offset=1410 */

	/* Return value */

/* 5700 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5702 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_version */

/* 5706 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5708 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5712 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5714 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5718 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5720 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5722 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 5730 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 5732 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5734 */	NdrFcShort( 0x586 ),	/* Type Offset=1414 */

	/* Return value */

/* 5736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5738 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const Extension_Classes_Component_MIDL_TYPE_FORMAT_STRING Extension_Classes_Component__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 20 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 22 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 24 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 26 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 28 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 30 */	NdrFcShort( 0x1c ),	/* Offset= 28 (58) */
/* 32 */	
			0x13, 0x0,	/* FC_OP */
/* 34 */	NdrFcShort( 0xe ),	/* Offset= 14 (48) */
/* 36 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 38 */	NdrFcShort( 0x2 ),	/* 2 */
/* 40 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 42 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 44 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 46 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 48 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (36) */
/* 54 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 56 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 58 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x4 ),	/* 4 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */
/* 66 */	NdrFcShort( 0xffde ),	/* Offset= -34 (32) */
/* 68 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 70 */	NdrFcShort( 0x2 ),	/* Offset= 2 (72) */
/* 72 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 74 */	NdrFcLong( 0x36c7b797 ),	/* 919058327 */
/* 78 */	NdrFcShort( 0x6bde ),	/* 27614 */
/* 80 */	NdrFcShort( 0x46d0 ),	/* 18128 */
/* 82 */	0x88,		/* 136 */
			0x70,		/* 112 */
/* 84 */	0x70,		/* 112 */
			0x18,		/* 24 */
/* 86 */	0x90,		/* 144 */
			0x0,		/* 0 */
/* 88 */	0xed,		/* 237 */
			0xf9,		/* 249 */
/* 90 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 92 */	NdrFcShort( 0x2 ),	/* Offset= 2 (94) */
/* 94 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 96 */	NdrFcLong( 0x270b4f92 ),	/* 655052690 */
/* 100 */	NdrFcShort( 0xb17c ),	/* -20100 */
/* 102 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 104 */	0x9a,		/* 154 */
			0xd1,		/* 209 */
/* 106 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 108 */	0x0,		/* 0 */
			0xb6,		/* 182 */
/* 110 */	0xfe,		/* 254 */
			0x26,		/* 38 */
/* 112 */	
			0x12, 0x0,	/* FC_UP */
/* 114 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (48) */
/* 116 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x4 ),	/* 4 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (112) */
/* 126 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 128 */	NdrFcLong( 0x270b4f98 ),	/* 655052696 */
/* 132 */	NdrFcShort( 0xb17c ),	/* -20100 */
/* 134 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 136 */	0x9a,		/* 154 */
			0xd1,		/* 209 */
/* 138 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 140 */	0x0,		/* 0 */
			0xb6,		/* 182 */
/* 142 */	0xfe,		/* 254 */
			0x26,		/* 38 */
/* 144 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 146 */	NdrFcShort( 0x2 ),	/* Offset= 2 (148) */
/* 148 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 150 */	NdrFcLong( 0xf2181278 ),	/* -233303432 */
/* 154 */	NdrFcShort( 0x749f ),	/* 29855 */
/* 156 */	NdrFcShort( 0x459d ),	/* 17821 */
/* 158 */	0x87,		/* 135 */
			0x0,		/* 0 */
/* 160 */	0x92,		/* 146 */
			0xf0,		/* 240 */
/* 162 */	0x88,		/* 136 */
			0xb8,		/* 184 */
/* 164 */	0xd,		/* 13 */
			0x72,		/* 114 */
/* 166 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 168 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 170 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 172 */	NdrFcShort( 0x2 ),	/* Offset= 2 (174) */
/* 174 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 176 */	NdrFcLong( 0x270b4f9a ),	/* 655052698 */
/* 180 */	NdrFcShort( 0xb17c ),	/* -20100 */
/* 182 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 184 */	0x9a,		/* 154 */
			0xd1,		/* 209 */
/* 186 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 188 */	0x0,		/* 0 */
			0xb6,		/* 182 */
/* 190 */	0xfe,		/* 254 */
			0x26,		/* 38 */
/* 192 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 194 */	NdrFcLong( 0xc5f4c2f0 ),	/* -973815056 */
/* 198 */	NdrFcShort( 0xc1fd ),	/* -15875 */
/* 200 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 202 */	0x9a,		/* 154 */
			0xd2,		/* 210 */
/* 204 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 206 */	0x0,		/* 0 */
			0xb6,		/* 182 */
/* 208 */	0xfe,		/* 254 */
			0x26,		/* 38 */
/* 210 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 212 */	NdrFcShort( 0xffaa ),	/* Offset= -86 (126) */
/* 214 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 216 */	NdrFcLong( 0x83ba3235 ),	/* -2084949451 */
/* 220 */	NdrFcShort( 0xb758 ),	/* -18600 */
/* 222 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 224 */	0xab,		/* 171 */
			0xae,		/* 174 */
/* 226 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 228 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 230 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 232 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 234 */	NdrFcShort( 0x2 ),	/* Offset= 2 (236) */
/* 236 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 238 */	NdrFcLong( 0x270b4fa0 ),	/* 655052704 */
/* 242 */	NdrFcShort( 0xb17c ),	/* -20100 */
/* 244 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 246 */	0x9a,		/* 154 */
			0xd1,		/* 209 */
/* 248 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 250 */	0x0,		/* 0 */
			0xb6,		/* 182 */
/* 252 */	0xfe,		/* 254 */
			0x26,		/* 38 */
/* 254 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 256 */	NdrFcLong( 0x83ba3233 ),	/* -2084949453 */
/* 260 */	NdrFcShort( 0xb758 ),	/* -18600 */
/* 262 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 264 */	0xab,		/* 171 */
			0xae,		/* 174 */
/* 266 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 268 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 270 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 272 */	
			0x12, 0x0,	/* FC_UP */
/* 274 */	NdrFcShort( 0x3e0 ),	/* Offset= 992 (1266) */
/* 276 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 278 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 280 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 282 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 284 */	NdrFcShort( 0x2 ),	/* Offset= 2 (286) */
/* 286 */	NdrFcShort( 0x10 ),	/* 16 */
/* 288 */	NdrFcShort( 0x2f ),	/* 47 */
/* 290 */	NdrFcLong( 0x14 ),	/* 20 */
/* 294 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 296 */	NdrFcLong( 0x3 ),	/* 3 */
/* 300 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 302 */	NdrFcLong( 0x11 ),	/* 17 */
/* 306 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 308 */	NdrFcLong( 0x2 ),	/* 2 */
/* 312 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 314 */	NdrFcLong( 0x4 ),	/* 4 */
/* 318 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 320 */	NdrFcLong( 0x5 ),	/* 5 */
/* 324 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 326 */	NdrFcLong( 0xb ),	/* 11 */
/* 330 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 332 */	NdrFcLong( 0xa ),	/* 10 */
/* 336 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 338 */	NdrFcLong( 0x6 ),	/* 6 */
/* 342 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (574) */
/* 344 */	NdrFcLong( 0x7 ),	/* 7 */
/* 348 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 350 */	NdrFcLong( 0x8 ),	/* 8 */
/* 354 */	NdrFcShort( 0xff0e ),	/* Offset= -242 (112) */
/* 356 */	NdrFcLong( 0xd ),	/* 13 */
/* 360 */	NdrFcShort( 0xfe9e ),	/* Offset= -354 (6) */
/* 362 */	NdrFcLong( 0x9 ),	/* 9 */
/* 366 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (580) */
/* 368 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 372 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (598) */
/* 374 */	NdrFcLong( 0x24 ),	/* 36 */
/* 378 */	NdrFcShort( 0x32e ),	/* Offset= 814 (1192) */
/* 380 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 384 */	NdrFcShort( 0x328 ),	/* Offset= 808 (1192) */
/* 386 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 390 */	NdrFcShort( 0x326 ),	/* Offset= 806 (1196) */
/* 392 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 396 */	NdrFcShort( 0x324 ),	/* Offset= 804 (1200) */
/* 398 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 402 */	NdrFcShort( 0x322 ),	/* Offset= 802 (1204) */
/* 404 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 408 */	NdrFcShort( 0x320 ),	/* Offset= 800 (1208) */
/* 410 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 414 */	NdrFcShort( 0x31e ),	/* Offset= 798 (1212) */
/* 416 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 420 */	NdrFcShort( 0x31c ),	/* Offset= 796 (1216) */
/* 422 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 426 */	NdrFcShort( 0x306 ),	/* Offset= 774 (1200) */
/* 428 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 432 */	NdrFcShort( 0x304 ),	/* Offset= 772 (1204) */
/* 434 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 438 */	NdrFcShort( 0x30e ),	/* Offset= 782 (1220) */
/* 440 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 444 */	NdrFcShort( 0x304 ),	/* Offset= 772 (1216) */
/* 446 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 450 */	NdrFcShort( 0x306 ),	/* Offset= 774 (1224) */
/* 452 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 456 */	NdrFcShort( 0x304 ),	/* Offset= 772 (1228) */
/* 458 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 462 */	NdrFcShort( 0x302 ),	/* Offset= 770 (1232) */
/* 464 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 468 */	NdrFcShort( 0x300 ),	/* Offset= 768 (1236) */
/* 470 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 474 */	NdrFcShort( 0x2fe ),	/* Offset= 766 (1240) */
/* 476 */	NdrFcLong( 0x10 ),	/* 16 */
/* 480 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 482 */	NdrFcLong( 0x12 ),	/* 18 */
/* 486 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 488 */	NdrFcLong( 0x13 ),	/* 19 */
/* 492 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 494 */	NdrFcLong( 0x15 ),	/* 21 */
/* 498 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 500 */	NdrFcLong( 0x16 ),	/* 22 */
/* 504 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 506 */	NdrFcLong( 0x17 ),	/* 23 */
/* 510 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 512 */	NdrFcLong( 0xe ),	/* 14 */
/* 516 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (1248) */
/* 518 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 522 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (1258) */
/* 524 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 528 */	NdrFcShort( 0x2de ),	/* Offset= 734 (1262) */
/* 530 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 534 */	NdrFcShort( 0x29a ),	/* Offset= 666 (1200) */
/* 536 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 540 */	NdrFcShort( 0x298 ),	/* Offset= 664 (1204) */
/* 542 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 546 */	NdrFcShort( 0x296 ),	/* Offset= 662 (1208) */
/* 548 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 552 */	NdrFcShort( 0x28c ),	/* Offset= 652 (1204) */
/* 554 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 558 */	NdrFcShort( 0x286 ),	/* Offset= 646 (1204) */
/* 560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* Offset= 0 (564) */
/* 566 */	NdrFcLong( 0x1 ),	/* 1 */
/* 570 */	NdrFcShort( 0x0 ),	/* Offset= 0 (570) */
/* 572 */	NdrFcShort( 0xffff ),	/* Offset= -1 (571) */
/* 574 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 578 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 580 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 582 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 592 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 594 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 596 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 598 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 600 */	NdrFcShort( 0x2 ),	/* Offset= 2 (602) */
/* 602 */	
			0x12, 0x0,	/* FC_UP */
/* 604 */	NdrFcShort( 0x23a ),	/* Offset= 570 (1174) */
/* 606 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 608 */	NdrFcShort( 0x18 ),	/* 24 */
/* 610 */	NdrFcShort( 0xa ),	/* 10 */
/* 612 */	NdrFcLong( 0x8 ),	/* 8 */
/* 616 */	NdrFcShort( 0x5a ),	/* Offset= 90 (706) */
/* 618 */	NdrFcLong( 0xd ),	/* 13 */
/* 622 */	NdrFcShort( 0x90 ),	/* Offset= 144 (766) */
/* 624 */	NdrFcLong( 0x9 ),	/* 9 */
/* 628 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (822) */
/* 630 */	NdrFcLong( 0xc ),	/* 12 */
/* 634 */	NdrFcShort( 0xec ),	/* Offset= 236 (870) */
/* 636 */	NdrFcLong( 0x24 ),	/* 36 */
/* 640 */	NdrFcShort( 0x148 ),	/* Offset= 328 (968) */
/* 642 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 646 */	NdrFcShort( 0x164 ),	/* Offset= 356 (1002) */
/* 648 */	NdrFcLong( 0x10 ),	/* 16 */
/* 652 */	NdrFcShort( 0x17e ),	/* Offset= 382 (1034) */
/* 654 */	NdrFcLong( 0x2 ),	/* 2 */
/* 658 */	NdrFcShort( 0x198 ),	/* Offset= 408 (1066) */
/* 660 */	NdrFcLong( 0x3 ),	/* 3 */
/* 664 */	NdrFcShort( 0x1b2 ),	/* Offset= 434 (1098) */
/* 666 */	NdrFcLong( 0x14 ),	/* 20 */
/* 670 */	NdrFcShort( 0x1cc ),	/* Offset= 460 (1130) */
/* 672 */	NdrFcShort( 0xffff ),	/* Offset= -1 (671) */
/* 674 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 676 */	NdrFcShort( 0x4 ),	/* 4 */
/* 678 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 684 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 686 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 688 */	NdrFcShort( 0x4 ),	/* 4 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	NdrFcShort( 0x1 ),	/* 1 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	0x12, 0x0,	/* FC_UP */
/* 700 */	NdrFcShort( 0xfd74 ),	/* Offset= -652 (48) */
/* 702 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 704 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 706 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 710 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 712 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 714 */	NdrFcShort( 0x4 ),	/* 4 */
/* 716 */	NdrFcShort( 0x4 ),	/* 4 */
/* 718 */	0x11, 0x0,	/* FC_RP */
/* 720 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (674) */
/* 722 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 724 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 726 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 738 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 740 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 742 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 744 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 754 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 758 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 760 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 762 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (726) */
/* 764 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 766 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0x6 ),	/* Offset= 6 (778) */
/* 774 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 776 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 778 */	
			0x11, 0x0,	/* FC_RP */
/* 780 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (744) */
/* 782 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 784 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 794 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 796 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 798 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 800 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 810 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 814 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 816 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 818 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (782) */
/* 820 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 822 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0x6 ),	/* Offset= 6 (834) */
/* 830 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 832 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 834 */	
			0x11, 0x0,	/* FC_RP */
/* 836 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (800) */
/* 838 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 840 */	NdrFcShort( 0x4 ),	/* 4 */
/* 842 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 848 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 850 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 852 */	NdrFcShort( 0x4 ),	/* 4 */
/* 854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 856 */	NdrFcShort( 0x1 ),	/* 1 */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	0x12, 0x0,	/* FC_UP */
/* 864 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1266) */
/* 866 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 868 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 870 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x6 ),	/* Offset= 6 (882) */
/* 878 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 880 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 882 */	
			0x11, 0x0,	/* FC_RP */
/* 884 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (838) */
/* 886 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 888 */	NdrFcLong( 0x2f ),	/* 47 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 898 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 900 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 902 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 904 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 906 */	NdrFcShort( 0x1 ),	/* 1 */
/* 908 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 910 */	NdrFcShort( 0x4 ),	/* 4 */
/* 912 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 914 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 916 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 918 */	NdrFcShort( 0x10 ),	/* 16 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0xa ),	/* Offset= 10 (932) */
/* 924 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 926 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 928 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (886) */
/* 930 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 932 */	
			0x12, 0x0,	/* FC_UP */
/* 934 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (904) */
/* 936 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 938 */	NdrFcShort( 0x4 ),	/* 4 */
/* 940 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 944 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 946 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 948 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 950 */	NdrFcShort( 0x4 ),	/* 4 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x1 ),	/* 1 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	0x12, 0x0,	/* FC_UP */
/* 962 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (916) */
/* 964 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 966 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 968 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x6 ),	/* Offset= 6 (980) */
/* 976 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 978 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 980 */	
			0x11, 0x0,	/* FC_RP */
/* 982 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (936) */
/* 984 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 986 */	NdrFcShort( 0x8 ),	/* 8 */
/* 988 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 990 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 992 */	NdrFcShort( 0x10 ),	/* 16 */
/* 994 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 996 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 998 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (984) */
			0x5b,		/* FC_END */
/* 1002 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1004 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0xa ),	/* Offset= 10 (1018) */
/* 1010 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1012 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1014 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (990) */
/* 1016 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1018 */	
			0x11, 0x0,	/* FC_RP */
/* 1020 */	NdrFcShort( 0xfeec ),	/* Offset= -276 (744) */
/* 1022 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1024 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1026 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1032 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1034 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1038 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1040 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1042 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1044 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1046 */	0x12, 0x0,	/* FC_UP */
/* 1048 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1022) */
/* 1050 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1052 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1054 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1056 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1058 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1064 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1066 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1068 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1070 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1072 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1074 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1076 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1078 */	0x12, 0x0,	/* FC_UP */
/* 1080 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1054) */
/* 1082 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1084 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1086 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1088 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1090 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1096 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1098 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1102 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1104 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1106 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1108 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1110 */	0x12, 0x0,	/* FC_UP */
/* 1112 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1086) */
/* 1114 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1116 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1118 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1122 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1128 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1130 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1134 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1136 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1138 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1140 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1142 */	0x12, 0x0,	/* FC_UP */
/* 1144 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1118) */
/* 1146 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1148 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1150 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1154 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1156 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1158 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1162 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1164 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1166 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1168 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1170 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1150) */
/* 1172 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1174 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1176 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1178 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1158) */
/* 1180 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1180) */
/* 1182 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1184 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1186 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1188 */	NdrFcShort( 0xfdba ),	/* Offset= -582 (606) */
/* 1190 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1192 */	
			0x12, 0x0,	/* FC_UP */
/* 1194 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (916) */
/* 1196 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1198 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1200 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1202 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1204 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1206 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1208 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1210 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1212 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1214 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1216 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1218 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1220 */	
			0x12, 0x0,	/* FC_UP */
/* 1222 */	NdrFcShort( 0xfd78 ),	/* Offset= -648 (574) */
/* 1224 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1226 */	NdrFcShort( 0xfba6 ),	/* Offset= -1114 (112) */
/* 1228 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1230 */	NdrFcShort( 0xfe08 ),	/* Offset= -504 (726) */
/* 1232 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1234 */	NdrFcShort( 0xfe3c ),	/* Offset= -452 (782) */
/* 1236 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1238 */	NdrFcShort( 0xfd80 ),	/* Offset= -640 (598) */
/* 1240 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1242 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1244) */
/* 1244 */	
			0x12, 0x0,	/* FC_UP */
/* 1246 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1266) */
/* 1248 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1250 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1252 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1254 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1256 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1258 */	
			0x12, 0x0,	/* FC_UP */
/* 1260 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1248) */
/* 1262 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1264 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1266 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1268 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1272 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1272) */
/* 1274 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1276 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1278 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1280 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1282 */	NdrFcShort( 0xfc12 ),	/* Offset= -1006 (276) */
/* 1284 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1286 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1288 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1290 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0xfc02 ),	/* Offset= -1022 (272) */
/* 1296 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1298 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1304) */
/* 1300 */	
			0x13, 0x0,	/* FC_OP */
/* 1302 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1266) */
/* 1304 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1306 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1308 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1300) */
/* 1314 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1316 */	NdrFcLong( 0x270b4f98 ),	/* 655052696 */
/* 1320 */	NdrFcShort( 0xb17c ),	/* -20100 */
/* 1322 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 1324 */	0x9a,		/* 154 */
			0xd1,		/* 209 */
/* 1326 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 1328 */	0x0,		/* 0 */
			0xb6,		/* 182 */
/* 1330 */	0xfe,		/* 254 */
			0x26,		/* 38 */
/* 1332 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1334 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1314) */
/* 1336 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1338 */	NdrFcShort( 0xfb86 ),	/* Offset= -1146 (192) */
/* 1340 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1342 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1344) */
/* 1344 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1346 */	NdrFcLong( 0x36c7b797 ),	/* 919058327 */
/* 1350 */	NdrFcShort( 0x6bde ),	/* 27614 */
/* 1352 */	NdrFcShort( 0x46d0 ),	/* 18128 */
/* 1354 */	0x88,		/* 136 */
			0x70,		/* 112 */
/* 1356 */	0x70,		/* 112 */
			0x18,		/* 24 */
/* 1358 */	0x90,		/* 144 */
			0x0,		/* 0 */
/* 1360 */	0xed,		/* 237 */
			0xf9,		/* 249 */
/* 1362 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1364 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1366) */
/* 1366 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1368 */	NdrFcLong( 0x270b4f9a ),	/* 655052698 */
/* 1372 */	NdrFcShort( 0xb17c ),	/* -20100 */
/* 1374 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 1376 */	0x9a,		/* 154 */
			0xd1,		/* 209 */
/* 1378 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 1380 */	0x0,		/* 0 */
			0xb6,		/* 182 */
/* 1382 */	0xfe,		/* 254 */
			0x26,		/* 38 */
/* 1384 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1386 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1388) */
/* 1388 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1390 */	NdrFcLong( 0x83ba324b ),	/* -2084949429 */
/* 1394 */	NdrFcShort( 0xb758 ),	/* -18600 */
/* 1396 */	NdrFcShort( 0x11d3 ),	/* 4563 */
/* 1398 */	0xab,		/* 171 */
			0xae,		/* 174 */
/* 1400 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1402 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1404 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1406 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1408 */	NdrFcShort( 0xfd8e ),	/* Offset= -626 (782) */
/* 1410 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1412 */	NdrFcShort( 0xfd52 ),	/* Offset= -686 (726) */
/* 1414 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1416 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Standard interface: __MIDL_itf_Extension_Classes_Component_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMgaDataSource, ver. 0.0,
   GUID={0x9FF8F4E0,0xE0C9,0x11d3,{0xB3,0x76,0x00,0x50,0x04,0xD3,0x85,0x90}} */

#pragma code_seg(".orpc")
static const unsigned short IMgaDataSource_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    108
    };

static const MIDL_STUBLESS_PROXY_INFO IMgaDataSource_ProxyInfo =
    {
    &Object_StubDesc,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IMgaDataSource_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMgaDataSource_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IMgaDataSource_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IMgaDataSourceProxyVtbl = 
{
    &IMgaDataSource_ProxyInfo,
    &IID_IMgaDataSource,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMgaDataSource::get_Data */ ,
    (void *) (INT_PTR) -1 /* IMgaDataSource::get_Folders */ ,
    (void *) (INT_PTR) -1 /* IMgaDataSource::get_RegistryData */ ,
    (void *) (INT_PTR) -1 /* IMgaDataSource::get_Project */
};


static const PRPC_STUB_FUNCTION IMgaDataSource_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMgaDataSourceStubVtbl =
{
    &IID_IMgaDataSource,
    &IMgaDataSource_ServerInfo,
    11,
    &IMgaDataSource_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_Extension_Classes_Component_0000_0001, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IGMEOLEApp, ver. 0.0,
   GUID={0x81191A44,0xB898,0x4143,{0xBF,0x8B,0xCA,0x75,0x01,0xFE,0xC1,0x9A}} */

#pragma code_seg(".orpc")
static const unsigned short IGMEOLEApp_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    144,
    180,
    216,
    252,
    288,
    324,
    360,
    396,
    432,
    468,
    504,
    540,
    582,
    618,
    648,
    678,
    714,
    744,
    780,
    810,
    846,
    882,
    912,
    942,
    972,
    1002,
    1038,
    1068,
    1098,
    1128,
    1158,
    1188,
    1218,
    1248,
    1278,
    1320,
    1362,
    1392,
    1428,
    1464,
    1500,
    1536,
    1572,
    1614,
    1656,
    1692,
    1728,
    1764,
    1794
    };

static const MIDL_STUBLESS_PROXY_INFO IGMEOLEApp_ProxyInfo =
    {
    &Object_StubDesc,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEApp_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IGMEOLEApp_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEApp_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(56) _IGMEOLEAppProxyVtbl = 
{
    &IGMEOLEApp_ProxyInfo,
    &IID_IGMEOLEApp,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::put_Visible */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_Visible */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_Version */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_VersionMajor */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_VersionMinor */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_VersionPatchLevel */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_Models */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_MgaProject */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_Panels */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::put_ConsoleContents */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_ConsoleContents */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::CreateProject */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::OpenProject */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::CreateProjectDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::OpenProjectDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::CloseProject */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::SaveProject */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::SaveProjectAs */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::SaveProjectAsDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ExportProject */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ImportProject */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ConstraintsDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::CheckAllConstraints */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::RegisterParagimsDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::RegisterComponentsDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::RunComponent */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::RunComponentDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::SettingsDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::Undo */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::Redo */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ClearUndoQueue */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ProjectPropertiesDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ShowHelpContents */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ShowAbout */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ShowFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ConsoleMessage */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ConsoleClear */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ConsoleNavigateTo */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::ChangeEditmode */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::GridShow */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::AttributepanelPage */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::get_OleIt */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::DisableComp */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::DisableCompForKinds */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::SetCompFiltering */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::GetCompFiltering */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::SetWorkingDirectory */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::Exit */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEApp::RefreshLib */
};


static const PRPC_STUB_FUNCTION IGMEOLEApp_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IGMEOLEAppStubVtbl =
{
    &IID_IGMEOLEApp,
    &IGMEOLEApp_ServerInfo,
    56,
    &IGMEOLEApp_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IGMEOLEIt, ver. 0.0,
   GUID={0xF2181278,0x749F,0x459d,{0x87,0x00,0x92,0xF0,0x88,0xB8,0x0D,0x72}} */

#pragma code_seg(".orpc")
static const unsigned short IGMEOLEIt_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1842,
    1878,
    1914,
    1950,
    1980,
    2010,
    2046,
    2076,
    2112,
    2142,
    2172,
    2220,
    2250,
    618,
    2286,
    2322,
    2358,
    744,
    2400,
    2442,
    2484,
    2526,
    2574,
    2628,
    2682,
    2730,
    2778,
    2820,
    2862,
    2904,
    2946,
    2988,
    3030,
    3084,
    3132,
    3198,
    3264,
    3324,
    3378,
    3426,
    3468,
    3504,
    3540,
    3582,
    3618,
    3654,
    3690,
    3738,
    3786,
    3834,
    3882,
    3930,
    3978,
    4026,
    4074,
    4104,
    4134,
    4164,
    4200,
    4242,
    4272,
    4308,
    4344,
    4380,
    4416,
    4452,
    4488,
    4518,
    4548,
    4578,
    4608,
    4662
    };

static const MIDL_STUBLESS_PROXY_INFO IGMEOLEIt_ProxyInfo =
    {
    &Object_StubDesc,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEIt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IGMEOLEIt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEIt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(79) _IGMEOLEItProxyVtbl = 
{
    &IGMEOLEIt_ProxyInfo,
    &IID_IGMEOLEIt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::get_Valid */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::get_Aspects */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::get_MgaModel */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Print */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::PrintDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::DumpWindowsMetaFile */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::CheckConstraints */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::RunComponent */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::RunComponentDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Close */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::GrayOutFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::GrayOutHide */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ShowSetMembers */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::HideSetMembers */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Zoom */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ZoomTo */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Scroll */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::DumpModelGeometryXML */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ShowFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ShowFCOPtr */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Child */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Create */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::CreateInChild */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::CreateInChildFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Duplicate */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::DuplicateFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Rename */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::SetName */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Include */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Exclude */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::IncludeFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ExcludeFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Connect */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Disconnect */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ConnectThruPort */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ConnectThruPortFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::DisconnectThruPort */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ConnectFCOs */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::DisconnectFCOs */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Refer */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ClearRef */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::FollowRef */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ReferFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::ClearRefFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::FollowRefFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::NullFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::SetAttribute */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::GetAttribute */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::SetAttributeFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::GetAttributeFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::SubType */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Instantiate */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::SubTypeFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::InstantiateFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::BeginTransaction */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::CommitTransaction */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::AbortTransaction */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::IsInTransaction */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::PutInTerritory */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Help */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::SetSelected */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::GetSelected */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::SetSelectedFCOs */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::GetSelectedFCOs */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::GetCurrentAspect */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::SetCurrentAspect */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::NextAspect */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::PrevAspect */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Next */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Prev */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::Position */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEIt::PositionFCO */
};


static const PRPC_STUB_FUNCTION IGMEOLEIt_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IGMEOLEItStubVtbl =
{
    &IID_IGMEOLEIt,
    &IGMEOLEIt_ServerInfo,
    79,
    &IGMEOLEIt_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IGMEOLEModel, ver. 0.0,
   GUID={0x399A16A0,0xD209,0x4d00,{0x9B,0xDF,0x85,0x8D,0x87,0xEC,0x46,0x41}} */

#pragma code_seg(".orpc")
static const unsigned short IGMEOLEModel_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    144,
    180,
    4716,
    4752,
    288,
    4788,
    2046,
    4818,
    2112,
    4854,
    4890,
    2220,
    4920,
    618,
    4968,
    5004,
    5034,
    5070,
    5106,
    5148,
    5184,
    5220
    };

static const MIDL_STUBLESS_PROXY_INFO IGMEOLEModel_ProxyInfo =
    {
    &Object_StubDesc,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEModel_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IGMEOLEModel_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEModel_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(29) _IGMEOLEModelProxyVtbl = 
{
    &IGMEOLEModel_ProxyInfo,
    &IID_IGMEOLEModel,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::put_Active */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::get_Active */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::get_Aspects */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::get_MgaModel */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::get_Valid */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::Print */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::PrintDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::DumpWindowsMetaFile */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::CheckConstraints */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::RunComponent */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::RunComponentDialog */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::Close */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::GrayOutFCO */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::GrayOutHide */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::ShowSetMembers */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::HideSetMembers */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::Zoom */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::ZoomTo */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::Scroll */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::DumpModelGeometryXML */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::GetCurrentAspect */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEModel::SetCurrentAspect */
};


static const PRPC_STUB_FUNCTION IGMEOLEModel_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IGMEOLEModelStubVtbl =
{
    &IID_IGMEOLEModel,
    &IGMEOLEModel_ServerInfo,
    29,
    &IGMEOLEModel_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IGMEOLEAspect, ver. 0.0,
   GUID={0xEDEEB1F8,0xBC44,0x40d2,{0xBE,0x91,0x83,0xE8,0xCC,0xD5,0x98,0x45}} */

#pragma code_seg(".orpc")
static const unsigned short IGMEOLEAspect_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5256,
    5292,
    5328,
    252
    };

static const MIDL_STUBLESS_PROXY_INFO IGMEOLEAspect_ProxyInfo =
    {
    &Object_StubDesc,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEAspect_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IGMEOLEAspect_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEAspect_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IGMEOLEAspectProxyVtbl = 
{
    &IGMEOLEAspect_ProxyInfo,
    &IID_IGMEOLEAspect,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEAspect::get_MgaAspect */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEAspect::put_Active */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEAspect::get_Active */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEAspect::get_Valid */
};


static const PRPC_STUB_FUNCTION IGMEOLEAspect_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IGMEOLEAspectStubVtbl =
{
    &IID_IGMEOLEAspect,
    &IGMEOLEAspect_ServerInfo,
    11,
    &IGMEOLEAspect_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IGMEOLEPanel, ver. 0.0,
   GUID={0xC047FAEB,0x7AE7,0x40fb,{0x8C,0x5C,0x90,0xC7,0x3D,0xAD,0x4B,0xC6}} */

#pragma code_seg(".orpc")
static const unsigned short IGMEOLEPanel_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5364,
    5292,
    5328,
    5400
    };

static const MIDL_STUBLESS_PROXY_INFO IGMEOLEPanel_ProxyInfo =
    {
    &Object_StubDesc,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEPanel_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IGMEOLEPanel_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEPanel_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IGMEOLEPanelProxyVtbl = 
{
    &IGMEOLEPanel_ProxyInfo,
    &IID_IGMEOLEPanel,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEPanel::get_Name */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEPanel::put_Visible */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEPanel::get_Visible */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEPanel::get_Interface */
};


static const PRPC_STUB_FUNCTION IGMEOLEPanel_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IGMEOLEPanelStubVtbl =
{
    &IID_IGMEOLEPanel,
    &IGMEOLEPanel_ServerInfo,
    11,
    &IGMEOLEPanel_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IGMEOLEColl, ver. 0.0,
   GUID={0x36C7B797,0x6BDE,0x46d0,{0x88,0x70,0x70,0x18,0x90,0x00,0xED,0xF9}} */

#pragma code_seg(".orpc")
static const unsigned short IGMEOLEColl_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5436,
    5472,
    5508,
    5550,
    1980,
    5586,
    5628,
    5670
    };

static const MIDL_STUBLESS_PROXY_INFO IGMEOLEColl_ProxyInfo =
    {
    &Object_StubDesc,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEColl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IGMEOLEColl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IGMEOLEColl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IGMEOLECollProxyVtbl = 
{
    &IGMEOLEColl_ProxyInfo,
    &IID_IGMEOLEColl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEColl::get_Count */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEColl::Add */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEColl::Find */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEColl::Remove */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEColl::RemoveAll */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEColl::get_Item */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEColl::put_Item */ ,
    (void *) (INT_PTR) -1 /* IGMEOLEColl::get__NewEnum */
};


static const PRPC_STUB_FUNCTION IGMEOLEColl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IGMEOLECollStubVtbl =
{
    &IID_IGMEOLEColl,
    &IGMEOLEColl_ServerInfo,
    15,
    &IGMEOLEColl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_Extension_Classes_Component_0000_0007, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IMgaVersionInfo, ver. 0.0,
   GUID={0x9A228010,0x020B,0x11d2,{0xBB,0xB3,0x00,0x40,0x05,0x1F,0x71,0x17}} */

#pragma code_seg(".orpc")
static const unsigned short IMgaVersionInfo_FormatStringOffsetTable[] =
    {
    5706
    };

static const MIDL_STUBLESS_PROXY_INFO IMgaVersionInfo_ProxyInfo =
    {
    &Object_StubDesc,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IMgaVersionInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMgaVersionInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Extension_Classes_Component__MIDL_ProcFormatString.Format,
    &IMgaVersionInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IMgaVersionInfoProxyVtbl = 
{
    &IMgaVersionInfo_ProxyInfo,
    &IID_IMgaVersionInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IMgaVersionInfo::get_version */
};

const CInterfaceStubVtbl _IMgaVersionInfoStubVtbl =
{
    &IID_IMgaVersionInfo,
    &IMgaVersionInfo_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    Extension_Classes_Component__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _Extension_Classes_Component_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IMgaVersionInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IGMEOLEAppProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IGMEOLEItProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IGMEOLECollProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IGMEOLEModelProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMgaDataSourceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IGMEOLEPanelProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IGMEOLEAspectProxyVtbl,
    0
};

const CInterfaceStubVtbl * _Extension_Classes_Component_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IMgaVersionInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IGMEOLEAppStubVtbl,
    ( CInterfaceStubVtbl *) &_IGMEOLEItStubVtbl,
    ( CInterfaceStubVtbl *) &_IGMEOLECollStubVtbl,
    ( CInterfaceStubVtbl *) &_IGMEOLEModelStubVtbl,
    ( CInterfaceStubVtbl *) &_IMgaDataSourceStubVtbl,
    ( CInterfaceStubVtbl *) &_IGMEOLEPanelStubVtbl,
    ( CInterfaceStubVtbl *) &_IGMEOLEAspectStubVtbl,
    0
};

PCInterfaceName const _Extension_Classes_Component_InterfaceNamesList[] = 
{
    "IMgaVersionInfo",
    "IGMEOLEApp",
    "IGMEOLEIt",
    "IGMEOLEColl",
    "IGMEOLEModel",
    "IMgaDataSource",
    "IGMEOLEPanel",
    "IGMEOLEAspect",
    0
};

const IID *  _Extension_Classes_Component_BaseIIDList[] = 
{
    0,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _Extension_Classes_Component_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _Extension_Classes_Component, pIID, n)

int __stdcall _Extension_Classes_Component_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _Extension_Classes_Component, 8, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _Extension_Classes_Component, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _Extension_Classes_Component, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _Extension_Classes_Component, 8, *pIndex )
    
}

const ExtendedProxyFileInfo Extension_Classes_Component_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _Extension_Classes_Component_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _Extension_Classes_Component_StubVtblList,
    (const PCInterfaceName * ) & _Extension_Classes_Component_InterfaceNamesList,
    (const IID ** ) & _Extension_Classes_Component_BaseIIDList,
    & _Extension_Classes_Component_IID_Lookup, 
    8,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

