// -*- C++ -*-

//============================================================================
/**
 * @file    Environment.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_ENVIRONMENT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_ENVIRONMENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInputBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Environment_Impl;
  typedef Environment_Impl * Environment_in;
  typedef ::GAME::Mga::Smart_Ptr < Environment_Impl > Environment;

  // Forward decl.
  class Visitor;

  /**
   * @class Environment_Impl
   *
   * Implementation for the Environment model element.
   */
  class PICML_Export Environment_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual MultiInputBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static Environment _create (const TopLevelBehavior_in parent);
    ///@}

    // Default constructor.
    Environment_Impl (void);

    // Initializing constructor.
    Environment_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Environment_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelBehavior parent_TopLevelBehavior (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Environment.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_ENVIRONMENT
