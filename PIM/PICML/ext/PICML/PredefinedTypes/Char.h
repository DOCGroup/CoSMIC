// -*- C++ -*-

//============================================================================
/**
 * @file    Char.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_CHAR_H_
#define _PICML_PREDEFINEDTYPES_CHAR_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/CharType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Char_Impl;
  typedef Char_Impl * Char_in;
  typedef ::GAME::Mga::Smart_Ptr < Char_Impl > Char;

  // Forward decl.
  class Visitor;

  /**
   * @class Char_Impl
   *
   * Implementation for the Char model element.
   */
  class PICML_Export Char_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual CharType_Impl
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
    static Char _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    Char_Impl (void);

    // Initializing constructor.
    Char_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Char_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Char.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_CHAR
