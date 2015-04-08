// -*- C++ -*-

//============================================================================
/**
 * @file    String.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_STRING_H_
#define _PICML_PREDEFINEDTYPES_STRING_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/StringType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class String_Impl;
  typedef String_Impl * String_in;
  typedef ::GAME::Mga::Smart_Ptr < String_Impl > String;

  // Forward decl.
  class Visitor;

  /**
   * @class String_Impl
   *
   * Implementation for the String model element.
   */
  class PICML_Export String_Impl :
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
    static String _create (const PredefinedTypes_in parent);
    ///@}

    // Default constructor.
    String_Impl (void);

    // Initializing constructor.
    String_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~String_Impl (void);

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
#include "String.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_STRING
