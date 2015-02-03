// -*- C++ -*-

//============================================================================
/**
 * @file    ShortInteger.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_SHORTINTEGER_H_
#define _PICML_PREDEFINEDTYPES_SHORTINTEGER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/SignedIntegerType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ShortInteger_Impl;
  typedef ShortInteger_Impl * ShortInteger_in;
  typedef ::GAME::Mga::Smart_Ptr < ShortInteger_Impl > ShortInteger;

  // Forward decl.
  class Visitor;

  /**
   * @class ShortInteger_Impl
   *
   * Implementation for the ShortInteger model element.
   */
  class PICML_Export ShortInteger_Impl :
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


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ShortInteger _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    ShortInteger_Impl (void);

    // Initializing constructor.
    ShortInteger_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ShortInteger_Impl (void);

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
#include "ShortInteger.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_SHORTINTEGER
