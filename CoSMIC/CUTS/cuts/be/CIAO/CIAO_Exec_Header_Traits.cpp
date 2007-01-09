// $Id$

#include "CIAO_Exec_Header_Traits.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Exec_Header_Traits.inl"
#endif

#include "CIAO_Var_Type.h"
#include "CIAO_Retn_Type.h"
#include "CIAO_In_Type.h"
#include "Export_File_Generator.h"
#include "cuts/be/BE_Options.h"

// UDM headers
#include "Uml.h"

// STL headers
#include <algorithm>
#include <sstream>

//
// env_table_
//
CUTS_CIAO_Exec_Header_Traits::Environment_Table
CUTS_CIAO_Exec_Header_Traits::env_table_;

//
// CUTS_CIAO_Exec_Header_Traits
//
CUTS_CIAO_Exec_Header_Traits::CUTS_CIAO_Exec_Header_Traits (void)
{
  if (this->env_table_.empty ())
  {
    this->env_table_.insert (
      Environment_Table::value_type ("preactivate",
      &CUTS_CIAO_Exec_Header_Traits::write_ciao_preactivate));

    this->env_table_.insert (
      Environment_Table::value_type ("activate",
      &CUTS_CIAO_Exec_Header_Traits::write_ccm_activate));

    this->env_table_.insert (
      Environment_Table::value_type ("postactivate",
      &CUTS_CIAO_Exec_Header_Traits::write_ciao_postactivate));

    this->env_table_.insert (
      Environment_Table::value_type ("passivate",
      &CUTS_CIAO_Exec_Header_Traits::write_ccm_passivate));

    this->env_table_.insert (
      Environment_Table::value_type ("remove",
      &CUTS_CIAO_Exec_Header_Traits::write_ccm_remove));
  }
}

//
// ~CUTS_CIAO_Exec_Header_Traits
//
CUTS_CIAO_Exec_Header_Traits::~CUTS_CIAO_Exec_Header_Traits (void)
{

}

//
// open_fle
//
bool CUTS_CIAO_Exec_Header_Traits::
open_file (const PICML::ComponentImplementationContainer & container)
{
  // Construct the name of the file.
  std::ostringstream ostr;
  ostr
    << CUTS_BE_OPTIONS ()->output_directory_
    << "/" << container.name ()
    << CUTS_BE_OPTIONS ()->exec_suffix_
    << ".h";

  // Open the file and pass control to the base class.
  this->outfile ().open (ostr.str ().c_str ());

  if (!this->outfile ().is_open ())
    return false;

  this->open_file_i ();
  return this->outfile ().good ();
}

//
// write_preamble
//
void CUTS_CIAO_Exec_Header_Traits::
write_prologue (const PICML::ComponentImplementationContainer & container)
{
  // Generate the hash definition for this file.
  std::string hashdef =
    to_upper ((std::string)container.name () +
    CUTS_BE_OPTIONS ()->exec_suffix_);

  this->outfile ()
    << "// -*- C++ -*-" << std::endl
    << std::endl
    << "#ifndef _" << hashdef << "_H_" << std::endl
    << "#define _" << hashdef << "_H_" << std::endl
    << std::endl
    << "#if !defined (ACE_LACKS_PRAGMA_ONCE)" << std::endl
    << "#pragma once" << std::endl
    << "#endif /* ACE_LACKS_PRAGMA_ONCE */" << std::endl
    << std::endl
    << "#include /**/ \"ace/pre.h\"" << std::endl
    << std::endl
    << single_line_comment ("for string variable types")
    << include ("ace/SString")
    << std::endl
    << single_line_comment ("servant header")
    << "#include \"" << container.name () << "_svnt.h\"" << std::endl
    << std::endl
    << "#include \"cuts/config.h\"" << std::endl;
}

//
// write_postamble
//
void CUTS_CIAO_Exec_Header_Traits::
write_epilogue (const PICML::ComponentImplementationContainer & container)
{
  std::string hashdef =
    to_upper ((std::string)container.name () +
    CUTS_BE_OPTIONS ()->exec_suffix_);

  this->outfile ()
    << "#include /**/ \"ace/post.h\"" << std::endl
    << std::endl
    << "#endif  // !defined _" << hashdef << "_H_" << std::endl;
}

//
// write_includes
//
void CUTS_CIAO_Exec_Header_Traits::
write_includes (const CUTS_String_Set & includes)
{
  for (CUTS_String_Set::const_iterator iter = includes.begin ();
      iter != includes.end ();
      iter ++)
  {
    this->outfile ()
      << include (*iter);
  }
}

//
// write_impl_begin
//
void CUTS_CIAO_Exec_Header_Traits::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & component)
{
  typedef std::vector <PICML::PeriodicEvent> PeriodicEvent_Set;
  PeriodicEvent_Set periodics = component.PeriodicEvent_kind_children ();

  if (!periodics.empty ())
    this->outfile () << include ("cuts/Trigger_T");

  // Write the class declaration for the component.
  _super::write_impl_begin (monoimpl, component);

  std::string name = component.name ();

  // Construct the name of the destructor.
  std::string destructor ("~");
  destructor += name;

  // Construct the name of the context.
  std::string exec (name);
  exec.append ("_Exec");

  this->outfile ()
    << "class " << name << " :" << std::endl
    << "  public virtual " << exec << "," << std::endl
    << "  public virtual TAO_Local_RefCounted_Object {"
    << "public:" << std::endl

    // Write the default constructor.
    << single_line_comment ("Default constructor")
    << name << " (void);"
    << std::endl

    // Write the destructor.
    << single_line_comment ("Destructor")
    << "virtual ~" << name << " (void);"
    << std::endl;
}

