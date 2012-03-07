// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_IMPLEMENTATIONCONTAINER_H_
#define _PICML_IMPLEMENTATIONCOMMON_IMPLEMENTATIONCONTAINER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationContainer_Impl;
  typedef ImplementationContainer_Impl * ImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < ImplementationContainer_Impl > ImplementationContainer;

  /**
   * @class ImplementationContainer_Impl
   *
   * Implementation for the ImplementationContainer model element.
   */
  class PICML_Export ImplementationContainer_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    ImplementationContainer_Impl (void);

    // Initializing constructor.
    ImplementationContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ImplementationContainer_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ImplementationRequirements (std::vector <ImplementationRequirement> & items) const;
    ::GAME::Mga::Iterator <ImplementationRequirement> get_ImplementationRequirements (void) const;

    size_t get_Propertys (std::vector <Property> & items) const;
    ::GAME::Mga::Iterator <Property> get_Propertys (void) const;

    size_t get_ImplementationArtifactReferences (std::vector <ImplementationArtifactReference> & items) const;
    ::GAME::Mga::Iterator <ImplementationArtifactReference> get_ImplementationArtifactReferences (void) const;

    size_t get_ConfigPropertys (std::vector <ConfigProperty> & items) const;
    ::GAME::Mga::Iterator <ConfigProperty> get_ConfigPropertys (void) const;

    size_t get_InfoPropertys (std::vector <InfoProperty> & items) const;
    ::GAME::Mga::Iterator <InfoProperty> get_InfoPropertys (void) const;

    size_t get_MonolithprimaryArtifacts (std::vector <MonolithprimaryArtifact> & items) const;
    ::GAME::Mga::Iterator <MonolithprimaryArtifact> get_MonolithprimaryArtifacts (void) const;

    size_t get_MonolithDeployRequirements (std::vector <MonolithDeployRequirement> & items) const;
    ::GAME::Mga::Iterator <MonolithDeployRequirement> get_MonolithDeployRequirements (void) const;

    size_t get_MonolithExecParameters (std::vector <MonolithExecParameter> & items) const;
    ::GAME::Mga::Iterator <MonolithExecParameter> get_MonolithExecParameters (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ImplementationContainer.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_IMPLEMENTATIONCONTAINER
