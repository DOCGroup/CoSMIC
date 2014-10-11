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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PathDiagrams_Impl;
  typedef PathDiagrams_Impl * PathDiagrams_in;
  typedef ::GAME::Mga::Smart_Ptr < PathDiagrams_Impl > PathDiagrams;

  // Forward decl.
  class Visitor;

  /**
   * @class PathDiagrams_Impl
   *
   * Implementation for the PathDiagrams model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static PathDiagrams _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    PathDiagrams_Impl (void);

    // Initializing constructor.
    PathDiagrams_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~PathDiagrams_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    /**
     * @name Folder Getters
     */
    ///@{

    size_t get_Pathss (std::vector <Paths> & items) const;

    ::GAME::Mga::Collection_T <Paths> get_Pathss (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PathDiagrams.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_PATHDIAGRAMS
