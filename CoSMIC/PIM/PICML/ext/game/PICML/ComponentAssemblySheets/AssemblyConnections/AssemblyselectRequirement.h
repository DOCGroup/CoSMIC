// -*- C++ -*-

//============================================================================
/**
 * @file    AssemblyselectRequirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYSELECTREQUIREMENT_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYSELECTREQUIREMENT_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AssemblyselectRequirement_Impl;
  typedef AssemblyselectRequirement_Impl * AssemblyselectRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <AssemblyselectRequirement_Impl> AssemblyselectRequirement;

  // Forward decl.
  class Visitor;

  class PICML_Export AssemblyselectRequirement_Impl :
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
    AssemblyselectRequirement_Impl (void);

    /// Initializing constructor
    AssemblyselectRequirement_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~AssemblyselectRequirement_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src AssemblyConfigPropertyEnd connection point.
    AssemblyConfigPropertyEnd src_AssemblyConfigPropertyEnd (void);

    /// Get the dst Requirement connection point.
    Requirement dst_Requirement (void);

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
