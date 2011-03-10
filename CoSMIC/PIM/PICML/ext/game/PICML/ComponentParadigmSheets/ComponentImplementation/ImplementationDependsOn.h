// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationDependsOn.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTATIONDEPENDSON_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTATIONDEPENDSON_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationDependsOn_Impl;
  typedef ImplementationDependsOn_Impl * ImplementationDependsOn_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationDependsOn_Impl> ImplementationDependsOn;

  // Forward decl.
  class Visitor;

  class PICML_Export ImplementationDependsOn_Impl :
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
    ImplementationDependsOn_Impl (void);

    /// Initializing constructor
    ImplementationDependsOn_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ImplementationDependsOn_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ImplementationDependsOn _create (const ComponentImplementationContainer_in parent);
    ///@}

    /// Get the src ComponentImplementation connection point.
    ComponentImplementation src_ComponentImplementation (void);

    /// Get the dst ImplementationDependency connection point.
    ImplementationDependency dst_ImplementationDependency (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementationContainer parent_ComponentImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
