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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalPortEnd.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InEventPortEnd_Impl;
  typedef InEventPortEnd_Impl * InEventPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr < InEventPortEnd_Impl > InEventPortEnd;

  /**
   * @class InEventPortEnd_Impl
   *
   * Implementation for the InEventPortEnd model element.
   */
  class PICML_Export InEventPortEnd_Impl :
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
    InEventPortEnd_Impl (void);

    // Initializing constructor.
    InEventPortEnd_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~InEventPortEnd_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst SendsTo connection.
    size_t dst_SendsTo (std::vector <SendsTo> & items) const;

    /// Get the dst EventSinkDelegate connection.
    size_t dst_EventSinkDelegate (std::vector <EventSinkDelegate> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "InEventPortEnd.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INEVENTPORTEND
