/* HelloStub.h
   Generated by gSOAP 2.7.8c from Hello.h
   Copyright (C) 2000-2006, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef HelloStub_H
#define HelloStub_H
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


#ifndef SOAP_TYPE_Hello__Hello_x002eCOLOR_USCORESELECTION
#define SOAP_TYPE_Hello__Hello_x002eCOLOR_USCORESELECTION (24)
/* Hello:Hello.COLOR_SELECTION */
enum Hello__Hello_x002eCOLOR_USCORESELECTION {Hello__Hello_x002eCOLOR_USCORESELECTION__empty = 0, Hello__Hello_x002eCOLOR_USCORESELECTION__white = 1, Hello__Hello_x002eCOLOR_USCORESELECTION__red = 2, Hello__Hello_x002eCOLOR_USCORESELECTION__yellow = 3};
#endif

#ifndef SOAP_TYPE_CORBA__CORBA_x002ecompletion_USCOREstatus
#define SOAP_TYPE_CORBA__CORBA_x002ecompletion_USCOREstatus (26)
/* CORBA:CORBA.completion_status */
enum CORBA__CORBA_x002ecompletion_USCOREstatus {CORBA__CORBA_x002ecompletion_USCOREstatus__COMPLETED_USCOREYES = 0, CORBA__CORBA_x002ecompletion_USCOREstatus__COMPLETED_USCORENO = 1, CORBA__CORBA_x002ecompletion_USCOREstatus__COMPLETED_USCOREMAYBE = 2};
#endif

/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/




#ifndef SOAP_TYPE_xsd__anyType
#define SOAP_TYPE_xsd__anyType (6)
/* Primitive xsd:anyType schema type: */
class SOAP_CMAC xsd__anyType
{
public:
	char *__item;
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 6; } /* = unique id SOAP_TYPE_xsd__anyType */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__anyType() : __item(NULL), soap(NULL) { }
	virtual ~xsd__anyType() { }
};
#endif

#ifndef SOAP_TYPE_xsd__ID_
#define SOAP_TYPE_xsd__ID_ (10)
/* Primitive xsd:ID schema type: */
class SOAP_CMAC xsd__ID_ : public xsd__anyType
{
public:
	char *__item;
public:
	virtual int soap_type() const { return 10; } /* = unique id SOAP_TYPE_xsd__ID_ */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__ID_() : __item(NULL) { }
	virtual ~xsd__ID_() { }
};
#endif

#ifndef SOAP_TYPE_xsd__anyURI_
#define SOAP_TYPE_xsd__anyURI_ (12)
/* Primitive xsd:anyURI schema type: */
class SOAP_CMAC xsd__anyURI_ : public xsd__anyType
{
public:
	char *__item;
public:
	virtual int soap_type() const { return 12; } /* = unique id SOAP_TYPE_xsd__anyURI_ */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__anyURI_() : __item(NULL) { }
	virtual ~xsd__anyURI_() { }
};
#endif

#ifndef SOAP_TYPE_xsd__int
#define SOAP_TYPE_xsd__int (13)
/* Primitive xsd:int schema type: */
class SOAP_CMAC xsd__int : public xsd__anyType
{
public:
	int __item;
public:
	virtual int soap_type() const { return 13; } /* = unique id SOAP_TYPE_xsd__int */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__int()  { }
	virtual ~xsd__int() { }
};
#endif

#ifndef SOAP_TYPE_xsd__string
#define SOAP_TYPE_xsd__string (14)
/* Primitive xsd:string schema type: */
class SOAP_CMAC xsd__string : public xsd__anyType
{
public:
	char *__item;
public:
	virtual int soap_type() const { return 14; } /* = unique id SOAP_TYPE_xsd__string */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__string() : __item(NULL) { }
	virtual ~xsd__string() { }
};
#endif

