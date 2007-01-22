// $Id$

#include "CIAO_Exec_Source_Traits.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Exec_Source_Traits.inl"
#endif

// CUTS headers
#include "CIAO_Retn_Type.h"
#include "CIAO_In_Type.h"
#include "CIAO_Var_Type.h"

#include "cuts/be/BE_Preprocessor.h"
#include "cuts/be/BE_Options.h"

// UDM headers
#include "Uml.h"

// STL headers
#include <sstream>
#include <fstream>
#include <algorithm>

// BOOST headers
#include "boost/bind.hpp"

//
// env_table_
//
CUTS_CIAO_Exec_Source_Traits::Environment_Table
CUTS_CIAO_Exec_Source_Traits::env_table_;

//
// CUTS_CIAO_Exec_Source_Traits
//
CUTS_CIAO_Exec_Source_Traits::CUTS_CIAO_Exec_Source_Traits (void)
: skip_action_ (false),
  auto_env_ (false)
{
  if (this->env_table_.empty ())
  {
    // We need to initialize the jump table the environment
    // methods.
    this->env_table_.insert (
      Environment_Table::value_type ("preactivate",
      &CUTS_CIAO_Exec_Source_Traits::write_ciao_preactivate));

    this->env_table_.insert (
      Environment_Table::value_type ("activate",
      &CUTS_CIAO_Exec_Source_Traits::write_ccm_activate));

    this->env_table_.insert (
      Environment_Table::value_type ("postactivate",
      &CUTS_CIAO_Exec_Source_Traits::write_ciao_postactivate));

    this->env_table_.insert (
      Environment_Table::value_type ("passivate",
      &CUTS_CIAO_Exec_Source_Traits::write_ccm_passivate));

    this->env_table_.insert (
      Environment_Table::value_type ("remove",
      &CUTS_CIAO_Exec_Source_Traits::write_ccm_remove));
  }
}

//
// ~CUTS_CIAO_Exec_Source_Traits
//
CUTS_CIAO_Exec_Source_Traits::~CUTS_CIAO_Exec_Source_Traits (void)
{

}

//
// open_file
//
bool CUTS_CIAO_Exec_Source_Traits::
open_file (const PICML::ComponentImplementationContainer & container)
{
  const CUTS_BE_Impl_Node * node = 0;
  if (!CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), node))
    return false;

  if (node->impl_flags_[CUTS_BE_Impl_Node::IMPL_PROXY])
    return false;

  // Construct the name of the file.
  std::ostringstream ostr;
  ostr
    << CUTS_BE_OPTIONS ()->output_directory_
    << "/" << container.name ()
    << CUTS_BE_OPTIONS ()->exec_suffix_ << ".cpp";

  // Open the file and pass contol to base class.
  this->outfile ().open (ostr.str ().c_str ());

  if (!this->outfile ().is_open ())
    return false;

  this->open_file_i ();
  return this->outfile ().good ();
}

//
// write_prologue
//
void CUTS_CIAO_Exec_Source_Traits::
write_prologue (const PICML::ComponentImplementationContainer & container)
{
  this->outfile ()
    << single_line_comment ("This file was generated by")
    << single_line_comment ("$Id$")
    << std::endl
    << include ((std::string)container.name () +
                CUTS_BE_OPTIONS ()->exec_suffix_)
    << include ("cuts/Activation_Record")
    << include ("cuts/CCM_Events_T")
    << include ("cuts/Thread_Activation_Record");
}

//
// write_epilogue
//
void CUTS_CIAO_Exec_Source_Traits::
write_epilogue (const PICML::ComponentImplementationContainer & container)
{

}

//
// write_impl_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & component)
{
  // Let's get all the event sources and initalize out port
  // manager. There has to be a better way to do this, which
  // I hope to realize in the near future.
  typedef std::vector <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set sources = component.OutEventPort_kind_children ();

  for (OutEventPort_Set::iterator iter = sources.begin ();
       iter != sources.end ();
       iter ++)
  {
    this->outevent_mgr_.insert (*iter);
  }

  // Let's write the constructor and destructor for the monolithic
  // implementation of the component.
  std::string destructor ("~");
  destructor += component.name ();

  _super::write_impl_begin (monoimpl, component);

  this->outfile ()
    << function_header (component.name ())
    << component.name () << "::" << component.name () << " (void)"
    << "{"
    << "CUTS_Thread_Activation_Record::init_singleton ();"
    << "}"

    << function_header (destructor)
    << component.name () << "::" << destructor << " (void)"
    << "{"
    << "}";
}

//
// write_impl_end
//
void CUTS_CIAO_Exec_Source_Traits::
write_impl_end (const PICML::MonolithicImplementation & monoimpl,
                const PICML::Component & component)
{
  this->outevent_mgr_.clear ();
}

