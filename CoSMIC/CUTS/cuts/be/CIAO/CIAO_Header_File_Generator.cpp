// $Id$

#include "CIAO_Header_File_Generator.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Header_File_Generator.inl"
#endif

#include "CIAO_Var_Type.h"
#include "CIAO_Retn_Type.h"
#include "CIAO_In_Type.h"
#include "Export_File_Generator.h"
#include "cuts/be/Preprocess_Data.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <algorithm>
#include <sstream>

//
// CUTS_CIAO_Header_File_Generator
//
CUTS_CIAO_Header_File_Generator::
CUTS_CIAO_Header_File_Generator (void)
{

}

//
// ~CUTS_CIAO_Header_File_Generator
//
CUTS_CIAO_Header_File_Generator::
~CUTS_CIAO_Header_File_Generator (void)
{

}

//
// open
//
void CUTS_CIAO_Header_File_Generator::
open (const std::string & pathname)
{
  CUTS_CIAO_Header_File_Generator g;

  std::ostringstream filename;
  filename << pathname << "_exec_i.h";

  this->open_i (filename.str ());
}

//
// write_preamble
//
void CUTS_CIAO_Header_File_Generator::
write_preamble (const PICML::ComponentImplementationContainer & container)
{
  // Create the export file generator for this container.
  std::string export_name = container.name ();
  export_name.append ("_exec");
  this->export_.reset (new CUTS_Export_File_Generator (export_name));

  // Generate the hash definition for this file.
  std::string hashdef = container.name ();
  this->to_upper (hashdef);

  this->out_
    << "// -*- C++ -*-" << std::endl
    << std::endl
    << "#ifndef _" << hashdef << "_EXEC_I_H_" << std::endl
    << "#define _" << hashdef << "_EXEC_I_H_" << std::endl
    << std::endl
    << "#if !defined (ACE_LACKS_PRAGMA_ONCE)" << std::endl
    << "#pragma once" << std::endl
    << "#endif /* ACE_LACKS_PRAGMA_ONCE */" << std::endl
    << std::endl
    << "#include /**/ \"ace/pre.h\"" << std::endl
    << std::endl
    << "#include \"" << container.name () << "_svnt.h\"" << std::endl
    << "#include \"" << this->export_->export_file () << "\"" << std::endl
    << std::endl
    << "#include \"cuts/config.h\"" << std::endl
    << "#include \"cuts/CCM_CoWorkEr_T.h\"" << std::endl
    << "#include \"cuts/CCM_Factory_T.h\"" << std::endl
    << "#include \"cuts/Trigger_T.h\"" << std::endl
    << std::endl;
}

//
// write_postamble
//
void CUTS_CIAO_Header_File_Generator::
write_postamble (const PICML::ComponentImplementationContainer & container)
{
  std::string hashdef = container.name ();
  this->to_upper (hashdef);

  this->out_
    << "#include /**/ \"ace/post.h\"" << std::endl
    << std::endl
    << "#endif  // !defined _" << hashdef << "_EXEC_I_H_" << std::endl;
}

//
// write_component_begin
//
void CUTS_CIAO_Header_File_Generator::
write_component_begin (const PICML::Component & component)
{
  // Construct the commonly used names.
  std::string name (component.name ());

  std::string exec (component.name ());
  exec.append ("_Exec");

  std::string context (component.name ());
  context.append ("_Context");

  // Write the class declaration for the component.
  this->out_
    << "class " << this->export_->export_macro () << " "
    << name << " :" << std::endl
    << "public CUTS_CCM_CoWorkEr_T <" << exec << ", " << context << "> {"
    << "public:" << std::endl;

  // Write the type definition for this component.
  this->write_single_line_comment ("Type definition of this component");
  this->out_ << "typedef " << component.name () << " This_Component;";
  this->out_ << std::endl;

  // Write the type definition for the CoWorkEr type.
  this->write_single_line_comment ("Type definition of the CoWorkEr type.");
  this->out_
    << "typedef CUTS_CCM_CoWorkEr_T <" << std::endl
    << "  " << exec << "," << std::endl
    << "  " << context << "> _coworker_type;"
    << std::endl;

  // @@ constructor
  this->write_single_line_comment ("Default constructor.");
  this->out_ << name << " (void);" << std::endl;

  // @@ destructor
  this->write_single_line_comment ("Destructor.");
  this->out_ << "virtual ~" << name << " (void);" << std::endl;
}

