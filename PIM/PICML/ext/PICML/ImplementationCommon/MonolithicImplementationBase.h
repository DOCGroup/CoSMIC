// -*- C++ -*-

//============================================================================
/**
 * @file    MonolithicImplementationBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_MONOLITHICIMPLEMENTATIONBASE_H_
#define _PICML_IMPLEMENTATIONCOMMON_MONOLITHICIMPLEMENTATIONBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ImplementationCommon/Implemenation.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MonolithicImplementationBase_Impl;
  typedef MonolithicImplementationBase_Impl * MonolithicImplementationBase_in;
  typedef ::GAME::Mga::Smart_Ptr < MonolithicImplementationBase_Impl > MonolithicImplementationBase;

  /**
   * @class MonolithicImplementationBase_Impl
   *
   * Implementation for the MonolithicImplementationBase model element.
   */
  class PICML_Export MonolithicImplementationBase_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual Implemenation_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    MonolithicImplementationBase_Impl (void);

    // Initializing constructor.
    MonolithicImplementationBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~MonolithicImplementationBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src MonolithExecParameter connection.
    size_t src_of_MonolithExecParameter (std::vector <MonolithExecParameter> & items) const;
    GAME::Mga::Collection_T <MonolithExecParameter> src_of_MonolithExecParameter (void) const;

    /// Get the src MonolithDeployRequirement connection.
    size_t src_of_MonolithDeployRequirement (std::vector <MonolithDeployRequirement> & items) const;
    GAME::Mga::Collection_T <MonolithDeployRequirement> src_of_MonolithDeployRequirement (void) const;

    /// Get the src MonolithprimaryArtifact connection.
    size_t src_of_MonolithprimaryArtifact (std::vector <MonolithprimaryArtifact> & items) const;
    GAME::Mga::Collection_T <MonolithprimaryArtifact> src_of_MonolithprimaryArtifact (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MonolithicImplementationBase.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_MONOLITHICIMPLEMENTATIONBASE
