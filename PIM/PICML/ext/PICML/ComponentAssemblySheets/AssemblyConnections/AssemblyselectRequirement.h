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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AssemblyselectRequirement_Impl;
  typedef AssemblyselectRequirement_Impl * AssemblyselectRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr < AssemblyselectRequirement_Impl > AssemblyselectRequirement;

  // Forward decl.
  class Visitor;

  /**
   * @class AssemblyselectRequirement_Impl
   *
   * Implementation for the AssemblyselectRequirement model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static AssemblyselectRequirement _create (const ComponentAssembly_in parent, AssemblyConfigPropertyEnd_in src, Requirement_in dst);
    ///@}

    // Default constructor.
    AssemblyselectRequirement_Impl (void);

    // Initializing constructor.
    AssemblyselectRequirement_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~AssemblyselectRequirement_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    AssemblyConfigPropertyEnd src_AssemblyConfigPropertyEnd (void) const;
    Requirement dst_Requirement (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "AssemblyselectRequirement.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYSELECTREQUIREMENT
