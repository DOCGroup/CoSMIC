// -*- C++ -*-

//============================================================================
/**
 * @file    SimpleProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_SIMPLEPROPERTY_H_
#define _PICML_COMMON_SIMPLEPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/Property.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SimpleProperty_Impl;
  typedef SimpleProperty_Impl * SimpleProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < SimpleProperty_Impl > SimpleProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class SimpleProperty_Impl
   *
   * Implementation for the SimpleProperty model element.
   */
  class PICML_Export SimpleProperty_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual Property_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static SimpleProperty _create (const QueryInputAction_in parent);
    static SimpleProperty _create (const ActionBase_in parent);
    static SimpleProperty _create (const BehaviorInputAction_in parent);
    static SimpleProperty _create (const Path_in parent);
    static SimpleProperty _create (const RequirementBase_in parent);
    static SimpleProperty _create (const ComponentAssembly_in parent);
    static SimpleProperty _create (const ImplementationContainer_in parent);
    static SimpleProperty _create (const ComponentContainer_in parent);
    static SimpleProperty _create (const Paths_in parent);
    static SimpleProperty _create (const DeploymentPlan_in parent);
    static SimpleProperty _create (const ArtifactContainer_in parent);
    static SimpleProperty _create (const PackageConfigurationContainer_in parent);
    static SimpleProperty _create (const PackageContainer_in parent);
    static SimpleProperty _create (const Domain_in parent);
    ///@}

    // Default constructor.
    SimpleProperty_Impl (void);

    // Initializing constructor.
    SimpleProperty_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~SimpleProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Value
    void Value (const std::string & val);

    /// Get the value of Value
    std::string Value (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool MemberType_is_nil (void) const;
    MemberType refers_to_MemberType (void) const;
    void refers_to_MemberType (MemberType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SimpleProperty.inl"
#endif

#endif  // !defined _PICML_COMMON_SIMPLEPROPERTY
