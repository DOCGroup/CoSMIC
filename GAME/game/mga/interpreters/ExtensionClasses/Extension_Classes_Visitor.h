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

#include "game/mga/Folder.h"

// Forward decl.
class Object_Class_Definition;

namespace GAME
{
namespace Mga
{

/**
 * @class Extension_Classes_Visitor
 */
class Extension_Classes_Visitor
{
public:
  Extension_Classes_Visitor (const std::string & outdir,
                             const Folder_in root,
                             const std::string & pch_basename);

  /// Destructor.
  virtual ~Extension_Classes_Visitor (void);

  // Visit a Folder element.
  void generate (Object_Class_Definition * definition);

private:
  void mkdir (const std::string & basename);

  /// Target output directory.
  std::string outdir_;

  /// The prefix for the macro definition
  std::string define_prefix_;

  std::string export_filename_;
  std::string export_macro_;

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
