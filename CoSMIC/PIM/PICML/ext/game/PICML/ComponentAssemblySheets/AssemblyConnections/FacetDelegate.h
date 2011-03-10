// -*- C++ -*-

//============================================================================
/**
 * @file    FacetDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_FACETDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_FACETDELEGATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FacetDelegate_Impl;
  typedef FacetDelegate_Impl * FacetDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <FacetDelegate_Impl> FacetDelegate;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    FacetDelegate_Impl (void);

    /// Initializing constructor
    FacetDelegate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~FacetDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src ProvidedRequestPortDelegate connection point.
    ProvidedRequestPortDelegate src_ProvidedRequestPortDelegate (void);

    /// Get the dst ProvidedRequestPortEnd connection point.
    ProvidedRequestPortEnd dst_ProvidedRequestPortEnd (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
