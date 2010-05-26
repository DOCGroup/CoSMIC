// $Id$

#include "stdafx.h"
#include "IDMLDecorators.h"
#include "CommonSmart.h"
#include "Resource.h"
#include "DecoratorUtil.h"
#include "MaskedBitmap.h"
#include <algorithm>

#include "game/Reference.h"
#include "game/MetaModel.h"
#include "game/Model.h"

CDecoratorUtil d_util;

#define NAME_MARGINY 20

#define ICON_SIZEX 64
#define ICON_SIZEY 64

static const int MAX_PORT_LENGTH = 5;
static const int WIDTH_MODELSIDE = 100;
static const int GAP_LABEL = 2;
static const int GAP_PORT = 3;
static const int GAP_XMODELPORT = 4;
static const int GAP_YMODELPORT = 8;
static const int GAP_XBORDER = 5;
static const int GAP_YBORDER = 2;
static const int GAP_PORTLABEL = 20;
static const int WIDTH_MODEL = 113;
static const int HEIGHT_MODEL = 71;

//########################################################
//
//  CLASS : DecoratorBase
//
//########################################################

//
// DecoratorBase
//
DecoratorBase::DecoratorBase (void)
  : m_mgaFco( 0 ),
    m_metaFco( 0 ),
    m_lBorderWidth( 0 ),
    m_bActive( true ),
    m_color( GME_BLACK_COLOR ),
    m_nameColor( GME_BLACK_COLOR )
{
}

//
// DecoratorBase
//
DecoratorBase::~DecoratorBase (void)
{
}

//
// initialize
//
void DecoratorBase::initialize (const GME::FCO & fco, const GME::Meta::FCO & meta)
{
  // obj == NULL, if we are in the PartBrowser
  m_mgaFco = fco;    
  m_metaFco = meta;

  // Get the display name for the type.
  this->metaname_ = this->m_metaFco.display_name ();

  if (this->metaname_.empty ())
    this->metaname_ = this->m_metaFco.name ();

  // Load the correct bitmap for the decorator.
  this->LoadBitmap ();

  if (this->m_mgaFco)
  {
    this->m_name = this->m_mgaFco.name ().c_str ();
    this->m_eType = this->m_mgaFco.type ();
  }
  else
  {
    this->m_name = this->metaname_.c_str ();
    this->m_eType = this->m_metaFco.type ();
  }
}

//
// destroy
//
void DecoratorBase::destroy (void)
{

}

const GME::FCO & DecoratorBase::getFCO (void) const
{
  return m_mgaFco;
}

objtype_enum
DecoratorBase::getType() const
{
  return m_eType;
}

CRect
DecoratorBase::getBoxLocation( bool bWithBorder ) const
{
  if ( bWithBorder )
    return m_rect;
  CRect cRect = m_rect;
  cRect.DeflateRect( getBorderWidth( false ), getBorderWidth( false ) );
  return cRect;
}

long
DecoratorBase::getBorderWidth( bool bActive ) const
{
  long lBorderWidth = m_lBorderWidth;
  return lBorderWidth;
}

CSize
DecoratorBase::getPreferredSize() const
{
  return CSize ( ICON_SIZEX, ICON_SIZEY );
}

void
DecoratorBase::setLocation (const CRect& cRect )
{
  m_rect = cRect;
}

CRect
DecoratorBase::getLocation() const
{
  return m_rect;
}

void
DecoratorBase::setActive( bool bActive )
{
  m_bActive = bActive;
}

vector<PortDecorator *> DecoratorBase::getPorts() const
{
  return vector<PortDecorator*> ();
}

PortDecorator* DecoratorBase::getPort( CComPtr<IMgaFCO> ) const
{
  return NULL;
}

//########################################################
//
//  CLASS : MemberDecorator
//
//########################################################

//
// MemberDecorator
//
MemberDecorator::MemberDecorator (void)
{

}

