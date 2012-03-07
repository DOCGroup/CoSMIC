// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationRequirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_IMPLEMENTATIONREQUIREMENT_H_
#define _PICML_COMMON_IMPLEMENTATIONREQUIREMENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/RequirementBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationRequirement_Impl;
  typedef ImplementationRequirement_Impl * ImplementationRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr < ImplementationRequirement_Impl > ImplementationRequirement;

  // Forward decl.
  class Visitor;

  /**
   * @class ImplementationRequirement_Impl
   *
   * Implementation for the ImplementationRequirement model element.
   */
  class PICML_Export ImplementationRequirement_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual RequirementBase_Impl
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
    static ImplementationRequirement _create (const ImplementationContainer_in parent);
    static ImplementationRequirement _create (const RequirementBase_in parent);
    ///@}

    // Default constructor.
    ImplementationRequirement_Impl (void);

    // Initializing constructor.
    ImplementationRequirement_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ImplementationRequirement_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of ResourceUsageKind
    void ResourceUsageKind (const std::string & val);

    /// Get the value of ResourceUsageKind
    std::string ResourceUsageKind (void) const;

    /// Set the value of resourcePort
    void resourcePort (const std::string & val);

    /// Get the value of resourcePort
    std::string resourcePort (void) const;

    /// Set the value of componentPort
    void componentPort (const std::string & val);

    /// Get the value of componentPort
    std::string componentPort (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst MonolithDeployRequirement connection.
    size_t dst_MonolithDeployRequirement (std::vector <MonolithDeployRequirement> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ImplementationRequirement.inl"
#endif

#endif  // !defined _PICML_COMMON_IMPLEMENTATIONREQUIREMENT
