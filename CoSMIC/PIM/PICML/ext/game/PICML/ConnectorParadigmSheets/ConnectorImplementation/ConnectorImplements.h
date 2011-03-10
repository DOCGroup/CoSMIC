// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplements.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTS_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTS_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplements_Impl;
  typedef ConnectorImplements_Impl * ConnectorImplements_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplements_Impl> ConnectorImplements;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorImplements_Impl :
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
    ConnectorImplements_Impl (void);

    /// Initializing constructor
    ConnectorImplements_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ConnectorImplements_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorImplements _create (const ConnectorImplementationContainer_in parent);
    ///@}

    /// Get the src ConnectorImplementation connection point.
    ConnectorImplementation src_ConnectorImplementation (void);

    /// Get the dst ConnectorType connection point.
    ConnectorType dst_ConnectorType (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorImplementationContainer parent_ConnectorImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
