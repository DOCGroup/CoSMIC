// -*- C++ -*-

//=============================================================================
/**
 * @file      Extension_Classes_Visitor.h
 *
 * $Id: Extension_Classes_Visitor.h 2220 2010-06-07 17:27:27Z alhad $
 *
 * @author    Alhad Mokashi <amokashi at iupui dot edu>
 *            James H. Hill <hillj at cs dot iupui dot edu>
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
  Extension_Classes_Visitor (const std::string & outdir,
                             const Folder_in root,
                             const std::string & pch_basename,
                             std::set <Object> & generated);

  /// Destructor.
  virtual ~Extension_Classes_Visitor (void);

  // Visit a Folder element.
  virtual void visit_RootFolder (RootFolder_in folder);
  virtual void visit_Folder (Folder_in folder);

  // Visit an Atom element.
  virtual void visit_Atom (Atom_in atom);

  // Visit a Model element.
  virtual void visit_Model (Model_in model);

private:
  /// Helper method for visiting an FCO.
  void visit_FCO (FCO_in fco);

  //type defintions
  typedef std::vector <FCO> FCOS;

  typedef std::vector <Model> MODELS;

  typedef std::vector <Connection> CONNECTIONS;

  void get_src_connections (Connection_in conn,
                            std::string,
                            CONNECTIONS &);

  void get_dst_connections (const Connection_in conn, std::string, CONNECTIONS &);


  void generate_connection_points (FCO_in fco);

  void create_directory (std::string);

  std::string get_instance_path (const FCO_in fco);

private:
  /// Target output directory.
  std::string outdir_;

  /// Collection of generated extension classes.
  std::set <Object> & generated_;

  /// The prefix for the macro definition
  std::string define_prefix_;

  /// The basename for the precompiled header.
  const std::string & pch_basename_;

  /// The generated header file.
  std::ofstream header_;

  /// The generated source file.
  std::ofstream source_;

  /// Name of the extension class.
  std::string classname_;
};

}
}

#endif  // !defined _Extension_Classes_VISITOR_H_
