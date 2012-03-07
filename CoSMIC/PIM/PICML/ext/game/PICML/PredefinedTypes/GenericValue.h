// -*- C++ -*-

//============================================================================
/**
 * @file    GenericValue.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_GENERICVALUE_H_
#define _PICML_PREDEFINEDTYPES_GENERICVALUE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class GenericValue_Impl;
  typedef GenericValue_Impl * GenericValue_in;
  typedef ::GAME::Mga::Smart_Ptr < GenericValue_Impl > GenericValue;

  // Forward decl.
  class Visitor;

  /**
   * @class GenericValue_Impl
   *
   * Implementation for the GenericValue model element.
   */
  class PICML_Export GenericValue_Impl :
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
    static GenericValue _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    GenericValue_Impl (void);

    // Initializing constructor.
    GenericValue_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~GenericValue_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
  };
}

#if defined (__GAME_INLINE__)
#include "GenericValue.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_GENERICVALUE
