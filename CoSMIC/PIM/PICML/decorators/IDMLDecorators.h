// IDMLDecorators.h : Declaration of the IDML Decorator classes

#ifndef __IDMLDECORATOR_H_
#define __IDMLDECORATOR_H_

#pragma warning( disable : 4290 )

#include "Resource.h"       // main symbols
#include "DecoratorLib.h"
#include "MaskedBitmap.h"
#include <vector>
#include <string>

using namespace std;

static const char* PICML_AGGREGATE_NAME =         "Aggregate";
static const char* PICML_ALIAS_NAME =             "Alias";
static const char* PICML_ATTRIBUTE_NAME =         "Attribute";
static const char* PICML_ATTRIBUTEMEMBER_NAME =   "AttributeMember";
static const char* PICML_BOOLEAN_NAME =           "Boolean";
static const char* PICML_BOXED_NAME =             "Boxed";
static const char* PICML_BYTE_NAME =              "Byte";
static const char* PICML_COLLECTION_NAME =        "Collection";
static const char* PICML_COMPONENT_NAME =         "Component";
static const char* PICML_COMPONENTREF_NAME =      "ComponentRef";
static const char* PICML_COMPONENTFACTORY_NAME =  "ComponentFactory";
static const char* PICML_ENUM_NAME =              "Enum";
static const char* PICML_EVENT_NAME =             "Event";
static const char* PICML_GENERICOBJECT_NAME =     "GenericObject";
static const char* PICML_GENERICVALUE_NAME =      "GenericValue";
static const char* PICML_GENERICVALUEOBJECT_NAME = "GenericValueObject";
static const char* PICML_INEVENTPORT_NAME =       "InEventPort";
static const char* PICML_INHERITS_NAME =          "Inherits";
static const char* PICML_LONGINTEGER_NAME =       "LongInteger";
static const char* PICML_MEMBER_NAME =            "Member";
static const char* PICML_OBJECT_NAME =            "Object";
static const char* PICML_OUTEVENTPORT_NAME =      "OutEventPort";
static const char* PICML_PROVIDEDREQUESTPORT_NAME = "ProvidedRequestPort";
static const char* PICML_READONLYATTRIBUTE_NAME = "ReadonlyAttribute";
static const char* PICML_FLOATNUMBER_NAME =        "FloatNumber";
static const char* PICML_DOUBLENUMBER_NAME =        "DoubleNumber";
static const char* PICML_REQUIREDREQUESTPORT_NAME = "RequiredRequestPort";
static const char* PICML_SHORTINTEGER_NAME =      "ShortInteger";
static const char* PICML_STRING_NAME =            "String";
static const char* PICML_SWITCHEDAGGREGATE_NAME = "SwitchedAggregate";
static const char* PICML_TYPEENCODING_NAME =      "TypeEncoding";
static const char* PICML_TYPEKIND_NAME =          "TypeKind";
static const char* PICML_VALUEOBJECT_NAME =       "ValueObject";
static const char* PICML_COMPONENTASSEMBLY_NAME = "ComponentAssembly";
static const char* PICML_DATATYPE_NAME =          "DataType";
static const char* PICML_ATTRIBUTEMAPPING_NAME =  "AttributeMapping";
static const char* PICML_COMPONENTASMREF_NAME =   "ComponentAssemblyReference";
static const char* PICML_SUPPORTS_NAME =          "Supports";
static const char* PREF_TYPESHOWN = "isTypeShown";

class PortDecorator;

static bool NamespaceEquals (const CString& target, const char* name)
{
  CString nsname ("PICML::");
  nsname += name;
  return (target == name || target == nsname);
}

static bool NamespaceEquals (const CComBSTR& target, const char* name)
{
    CComBSTR nsname ("PICML::");
    nsname += name;
    return (target == name || target == nsname);
}

//########################################################
//
//  CLASS : DecoratorBase
//
//########################################################

