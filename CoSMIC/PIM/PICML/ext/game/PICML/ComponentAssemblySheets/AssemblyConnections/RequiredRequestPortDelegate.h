// -*- C++ -*-

//============================================================================
/**
 * @file    RequiredRequestPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_REQUIREDREQUESTPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_REQUIREDREQUESTPORTDELEGATE_H_

#include "game/mga/Atom.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequiredRequestPortDelegate_Impl;
  typedef RequiredRequestPortDelegate_Impl * RequiredRequestPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <RequiredRequestPortDelegate_Impl> RequiredRequestPortDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export RequiredRequestPortDelegate_Impl :
    public virtual RequiredRequestPortEnd_Impl,
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
    RequiredRequestPortDelegate_Impl (void);

    /// Initializing constructor
    RequiredRequestPortDelegate_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~RequiredRequestPortDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_ReceptacleDelegate_connections (std::vector <ReceptacleDelegate> & conns) const;

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
