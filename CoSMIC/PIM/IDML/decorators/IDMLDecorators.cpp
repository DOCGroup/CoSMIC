// Decorator.cpp : Implementation of CDecorator
#include "stdafx.h"
#include "IDMLDecorators.h"
#include "CommonSmart.h"
#include "Resource.h"
#include "DecoratorUtil.h"
#include "MaskedBitmap.h"
#include <algorithm>

CDecoratorUtil d_util;

#define NAME_MARGINY 20

#define ICON_SIZEX 64
#define ICON_SIZEY 64

static const int MAX_PORT_LENGTH = 3;
static const int WIDTH_MODELSIDE = 100;
static const int GAP_LABEL = 2;
static const int GAP_PORT = 3;
static const int GAP_XMODELPORT = 4;
static const int GAP_YMODELPORT = 8;
static const int GAP_XOVALICONFUDGE = 5;
static const int GAP_YOVALICONFUDGE = 2;
static const int GAP_PORTLABEL = 20;
static const int WIDTH_MODEL = 113;
static const int HEIGHT_MODEL = 71;

//########################################################
//
//	CLASS : DecoratorBase
//
//########################################################

DecoratorBase::DecoratorBase() 
  : m_mgaFco( 0 ),
    m_metaFco( 0 ),
    m_lBorderWidth( 0 ),
    m_color( GME_BLACK_COLOR ),
    m_nameColor( GME_BLACK_COLOR )
{
}

DecoratorBase::~DecoratorBase()
{
}

void 
DecoratorBase::initialize( IMgaFCO *obj, CComPtr<IMgaMetaFCO>& metaFco )
{
	m_mgaFco = obj;		// obj == NULL, if we are in the PartBrowser
  m_metaFco = metaFco;
	
  CComBSTR bstr;
  COMTHROW( m_metaFco->get_DisplayedName( &bstr ) );
	if ( bstr.Length() == 0 ) {
		bstr.Empty();
		COMTHROW( m_metaFco->get_Name( &bstr ) );
	}
	m_metaName = bstr;

  LoadBitmap();
	
	if ( m_mgaFco ) {
		CComBSTR bstr;
		COMTHROW( m_mgaFco->get_Name( &bstr ) );
		m_name = bstr;
		COMTHROW( m_mgaFco->get_ObjType( &m_eType ) );
	}
	else {
		CComBSTR bstr;
		COMTHROW( m_metaFco->get_DisplayedName( &bstr ) );
		if ( bstr.Length() == 0 ) {
			bstr.Empty();
			COMTHROW( m_metaFco->get_Name( &bstr ) );
		  COMTHROW( m_metaFco->get_ObjType( &m_eType ) );
		}
		m_name = bstr;
	}
}

void
DecoratorBase::destroy()
{
  m_metaFco = NULL;
  m_mgaFco = NULL;
}

CComPtr<IMgaFCO>
DecoratorBase::getFCO() const
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
DecoratorBase::setLocation( const CRect& cRect )
{
  m_rect = cRect;
}

CRect
DecoratorBase::getLocation() const
{
  return m_rect;
}

//########################################################
//
//	CLASS : MemberDecorator
//
//########################################################

MemberDecorator::MemberDecorator()
  : DecoratorBase()
{
}

void 
MemberDecorator::initialize( IMgaFCO *obj, CComPtr<IMgaMetaFCO>& metaFco )
{
  DecoratorBase::initialize( obj, metaFco );
}

void
MemberDecorator::LoadBitmap()
{
  if (m_metaName == IDML_MEMBER_NAME 
      || m_metaName == IDML_ATTRIBUTEMEMBER_NAME) {
	  CComPtr<IMgaFCO> mgaFco = m_mgaFco;
    if ( mgaFco ) {
		  CComPtr<IMgaReference> ref;
		  COMTHROW( mgaFco.QueryInterface( &ref ) );
		  mgaFco = NULL;
		  COMTHROW( ref->get_Referred( &mgaFco ) );
    }
		if (mgaFco) {
      CComPtr<IMgaMetaFCO> metaFco;
      mgaFco->get_Meta( &metaFco );
		  CComBSTR bstr;
		  COMTHROW( metaFco->get_Name( &bstr ) );
      if ( bstr == IDML_STRING_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_STRING );
      }
      else if ( bstr == IDML_LONGINTEGER_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_LONG );       
      }
      else if ( bstr == IDML_BOOLEAN_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_BOOLEAN );       
      }
      else if ( bstr == IDML_REALNUMBER_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_REALNUMBER );       
      }
      else if ( bstr == IDML_COLLECTION_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_COLLECTIONREF );       
      }
      else if ( bstr == IDML_ENUM_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_ENUMREF );       
      }
      else if ( bstr == IDML_AGGREGATE_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_AGGREGATEREF );       
      }
      else if ( bstr == IDML_ALIAS_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_ALIASREF );       
      }
      else if ( bstr == IDML_SHORTINTEGER_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_SHORTINTEGER );       
      }
      else if ( bstr == IDML_OBJECT_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_OBJECTREF );       
      }
      else if ( bstr == IDML_VALUEOBJECT_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_VALUEREF );       
      }
      else if ( bstr == IDML_COMPONENT_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENTREF );       
      }
      else if ( bstr == IDML_EVENT_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_EVENTREF );       
      }
      else if ( bstr == IDML_COMPONENTFACTORY_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENTFACTORYREF );       
      }
      else if ( bstr == IDML_SWITCHEDAGGREGATE_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_SWITCHEDAGGREGATEREF );       
      }
      else if ( bstr == IDML_GENERICVALUE_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_GENERICVALUE );       
      }
      else if ( bstr == IDML_GENERICOBJECT_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_GENERICOBJECT );       
      }
      else if ( bstr == IDML_GENERICVALUEOBJECT_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_GENERICVALUEOBJECT );       
      }
      else if ( bstr == IDML_BYTE_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_BYTE );       
      }
      else if ( bstr == IDML_TYPEENCODING_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_TYPEENCODING );       
      }
      else if ( bstr == IDML_TYPEKIND_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_TYPEKIND );       
      }
      else if ( bstr == IDML_BOXED_NAME ) {
        m_bitmap.ReadFromResource( IDB_BITMAP_BOXEDREF );       
      }
		  mgaFco = NULL;
    }
    else {
      m_bitmap.ReadFromResource( IDB_BITMAP_MEMBER );
    }
  }
}

