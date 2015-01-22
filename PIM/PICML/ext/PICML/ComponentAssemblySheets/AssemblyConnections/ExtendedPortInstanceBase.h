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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendPortEnd.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPortInstanceBase_Impl;
  typedef ExtendedPortInstanceBase_Impl * ExtendedPortInstanceBase_in;
  typedef ::GAME::Mga::Smart_Ptr < ExtendedPortInstanceBase_Impl > ExtendedPortInstanceBase;

  /**
   * @class ExtendedPortInstanceBase_Impl
   *
   * Implementation for the ExtendedPortInstanceBase model element.
   */
  class PICML_Export ExtendedPortInstanceBase_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual ExtendPortEnd_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    ExtendedPortInstanceBase_Impl (void);

    // Initializing constructor.
    ExtendedPortInstanceBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ExtendedPortInstanceBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ExtendedDelegate connection.
    size_t src_of_ExtendedDelegate (std::vector <ExtendedDelegate> & items) const;
    GAME::Mga::Collection_T <ExtendedDelegate> src_of_ExtendedDelegate (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExtendedPortInstanceBase.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDPORTINSTANCEBASE
