// -*- C++ -*-

//============================================================================
/**
 * @file    ProvidedRequestPortEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTEND_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ProvidedRequestPortEnd_Impl;
  typedef ProvidedRequestPortEnd_Impl * ProvidedRequestPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <ProvidedRequestPortEnd_Impl> ProvidedRequestPortEnd;

  class PICML_Export ProvidedRequestPortEnd_Impl :
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
    ProvidedRequestPortEnd_Impl (void);

    /// Initializing constructor
    ProvidedRequestPortEnd_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ProvidedRequestPortEnd_Impl (void) = 0;
    size_t in_FacetDelegate_connections (std::vector <FacetDelegate> & conns) const;
    size_t in_Invoke_connections (std::vector <Invoke> & conns) const;
    size_t in_ConnectorToFacet_connections (std::vector <ConnectorToFacet> & conns) const;

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
