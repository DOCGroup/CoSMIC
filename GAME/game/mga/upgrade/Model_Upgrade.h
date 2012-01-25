// -*- C++ -*-

//=============================================================================
/**
 * @file      Model_Upgrade.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_MODEL_UPGRADE_H_
#define _GME_MODEL_UPGRADE_H_

#include "game/mga/Project.h"
#include "ace/SString.h"
#include "ace/Unbounded_Set.h"

/**
 * @class GME_Model_Upgrade
 */
class GME_Model_Upgrade
{
public:
  /// Default constructor.
  GME_Model_Upgrade (void);

  /// Destructor.
  ~GME_Model_Upgrade (void);

  int run_main (int argc, char * argv []);

private:
  /// Import current XML file.
  int import_xme_file (const ACE_CString & file);

  /// Export project file to current XML file.
  int export_project_file (const ACE_CString & file);

  /// Print the help
  void print_help (void);

  /// Parse the command-line arguments.
  int parse_args (int argc, char * argv []);

  /// Target XME file to import/upgrade.
  typedef ACE_Unbounded_Set <ACE_CString> filelist_t;

  /// List of the XML files to upgrade.
  filelist_t xme_files_;

  /// The GME project.
  GAME::Mga::Project project_;

  /// Target output filename.
  ACE_CString outfile_;
};

#endif  // !defined _GME_MODEL_UPGRADE_H_
