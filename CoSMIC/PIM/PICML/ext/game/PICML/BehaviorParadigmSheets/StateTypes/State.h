// -*- C++ -*-

//============================================================================
/**
 * @file    State.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATE_H_

#include "game/mga/Atom.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class State_Impl;
  typedef State_Impl * State_in;
  typedef ::GAME::Mga::Smart_Ptr <State_Impl> State;

  // Forward decl.
  class Visitor;

  class PICML_Export State_Impl :
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
    State_Impl (void);

    /// Initializing constructor
    State_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~State_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_Transition_connections (std::vector <Transition> & conns) const;

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