//
// LoadBitmap
//
void MemberDecorator::LoadBitmap (void)
{
  if (NamespaceEquals (this->metaname_, PICML_MEMBER_NAME) || 
      NamespaceEquals (this->metaname_, PICML_ATTRIBUTEMEMBER_NAME) ||
      NamespaceEquals (this->metaname_, PICML_DATATYPE_NAME)) 
  {
    // This is a reference element. So, narrow it to a reference
    // and get its referred element.
    GME::Reference ref = GME::Reference::_narrow (this->m_mgaFco);
    GME::FCO referred = ref.refers_to ();

    if (referred.is_nil ())
      return;

    std::string metaname = referred.meta ().name ();

    if (NamespaceEquals (metaname, PICML_STRING_NAME) ) {
      m_bitmap.ReadFromResource (IDB_BITMAP_STRING);
    }
    else if ( NamespaceEquals (metaname, PICML_LONGINTEGER_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_LONG );
    }
    else if ( NamespaceEquals (metaname, PICML_BOOLEAN_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_BOOLEAN );
    }
    else if ( NamespaceEquals (metaname, PICML_FLOATNUMBER_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_FLOATNUMBER );
    }
    else if ( NamespaceEquals (metaname, PICML_DOUBLENUMBER_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_DOUBLENUMBER );
    }
    else if ( NamespaceEquals (metaname, PICML_COLLECTION_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_COLLECTIONREF );
    }
    else if ( NamespaceEquals (metaname, PICML_ENUM_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_ENUMREF );
    }
    else if ( NamespaceEquals (metaname, PICML_AGGREGATE_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_AGGREGATEREF );
    }
    else if ( NamespaceEquals (metaname, PICML_ALIAS_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_ALIASREF );
    }
    else if ( NamespaceEquals (metaname, PICML_SHORTINTEGER_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_SHORTINTEGER );
    }
    else if ( NamespaceEquals (metaname, PICML_OBJECT_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_OBJECTREF );
    }
    else if ( NamespaceEquals (metaname, PICML_VALUEOBJECT_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_VALUEREF );
    }
    else if ( NamespaceEquals (metaname, PICML_COMPONENT_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENTREF );
    }
    else if ( NamespaceEquals (metaname, PICML_EVENT_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_EVENTREF );
    }
    else if ( NamespaceEquals (metaname, PICML_COMPONENTFACTORY_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENTFACTORYREF );
    }
    else if ( NamespaceEquals (metaname, PICML_SWITCHEDAGGREGATE_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_SWITCHEDAGGREGATEREF );
    }
    else if ( NamespaceEquals (metaname, PICML_GENERICVALUE_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_GENERICVALUE );
    }
    else if ( NamespaceEquals (metaname, PICML_GENERICOBJECT_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_GENERICOBJECT );
    }
    else if ( NamespaceEquals (metaname, PICML_GENERICVALUEOBJECT_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_GENERICVALUEOBJECT );
    }
    else if ( NamespaceEquals (metaname, PICML_BYTE_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_BYTE );
    }
    else if ( NamespaceEquals (metaname, PICML_TYPEENCODING_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_TYPEENCODING );
    }
    else if ( NamespaceEquals (metaname, PICML_TYPEKIND_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_TYPEKIND );
    }
    else if ( NamespaceEquals (metaname, PICML_BOXED_NAME) ) {
      m_bitmap.ReadFromResource( IDB_BITMAP_BOXEDREF );
    }
  }
  else 
  {
    if (NamespaceEquals (this->metaname_, PICML_MEMBER_NAME) ||
        NamespaceEquals (this->metaname_, PICML_ATTRIBUTEMEMBER_NAME))
    {
      m_bitmap.ReadFromResource (IDB_BITMAP_MEMBER);
    }
    else
    {
      m_bitmap.ReadFromResource (IDB_BITMAP_DATATYPE);
    }
  }
}

