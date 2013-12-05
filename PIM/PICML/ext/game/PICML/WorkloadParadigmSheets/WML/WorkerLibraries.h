// -*- C++ -*-

//============================================================================
/**
 * @file    WorkerLibraries.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERLIBRARIES_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERLIBRARIES_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerLibraries_Impl;
  typedef WorkerLibraries_Impl * WorkerLibraries_in;
  typedef ::GAME::Mga::Smart_Ptr < WorkerLibraries_Impl > WorkerLibraries;

  // Forward decl.
  class Visitor;

  /**
   * @class WorkerLibraries_Impl
   *
   * Implementation for the WorkerLibraries model element.
   */
  class PICML_Export WorkerLibraries_Impl :
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
    static WorkerLibraries _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    WorkerLibraries_Impl (void);

    // Initializing constructor.
    WorkerLibraries_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~WorkerLibraries_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ::GAME::Mga::RootFolder parent_RootFolder (void);
    ///@}

    size_t get_WorkerLibrarys (std::vector <WorkerLibrary> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "WorkerLibraries.inl"
#endif

#endif  // !defined _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERLIBRARIES
