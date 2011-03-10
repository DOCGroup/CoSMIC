// -*- C++ -*-

//============================================================================
/**
 * @file    WhileState.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_WHILESTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_WHILESTATE_H_

#include "game/mga/Atom.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WhileState_Impl;
  typedef WhileState_Impl * WhileState_in;
  typedef ::GAME::Mga::Smart_Ptr <WhileState_Impl> WhileState;

  // Forward decl.
  class Visitor;

  class PICML_Export WhileState_Impl :
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
    WhileState_Impl (void);

    /// Initializing constructor
    WhileState_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~WhileState_Impl (void);

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
