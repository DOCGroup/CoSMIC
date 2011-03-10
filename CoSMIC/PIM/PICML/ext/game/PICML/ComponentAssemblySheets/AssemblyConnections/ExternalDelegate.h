// -*- C++ -*-

//============================================================================
/**
 * @file    ExternalDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALDELEGATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExternalDelegate_Impl;
  typedef ExternalDelegate_Impl * ExternalDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ExternalDelegate_Impl> ExternalDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export ExternalDelegate_Impl :
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
    ExternalDelegate_Impl (void);

    /// Initializing constructor
    ExternalDelegate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ExternalDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src ExternalPort connection point.
    ExternalPort src_ExternalPort (void);

    /// Get the dst ExternalPortEnd connection point.
    ExternalPortEnd dst_ExternalPortEnd (void);

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
