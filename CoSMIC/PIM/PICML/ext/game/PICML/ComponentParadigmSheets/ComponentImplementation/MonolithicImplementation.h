// -*- C++ -*-

//============================================================================
/**
 * @file    MonolithicImplementation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_MONOLITHICIMPLEMENTATION_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_MONOLITHICIMPLEMENTATION_H_

#include "game/mga/Atom.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MonolithicImplementation_Impl;
  typedef MonolithicImplementation_Impl * MonolithicImplementation_in;
  typedef ::GAME::Mga::Smart_Ptr <MonolithicImplementation_Impl> MonolithicImplementation;

  // Forward decl.
  class Visitor;

  class PICML_Export MonolithicImplementation_Impl :
    public virtual ComponentImplementation_Impl,
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
    MonolithicImplementation_Impl (void);

    /// Initializing constructor
    MonolithicImplementation_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~MonolithicImplementation_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

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
