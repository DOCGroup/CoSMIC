// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORTYPE_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORTYPE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorType_Impl;
  typedef ConnectorType_Impl * ConnectorType_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorType_Impl> ConnectorType;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ConnectorType_Impl (void);

    /// Initializing constructor
    ConnectorType_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ConnectorType_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorType _create (const ConnectorImplementationContainer_in parent);
    ///@}
    size_t in_ConnectorImplements_connections (std::vector <ConnectorImplements> & conns) const;

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
