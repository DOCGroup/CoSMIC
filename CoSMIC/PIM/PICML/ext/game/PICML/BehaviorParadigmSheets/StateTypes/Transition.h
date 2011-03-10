// -*- C++ -*-

//============================================================================
/**
 * @file    Transition.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_TRANSITION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_TRANSITION_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Transition_Impl;
  typedef Transition_Impl * Transition_in;
  typedef ::GAME::Mga::Smart_Ptr <Transition_Impl> Transition;

  // Forward decl.
  class Visitor;

  class PICML_Export Transition_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Transition_Impl (void);

    /// Initializing constructor
    Transition_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Transition_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src State connection point.
    State src_State (void);

    /// Get the dst ActionBase connection point.
    ActionBase dst_ActionBase (void);

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
