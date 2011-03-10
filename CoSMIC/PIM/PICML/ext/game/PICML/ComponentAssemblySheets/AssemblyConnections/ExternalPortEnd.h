// -*- C++ -*-

//============================================================================
/**
 * @file    ExternalPortEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALPORTEND_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExternalPortEnd_Impl;
  typedef ExternalPortEnd_Impl * ExternalPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <ExternalPortEnd_Impl> ExternalPortEnd;

  class PICML_Export ExternalPortEnd_Impl :
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
    ExternalPortEnd_Impl (void);

    /// Initializing constructor
    ExternalPortEnd_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ExternalPortEnd_Impl (void) = 0;
    size_t in_ExternalDelegate_connections (std::vector <ExternalDelegate> & conns) const;

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
