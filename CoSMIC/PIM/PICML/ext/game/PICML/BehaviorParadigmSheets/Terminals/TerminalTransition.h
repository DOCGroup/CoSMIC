// -*- C++ -*-

//============================================================================
/**
 * @file    TerminalTransition.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINALTRANSITION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINALTRANSITION_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TerminalTransition_Impl;
  typedef TerminalTransition_Impl * TerminalTransition_in;
  typedef ::GAME::Mga::Smart_Ptr <TerminalTransition_Impl> TerminalTransition;

  // Forward decl.
  class Visitor;

  class PICML_Export TerminalTransition_Impl :
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
    TerminalTransition_Impl (void);

    /// Initializing constructor
    TerminalTransition_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~TerminalTransition_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src State connection point.
    State src_State (void);

    /// Get the dst Terminal connection point.
    Terminal dst_Terminal (void);

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
