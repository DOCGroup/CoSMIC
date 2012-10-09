// -*- C++ -*-

//============================================================================
/**
 * @file    Manageable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGEABLE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGEABLE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Manageable_Impl;
  typedef Manageable_Impl * Manageable_in;
  typedef ::GAME::Mga::Smart_Ptr < Manageable_Impl > Manageable;

  /**
   * @class Manageable_Impl
   *
   * Implementation for the Manageable model element.
   */
  class PICML_Export Manageable_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    Manageable_Impl (void);

    // Initializing constructor.
    Manageable_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~Manageable_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ManagesComponent connection.
    size_t dst_ManagesComponent (std::vector <ManagesComponent> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Manageable.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGEABLE
