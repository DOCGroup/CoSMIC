// -*- C++ -*-

//============================================================================
/**
 * @file    DoubleNumber.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_DOUBLENUMBER_H_
#define _PICML_PREDEFINEDTYPES_DOUBLENUMBER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/FloatingPointType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DoubleNumber_Impl;
  typedef DoubleNumber_Impl * DoubleNumber_in;
  typedef ::GAME::Mga::Smart_Ptr < DoubleNumber_Impl > DoubleNumber;

  // Forward decl.
  class Visitor;

  /**
   * @class DoubleNumber_Impl
   *
   * Implementation for the DoubleNumber model element.
   */
  class PICML_Export DoubleNumber_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static DoubleNumber _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    DoubleNumber_Impl (void);

    // Initializing constructor.
    DoubleNumber_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~DoubleNumber_Impl (void);

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
#include "DoubleNumber.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_DOUBLENUMBER
