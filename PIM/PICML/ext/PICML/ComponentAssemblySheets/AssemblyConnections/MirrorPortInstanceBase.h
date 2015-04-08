// -*- C++ -*-

//============================================================================
/**
 * @file    MirrorPortInstanceBase.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORPORTINSTANCEBASE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORPORTINSTANCEBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendPortEnd.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MirrorPortInstanceBase_Impl;
  typedef MirrorPortInstanceBase_Impl * MirrorPortInstanceBase_in;
  typedef ::GAME::Mga::Smart_Ptr < MirrorPortInstanceBase_Impl > MirrorPortInstanceBase;

  /**
   * @class MirrorPortInstanceBase_Impl
   *
   * Implementation for the MirrorPortInstanceBase model element.
   */
  class PICML_Export MirrorPortInstanceBase_Impl :
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    MirrorPortInstanceBase_Impl (void);

    // Initializing constructor.
    MirrorPortInstanceBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~MirrorPortInstanceBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src MirrorDelegate connection.
    size_t src_of_MirrorDelegate (std::vector <MirrorDelegate> & items) const;
    bool has_src_of_MirrorDelegate (void) const;
    MirrorDelegate src_of_MirrorDelegate (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MirrorPortInstanceBase.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_MIRRORPORTINSTANCEBASE
