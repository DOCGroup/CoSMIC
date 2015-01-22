// -*- C++ -*-

//============================================================================
/**
 * @file    ComplexProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_COMPLEXPROPERTY_H_
#define _PICML_COMMON_COMPLEXPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/Property.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComplexProperty_Impl;
  typedef ComplexProperty_Impl * ComplexProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < ComplexProperty_Impl > ComplexProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class ComplexProperty_Impl
   *
   * Implementation for the ComplexProperty model element.
   */
  class PICML_Export ComplexProperty_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Property_Impl
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
    static ComplexProperty _create (const QueryInputAction_in parent);
    static ComplexProperty _create (const ActionBase_in parent);
    static ComplexProperty _create (const BehaviorInputAction_in parent);
    static ComplexProperty _create (const Path_in parent);
    static ComplexProperty _create (const RequirementBase_in parent);
    static ComplexProperty _create (const ComponentAssembly_in parent);
    static ComplexProperty _create (const ImplementationContainer_in parent);
    static ComplexProperty _create (const ComponentContainer_in parent);
    static ComplexProperty _create (const Paths_in parent);
    static ComplexProperty _create (const DeploymentPlan_in parent);
    static ComplexProperty _create (const ArtifactContainer_in parent);
    static ComplexProperty _create (const PackageConfigurationContainer_in parent);
    static ComplexProperty _create (const PackageContainer_in parent);
    static ComplexProperty _create (const Domain_in parent);
    ///@}

    // Default constructor.
    ComplexProperty_Impl (void);

    // Initializing constructor.
    ComplexProperty_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ComplexProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ComplexTypeReference (void) const;
    ComplexTypeReference get_ComplexTypeReference (void) const;
    size_t get_DataValueContainers (std::vector <DataValueContainer> & items) const;
    ::GAME::Mga::Collection_T <DataValueContainer> get_DataValueContainers (void) const;

    size_t get_DataValues (std::vector <DataValue> & items) const;
    ::GAME::Mga::Collection_T <DataValue> get_DataValues (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComplexProperty.inl"
#endif

#endif  // !defined _PICML_COMMON_COMPLEXPROPERTY