//
// write_component_end
//
void CUTS_CIAO_Header_File_Generator::
write_component_end (const PICML::Component & component)
{
  // Write the event handlers for the component.
  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set sinks = component.InEventPort_kind_children ();

  typedef void (CUTS_CIAO_Header_File_Generator::*BE_METHOD_EVENT_SINK)
    (const PICML::InEventPort &);

  std::for_each (sinks.begin (),
                 sinks.end (),
                 boost::bind (static_cast <BE_METHOD_EVENT_SINK> (
                              &CUTS_CIAO_Header_File_Generator::write_variable),
                              boost::ref (*this),
                              _1));

  // Write the periodic event declarations.
  typedef std::set <PICML::PeriodicAction> Periodic_Set;
  Periodic_Set periodics = component.PeriodicAction_kind_children ();

  typedef void (CUTS_CIAO_Header_File_Generator::*BE_METHOD_PERIODIC)
    (const PICML::PeriodicAction &);

  std::for_each (periodics.begin (),
                 periodics.end (),
                 boost::bind (static_cast <BE_METHOD_PERIODIC> (
                              &CUTS_CIAO_Header_File_Generator::write_variable),
                              boost::ref (*this),
                              _1));

  this->out_ << "public:" << std::endl;
  CUTS_CIAO_File_Generator_Base::write_component_end (component);
  this->out_ << "};";
}

//
// write_monolithic_begin
//
void CUTS_CIAO_Header_File_Generator::
write_monolithic_begin (const PICML::MonolithicImplementation & mono)
{
  // Write the remaining of the include files before we go into
  // writing the rest of the monolithic declaration.
  std::for_each (
    this->preprocess_data ().headers ().begin (),
    this->preprocess_data ().headers ().end (),
    boost::bind (&CUTS_CIAO_Header_File_Generator::write_include_file,
                 this,
                 _1));

  this->out_ << std::endl;

  CUTS_CIAO_File_Generator_Base::write_monolithic_begin (mono);
}

//
// write_method_begin
//
void CUTS_CIAO_Header_File_Generator::
write_method_begin (const PICML::InEventPort & sink)
{
  std::string comment ("EventSink: ");
  comment.append (sink.name ());

  this->write_single_line_comment (comment);
  this->out_ << "virtual void ";
  CUTS_CIAO_File_Generator_Base::write_method_begin (sink);
  this->out_ << ";" << std::endl;
}

//
// write_method_begin
//
void CUTS_CIAO_Header_File_Generator::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  std::string comment ("Facet: ");
  comment.append (facet.name ());

  this->write_single_line_comment (comment);
  this->out_ << "virtual void ";
  CUTS_CIAO_File_Generator_Base::write_method_begin (facet);
  this->out_ << ";" << std::endl;
}

//
// write_set_session_context
//
void CUTS_CIAO_Header_File_Generator::
write_set_session_context (const PICML::Component & component)
{
  this->out_ << "virtual void ";
  this->_super::write_set_session_context (component);
  this->out_ << ";" << std::endl;
}

//
// write_ciao_preactivate
//
void CUTS_CIAO_Header_File_Generator::
write_ciao_preactivate (const PICML::Component & component)
{
  this->out_ << "virtual void ";
  this->_super::write_ciao_preactivate (component);
  this->out_ << ";" << std::endl;
}

