// -*- C++ -*-

//============================================================================
/**
 * @file    MirrorDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORDELEGATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MirrorDelegate_Impl;
  typedef MirrorDelegate_Impl * MirrorDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <MirrorDelegate_Impl> MirrorDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export MirrorDelegate_Impl :
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
    MirrorDelegate_Impl (void);

    /// Initializing constructor
    MirrorDelegate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~MirrorDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src MirrorPortInstanceBase connection point.
    MirrorPortInstanceBase src_MirrorPortInstanceBase (void);

    /// Get the dst MirrorPortDelegate connection point.
    MirrorPortDelegate dst_MirrorPortDelegate (void);

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
