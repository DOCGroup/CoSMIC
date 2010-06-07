// -*- C++ -*-

//=============================================================================
/**
 * @file      File_Creator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_TO_PICML_FILE_CREATOR_H_
#define _IDL_TO_PICML_FILE_CREATOR_H_

#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"
#include "game/xme/Project.h"
#include "game/xme/Auto_Model_T.h"

/**
 * @class PICML_File_Creator_Item
 */
class PICML_File_Creator_Item
{
public:
  PICML_File_Creator_Item (GAME::XME::Model & file);

  ~PICML_File_Creator_Item (void);

  GAME::XME::Auto_Model_T <GAME::XME::Model> file_;

  ACE_Hash_Map_Manager <ACE_CString,
                        GAME::XME::Auto_Model_T <GAME::XME::Model> *,
                        ACE_Null_Mutex> modules_;
};

/**
 * @class PICML_File_Creator
 */
class PICML_File_Creator
{
public:
  /// Type definition for the collection of files.
  typedef ACE_Hash_Map_Manager <ACE_CString,
                                PICML_File_Creator_Item *,
                                ACE_Null_Mutex>
                                item_map;

  /**
   * Initializing constructor
   *
   * @param[in]       proj        Target project
   */
  PICML_File_Creator (GAME::XME::Project & proj);

  /// Destructor.
  ~PICML_File_Creator (void);

  /// Get the current set of files.
  const item_map & files (void) const;

  /**
   * Create the specified set of files.
   *
   * @param[in]       files       Collection of files
   * @param[in]       count       Number of files
   * @param[in]       dest        Target folder to create files
   */
  int create_files (const char * const * files, size_t count, const char * dest);

private:
  /// Target project to create the files
  GAME::XME::Project & proj_;

  /// Collection of files.
  item_map files_;
};

#include "File_Creator.inl"

#endif  // !defined _IDL_TO_PICML_FILE_CREATOR_H_
