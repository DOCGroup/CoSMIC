// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedDelegate_Impl;
  typedef ExtendedDelegate_Impl * ExtendedDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < ExtendedDelegate_Impl > ExtendedDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class ExtendedDelegate_Impl
   *
   * Implementation for the ExtendedDelegate model element.
   */
  class PICML_Export ExtendedDelegate_Impl :
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
    static ExtendedDelegate _create (const ComponentAssembly_in parent, ExtendedPortInstanceBase_in src, ExtendedPortDelegate_in dst);
    ///@}

    // Default constructor.
    ExtendedDelegate_Impl (void);

    // Initializing constructor.
    ExtendedDelegate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ExtendedDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    ExtendedPortInstanceBase src_ExtendedPortInstanceBase (void) const;
    ExtendedPortDelegate dst_ExtendedPortDelegate (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ExtendedDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDDELEGATE
