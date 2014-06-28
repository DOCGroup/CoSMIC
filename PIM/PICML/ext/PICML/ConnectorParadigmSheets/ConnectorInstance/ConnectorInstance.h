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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigPropertyEnd.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorInstance_Impl;
  typedef ConnectorInstance_Impl * ConnectorInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorInstance_Impl > ConnectorInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorInstance_Impl
   *
   * Implementation for the ConnectorInstance model element.
   */
  class PICML_Export ConnectorInstance_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual AssemblyConfigPropertyEnd_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorInstance _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    ConnectorInstance_Impl (void);

    // Initializing constructor.
    ConnectorInstance_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ConnectorInstance_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of UUID
    void UUID (const std::string & val);

    /// Get the value of UUID
    std::string UUID (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ConnectorToFacet connection.
    size_t src_ConnectorToFacet (std::vector <ConnectorToFacet> & items) const;

    /// Get the src Consume connection.
    size_t src_Consume (std::vector <Consume> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst Publish connection.
    size_t dst_Publish (std::vector <Publish> & items) const;

    /// Get the dst ConnectorToReceptacle connection.
    size_t dst_ConnectorToReceptacle (std::vector <ConnectorToReceptacle> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ConnectorImplementationType (void) const;
    ConnectorImplementationType get_ConnectorImplementationType (void) const;
    size_t get_AttributeInstances (std::vector <AttributeInstance> & items) const;
    ::GAME::Mga::Collection_T <AttributeInstance> get_AttributeInstances (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorInstance.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINSTANCE_CONNECTORINSTANCE
