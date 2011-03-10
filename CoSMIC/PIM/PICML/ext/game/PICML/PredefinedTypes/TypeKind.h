// -*- C++ -*-

//============================================================================
/**
 * @file    TypeKind.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_TYPEKIND_H_
#define _PICML_PREDEFINEDTYPES_TYPEKIND_H_

#include "game/mga/Atom.h"
#include "PICML/PredefinedTypes/PredefinedType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TypeKind_Impl;
  typedef TypeKind_Impl * TypeKind_in;
  typedef ::GAME::Mga::Smart_Ptr <TypeKind_Impl> TypeKind;

  // Forward decl.
  class Visitor;

  class PICML_Export TypeKind_Impl :
    public virtual PredefinedType_Impl,
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
    TypeKind_Impl (void);

    /// Initializing constructor
    TypeKind_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~TypeKind_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
