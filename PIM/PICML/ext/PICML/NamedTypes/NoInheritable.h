// -*- C++ -*-

//============================================================================
/**
 * @file    NoInheritable.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_NOINHERITABLE_H_
#define _PICML_NAMEDTYPES_NOINHERITABLE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NamedType.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class NoInheritable_Impl;
  typedef NoInheritable_Impl * NoInheritable_in;
  typedef ::GAME::Mga::Smart_Ptr < NoInheritable_Impl > NoInheritable;

  /**
   * @class NoInheritable_Impl
   *
   * Implementation for the NoInheritable model element.
   */
  class PICML_Export NoInheritable_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual NamedType_Impl
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
    NoInheritable_Impl (void);

    // Initializing constructor.
    NoInheritable_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~NoInheritable_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    HasOperations parent_HasOperations (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "NoInheritable.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_NOINHERITABLE
