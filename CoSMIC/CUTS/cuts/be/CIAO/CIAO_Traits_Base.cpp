// $Id$

#include "CIAO_Traits_Base.h"
#include "CIAO_In_Type.h"
#include "CIAO_Retn_Type.h"
#include "CIAO_Out_Type.h"
#include "CIAO_Inout_Type.h"

// backend headers
#include "cuts/be/UDM_Utility_T.h"
#include "cuts/be/BE_Preprocessor.h"

// code generation headers
#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

// UDM headers
#include "Uml.h"

// BOOST headers
#include "boost/bind.hpp"

// STL headers
#include <algorithm>
#include <ctype.h>
#include <stack>

//
// CIAO_Traits_Base
//
CIAO_Traits_Base::CIAO_Traits_Base (void)
{

}

//
// ~CIAO_Traits_Base
//
CIAO_Traits_Base::~CIAO_Traits_Base (void)
{

}

//
// open_file
//
void CIAO_Traits_Base::open_file_i (void)
{
  this->formatter_.reset (new Formatter_Type (this->outfile ()));
}

//
// close_file
//
void CIAO_Traits_Base::
close_file (const PICML::ComponentImplementationContainer & container)
{
  this->formatter_.reset ();
  this->outfile ().close ();
  this->node_ = 0;
}

//
// include
//
std::string CIAO_Traits_Base::
include (const std::string & str)
{
  std::ostringstream ostr;
  ostr << "#include \"" << str << ".h\"" << std::endl;
  return ostr.str ();
}

//
// single_line_comment
//
std::string CIAO_Traits_Base::
single_line_comment (const std::string & str)
{
  std::ostringstream ostr;
  ostr << "// " << str << std::endl;
  return ostr.str ();
}

//
// scope
//
std::string CIAO_Traits_Base::
scope (const PICML::MgaObject & type,
       const std::string & separator,
       bool leading)
{
  std::string scope;
  std::stack <PICML::MgaObject> temp_stack;

  // Continue walking up the tree until we reach a File object.
  PICML::MgaObject parent = PICML::MgaObject::Cast (type.parent ());

  while (parent.type () != PICML::File::meta)
  {
    temp_stack.push (parent);
    parent = PICML::MgaObject::Cast (parent.parent ());
  }

  // Insert the leading separator, if applicable.
  if (leading)
    scope += separator;

  // Empty the stack while writing its contents to a string.
  while (!temp_stack.empty ())
  {
    parent = temp_stack.top ();
    temp_stack.pop ();

    scope += (std::string) parent.name () + separator;
  }

  return scope;
}

//
// write_impl_begin
//
void CIAO_Traits_Base::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & type)
{
  this->outfile ()
    << std::endl
    << "namespace CIDL_" << monoimpl.name () << "{";
}

//
// write_factory_impl_end
//
void CIAO_Traits_Base::
write_factory_impl_end (const PICML::ComponentFactory & factory,
                        const PICML::MonolithicImplementation & impl,
                        const PICML::Component & type)
{
  if (this->entry_point_.empty ())
  {
    this->entry_point_ =
      "create_" + this->scope (factory, "_") +
      (std::string) factory.name () + "_Impl";
  }

  // This is really closing off the implementation namespace
  this->outfile ()
    << "}";
}

//
// write_InEventPort_begin
//
void CIAO_Traits_Base::
write_InEventPort_begin (const PICML::InEventPort & sink)
{
  PICML::Event event = sink.ref ();

  if (event != Udm::null)
  {
    this->outfile ()
      << "push_" << sink.name () << " ("
      << scope (event, "::") << event.name () << " * ev)";
  }
}

//
// write_PeriodicEvent_begin
//
void CIAO_Traits_Base::
write_PeriodicEvent_begin (const PICML::PeriodicEvent & periodic)
{
  this->outfile ()
    << "periodic_" << periodic.name () << " (void)";
}

//
// write_ProvidedRequestPort_begin
//
void CIAO_Traits_Base::
write_ProvidedRequestPort_begin (const PICML::ProvidedRequestPort & facet)
{
  this->outfile ()
    << "get_" << facet.name () << " (void)";
}

//
// write_ReadonlyAttribute_begin
//
void CIAO_Traits_Base::
write_ReadonlyAttribute_begin (const PICML::ReadonlyAttribute & ro_attr)
{
  this->outfile ()
    << ro_attr.name () << " (void)";
}

//
// write_Attribute_begin
//
void CIAO_Traits_Base::
write_Attribute_begin (const PICML::Attribute & attr)
{
  std::string attr_name = attr.name ();
  PICML::AttributeMember member = attr.AttributeMember_child ();
  PICML::MemberType mtype = member.ref ();

  this->outfile ()
    << attr_name << " (" << CIAO_IN_TYPE (mtype)
    << " " << attr_name << ")";
}

