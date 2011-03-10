// -*- C++ -*-

//============================================================================
/**
 * @file    TopLevelPackages.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGES_H_
#define _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGES_H_

#include "game/mga/Folder.h"
#include "game/mga/RootFolder.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TopLevelPackages_Impl;
  typedef TopLevelPackages_Impl * TopLevelPackages_in;
  typedef ::GAME::Mga::Smart_Ptr <TopLevelPackages_Impl> TopLevelPackages;

  // Forward decl.
  class Visitor;

  class PICML_Export TopLevelPackages_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    TopLevelPackages_Impl (void);

    /// Initializing constructor
    TopLevelPackages_Impl (IMgaFolder * ptr);

    /// Destructor
    virtual ~TopLevelPackages_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static TopLevelPackages _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ::GAME::Mga::RootFolder parent_RootFolder (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
