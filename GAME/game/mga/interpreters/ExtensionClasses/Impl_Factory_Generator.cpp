// $Id$

#include "StdAfx.h"
#include "Impl_Factory_Generator.h"
#include "Functors.h"

#include "game/mga/Project.h"
#include "game/mga/Utils.h"
#include "game/mga/FCO.h"
#include "game/mga/Attribute.h"
#include "Object_Class_Definition.h"
#include "Object_Manager.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <iomanip>
#include <fstream>

namespace GAME
{
namespace Mga
{
/**
 * @struct bind_generator_t
 *
 * Functor that inserts the factory method for an implementation into
 * the functor map.
 */
struct bind_generator_t
{
  bind_generator_t (std::ofstream & cfile)
    : cfile_ (cfile)
  {

  }

  void operator () (const Object_Manager::map_type::ENTRY & entry) const
  {
    if (entry.item ()->is_abstract ())
      return;

    const std::string name = entry.key ();
    const std::string impl_name = name + "_Impl";

    this->cfile_
      << "this->map_.bind (\"" << name
      << "\", &::GAME::Mga::allocate_impl <" << impl_name << ">);";
  }

private:
  /// The target source file.
  std::ofstream & cfile_;
};

/**
 * @struct bind_generator_t
 *
 * Functor that inserts the factory method for an implementation into
 * the functor map.
 */
struct include_generator_t
{
  include_generator_t (std::ofstream & cfile)
    : cfile_ (cfile)
  {

  }

