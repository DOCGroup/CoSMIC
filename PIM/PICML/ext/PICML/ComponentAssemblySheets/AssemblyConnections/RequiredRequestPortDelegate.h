// -*- C++ -*-

//============================================================================
/**
 * @file    RequiredRequestPortDelegate.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_REQUIREDREQUESTPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_REQUIREDREQUESTPORTDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequiredRequestPortDelegate_Impl;
  typedef RequiredRequestPortDelegate_Impl * RequiredRequestPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < RequiredRequestPortDelegate_Impl > RequiredRequestPortDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class RequiredRequestPortDelegate_Impl
   *
   * Implementation for the RequiredRequestPortDelegate model element.
   */
  class PICML_Export RequiredRequestPortDelegate_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual RequiredRequestPortEnd_Impl
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
    static RequiredRequestPortDelegate _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    RequiredRequestPortDelegate_Impl (void);

    // Initializing constructor.
    RequiredRequestPortDelegate_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~RequiredRequestPortDelegate_Impl (void);

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

    /// Get the src ReceptacleDelegate connection.
    size_t src_of_ReceptacleDelegate (std::vector <ReceptacleDelegate> & items) const;
    GAME::Mga::Collection_T <ReceptacleDelegate> src_of_ReceptacleDelegate (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "RequiredRequestPortDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_REQUIREDREQUESTPORTDELEGATE
