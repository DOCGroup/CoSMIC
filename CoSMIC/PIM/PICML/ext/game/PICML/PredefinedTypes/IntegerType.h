// -*- C++ -*-

//============================================================================
/**
 * @file    IntegerType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_INTEGERTYPE_H_
#define _PICML_PREDEFINEDTYPES_INTEGERTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class IntegerType_Impl;
  typedef IntegerType_Impl * IntegerType_in;
  typedef ::GAME::Mga::Smart_Ptr < IntegerType_Impl > IntegerType;

  /**
   * @class IntegerType_Impl
   *
   * Implementation for the IntegerType model element.
   */
  class PICML_Export IntegerType_Impl :
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

    // Default constructor.
    IntegerType_Impl (void);

    // Initializing constructor.
    IntegerType_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~IntegerType_Impl (void) = 0;
  };
}

#if defined (__GAME_INLINE__)
#include "IntegerType.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_INTEGERTYPE
