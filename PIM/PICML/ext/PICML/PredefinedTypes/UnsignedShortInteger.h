// -*- C++ -*-

//============================================================================
/**
 * @file    UnsignedShortInteger.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_UNSIGNEDSHORTINTEGER_H_
#define _PICML_PREDEFINEDTYPES_UNSIGNEDSHORTINTEGER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/UnsignedIntegerType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class UnsignedShortInteger_Impl;
  typedef UnsignedShortInteger_Impl * UnsignedShortInteger_in;
  typedef ::GAME::Mga::Smart_Ptr < UnsignedShortInteger_Impl > UnsignedShortInteger;

  // Forward decl.
  class Visitor;

  /**
   * @class UnsignedShortInteger_Impl
   *
   * Implementation for the UnsignedShortInteger model element.
   */
  class PICML_Export UnsignedShortInteger_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static UnsignedShortInteger _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    UnsignedShortInteger_Impl (void);

    // Initializing constructor.
    UnsignedShortInteger_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~UnsignedShortInteger_Impl (void);

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
#include "UnsignedShortInteger.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_UNSIGNEDSHORTINTEGER
