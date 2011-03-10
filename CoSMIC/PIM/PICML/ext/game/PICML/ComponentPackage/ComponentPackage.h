// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentPackage.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_COMPONENTPACKAGE_H_
#define _PICML_COMPONENTPACKAGE_COMPONENTPACKAGE_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentPackage_Impl;
  typedef ComponentPackage_Impl * ComponentPackage_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentPackage_Impl> ComponentPackage;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentPackage_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentPackage_Impl (void);

    /// Initializing constructor
    ComponentPackage_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ComponentPackage_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentPackage _create (const PackageContainer_in parent);
    ///@}
    size_t in_PackageConfigProperty_connections (std::vector <PackageConfigProperty> & conns) const;
    size_t in_PackageInterface_connections (std::vector <PackageInterface> & conns) const;
    size_t in_PackageInfoProperty_connections (std::vector <PackageInfoProperty> & conns) const;
    size_t in_Implementation_connections (std::vector <Implementation> & conns) const;

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