class DecoratorBase
{
public:
  virtual ~DecoratorBase();

  virtual void      initialize( IMgaFCO *obj, CComPtr<IMgaMetaFCO>& metaFco );
  virtual void      destroy();
  CComPtr<IMgaFCO>  getFCO() const;
  objtype_enum      getType() const;
  CRect             getBoxLocation( bool bWithBorder = false ) const;
  long              getBorderWidth( bool bActive = true ) const;
  virtual CSize     getPreferredSize() const;
  virtual void      setLocation( const CRect& cRect );
  virtual CRect     getLocation() const;
  virtual void      setActive( bool bActive );
  virtual void      draw( CDC* pDC ) = 0;
  virtual void      LoadBitmap() = 0;

  virtual vector<PortDecorator*>  getPorts() const;
  virtual PortDecorator*          getPort( CComPtr<IMgaFCO> ) const;

protected:
  DecoratorBase();

protected:
  CRect                 m_rect;
  CComPtr<IMgaFCO>  m_mgaFco;
  CComPtr<IMgaMetaFCO>  m_metaFco;
  CString    m_name;
  CString               m_metaName;
  objtype_enum    m_eType;
  CMaskedBitmap         m_bitmap;
  long      m_lBorderWidth;
  bool      m_bActive;

  COLORREF          m_color;
  COLORREF          m_nameColor;
};

//########################################################
//
//  CLASS : MemberDecorator
//
//########################################################

class MemberDecorator : public DecoratorBase
{
public:
  MemberDecorator();

  virtual void draw( CDC* pDC );
  virtual void LoadBitmap();
};

//########################################################
//
//  CLASS : InheritsDecorator
//
//########################################################

class InheritsDecorator : public DecoratorBase
{
public:
  InheritsDecorator();

  virtual void draw( CDC* pDC );
  virtual void LoadBitmap();
};

//########################################################
//
//  CLASS : PortDecorator
//
//########################################################

class PortDecorator  : public DecoratorBase
{
private :
  CPoint m_ptInner;
  bool m_right;

public :
  PortDecorator( CComPtr<IMgaFCO> mgaFco, const CPoint& ptInner );

  virtual void   initialize();
  virtual CSize   getPreferredSize() const;
  CPoint getInnerPosition() const;
  virtual void    draw( CDC* pDC );
  virtual void   LoadBitmap();
  void   setToRight();
};

//########################################################
//
//  CLASS : ComponentDecorator
//
//########################################################

class ComponentDecorator : public DecoratorBase
{
private:
  CComPtr<IMgaMetaPart>      m_metaPart;
  vector<PortDecorator*>    m_vecLeftPorts;
  vector<PortDecorator*>    m_vecRightPorts;
  CComPtr<IMgaMetaAspect>   m_spAspect;
  long          m_iMaxPortTextLength;
  CString        m_strTypeName;
  bool                      m_bTypeNameEnabled;
  int                       m_iTypeInfo;
public:
  ComponentDecorator( CComPtr<IMgaMetaPart>  metaPart );
  virtual ~ComponentDecorator();

  virtual void  initialize( IMgaFCO *obj, CComPtr<IMgaMetaFCO>& metaFco );
  virtual CSize getPreferredSize() const;
  virtual void  setLocation( const CRect& cRect );
  virtual void  setActive( bool bActive );
  virtual void  draw( CDC* pDC );
  virtual void  LoadBitmap();

  virtual vector<PortDecorator*>  getPorts() const;
  virtual PortDecorator*      getPort( CComPtr<IMgaFCO> ) const;

private:
  void loadPorts();
  void orderPorts( vector<PortDecorator*>& );
  void findPorts( vector<PortDecorator*>&, CComPtr<IMgaFCOs>& );
  void checkInherits( vector<PortDecorator*>&, CComPtr<IMgaFCO>& );
};

#endif //__DECORATOR_H_