//
// write_factory_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_factory_begin (const PICML::ComponentFactory & factory,
                     const PICML::MonolithicImplementation & impl,
                     const PICML::Component & type)
{
  std::string destructor ("~");
  destructor += factory.name ();

  this->outfile ()
    << function_header (factory.name ())
    << factory.name () << "::" << factory.name () << " (void)"
    << "{"
    << "}"

    << function_header (destructor)
    << factory.name () << "::" << destructor << " (void)"
    << "{"
    << "}"

    << function_header ("create")
    << "::Components::EnterpriseComponent_ptr " << std::endl
    << "  " << factory.name ()
    << "::create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException," << std::endl
    << "::Components::CCMException)) {"
    << "::Components::EnterpriseComponent_ptr retval =" << std::endl
    << "  ::Components::EnterpriseComponent::_nil ();"
    << std::endl
    << "ACE_NEW_THROW_EX (retval," << std::endl
    << type.name () << "," << std::endl
    << "::CORBA::NO_MEMORY ());"
    << std::endl
    << "ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());"
    << "return retval;"
    << "}";
}

//
// write_factory_end
//
void CUTS_CIAO_Exec_Source_Traits::
write_factory_end (const PICML::ComponentFactory & factory,
                   const PICML::MonolithicImplementation & impl,
                   const PICML::Component & type)
{
  _super::write_factory_end (factory, impl, type);

  std::string func_name =
    "create_" + scope (factory, "_") +
    (std::string)factory.name () + "_Impl";

  this->outfile ()
    << function_header (func_name)
    << "::Components::HomeExecutorBase_ptr" << std::endl
    << func_name << " (void) {"
    << "::Components::HomeExecutorBase_ptr retval =" << std::endl
    << "  ::Components::HomeExecutorBase::_nil ();"
    << std::endl
    << "ACE_NEW_RETURN (retval," << std::endl
    << "::CIDL_" << impl.name ()
    << "::" << factory.name () << "," << std::endl
    << "::Components::HomeExecutorBase::_nil ());"
    << std::endl
    << "return retval;"
    << "}";
}

//
// write_method_end
//
void CUTS_CIAO_Exec_Source_Traits::
write_method_end (const PICML::ProvidedRequestPort & facet)
{
  PICML::Object obj = PICML::Object::Cast (facet.ref ());

  if (obj != Udm::null)
  {
    std::string obj_scope = scope (obj, "::");

    this->outfile ()
      << "return " << obj_scope
      << "CCM_" << obj.name () << "::_nil ();";
  }

  this->_super::write_method_end (facet);
}

//
// write_method_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_method_begin (const PICML::InEventPort & sink)
{
  this->_super::write_method_begin (sink);

  this->outfile ()
    << single_line_comment ("get activation record for this thread")
    << "CUTS_Activation_Record * record = CUTS_THR_ACTIVATION_RECORD ();"
    << std::endl;
}

//
// write_method_begin [ReadonlyAttribute]
//
void CUTS_CIAO_Exec_Source_Traits::
write_method_begin (const PICML::ReadonlyAttribute & attr)
{
  // Write the class scope resolution.
  this->_super::write_method_begin (attr);

  PICML::AttributeMember member = attr.AttributeMember_child ();
  PICML::MemberType mtype = member.ref ();
  Uml::Class metatype = mtype.type ();

  if (metatype == PICML::String::meta)
  {
    // Strings are special case. We need to return a duplicate
    // copy of the string, or we will have major problems.
    this->outfile ()
      << "::CORBA::String_var s =" << std::endl
      << "  ::CORBA::string_dup (this->"
      << attr.name () << "_.c_str ());"
      << "return s._retn ();";
  }
  else if (metatype == PICML::GenericValue::meta)
  {
    // We need to create an <Any::_var_type> for temporary
    // storage and give control to the client using the
    // _retn () method.
    this->outfile ()
      << "CORBA::Any::_var_type tmp = new ::CORBA::Any (this->"
      << attr.name () << "_);"
      << "return tmp._retn ();";
  }
  else if (metatype == PICML::GenericObject::meta)
  {
    this->outfile ()
      << "return ::CORBA::Object::_duplicate (this->"
      << attr.name () << "_.in ());";
  }
  else if (metatype == PICML::TypeEncoding::meta)
  {
    this->outfile ()
      << "return ::CORBA::TypeCode::_duplicate (this->"
      << attr.name () << "_.in ());";
  }
  else
    this->outfile () << "return this->" << attr.name () << "_;";
}

