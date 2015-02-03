// -*- C++ -*-

//============================================================================
/**
 * @file    Port.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/IdTags/Taggable.h"
#include "PICML/PathDiagram/GraphVertex.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/CommonPortAttrs.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Port_Impl;
  typedef Port_Impl * Port_in;
  typedef ::GAME::Mga::Smart_Ptr < Port_Impl > Port;

  /**
   * @class Port_Impl
   *
   * Implementation for the Port model element.
   */
  class PICML_Export Port_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual Taggable_Impl,
    public virtual GraphVertex_Impl,
    public virtual CommonPortAttrs_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    Port_Impl (void);

    // Initializing constructor.
    Port_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~Port_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    Component parent_Component (void);
    ConnectedComponent parent_ConnectedComponent (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Port.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORT
