// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorToFacet.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTOFACET_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTOFACET_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorToFacet_Impl;
  typedef ConnectorToFacet_Impl * ConnectorToFacet_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorToFacet_Impl> ConnectorToFacet;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorToFacet_Impl :
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
    ConnectorToFacet_Impl (void);

    /// Initializing constructor
    ConnectorToFacet_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ConnectorToFacet_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src ConnectorInstance connection point.
    ConnectorInstance src_ConnectorInstance (void);

    /// Get the dst ProvidedRequestPortEnd connection point.
    ProvidedRequestPortEnd dst_ProvidedRequestPortEnd (void);

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
