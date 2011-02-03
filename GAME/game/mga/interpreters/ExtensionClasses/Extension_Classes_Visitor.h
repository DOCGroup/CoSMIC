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

#include <string>
#include <fstream>
#include <set>

#include "game/mga/Project.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Visitor.h"
#include "game/mga/Connection.h"

#include "Extension_Classes_Code_Generator.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Extension_Classes_Visitor
 */
class Extension_Classes_Visitor : public Visitor
{
public:
  Extension_Classes_Visitor (const std::string &, const std::string &);

  virtual ~Extension_Classes_Visitor (void);

  virtual void visit_Folder (Folder_in folder);

  virtual void visit_FCO (FCO_in fco);

  virtual void visit_Model (Model_in model);

  const std::set <Object> & get_objects (void) const;

private:
  //type defintions
  typedef std::vector <FCO> FCOS;

  typedef std::vector <Model> MODELS;

  typedef std::vector <Connection> CONNECTIONS;

  void get_src_connections (Connection_in conn,
                            std::string,
                            CONNECTIONS &);

  void get_dst_connections (const Connection_in conn, std::string, CONNECTIONS &);


  void create_directory (std::string);

  void create_default_functions (std::string,
                                 std::string,
                                 std::string,
                                 std::string,
                                 Extension_Classes_Code_Generator &);

  std::string get_instance_path (const FCO_in fco);

private:
  const std::string outdir_;

  const std::string uc_paradigm_name_;

  std::ofstream out_;

  std::set <Object> objects_;
};

}
}

#endif  // !defined _Extension_Classes_VISITOR_H_
