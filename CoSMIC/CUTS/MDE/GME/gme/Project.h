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
   */
  //===========================================================================

  class GME_Export Project
  {
  public:
    Project (void);
    Project (IMgaProject * project);
    Project (const Project & project);

    ~Project (void);

    void create (const std::string & name, const std::string & paradigm);
    void open (const std::string & name, bool * ro_mode = 0);
    void save (const std::string & saveas, bool keep_old_name);
    void close (bool abort = false);

    std::string name (void) const;
    void name (const std::string & name);

    std::string version (void) const;
    void version (const std::string & version);

    std::string comment (void) const;
    void comment (const std::string & comment);

    std::string author (void) const;
    void author (const std::string & author);

    std::string create_time (void) const;
    std::string change_time (void) const;

    Territory create_territory (void);
    Territory active_territory (void);

    void begin_transaction (void);
    void begin_transaction (const Territory & terr);
    void abort_transaction (void);
    void commit_transaction (void);

    Folder root_folder (void) const;

    Folder folder_by_path (const std::string & path) const;
    Object object_by_path (const std::string & path) const;

    operator IMgaProject * (void) const;

  private:
    /// The project type.
    CComPtr <IMgaProject> project_;

    /// Default territory for the project.
    Territory terr_;
  };
}

#endif  // !defined _GME_PROJECT_H_
