// -*- C++ -*-

//============================================================================
/**
 * @file    Implementation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_IMPLEMENTATION_H_
#define _PICML_COMPONENTPACKAGE_IMPLEMENTATION_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Implementation_Impl;
  typedef Implementation_Impl * Implementation_in;
  typedef ::GAME::Mga::Smart_Ptr <Implementation_Impl> Implementation;

  // Forward decl.
  class Visitor;

  class PICML_Export Implementation_Impl :
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
    Implementation_Impl (void);

    /// Initializing constructor
    Implementation_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Implementation_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Implementation _create (const PackageContainer_in parent);
    ///@}

    /// Get the src ComponentPackage connection point.
    ComponentPackage src_ComponentPackage (void);

    /// Get the dst ComponentImplementationReference connection point.
    ComponentImplementationReference dst_ComponentImplementationReference (void);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageContainer parent_PackageContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
