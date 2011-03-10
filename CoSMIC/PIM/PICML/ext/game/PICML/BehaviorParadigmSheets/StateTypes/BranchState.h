// -*- C++ -*-

//============================================================================
/**
 * @file    BranchState.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHSTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHSTATE_H_

#include "game/mga/Atom.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BranchState_Impl;
  typedef BranchState_Impl * BranchState_in;
  typedef ::GAME::Mga::Smart_Ptr <BranchState_Impl> BranchState;

  // Forward decl.
  class Visitor;

  class PICML_Export BranchState_Impl :
    public virtual StateBase_Impl,
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
    BranchState_Impl (void);

    /// Initializing constructor
    BranchState_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~BranchState_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_BranchTransition_connections (std::vector <BranchTransition> & conns) const;

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
