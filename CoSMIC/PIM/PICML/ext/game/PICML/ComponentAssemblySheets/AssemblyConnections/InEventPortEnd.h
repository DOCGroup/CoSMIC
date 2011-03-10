// -*- C++ -*-

//============================================================================
/**
 * @file    InEventPortEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INEVENTPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INEVENTPORTEND_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InEventPortEnd_Impl;
  typedef InEventPortEnd_Impl * InEventPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <InEventPortEnd_Impl> InEventPortEnd;

  class PICML_Export InEventPortEnd_Impl :
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
    InEventPortEnd_Impl (void);

    /// Initializing constructor
    InEventPortEnd_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~InEventPortEnd_Impl (void) = 0;
    size_t in_EventSinkDelegate_connections (std::vector <EventSinkDelegate> & conns) const;
    size_t in_SendsTo_connections (std::vector <SendsTo> & conns) const;

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
