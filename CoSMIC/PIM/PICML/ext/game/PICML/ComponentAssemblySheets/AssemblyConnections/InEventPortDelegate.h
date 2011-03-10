// -*- C++ -*-

//============================================================================
/**
 * @file    InEventPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INEVENTPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INEVENTPORTDELEGATE_H_

#include "game/mga/Atom.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortEnd.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InEventPortDelegate_Impl;
  typedef InEventPortDelegate_Impl * InEventPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <InEventPortDelegate_Impl> InEventPortDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export InEventPortDelegate_Impl :
    public virtual InEventPortEnd_Impl,
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
    InEventPortDelegate_Impl (void);

    /// Initializing constructor
    InEventPortDelegate_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~InEventPortDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_EventSinkDelegate_connections (std::vector <EventSinkDelegate> & conns) const;

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