//
// draw
//
void MemberDecorator::draw (CDC * pDC)
{
  if (!m_bitmap.IsValid ()) 
    return;

  this->m_bitmap.Draw (pDC, this->m_rect);

  // Skip drawing the name only for attribute members appearing
  // in the editor.
  if (this->m_mgaFco.is_nil () || 
      this->metaname_ != PICML_ATTRIBUTEMEMBER_NAME)
  {
    CPoint namePos (m_rect.left + ICON_SIZEX / 2,
                    m_rect.bottom + NAME_MARGINY );

    d_util.DrawText (pDC,
                     m_name,
                     namePos,
                     d_util.GetFont (GME_NAME_FONT),
                     m_nameColor,
                     TA_BOTTOM | TA_CENTER);
  }
}

//########################################################
//
//  CLASS : InheritsDecorator
//
//########################################################

InheritsDecorator::InheritsDecorator()
  : DecoratorBase()
{
}

void
InheritsDecorator::LoadBitmap()
{
  m_bitmap.ReadFromResource( IDB_BITMAP_INHERITS );
}

//
// draw
//
void InheritsDecorator::draw (CDC * pDC)
{
  if (!m_bitmap.IsValid ())
    return;

  m_bitmap.Draw( pDC, m_rect );

  if (!m_mgaFco) 
  {
    // Skip drawing the name in the editor.
    CPoint namePos( m_rect.left + ICON_SIZEX / 2,
                    m_rect.bottom + NAME_MARGINY );

    d_util.DrawText( pDC,
                     m_name,
                     namePos,
                     d_util.GetFont(GME_NAME_FONT),
                     m_nameColor,
                     TA_BOTTOM | TA_CENTER);
  }
}

//########################################################
//
//  CLASS : PortDecorator
//
//########################################################

PortDecorator::
PortDecorator (const GME::FCO & mgaFco, const CPoint& ptInner)
  : m_ptInner( ptInner ),
    m_right( false )
{
  this->m_mgaFco = mgaFco;
}

void
PortDecorator::initialize()
{
  // Load the bitmap.
  this->LoadBitmap ();

  // Get the name to display on the port.
  m_name = this->m_mgaFco.name ().c_str ();
  m_name = m_name.Left (MAX_PORT_LENGTH);
}

CSize
PortDecorator::getPreferredSize() const
{
  return CSize( GME_PORT_SIZE, GME_PORT_SIZE );
}

CPoint
PortDecorator::getInnerPosition() const
{
  return m_ptInner;
}

//
// draw
//
void PortDecorator::draw (CDC * pDC)
{
  CRect dst = this->getLocation ();
  m_bitmap.DrawTransparent (pDC,
                            dst,
                            GME_WHITE_COLOR,
                            !m_bActive,
                            GME_GRAYED_OUT_COLOR );

  CPoint namePos( m_right ? dst.left - GAP_LABEL : dst.right + GAP_LABEL,
                  dst.top - GAP_PORT );

  d_util.DrawText( pDC,
                   m_name,
                   namePos,
                   d_util.GetFont( GME_PORTNAME_FONT ),
                   m_bActive ? m_nameColor : GME_GRAYED_OUT_COLOR,
                   m_right ? TA_RIGHT : TA_LEFT );
}

