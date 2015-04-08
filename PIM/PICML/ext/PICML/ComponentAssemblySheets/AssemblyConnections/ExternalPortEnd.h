// -*- C++ -*-

//============================================================================
/**
 * @file    ExternalPortEnd.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALPORTEND_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExternalPortEnd_Impl;
  typedef ExternalPortEnd_Impl * ExternalPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr < ExternalPortEnd_Impl > ExternalPortEnd;

  /**
   * @class ExternalPortEnd_Impl
   *
   * Implementation for the ExternalPortEnd model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    ExternalPortEnd_Impl (void);

    // Initializing constructor.
    ExternalPortEnd_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ExternalPortEnd_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ExternalDelegate connection.
    size_t dst_of_ExternalDelegate (std::vector <ExternalDelegate> & items) const;
    GAME::Mga::Collection_T <ExternalDelegate> dst_of_ExternalDelegate (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExternalPortEnd.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALPORTEND
