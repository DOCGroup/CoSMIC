// -*- C++ -*-

//============================================================================
/**
 * @file    OutEventPortEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_OUTEVENTPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_OUTEVENTPORTEND_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalPortEnd.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OutEventPortEnd_Impl;
  typedef OutEventPortEnd_Impl * OutEventPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr < OutEventPortEnd_Impl > OutEventPortEnd;

  /**
   * @class OutEventPortEnd_Impl
   *
   * Implementation for the OutEventPortEnd model element.
   */
  class PICML_Export OutEventPortEnd_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual ExternalPortEnd_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    OutEventPortEnd_Impl (void);

    // Initializing constructor.
    OutEventPortEnd_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~OutEventPortEnd_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src SendsTo connection.
    size_t src_SendsTo (std::vector <SendsTo> & items) const;

    /// Get the src EventSourceDelegate connection.
    size_t src_EventSourceDelegate (std::vector <EventSourceDelegate> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OutEventPortEnd.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_OUTEVENTPORTEND