#ifndef SOAP_TYPE_xsd__unsignedInt
#define SOAP_TYPE_xsd__unsignedInt (15)
/* Primitive xsd:unsignedInt schema type: */
class SOAP_CMAC xsd__unsignedInt : public xsd__anyType
{
public:
	unsigned int __item;
public:
	virtual int soap_type() const { return 15; } /* = unique id SOAP_TYPE_xsd__unsignedInt */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         xsd__unsignedInt()  { }
	virtual ~xsd__unsignedInt() { }
};
#endif

#ifndef SOAP_TYPE_Hello__Hello_x002eCOLOR_USCORESELECTION_
#define SOAP_TYPE_Hello__Hello_x002eCOLOR_USCORESELECTION_ (25)
/* Primitive Hello:Hello.COLOR_SELECTION schema type: */
class SOAP_CMAC Hello__Hello_x002eCOLOR_USCORESELECTION_ : public xsd__anyType
{
public:
	enum Hello__Hello_x002eCOLOR_USCORESELECTION __item;
public:
	virtual int soap_type() const { return 25; } /* = unique id SOAP_TYPE_Hello__Hello_x002eCOLOR_USCORESELECTION_ */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         Hello__Hello_x002eCOLOR_USCORESELECTION_()  { }
	virtual ~Hello__Hello_x002eCOLOR_USCORESELECTION_() { }
};
#endif

#ifndef SOAP_TYPE_CORBA__CORBA_x002ecompletion_USCOREstatus_
#define SOAP_TYPE_CORBA__CORBA_x002ecompletion_USCOREstatus_ (27)
/* Primitive CORBA:CORBA.completion_status schema type: */
class SOAP_CMAC CORBA__CORBA_x002ecompletion_USCOREstatus_ : public xsd__anyType
{
public:
	enum CORBA__CORBA_x002ecompletion_USCOREstatus __item;
public:
	virtual int soap_type() const { return 27; } /* = unique id SOAP_TYPE_CORBA__CORBA_x002ecompletion_USCOREstatus_ */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         CORBA__CORBA_x002ecompletion_USCOREstatus_()  { }
	virtual ~CORBA__CORBA_x002ecompletion_USCOREstatus_() { }
};
#endif

#ifndef SOAP_TYPE_Hello__Hello_x002eTimeOut
#define SOAP_TYPE_Hello__Hello_x002eTimeOut (17)
/* Hello:Hello.TimeOut */
class SOAP_CMAC Hello__Hello_x002eTimeOut : public xsd__anyType
{
public:
	char *data;	/* required element of type xsd:string */
	char *id;	/* optional attribute */
public:
	virtual int soap_type() const { return 17; } /* = unique id SOAP_TYPE_Hello__Hello_x002eTimeOut */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         Hello__Hello_x002eTimeOut() : data(NULL), id(NULL) { }
	virtual ~Hello__Hello_x002eTimeOut() { }
};
#endif

#ifndef SOAP_TYPE_CORBA__ObjectReference
#define SOAP_TYPE_CORBA__ObjectReference (18)
/* CORBA:ObjectReference */
class SOAP_CMAC CORBA__ObjectReference : public xsd__anyType
{
public:
	int __sizeurl;	/* sequence of elements <url> */
	char **url;	/* required element of type xsd:anyURI */
public:
	virtual int soap_type() const { return 18; } /* = unique id SOAP_TYPE_CORBA__ObjectReference */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         CORBA__ObjectReference() : url(NULL) { }
	virtual ~CORBA__ObjectReference() { }
};
#endif

#ifndef SOAP_TYPE_CORBA__CORBA_x002eTypeCode
#define SOAP_TYPE_CORBA__CORBA_x002eTypeCode (19)
/* CORBA:CORBA.TypeCode */
class SOAP_CMAC CORBA__CORBA_x002eTypeCode : public xsd__anyType
{
public:
	char *definition;	/* required element of type xsd:anyURI */
	char *typename_;	/* required element of type xsd:string */
public:
	virtual int soap_type() const { return 19; } /* = unique id SOAP_TYPE_CORBA__CORBA_x002eTypeCode */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         CORBA__CORBA_x002eTypeCode() : definition(NULL), typename_(NULL) { }
	virtual ~CORBA__CORBA_x002eTypeCode() { }
};
#endif

