// IDMLDecorators.h : Declaration of the IDML Decorator classes

#ifndef __IDMLDECORATOR_H_
#define __IDMLDECORATOR_H_

#pragma warning( disable : 4290 )

#include "Resource.h"       // main symbols
#include "DecoratorLib.h"
#include "MaskedBitmap.h"
#include <vector>

using namespace std;

#define IDML_AGGREGATE_NAME           "Aggregate"
#define IDML_ALIAS_NAME               "Alias"
#define IDML_ATTRIBUTEMEMBER_NAME     "AttributeMember"
#define IDML_BOOLEAN_NAME             "Boolean"
#define IDML_BOXED_NAME               "Boxed"
#define IDML_BYTE_NAME                "Byte"
#define IDML_COLLECTION_NAME          "Collection"
#define IDML_COMPONENT_NAME           "Component"
#define IDML_COMPONENTFACTORY_NAME    "ComponentFactory"
#define IDML_ENUM_NAME                "Enum"
#define IDML_EVENT_NAME               "Event"
#define IDML_GENERICOBJECT_NAME       "GenericObject"
#define IDML_GENERICVALUE_NAME        "GenericValue"
#define IDML_GENERICVALUEOBJECT_NAME  "GenericValueObject"
#define IDML_INEVENTPORT_NAME         "InEventPort"
#define IDML_LONGINTEGER_NAME         "LongInteger"
#define IDML_MEMBER_NAME              "Member"
#define IDML_OBJECT_NAME              "Object"
#define IDML_OUTEVENTPORT_NAME        "OutEventPort"
#define IDML_PROVIDEDREQUESTPORT_NAME "ProvidedRequestPort"
#define IDML_REALNUMBER_NAME          "RealNumber"
#define IDML_REQUIREDREQUESTPORT_NAME "RequiredRequestPort"
#define IDML_SHORTINTEGER_NAME        "ShortInteger"
#define IDML_STRING_NAME              "String"
#define IDML_SWITCHEDAGGREGATE_NAME   "SwitchedAggregate"
#define IDML_TYPEENCODING_NAME        "TypeEncoding"
#define IDML_TYPEKIND_NAME            "TypeKind"
#define IDML_VALUEOBJECT_NAME         "ValueObject"

static const char* PREF_TYPESHOWN				= "isTypeShown";

//########################################################
//
//	CLASS : DecoratorBase
//
//########################################################

class DecoratorBase
{
public:
  virtual ~DecoratorBase();

  virtual void      initialize( IMgaFCO *obj, CComPtr<IMgaMetaFCO>& metaFco );
  virtual void      destroy();
	CComPtr<IMgaFCO>	getFCO() const;
	objtype_enum			getType() const;
	CRect			        getBoxLocation( bool bWithBorder = false ) const;
	long					    getBorderWidth( bool bActive = true ) const;
	virtual CSize			getPreferredSize() const;
  virtual void      setLocation( const CRect& cRect );
  virtual CRect     getLocation() const;
  virtual void 			draw( CDC* pDC ) = 0;
  virtual void      LoadBitmap() = 0;

protected:
  DecoratorBase();

protected:
  CRect                 m_rect;
	CComPtr<IMgaFCO>	    m_mgaFco;
	CComPtr<IMgaMetaFCO>	m_metaFco;
	CString		            m_name;
  CString               m_metaName;
	objtype_enum					m_eType;
	CMaskedBitmap         m_bitmap;
	long							    m_lBorderWidth;

	COLORREF	            m_color;
	COLORREF	            m_nameColor;
};

//########################################################
//
//	CLASS : MemberDecorator
//
//########################################################

class MemberDecorator : public DecoratorBase
{
public:
  MemberDecorator();

  virtual void initialize( IMgaFCO *obj, CComPtr<IMgaMetaFCO>& metaFco );
  virtual void draw( CDC* pDC );
  virtual void LoadBitmap();
};

//########################################################
//
//	CLASS : PortDecorator
//
//########################################################

class PortDecorator	: public DecoratorBase
{
private :
	CPoint m_ptInner;
  bool m_right;

public :
	PortDecorator( CComPtr<IMgaFCO> mgaFco, const CPoint& ptInner );

	virtual void   initialize();
	virtual CSize	 getPreferredSize() const;
		      CPoint getInnerPosition() const;
  virtual void 	 draw( CDC* pDC );
  virtual void   LoadBitmap();
          void   setToRight();
};

//########################################################
//
//	CLASS : ComponentDecorator
//
//########################################################

class ComponentDecorator : public DecoratorBase
{
private:
	CComPtr<IMgaMetaPart>	    m_metaPart;
	vector<PortDecorator*>		m_vecLeftPorts;
	vector<PortDecorator*>		m_vecRightPorts;
	CComPtr<IMgaMetaAspect>	  m_spAspect;
	long							        m_iMaxPortTextLength;
	CString		                m_strTypeName;
  bool							        m_bTypeNameEnabled;
  int                       m_iTypeInfo;
public:
  ComponentDecorator( CComPtr<IMgaMetaPart>	metaPart );
  virtual ~ComponentDecorator();

  virtual void  initialize( IMgaFCO *obj, CComPtr<IMgaMetaFCO>& metaFco );
  virtual CSize getPreferredSize() const;
  virtual void  setLocation( const CRect& cRect );
  virtual void  draw( CDC* pDC );
  virtual void  LoadBitmap();

	vector<PortDecorator*>  getPorts() const;
	PortDecorator*			    getPort( CComPtr<IMgaFCO> ) const;

private:
	void loadPorts();
	void orderPorts( vector<PortDecorator*>& vecPorts );
};

#endif //__DECORATOR_H_
