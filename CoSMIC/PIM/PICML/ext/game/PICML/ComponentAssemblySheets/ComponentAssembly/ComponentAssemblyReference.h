// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentAssemblyReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_COMPONENTASSEMBLYREFERENCE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_COMPONENTASSEMBLYREFERENCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentAssemblyReference_Impl;
  typedef ComponentAssemblyReference_Impl * ComponentAssemblyReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentAssemblyReference_Impl> ComponentAssemblyReference;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentAssemblyReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentAssemblyReference_Impl (void);

    /// Initializing constructor
    ComponentAssemblyReference_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComponentAssemblyReference_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentAssemblyReference _create (const ComponentAssembly_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ComponentAssembly refers_to_ComponentAssembly (void) const;
    ///@}
  };
}

#endif
