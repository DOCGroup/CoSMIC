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

#include "game/mga/Atom.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/SingleInputBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PeriodicEvent_Impl;
  typedef PeriodicEvent_Impl * PeriodicEvent_in;
  typedef ::GAME::Mga::Smart_Ptr <PeriodicEvent_Impl> PeriodicEvent;

  // Forward decl.
  class Visitor;

  class PICML_Export PeriodicEvent_Impl :
    public virtual SingleInputBase_Impl,
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
    PeriodicEvent_Impl (void);

    /// Initializing constructor
    PeriodicEvent_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~PeriodicEvent_Impl (void);

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

    /// Set the value of Distribution
    void Distribution (const std::string & val);

    /// Get the value of Distribution
    std::string Distribution (void) const;

    /// Set the value of Hertz
    void Hertz (const std::string & val);

    /// Get the value of Hertz
    std::string Hertz (void) const;
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
