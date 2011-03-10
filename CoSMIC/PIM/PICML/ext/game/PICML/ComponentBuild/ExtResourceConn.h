// -*- C++ -*-

//============================================================================
/**
 * @file    ExtResourceConn.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_EXTRESOURCECONN_H_
#define _PICML_COMPONENTBUILD_EXTRESOURCECONN_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtResourceConn_Impl;
  typedef ExtResourceConn_Impl * ExtResourceConn_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtResourceConn_Impl> ExtResourceConn;

  // Forward decl.
  class Visitor;

  class PICML_Export ExtResourceConn_Impl :
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
    ExtResourceConn_Impl (void);

    /// Initializing constructor
    ExtResourceConn_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ExtResourceConn_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ExtResourceConn _create (const Project_in parent);
    ///@}

    /// Get the src ComponentLib connection point.
    ComponentLib src_ComponentLib (void);

    /// Get the dst ExternalResources connection point.
    ExternalResources dst_ExternalResources (void);

    /**
     * @name Parent Methods
     */
    ///@{
    Project parent_Project (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
