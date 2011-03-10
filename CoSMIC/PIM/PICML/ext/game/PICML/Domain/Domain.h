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

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Domain_Impl;
  typedef Domain_Impl * Domain_in;
  typedef ::GAME::Mga::Smart_Ptr <Domain_Impl> Domain;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    Domain_Impl (void);

    /// Initializing constructor
    Domain_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Domain_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Domain _create (const Targets_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_BridgeConnections (std::vector <BridgeConnection> & items) const;
    size_t get_InterconnectConnections (std::vector <InterconnectConnection> & items) const;
    size_t get_Sharess (std::vector <Shares> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;
    size_t get_SharedResources (std::vector <SharedResource> & items) const;
    size_t get_Bridges (std::vector <Bridge> & items) const;
    size_t get_Nodes (std::vector <Node> & items) const;
    size_t get_Interconnects (std::vector <Interconnect> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Targets parent_Targets (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
