// -*- C++ -*-

//============================================================================
/**
 * @file    Consume.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONSUME_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONSUME_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Consume_Impl;
  typedef Consume_Impl * Consume_in;
  typedef ::GAME::Mga::Smart_Ptr <Consume_Impl> Consume;

  // Forward decl.
  class Visitor;

  class PICML_Export Consume_Impl :
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
    Consume_Impl (void);

    /// Initializing constructor
    Consume_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Consume_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src ConnectorInstance connection point.
    ConnectorInstance src_ConnectorInstance (void);

    /// Get the dst ExtendPortEnd connection point.
    ExtendPortEnd dst_ExtendPortEnd (void);

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
