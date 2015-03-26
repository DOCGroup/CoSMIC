// -*- C++ -*-

//============================================================================
/**
 * @file    UnsignedLongLongInteger.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_UNSIGNEDLONGLONGINTEGER_H_
#define _PICML_PREDEFINEDTYPES_UNSIGNEDLONGLONGINTEGER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/UnsignedIntegerType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class UnsignedLongLongInteger_Impl;
  typedef UnsignedLongLongInteger_Impl * UnsignedLongLongInteger_in;
  typedef ::GAME::Mga::Smart_Ptr < UnsignedLongLongInteger_Impl > UnsignedLongLongInteger;

  // Forward decl.
  class Visitor;

  /**
   * @class UnsignedLongLongInteger_Impl
   *
   * Implementation for the UnsignedLongLongInteger model element.
   */
  class PICML_Export UnsignedLongLongInteger_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual UnsignedIntegerType_Impl
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
    static UnsignedLongLongInteger _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    UnsignedLongLongInteger_Impl (void);

    // Initializing constructor.
    UnsignedLongLongInteger_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~UnsignedLongLongInteger_Impl (void);

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
#include "UnsignedLongLongInteger.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_UNSIGNEDLONGLONGINTEGER
