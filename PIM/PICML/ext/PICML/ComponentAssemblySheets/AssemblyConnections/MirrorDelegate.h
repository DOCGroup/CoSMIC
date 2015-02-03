// -*- C++ -*-

//============================================================================
/**
 * @file    MirrorDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MirrorDelegate_Impl;
  typedef MirrorDelegate_Impl * MirrorDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < MirrorDelegate_Impl > MirrorDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class MirrorDelegate_Impl
   *
   * Implementation for the MirrorDelegate model element.
   */
  class PICML_Export MirrorDelegate_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static MirrorDelegate _create (const ComponentAssembly_in parent, MirrorPortInstanceBase_in src, MirrorPortDelegate_in dst);
    ///@}

    // Default constructor.
    MirrorDelegate_Impl (void);

    // Initializing constructor.
    MirrorDelegate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~MirrorDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    MirrorPortInstanceBase src_MirrorPortInstanceBase (void) const;
    MirrorPortDelegate dst_MirrorPortDelegate (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "MirrorDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORDELEGATE
