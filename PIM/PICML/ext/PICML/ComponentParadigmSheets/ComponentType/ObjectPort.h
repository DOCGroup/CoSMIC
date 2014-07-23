// -*- C++ -*-

//============================================================================
/**
 * @file    ObjectPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_OBJECTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_OBJECTPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ObjectPort_Impl;
  typedef ObjectPort_Impl * ObjectPort_in;
  typedef ::GAME::Mga::Smart_Ptr < ObjectPort_Impl > ObjectPort;

  /**
   * @class ObjectPort_Impl
   *
   * Implementation for the ObjectPort model element.
   */
  class PICML_Export ObjectPort_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual Port_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    ObjectPort_Impl (void);

    // Initializing constructor.
    ObjectPort_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ObjectPort_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorObject parent_ConnectorObject (void);
    PortType parent_PortType (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ObjectPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_OBJECTPORT
