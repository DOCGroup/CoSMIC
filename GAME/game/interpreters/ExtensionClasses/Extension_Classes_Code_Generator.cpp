// $Id$

#include "StdAfx.h"
#include "StdAfx.cpp"

#include "Extension_Classes_Code_Generator.h"

namespace GAME
{

//
// Extension_Classes_Code_Generator
//
Extension_Classes_Code_Generator::
Extension_Classes_Code_Generator (std::string uc_paradigm_name,
                                  const GAME::FCO fco,
                                  std::string outdir)
: indentation_h_ ("  "),
  indentation_cpp_ ("  "),
  class_name_ (fco.name ()),
  meta_name_ (fco.meta ().name ()),
  path_ (fco.path ("\\", true)),
  uc_paradigm_name_ (uc_paradigm_name),
  done_inheriting_ (false),
  has_attribute_ (false),
  fco_ (fco),
  outdir_ (outdir)
{
}


//
// ~Extension_Classes_Code_Generator
//
Extension_Classes_Code_Generator::~Extension_Classes_Code_Generator (void)
{
}


//
// generate_default_functions
//
void Extension_Classes_Code_Generator::
generate_default_functions (std::string prefix_symbol,
                            std::string params,
                            std::string parent_cons)
{
  prefix_symbol.append (this->class_name_);

  this->default_member_functions_h_   << this->indentation_h_ << prefix_symbol
                                      << " (" << params.c_str () << ");"
                                      << std::endl << std::endl;

  this->default_member_functions_cpp_ << this->generate_function_comments_header (prefix_symbol);
  this->default_member_functions_cpp_ << this->class_name_ << "::" << prefix_symbol
                                      << " (" << params.c_str () << ")"
                                      << parent_cons.c_str () << std::endl << "{"
                                      << std::endl << "}" << std::endl << std::endl;
}


//
// generate_narrow
//
void Extension_Classes_Code_Generator::generate_narrow (void)
{
  // declaration _narrow ()
  this->member_functions_h_   << this->indentation_h_ << "static " << this->class_name_
                              << " _narrow (const GAME::Object & object);" << std::endl
                              << std::endl;

  // definition _narrow ()
  this->member_functions_cpp_ << this->generate_function_comments_header ("_narrow");
  this->member_functions_cpp_ << this->class_name_ << " " << this->class_name_
                              << "::_narrow (const GAME::Object & object)" << std::endl
                              << "{" << std::endl << this->indentation_cpp_
                              << "CComPtr <IMga" << this->meta_name_ << "> curr_type;"
                              << std::endl << std::endl << this->indentation_cpp_
                              << "VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&curr_type),"
                              << std::endl << "                           "
                              << "GAME::Invalid_Cast ());" << std::endl << std::endl
                              << this->indentation_cpp_ << "return curr_type.p;" << std::endl
                              << "}" << std::endl << std::endl;
}

//
// generate_create
//
void Extension_Classes_Code_Generator::generate_create (std::string name)
{
  this->add_h_includes (name);
  name.erase (0, (name.find_last_of ("/") + 1));

  this->member_functions_h_   << this->indentation_h_ << "static " << this->class_name_
                                << " _create (" << name << " parent);"
                                << std::endl << std::endl;

  // definition of _create ()
  this->member_functions_cpp_ << this->generate_function_comments_header ("_create");
  this->member_functions_cpp_ << this->class_name_ << " " << this->class_name_
                              << "::_create (" << name << " parent)" << std::endl
                              << "{" << std::endl << "  return GAME::" << this->meta_name_
                              << "::_create (parent, \"" << this->class_name_ << "\");"
                              << std::endl << "}" << std::endl << std::endl;
}

//
// add_inherited_class
//
void Extension_Classes_Code_Generator::add_inherited_class (std::string name)
{
  this->add_h_includes (name);
  name.erase (0, (name.find_last_of ("/") + 1));

  if (this->inherited_classes_.str () == "")
    this->inherited_classes_ << " : public " << name;
 else
   this->inherited_classes_ << ", public " << name;
}


//
// add_h_includes
//
void Extension_Classes_Code_Generator::add_h_includes (std::string name)
{
  this->classes_includes_ << "#include \"" << name << ".h\"" << std::endl;
}

//
// add_cpp_includes
//
void Extension_Classes_Code_Generator::add_cpp_includes (std::string name)
{
  this->cpp_includes_ << "#include \"" << name << ".h\"" << std::endl;
}


//
// generate_connector_connections
//
void Extension_Classes_Code_Generator::
generate_connector_connections (std::string name)
{
  this->add_cpp_includes (name);
  name.erase (0, (name.find_last_of ("/") + 1));

  this->forward_declerations_ << "class " << name << ";" << std::endl;

  std::string function_name = "in_";
  function_name.append (name);
  function_name.append ("_connections");

  // declaration in_TYPE_connections ()
  this->member_functions_h_   << this->indentation_h_ << "void "
                              << function_name << " (std::vector <"
                              << name << "> & conns);" << std::endl
                              << std::endl;

   // definition in_TYPE_connections ()
  this->member_functions_cpp_ << this->generate_function_comments_header (function_name);
  this->member_functions_cpp_ << "void " << this->class_name_ << "::"
                              << function_name << " (std::vector <"
                              << name << "> & conns)" << std::endl << "{" 
                              << std::endl << this->indentation_cpp_
                              << "std::vector <GAME::Connection> v;"
                              << std::endl << this->indentation_cpp_
                              << "this->in_connections (\"" << name << "\", v);"
                              << std::endl << std::endl << this->indentation_cpp_
                              << "std::vector <GAME::Connection>::iterator iter = v.begin ();"
                              << std::endl << this->indentation_cpp_
                              << "for (; iter != v.end (); ++ iter)" << std::endl
                              << this->indentation_cpp_ << "  v.push_back ("
                              << name << "::_narrow (*iter));"
                              << std::endl << "}" << std::endl << std::endl;
}


//
// generate_connection_end
//
void Extension_Classes_Code_Generator::
generate_connection_end (std::string role_name,
                         std::string name)
{
  this->add_h_includes (name);
  name.erase (0, (name.find_last_of ("/") + 1));

  // declaration src () or dst ()
  this->member_functions_h_   << this->indentation_h_ << name << " "
                              << role_name << " (void);" << std::endl
                              << std::endl;

  // definition src () or dst ()
  this->member_functions_cpp_ << this->generate_function_comments_header (role_name);
  this->member_functions_cpp_ << name << " " << this->class_name_ << "::"
                              << role_name << " (void)" << std::endl
                              << "{" << std::endl << this->indentation_cpp_
                              << "return " << name << "::"
                              << "_narrow (this->connection_point (\""
                              << role_name << "\").target ());" << std::endl
                              << "}" << std::endl << std::endl;
}


//
// generate_h_file
//
void Extension_Classes_Code_Generator::generate_h_file (void)
{
  // the complete file path
  std::ostringstream filename_h;
  filename_h << this->outdir_ << this->path_ << ".h";

  // open the document for writing the .h file.
  this->out_.open (filename_h.str ().c_str ());

  if (!this->out_.is_open ())
    return;

  this->out_ << "// -*- C++ -*-" << std::endl << std::endl;

  // generate the header preamble
  this->generate_header_preamble ();

  std::string ifndef  = this->fco_.path ("_", true);
  ifndef += "_H_";

  this->normalize (ifndef);

  std::transform (ifndef.begin (),
                  ifndef.end (),
                  ifndef.begin (),
                  & ::toupper);

  // add the #ifndef preprocessor
  this->out_ << "#ifndef " << ifndef << std::endl
             << "#define " << ifndef << std::endl
             << std::endl;

  // include file of the inherited parent if not included
  if (!this->done_inheriting_)
    this->classes_includes_ << "#include \"game/" << this->meta_name_
                            << ".h\"" << std::endl;

  // add include files to the output file
  this->out_ << this->classes_includes_.str ().c_str () << std::endl;

  if (this->forward_declerations_.str () != "")
    this->out_ << this->forward_declerations_.str ().c_str ()
               << std::endl << std::endl;

  this->out_ << "class " << this->uc_paradigm_name_
             << "_Export " << this->class_name_;

  // if object doesnot inherit object of its same type then
  // inherit the base GAME type
  if (!this->done_inheriting_)
  {
    if (this->inherited_classes_.str () == "")
      this->inherited_classes_ << " : public GAME::";
    else
      this->inherited_classes_ << ", public GAME::";

    this->inherited_classes_   << this->meta_name_;
  }

  this->out_ << this->inherited_classes_.str () << std::endl << "{"
             << std::endl << "public:" << std::endl
             << this->indentation_h_ << "static const std::string metaname;"
             << std::endl << std::endl
             << this->default_member_functions_h_.str ()
             << this->member_functions_h_.str ();

  if (!this->member_variables_.str ().empty ())
    this->out_ << std::endl << "private:" << std::endl 
               << this->member_variables_.str () << std::endl;

  this->out_ << "};" << std::endl << std::endl
             << "#endif // !defined " << ifndef
             << std::endl;

  // Close the output file.
  this->out_.close ();
}


//
// generate_cpp_file
//
void Extension_Classes_Code_Generator::generate_cpp_file (void)
{
  // the complete file path
  std::ostringstream filename_cpp;
  filename_cpp << this->outdir_ << this->path_ << ".cpp";

  // Open the document for writing .cpp file.
  this->out_.open (filename_cpp.str ().c_str ());

  if (!this->out_.is_open ())
    return;

  this->out_ << "// " << "$" << "Id" << "$"
             << std::endl << std::endl;

  this->out_ << "#include \"stdafx.h\"" << std::endl
             << "#include \"" << this->class_name_ << ".h\""
             << std::endl << std::endl;

  if (!this->cpp_includes_.str ().empty ())
    this->out_ << this->cpp_includes_.str ().c_str ()
               << std::endl;

  this->out_ << "const std::string " << this->class_name_
             << "::metaname = " << "\"" << this->class_name_
             << "\";" << std::endl << std::endl;

  this->out_ << this->default_member_functions_cpp_.str ()
             << this->member_functions_cpp_.str ();

  // Close the output file.
  this->out_.close ();
}


//
// set_inheritance_flag
//
void Extension_Classes_Code_Generator::set_inheritance_flag (void)
{
  this->done_inheriting_ = true;
}


//
// generate_attribute_list
//
void Extension_Classes_Code_Generator::generate_attribute_list (GAME::FCO fco)
{
  if (!this->has_attribute_)
    this->add_cpp_includes ("game/Attribute");

  this->has_attribute_ = true;

  std::string function_name, return_type;
  std::string name = fco.name ();
  std::string meta_name = fco.meta ().name ();

  if (meta_name == "BooleanAttribute")
  {
    function_name = "bool_value";
    return_type = "bool";
  }
  else if (meta_name == "EnumAttribute")
  {
    function_name = "string_value";
    return_type = "std::string";
  }
  else if (meta_name == "FieldAttribute")
  {
    std::string data_type = fco.attribute ("DataType").string_value ();

    if (data_type == "integer")
    {
      function_name = "int_value";
      return_type = "long";
    }
    else if (data_type == "string")
    {
      function_name = "string_value";
      return_type = "std::string";
    }
    else if (data_type == "double")
    {
      function_name = "float_value";
      return_type = "double";
    }
  }

  // generate functions for getting the value
  this->member_functions_h_   << this->indentation_h_ << return_type
                              << " " << name << " (void);"
                              << std::endl << std::endl;

  this->member_functions_cpp_ << this->generate_function_comments_header (name);
  this->member_functions_cpp_ << return_type << " " << this->class_name_
                              << "::" << name << " (void)" << std::endl
                              << "{" << std::endl << this->indentation_cpp_
                              << "static const std::string attrname (\"" << name << "\");"
                              << std::endl << this->indentation_cpp_ 
                              << "return this->attribute (attrname)."
                              << function_name << " ();" << std::endl
                              << "}" << std::endl << std::endl;
  
  // generate functions for setting the value
  this->member_functions_h_   << this->indentation_h_ << "void "
                              << name << " (" << return_type << " val);"
                              << std::endl << std::endl;

  this->member_functions_cpp_ << this->generate_function_comments_header (name);
  this->member_functions_cpp_ << "void " << this->class_name_ << "::"
                              << name << " (" << return_type << " val)"
                              << std::endl << "{" << std::endl
                              << this->indentation_cpp_ << "static const std::string attrname (\""
                              << name << "\");" << std::endl
                              << this->indentation_cpp_ << "this->attribute (attrname)."
                              << function_name << " (val);" << std::endl
                              << "}" << std::endl << std::endl;  
}


//
// generate_function_comments_header
//
std::string Extension_Classes_Code_Generator::generate_function_comments_header (std::string name)
{
  std::stringstream header;
  header << "//" << std::endl
         << "// " << name << std::endl
         << "//" << std::endl;

  return header.str ();
}

//
// generate_header_preamble
//
void Extension_Classes_Code_Generator::generate_header_preamble (void)
{
  this->out_ << "//================================================================="
             << "===============" << std::endl << "/**" << std::endl
             << " * @file       " << this->class_name_ << ".h" << std::endl
             << " *" << std::endl
             << " *" << " $" << "Id" << "$" << std::endl
             << " *" << std::endl
             << " * @author     Alhad Mokashi <amokashi at iupui dot edu>" << std::endl
             << " *             James H. Hill <hillj at cs dot iupui dot edu>"
             << std::endl << " *" << std::endl
             << " * This file was generated by the GAME extension "
             << "class interpreter," << std::endl
             << " * which is freely available in open-source format "
             << "for use on any" << std::endl
             << " * MetaGME project." << std::endl
             << " */" << std::endl
             << "//================================================================"
             << "================" << std::endl << std::endl;
}

//
// normalize
//
void Extension_Classes_Code_Generator::normalize (std::string & text)
{
  static const char * special = "{}|[]^.()+*?\\-@#!$%&;'/<>,~`";
  std::string::size_type found = text.find_first_of (special);

  while (found != std::string::npos)
  {
    text.erase (found, 1);
    found = text.find_first_of (special, found);
  }
}

}