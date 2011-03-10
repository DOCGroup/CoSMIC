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

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationContainer_Impl;
  typedef ImplementationContainer_Impl * ImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationContainer_Impl> ImplementationContainer;

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

    /// Default constructor
    ImplementationContainer_Impl (void);

    /// Initializing constructor
    ImplementationContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ImplementationContainer_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_MonolithDeployRequirements (std::vector <MonolithDeployRequirement> & items) const;
    size_t get_InfoPropertys (std::vector <InfoProperty> & items) const;
    size_t get_ImplementationRequirements (std::vector <ImplementationRequirement> & items) const;
    size_t get_ImplementationArtifactReferences (std::vector <ImplementationArtifactReference> & items) const;
    size_t get_MonolithExecParameters (std::vector <MonolithExecParameter> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;
    size_t get_ConfigPropertys (std::vector <ConfigProperty> & items) const;
    size_t get_MonolithprimaryArtifacts (std::vector <MonolithprimaryArtifact> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
