// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINSTANCE_CONNECTORINSTANCE_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINSTANCE_CONNECTORINSTANCE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorInstance_Impl;
  typedef ConnectorInstance_Impl * ConnectorInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorInstance_Impl> ConnectorInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorInstance_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ConnectorInstance_Impl (void);

    /// Initializing constructor
    ConnectorInstance_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ConnectorInstance_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    ConnectorImplementationType get_ConnectorImplementationType (void) const;
    size_t get_AttributeInstances (std::vector <AttributeInstance> & items) const;
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
