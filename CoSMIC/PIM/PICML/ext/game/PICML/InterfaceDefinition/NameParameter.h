// -*- C++ -*-

//============================================================================
/**
 * @file    NameParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_NAMEPARAMETER_H_
#define _PICML_INTERFACEDEFINITION_NAMEPARAMETER_H_

#include "game/mga/Atom.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class NameParameter_Impl;
  typedef NameParameter_Impl * NameParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <NameParameter_Impl> NameParameter;

  // Forward decl.
  class Visitor;

  class PICML_Export NameParameter_Impl :
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
    NameParameter_Impl (void);

    /// Initializing constructor
    NameParameter_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~NameParameter_Impl (void);

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
