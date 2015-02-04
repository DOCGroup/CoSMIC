// -*- C++ -*-

//============================================================================
/**
 * @file    PeriodicEvent.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_PERIODICEVENT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_PERIODICEVENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/SingleInputBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PeriodicEvent_Impl;
  typedef PeriodicEvent_Impl * PeriodicEvent_in;
  typedef ::GAME::Mga::Smart_Ptr < PeriodicEvent_Impl > PeriodicEvent;

  // Forward decl.
  class Visitor;

  /**
   * @class PeriodicEvent_Impl
   *
   * Implementation for the PeriodicEvent model element.
   */
  class PICML_Export PeriodicEvent_Impl :
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PeriodicEvent _create (const TopLevelBehavior_in parent);
    ///@}

    // Default constructor.
    PeriodicEvent_Impl (void);

    // Initializing constructor.
    PeriodicEvent_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~PeriodicEvent_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelBehavior parent_TopLevelBehavior (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Hertz
    void Hertz (const std::string & val);

    /// Get the value of Hertz
    std::string Hertz (void) const;

    /// Set the value of Distribution
    void Distribution (const std::string & val);

    /// Get the value of Distribution
    std::string Distribution (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PeriodicEvent.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_PERIODICEVENT
