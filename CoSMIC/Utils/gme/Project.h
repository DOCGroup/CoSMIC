// -*- C++ -*-

//===========================================================================
/**
 * @file        Project.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//===========================================================================

#ifndef _GME_PROJECT_H_
#define _GME_PROJECT_H_

#include "Territory.h"
#include "Folder.h"
#include "Object.h"

namespace GME
{
  //===========================================================================
  /**
   * @class Project
   *
   * Wrapper class for the IMgaProject interface.
   */
  //===========================================================================

  class GME_Export Project
  {
  public:
    /**
     * Default constructor. This will create a Mga.MgaProject
     * object that will allow you to manage existing GME projects.
     */
    Project (void);

    /**
     * Initializing constructor.
     *
     * @param[in]     project       Pointer to an existing object.
     */
    Project (IMgaProject * project);

    /**
     * Copy constructor.
     *
     * @param[in]     project       The source project.
     */
    Project (const Project & project);

    /// Destructor.
    ~Project (void);

    /**
     * Convert the object to a IMgaProject pointer.
     *
     * @return      Pointer to a IMgaProject object.
     */
    operator IMgaProject * (void) const;

    /**
     * Create a new project. The name of the project is specified
     * in the \a name parameter. The project type, i.e., its paradigm,
     * is specified by the \a paradigm parameter.
     *
     * @param[in]     path          Location of the project.
     * @param[in]     paradigm      The project's paradigm type.
     */
    void create (const std::string & path, const std::string & paradigm);

    /**
     * Open an existing project.
     *
     * @param[in]     path          Location of the project.
     * @param[out]    ro_mode       Read/write mode of the project.
     */
    void open (const std::string & path, bool * ro_mode = 0);

    /**
     * Save the project as a new different project.
     *
     * @param[in]     path            Location of the new project.
     * @param[in]     keep_old_name   Keep the old name for the new project.
     */
    void save (const std::string & path, bool keep_old_name);

    /***
     * Close the current project.
     *
     * @param[in]     abort           Do not commit any modifications.
     */
    void close (bool abort = false);

    /**
     * Get the name of the project.
     *
     * @param[out]    name            Name of the project.
     */
    std::string name (void) const;

    /**
     * Set the name of the project.
     *
     * @param[in]     name            New name of the project.
     */
    void name (const std::string & name);

    /**
     * Get the version of the project.
     *
     * @param[out]    version         The version of the project.
     */
    std::string version (void) const;

    /**
     * Set the version of the project.
     *
     * @param[out]    version         The version of the project.
     */
    void version (const std::string & version);

    /**
     * Get the comment string of the project.
     *
     * @param[out]    comment         The comment string.
     */
    std::string comment (void) const;

    /**
     * Set the comment string of the project.
     *
     * @param[out]    comment         The comment string.
     */
    void comment (const std::string & comment);

    /**
     * Get the author of the project.
     *
     * @param[out]    author         The author of the project.
     */
    std::string author (void) const;

    /**
     * Set the author of the project.
     *
     * @param[out]    author         The author of the project.
     */
    void author (const std::string & author);

    /**
     * Get the creation time of the project.
     *
     * @param[out]    create_time     The creation time.
     */
    std::string create_time (void) const;

    /**
     * Get the change time for the project.
     *
     * @param[in]     change_time     The change time.
     */
    std::string change_time (void) const;

    /**
     * Create a new territory for the project.
     *
     * @return        New territory object.
     */
    Territory create_territory (void);

    /**
     * Get the active territory, i.e., one that is in transaction,
     * for the current project.
     *
     * @return        The active territory for the project.
     */
    Territory active_territory (void);

    /// Begin a new transaction using the project's default territory
    void begin_transaction (void);

    /**
     * Begin a new transaction using the specified territory.
     *
     * @param[in]     terr        Source territory for the transaction.
     */
    void begin_transaction (const Territory & terr);

    /// Commit all modifications in the current transaction.
    void commit_transaction (void);

    /// Abort the current transaction.
    void abort_transaction (void);

    /**
     * Get the root folder for the project.
     *
     * @return      The root folder.
     */
    Folder root_folder (void) const;

    Folder folder_by_path (const std::string & path) const;
    Object object_by_path (const std::string & path) const;

  private:
    /// The project type.
    CComPtr <IMgaProject> project_;

    /// Default territory for the project.
    Territory terr_;
  };
}

#endif  // !defined _GME_PROJECT_H_
