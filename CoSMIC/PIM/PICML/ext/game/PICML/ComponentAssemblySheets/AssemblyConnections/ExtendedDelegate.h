// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDDELEGATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedDelegate_Impl;
  typedef ExtendedDelegate_Impl * ExtendedDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedDelegate_Impl> ExtendedDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export ExtendedDelegate_Impl :
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
    ExtendedDelegate_Impl (void);

    /// Initializing constructor
    ExtendedDelegate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ExtendedDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src ExtendedPortInstanceBase connection point.
    ExtendedPortInstanceBase src_ExtendedPortInstanceBase (void);

    /// Get the dst ExtendedPortDelegate connection point.
    ExtendedPortDelegate dst_ExtendedPortDelegate (void);

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