//
// LoadBitmap
//
void PortDecorator::LoadBitmap (void)
{
  if (this->m_mgaFco.is_nil ())
    return;

  std::string metaname = this->m_mgaFco.meta ().name ();

  if ( NamespaceEquals (metaname, PICML_INEVENTPORT_NAME) ) {
    m_bitmap.ReadFromResource (m_right
                               ? IDB_BITMAP_INEVENT_RT
                               : IDB_BITMAP_INEVENT_LF );
  }
  else if ( NamespaceEquals (metaname, PICML_OUTEVENTPORT_NAME) ) {
    m_bitmap.ReadFromResource( m_right
                               ? IDB_BITMAP_OUTEVENT_RT
                               : IDB_BITMAP_OUTEVENT_LF );
  }
  else if ( NamespaceEquals (metaname, PICML_REQUIREDREQUESTPORT_NAME) ) {
    m_bitmap.ReadFromResource( m_right
                               ? IDB_BITMAP_RECEPTACLE_RT
                               : IDB_BITMAP_RECEPTACLE_LF );
  }
  else if ( NamespaceEquals (metaname, PICML_PROVIDEDREQUESTPORT_NAME) ) {
    m_bitmap.ReadFromResource( IDB_BITMAP_FACET );
  }
  else if ( NamespaceEquals (metaname, PICML_READONLYATTRIBUTE_NAME) ) {
    m_bitmap.ReadFromResource( IDB_BITMAP_READONLYATTRIBUTE );
  }
  else if ( NamespaceEquals (metaname, PICML_ATTRIBUTE_NAME) ) {
    m_bitmap.ReadFromResource( IDB_BITMAP_ATTRIBUTE );
  }
  else if (NamespaceEquals (metaname, PICML_ATTRIBUTEMAPPING_NAME)) {
    m_bitmap.ReadFromResource (IDB_BITMAP_ATTRIBUTEMAPPING);
  }
  else if (NamespaceEquals (metaname, PICML_SUPPORTS_NAME)) {
    m_bitmap.ReadFromResource (IDB_BITMAP_OBJECT);
  }
}

void
PortDecorator::setToRight()
{
  m_right = true;
}

struct PortLess
{
  bool operator()( PortDecorator* pPortA, PortDecorator* pPortB )
  {
    return pPortA->getInnerPosition().y < pPortB->getInnerPosition().y;
  }
};

//########################################################
//
//  CLASS : ComponentDecorator
//
//########################################################

//
// ComponentDecorator
//
ComponentDecorator::ComponentDecorator( CComPtr<IMgaMetaPart>  metaPart )
  : DecoratorBase(),
    m_metaPart( metaPart ),
    m_iMaxPortTextLength( MAX_PORT_LENGTH ),
    m_bTypeNameEnabled( false ),
    m_iTypeInfo( 0 )
{
}

//
// ~ComponentDecorator
//
ComponentDecorator::~ComponentDecorator (void)
{
  unsigned int i;
  for ( i = 0 ; i < m_vecLeftPorts.size() ; i++ )
    delete m_vecLeftPorts[ i ];
  for ( i = 0 ; i < m_vecRightPorts.size() ; i++ )
    delete m_vecRightPorts[ i ];
}

