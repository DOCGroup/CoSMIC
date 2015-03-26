// -*- C++ -*-

//============================================================================
/**
 * @file    FloatNumber.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_FLOATNUMBER_H_
#define _PICML_PREDEFINEDTYPES_FLOATNUMBER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/FloatingPointType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FloatNumber_Impl;
  typedef FloatNumber_Impl * FloatNumber_in;
  typedef ::GAME::Mga::Smart_Ptr < FloatNumber_Impl > FloatNumber;

  // Forward decl.
  class Visitor;

  /**
   * @class FloatNumber_Impl
   *
   * Implementation for the FloatNumber model element.
   */
  class PICML_Export FloatNumber_Impl :
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
    static FloatNumber _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    FloatNumber_Impl (void);

    // Initializing constructor.
    FloatNumber_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~FloatNumber_Impl (void);

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
#include "FloatNumber.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_FLOATNUMBER
