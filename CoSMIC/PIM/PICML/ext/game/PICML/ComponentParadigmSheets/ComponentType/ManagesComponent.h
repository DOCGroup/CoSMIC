// -*- C++ -*-

//============================================================================
/**
 * @file    ManagesComponent.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGESCOMPONENT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGESCOMPONENT_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ManagesComponent_Impl;
  typedef ManagesComponent_Impl * ManagesComponent_in;
  typedef ::GAME::Mga::Smart_Ptr <ManagesComponent_Impl> ManagesComponent;

  // Forward decl.
  class Visitor;

  class PICML_Export ManagesComponent_Impl :
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
    ManagesComponent_Impl (void);

    /// Initializing constructor
    ManagesComponent_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ManagesComponent_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src ComponentFactory connection point.
    ComponentFactory src_ComponentFactory (void);

    /// Get the dst Manageable connection point.
    Manageable dst_Manageable (void);

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
