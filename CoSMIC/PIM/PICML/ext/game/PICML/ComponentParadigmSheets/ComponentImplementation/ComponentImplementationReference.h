// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementationReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONREFERENCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONREFERENCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementationReference_Impl;
  typedef ComponentImplementationReference_Impl * ComponentImplementationReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementationReference_Impl> ComponentImplementationReference;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentImplementationReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentImplementationReference_Impl (void);

    /// Initializing constructor
    ComponentImplementationReference_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComponentImplementationReference_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ComponentImplementation refers_to_ComponentImplementation (void) const;
    ///@}
  };
}

#endif
