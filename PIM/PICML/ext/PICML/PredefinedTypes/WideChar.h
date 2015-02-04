// -*- C++ -*-

//============================================================================
/**
 * @file    WideChar.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_WIDECHAR_H_
#define _PICML_PREDEFINEDTYPES_WIDECHAR_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/CharType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WideChar_Impl;
  typedef WideChar_Impl * WideChar_in;
  typedef ::GAME::Mga::Smart_Ptr < WideChar_Impl > WideChar;

  // Forward decl.
  class Visitor;

  /**
   * @class WideChar_Impl
   *
   * Implementation for the WideChar model element.
   */
  class PICML_Export WideChar_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual CharType_Impl
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
    static WideChar _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    WideChar_Impl (void);

    // Initializing constructor.
    WideChar_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~WideChar_Impl (void);

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
#include "WideChar.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_WIDECHAR
