// -*- C++ -*-

//============================================================================
/**
 * @file    Publish.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PUBLISH_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PUBLISH_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Publish_Impl;
  typedef Publish_Impl * Publish_in;
  typedef ::GAME::Mga::Smart_Ptr <Publish_Impl> Publish;

  // Forward decl.
  class Visitor;

  class PICML_Export Publish_Impl :
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
    Publish_Impl (void);

    /// Initializing constructor
    Publish_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Publish_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src ExtendPortEnd connection point.
    ExtendPortEnd src_ExtendPortEnd (void);

    /// Get the dst ConnectorInstance connection point.
    ConnectorInstance dst_ConnectorInstance (void);

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
