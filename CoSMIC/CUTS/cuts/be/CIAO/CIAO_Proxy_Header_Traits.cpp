// $Id$

#include "CIAO_Proxy_Header_Traits.h"

#include "CIAO_Var_Type.h"
#include "CIAO_Retn_Type.h"
#include "CIAO_In_Type.h"

#include "cuts/be/BE_Impl_Node.h"
#include "cuts/be/BE_Options.h"
#include "cuts/be/BE_Preprocessor.h"

// UDM headers
#include "Uml.h"

// STL headers
#include <algorithm>
#include <sstream>

#include "boost/bind.hpp"

//
// CUTS_CIAO_Proxy_Header_Traits
//
CUTS_CIAO_Proxy_Header_Traits::
CUTS_CIAO_Proxy_Header_Traits (void)
{

}

//
// ~CUTS_CIAO_Proxy_Header_Traits
//
CUTS_CIAO_Proxy_Header_Traits::
~CUTS_CIAO_Proxy_Header_Traits (void)
{

}

//
// open_fle
//
bool CUTS_CIAO_Proxy_Header_Traits::
open_file (const PICML::ComponentImplementationContainer & container)
{
  if (!CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), this->node_))
    return false;

  if (!this->node_->is_proxy_)
    return false;

  return this->_super::open_file (container);
}

//
// write_preamble
//
void CUTS_CIAO_Proxy_Header_Traits::
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
    << single_line_comment ("executor client")
    << "#include \"" << container.name () << "EC.h\"" << std::endl
    << "#include \"tao/LocalObject.h\"" << std::endl
    << std::endl
    << single_line_comment ("proxy header file")
    << include ("cuts/CCM_CoWorkEr_Proxy_T")
    << include ("cuts/CCM_Context_T");
}

