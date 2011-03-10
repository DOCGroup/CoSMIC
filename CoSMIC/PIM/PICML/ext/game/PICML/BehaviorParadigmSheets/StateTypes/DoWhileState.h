// -*- C++ -*-

//============================================================================
/**
 * @file    DoWhileState.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_DOWHILESTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_DOWHILESTATE_H_

#include "game/mga/Atom.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DoWhileState_Impl;
  typedef DoWhileState_Impl * DoWhileState_in;
  typedef ::GAME::Mga::Smart_Ptr <DoWhileState_Impl> DoWhileState;

  // Forward decl.
  class Visitor;

  class PICML_Export DoWhileState_Impl :
    public virtual LoopState_Impl,
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
    DoWhileState_Impl (void);

    /// Initializing constructor
    DoWhileState_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~DoWhileState_Impl (void);

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
