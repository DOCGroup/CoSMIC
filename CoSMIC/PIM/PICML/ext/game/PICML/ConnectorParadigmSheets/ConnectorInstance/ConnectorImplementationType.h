// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplementationType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINSTANCE_CONNECTORIMPLEMENTATIONTYPE_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINSTANCE_CONNECTORIMPLEMENTATIONTYPE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplementationType_Impl;
  typedef ConnectorImplementationType_Impl * ConnectorImplementationType_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplementationType_Impl> ConnectorImplementationType;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorImplementationType_Impl :
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
    ConnectorImplementationType_Impl (void);

    /// Initializing constructor
    ConnectorImplementationType_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ConnectorImplementationType_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorImplementationType _create (const ConnectorInstance_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorInstance parent_ConnectorInstance (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
