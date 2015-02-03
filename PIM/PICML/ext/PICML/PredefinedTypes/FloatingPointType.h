// -*- C++ -*-

//============================================================================
/**
 * @file    FloatingPointType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_FLOATINGPOINTTYPE_H_
#define _PICML_PREDEFINEDTYPES_FLOATINGPOINTTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InterfaceDefinition/ConstantType.h"
#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FloatingPointType_Impl;
  typedef FloatingPointType_Impl * FloatingPointType_in;
  typedef ::GAME::Mga::Smart_Ptr < FloatingPointType_Impl > FloatingPointType;

  /**
   * @class FloatingPointType_Impl
   *
   * Implementation for the FloatingPointType model element.
   */
  class PICML_Export FloatingPointType_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual ConstantType_Impl,
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

    // Default constructor.
    FloatingPointType_Impl (void);

    // Initializing constructor.
    FloatingPointType_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~FloatingPointType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "FloatingPointType.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_FLOATINGPOINTTYPE
