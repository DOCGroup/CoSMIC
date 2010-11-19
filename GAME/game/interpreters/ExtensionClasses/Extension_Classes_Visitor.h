// -*- C++ -*-

//=============================================================================
/**
 * @file      Extension_Classes_Visitor.h
 *
 * $Id: Extension_Classes_Visitor.h 2220 2010-06-07 17:27:27Z alhad $
 *
 * @author    Alhad Mokashi
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_VISITOR_H_
#define _EXTENSION_CLASSES_VISITOR_H_

#include "game/Visitor.h"

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <set>
//#include <windows.h>

#include "Atom.h"
#include "Attribute.h"
#include "Connection.h"
#include "FCO.h"
#include "Folder.h"
#include "Model.h"
#include "Object.h"
#include "Project.h"
#include "Reference.h"
#include "Set.h"

#include "MetaFCO.h"
#include "MetaModel.h"

namespace GAME
{
/**
 * @class Extension_Classes_Visitor
 */
class Extension_Classes_Visitor :
  public GAME::Visitor
{
public:
  //type defs
  typedef std::vector<GAME::Connection> CONNECTIONS;

  typedef std::vector<GAME::FCO> FCOS;

  typedef std::vector<GAME::Model> MODELS;

  Extension_Classes_Visitor (const std::string & outdir,
                             const std::string & uc_paradigm_name);

  virtual ~Extension_Classes_Visitor (void);

  virtual void visit_Atom (GAME::Atom &);

  virtual void visit_Attribute (GAME::Attribute &);

  virtual void visit_FCO (const GAME::FCO &);

  virtual void visit_Folder (GAME::Folder &);

  virtual void visit_Model (GAME::Model &);

  virtual void visit_Object (GAME::Object &);

  virtual void visit_Project (GAME::Project &);

  virtual void visit_Reference (GAME::Reference &);

  virtual void visit_Set (GAME::Set &);

  void get_src_connections (GAME::Connection, std::string, CONNECTIONS &);

  void get_dst_connections (GAME::Connection, std::string, CONNECTIONS &);

  std::string get_src_name (GAME::Connection);

  std::string get_dst_name (GAME::Connection);

  std::string get_src_meta_name (GAME::Connection);

  std::string get_dst_meta_name (GAME::Connection);

  void get_objects (std::set <GAME::Object> &);

private:
  const std::string outdir_;

  const std::string uc_paradigm_name_;

  std::string curr_folder_name_;

  std::string curr_sheet_name_;

  std::string curr_paradigm_sheet_root_dir_;
  
  std::string curr_dir_;

  std::ofstream out_;

  std::vector <GAME::Atom> attribute_list_;

  std::set <GAME::Object> objects_;
};
}

#if defined (__GAME_INLINE__)
#include "Extension_Classes_Visistor.inl"
#endif

#endif  // !defined _Extension_Classes_VISITOR_H_
