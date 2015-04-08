// -*- C++ -*-

//============================================================================
/**
 * @file    Provideable.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PROVIDEABLE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PROVIDEABLE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Provideable_Impl;
  typedef Provideable_Impl * Provideable_in;
  typedef ::GAME::Mga::Smart_Ptr < Provideable_Impl > Provideable;

  /**
   * @class Provideable_Impl
   *
   * Implementation for the Provideable model element.
   */
  class PICML_Export Provideable_Impl :
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
    Provideable_Impl (void);

    // Initializing constructor.
    Provideable_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~Provideable_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Provideable.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PROVIDEABLE
