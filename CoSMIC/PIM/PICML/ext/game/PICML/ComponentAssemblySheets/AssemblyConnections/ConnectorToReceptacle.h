// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorToReceptacle.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTORECEPTACLE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTORECEPTACLE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorToReceptacle_Impl;
  typedef ConnectorToReceptacle_Impl * ConnectorToReceptacle_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorToReceptacle_Impl> ConnectorToReceptacle;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorToReceptacle_Impl :
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
    ConnectorToReceptacle_Impl (void);

    /// Initializing constructor
    ConnectorToReceptacle_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ConnectorToReceptacle_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src RequiredRequestPortEnd connection point.
    RequiredRequestPortEnd src_RequiredRequestPortEnd (void);

    /// Get the dst ConnectorInstance connection point.
    ConnectorInstance dst_ConnectorInstance (void);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of InnerName
    void InnerName (const std::string & val);

    /// Get the value of InnerName
    std::string InnerName (void) const;
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
