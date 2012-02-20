// $Id$

#include "stdafx.h"
#include "Extension_Classes_Visitor.h"

#if !defined (__GAME_INLINE__)
#include "Extension_Classes_Visitor.inl"
#endif

#include "Attribute_Generator.h"
#include "Base_Class_Locator.h"
#include "Class_Definition.h"
#include "Connection_Point_Generator.h"
#include "Containment_Generator.h"
#include "Factory_Method_Generator.h"
#include "Functors.h"
#include "InConnection_Generator.h"
#include "Parent_Generator.h"
#include "RefersTo_Method_Generator.h"

#include "game/mga/Attribute.h"
#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/MetaAttribute.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/Reference.h"
#include "game/mga/RootFolder.h"

#include "boost/bind.hpp"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <iomanip>

namespace GAME
{
namespace Mga
{

//
// Extension_Clases_Visitor
//
Extension_Classes_Visitor::
Extension_Classes_Visitor (const std::string & outdir,
                           const Folder_in root,
                           const std::string & pch_basename,
                           std::set <Object> & generated)
: outdir_ (outdir),
  define_prefix_ (root->name ()),
  pch_basename_ (pch_basename),
  generated_ (generated)
{
  GAME::Utils::normalize (this->define_prefix_);
  std::transform (this->define_prefix_.begin (),
                  this->define_prefix_.end (),
                  this->define_prefix_.begin (),
                  &::toupper);
}

//
// ~Extension_Classes_Visitor
//
Extension_Classes_Visitor::~Extension_Classes_Visitor (void)
{

}

//
// visit_Folder
//
void Extension_Classes_Visitor::visit_RootFolder (RootFolder_in folder)
{
  const std::string path = this->outdir_ + "/" + folder->name ();
  ::GAME::Utils::create_path (path);

  this->visit_Folder_i (folder);
}

//
// visit_Folder
//
void Extension_Classes_Visitor::visit_Folder (Folder_in folder)
{
  // Create the directory for this model, and its elements.
  const std::string path = this->outdir_ + folder->path ("/");
  ::GAME::Utils::create_path (path);

  this->visit_Folder_i (folder);
}

//
// visit_Folder_i
//
void Extension_Classes_Visitor::visit_Folder_i (Folder_in folder)
{
  // Visit all the paradigm sheets.
  std::vector <Model> sheets;
  folder->children (sheets);

  std::for_each (make_impl_iter (sheets.begin ()),
                 make_impl_iter (sheets.end ()),
                 boost::bind (&Model::impl_type::accept, _1, this));

  // Visit all the SheetFolder elements in the model.
  std::vector <Folder> folders;
  folder->folders ("SheetFolder", folders);

  std::for_each (make_impl_iter (folders.begin ()),
                 make_impl_iter (folders.end ()),
                 boost::bind (&Folder::impl_type::accept, _1, this));
}

//
// visit_Model
//
void Extension_Classes_Visitor::visit_Model (Model_in model)
{
  // Create the directory for this model, and its elements.
  const std::string path = this->outdir_ + model->path ("/");
  GAME::Utils::create_path (path);

  // Visit all the children in this model (or paradigm sheet).
  std::vector <FCO> children;
  model->children (children);

  std::for_each (make_impl_iter (children.begin ()),
                 make_impl_iter (children.end ()),
                 boost::bind (&FCO::impl_type::accept, _1, this));
}

//
// visit_Atom
//
void Extension_Classes_Visitor::visit_Atom (Atom_in atom)
{
  std::auto_ptr <Class_Definition> definition (Class_Definition::_create (atom));

  if (0 != definition.get ())
  {
    // Build the definition.
    definition->build (atom);

    // Start a new extension class.
    const std::string basename = this->outdir_ + atom->path ("/");
    const std::string hxx_filename = basename + ".h";
    const std::string cpp_filename = basename + ".cpp";
    const std::string inl_filename = basename + ".inl";

    std::ofstream hfile (hxx_filename.c_str ());
    std::ofstream ifile (inl_filename.c_str ());
    std::ofstream sfile (cpp_filename.c_str ());

    if (!(hfile.is_open () && ifile.is_open () && sfile.is_open ()))
      return;

    do
    {
      // Set the indentation implanter for this extension class.
      Indentation::Implanter <Indentation::Cxx, char> header_indent (hfile);
      Indentation::Implanter <Indentation::Cxx, char> source_indent (sfile);
      Indentation::Implanter <Indentation::Cxx, char> inline_indent (ifile);

      // Initialize the generation context.
      Generation_Context context (hfile, ifile, sfile);

      std::string export_name =
        ::GAME::Utils::normalize (atom->project ().root_folder ()->name ());

      context.export_filename_ = export_name + "_export.h";

      std::transform (export_name.begin (),
                      export_name.end (),
                      export_name.begin (),
                      &::toupper);

      context.export_macro_ = export_name + "_Export";

      // Generate the class definition.
      definition->generate (context);
    }
    while (false);

    // Insert the model element into the generated list.
    this->generated_.insert (atom);

    // Close the file handles.
    hfile.close ();
    sfile.close ();
    ifile.close ();
  }
}

}
}