//
// initialize
//
void ComponentDecorator::
initialize (const GME::FCO & fco, const GME::Meta::FCO & meta)
{
  DecoratorBase::initialize (fco, meta);

  if (this->m_mgaFco.is_nil ()) 
    return;

  CComPtr <IMgaMetaAspect>  spParentAspect;
  COMTHROW (m_metaPart->get_ParentAspect( &spParentAspect ) );

  GME::Meta::Model metamodel;

  if (NamespaceEquals (this->metaname_, PICML_COMPONENT_NAME)|| 
      NamespaceEquals (this->metaname_, PICML_COMPONENTASSEMBLY_NAME))
  {
    metamodel = GME::Meta::Model::_narrow (this->m_mgaFco.meta ());
  }
  else if (NamespaceEquals (metaname_, PICML_COMPONENTREF_NAME) ||
           NamespaceEquals (metaname_, PICML_COMPONENTASMREF_NAME))
  {
    GME::Reference ref = GME::Reference::_narrow (m_mgaFco);
    GME::FCO referred = ref.refers_to ();

    // We could be drawing an unassigned ComponentRef.
    if (referred.is_nil ())
      return;

    metamodel = GME::Meta::Model::_narrow (referred.meta ());
  }

  CComBSTR bstrAspect;
  COMTHROW (m_metaPart->get_KindAspect (&bstrAspect));
 
  if (bstrAspect.Length () == 0) 
  {
    bstrAspect.Empty ();
    COMTHROW (spParentAspect->get_Name (&bstrAspect ));
  }

  HRESULT hr = metamodel.impl ()->get_AspectByName (bstrAspect, &m_spAspect );

  if (hr == E_NOTFOUND) 
  {
    try 
    {
      // JEFF: There is at present only one aspect in PICML,
      // but this is still the easiest way
      m_spAspect = NULL;
      CComPtr<IMgaMetaAspects> spAspects;
      COMTHROW (metamodel.impl ()->get_Aspects (&spAspects ));

      ASSERT ( spAspects );

      long nAspects = 0;
      COMTHROW( spAspects->get_Count( &nAspects ) );
      if ( nAspects > 0 ) {
        COMTHROW( spAspects->get_Item( 1, &m_spAspect ) );
      }
    }
    catch ( hresult_exception& ) {
    }
  }

  this->loadPorts ();

  std::string value = this->m_mgaFco.registry_value (PREF_TYPESHOWN);
  this->m_bTypeNameEnabled = (value == "t" || value == "true" || value == "1" );

  if (this->m_mgaFco.is_instance ()) 
  {
    this->m_iTypeInfo = 3;

    if (this->m_bTypeNameEnabled) 
    {
      GME::FCO type = m_mgaFco.derived_from ();
      this->m_strTypeName = type.name ().c_str ();
    }
  }
  else 
  {
    GME::FCO derived_from = m_mgaFco.derived_from ();

    if (derived_from)
    {
      m_iTypeInfo = 2;
    }
    else 
    {
      CComPtr<IMgaFCOs> spFCOs;
      COMTHROW (m_mgaFco.impl ()->get_DerivedObjects( &spFCOs ) );
      long lCount = 0;
      COMTHROW( spFCOs->get_Count( &lCount ) );
      m_iTypeInfo = ( lCount == 0 ) ? 0 : 1;
    }
  }
}

CSize
ComponentDecorator::getPreferredSize() const
{
  long lWidth =
    ( 8 * m_iMaxPortTextLength
      + GAP_LABEL
      + GME_PORT_SIZE
      + GAP_XMODELPORT
      + GAP_XBORDER )
    * 2
    + GAP_PORTLABEL;

  long lHeight =
    ( GAP_YMODELPORT + GAP_YBORDER ) * 2
    + max( m_vecLeftPorts.size(), m_vecRightPorts.size() )
    * ( GME_PORT_SIZE + GAP_PORT )
    - GAP_PORT;

  return CSize( max( m_bitmap.Width(), lWidth ),
                max( m_bitmap.Height(), lHeight ) );
}

//
// setLocation
//
void ComponentDecorator::setLocation (const CRect& cRect)
{ 
  m_rect = cRect;
  long lY = ( m_rect.Height()
              - m_vecLeftPorts.size() * ( GME_PORT_SIZE + GAP_PORT )
              + GAP_PORT )
            / 2;

  unsigned int i;

  for ( i = 0 ; i < m_vecLeftPorts.size() ; i++ ) {
    m_vecLeftPorts[ i ]->setLocation( CRect( GAP_XMODELPORT
                                             + GAP_XBORDER,
                                             lY,
                                             GAP_XMODELPORT
                                             + GME_PORT_SIZE
                                             + GAP_XBORDER,
                                             lY + GME_PORT_SIZE ) );
    lY += GME_PORT_SIZE + GAP_PORT;
  }

  lY = ( m_rect.Height()
         - m_vecRightPorts.size() * ( GME_PORT_SIZE + GAP_PORT )
         + GAP_PORT )
       / 2;

  for ( i = 0 ; i < m_vecRightPorts.size() ; i++ ) {
    m_vecRightPorts[ i ]->setLocation( CRect( cRect.Width()
                                              - GAP_XMODELPORT
                                              - GME_PORT_SIZE
                                              - GAP_XBORDER,
                                              lY,
                                              cRect.Width()
                                              - GAP_XMODELPORT
                                              - GAP_XBORDER,
                                              lY + GME_PORT_SIZE ) );
    lY += GME_PORT_SIZE + GAP_PORT;
  }
}

