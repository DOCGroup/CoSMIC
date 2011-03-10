// -*- C++ -*-

//============================================================================
/**
 * @file    Implements.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTS_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTS_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Implements_Impl;
  typedef Implements_Impl * Implements_in;
  typedef ::GAME::Mga::Smart_Ptr <Implements_Impl> Implements;

  // Forward decl.
  class Visitor;

  class PICML_Export Implements_Impl :
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
    Implements_Impl (void);

    /// Initializing constructor
    Implements_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Implements_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Implements _create (const ComponentImplementationContainer_in parent);
    ///@}

    /// Get the src ComponentImplementation connection point.
    ComponentImplementation src_ComponentImplementation (void);

    /// Get the dst ComponentRef connection point.
    ComponentRef dst_ComponentRef (void);

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
