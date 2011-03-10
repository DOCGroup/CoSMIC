// -*- C++ -*-

//============================================================================
/**
 * @file    ProvidedRequestPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTDELEGATE_H_

#include "game/mga/Atom.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ProvidedRequestPortDelegate_Impl;
  typedef ProvidedRequestPortDelegate_Impl * ProvidedRequestPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ProvidedRequestPortDelegate_Impl> ProvidedRequestPortDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export ProvidedRequestPortDelegate_Impl :
    public virtual ProvidedRequestPortEnd_Impl,
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
    ProvidedRequestPortDelegate_Impl (void);

    /// Initializing constructor
    ProvidedRequestPortDelegate_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ProvidedRequestPortDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_FacetDelegate_connections (std::vector <FacetDelegate> & conns) const;

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