void
MemberDecorator::draw( CDC* pDC )
{
  if (m_bitmap.IsValid ()) {
    m_bitmap.Draw( pDC, m_rect );

    // Skip drawing the name only for attribute members appearing
    // in the editor.
    if (!m_mgaFco || m_metaName != IDML_ATTRIBUTEMEMBER_NAME) {
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
}

//########################################################
//
//	CLASS : PortDecorator
//
//########################################################

PortDecorator::PortDecorator( CComPtr<IMgaFCO> mgaFco,
                              const CPoint& ptInner )
	: DecoratorBase(),
    m_ptInner( ptInner ),
    m_right( false )
{
  m_mgaFco = mgaFco;
}

void 
PortDecorator::initialize()
{
  LoadBitmap();
  CComBSTR bstr;
  m_mgaFco->get_Name( &bstr );
  m_name = bstr;
  m_name = m_name.Left( MAX_PORT_LENGTH );
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


void
PortDecorator::draw( CDC* pDC )
{
  CRect dst = getLocation();
  m_bitmap.Draw( pDC, dst );

	CPoint namePos( m_right ? dst.left - GAP_LABEL - ( 8 * MAX_PORT_LENGTH )
                          : dst.right + GAP_LABEL,
                  dst.top - GAP_PORT );
	d_util.DrawText( pDC, 
                   m_name,
                   namePos,
                   d_util.GetFont( GME_PORTNAME_FONT ),
                   m_nameColor,
                   TA_LEFT );
}

void
PortDecorator::LoadBitmap()
{
	CComPtr<IMgaFCO> mgaFco = m_mgaFco;
	if ( mgaFco ) {
    CComPtr<IMgaMetaFCO> metaFco;
    mgaFco->get_Meta( &metaFco );
		CComBSTR bstr;
		COMTHROW( metaFco->get_Name( &bstr ) );
    if ( bstr == IDML_INEVENTPORT_NAME ) {
      m_bitmap.ReadFromResource( m_right
                                 ? IDB_BITMAP_INEVENT_RT
                                 : IDB_BITMAP_INEVENT_LF );
    }
    else if ( bstr == IDML_OUTEVENTPORT_NAME ) {
      m_bitmap.ReadFromResource( m_right
                                 ? IDB_BITMAP_OUTEVENT_RT
                                 : IDB_BITMAP_OUTEVENT_LF );
    }
    else if ( bstr == IDML_REQUIREDREQUESTPORT_NAME ) {
      m_bitmap.ReadFromResource( m_right
                                 ? IDB_BITMAP_RECEPTACLE_RT
                                 : IDB_BITMAP_RECEPTACLE_LF );
    }
    else m_bitmap.ReadFromResource( IDB_BITMAP_FACET );
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
//	CLASS : ComponentDecorator
//
//########################################################

ComponentDecorator::ComponentDecorator( CComPtr<IMgaMetaPart>	metaPart )
  : DecoratorBase(),
    m_metaPart( metaPart ),
    m_iMaxPortTextLength( MAX_PORT_LENGTH ),
    m_bTypeNameEnabled( false ),
    m_iTypeInfo( 0 )
{
}

ComponentDecorator::~ComponentDecorator()
{
  unsigned int i;
	for ( i = 0 ; i < m_vecLeftPorts.size() ; i++ )
		delete m_vecLeftPorts[ i ];
	for ( i = 0 ; i < m_vecRightPorts.size() ; i++ )
		delete m_vecRightPorts[ i ];
}

void 
ComponentDecorator::initialize(IMgaFCO *obj, CComPtr<IMgaMetaFCO>& metaFco)
{
  DecoratorBase::initialize(obj, metaFco);
  if (!m_mgaFco) return;
  
  loadPorts();

	CComBSTR bstrPath = PREF_TYPESHOWN;
	CComBSTR bstrValue;
	COMTHROW( m_mgaFco->get_RegistryValue( bstrPath, &bstrValue ) );
  m_bTypeNameEnabled =
    (bstrValue == "t" || bstrValue == "true" || bstrValue == "1" );

	VARIANT_BOOL bInstance = VARIANT_FALSE;
	COMTHROW( m_mgaFco->get_IsInstance( &bInstance ) );
	if ( bInstance == VARIANT_TRUE ) {
		m_iTypeInfo = 3;
		if ( m_bTypeNameEnabled ) {
			CComPtr<IMgaFCO> spType;
			COMTHROW( m_mgaFco->get_DerivedFrom( &spType ) );
			CComBSTR bstrName;
			COMTHROW( spType->get_Name( &bstrName ) );
			m_strTypeName = bstrName;
		}
	}
	else {
		CComPtr<IMgaFCO> spType;
		COMTHROW( m_mgaFco->get_DerivedFrom( &spType ) );
		if ( spType )
			m_iTypeInfo = 2;
		else {
			CComPtr<IMgaFCOs> spFCOs;
			COMTHROW( m_mgaFco->get_DerivedObjects( &spFCOs ) );
			long lCount = 0;
			COMTHROW( spFCOs->get_Count( &lCount ) );
			m_iTypeInfo = ( lCount == 0 ) ? 0 : 1;
		}
	}
}

CSize
ComponentDecorator::getPreferredSize() const
{
	if ( m_vecLeftPorts.empty() && m_vecRightPorts.empty() )
		return DecoratorBase::getPreferredSize();

	long lWidth =
    ( 8 * m_iMaxPortTextLength
      + GAP_LABEL
      + GME_PORT_SIZE
      + GAP_XMODELPORT
      + GAP_XOVALICONFUDGE )
      * 2
    + GAP_PORTLABEL;
	long lHeight =
    (GAP_YMODELPORT + GAP_YOVALICONFUDGE) * 2
    + max( m_vecLeftPorts.size(), m_vecRightPorts.size() )
      * ( GME_PORT_SIZE + GAP_PORT )
    - GAP_PORT;

	return CSize( max( (long) WIDTH_MODEL, lWidth ),
                max( (long) HEIGHT_MODEL, lHeight ) );
}

void
ComponentDecorator::setLocation( const CRect& cRect )
{
  m_rect = cRect;
	long lY = ( m_rect.Height()
              - m_vecLeftPorts.size() * ( GME_PORT_SIZE + GAP_PORT )
              + GAP_PORT )
             / 2;

  unsigned int i;

	for ( i = 0 ; i < m_vecLeftPorts.size() ; i++ ) {
		m_vecLeftPorts[ i ]->setLocation( CRect( GAP_XMODELPORT
                                             + GAP_XOVALICONFUDGE, 
                                             lY, 
                                             GAP_XMODELPORT
                                             + GME_PORT_SIZE
                                             + GAP_XOVALICONFUDGE, 
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
                                              - GAP_XOVALICONFUDGE, 
                                              lY,
                                              cRect.Width()
                                              - GAP_XMODELPORT
                                              - GAP_XOVALICONFUDGE, 
                                              lY + GME_PORT_SIZE ) );
		lY += GME_PORT_SIZE + GAP_PORT;
	}
}

void
ComponentDecorator::LoadBitmap()
{
  m_bitmap.ReadFromResource( IDB_BITMAP_COMPONENT );       
}

void
ComponentDecorator::draw( CDC* pDC )
{
  // Draw the component icon.
  CRect dst = getLocation();
	m_bitmap.Draw( pDC, dst );

  // Draw the component name.
	CPoint namePos( dst.left + dst.Width () / 2, dst.bottom + NAME_MARGINY );
	d_util.DrawText( pDC, 
                   m_name,
                   namePos,
                   d_util.GetFont( GME_NAME_FONT ),
                   m_nameColor,
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
                     m_nameColor,
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

vector<PortDecorator*>
ComponentDecorator::getPorts() const
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
		if ( m_vecLeftPorts[ i ]->getFCO() == spFCO )
			return m_vecLeftPorts[ i ];
	for ( i = 0 ; i < m_vecRightPorts.size() ; i++ )
		if ( m_vecRightPorts[ i ]->getFCO() == spFCO )
			return m_vecRightPorts[ i ];
	return NULL;
}

void
ComponentDecorator::loadPorts()
{
	CComPtr<IMgaMetaAspect>	spParentAspect;
	COMTHROW( m_metaPart->get_ParentAspect( &spParentAspect ) );

	CComQIPtr<IMgaModel> spModel = m_mgaFco;
	CComPtr<IMgaMetaFCO> spMetaFCO;
	COMTHROW( spModel->get_Meta( &spMetaFCO ) );
	CComQIPtr<IMgaMetaModel> spMetaModel = spMetaFCO;

	CComBSTR bstrAspect;
	COMTHROW( m_metaPart->get_KindAspect( &bstrAspect ) );
	if ( bstrAspect.Length() == 0 ) {
		bstrAspect.Empty();
		COMTHROW( spParentAspect->get_Name( &bstrAspect ) );
	}
	
	HRESULT hr = spMetaModel->get_AspectByName( bstrAspect, &m_spAspect );
	
	if ( hr == E_NOTFOUND) {
		try {
			// JEFF: There is only one aspect in IDML,
      // but this is still the easiest way
			m_spAspect = NULL;
			CComPtr<IMgaMetaAspects> spAspects;
			COMTHROW(spMetaModel->get_Aspects(&spAspects));
			ASSERT(spAspects);
			long nAspects = 0;
			COMTHROW(spAspects->get_Count(&nAspects));
			if (nAspects > 0) {
				COMTHROW(spAspects->get_Item(1, &m_spAspect));
			}
		}
		catch ( hresult_exception& ) {
		}
	}

	if ( m_spAspect ) {

		vector<PortDecorator*>	vecPorts;

		CComPtr<IMgaFCOs> spFCOs;
		COMTHROW( spModel->get_ChildFCOs( &spFCOs ) );
		MGACOLL_ITERATE( IMgaFCO, spFCOs ) {
			CComPtr<IMgaPart> spPart;
			COMTHROW( MGACOLL_ITER->get_Part( m_spAspect, &spPart ) );
			if ( spPart ) {
				CComPtr<IMgaMetaPart> spMetaPart;
				COMTHROW( spPart->get_Meta( &spMetaPart ) );
				VARIANT_BOOL vbLinked;
				COMTHROW( spMetaPart->get_IsLinked( &vbLinked ) );
				if ( vbLinked ) {
					long lX = 0;
					long lY = 0;
					COMTHROW( spPart->GetGmeAttrs( 0, &lX, &lY ) );
					vecPorts.push_back( new PortDecorator( MGACOLL_ITER,
                                                 CPoint( lX, lY ) ) );
				}
				else
					COMTHROW( MGACOLL_ITER->Close() );
			}
			else
				COMTHROW( MGACOLL_ITER->Close() );
		} MGACOLL_ITERATE_END;

		orderPorts( vecPorts );
	}
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

