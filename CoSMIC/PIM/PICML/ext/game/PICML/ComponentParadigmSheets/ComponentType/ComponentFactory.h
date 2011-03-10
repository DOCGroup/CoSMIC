// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentFactory.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTFACTORY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTFACTORY_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentFactory_Impl;
  typedef ComponentFactory_Impl * ComponentFactory_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentFactory_Impl> ComponentFactory;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentFactory_Impl :
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
    ComponentFactory_Impl (void);

    /// Initializing constructor
    ComponentFactory_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ComponentFactory_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_ManagesComponent_connections (std::vector <ManagesComponent> & conns) const;

    /**
     * @name Containment Methods
     */
    ///@{

    LookupKey get_LookupKey (void) const;
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
