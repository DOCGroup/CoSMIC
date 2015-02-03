// -*- C++ -*-

//============================================================================
/**
 * @file    MirrorPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORPORTDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortInstanceBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MirrorPortDelegate_Impl;
  typedef MirrorPortDelegate_Impl * MirrorPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < MirrorPortDelegate_Impl > MirrorPortDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class MirrorPortDelegate_Impl
   *
   * Implementation for the MirrorPortDelegate model element.
   */
  class PICML_Export MirrorPortDelegate_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual MirrorPortInstanceBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static MirrorPortDelegate _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    MirrorPortDelegate_Impl (void);

    // Initializing constructor.
    MirrorPortDelegate_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~MirrorPortDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst MirrorDelegate connection.
    size_t dst_of_MirrorDelegate (std::vector <MirrorDelegate> & items) const;
    GAME::Mga::Collection_T <MirrorDelegate> dst_of_MirrorDelegate (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MirrorPortDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORPORTDELEGATE
