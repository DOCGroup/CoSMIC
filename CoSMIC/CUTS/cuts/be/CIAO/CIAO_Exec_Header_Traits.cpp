// $Id$

#include "CIAO_Exec_Header_Traits.h"

#include "CIAO_Var_Type.h"
#include "CIAO_Retn_Type.h"
#include "CIAO_In_Type.h"

#include "cuts/be/BE_Preprocessor.h"
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
  if (!CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), this->node_))
    return false;

  if (this->node_->is_proxy_)
    return false;

  return this->_super::open_file (container);
}

//
// write_preamble
//
void CUTS_CIAO_Exec_Header_Traits::
write_prologue (const PICML::ComponentImplementationContainer & container)
{
  if (!this->outfile ().is_open ())
    return;

  // Generate the hash definition for this file.
  std::string hashdef =
    to_upper ((std::string)container.name () +
    CUTS_BE_OPTIONS ()->exec_suffix_);

  std::replace (hashdef.begin (),
                hashdef.end (),
                '/', '_');

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
    << single_line_comment ("executor client")
    << "#include \"" << container.name () << "EC.h\"" << std::endl
    << "#include \"tao/LocalObject.h\"" << std::endl
    << std::endl
    << "#include \"cuts/config.h\"" << std::endl;
}

//
// write_postamble
//
void CUTS_CIAO_Exec_Header_Traits::
write_epilogue (const PICML::ComponentImplementationContainer & container)
{
  if (!this->outfile ().is_open ())
    return;

  std::string hashdef =
    to_upper ((std::string)container.name () +
    CUTS_BE_OPTIONS ()->exec_suffix_);

  std::replace (hashdef.begin (),
                hashdef.end (),
                '/', '_');

  this->outfile ()
    << "#include /**/ \"ace/post.h\"" << std::endl
    << std::endl
    << "#endif  // !defined _" << hashdef << "_H_" << std::endl;
}

//
// write_impl_begin
//
void CUTS_CIAO_Exec_Header_Traits::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & component)
{
  if (!this->outfile ().is_open ())
    return;

  typedef std::vector <PICML::PeriodicEvent> PeriodicEvent_Set;
  PeriodicEvent_Set periodics = component.PeriodicEvent_kind_children ();

  if (!periodics.empty ())
  {
    this->outfile () << include ("cuts/Trigger_T");
  }

  // We need to determine if any of the events sources has a
  // CUTS::Payload_Event type. This is necessary because we will
  // have to include a special header.
  //
  // @note Checking for a CUTS::Payload_Event should be done by
  //       the preprocessor.

  typedef std::vector <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set outevents = component.OutEventPort_kind_children ();

  for (OutEventPort_Set::iterator iter = outevents.begin ();
       iter != outevents.end ();
       iter ++)
  {
    PICML::Event event = iter->ref ();
    std::string eventtype =
      this->scope (event, "::") + (std::string) event.name ();

    if (eventtype == "CUTS::Payload_Event")
    {
      this->outfile () << include ("cuts/events_i");
      break;
    }
  }

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
    << "  public " << exec << "," << std::endl
    << "  public TAO_Local_RefCounted_Object {"
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
  if (!this->outfile ().is_open ())
    return;

  this->outfile ()
    << "};";
}

//
// write_variables_begin
//
void CUTS_CIAO_Exec_Header_Traits::
write_variables_begin (const PICML::Component & component)
{
  if (!this->outfile ().is_open ())
    return;

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
  if (!this->outfile ().is_open ())
    return;

  PICML::PredefinedType ptype = variable.ref ();

  if (ptype != Udm::null)
  {
    std::string name = variable.name ();

    this->outfile ()
      << single_line_comment ("variable: " + name)
      << CIAO_VAR_TYPE (ptype) << " " << name << "_;"
      << std::endl;
  }
}

//
// write_variable
//
void CUTS_CIAO_Exec_Header_Traits::
write_ReadonlyAttribute_variable (const PICML::ReadonlyAttribute & readonly)
{
  if (!this->outfile ().is_open ())
    return;

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
        << single_line_comment ("variable: " + name)
        << CIAO_VAR_TYPE (mtype) << " " << name << "_;"
        << std::endl;
    }
  }
}

//
// write_PeriodicEvent_variable
//
void CUTS_CIAO_Exec_Header_Traits::
write_PeriodicEvent_variable (const PICML::PeriodicEvent & periodic)
{
  if (!this->outfile ().is_open ())
    return;

  PICML::Component parent = PICML::Component::Cast (periodic.parent ());

  this->outfile ()
    << single_line_comment ("periodic: " + (std::string)periodic.name ())
    << "CUTS_Periodic_Trigger_T <" << parent.name ()
    << "> periodic_" << periodic.name () << "_;" << std::endl;
}


//
// write_worker_variable
//
void CUTS_CIAO_Exec_Header_Traits::
write_worker_variable (const PICML::WorkerType & var,
                const PICML::Worker & worker)
{
  if (!this->outfile ().is_open ())
    return;

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
  if (!this->outfile ().is_open ())
    return;

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
