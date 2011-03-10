// -*- C++ -*-

//============================================================================
/**
 * @file    ForState.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_FORSTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_FORSTATE_H_

#include "game/mga/Atom.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ForState_Impl;
  typedef ForState_Impl * ForState_in;
  typedef ::GAME::Mga::Smart_Ptr <ForState_Impl> ForState;

  // Forward decl.
  class Visitor;

  class PICML_Export ForState_Impl :
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
    ForState_Impl (void);

    /// Initializing constructor
    ForState_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ForState_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of IncrementExpr
    void IncrementExpr (const std::string & val);

    /// Get the value of IncrementExpr
    std::string IncrementExpr (void) const;

    /// Set the value of InitialCondition
    void InitialCondition (const std::string & val);

    /// Get the value of InitialCondition
    std::string InitialCondition (void) const;
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
