// -*- C++ -*-

//=============================================================================
/**
 * @file      Library_Importer.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_LIBRARY_IMPORTER_H_
#define _GAME_XME_LIBRARY_IMPORTER_H_

#include <map>
#include <vector>

#include "Reference.h"
#include "Connection.h"

namespace GAME
{
namespace XME
{ 
class Library;

class Folder;

class FCO;

class Library_Importer
{
public:
  Library_Importer (void);

  ~Library_Importer (void);

  void import (Folder & folder);

private:
  struct insensitive_id
  {
    bool operator () (const ::Utils::XStr & lid, const ::Utils::XStr & rid) const;
  };

  void handle_folder (Folder & folder);

  void handle_import_fco (FCO & fco);

  void handle_import_atom (FCO & fco);
  
  void handle_import_model (FCO & fco);
  
  void handle_import_reference (FCO & fco);
  
  void handle_import_connection (FCO & fco);

  void resolve_reference (Reference & ref);

  void resolved_connection (Connection & conn);

  template <typename T>
  void handle_import_common (T & element);
 
  typedef std::map < ::Utils::XStr, 
                     ::Utils::XStr,
                     insensitive_id > id_map_t;

  id_map_t id_map_;

  std::vector < Reference > unresolved_refs_;

  std::vector < Connection > unresolved_conns_;

  static const ::Utils::XStr ATTR_ID;
  static const ::Utils::XStr ATTR_REFERRED;
  static const ::Utils::XStr ATTR_TARGET;
};

}
}

#endif
