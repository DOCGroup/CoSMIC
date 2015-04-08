// -*- C++ -*-

//============================================================================
/**
 * @file    GenericValueObject.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_GENERICVALUEOBJECT_H_
#define _PICML_PREDEFINEDTYPES_GENERICVALUEOBJECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class GenericValueObject_Impl;
  typedef GenericValueObject_Impl * GenericValueObject_in;
  typedef ::GAME::Mga::Smart_Ptr < GenericValueObject_Impl > GenericValueObject;

  // Forward decl.
  class Visitor;

  /**
   * @class GenericValueObject_Impl
   *
   * Implementation for the GenericValueObject model element.
   */
  class PICML_Export GenericValueObject_Impl :
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
    static GenericValueObject _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    GenericValueObject_Impl (void);

    // Initializing constructor.
    GenericValueObject_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~GenericValueObject_Impl (void);

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
#include "GenericValueObject.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_GENERICVALUEOBJECT