  void operator () (const Object_Manager::map_type::ENTRY & entry) const
  {
    const Object_Class_Definition * definition = entry.item ();

    if (!definition->is_abstract ())
      this->cfile_ << include_t (definition->compute_path ("/", false) + ".h");
  }

private:
  /// The target source file.
  std::ofstream & cfile_;
};

//
// Impl_Factory_Generator
//
Impl_Factory_Generator::Impl_Factory_Generator (void)
{

}

//
// ~Impl_Factory_Generator
//
Impl_Factory_Generator::~Impl_Factory_Generator (void)
{

}

//
// generate
//
bool Impl_Factory_Generator::
generate (const std::string & location,
          const Project & proj,
          const std::string & pch_basename,
          const Object_Manager * obj_mgr)
{
  // Open the .mpc file for writing.
  const std::string project_name = proj.name ();
  const std::string root = proj.root_folder ()->name ();
  const std::string basename = location + "/" + root + "/Impl_Factory";

  // Start a new extension class.
  const std::string hxx_filename = basename + ".h";
  const std::string cpp_filename = basename + ".cpp";

  this->hxx_file_.open (hxx_filename.c_str ());
  this->cxx_file_.open (cpp_filename.c_str ());

  if (!this->hxx_file_.is_open () || !this->cxx_file_.is_open ())
    return false;

  std::string export_name = project_name;
  std::transform (export_name.begin (),
                  export_name.end (),
                  export_name.begin (),
                  &::toupper);

  this->hxx_file_
    << "// -*- C++ -*-" << std::endl
    << std::endl
    << std::left << std::setw (78) << std::setfill ('=') << "//" << std::endl
    << "/**" << std::endl
    << " * @file    Impl_Factory.h" << std::endl
    << " *" << std::endl
    << " * $" << "Id" << "$" << std::endl
    << " *" << std::endl
    << " * @author  Alhad Mokashi <amokashi at iupui dot edu>" << std::endl
    << " *          James H. Hill <hillj at cs dot iupui dot edu>" << std::endl
    << " */" << std::endl
    << std::left << std::setw (78) << std::setfill ('=') << "//" << std::endl
    << std::endl
    << "#ifndef _" << export_name << "_IMPL_FACTORY_H_" << std::endl
    << "#define _" << export_name << "_IMPL_FACTORY_H_" << std::endl
    << std::endl
    << include_t ("game/mga/Impl_Factory.h")
    << include_t ("ace/Hash_Map_Manager.h")
    << include_t ("ace/Null_Mutex.h")
    << include_t ("ace/SString.h")
    << std::endl
    << include_t (project_name + "_export.h");

  this->cxx_file_
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << include_t (pch_basename + ".h")
    << include_t ("Impl_Factory.h")
    << std::endl
    << include_t ("game/mga/Functional_T.h")
    << include_t ("game/mga/Exception.h")
    << std::endl;

  std::for_each (obj_mgr->objects ().begin (),
                 obj_mgr->objects ().end (),
                 include_generator_t (this->cxx_file_));

  this->generate_source_files (proj, obj_mgr);

  // Close the file handles.
  this->hxx_file_.close ();
  this->cxx_file_.close ();
  return true;
}

//
// generate_source_files
//
void Impl_Factory_Generator::
generate_source_files (const Project & proj, const Object_Manager * obj_mgr)
{
  Indentation::Implanter <Indentation::Cxx, char> header_indent (this->hxx_file_);
  Indentation::Implanter <Indentation::Cxx, char> source_indent (this->cxx_file_);

  const std::string project_name = GAME::Utils::normalize (proj.name ());
  std::string export_name = project_name;

  std::transform (export_name.begin (),
                  export_name.end (),
                  export_name.begin (),
                  &::toupper);

  // Start the project namespace.
  this->hxx_file_
    << std::endl
    << "namespace " << project_name
    << "{"
    << "class " << export_name << "_Export Impl_Factory : public ::GAME::Mga::Impl_Factory_Base"
    << "{"
    << "public:" << std::endl
    << "/// Default constructor." << std::endl
    << "Impl_Factory (void);"
    << std::endl
    << "/// Destructor." << std::endl
    << "virtual ~Impl_Factory (void);"
    << std::endl
    << "/// Allocate the implementation for this object." << std::endl
    << "virtual ::GAME::Mga::Object_Impl * allocate (IMgaObject * ptr);"
    << std::endl
    << "private:" << std::endl
    << "/// Map of factory methods for this paradigm." << std::endl
    << "ACE_Hash_Map_Manager <ACE_CString, FACTORY_METHOD, ACE_Null_Mutex> map_;"
    << "};"
    << "}"
    << "#endif" << std::endl;

  this->cxx_file_
    << std::endl
    << "namespace " << project_name
    << "{"
    << function_header_t ("Impl_Factory")
    << "Impl_Factory::Impl_Factory (void)"
    << "{";

  std::for_each (obj_mgr->objects ().begin (),
                 obj_mgr->objects ().end (),
                 bind_generator_t (this->cxx_file_));

  // Generate the bind method for the RootFolder, then end the
  // the constructor's implementation.
  this->cxx_file_
    << "this->map_.bind (\"RootFolder\", &::GAME::Mga::allocate_impl <GAME::Mga::RootFolder_Impl>);"
    << "}"
    << function_header_t ("~Impl_Factory")
    << "Impl_Factory::~Impl_Factory (void)"
    << "{"
    << "}"
    << function_header_t ("allocate")
    << "::GAME::Mga::Object_Impl * Impl_Factory::allocate (IMgaObject * ptr)"
    << "{"
    << "if (0 == ptr)" << std::endl
    << "  return 0;" << std::endl
    << std::endl
    << "CComPtr <IMgaMetaBase> metabase;"
    << "VERIFY_HRESULT (ptr->get_MetaBase (&metabase));"
    << std::endl
    << "CComBSTR bstr;"
    << "VERIFY_HRESULT (metabase->get_Name (&bstr));"
    << std::endl
    << "CW2A metaname (bstr);"
    << "FACTORY_METHOD factory_method = 0;"
    << std::endl
    << "if (0 == this->map_.find (metaname.m_psz, factory_method))" << std::endl
    << "  return factory_method (ptr);"
    << "else" << std::endl
    << "  return Impl_Factory_Base::allocate (ptr);"
    << "}"
    << "}";
}

}
}
