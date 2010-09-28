// $Id$

#include "StdAfx.h"
#include "File_Processor.h"
#include "Find_Forward_Decls.h"
#include "IDL_File_Dependency_Processor.h"
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

  // Write the pragma statement for the local executor mapping.
  if (fwd_decls.has_component ())
    this->idl_ << nl
               << "#pragma ciao lem \"" << basename << "E.idl\"" << nl;

  // Write the pragma statement for ami4ccm.
  if (fwd_decls.has_ami4ccm ())
    this->idl_ << nl
               << "#pragma ciao ami4ccm idl \"" << basename << "A.idl\"" << nl
               << "#pragma ciao lem \"" << basename << "AE.idl\"" << nl;

  // Write the pragma statement for the type support.
  if (fwd_decls.has_typesupport ())
    this->idl_ << nl
               << "#pragma ndds typesupport \"" << basename << "Support.h\"" << nl
               << "#pragma opendds typesupport \"" << basename << "TypeSupportC.h\"" << nl
               << "#pragma splice typesupport \"" << basename << "DscpC.h\"" << nl;

  IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->visit_file (file, *this, true);

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
  if (IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->no_forward_declaration (p))
    return;

  std::vector <PICML::TemplateParameter> params = p.TemplateParameter_kind_children ();

  using namespace IDL_GENERATOR;

  if (params.empty () && (GLOBAL_IDL_DEPEND_PROCESSOR::instance()->forward_declaration () ||
      GLOBAL_IDL_DEPEND_PROCESSOR::instance()->visit_template_module ()))
  {
    IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->visit_all (p, *this);
  }
}

//
// Visit_Aggregate
//
void IDL_File_Processor::Visit_Aggregate (const PICML::Aggregate & a)
{
  if (IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->no_forward_declaration (a))
    return;

  this->idl_ << nl << "struct " << a.name () << ";" << nl;
}

//
// Visit_SwitchedAggregate
//
void IDL_File_Processor::
Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s)
{
  if (IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->no_forward_declaration (s))
    return;

  this->idl_ << nl << "union " << s.name () << ";" << nl;
}

//
// Visit_Object
//
void IDL_File_Processor::Visit_Object (const PICML::Object & o)
{
  if (IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->no_forward_declaration (o))
    return;
    
  this->idl_ << nl;

  std::string semantics = o.InterfaceSemantics ();

  if (semantics == "local")
    this->idl_ << "local " << nl;
  else if (semantics == "abstract")
    this->idl_ << "abstract " << nl;

  this->idl_ << "interface " << o.name () << ";" << nl;
}

//
// Visit_Event
//
void IDL_File_Processor::Visit_Event (const PICML::Event & e)
{
  if (IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->no_forward_declaration (e))
    return;

  this->idl_ << nl;

  if (e.abstract ())
    this->idl_ << "abstract " << nl;

  this->idl_ << "eventtype " << e.name () << ";" << nl;
}

//
// Visit_ValueObject
//
void IDL_File_Processor::Visit_ValueObject (const PICML::ValueObject & v)
{
  if (IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->no_forward_declaration (v))
    return;

  this->idl_ << nl;

  if (v.abstract ())
    this->idl_ << "abstract "<< nl;

  this->idl_ << "valuetype " << v.name () << ";"<< nl;
}

//
// Visit_PortType
//
void IDL_File_Processor::
Visit_PortType (const PICML::PortType & p)
{
  if (IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->no_forward_declaration (p))
    return;

  this->idl_ << nl << "porttype " << p.name () << ";" << nl;
}

//
// Visit_Component
//
void IDL_File_Processor::Visit_Component (const PICML::Component & c)
{
  if (IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->no_forward_declaration (c))
    return;
    
  this->idl_ << nl << "component " << c.name () << ";" << nl;
}