//
// write_cmm_activate
//
void CUTS_CIAO_Header_File_Generator::
write_ccm_activate (const PICML::Component & component)
{
  this->write_single_line_comment ("Environment: activate");
  this->out_ << "virtual void ";
  this->_super::write_ccm_activate (component);
  this->out_ << ";" << std::endl;
}

//
// write_ciao_postactivate
//
void CUTS_CIAO_Header_File_Generator::
write_ciao_postactivate (const PICML::Component & component)
{
  this->out_ << "virtual void ";
  this->_super::write_ciao_postactivate (component);
  this->out_ << ";" << std::endl;
}

//
// write_ccm_passivate
//
void CUTS_CIAO_Header_File_Generator::
write_ccm_passivate (const PICML::Component & component)
{
  this->out_ << "virtual void ";
  this->_super::write_ccm_passivate (component);
  this->out_ << ";" << std::endl;
}

//
// write_ccm_remove
//
void CUTS_CIAO_Header_File_Generator::
write_ccm_remove (const PICML::Component & component)
{
  this->out_ << "virtual void ";
  this->_super::write_ccm_remove (component);
  this->out_ << ";" << std::endl;
}

//
// write_variable_begin
//
void CUTS_CIAO_Header_File_Generator::write_variables_begin (void)
{
  this->out_ << "private:" << std::endl;
}

//
// write_variable
//
void CUTS_CIAO_Header_File_Generator::
write_variable (const PICML::WorkerType & worker_type)
{
  PICML::Worker worker = worker_type.ref ();

  std::string comment ("Worker: ");
  comment.append (worker_type.name ());

  this->write_single_line_comment (comment);
  this->out_
    << worker.name ()
    << " " << worker_type.name () << "_;"
    << std::endl;
}

//
// write_variable
//
void CUTS_CIAO_Header_File_Generator::
write_variable (const PICML::Variable & variable)
{
  // Create a comment string and write it.
  std::string comment ("Variable: ");
  comment.append (variable.name ());
  this->write_single_line_comment (comment);

  // Write the variable type.
  PICML::PredefinedType ptype = variable.ref ();
  CUTS_CIAO_Var_Type_T <PICML::PredefinedType>::write (this->out_, ptype);

  // Write the varialbe name.
  this->out_ << " " << variable.name () << "_;" << std::endl;
}

//
// write_variable
//
void CUTS_CIAO_Header_File_Generator::
write_variable (const PICML::InEventPort & sink)
{
  // Write the leading comment.
  std::string comment ("Event handler: ");
  comment.append (sink.name ());
  this->write_single_line_comment (comment);

  PICML::Event event = sink.ref ();
  if (event == Udm::null)
    return;

  // Write the emulated event handler method.
  this->out_
    << "void push_" << sink.name () << "_handler (" << std::endl;

  this->write_scope (PICML::NamedType::Cast (event), "::");

  this->out_
    << event.name () << " * ev, CUTS_Activation_Record * record);"
    << std::endl

    // Write the event handler variable.
    << "CUTS_Event_Handler_Manager_T <" << std::endl
    << "  This_Component, ";

  this->write_scope (PICML::NamedType::Cast (event), "::");

  this->out_
    << event.name () << "> "
    << "push_" << sink.name () << "_handler_;"
    << std::endl;
}

//
// write_variable
//
void CUTS_CIAO_Header_File_Generator::
write_variable (const PICML::PeriodicAction & periodic)
{
  // Write the leading comment.
  std::string comment ("Periodic: ");
  comment.append (periodic.name ());
  this->write_single_line_comment (comment);

  this->out_
    << "CUTS_Periodic_Trigger_T <This_Component> periodic_"
    << periodic.name () << "_;" << std::endl;
}

//
// write_variables_end
//
void CUTS_CIAO_Header_File_Generator::write_variables_end (void)
{

}

//
// write_method_begin
//
void CUTS_CIAO_Header_File_Generator::
write_method_begin (const PICML::PeriodicAction & periodic)
{
  std::string comment ("Periodic event: ");
  comment.append (periodic.name ());
  this->write_single_line_comment (comment);

  this->out_
    << "void periodic_"  << periodic.name () << " (void);"
    << std::endl;
}

