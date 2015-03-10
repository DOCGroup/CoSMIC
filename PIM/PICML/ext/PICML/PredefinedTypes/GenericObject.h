// -*- C++ -*-

//============================================================================
/**
 * @file    GenericObject.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_GENERICOBJECT_H_
#define _PICML_PREDEFINEDTYPES_GENERICOBJECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Provideable.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class GenericObject_Impl;
  typedef GenericObject_Impl * GenericObject_in;
  typedef ::GAME::Mga::Smart_Ptr < GenericObject_Impl > GenericObject;

  // Forward decl.
  class Visitor;

  /**
   * @class GenericObject_Impl
   *
   * Implementation for the GenericObject model element.
   */
  class PICML_Export GenericObject_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual PredefinedType_Impl,
    public virtual Provideable_Impl
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
    static GenericObject _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    GenericObject_Impl (void);

    // Initializing constructor.
    GenericObject_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~GenericObject_Impl (void);

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
#include "GenericObject.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_GENERICOBJECT
