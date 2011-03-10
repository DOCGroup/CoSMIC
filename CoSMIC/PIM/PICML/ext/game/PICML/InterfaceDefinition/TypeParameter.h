// -*- C++ -*-

//============================================================================
/**
 * @file    TypeParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_TYPEPARAMETER_H_
#define _PICML_INTERFACEDEFINITION_TYPEPARAMETER_H_

#include "game/mga/Atom.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TypeParameter_Impl;
  typedef TypeParameter_Impl * TypeParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <TypeParameter_Impl> TypeParameter;

  // Forward decl.
  class Visitor;

  class PICML_Export TypeParameter_Impl :
    public virtual TemplateParameter_Impl,
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
    TypeParameter_Impl (void);

    /// Initializing constructor
    TypeParameter_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~TypeParameter_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Type
    void Type (const std::string & val);

    /// Get the value of Type
    std::string Type (void) const;
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
