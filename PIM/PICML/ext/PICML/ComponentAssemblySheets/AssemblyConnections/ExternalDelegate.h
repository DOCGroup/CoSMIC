// -*- C++ -*-

//============================================================================
/**
 * @file    ExternalDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExternalDelegate_Impl;
  typedef ExternalDelegate_Impl * ExternalDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < ExternalDelegate_Impl > ExternalDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class ExternalDelegate_Impl
   *
   * Implementation for the ExternalDelegate model element.
   */
  class PICML_Export ExternalDelegate_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ExternalDelegate _create (const ComponentAssembly_in parent, ExternalPort_in src, ExternalPortEnd_in dst);
    ///@}

    // Default constructor.
    ExternalDelegate_Impl (void);

    // Initializing constructor.
    ExternalDelegate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ExternalDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    ExternalPort src_ExternalPort (void) const;
    ExternalPortEnd dst_ExternalPortEnd (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ExternalDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTERNALDELEGATE
