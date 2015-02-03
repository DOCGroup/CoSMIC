// -*- C++ -*-

//============================================================================
/**
 * @file    PortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_PORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_PORTINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PortInstance_Impl;
  typedef PortInstance_Impl * PortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < PortInstance_Impl > PortInstance;

  /**
   * @class PortInstance_Impl
   *
   * Implementation for the PortInstance model element.
   */
  class PICML_Export PortInstance_Impl :
    public virtual ::GAME::Mga::FCO_Impl
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
    PortInstance_Impl (void);

    // Initializing constructor.
    PortInstance_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~PortInstance_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentInstance parent_ComponentInstance (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PortInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_PORTINSTANCE
