// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInherits.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTINHERITS_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTINHERITS_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInherits_Impl;
  typedef ComponentInherits_Impl * ComponentInherits_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInherits_Impl> ComponentInherits;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentInherits_Impl :
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
    ComponentInherits_Impl (void);

    /// Initializing constructor
    ComponentInherits_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComponentInherits_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentInherits _create (const Component_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Component parent_Component (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    Component refers_to_Component (void) const;
    ///@}
  };
}

#endif
