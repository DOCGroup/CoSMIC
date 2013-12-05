// -*- C++ -*-

//============================================================================
/**
 * @file    LongLongInteger.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_LONGLONGINTEGER_H_
#define _PICML_PREDEFINEDTYPES_LONGLONGINTEGER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/SignedIntegerType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LongLongInteger_Impl;
  typedef LongLongInteger_Impl * LongLongInteger_in;
  typedef ::GAME::Mga::Smart_Ptr < LongLongInteger_Impl > LongLongInteger;

  // Forward decl.
  class Visitor;

  /**
   * @class LongLongInteger_Impl
   *
   * Implementation for the LongLongInteger model element.
   */
  class PICML_Export LongLongInteger_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual SignedIntegerType_Impl
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
    static LongLongInteger _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    LongLongInteger_Impl (void);

    // Initializing constructor.
    LongLongInteger_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~LongLongInteger_Impl (void);

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
#include "LongLongInteger.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_LONGLONGINTEGER