//
// write_component_factory_begin
//
void CUTS_CIAO_Header_File_Generator::
write_component_factory_begin (const PICML::ComponentFactory & factory,
                               const PICML::Component & component)
{
  std::string factory_name;

  if (factory != Udm::null)
    factory_name = factory.name ();
  else
  {
    factory_name = component.name ();
    factory_name.append ("PICMLDefaultHome");
  }

  this->out_
    // Define the component home.
    << "class " << this->export_->export_macro () << " "
    << factory_name << " :" << std::endl
    << "  public CUTS_CCM_Factory_T <" << factory_name << "_Exec, "
    << component.name () << "> {"
    << "public:" << std::endl

    // Generate the constructor and destructor.
    << "// Default constructor." << std::endl
    << factory_name << " (void);"
    << std::endl
    << "// Destructor." << std::endl
    << "virtual ~" << factory_name << " (void);"
    << "};"
    << "CUTS_FACTORY_EXPORT_DECLARE ("
    << this->export_->export_macro () << "," << std::endl
    << "create_";

  this->write_scope (component, "_");
  this->out_ << factory_name << "_Impl);";
}

//
// write_variable
//
void CUTS_CIAO_Header_File_Generator::
write_variable (const PICML::ReadonlyAttribute & attr)
{
  // Check for the attribute member..
  PICML::AttributeMember member = attr.AttributeMember_child ();

  if (member != Udm::null)
  {
    // Now, let's get its type.
    PICML::MemberType mtype = member.ref ();

    if (mtype != Udm::null)
    {
      // Write a header comment for the attribute.
      std::string comment ("Attribute: ");
      comment += attr.name ();
      this->write_single_line_comment (comment);

      // Write the variable type.
      CUTS_CIAO_Var_Type_T <PICML::MemberType>::write (this->out_, mtype);

      // Write the name of the variable.
      this->out_ << " " << attr.name () << "_;" << std::endl;
    }
  }
}

//
// write_variable
//
void CUTS_CIAO_Header_File_Generator::
write_variable (const PICML::Attribute & attr)
{
  PICML::ReadonlyAttribute readonly (attr);
  this->write_variable (readonly);
}

//
// write_method_begin
//
void CUTS_CIAO_Header_File_Generator::
write_method_begin (const PICML::ReadonlyAttribute & attr)
{
  PICML::AttributeMember member = attr.AttributeMember_child ();
  PICML::MemberType mtype = member.ref ();

  // Write the getter method for the attribute.
  this->out_ << "virtual ";

  CUTS_CIAO_Retn_Type_T <PICML::MemberType>::write (this->out_, mtype);
  PICML::Component parent = attr.Component_parent ();

  this->out_
    << " " << attr.name () << " (" <<std::endl
    << "void ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "\tACE_THROW_SPEC ((::CORBA::SystemException));" << std::endl;
}

//
// write_method_begin
//
void CUTS_CIAO_Header_File_Generator::
write_method_begin (const PICML::Attribute & attr)
{
  // Generate the getter method for the attribute.
  PICML::Attribute temp_attr (attr);
  PICML::ReadonlyAttribute ro = PICML::ReadonlyAttribute::Cast (temp_attr);
  this->write_method_begin (ro);

  PICML::AttributeMember member = attr.AttributeMember_child ();
  PICML::MemberType mtype = member.ref ();
  PICML::Component parent = attr.Component_parent ();

  // Close the getter method and generate the setter method
  // for the current attribute.
  this->out_
    << "virtual void " << attr.name () << " (" << std::endl;

  CUTS_CIAO_In_Type_T <PICML::MemberType>::write (this->out_, mtype);

  this->out_
    << " " << attr.name () << std::endl
    << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "\tACE_THROW_SPEC ((::CORBA::SystemException));" << std::endl;
}
