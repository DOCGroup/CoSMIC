// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInstance_Impl;
  typedef ComponentInstance_Impl * ComponentInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInstance_Impl> ComponentInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentInstance_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentInstance_Impl (void);

    /// Initializing constructor
    ComponentInstance_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ComponentInstance_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_PortInstances (std::vector <PortInstance> & items) const;

    ComponentInstanceType get_ComponentInstanceType (void) const;
    size_t get_SupportsInstances (std::vector <SupportsInstance> & items) const;
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
