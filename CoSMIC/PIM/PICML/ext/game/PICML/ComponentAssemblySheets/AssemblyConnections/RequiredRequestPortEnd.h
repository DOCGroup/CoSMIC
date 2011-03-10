// -*- C++ -*-

//============================================================================
/**
 * @file    RequiredRequestPortEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_REQUIREDREQUESTPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_REQUIREDREQUESTPORTEND_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequiredRequestPortEnd_Impl;
  typedef RequiredRequestPortEnd_Impl * RequiredRequestPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <RequiredRequestPortEnd_Impl> RequiredRequestPortEnd;

  class PICML_Export RequiredRequestPortEnd_Impl :
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
    RequiredRequestPortEnd_Impl (void);

    /// Initializing constructor
    RequiredRequestPortEnd_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~RequiredRequestPortEnd_Impl (void) = 0;
    size_t in_ConnectorToReceptacle_connections (std::vector <ConnectorToReceptacle> & conns) const;
    size_t in_Invoke_connections (std::vector <Invoke> & conns) const;
    size_t in_ReceptacleDelegate_connections (std::vector <ReceptacleDelegate> & conns) const;

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
