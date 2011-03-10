// -*- C++ -*-

//============================================================================
/**
 * @file    MonolithDeployRequirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_MONOLITHDEPLOYREQUIREMENT_H_
#define _PICML_IMPLEMENTATIONCOMMON_MONOLITHDEPLOYREQUIREMENT_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MonolithDeployRequirement_Impl;
  typedef MonolithDeployRequirement_Impl * MonolithDeployRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <MonolithDeployRequirement_Impl> MonolithDeployRequirement;

  // Forward decl.
  class Visitor;

  class PICML_Export MonolithDeployRequirement_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    MonolithDeployRequirement_Impl (void);

    /// Initializing constructor
    MonolithDeployRequirement_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~MonolithDeployRequirement_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static MonolithDeployRequirement _create (const ImplementationContainer_in parent);
    ///@}

    /// Get the src MonolithicImplementationBase connection point.
    MonolithicImplementationBase src_MonolithicImplementationBase (void);

    /// Get the dst ImplementationRequirement connection point.
    ImplementationRequirement dst_ImplementationRequirement (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationContainer parent_ImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
