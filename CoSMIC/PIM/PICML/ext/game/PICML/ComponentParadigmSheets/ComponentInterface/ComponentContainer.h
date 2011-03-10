// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTCONTAINER_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTCONTAINER_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentContainer_Impl;
  typedef ComponentContainer_Impl * ComponentContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentContainer_Impl> ComponentContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentContainer_Impl :
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
    ComponentContainer_Impl (void);

    /// Initializing constructor
    ComponentContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ComponentContainer_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentContainer _create (const ComponentTypes_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComponentInfoPropertys (std::vector <ComponentInfoProperty> & items) const;
    size_t get_ComponentConfigPropertys (std::vector <ComponentConfigProperty> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;

    ComponentRef get_ComponentRef (void) const;
    size_t get_ComponentPropertyDescriptions (std::vector <ComponentPropertyDescription> & items) const;
    size_t get_ComponentPropertys (std::vector <ComponentProperty> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentTypes parent_ComponentTypes (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
