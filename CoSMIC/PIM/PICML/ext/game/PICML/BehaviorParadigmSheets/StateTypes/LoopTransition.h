// -*- C++ -*-

//============================================================================
/**
 * @file    LoopTransition.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_LOOPTRANSITION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_LOOPTRANSITION_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LoopTransition_Impl;
  typedef LoopTransition_Impl * LoopTransition_in;
  typedef ::GAME::Mga::Smart_Ptr <LoopTransition_Impl> LoopTransition;

  // Forward decl.
  class Visitor;

  class PICML_Export LoopTransition_Impl :
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
    LoopTransition_Impl (void);

    /// Initializing constructor
    LoopTransition_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~LoopTransition_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src LoopState connection point.
    LoopState src_LoopState (void);

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
