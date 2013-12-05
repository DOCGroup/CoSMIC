// -*- C++ -*-

//============================================================================
/**
 * @file    ProvidedRequestPortDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ProvidedRequestPortDelegate_Impl;
  typedef ProvidedRequestPortDelegate_Impl * ProvidedRequestPortDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < ProvidedRequestPortDelegate_Impl > ProvidedRequestPortDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class ProvidedRequestPortDelegate_Impl
   *
   * Implementation for the ProvidedRequestPortDelegate model element.
   */
  class PICML_Export ProvidedRequestPortDelegate_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual ProvidedRequestPortEnd_Impl
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
    static ProvidedRequestPortDelegate _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    ProvidedRequestPortDelegate_Impl (void);

    // Initializing constructor.
    ProvidedRequestPortDelegate_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ProvidedRequestPortDelegate_Impl (void);

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

    /// Get the src FacetDelegate connection.
    size_t src_FacetDelegate (std::vector <FacetDelegate> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ProvidedRequestPortDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTDELEGATE
