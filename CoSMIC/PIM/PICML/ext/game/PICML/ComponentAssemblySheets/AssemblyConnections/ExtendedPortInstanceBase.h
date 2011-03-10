// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPortInstanceBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDPORTINSTANCEBASE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDPORTINSTANCEBASE_H_

#include "game/mga/FCO.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendPortEnd.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPortInstanceBase_Impl;
  typedef ExtendedPortInstanceBase_Impl * ExtendedPortInstanceBase_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPortInstanceBase_Impl> ExtendedPortInstanceBase;

  class PICML_Export ExtendedPortInstanceBase_Impl :
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
    ExtendedPortInstanceBase_Impl (void);

    /// Initializing constructor
    ExtendedPortInstanceBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ExtendedPortInstanceBase_Impl (void) = 0;
    size_t in_ExtendedDelegate_connections (std::vector <ExtendedDelegate> & conns) const;

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
