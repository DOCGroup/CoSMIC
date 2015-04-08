// -*- C++ -*-

//============================================================================
/**
 * @file    TypeEncoding.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_TYPEENCODING_H_
#define _PICML_PREDEFINEDTYPES_TYPEENCODING_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TypeEncoding_Impl;
  typedef TypeEncoding_Impl * TypeEncoding_in;
  typedef ::GAME::Mga::Smart_Ptr < TypeEncoding_Impl > TypeEncoding;

  // Forward decl.
  class Visitor;

  /**
   * @class TypeEncoding_Impl
   *
   * Implementation for the TypeEncoding model element.
   */
  class PICML_Export TypeEncoding_Impl :
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static TypeEncoding _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    TypeEncoding_Impl (void);

    // Initializing constructor.
    TypeEncoding_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TypeEncoding_Impl (void);

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
#include "TypeEncoding.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_TYPEENCODING
