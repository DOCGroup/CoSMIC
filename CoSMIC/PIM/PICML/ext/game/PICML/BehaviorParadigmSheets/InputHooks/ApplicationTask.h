// -*- C++ -*-

//============================================================================
/**
 * @file    ApplicationTask.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_APPLICATIONTASK_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_APPLICATIONTASK_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/SingleInputBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ApplicationTask_Impl;
  typedef ApplicationTask_Impl * ApplicationTask_in;
  typedef ::GAME::Mga::Smart_Ptr < ApplicationTask_Impl > ApplicationTask;

  // Forward decl.
  class Visitor;

  /**
   * @class ApplicationTask_Impl
   *
   * Implementation for the ApplicationTask model element.
   */
  class PICML_Export ApplicationTask_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual SingleInputBase_Impl
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
    static ApplicationTask _create (const TopLevelBehavior_in parent);
    ///@}

    // Default constructor.
    ApplicationTask_Impl (void);

    // Initializing constructor.
    ApplicationTask_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ApplicationTask_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
  };
}

#if defined (__GAME_INLINE__)
#include "ApplicationTask.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_APPLICATIONTASK
