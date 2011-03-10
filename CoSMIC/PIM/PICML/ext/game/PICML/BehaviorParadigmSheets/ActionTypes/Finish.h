// -*- C++ -*-

//============================================================================
/**
 * @file    Finish.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_FINISH_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_FINISH_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Finish_Impl;
  typedef Finish_Impl * Finish_in;
  typedef ::GAME::Mga::Smart_Ptr <Finish_Impl> Finish;

  // Forward decl.
  class Visitor;

  class PICML_Export Finish_Impl :
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
    Finish_Impl (void);

    /// Initializing constructor
    Finish_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Finish_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src StateBase connection point.
    StateBase src_StateBase (void);

    /// Get the dst BehaviorInputAction connection point.
    BehaviorInputAction dst_BehaviorInputAction (void);

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
