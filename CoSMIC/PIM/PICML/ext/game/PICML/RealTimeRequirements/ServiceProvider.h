// -*- C++ -*-

//============================================================================
/**
 * @file    ServiceProvider.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_REALTIMEREQUIREMENTS_SERVICEPROVIDER_H_
#define _PICML_REALTIMEREQUIREMENTS_SERVICEPROVIDER_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ServiceProvider_Impl;
  typedef ServiceProvider_Impl * ServiceProvider_in;
  typedef ::GAME::Mga::Smart_Ptr <ServiceProvider_Impl> ServiceProvider;

  // Forward decl.
  class Visitor;

  class PICML_Export ServiceProvider_Impl :
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
    ServiceProvider_Impl (void);

    /// Initializing constructor
    ServiceProvider_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ServiceProvider_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ServiceProvider _create (const RTRequirements_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of fixed_prioirty_service_execution
    void fixed_prioirty_service_execution (bool val);

    /// Get the value of fixed_prioirty_service_execution
    bool fixed_prioirty_service_execution (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    ServiceLevels get_ServiceLevels (void) const;

    MultipleServiceRequests get_MultipleServiceRequests (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    RTRequirements parent_RTRequirements (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
