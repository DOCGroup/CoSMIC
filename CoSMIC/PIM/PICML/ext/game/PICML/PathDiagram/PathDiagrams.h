// -*- C++ -*-

//============================================================================
/**
 * @file    PathDiagrams.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATHDIAGRAMS_H_
#define _PICML_PATHDIAGRAM_PATHDIAGRAMS_H_

#include "game/mga/Folder.h"
#include "game/mga/RootFolder.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PathDiagrams_Impl;
  typedef PathDiagrams_Impl * PathDiagrams_in;
  typedef ::GAME::Mga::Smart_Ptr <PathDiagrams_Impl> PathDiagrams;

  // Forward decl.
  class Visitor;

  class PICML_Export PathDiagrams_Impl :
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
    PathDiagrams_Impl (void);

    /// Initializing constructor
    PathDiagrams_Impl (IMgaFolder * ptr);

    /// Destructor
    virtual ~PathDiagrams_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PathDiagrams _create (const ::GAME::Mga::RootFolder_in parent);
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
