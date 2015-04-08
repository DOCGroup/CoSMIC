// -*- C++ -*-

//============================================================================
/**
 * @file    ServiceProvider.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_REALTIMEREQUIREMENTS_SERVICEPROVIDER_H_
#define _PICML_REALTIMEREQUIREMENTS_SERVICEPROVIDER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ServiceProvider_Impl;
  typedef ServiceProvider_Impl * ServiceProvider_in;
  typedef ::GAME::Mga::Smart_Ptr < ServiceProvider_Impl > ServiceProvider;

  // Forward decl.
  class Visitor;

  /**
   * @class ServiceProvider_Impl
   *
   * Implementation for the ServiceProvider model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ServiceProvider _create (const RTRequirements_in parent);
    ///@}

    // Default constructor.
    ServiceProvider_Impl (void);

    // Initializing constructor.
    ServiceProvider_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ServiceProvider_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RTRequirements parent_RTRequirements (void);
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

    bool has_ServiceLevels (void) const;
    ServiceLevels get_ServiceLevels (void) const;

    bool has_MultipleServiceRequests (void) const;
    MultipleServiceRequests get_MultipleServiceRequests (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ServiceProvider.inl"
#endif

#endif  // !defined _PICML_REALTIMEREQUIREMENTS_SERVICEPROVIDER
