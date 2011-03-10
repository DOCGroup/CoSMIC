// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentPackageReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_COMPONENTPACKAGEREFERENCE_H_
#define _PICML_COMPONENTPACKAGE_COMPONENTPACKAGEREFERENCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentPackageReference_Impl;
  typedef ComponentPackageReference_Impl * ComponentPackageReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentPackageReference_Impl> ComponentPackageReference;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentPackageReference_Impl :
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
    ComponentPackageReference_Impl (void);

    /// Initializing constructor
    ComponentPackageReference_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComponentPackageReference_Impl (void);

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
    ComponentPackage refers_to_ComponentPackage (void) const;
    ///@}
  };
}

#endif
