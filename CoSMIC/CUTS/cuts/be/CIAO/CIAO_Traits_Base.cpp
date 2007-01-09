// $Id$

#include "CIAO_Traits_Base.h"
#include "CIAO_In_Type.h"
#include "CIAO_Retn_Type.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include "Uml.h"
#include <algorithm>
#include <ctype.h>

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
scope (const PICML::NamedType & type,
       const std::string & separator)
{
  std::string scope;

  PICML::MgaObject parent = type.parent ();

  while (parent.type () != PICML::File::meta)
  {
    scope.insert (0, separator);
    scope.insert (0, parent.name ());

    parent = PICML::MgaObject::Cast (parent.parent ());
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
// write_factory_end
//
void CIAO_Traits_Base::
write_factory_end (const PICML::ComponentFactory & factory,
                   const PICML::MonolithicImplementation & impl,
                   const PICML::Component & type)
{
  // This is really closing off the implementation namespace
  this->outfile () << "}";
}

//
// write_method_begin [InEventPort]
//
void CIAO_Traits_Base::
write_method_begin (const PICML::InEventPort & sink)
{
  PICML::Event event = sink.ref ();

  if (event != Udm::null)
  {
    this->outfile ()
      << "push_" << sink.name () << " (" << std::endl
      << scope (event, "::") << event.name () << " * ev" << std::endl
      << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "  ACE_THROW_SPEC ((::CORBA::SystemException))";
  }
}

//
// write_method_begin [PeriodicEvent]
//
void CIAO_Traits_Base::
write_method_begin (const PICML::PeriodicEvent & periodic)
{
  this->outfile ()
    << "periodic_" << periodic.name () << " (void)";
}

//
// write_method_begin [ProvidedRequestPort]
//
void CIAO_Traits_Base::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  this->outfile ()
    << "get_" << facet.name () << " (" << std::endl
    << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException))";
}

//
// write_method_begin [ReadonlyAttribute]
//
void CIAO_Traits_Base::
write_method_begin (const PICML::ReadonlyAttribute & ro_attr)
{
  this->outfile ()
    << ro_attr.name () << " (" << std::endl
    << "void ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException))";
}

//
// write_method_begin [Attribute]
//
void CIAO_Traits_Base::
write_method_begin (const PICML::Attribute & attr)
{
  PICML::AttributeMember member = attr.AttributeMember_child ();
  PICML::MemberType mtype = member.ref ();

  this->outfile ()
    << attr.name () << " (" << std::endl;

  CUTS_CIAO_In_Type_T <PICML::MemberType>::write (this->outfile (), mtype);

  this->outfile ()
    << " " << attr.name () << std::endl
    << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException))";
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
      << "push_" << source.name () << " (" << std::endl
      << scope (event, "::") << event.name () << " * ev" << std::endl
      << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "  ACE_THROW_SPEC ((::CORBA::SystemException))";
  }
}

//
// write_method [RequiredRequestPort]
//
void CIAO_Traits_Base::
write_method (const PICML::RequiredRequestPort & receptacle)
{
  this->outfile ()
    << "get_connection_" << receptacle.name () << " (" << std::endl
    << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException))";
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
    << "set_session_context (" << std::endl
    << "::Components::SessionContext_ptr ctx" << std::endl
    << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException," << std::endl
    << "::Components::CCMException))";
}

//
// write_ciao_preactivate
//
void CIAO_Traits_Base::
write_ciao_preactivate (const PICML::Component & component)
{
  this->env_bits_[ENV_PREACTIVATE] = true;

  this->outfile ()
    << "ciao_preactivate (" << std::endl
    << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException," << std::endl
    << "::Components::CCMException))";
}

//
// write_ccm_activate
//
void CIAO_Traits_Base::
write_ccm_activate (const PICML::Component & component)
{
  this->env_bits_[ENV_ACTIVATE] = true;

  this->outfile ()
    << "ccm_activate (" << std::endl
    << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException," << std::endl
    << "::Components::CCMException))";
}

//
// write_ciao_postactivate
//
void CIAO_Traits_Base::
write_ciao_postactivate (const PICML::Component & component)
{
  this->env_bits_[ENV_POSTACTIVATE] = true;

  this->outfile ()
    << "ciao_postactivate (" << std::endl
    << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException," << std::endl
    << "::Components::CCMException))";
}

void CIAO_Traits_Base::
write_ccm_passivate (const PICML::Component & component)
{
  this->env_bits_[ENV_PASSIVATE] = true;

  this->outfile ()
    << "ccm_passivate (" << std::endl
    << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException," << std::endl
    << "::Components::CCMException))";
}

//
// write_ccm_remove
//
void CIAO_Traits_Base::
write_ccm_remove (const PICML::Component & component)
{
  this->env_bits_[ENV_REMOVE] = true;

  this->outfile ()
    << "ccm_remove (" << std::endl
    << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "  ACE_THROW_SPEC ((::CORBA::SystemException," << std::endl
    << "::Components::CCMException))";
}