//
// write_method
//
void CIAO_Traits_Base::
write_method (const PICML::OutEventPort & source)
{
  PICML::Event event = source.ref ();

  if (event != Udm::null)
  {
    this->outfile ()
      << "push_" << source.name () << " ("
      << scope (event, "::") << event.name () << " * ev)";
  }
}

//
// write_method [RequiredRequestPort]
//
void CIAO_Traits_Base::
write_method (const PICML::RequiredRequestPort & receptacle)
{
  this->outfile ()
    << "get_connection_" << receptacle.name () << " (void)";
}

//
// to_upper
//
std::string CIAO_Traits_Base::
to_upper (const std::string & str)
{
  std::string newstr = str;

  std::transform (newstr.begin (),
                  newstr.end (),
                  newstr.begin (),
                  toupper);

  return newstr;
}

void CIAO_Traits_Base::
write_environment_begin (const PICML::Component & component)
{
  this->env_bits_.reset ();
  this->write_set_session_context (component);
}

//
// write_environment_end
//
void CIAO_Traits_Base::
write_environment_end (const PICML::Component & component)
{
  if (!this->env_bits_[ENV_PREACTIVATE])
    this->write_ciao_preactivate (component);

  if (!this->env_bits_[ENV_ACTIVATE])
    this->write_ccm_activate (component);

  if (!this->env_bits_[ENV_POSTACTIVATE])
    this->write_ciao_postactivate (component);

  if (!this->env_bits_[ENV_PASSIVATE])
    this->write_ccm_passivate (component);

  if (!this->env_bits_[ENV_REMOVE])
    this->write_ccm_remove (component);
}

//
// write_set_session_context
//
void CIAO_Traits_Base::
write_set_session_context (const PICML::Component & component)
{
  this->env_bits_[ENV_SET_SESSION_CONTEXT] = true;

  this->outfile ()
    << "set_session_context (::Components::SessionContext_ptr ctx)";
}

//
// write_ciao_preactivate
//
void CIAO_Traits_Base::
write_ciao_preactivate (const PICML::Component & component)
{
  this->env_bits_[ENV_PREACTIVATE] = true;
  this->outfile () << "ciao_preactivate (void)";
}

//
// write_ccm_activate
//
void CIAO_Traits_Base::
write_ccm_activate (const PICML::Component & component)
{
  this->env_bits_[ENV_ACTIVATE] = true;
  this->outfile () << "ccm_activate (void)";
}

//
// write_ciao_postactivate
//
void CIAO_Traits_Base::
write_ciao_postactivate (const PICML::Component & component)
{
  this->env_bits_[ENV_POSTACTIVATE] = true;
  this->outfile () << "ciao_postactivate (void)";
}

void CIAO_Traits_Base::
write_ccm_passivate (const PICML::Component & component)
{
  this->env_bits_[ENV_PASSIVATE] = true;
  this->outfile () << "ccm_passivate (void)";
}

//
// write_ccm_remove
//
void CIAO_Traits_Base::
write_ccm_remove (const PICML::Component & component)
{
  this->env_bits_[ENV_REMOVE] = true;
  this->outfile () << "ccm_remove (void)";
}

//
// write_TwowayOperation_begin
//
void CIAO_Traits_Base::
write_TwowayOperation_begin (const PICML::TwowayOperation & twoway)
{
  this->outfile ()
    << twoway.name () << " (";

  typedef std::vector <PICML::ParameterType> ParameterType_Set;
  ParameterType_Set params =
    twoway.ParameterType_kind_children_sorted (
    Sort_By_Position <PICML::ParameterType> ());

  if (!params.empty ())
  {
    ParameterType_Set::iterator iter = params.begin ();
    this->write_parameter_first (*iter ++);

    // Write all the in parameters for this method.
    std::for_each (iter,
                   params.end (),
                   boost::bind (&CIAO_Traits_Base::write_parameter,
                                this,
                                _1));
  }
  else
    // Print the correct trailing macro for no arguments.
    this->outfile () << "void";

  this->outfile () << ")";
}

//
// write_TwowayOperation_begin
//
void CIAO_Traits_Base::
write_OnewayOperation_begin (const PICML::OnewayOperation & oneway)
{
  this->write_OperationBase_begin (oneway);
}

//
// write_in_parameter_first
//
void CIAO_Traits_Base::
write_in_parameter_first (const PICML::InParameter & in)
{
  PICML::MemberType type = in.ref ();

  if (type != Udm::null)
  {
    this->outfile ()
      << CIAO_IN_TYPE (type) << " " << in.name ();
  }
}

//
// write_in_parameter
//
void CIAO_Traits_Base::
write_in_parameter (const PICML::InParameter & in)
{
  this->outfile ()
    << "," << std::endl;

  this->write_in_parameter_first (in);
}

