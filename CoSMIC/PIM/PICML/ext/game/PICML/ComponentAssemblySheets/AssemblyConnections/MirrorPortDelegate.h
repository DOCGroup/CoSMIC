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

#include "game/mga/Atom.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortInstanceBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MirrorPortDelegate_Impl;
  typedef MirrorPortDelegate_Impl * MirrorPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <MirrorPortDelegate_Impl> MirrorPortDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export MirrorPortDelegate_Impl :
    public virtual MirrorPortInstanceBase_Impl,
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    MirrorPortDelegate_Impl (void);

    /// Initializing constructor
    MirrorPortDelegate_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~MirrorPortDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_MirrorDelegate_connections (std::vector <MirrorDelegate> & conns) const;

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
