// -*- C++ -*-

//============================================================================
/**
 * @file    WorkerLibrary.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERLIBRARY_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERLIBRARY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerLibrary_Impl;
  typedef WorkerLibrary_Impl * WorkerLibrary_in;
  typedef ::GAME::Mga::Smart_Ptr < WorkerLibrary_Impl > WorkerLibrary;

  // Forward decl.
  class Visitor;

  /**
   * @class WorkerLibrary_Impl
   *
   * Implementation for the WorkerLibrary model element.
   */
  class PICML_Export WorkerLibrary_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkerLibrary _create (const WorkerLibraries_in parent);
    ///@}

    // Default constructor.
    WorkerLibrary_Impl (void);

    // Initializing constructor.
    WorkerLibrary_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~WorkerLibrary_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    WorkerLibraries parent_WorkerLibraries (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Location
    void Location (const std::string & val);

    /// Get the value of Location
    std::string Location (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_WorkerFiles (std::vector <WorkerFile> & items) const;
    ::GAME::Mga::Collection_T <WorkerFile> get_WorkerFiles (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "WorkerLibrary.inl"
#endif

#endif  // !defined _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERLIBRARY
