// -*- C++ -*-

//============================================================================
/**
 * @file    Component.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENT_H_

#include "game/mga/Model.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Manageable.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Component_Impl;
  typedef Component_Impl * Component_in;
  typedef ::GAME::Mga::Smart_Ptr <Component_Impl> Component;

  // Forward decl.
  class Visitor;

  class PICML_Export Component_Impl :
    public virtual Manageable_Impl,
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
    Component_Impl (void);

    /// Initializing constructor
    Component_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Component_Impl (void);

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
    size_t get_ExtendedPortBases (std::vector <ExtendedPortBase> & items) const;

    ComponentInherits get_ComponentInherits (void) const;
    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
    size_t get_Ports (std::vector <Port> & items) const;
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
