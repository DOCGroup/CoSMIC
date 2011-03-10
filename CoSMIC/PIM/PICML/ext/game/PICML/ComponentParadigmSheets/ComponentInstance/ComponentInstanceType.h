// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInstanceType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCETYPE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCETYPE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInstanceType_Impl;
  typedef ComponentInstanceType_Impl * ComponentInstanceType_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInstanceType_Impl> ComponentInstanceType;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentInstanceType_Impl :
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
    ComponentInstanceType_Impl (void);

    /// Initializing constructor
    ComponentInstanceType_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComponentInstanceType_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentInstanceType _create (const ComponentInstance_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentInstance parent_ComponentInstance (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
