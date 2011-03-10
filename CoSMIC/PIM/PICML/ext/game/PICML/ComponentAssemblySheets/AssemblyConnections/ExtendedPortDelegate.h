// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDPORTDELEGATE_H_

#include "game/mga/Atom.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortInstanceBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPortDelegate_Impl;
  typedef ExtendedPortDelegate_Impl * ExtendedPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPortDelegate_Impl> ExtendedPortDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export ExtendedPortDelegate_Impl :
    public virtual ExtendedPortInstanceBase_Impl,
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
    ExtendedPortDelegate_Impl (void);

    /// Initializing constructor
    ExtendedPortDelegate_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ExtendedPortDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_ExtendedDelegate_connections (std::vector <ExtendedDelegate> & conns) const;

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
