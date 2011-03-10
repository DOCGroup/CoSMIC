// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplementation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATION_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATION_H_

#include "game/mga/Atom.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplementation_Impl;
  typedef ConnectorImplementation_Impl * ConnectorImplementation_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorImplementation_Impl> ConnectorImplementation;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorImplementation_Impl :
    public virtual MonolithicImplementationBase_Impl,
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
    ConnectorImplementation_Impl (void);

    /// Initializing constructor
    ConnectorImplementation_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ConnectorImplementation_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorImplementation _create (const ConnectorImplementationContainer_in parent);
    ///@}
    size_t in_ConnectorImplements_connections (std::vector <ConnectorImplements> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorImplementationContainer parent_ConnectorImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
