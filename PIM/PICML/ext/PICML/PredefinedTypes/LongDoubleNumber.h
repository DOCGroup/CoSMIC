// -*- C++ -*-

//============================================================================
/**
 * @file    LongDoubleNumber.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_LONGDOUBLENUMBER_H_
#define _PICML_PREDEFINEDTYPES_LONGDOUBLENUMBER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/FloatingPointType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LongDoubleNumber_Impl;
  typedef LongDoubleNumber_Impl * LongDoubleNumber_in;
  typedef ::GAME::Mga::Smart_Ptr < LongDoubleNumber_Impl > LongDoubleNumber;

  // Forward decl.
  class Visitor;

  /**
   * @class LongDoubleNumber_Impl
   *
   * Implementation for the LongDoubleNumber model element.
   */
  class PICML_Export LongDoubleNumber_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual FloatingPointType_Impl
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
    static LongDoubleNumber _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    LongDoubleNumber_Impl (void);

    // Initializing constructor.
    LongDoubleNumber_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~LongDoubleNumber_Impl (void);

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
#include "LongDoubleNumber.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_LONGDOUBLENUMBER
