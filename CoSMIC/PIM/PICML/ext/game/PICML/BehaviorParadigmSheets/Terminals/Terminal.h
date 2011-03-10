// -*- C++ -*-

//============================================================================
/**
 * @file    Terminal.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINAL_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINAL_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Terminal_Impl;
  typedef Terminal_Impl * Terminal_in;
  typedef ::GAME::Mga::Smart_Ptr <Terminal_Impl> Terminal;

  // Forward decl.
  class Visitor;

  class PICML_Export Terminal_Impl :
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
    Terminal_Impl (void);

    /// Initializing constructor
    Terminal_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~Terminal_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_TerminalEffect_connections (std::vector <TerminalEffect> & conns) const;
    size_t in_TerminalTransition_connections (std::vector <TerminalTransition> & conns) const;

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
