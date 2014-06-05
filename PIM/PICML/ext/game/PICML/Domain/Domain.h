// -*- C++ -*-

//============================================================================
/**
 * @file    Domain.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DOMAIN_DOMAIN_H_
#define _PICML_DOMAIN_DOMAIN_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Domain_Impl;
  typedef Domain_Impl * Domain_in;
  typedef ::GAME::Mga::Smart_Ptr < Domain_Impl > Domain;

  // Forward decl.
  class Visitor;

  /**
   * @class Domain_Impl
   *
   * Implementation for the Domain model element.
   */
  class PICML_Export Domain_Impl :
    public virtual ::GAME::Mga::Model_Impl
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
    static Domain _create (const Targets_in parent);
    ///@}

    // Default constructor.
    Domain_Impl (void);

    // Initializing constructor.
    Domain_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Domain_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Targets parent_Targets (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of UUID
    void UUID (const std::string & val);

    /// Get the value of UUID
    std::string UUID (void) const;

    /// Set the value of label
    void label (const std::string & val);

    /// Get the value of label
    std::string label (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_Nodes (std::vector <Node> & items) const;
    ::GAME::Mga::Collection_T <Node> get_Nodes (void) const;

    size_t get_SharedResources (std::vector <SharedResource> & items) const;
    ::GAME::Mga::Collection_T <SharedResource> get_SharedResources (void) const;

    size_t get_Interconnects (std::vector <Interconnect> & items) const;
    ::GAME::Mga::Collection_T <Interconnect> get_Interconnects (void) const;

    size_t get_Bridges (std::vector <Bridge> & items) const;
    ::GAME::Mga::Collection_T <Bridge> get_Bridges (void) const;

    size_t get_Sharess (std::vector <Shares> & items) const;
    ::GAME::Mga::Collection_T <Shares> get_Sharess (void) const;

    size_t get_InterconnectConnections (std::vector <InterconnectConnection> & items) const;
    ::GAME::Mga::Collection_T <InterconnectConnection> get_InterconnectConnections (void) const;

    size_t get_BridgeConnections (std::vector <BridgeConnection> & items) const;
    ::GAME::Mga::Collection_T <BridgeConnection> get_BridgeConnections (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Domain.inl"
#endif

#endif  // !defined _PICML_DOMAIN_DOMAIN
