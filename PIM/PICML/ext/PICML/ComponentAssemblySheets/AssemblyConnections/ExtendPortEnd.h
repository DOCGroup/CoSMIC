// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendPortEnd.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDPORTEND_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalPortEnd.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendPortEnd_Impl;
  typedef ExtendPortEnd_Impl * ExtendPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr < ExtendPortEnd_Impl > ExtendPortEnd;

  /**
   * @class ExtendPortEnd_Impl
   *
   * Implementation for the ExtendPortEnd model element.
   */
  class PICML_Export ExtendPortEnd_Impl :
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
    ExtendPortEnd_Impl (void);

    // Initializing constructor.
    ExtendPortEnd_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ExtendPortEnd_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src Publish connection.
    size_t src_of_Publish (std::vector <Publish> & items) const;
    bool has_src_of_Publish (void) const;
    Publish src_of_Publish (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst Consume connection.
    size_t dst_of_Consume (std::vector <Consume> & items) const;
    bool has_dst_of_Consume (void) const;
    Consume dst_of_Consume (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExtendPortEnd.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDPORTEND
