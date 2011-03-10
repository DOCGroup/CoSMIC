// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInfoProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTINFOPROPERTY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTINFOPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInfoProperty_Impl;
  typedef ComponentInfoProperty_Impl * ComponentInfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInfoProperty_Impl> ComponentInfoProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentInfoProperty_Impl :
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
    ComponentInfoProperty_Impl (void);

    /// Initializing constructor
    ComponentInfoProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ComponentInfoProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentInfoProperty _create (const ComponentContainer_in parent);
    ///@}

    /// Get the src ComponentRef connection point.
    ComponentRef src_ComponentRef (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

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
