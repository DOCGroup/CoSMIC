// -*- C++ -*-

//============================================================================
/**
 * @file    FacetDelegate.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_FACETDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_FACETDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FacetDelegate_Impl;
  typedef FacetDelegate_Impl * FacetDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < FacetDelegate_Impl > FacetDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class FacetDelegate_Impl
   *
   * Implementation for the FacetDelegate model element.
   */
  class PICML_Export FacetDelegate_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static FacetDelegate _create (const ComponentAssembly_in parent, ProvidedRequestPortDelegate_in src, ProvidedRequestPortEnd_in dst);
    ///@}

    // Default constructor.
    FacetDelegate_Impl (void);

    // Initializing constructor.
    FacetDelegate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~FacetDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    ProvidedRequestPortDelegate src_ProvidedRequestPortDelegate (void) const;
    ProvidedRequestPortEnd dst_ProvidedRequestPortEnd (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "FacetDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_FACETDELEGATE
