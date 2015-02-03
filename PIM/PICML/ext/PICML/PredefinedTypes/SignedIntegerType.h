// -*- C++ -*-

//============================================================================
/**
 * @file    SignedIntegerType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_SIGNEDINTEGERTYPE_H_
#define _PICML_PREDEFINEDTYPES_SIGNEDINTEGERTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/IntegerType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SignedIntegerType_Impl;
  typedef SignedIntegerType_Impl * SignedIntegerType_in;
  typedef ::GAME::Mga::Smart_Ptr < SignedIntegerType_Impl > SignedIntegerType;

  /**
   * @class SignedIntegerType_Impl
   *
   * Implementation for the SignedIntegerType model element.
   */
  class PICML_Export SignedIntegerType_Impl :
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


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    SignedIntegerType_Impl (void);

    // Initializing constructor.
    SignedIntegerType_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~SignedIntegerType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SignedIntegerType.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_SIGNEDINTEGERTYPE
