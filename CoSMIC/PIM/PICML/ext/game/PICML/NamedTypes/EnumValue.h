// -*- C++ -*-

//============================================================================
/**
 * @file    EnumValue.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_ENUMVALUE_H_
#define _PICML_NAMEDTYPES_ENUMVALUE_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EnumValue_Impl;
  typedef EnumValue_Impl * EnumValue_in;
  typedef ::GAME::Mga::Smart_Ptr <EnumValue_Impl> EnumValue;

  // Forward decl.
  class Visitor;

  class PICML_Export EnumValue_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    EnumValue_Impl (void);

    /// Initializing constructor
    EnumValue_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~EnumValue_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static EnumValue _create (const Enum_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Enum parent_Enum (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