//
// write_method_begin [Attribute]
//
void CUTS_CIAO_Exec_Source_Traits::
write_method_begin (const PICML::Attribute & attr)
{
  this->_super::write_method_begin (attr);
  this->outfile () << "this->" << attr.name () << "_ = ";

  PICML::AttributeMember member = attr.AttributeMember_child ();
  PICML::MemberType mtype = member.ref ();
  Uml::Class metatype = mtype.type ();

  if (metatype == PICML::GenericObject::meta)
  {
    // We need to create a duplicate copy of the interface
    // before we store it.
    this->outfile ()
      << std::endl
      << "  ::CORBA::Object::_duplicate (" << attr.name () << ");";
  }
  else if (metatype == PICML::TypeEncoding::meta)
  {
    // We need to create a duplicate copy of the typecode
    // interface before we store it.
    this->outfile ()
      << std::endl
      << "  ::CORBA::TypeCode::_duplicate (" << attr.name () << ");";
  }
  else
    this->outfile () << attr.name () << ";";
}

//
// write_set_session_context
//
void CUTS_CIAO_Exec_Source_Traits::
write_set_session_context (const PICML::Component & component)
{
  this->_super::write_set_session_context (component);

  // Since we do not support this method, we do not have to guard
  // the implemenation. There is no way this method will not be
  // auto generated (i.e., called as a result of the modeler excluding
  // this environment method).

  this->outfile ()
    << "{"
    << "this->context_ =" << std::endl
    << "  " << scope (component, "::")
    << "CCM_" << component.name () << "_Context::_narrow (ctx);"
    << std::endl
    << "ACE_CHECK;"
    << std::endl
    << "if (this->context_ == 0)" << std::endl
    << "  ACE_THROW (::CORBA::INTERNAL ());"
    << "}";
}

//
// write_ciao_preactivate
//
void CUTS_CIAO_Exec_Source_Traits::
write_ciao_preactivate (const PICML::Component & component)
{
  this->_super::write_ciao_preactivate (component);
  this->outfile () << "{";

  typedef std::vector <PICML::PeriodicEvent> PeriodicEvent_Set;
  PeriodicEvent_Set periodics = component.PeriodicEvent_kind_children ();

  for (PeriodicEvent_Set::iterator iter = periodics.begin ();
       iter != periodics.end ();
       iter ++)
  {
    this->outfile ()
      << "this->periodic_" << iter->name () << "_.init (this, &"
      << component.name () << "::periodic_" << iter->name () << ");"
      << "this->periodic_" << iter->name () << "_.probability ("
      << iter->Probability () << ");"
      << std::endl;
  }

  if (this->auto_env_)
    this->outfile () << "}";
}

//
// write_cmm_activate
//
void CUTS_CIAO_Exec_Source_Traits::
write_ccm_activate (const PICML::Component & component)
{
  this->_super::write_ccm_activate (component);
  this->outfile () << "{";

  if (this->auto_env_)
    this->outfile () << "}";
}

//
// write_ciao_postactivate
//
void CUTS_CIAO_Exec_Source_Traits::
write_ciao_postactivate (const PICML::Component & component)
{
  this->_super::write_ciao_postactivate (component);
  this->outfile () << "{";

  typedef std::vector <PICML::PeriodicEvent> PeriodicEvent_Set;
  PeriodicEvent_Set periodics = component.PeriodicEvent_kind_children ();

  for (PeriodicEvent_Set::iterator iter = periodics.begin ();
       iter != periodics.end ();
       iter ++)
  {
    this->outfile ()
      << "this->periodic_" << iter->name () << "_.activate ("
      << iter->Period () << ");";
  }

  if (this->auto_env_)
    this->outfile () << "}";
}

//
// write_ccm_passivate
//
void CUTS_CIAO_Exec_Source_Traits::
write_ccm_passivate (const PICML::Component & component)
{
  this->_super::write_ccm_passivate (component);
  this->outfile () << "{";


  typedef std::vector <PICML::PeriodicEvent> PeriodicEvent_Set;
  PeriodicEvent_Set periodics = component.PeriodicEvent_kind_children ();

  for (PeriodicEvent_Set::iterator iter = periodics.begin ();
       iter != periodics.end ();
       iter ++)
  {
    this->outfile ()
      << "this->periodic_" << iter->name () << "_.deactivate ();";
  }

  if (this->auto_env_)
    this->outfile () << "}";
}

//
// write_ccm_remove
//
void CUTS_CIAO_Exec_Source_Traits::
write_ccm_remove (const PICML::Component & component)
{
  this->_super::write_ccm_remove (component);

  this->outfile ()
    << "{";

  if (this->auto_env_)
  {
    this->outfile ()
      << "CUTS_Thread_Activation_Record::fini_singleton ();"
      << "}";
  }
}

//
// write_environment_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_environment_begin (const PICML::Component & component)
{
  this->auto_env_ = false;
  this->_super::write_environment_begin (component);
}

