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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalPortEnd.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequiredRequestPortEnd_Impl;
  typedef RequiredRequestPortEnd_Impl * RequiredRequestPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr < RequiredRequestPortEnd_Impl > RequiredRequestPortEnd;

  /**
   * @class RequiredRequestPortEnd_Impl
   *
   * Implementation for the RequiredRequestPortEnd model element.
   */
  class PICML_Export RequiredRequestPortEnd_Impl :
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    RequiredRequestPortEnd_Impl (void);

    // Initializing constructor.
    RequiredRequestPortEnd_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~RequiredRequestPortEnd_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ConnectorToReceptacle connection.
    size_t src_of_ConnectorToReceptacle (std::vector <ConnectorToReceptacle> & items) const;
    GAME::Mga::Collection_T <ConnectorToReceptacle> src_of_ConnectorToReceptacle (void) const;

    /// Get the src Invoke connection.
    size_t src_of_Invoke (std::vector <Invoke> & items) const;
    GAME::Mga::Collection_T <Invoke> src_of_Invoke (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ReceptacleDelegate connection.
    size_t dst_of_ReceptacleDelegate (std::vector <ReceptacleDelegate> & items) const;
    GAME::Mga::Collection_T <ReceptacleDelegate> dst_of_ReceptacleDelegate (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "RequiredRequestPortEnd.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_REQUIREDREQUESTPORTEND