//
// write_postamble
//
void CUTS_CIAO_Proxy_Header_Traits::
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
void CUTS_CIAO_Proxy_Header_Traits::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & component)
{
  if (!this->outfile ().is_open ())
    return;

  std::string name = component.name ();
  std::string proxy_exec = name + "_Exec";
  std::string proxy_ctx = proxy_exec + "_Context";

  PICML::Component supertype = PICML::Component (component).Archetype ();

  PICML::ComponentFactory supertype_factory;
  this->get_component_factory (supertype, supertype_factory);

  std::string ccm_type =
    scope (supertype, "::") + "CCM_" + (std::string)supertype.name ();

  std::string ccm_home =
    scope (supertype_factory, "::") +
    "CCM_" + (std::string)supertype_factory.name ();

  std::string proxy_type = name + "_Proxy";

  std::string ctx_proxy = name + "_Context_Proxy";

  this->outfile ()
    << std::endl
    << "namespace CIDL_" << monoimpl.name () << "{"

    // Generate the context proxy for the component.
    << "class " << ctx_proxy << " :" << std::endl
    << "  public CUTS_CCM_Context_T <" << scope (component, "::")
    << "CCM_" << name << "_Context> {"
    << "public:" << std::endl
    << single_line_comment ("constructor")
    << ctx_proxy << " (::Components::SessionContext_ptr ctx," << std::endl
    << "CUTS_Benchmark_Agent * agent);"
    << std::endl
    << single_line_comment ("destructor")
    << "virtual ~" << ctx_proxy << " (void);"
    << std::endl;

  // Generate the event sinks for the context.
  typedef std::vector <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set sources = component.OutEventPort_kind_children ();

  typedef
    void (CUTS_CIAO_Proxy_Header_Traits::*OutEventPort_method) (
    const PICML::OutEventPort &);

  std::for_each (sources.begin (),
                 sources.end (),
                 boost::bind (reinterpret_cast <OutEventPort_method> (
                 &CUTS_CIAO_Proxy_Header_Traits::write_method),
                 this,
                 _1));

  // Generate the receptacles for the context.
  typedef std::vector <PICML::RequiredRequestPort> RequiredRequestPort_Set;
  RequiredRequestPort_Set receptacles = component.RequiredRequestPort_kind_children ();

  typedef
    void (CUTS_CIAO_Proxy_Header_Traits::*RequiredRequestPort_method) (
    const PICML::RequiredRequestPort &);

  std::for_each (receptacles.begin (),
                 receptacles.end (),
                 boost::bind (reinterpret_cast <RequiredRequestPort_method> (
                 &CUTS_CIAO_Proxy_Header_Traits::write_method),
                 this,
                 _1));

  // We are now ready to generate the executor.
  this->outfile ()
    << "private:" << std::endl;

  // Reset the endpoint id for this iteration.
  this->endpoint_id_ = 1;

  std::for_each (
    sources.begin (),
    sources.end (),
    boost::bind (&CUTS_CIAO_Proxy_Header_Traits::write_id_variable,
                 this,
                 _1));

  this->outfile ()
    << "};"
    << single_line_comment ("Type definition for proxy base class")
    << "typedef CUTS_CCM_CoWorkEr_Proxy_T <" << std::endl
    << "  " << proxy_exec << "," << std::endl
    << "  " << ctx_proxy << "," << std::endl
    << "  " << ccm_type << "," << std::endl
    << "  " << ccm_home << "> " << proxy_type << ";"
    << std::endl

    // Generate the proxy for the component type.
    << "class " << name << " :" << std::endl
    << "  public " << proxy_type << " {"
    << "public:" << std::endl
    << "typedef " << proxy_type << " _proxy_type;"
    << std::endl

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
void CUTS_CIAO_Proxy_Header_Traits::
write_impl_end (const PICML::MonolithicImplementation & monoimpl,
                const PICML::Component & component)
{
  if (!this->outfile ().is_open ())
    return;

  this->outfile () << "};";
}

//
// get_component_factory
//
bool CUTS_CIAO_Proxy_Header_Traits::
get_component_factory (const PICML::Component & component,
                       PICML::ComponentFactory & factory)
{
  // Try and locate the real factory for the component.
  typedef std::set <PICML::ManagesComponent> Manages_Set;
  Manages_Set manages = component.srcManagesComponent ();

  if (manages.size () > 0)
  {
    PICML::ManagesComponent manage = (*manages.begin ());
    factory = manage.srcManagesComponent_end ();
    return true;
  }

  typedef std::set <PICML::ComponentRef> ComponentRef_Set;
  ComponentRef_Set refs = component.referedbyComponentRef ();

  PICML::MgaObject parent;
  std::string parent_type;

  for (ComponentRef_Set::iterator iter = refs.begin ();
       iter != refs.end ();
       iter ++)
  {
    parent = iter->parent ();
    Uml::Class type = parent.type ();

    if (type == PICML::File::meta ||  type == PICML::Package::meta)
      return this->get_component_factory (iter->ref (), factory);
  }

  return false;
}

//
// write_variables_begin
//
void CUTS_CIAO_Proxy_Header_Traits::
write_variables_begin (const PICML::Component & component)
{
  if (!this->outfile ().is_open ())
    return;

  this->outfile ()
    << "private:" << std::endl;

  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set sinks = component.InEventPort_kind_children ();

  std::for_each (
    sinks.begin (),
    sinks.end (),
    boost::bind (&CUTS_CIAO_Proxy_Header_Traits::write_eventsink_variable,
                 this,
                 _1));
}

//
// write_eventsink_variable
//
void CUTS_CIAO_Proxy_Header_Traits::
write_eventsink_variable (const PICML::InEventPort & sink)
{
  if (!this->outfile ().is_open ())
    return;

  PICML::Event event = sink.ref ();

  this->outfile ()
    << single_line_comment ((std::string)sink.name () + " event handler")
    << "CUTS_Event_Handler_Manager_T <" << std::endl
    << "  _proxy_type::_impl_type," << std::endl
    << "  ::" << scope (event, "::") << event.name () << "> "
    << "push_" << sink.name () << "_;"
    << std::endl;
}

//
// write_id_variable
//
void CUTS_CIAO_Proxy_Header_Traits::
write_id_variable (const PICML::OutEventPort & source)
{
  if (!this->outfile ().is_open ())
    return;

  std::string name = source.name ();

  this->outfile ()
    << single_line_comment (name + " id variable")
    << "static const size_t push_" << name << "_id_ = "
    << this->endpoint_id_ ++ << ";" << std::endl;
}

//
// write_ReadonlyAttribute_begin
//
void CUTS_CIAO_Proxy_Header_Traits::
write_ReadonlyAttribute_begin (const PICML::ReadonlyAttribute & attr)
{
  std::string name = attr.name ();

  if (name.find ("cuts_") != 0)
    this->_super::write_ReadonlyAttribute_begin (attr);
}

//
// write_ReadonlyAttribute_begin
//
void CUTS_CIAO_Proxy_Header_Traits::
write_ReadonlyAttribute_end (const PICML::ReadonlyAttribute & attr)
{
  std::string name = attr.name ();

  if (name.find ("cuts_") != 0)
    this->_super::write_ReadonlyAttribute_end (attr);
}

//
// write_ReadonlyAttribute_begin
//
void CUTS_CIAO_Proxy_Header_Traits::
write_Attribute_begin (const PICML::Attribute & attr)
{
  std::string name = attr.name ();

  if (name.find ("cuts_") != 0)
    this->_super::write_Attribute_begin (attr);
}

//
// write_ReadonlyAttribute_end
//
void CUTS_CIAO_Proxy_Header_Traits::
write_Attribute_end (const PICML::Attribute & attr)
{
  std::string name = attr.name ();

  if (name.find ("cuts_") != 0)
    this->_super::write_Attribute_end (attr);
}