void ComponentDecorator::setActive ( bool bActive)
{
  m_bActive = bActive;
  for ( unsigned int i = 0 ; i < m_vecLeftPorts.size() ; i++ )
    m_vecLeftPorts[ i ]->setActive( bActive );
  for ( unsigned int i = 0 ; i < m_vecRightPorts.size() ; i++ )
    m_vecRightPorts[ i ]->setActive( bActive );
}

//
// LoadBitmap
//
void ComponentDecorator::LoadBitmap (void)
{
  if ( NamespaceEquals (metaname_, PICML_COMPONENT_NAME))
    m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENT );
  else if (NamespaceEquals (metaname_, PICML_COMPONENTASSEMBLY_NAME))
    m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENTASSEMBLY);
  else if (NamespaceEquals (metaname_, PICML_COMPONENTREF_NAME))
    m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENTREF);
  else if (NamespaceEquals (metaname_, PICML_COMPONENTASMREF_NAME))
    m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENTASSEMBLYREF);
}

//
// draw
//
void ComponentDecorator::draw (CDC * pDC)
{
  // Draw the component icon.
  CRect dst = this->getLocation ();

  m_bitmap.DrawTransparent( pDC,
                            dst,
                            GME_WHITE_COLOR,
                            !m_bActive,
                            GME_GRAYED_OUT_COLOR );

  // Draw the component name.
  CPoint namePos( dst.left + dst.Width () / 2, dst.bottom + NAME_MARGINY );
  d_util.DrawText( pDC,
                   m_name,
                   namePos,
                   d_util.GetFont( GME_NAME_FONT ),
                   m_bActive ? m_nameColor : GME_GRAYED_OUT_COLOR,
                   TA_BOTTOM | TA_CENTER );

  // If we are an instance, draw the type info.
  if ( m_bTypeNameEnabled && m_iTypeInfo == 3 ) {
    CPoint typeNamePos( dst.left + dst.Width () / 2,
                        dst.bottom + 2 * NAME_MARGINY );
    CString typeInfoStr = "[  " + m_strTypeName + "  ]";
    d_util.DrawText( pDC,
                     typeInfoStr,
                     typeNamePos,
                     d_util.GetFont( GME_PORTNAME_FONT ),
                     m_bActive ? m_nameColor : GME_GRAYED_OUT_COLOR,
                     TA_BOTTOM | TA_CENTER );
  }

  // Draw the component ports, if any.
  CSize cExtentD = pDC->GetViewportExt();
  CSize cExtentL = pDC->GetWindowExt();
  CRect cRect = getLocation();
  CPoint ptOrigin =
    pDC->OffsetViewportOrg( (long) ( cRect.left
                                     * ( (double) cExtentD.cx
                                         / cExtentL.cx ) ),
                            (long) ( cRect.top
                                     * ( (double) cExtentD.cy
                                         / cExtentL.cy ) ) );
  unsigned int i;

  for ( i = 0 ; i < m_vecLeftPorts.size() ; i++ ) {
    m_vecLeftPorts[ i ]->draw( pDC );
  }

  for ( i = 0 ; i < m_vecRightPorts.size() ; i++ ) {
    m_vecRightPorts[ i ]->draw( pDC );
  }
  pDC->SetViewportOrg( ptOrigin );
}

//
// getPorts
//
vector<PortDecorator*> ComponentDecorator::getPorts() const
{
  vector<PortDecorator*> vecPorts( m_vecLeftPorts );
  for ( unsigned int i = 0 ; i < m_vecRightPorts.size() ; i++ )
    vecPorts.push_back( m_vecRightPorts[ i ] );
  return vecPorts;
}

