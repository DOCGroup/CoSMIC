// -*- C++ -*-

//============================================================================
/**
 * @file    TypeKind.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_TYPEKIND_H_
#define _PICML_PREDEFINEDTYPES_TYPEKIND_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TypeKind_Impl;
  typedef TypeKind_Impl * TypeKind_in;
  typedef ::GAME::Mga::Smart_Ptr < TypeKind_Impl > TypeKind;

  // Forward decl.
  class Visitor;

  /**
   * @class TypeKind_Impl
   *
   * Implementation for the TypeKind model element.
   */
  class PICML_Export TypeKind_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual PredefinedType_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static TypeKind _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    TypeKind_Impl (void);

    // Initializing constructor.
    TypeKind_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TypeKind_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
  };
}

#if defined (__GAME_INLINE__)
#include "TypeKind.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_TYPEKIND
