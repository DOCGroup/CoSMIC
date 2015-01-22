// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDPORTDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortInstanceBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPortDelegate_Impl;
  typedef ExtendedPortDelegate_Impl * ExtendedPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < ExtendedPortDelegate_Impl > ExtendedPortDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class ExtendedPortDelegate_Impl
   *
   * Implementation for the ExtendedPortDelegate model element.
   */
  class PICML_Export ExtendedPortDelegate_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual ExtendedPortInstanceBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ExtendedPortDelegate _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    ExtendedPortDelegate_Impl (void);

    // Initializing constructor.
    ExtendedPortDelegate_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ExtendedPortDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ExtendedDelegate connection.
    size_t dst_of_ExtendedDelegate (std::vector <ExtendedDelegate> & items) const;
    GAME::Mga::Collection_T <ExtendedDelegate> dst_of_ExtendedDelegate (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExtendedPortDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDEDPORTDELEGATE
