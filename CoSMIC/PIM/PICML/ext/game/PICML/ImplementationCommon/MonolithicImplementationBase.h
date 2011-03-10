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

#include "game/mga/FCO.h"
#include "PICML/ImplementationCommon/Implemenation.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MonolithicImplementationBase_Impl;
  typedef MonolithicImplementationBase_Impl * MonolithicImplementationBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MonolithicImplementationBase_Impl> MonolithicImplementationBase;

  class PICML_Export MonolithicImplementationBase_Impl :
    public virtual Implemenation_Impl,
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    MonolithicImplementationBase_Impl (void);

    /// Initializing constructor
    MonolithicImplementationBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~MonolithicImplementationBase_Impl (void) = 0;
    size_t in_MonolithDeployRequirement_connections (std::vector <MonolithDeployRequirement> & conns) const;
    size_t in_MonolithExecParameter_connections (std::vector <MonolithExecParameter> & conns) const;
    size_t in_MonolithprimaryArtifact_connections (std::vector <MonolithprimaryArtifact> & conns) const;

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
