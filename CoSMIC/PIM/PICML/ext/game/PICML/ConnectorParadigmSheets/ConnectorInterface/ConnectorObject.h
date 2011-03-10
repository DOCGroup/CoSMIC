// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorObject.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTOROBJECT_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTOROBJECT_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorObject_Impl;
  typedef ConnectorObject_Impl * ConnectorObject_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorObject_Impl> ConnectorObject;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorObject_Impl :
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
    ConnectorObject_Impl (void);

    /// Initializing constructor
    ConnectorObject_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ConnectorObject_Impl (void);

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

    ConnectorInherits get_ConnectorInherits (void) const;
    size_t get_Collections (std::vector <Collection> & items) const;
    size_t get_Aggregates (std::vector <Aggregate> & items) const;
    size_t get_ExtendedPortBases (std::vector <ExtendedPortBase> & items) const;
    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
    size_t get_ObjectPorts (std::vector <ObjectPort> & items) const;
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
