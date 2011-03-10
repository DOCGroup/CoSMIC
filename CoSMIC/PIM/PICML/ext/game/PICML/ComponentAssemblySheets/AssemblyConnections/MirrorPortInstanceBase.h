// -*- C++ -*-

//============================================================================
/**
 * @file    MirrorPortInstanceBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORPORTINSTANCEBASE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORPORTINSTANCEBASE_H_

#include "game/mga/FCO.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendPortEnd.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MirrorPortInstanceBase_Impl;
  typedef MirrorPortInstanceBase_Impl * MirrorPortInstanceBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MirrorPortInstanceBase_Impl> MirrorPortInstanceBase;

  class PICML_Export MirrorPortInstanceBase_Impl :
    public virtual ExtendPortEnd_Impl,
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    MirrorPortInstanceBase_Impl (void);

    /// Initializing constructor
    MirrorPortInstanceBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~MirrorPortInstanceBase_Impl (void) = 0;
    size_t in_MirrorDelegate_connections (std::vector <MirrorDelegate> & conns) const;

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
