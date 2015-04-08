// -*- C++ -*-

//============================================================================
/**
 * @file    InEventPortDelegate.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INEVENTPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INEVENTPORTDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortEnd.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InEventPortDelegate_Impl;
  typedef InEventPortDelegate_Impl * InEventPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < InEventPortDelegate_Impl > InEventPortDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class InEventPortDelegate_Impl
   *
   * Implementation for the InEventPortDelegate model element.
   */
  class PICML_Export InEventPortDelegate_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual InEventPortEnd_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static InEventPortDelegate _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    InEventPortDelegate_Impl (void);

    // Initializing constructor.
    InEventPortDelegate_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~InEventPortDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src EventSinkDelegate connection.
    size_t src_of_EventSinkDelegate (std::vector <EventSinkDelegate> & items) const;
    GAME::Mga::Collection_T <EventSinkDelegate> src_of_EventSinkDelegate (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "InEventPortDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INEVENTPORTDELEGATE