//
// write_environment_method_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_environment_method_begin (const PICML::InputAction & action)
{
  // Extract the name of the environment method and the
  // component to which the method belongs.
  std::string name = action.name ();
  PICML::Component component = PICML::Component::Cast (action.parent ());

  // Determine if this is a valid environment method.
  Environment_Table::const_iterator iter = this->env_table_.find (name);

  if (iter != this->env_table_.end ())
  {
    // Call the correct environment method. Then generate the remainder
    // of this method. This means generating the code that will access
    // the activation record for the calling thread.
    (this->*(iter->second)) (component);

    this->outfile ()
      << "CUTS_Activation_Record * record = CUTS_THR_ACTIVATION_RECORD ();"
      << std::endl;
  }
  else
  {
    this->outfile ()
      << single_line_comment ("ignoring environment method: " + name);
  }
}

//
// write_environment_method_end
//
void CUTS_CIAO_Exec_Source_Traits::
write_environment_method_end (const PICML::InputAction & action)
{
  // Determine if this is a valid environment method.
  Environment_Table::const_iterator iter =
    this->env_table_.find (action.name ());

  if (iter != this->env_table_.end ())
  {
    // The "remove" method has a special operation it must complete
    // after the component finishes it's regular operations.
    if ((std::string)action.name () == "remove")
    {
      this->outfile ()
        << "CUTS_Thread_Activation_Record::fini_singleton ();";
    }

    this->outfile ()
      << "}";
  }
}

//
// write_environment_end
//
void CUTS_CIAO_Exec_Source_Traits::
write_environment_end (const PICML::Component & component)
{
  this->auto_env_ = true;
  this->_super::write_environment_end (component);
}

//
// write_action_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_action_begin (const PICML::Worker & parent,
                    const PICML::Action & action)
{
  long repetitions = static_cast <long> (action.Repetitions ());

  if (repetitions > 0)
  {
    // Ok, we are not skipping this action since there is at
    // least one repetition in play.
    this->skip_action_ = false;

    // Now, how are we to log this action. If logging is enabled
    // then we need to invoke the logging method. If not, then we
    // need to invoke the non-logging method.

    if (action.LogAction ())
      this->outfile () << "record->perform_action (" << std::endl;
    else
      this->outfile () << "record->perform_action_no_logging (" << std::endl;

    // Since we have overloaded the methods based on the number of
    // repetitions specified for an action, let's call the appropriate
    // one. This is a minor optimization.

    if (repetitions > 1)
      this->outfile () << repetitions << ", ";

    PICML::Action action_type =
      const_cast <PICML::Action &> (action).Archetype ();

    std::string name = action_type.name ();

    // Print the fully qualifies name of the action.
    std::string tempstr = parent.name ();
    PICML::MgaObject parent_action = parent.parent ();

    while (parent_action.type () != PICML::WorkerFile::meta)
    {
      tempstr.insert (0, "::");
      tempstr.insert (0, parent_action.name ());

      parent_action = PICML::MgaObject::Cast (parent_action.parent ());
    }

    // Print the action and it's worker.
    this->outfile ()
      << tempstr << "::" << action_type.name ()
      << " (this->" << action.name () << "_";
  }
  else
    this->skip_action_ = true;
}

//
// write_action_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_action_end (void)
{
  if (!this->skip_action_)
    this->outfile () << "));" << std::endl;
}

//
// write_action_property
//
void CUTS_CIAO_Exec_Source_Traits::
write_action_property (const PICML::Property & property)
{
  // Extract the type information from the <property>.
  PICML::DataType datatype = property.DataType_child ();

  this->outfile ()
    << ", " << property.DataValue ();
}

//
// write_action_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_action_begin (const PICML::OutputAction & action)
{
  std::string scoped_name;

  if (this->outevent_mgr_.get_scoped_typename (action.name (), scoped_name))
  {
    this->outfile ()
      << "CUTS_CCM_Event_T <OBV_" << scoped_name
      << "> __event_" << action.uniqueId () << "__;"
      << "this->context_->push_"
      << action.name () << " (__event_" << action.uniqueId () << "__.in ());"
      << std::endl;

    this->skip_action_ = true;
  }
}

//
// write_precondition
//
void CUTS_CIAO_Exec_Source_Traits::
write_precondition (const std::string & precondition)
{
  this->outfile () << precondition;
}

//
// write_precondition
//
void CUTS_CIAO_Exec_Source_Traits::
write_postcondition (const std::string & postcondition)
{
  this->outfile () << postcondition << ";";
}


//
// write_method_begin
//
void CUTS_CIAO_Exec_Source_Traits::
write_method_begin (const PICML::PeriodicEvent & periodic)
{
  this->_super::write_method_begin (periodic);

  this->outfile ()
    << single_line_comment ("get activation record for this thread")
    << "CUTS_Activation_Record * record = CUTS_THR_ACTIVATION_RECORD ();"
    << std::endl;
}
