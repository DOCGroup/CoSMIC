// -*- C++ -*-

//============================================================================
/**
 * @file    ReceptacleDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_RECEPTACLEDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_RECEPTACLEDELEGATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ReceptacleDelegate_Impl;
  typedef ReceptacleDelegate_Impl * ReceptacleDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <ReceptacleDelegate_Impl> ReceptacleDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export ReceptacleDelegate_Impl :
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
    ReceptacleDelegate_Impl (void);

    /// Initializing constructor
    ReceptacleDelegate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ReceptacleDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src RequiredRequestPortDelegate connection point.
    RequiredRequestPortDelegate src_RequiredRequestPortDelegate (void);

    /// Get the dst RequiredRequestPortEnd connection point.
    RequiredRequestPortEnd dst_RequiredRequestPortEnd (void);

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
