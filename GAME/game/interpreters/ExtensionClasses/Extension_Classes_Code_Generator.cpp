#include "StdAfx.h"
#include "StdAfx.cpp"

#include "Extension_Classes_Code_Generator.h"

namespace GAME
{

//
// Extension_Classes_Code_Generator
//
Extension_Classes_Code_Generator::Extension_Classes_Code_Generator (std::string fname,
                                                                    std::string mname,
                                                                    std::string fpath,
                                                                    std::string uc_paradigm_name,
                                                                    std::string inner_location)
: indentation_h_ ("  "),
  indentation_cpp_ ("  "),
  class_name_ (fname),
  meta_name_ (mname),
  path_ (fpath),
  uc_paradigm_name_ (uc_paradigm_name),
  inner_location_ (inner_location),
  done_inheriting_ (false),
  has_attribute_ (false),
  is_in_connections_ (false)
{
}


//
// ~Extension_Classes_Code_Generator
//
Extension_Classes_Code_Generator::~Extension_Classes_Code_Generator (void)
{
}


//
// generate_default_functions ()
//
void Extension_Classes_Code_Generator::generate_default_functions
                                       (std::string prefix_symbol,
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
// generate_narrow ()
//
void Extension_Classes_Code_Generator::generate_narrow ()
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
                              << "GAME::Invalid_Cast ());" << std::endl << std::endl
                              << this->indentation_cpp_ << "return curr_type.p;" << std::endl
                              << "}" << std::endl << std::endl;
}


//
// generate_create ()
//
void Extension_Classes_Code_Generator::generate_create ()
{
  if (this->meta_name_ == "Connection")
  {
    this->add_includes ("game/FCO");
    this->add_includes ("game/Model");
    this->add_includes ("game/MetaModel");

    // declaration _create () for CONNECTION type
    this->member_functions_h_   << this->indentation_h_ << "static " << this->class_name_
                                << " _create (const GAME::Model & parent, const std::string & name,"
                                << "const GAME::FCO & src, const GAME::FCO & dst);"
                                << std::endl << std::endl;

    // definition _create () for CONNECTION type
    this->member_functions_cpp_ << this->generate_function_comments_header ("_create");
    this->member_functions_cpp_ << this->class_name_ << " " << this->class_name_
                                << "::_create (const GAME::Model & parent, const std::string & name,"
                                << " const GAME::FCO & src, const GAME::FCO & dst)" << std::endl
                                << "{" << std::endl << this->indentation_cpp_
                                << "GAME::Meta::Role role = parent.meta ().role (name);"
                                << std::endl << this->indentation_cpp_
                                << "CComPtr <IMgaFCO> conn;" << std::endl
                                << this->indentation_cpp_ << "VERIFY_HRESULT (parent.impl ()"
                                << " ->CreateSimpleConn (role, src.impl (), dst.impl (),"
                                << " 0, 0, &conn));" << std::endl << this->indentation_cpp_
                                << "return " << this->class_name_ <<"::_narrow (FCO (conn));"
                                << std::endl << "}" << std::endl << std::endl;
  }
  else
  {
    if (this->meta_name_ != "Model")
      this->add_includes ("game/Model");

    this->add_includes ("game/MetaModel");

    // declaration _create (GAME::Model & parent, const std::string & type)
    this->member_functions_h_   << this->indentation_h_ << "static " << this->class_name_
                                << "  _create (GAME::Model & parent, const std::string & type);"
                                << std::endl << std::endl;

    // definition _create (GAME::Model & parent, const std::string & type)
    this->member_functions_cpp_ << this->generate_function_comments_header ("_create");
    this->member_functions_cpp_ << this->class_name_ << " " << this->class_name_
                                << "::_create (GAME::Model & parent, const std::string & type)"
                                << std::endl << "{" << std::endl << this->indentation_cpp_
                                << "GAME::Meta::Role role = parent.meta ().role (type);"
                                << std::endl << std::endl << this->indentation_cpp_ << "return "
                                << this->class_name_ <<"::_create (parent, role);" << std::endl
                                << "}" << std::endl << std::endl;

    // declaration _create (GAME::Model & parent, const GAME::Meta::Role & type)
    this->member_functions_h_   << this->indentation_h_ << "static " << this->class_name_
                                << "  _create (GAME::Model & parent, const GAME::Meta::Role & type);"
                                << std::endl << std::endl;

     // definition _create (GAME::Model & parent, const GAME::Meta::Role & type)
    this->member_functions_cpp_ << this->generate_function_comments_header ("_create");
    this->member_functions_cpp_ << this->class_name_ << " " << this->class_name_
                                << "::_create (GAME::Model & parent, const GAME::Meta::Role & role)"
                                << std::endl << "{" << std::endl << this->indentation_cpp_
                                << "CComPtr <IMgaFCO> child;" << std::endl << std::endl
                                << this->indentation_cpp_
                                << "VERIFY_HRESULT (parent.impl ()->CreateChildObject (role, &child));"
                                << std::endl << std::endl << this->indentation_cpp_ << "return ";

    // if the current object is of type FCO then retupn it else convert it
    // to the type of current object using _narrow
    (this->meta_name_ == "FCO")? this->member_functions_cpp_ << "child.p;" :
                                 this->member_functions_cpp_ << this->class_name_ << "::_narrow (FCO (child));";

     this->member_functions_cpp_ << std::endl << "}" << std::endl << std::endl;

    if (this->meta_name_ != "FCO")
    {
      this->add_includes ("game/Folder");

      // declaration _create (GAME::Folder & parent, const std::string & type)
      this->member_functions_h_   << this->indentation_h_ << "static " << this->class_name_
                                  << "  _create (GAME::Folder & parent, const std::string & type);"
                                  << std::endl << std::endl;

      // definition _create (GAME::Folder & parent, const std::string & type)
      this->member_functions_cpp_ << this->generate_function_comments_header ("_create");
      this->member_functions_cpp_ << this->class_name_ << " " << this->class_name_
                                  << "::_create (GAME::Folder & parent, const std::string & type)"
                                  << std::endl << "{" << std::endl << this->indentation_cpp_
                                  << "GAME::Meta::FCO role = parent.meta ().child (type);"
                                  << std::endl << std::endl << this->indentation_cpp_ << "return "
                                  << this->class_name_ <<"::_create (parent, role);" << std::endl
                                  << "}" << std::endl << std::endl;

      // declaration _create (GAME::Folder & parent, const GAME::Meta::FCO & type)
      this->member_functions_h_   << this->indentation_h_ << "static " << this->class_name_
                                  << "  _create (GAME::Folder & parent, const GAME::Meta::FCO & type);"
                                  << std::endl << std::endl;

      // definition _create (GAME::Folder & parent, const GAME::Meta::FCO & type)
      this->member_functions_cpp_ << this->generate_function_comments_header ("_create");
      this->member_functions_cpp_ << this->class_name_ << " " << this->class_name_
                                  << "::_create (GAME::Folder & parent, const GAME::Meta::FCO & type)"
                                  << std::endl << "{" << std::endl << this->indentation_cpp_
                                  << "CComPtr <IMgaFCO> child;" << std::endl << std::endl
                                  << this->indentation_cpp_
                                  << "VERIFY_HRESULT (parent.impl ()->CreateRootObject (type.impl (), &child));"
                                  << std::endl << std::endl << this->indentation_cpp_ << "return "
                                  << this->class_name_ << "::_narrow (FCO (child));" << std::endl
                                  << "}" << std::endl << std::endl;
    }
  }
}


//
// add_inherited_class
//
void Extension_Classes_Code_Generator::add_inherited_class (std::string name)
{
  if (this->inherited_classes_.str () == "")
    this->inherited_classes_ << " : public " << name;
 else
   this->inherited_classes_ << ", public " << name;

  this->add_includes (name);
}


//
// add_includes
//
void Extension_Classes_Code_Generator::add_includes (std::string name)
{
  this->classes_includes_ << "#include \"" << name << ".h\"" << std::endl;
}


//
// generate_connector_connections ()
//
void Extension_Classes_Code_Generator::generate_connector_connections (std::string name)
{
  if (!this->is_in_connections_)
    this->add_includes ("game/Connection");

  this->is_in_connections_ = true;

  this->forward_declerations_ << "class " << name << ";" << std::endl;
  this->cpp_includes_ << "#include \"" << name << ".h\"" << std::endl;

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
// generate_connection_end ()
//
void Extension_Classes_Code_Generator::generate_connection_end (std::string role_name,
                                                                std::string name)
{
  this->add_includes (name);

  // declaration src () or dst ()
  this->member_functions_h_   << this->indentation_h_ << name << " "
                              << role_name << " ();" << std::endl
                              << std::endl;

  // definition src () or dst ()
  this->member_functions_cpp_ << this->generate_function_comments_header (role_name);
  this->member_functions_cpp_ << name << " " << this->class_name_ << "::"
                              << role_name << " ()" << std::endl
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
  filename_h << this->path_ << "/" << this->class_name_ << ".h";

  std::string upper_class_name = this->class_name_;
  std::transform (upper_class_name.begin (), upper_class_name.end (),
                  upper_class_name.begin (), ::toupper);

  // open the document for writing the .h file.
  this->out_.open (filename_h.str ().c_str ());

  if (!this->out_.is_open ())
    return;

  std::stringstream full_path_ifndef;
  full_path_ifndef << this->uc_paradigm_name_ << "_" << this->inner_location_
                   << "_" << upper_class_name << "_H_";

  // add the #ifndef preprocessor
  this->out_ << "#ifndef _" << full_path_ifndef.str () << std::endl
             << "#define _" << full_path_ifndef.str () << std::endl
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
             << this->default_member_functions_h_.str ()
             << this->member_functions_h_.str ();

  if (!this->member_variables_.str ().empty ())
    this->out_ << std::endl << "private:" << std::endl 
               << this->member_variables_.str () << std::endl;

  this->out_ << "};" << std::endl << std::endl
             << "#endif // !defined " << full_path_ifndef.str ();

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
  filename_cpp << this->path_ << "/" << this->class_name_ << ".cpp";

  // Open the document for writing .cpp file.
  this->out_.open (filename_cpp.str ().c_str ());

  if (!this->out_.is_open ())
    return;

  this->out_ << "#include \"stdafx.h\"" << std::endl
             << "#include \"" << this->class_name_ << ".h\""
             << std::endl << std::endl;

  if (!this->cpp_includes_.str ().empty ())
    this->out_ << this->cpp_includes_.str ().c_str ()
               << std::endl << std::endl;

  this->out_ << this->default_member_functions_cpp_.str ();
  this->out_ << this->member_functions_cpp_.str ();

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
// generate_attribute_list ()
//
void Extension_Classes_Code_Generator::generate_attribute_list (GAME::FCO fco)
{
  if (!this->has_attribute_)
    this->add_includes ("game/Attribute");

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
                              << " " << name << " ();"
                              << std::endl << std::endl;

  this->member_functions_cpp_ << this->generate_function_comments_header (name);
  this->member_functions_cpp_ << return_type << " " << this->class_name_
                              << "::" << name << " ()" << std::endl
                              << "{" << std::endl << this->indentation_cpp_
                              << "return this->attribute (\"" << name << "\")."
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
                              << this->indentation_cpp_
                              << "this->attribute (\"" << name << "\")."
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
         << "// " << name << " ()" << std::endl
         << "//" << std::endl;

  return header.str ();
}

}