// -*- C++ -*-

//============================================================================
/**
 * @file    StringType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_STRINGTYPE_H_
#define _PICML_PREDEFINEDTYPES_STRINGTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class StringType_Impl;
  typedef StringType_Impl * StringType_in;
  typedef ::GAME::Mga::Smart_Ptr < StringType_Impl > StringType;

  /**
   * @class StringType_Impl
   *
   * Implementation for the StringType model element.
   */
  class PICML_Export StringType_Impl :
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
    StringType_Impl (void);

    // Initializing constructor.
    StringType_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~StringType_Impl (void) = 0;
  };
}

#if defined (__GAME_INLINE__)
#include "StringType.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_STRINGTYPE
