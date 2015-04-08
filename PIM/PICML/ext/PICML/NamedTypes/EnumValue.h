// -*- C++ -*-

//============================================================================
/**
 * @file    EnumValue.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_ENUMVALUE_H_
#define _PICML_NAMEDTYPES_ENUMVALUE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EnumValue_Impl;
  typedef EnumValue_Impl * EnumValue_in;
  typedef ::GAME::Mga::Smart_Ptr < EnumValue_Impl > EnumValue;

  // Forward decl.
  class Visitor;

  /**
   * @class EnumValue_Impl
   *
   * Implementation for the EnumValue model element.
   */
  class PICML_Export EnumValue_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static EnumValue _create (const Enum_in parent);
    ///@}

    // Default constructor.
    EnumValue_Impl (void);

    // Initializing constructor.
    EnumValue_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~EnumValue_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Enum parent_Enum (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "EnumValue.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_ENUMVALUE
