// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTPROPERTY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentProperty_Impl;
  typedef ComponentProperty_Impl * ComponentProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentProperty_Impl> ComponentProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentProperty_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentProperty_Impl (void);

    /// Initializing constructor
    ComponentProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ComponentProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentProperty _create (const ComponentContainer_in parent);
    ///@}

    /// Get the src ComponentRef connection point.
    ComponentRef src_ComponentRef (void);

    /// Get the dst ComponentPropertyDescription connection point.
    ComponentPropertyDescription dst_ComponentPropertyDescription (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentContainer parent_ComponentContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
