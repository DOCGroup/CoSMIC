// -*- C++ -*-

//============================================================================
/**
 * @file    OutEventPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_OUTEVENTPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_OUTEVENTPORTDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortEnd.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OutEventPortDelegate_Impl;
  typedef OutEventPortDelegate_Impl * OutEventPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < OutEventPortDelegate_Impl > OutEventPortDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class OutEventPortDelegate_Impl
   *
   * Implementation for the OutEventPortDelegate model element.
   */
  class PICML_Export OutEventPortDelegate_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual OutEventPortEnd_Impl
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
    static OutEventPortDelegate _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    OutEventPortDelegate_Impl (void);

    // Initializing constructor.
    OutEventPortDelegate_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~OutEventPortDelegate_Impl (void);

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

    /// Get the dst EventSourceDelegate connection.
    size_t dst_EventSourceDelegate (std::vector <EventSourceDelegate> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OutEventPortDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_OUTEVENTPORTDELEGATE
