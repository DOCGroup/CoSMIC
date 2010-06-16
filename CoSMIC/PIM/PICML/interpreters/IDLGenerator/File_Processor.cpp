// $Id$

#include "StdAfx.h"
#include "File_Processor.h"
#include "Find_Forward_Decls.h"
#include "IDLStream.h"

#include "Utils/UDM/visit.h"

//
// IDL_File_Processor
//
IDL_File_Processor::IDL_File_Processor (IDLStream & idl_stream)
: idl_ (idl_stream)
{

}

//
// ~IDL_File_Processor
//
IDL_File_Processor::~IDL_File_Processor (void)
{

}

//
// Visit_File
//
void IDL_File_Processor::Visit_File (const PICML::File & file)
{
  // Locate all the forward declarations of this file.
  Find_Forward_Decls fwd_decls;
  PICML::File (file).Accept (fwd_decls);

  // Generate the basename for this file.
  std::string basename (file.Path ());

  if (!basename.empty ())
    basename.append ("/");

  basename.append (file.name ());

  if (fwd_decls.has_component ())
    this->idl_ << "#include <Components.idl>" << nl;

  // Generate the include files for this file.
  std::for_each (fwd_decls.includes ().begin (),
                 fwd_decls.includes ().end (),
                 boost::bind (&IDL_File_Processor::generate_include_file,
                              this,
                              _1));

  if (fwd_decls.has_component ())
  {
    // Write the pragma statement for the local executor mapping.
    this->idl_ << nl 
               << "#pragma ciao lem \"" << basename << "E.idl\"" << nl;
  }

  if (fwd_decls.has_typesupport ())
  {
    // Write the pragma statement for the type support.
    this->idl_ << nl
               << "#pragma ndds typesupport \"" << basename << "Support.h\"" << nl
               << "#pragma opendds typesupport \"" << basename << "TypeSupportC.h\"" << nl
               << "#pragma splice typesupport \"" << basename << "DscpC.h\"" << nl;
  }

  // Write any of the preprocessor directives that should occur 
  // before the file's content.
  std::string directives = file.PrePreprocessorDirectives ();

  if (!directives.empty ())
    this->idl_ << nl << directives << nl;

  this->idl_ << nl
             << "// forward declaration(s)" << nl
             << nl;

  // Now, let's generate every element that can be forward declared. This 
  // is not the most optimal way of doing things, but it will ensure that 
  // all referenced elements are declared before they are used. In the 
  // future, we should optimize this approach.
  this->Visit_FilePackage (file);

  // Write any of the preprocessor directives that should occur 
  // after the file's content.
  directives = file.PostPreprocessorDirectives ();

  if (!directives.empty ())
    this->idl_ << nl << directives << nl;

  this->idl_ << nl;
}

//
// generate_include_file
//
void IDL_File_Processor::generate_include_file (const PICML::File &file)
{
  std::string path = file.Path ();
  
  if (path.empty ())
    path = ".";

  this->idl_ << "#include \"" << path << "/" << file.name () << ".idl\"" << nl;
}

//
// Visit_Package
//
void IDL_File_Processor::Visit_Package (const PICML::Package & p)
{
  std::vector <PICML::TemplateParameter> params = p.TemplateParameter_kind_children ();

  if (params.empty ())
  {
    this->idl_ << "module " << p.name () << nl 
               << "{" << idt_nl;

    this->Visit_FilePackage (p);

    this->idl_ << uidt_nl << "};";
  }
}

//
// Visit_FilePackage
//
void IDL_File_Processor::Visit_FilePackage (const Udm::Object & object)
{
  // aggregations
  Udm::visit_all <PICML::Aggregate> (object, *this);
  Udm::visit_all <PICML::SwitchedAggregate> (object, *this);

  // object by value types
  Udm::visit_all <PICML::ValueObject> (object, *this);
  Udm::visit_all <PICML::Event> (object, *this);
  
  // interfaces
  Udm::visit_all <PICML::Object> (object, *this);
  //Udm::visit_all <PICML::PortType> (object, *this);

  // components
  Udm::visit_all <PICML::Component> (object, *this);
  Udm::visit_all <PICML::ConnectorObject> (object, *this);

  Udm::visit_all <PICML::Package> (object, *this);
}

//
// Visit_Aggregate
//
void IDL_File_Processor::Visit_Aggregate (const PICML::Aggregate & a)
{
  this->idl_ << nl << "struct " << a.name () << ";";
}

//
// Visit_SwitchedAggregate
//
void IDL_File_Processor::
Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s)
{
  this->idl_ << nl << "union " << s.name () << ";";
}

//
// Visit_Object
//
void IDL_File_Processor::Visit_Object (const PICML::Object & o)
{
  this->idl_ << nl;
  
  std::string semantics = o.InterfaceSemantics ();

  if (semantics == "local")
    this->idl_ << "local ";
  else if (semantics == "abstract")
    this->idl_ << "abstract ";

  this->idl_ << "interface " << o.name () << ";";
}

//
// Visit_Event
//
void IDL_File_Processor::Visit_Event (const PICML::Event & e)
{
  this->idl_ << nl;
  
  if (e.abstract ())
    this->idl_ << "abstract ";

  this->idl_ << "eventtype " << e.name () << ";";
}

//
// Visit_ValueObject
//
void IDL_File_Processor::Visit_ValueObject (const PICML::ValueObject & v)
{
  this->idl_ << nl;
  
  if (v.abstract ())
    this->idl_ << "abstract ";

  this->idl_ << "valuetype " << v.name () << ";";
}

//
// Visit_PortType
//
void IDL_File_Processor::
Visit_PortType (const PICML::PortType & p)
{
  this->idl_ << nl << "porttype " << p.name () << ";";
}

//
// Visit_Component
//
void IDL_File_Processor::Visit_Component (const PICML::Component & c)
{
  this->idl_ << nl << "component " << c.name () << ";";
}
