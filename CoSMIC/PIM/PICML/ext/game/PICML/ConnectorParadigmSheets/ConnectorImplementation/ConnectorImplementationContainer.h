// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplementationContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATIONCONTAINER_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATIONCONTAINER_H_

#include "game/mga/Model.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplementationContainer_Impl;
  typedef ConnectorImplementationContainer_Impl * ConnectorImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplementationContainer_Impl> ConnectorImplementationContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorImplementationContainer_Impl :
    public virtual ImplementationContainer_Impl,
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
    ConnectorImplementationContainer_Impl (void);

    /// Initializing constructor
    ConnectorImplementationContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ConnectorImplementationContainer_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorImplementationContainer _create (const ConnectorImplementations_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ConnectorTypes (std::vector <ConnectorType> & items) const;
    size_t get_ConnectorImplementss (std::vector <ConnectorImplements> & items) const;
    size_t get_ConnectorImplementations (std::vector <ConnectorImplementation> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorImplementations parent_ConnectorImplementations (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