//
// write_impl_end
//
void CUTS_CIAO_Exec_Header_Traits::
write_impl_end (const PICML::MonolithicImplementation & monoimpl,
                const PICML::Component & component)
{
  this->outfile ()
    << "};";
}

//
// write_factory_begin
//
void CUTS_CIAO_Exec_Header_Traits::
write_factory_begin (const PICML::ComponentFactory & factory,
                     const PICML::MonolithicImplementation & impl,
                     const PICML::Component & type)
{
  this->outfile ()
    << "class " << factory.name () << " :" << std::endl
    << "  public virtual " << factory.name () << "_Exec," << std::endl
    << "  public virtual TAO_Local_RefCounted_Object {"
    << "public:" << std::endl
    << single_line_comment ("default constructor")
    << factory.name () << " (void);"
    << std::endl
    << single_line_comment ("destructor")
    << "virtual ~" << factory.name () << " (void);"
    << std::endl
    << single_line_comment ("default creation method")
    << "virtual ::Components::EnterpriseComponent_ptr" << std::endl
    << "  create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException," << std::endl
    << "::Components::CCMException));" << std::endl;
}

//
// write_factory_end
//
void CUTS_CIAO_Exec_Header_Traits::
write_factory_end (const PICML::ComponentFactory & factory,
                   const PICML::MonolithicImplementation & impl,
                   const PICML::Component & type)
{
  // Generate the export file for the factory.
  CUTS_Export_File_Generator export ((std::string)type.name () + "_exec");
  export.generate ();

  // Close off the class definition.
  this->outfile ()
    << "};";

  _super::write_factory_end (factory, impl, type);

  this->outfile ()
    << "#include \"" << export.export_file () << "\"" << std::endl
    << std::endl
    << "extern \"C\" " << export.export_macro () << std::endl
    << "::Components::HomeExecutorBase_ptr " << std::endl
    << "create_" << scope (factory, "_")
    << factory.name () << "_Impl (void);"
    << std::endl;
}

//
// write_variables_begin
//
void CUTS_CIAO_Exec_Header_Traits::
write_variables_begin (const PICML::Component & component)
{
  this->_super::write_variables_begin (component);

  this->outfile ()
    << single_line_comment ("context for the component (proxy-enabled)")
    << scope (component, "::") << "CCM_" << component.name ()
    << "_Context::_var_type context_;"
    << std::endl;
}

//
// write_variable
//
void CUTS_CIAO_Exec_Header_Traits::
write_variable (const PICML::Variable & variable)
{
  PICML::PredefinedType ptype = variable.ref ();

  if (ptype != Udm::null)
  {
    std::string name = variable.name ();

    this->outfile ()
      << single_line_comment ("variable: " + name);

    CUTS_CIAO_Var_Type_T <PICML::PredefinedType>::write (this->outfile (),
                                                         ptype);

    this->outfile ()
      << " " << name << "_;"
      << std::endl;
  }
}

//
// write_variable
//
void CUTS_CIAO_Exec_Header_Traits::
write_variable (const PICML::ReadonlyAttribute & readonly)
{
  // Get the contained attribute member.
  PICML::AttributeMember member = readonly.AttributeMember_child ();

  if (member != Udm::null)
  {
    // Now, let's get the member type.
    PICML::MemberType mtype = member.ref ();

    if (mtype != Udm::null)
    {
      // We made it this far, so we can at least try to generate
      // the variable for this attribute.
      std::string name = readonly.name ();

      this->outfile ()
        << single_line_comment ("variable: " + name);

      CUTS_CIAO_Var_Type_T <PICML::MemberType>::write (this->outfile (),
                                                       mtype);
      this->outfile ()
        << " " << name << "_;"
        << std::endl;
    }
  }
}

//
// write_variable
//
void CUTS_CIAO_Exec_Header_Traits::
write_variable (const PICML::PeriodicEvent & periodic)
{
  PICML::Component parent = PICML::Component::Cast (periodic.parent ());

  this->outfile ()
    << single_line_comment ("periodic: " + (std::string)periodic.name ())
    << "CUTS_Periodic_Trigger_T <" << parent.name ()
    << "> periodic_" << periodic.name () << "_;" << std::endl;
}


//
// write_variable
//
void CUTS_CIAO_Exec_Header_Traits::
write_variable (const PICML::WorkerType & var,
                const PICML::Worker & worker)
{
  this->outfile ()
    << single_line_comment ("worker variable: " + (std::string)var.name ())
    << worker.name () << " " << var.name () << "_;" << std::endl;
}

//
// write_environment_method_begin
//
void CUTS_CIAO_Exec_Header_Traits::
write_environment_method_begin (const PICML::InputAction & action)
{
  // Extract the necessary information.
  PICML::Component component = PICML::Component::Cast (action.parent ());
  std::string name = action.name ();

  // Locate the method inside the table.
  Environment_Table::const_iterator iter = this->env_table_.find (name);

  if (iter != this->env_table_.end ())
  {
    (this->*(iter->second)) (component);
  }
  else
  {
    this->outfile ()
      << single_line_comment ("ignoring environment method: " + name);
  }
}
