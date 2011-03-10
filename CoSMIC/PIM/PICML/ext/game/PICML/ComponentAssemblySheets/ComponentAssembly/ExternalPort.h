// -*- C++ -*-

//============================================================================
/**
 * @file    ExternalPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_EXTERNALPORT_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_EXTERNALPORT_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExternalPort_Impl;
  typedef ExternalPort_Impl * ExternalPort_in;
  typedef ::GAME::Mga::Smart_Ptr <ExternalPort_Impl> ExternalPort;

  // Forward decl.
  class Visitor;

  class PICML_Export ExternalPort_Impl :
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
    ExternalPort_Impl (void);

    /// Initializing constructor
    ExternalPort_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ExternalPort_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ExternalPort _create (const ComponentAssembly_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