#ifndef SOAP_TYPE_CORBA__CORBA_x002eAny
#define SOAP_TYPE_CORBA__CORBA_x002eAny (20)
/* CORBA:CORBA.Any */
class SOAP_CMAC CORBA__CORBA_x002eAny : public xsd__anyType
{
public:
	CORBA__CORBA_x002eTypeCode *type;	/* required element of type CORBA:CORBA.TypeCode */
	xsd__anyType *value;	/* required element of type xsd:anyType */
public:
	virtual int soap_type() const { return 20; } /* = unique id SOAP_TYPE_CORBA__CORBA_x002eAny */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         CORBA__CORBA_x002eAny() : type(NULL), value(NULL) { }
	virtual ~CORBA__CORBA_x002eAny() { }
};
#endif

#ifndef SOAP_TYPE_CORBA__CORBA_x002eSystemException
#define SOAP_TYPE_CORBA__CORBA_x002eSystemException (21)
/* CORBA:CORBA.SystemException */
class SOAP_CMAC CORBA__CORBA_x002eSystemException : public xsd__anyType
{
public:
	unsigned int minor;	/* required element of type xsd:unsignedInt */
	enum CORBA__CORBA_x002ecompletion_USCOREstatus completion_USCOREstatus;	/* required element of type CORBA:CORBA.completion_status */
public:
	virtual int soap_type() const { return 21; } /* = unique id SOAP_TYPE_CORBA__CORBA_x002eSystemException */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         CORBA__CORBA_x002eSystemException()  { }
	virtual ~CORBA__CORBA_x002eSystemException() { }
};
#endif

#ifndef SOAP_TYPE__CORBA__SourceIDL
#define SOAP_TYPE__CORBA__SourceIDL (22)
/* CORBA:SourceIDL */
class SOAP_CMAC _CORBA__SourceIDL
{
public:
	char *source;	/* required element of type xsd:string */
	char *version;	/* required element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 22; } /* = unique id SOAP_TYPE__CORBA__SourceIDL */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _CORBA__SourceIDL() : source(NULL), version(NULL), soap(NULL) { }
	virtual ~_CORBA__SourceIDL() { }
};
#endif

#ifndef SOAP_TYPE__CORBA__SourceRepositoryID
#define SOAP_TYPE__CORBA__SourceRepositoryID (23)
/* CORBA:SourceRepositoryID */
class SOAP_CMAC _CORBA__SourceRepositoryID
{
public:
	char *repositoryID;	/* required element of type xsd:string */
	char *version;	/* required element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 23; } /* = unique id SOAP_TYPE__CORBA__SourceRepositoryID */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _CORBA__SourceRepositoryID() : repositoryID(NULL), version(NULL), soap(NULL) { }
	virtual ~_CORBA__SourceRepositoryID() { }
};
#endif

#ifndef SOAP_TYPE__CORBA__CORBA_x002eSystemExceptionMessage
#define SOAP_TYPE__CORBA__CORBA_x002eSystemExceptionMessage (31)
/* CORBA:CORBA.SystemExceptionMessage */
class SOAP_CMAC _CORBA__CORBA_x002eSystemExceptionMessage
{
public:
	CORBA__CORBA_x002eSystemException *_USCOREreturn;	/* optional element of type CORBA:CORBA.SystemException */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 31; } /* = unique id SOAP_TYPE__CORBA__CORBA_x002eSystemExceptionMessage */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _CORBA__CORBA_x002eSystemExceptionMessage() : _USCOREreturn(NULL), soap(NULL) { }
	virtual ~_CORBA__CORBA_x002eSystemExceptionMessage() { }
};
#endif

