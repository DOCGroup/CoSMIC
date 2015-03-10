// -*- C++ -*-

//============================================================================
/**
 * @file    Byte.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_BYTE_H_
#define _PICML_PREDEFINEDTYPES_BYTE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "PICML/InterfaceDefinition/ConstantType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Byte_Impl;
  typedef Byte_Impl * Byte_in;
  typedef ::GAME::Mga::Smart_Ptr < Byte_Impl > Byte;

  // Forward decl.
  class Visitor;

  /**
   * @class Byte_Impl
   *
   * Implementation for the Byte model element.
   */
  class PICML_Export Byte_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual PredefinedType_Impl,
    public virtual ConstantType_Impl
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
    static Byte _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    Byte_Impl (void);

    // Initializing constructor.
    Byte_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Byte_Impl (void);

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
#include "Byte.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_BYTE
