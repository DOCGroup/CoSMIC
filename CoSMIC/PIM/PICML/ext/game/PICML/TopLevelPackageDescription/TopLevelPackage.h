// -*- C++ -*-

//============================================================================
/**
 * @file    TopLevelPackage.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGE_H_
#define _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGE_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TopLevelPackage_Impl;
  typedef TopLevelPackage_Impl * TopLevelPackage_in;
  typedef ::GAME::Mga::Smart_Ptr <TopLevelPackage_Impl> TopLevelPackage;

  // Forward decl.
  class Visitor;

  class PICML_Export TopLevelPackage_Impl :
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
    TopLevelPackage_Impl (void);

    /// Initializing constructor
    TopLevelPackage_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~TopLevelPackage_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static TopLevelPackage _create (const TopLevelPackageContainer_in parent);
    ///@}
    size_t in_package_connections (std::vector <package> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelPackageContainer parent_TopLevelPackageContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
