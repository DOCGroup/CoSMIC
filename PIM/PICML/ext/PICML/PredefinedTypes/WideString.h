// -*- C++ -*-

//============================================================================
/**
 * @file    WideString.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_WIDESTRING_H_
#define _PICML_PREDEFINEDTYPES_WIDESTRING_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/StringType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WideString_Impl;
  typedef WideString_Impl * WideString_in;
  typedef ::GAME::Mga::Smart_Ptr < WideString_Impl > WideString;

  // Forward decl.
  class Visitor;

  /**
   * @class WideString_Impl
   *
   * Implementation for the WideString model element.
   */
  class PICML_Export WideString_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual StringType_Impl
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
    static WideString _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    WideString_Impl (void);

    // Initializing constructor.
    WideString_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~WideString_Impl (void);

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
#include "WideString.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_WIDESTRING