#ifndef SOAP_TYPE_Hello__get_USCOREmessageResponse
#define SOAP_TYPE_Hello__get_USCOREmessageResponse (35)
/* Hello:get_messageResponse */
struct Hello__get_USCOREmessageResponse
{
public:
	char *_USCOREreturn;	/* RPC return element */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_Hello__get_USCOREmessage
#define SOAP_TYPE_Hello__get_USCOREmessage (36)
/* Hello:get_message */
struct Hello__get_USCOREmessage
{
};
#endif

#ifndef SOAP_TYPE_Hello__startResponse
#define SOAP_TYPE_Hello__startResponse (37)
/* Hello:startResponse */
struct Hello__startResponse
{
};
#endif

#ifndef SOAP_TYPE_Hello__start
#define SOAP_TYPE_Hello__start (40)
/* Hello:start */
struct Hello__start
{
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREset_USCOREcolorResponse
#define SOAP_TYPE_Hello___USCOREset_USCOREcolorResponse (41)
/* Hello:_set_colorResponse */
struct Hello___USCOREset_USCOREcolorResponse
{
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREset_USCOREcolor
#define SOAP_TYPE_Hello___USCOREset_USCOREcolor (44)
/* Hello:_set_color */
struct Hello___USCOREset_USCOREcolor
{
public:
	enum Hello__Hello_x002eCOLOR_USCORESELECTION value;	/* required element of type Hello:Hello.COLOR_SELECTION */
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREget_USCOREcolorResponse
#define SOAP_TYPE_Hello___USCOREget_USCOREcolorResponse (45)
/* Hello:_get_colorResponse */
struct Hello___USCOREget_USCOREcolorResponse
{
public:
	enum Hello__Hello_x002eCOLOR_USCORESELECTION _USCOREreturn;	/* RPC return element */	/* required element of type Hello:Hello.COLOR_SELECTION */
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREget_USCOREcolor
#define SOAP_TYPE_Hello___USCOREget_USCOREcolor (48)
/* Hello:_get_color */
struct Hello___USCOREget_USCOREcolor
{
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREget_USCOREhertzResponse
#define SOAP_TYPE_Hello___USCOREget_USCOREhertzResponse (51)
/* Hello:_get_hertzResponse */
struct Hello___USCOREget_USCOREhertzResponse
{
public:
	int _USCOREreturn;	/* RPC return element */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREget_USCOREhertz
#define SOAP_TYPE_Hello___USCOREget_USCOREhertz (52)
/* Hello:_get_hertz */
struct Hello___USCOREget_USCOREhertz
{
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREset_USCORElocal_USCOREmessageResponse
#define SOAP_TYPE_Hello___USCOREset_USCORElocal_USCOREmessageResponse (53)
/* Hello:_set_local_messageResponse */
struct Hello___USCOREset_USCORElocal_USCOREmessageResponse
{
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREset_USCORElocal_USCOREmessage
#define SOAP_TYPE_Hello___USCOREset_USCORElocal_USCOREmessage (56)
/* Hello:_set_local_message */
struct Hello___USCOREset_USCORElocal_USCOREmessage
{
public:
	char *value;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREget_USCORElocal_USCOREmessageResponse
#define SOAP_TYPE_Hello___USCOREget_USCORElocal_USCOREmessageResponse (58)
/* Hello:_get_local_messageResponse */
struct Hello___USCOREget_USCORElocal_USCOREmessageResponse
{
public:
	char *_USCOREreturn;	/* RPC return element */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_Hello___USCOREget_USCORElocal_USCOREmessage
#define SOAP_TYPE_Hello___USCOREget_USCORElocal_USCOREmessage (59)
/* Hello:_get_local_message */
struct Hello___USCOREget_USCORElocal_USCOREmessage
{
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (62)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	void *dummy;	/* transient */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (63)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (65)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
	char *__any;
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (66)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (67)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (4)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE_xsd__ID
#define SOAP_TYPE_xsd__ID (9)
typedef char *xsd__ID;
#endif

#ifndef SOAP_TYPE_xsd__anyURI
#define SOAP_TYPE_xsd__anyURI (11)
typedef char *xsd__anyURI;
#endif


/******************************************************************************\
 *                                                                            *
 * Typedef Synonyms                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of HelloStub.h */
