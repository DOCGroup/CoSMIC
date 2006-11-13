// $Id$

#include "BE_Method_Visitor.h"
#include "BE_File_Generator.h"
#include "BE_Execution_Visitor.h"
#include "UDM_Utility_T.h"
#include "boost/bind.hpp"
#include "boost/iterator/filter_iterator.hpp"
#include <algorithm>

//
// CUTS_BE_Method_Visitor
//
CUTS_BE_Method_Visitor::
CUTS_BE_Method_Visitor (const CUTS_BE_File_Generator_Set & generators)
: generators_ (generators)
{

}

//
// CUTS_BE_Method_Visitor
//
CUTS_BE_Method_Visitor::
~CUTS_BE_Method_Visitor (void)
{

}

//
// Visit_Component
//
void CUTS_BE_Method_Visitor::
Visit_Component (const PICML::Component & component)
{
  // @@ event sinks
  typedef std::vector <PICML::InEventPort> EventSink_Set;
  EventSink_Set sinks = component.InEventPort_kind_children ();

  std::for_each (sinks.begin (),
                 sinks.end (),
                 boost::bind (&EventSink_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // @@ facets
  typedef std::vector <PICML::ProvidedRequestPort> Facet_Set;
  Facet_Set facets = component.ProvidedRequestPort_kind_children ();

  std::for_each (facets.begin (),
                 facets.end (),
                 boost::bind (&Facet_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // @@ readonly attributes
  typedef std::vector <PICML::ReadonlyAttribute> ReadonlyAttribute_Set;
  ReadonlyAttribute_Set readonly_attrs = component.ReadonlyAttribute_children ();

  typedef
    is_type <PICML::ReadonlyAttribute> ReadonlyAttribute_Type;

  std::for_each (
    boost::make_filter_iterator <ReadonlyAttribute_Type> (
      readonly_attrs.begin (), readonly_attrs.end ()),
    boost::make_filter_iterator <ReadonlyAttribute_Type> (
      readonly_attrs.end (), readonly_attrs.end ()),
    boost::bind (&ReadonlyAttribute_Set::value_type::Accept,
                 _1,
                 boost::ref (*this)));

  // @@ read/write attributes
  typedef std::vector <PICML::Attribute> Attribute_Set;
  Attribute_Set attrs = component.Attribute_kind_children ();

  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&Attribute_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // @@ environment actions
  PICML::Environment env = component.Environment_child ();
  if (env != Udm::null)
    env.Accept (*this);

  // @@ periodic actions
  typedef std::vector <PICML::PeriodicEvent> Periodic_Set;
  Periodic_Set periodics = component.PeriodicEvent_kind_children ();

  std::for_each (periodics.begin (),
                 periodics.end (),
                 boost::bind (&Periodic_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ProvidedRequestPort
//
void CUTS_BE_Method_Visitor::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & facet)
{
  typedef
  void (CUTS_BE_File_Generator::* BE_WRITE_METHOD)
       (const PICML::ProvidedRequestPort &);

  // Signal the start of writing a <InEventPort>.
  std::for_each (
    this->generators_.begin (),
    this->generators_.end (),
    boost::bind (static_cast <BE_WRITE_METHOD> (
                 &CUTS_BE_File_Generator::write_method_begin),
                 _1,
                 facet));

  // @@ eventually we will support actions!!

  // Signal the end of writing a <InEventPort>.
  std::for_each (
    this->generators_.begin (),
    this->generators_.end (),
    boost::bind (&CUTS_BE_File_Generator::write_method_end,
                 _1));
}

//
// Visit_InEventPort
//
void CUTS_BE_Method_Visitor::
Visit_InEventPort (const PICML::InEventPort & sink)
{
  typedef
  void (CUTS_BE_File_Generator::*BE_WRITE_METHOD)
       (const PICML::InEventPort &);

  // Signal the start of writing a <InEventPort>.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_WRITE_METHOD> (
                              &CUTS_BE_File_Generator::write_method_begin),
                              _1,
                              sink));

  // Visit the input action for this port.
  PICML::Input input = sink.dstInput ();

  if (input != Udm::null)
  {
    CUTS_BE_Execution_Visitor execution_visitor (this->generators_);
    input.Accept (execution_visitor);
  }

  // Signal the end of writing a <InEventPort>.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_method_end,
                              _1));
}

//
// Visit_PeriodicEvent
//
void CUTS_BE_Method_Visitor::
Visit_PeriodicEvent (const PICML::PeriodicEvent & periodic)
{
  typedef
  void (CUTS_BE_File_Generator::*BE_WRITE_METHOD)
       (const PICML::PeriodicEvent &);

  // Signal the start of writing a <PeriodicEvent>.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_WRITE_METHOD> (
                              &CUTS_BE_File_Generator::write_method_begin),
                              _1,
                              periodic));

  PICML::Input input = periodic.dstInput ();

  if (input != Udm::null)
  {
    // Let's generate the execution sequence for this event.
    CUTS_BE_Execution_Visitor execution_visitor (this->generators_);
    input.Accept (execution_visitor);
  }

  // Signal the end of writing a <PeriodicEvent>.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_method_end,
                              _1));
}

//
// Visit_Attribute
//
void CUTS_BE_Method_Visitor::
Visit_Attribute (const PICML::Attribute & attr)
{
  typedef
  void (CUTS_BE_File_Generator::* BE_METHOD)
       (const PICML::Attribute &);

  // Signal the end of writing a <InEventPort>.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_METHOD> (
                              &CUTS_BE_File_Generator::write_method_begin),
                              _1,
                              attr));

  // Signal the end of writing a <InEventPort>.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_method_end,
                              _1));
}

//
// Visit_ReadonlyAttribute
//
void CUTS_BE_Method_Visitor::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & attr)
{
  typedef
  void (CUTS_BE_File_Generator::* BE_METHOD)
       (const PICML::ReadonlyAttribute &);

  // Signal the end of writing a <InEventPort>.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_METHOD> (
                              &CUTS_BE_File_Generator::write_method_begin),
                              _1,
                              attr));

  // Signal the end of writing a <InEventPort>.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_method_end,
                              _1));
}

//
// Visit_Environment
//
void CUTS_BE_Method_Visitor::
Visit_Environment (const PICML::Environment & env)
{
  typedef
  void (CUTS_BE_File_Generator::* BE_METHOD)
       (const PICML::InputAction &);

  typedef std::set <PICML::MultiInput> MultiInput_Set;
  MultiInput_Set inputs = env.dstMultiInput ();

  for (MultiInput_Set::iterator iter = inputs.begin ();
       iter != inputs.end ();
       iter ++)
  {
    PICML::InputAction action =
      PICML::InputAction::Cast (iter->dstMultiInput_end ());

    std::for_each (
      this->generators_.begin (),
      this->generators_.end (),
        boost::bind (static_cast <BE_METHOD> (
                     &CUTS_BE_File_Generator::write_environment_begin),
                     _1,
                     action));

    CUTS_BE_Execution_Visitor execution_visitor (this->generators_);
    action.Accept (execution_visitor);

    // Signal the end of writing a <InEventPort>.
    std::for_each (this->generators_.begin (),
                   this->generators_.end (),
                   boost::bind (&CUTS_BE_File_Generator::write_environment_end,
                                _1));
  }
}