//
// write_out_parameter_first
//
void CIAO_Traits_Base::
write_out_parameter_first (const PICML::OutParameter & out)
{
  PICML::MemberType type = out.ref ();

  if (type != Udm::null)
  {
    this->outfile ()
      << CIAO_OUT_TYPE (type) << " " << out.name ();
  }
}

//
// write_out_parameter
//
void CIAO_Traits_Base::
write_out_parameter (const PICML::OutParameter & out)
{
  this->outfile ()
    << "," << std::endl;

  this->write_out_parameter_first (out);
}

//
// write_inout_parameter_first
//
void CIAO_Traits_Base::
write_inout_parameter_first (const PICML::InoutParameter & inout)
{
  PICML::MemberType type = inout.ref ();

  if (type != Udm::null)
  {
    this->outfile ()
      << CIAO_INOUT_TYPE (type) << " " << inout.name ();
  }
}

//
// write_inout_parameter
//
void CIAO_Traits_Base::
write_inout_parameter (const PICML::InoutParameter & inout)
{
  this->outfile ()
    << "," << std::endl;

  this->write_inout_parameter_first (inout);
}

//
// write_parameter
//
void CIAO_Traits_Base::
write_parameter (const PICML::ParameterType & param)
{
  Uml::Class type = param.type ();

  if (type == PICML::InParameter::meta)
    this->write_in_parameter (PICML::InParameter::Cast (param));
  else if (type == PICML::OutParameter::meta)
    this->write_out_parameter (PICML::OutParameter::Cast (param));
  else if (type == PICML::InoutParameter::meta)
    this->write_inout_parameter (PICML::InoutParameter::Cast (param));
}

//
// write_parameter_first
//
void CIAO_Traits_Base::
write_parameter_first (const PICML::ParameterType & param)
{
  Uml::Class type = param.type ();

  if (type == PICML::InParameter::meta)
    this->write_in_parameter_first (PICML::InParameter::Cast (param));
  else if (type == PICML::OutParameter::meta)
    this->write_out_parameter_first (PICML::OutParameter::Cast (param));
  else if (type == PICML::InoutParameter::meta)
    this->write_inout_parameter_first (PICML::InoutParameter::Cast (param));
}

//
// write_exception
//
void CIAO_Traits_Base::
write_exception_spec (const PICML::ExceptionRef & ref)
{
  PICML::Exception exception = ref.ref ();
  std::string scope = this->scope (exception, "::", true);

  this->outfile ()
    << "," << std::endl
    << scope << exception.name ();
}

//
// write_FactoryOperation_begin
//
void CIAO_Traits_Base::
write_FactoryOperation_begin (const PICML::FactoryOperation & factory_op)
{
  this->write_OperationBase_begin (factory_op);
}

//
// write_FactoryOperation_end
//
void CIAO_Traits_Base::
write_FactoryOperation_end (const PICML::FactoryOperation & factory_op)
{

}

//
// write_OperationBase
//
void CIAO_Traits_Base::
write_OperationBase_begin (const PICML::OperationBase & operation_base)
{
  this->outfile ()
    << operation_base.name () << " (";

  // Get all the in parameters for this method.
  typedef std::vector <PICML::InParameter> InParameter_Set;
  InParameter_Set inparams =
    operation_base.InParameter_kind_children_sorted (
    Sort_By_Position <InParameter_Set::value_type> ());

  if (!inparams.empty ())
  {
    InParameter_Set::iterator iter = inparams.begin ();
    this->write_in_parameter_first (*iter ++);

    // Write all the in parameters for this method.
    std::for_each (iter,
                   inparams.end (),
                   boost::bind (&CIAO_Traits_Base::write_in_parameter,
                                this,
                                _1));
  }
  else
    this->outfile () << "void";

  // Close the method declaration and write the exception.
  this->outfile () << ")";
}

//
// get_impl_entry_point
//
void CIAO_Traits_Base::
get_impl_entry_point (const PICML::
                      ComponentImplementationContainer & container)
{
  const CUTS_BE_Impl_Node * node = 0;
  if (!CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), node))
    return;

  CUTS_BE_Impl_Node::Artifact_Set::const_iterator iter;

  for (iter  = node->artifacts_.begin ();
       iter != node->artifacts_.end ();
       iter ++)
  {
    std::string name = iter->name ();
    size_t index = name.rfind ("_exec");

    if (index == name.length () - 5)
    {
      // We found the artifact that ends in _exec!!!
      typedef std::set <PICML::ArtifactExecParameter> ExecParameter_Set;
      ExecParameter_Set params = iter->dstArtifactExecParameter ();

      for (ExecParameter_Set::iterator piter = params.begin ();
           piter != params.end ();
           piter ++)
      {
        PICML::Property property = piter->dstArtifactExecParameter_end ();

        if ((std::string)property.name () == "entryPoint")
          this->entry_point_ = property.DataValue ();
      }
    }
  }
}

//
// write_include
//
void CIAO_Traits_Base::write_include (const std::string & file)
{
  this->outfile () << include (file);
}
