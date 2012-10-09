// -*- C++ -*-

//============================================================================
/**
 * @file    UnsignedIntegerType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_UNSIGNEDINTEGERTYPE_H_
#define _PICML_PREDEFINEDTYPES_UNSIGNEDINTEGERTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/IntegerType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class UnsignedIntegerType_Impl;
  typedef UnsignedIntegerType_Impl * UnsignedIntegerType_in;
  typedef ::GAME::Mga::Smart_Ptr < UnsignedIntegerType_Impl > UnsignedIntegerType;

  /**
   * @class UnsignedIntegerType_Impl
   *
   * Implementation for the UnsignedIntegerType model element.
   */
  class PICML_Export UnsignedIntegerType_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual IntegerType_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    UnsignedIntegerType_Impl (void);

    // Initializing constructor.
    UnsignedIntegerType_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~UnsignedIntegerType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "UnsignedIntegerType.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_UNSIGNEDINTEGERTYPE
