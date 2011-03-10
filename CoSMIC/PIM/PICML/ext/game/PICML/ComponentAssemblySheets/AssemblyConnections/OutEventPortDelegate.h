// -*- C++ -*-

//============================================================================
/**
 * @file    OutEventPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_OUTEVENTPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_OUTEVENTPORTDELEGATE_H_

#include "game/mga/Atom.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortEnd.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OutEventPortDelegate_Impl;
  typedef OutEventPortDelegate_Impl * OutEventPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <OutEventPortDelegate_Impl> OutEventPortDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export OutEventPortDelegate_Impl :
    public virtual OutEventPortEnd_Impl,
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
    OutEventPortDelegate_Impl (void);

    /// Initializing constructor
    OutEventPortDelegate_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~OutEventPortDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_EventSourceDelegate_connections (std::vector <EventSourceDelegate> & conns) const;

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
