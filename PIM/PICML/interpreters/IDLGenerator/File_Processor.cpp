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
IDL_File_Processor::
IDL_File_Processor (IDL_File_Dependency_Processor & depends_graph,
                    IDLStream & idl_stream)
: depends_graph_ (depends_graph),
  idl_ (idl_stream)
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
  Find_Forward_Decls fwd_decls (this->depends_graph_);
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
  if (fwd_decls.has_component () || this->file_has_object_with_reference (file))
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

  this->depends_graph_.visit_file (file, *this, true);

  this->idl_ << nl;
}

//
// file_has_object_with_reference
//
bool IDL_File_Processor::
file_has_object_with_reference (const PICML::File & file)
{
  std::set <PICML::ProvidedRequestPort> pvdports;
  std::set <PICML::RequiredRequestPort> reqports;
  std::vector <PICML::Object> objects = file.Object_kind_children ();
  std::vector <PICML::Object>::iterator iter = objects.begin (),
                                        end = objects.end ();

  for (; iter != end; ++iter)
  {
    pvdports = (*iter).referedbyProvidedRequestPort ();
    reqports = (*iter).referedbyRequiredRequestPort ();
    if (pvdports.size () != 0 || reqports.size () != 0)
      return true;
  }

  return false;
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
  if (this->depends_graph_.no_forward_declaration (p))
    return;

  std::vector <PICML::TemplateParameter> params = p.TemplateParameter_kind_children ();

  if (params.empty () &&
     (this->depends_graph_.forward_declaration () ||
      this->depends_graph_.visit_template_module ()))
  {
    this->depends_graph_.visit_all (p, *this);
  }
}

//
// Visit_Aggregate
//
void IDL_File_Processor::Visit_Aggregate (const PICML::Aggregate & a)
{
  if (!this->depends_graph_.no_forward_declaration (a))
    this->idl_ << nl << "struct " << a.name () << ";" << nl;
}

//
// Visit_SwitchedAggregate
//
void IDL_File_Processor::
Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s)
{
  if (!this->depends_graph_.no_forward_declaration (s))
    this->idl_ << nl << "union " << s.name () << ";" << nl;
}

//
// Visit_Object
//
void IDL_File_Processor::Visit_Object (const PICML::Object & o)
{
  if (this->depends_graph_.no_forward_declaration (o))
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
  if (this->depends_graph_.no_forward_declaration (e))
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
  if (this->depends_graph_.no_forward_declaration (v))
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
  if (!this->depends_graph_.no_forward_declaration (p))
    this->idl_ << nl << "porttype " << p.name () << ";" << nl;
}

//
// Visit_Component
//
void IDL_File_Processor::Visit_Component (const PICML::Component & c)
{
  if (!this->depends_graph_.no_forward_declaration (c))
    this->idl_ << nl << "component " << c.name () << ";" << nl;
}