PortDecorator*
ComponentDecorator::getPort( CComPtr<IMgaFCO> spFCO ) const
{
  unsigned int i;

  for ( i = 0 ; i < m_vecLeftPorts.size() ; i++ )
    if ( m_vecLeftPorts[ i ]->getFCO().impl () == spFCO )
      return m_vecLeftPorts[ i ];
  for ( i = 0 ; i < m_vecRightPorts.size() ; i++ )
    if ( m_vecRightPorts[ i ]->getFCO().impl () == spFCO )
      return m_vecRightPorts[ i ];
  return NULL;
}

void
ComponentDecorator::loadPorts()
{
  // If we are in the Part Browser, we don't want to load ports.
  if (!m_spAspect) 
    return;

  vector <PortDecorator*>  vecPorts;
  GME::Model model;

  if (NamespaceEquals (this->metaname_, PICML_COMPONENT_NAME) ||
      NamespaceEquals (this->metaname_, PICML_COMPONENTASSEMBLY_NAME))
  {
    model = GME::Model::_narrow (this->m_mgaFco);
  }
  else if (NamespaceEquals (this->metaname_, PICML_COMPONENTREF_NAME) ||
           NamespaceEquals (this->metaname_, PICML_COMPONENTASMREF_NAME))
  {
    GME::Reference ref = GME::Reference::_narrow (this->m_mgaFco);
    GME::FCO referred = ref.refers_to ();

    if (referred.is_nil ())
      return;

    model = GME::Model::_narrow (referred);
  }

  std::vector <GME::FCO> fcos;
  model.children (fcos);

  // Iterate over the child FCOs list and add any ports to
  // the vector.
  this->findPorts (vecPorts, fcos);
  this->orderPorts (vecPorts);
}

void
ComponentDecorator::orderPorts( vector<PortDecorator*>& vecPorts )
{
  long lMin = 100000000;
  long lMax = 0;
  unsigned int i;

  for ( i = 0 ; i < vecPorts.size() ; i++ ) {
    lMin = min( lMin, vecPorts[ i ]->getInnerPosition().x );
    lMax = max( lMax, vecPorts[ i ]->getInnerPosition().x );
  }

  for ( i = 0 ; i < vecPorts.size() ; i++ ) {
    if ( vecPorts[ i ]->getInnerPosition().x <= WIDTH_MODELSIDE
         || vecPorts[ i ]->getInnerPosition().x < lMax / 2 ) {
      m_vecLeftPorts.push_back( vecPorts[ i ] );
    }
    else {
      m_vecRightPorts.push_back( vecPorts[ i ] );
      vecPorts[ i ]->setToRight();
    }

    vecPorts[ i ]->initialize();
  }

  sort( m_vecLeftPorts.begin(), m_vecLeftPorts.end(), PortLess() );
  sort( m_vecRightPorts.begin(), m_vecRightPorts.end(), PortLess() );
}

//
// findPorts
//
void ComponentDecorator::
findPorts (vector<PortDecorator*>& vecPorts,
           const std::vector <GME::FCO> & fcos)
{
  std::vector <GME::FCO>::const_iterator 
    iter = fcos.begin (), iter_end = fcos.end ();

  for (; iter != iter_end; ++ iter)
  {
    CComPtr<IMgaPart> spPart;
    COMTHROW (iter->impl ()->get_Part (m_spAspect, &spPart));

    if (spPart) 
    {
      CComPtr <IMgaMetaPart> spMetaPart;
      COMTHROW (spPart->get_Meta(&spMetaPart ) );

      VARIANT_BOOL vbLinked;
      COMTHROW (spMetaPart->get_IsLinked (&vbLinked));

      if ( vbLinked ) 
      {
        long lX = 0;
        long lY = 0;
        COMTHROW (spPart->GetGmeAttrs ( 0, &lX, &lY ) );
        vecPorts.push_back (new PortDecorator (*iter, CPoint (lX, lY ) ) );
      }
      else
        COMTHROW ( iter->impl ()->Close() );
    }
    else
      COMTHROW (iter->impl ()->Close());
  }
}
