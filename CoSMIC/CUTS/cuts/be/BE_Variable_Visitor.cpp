// $Id$

#include "BE_Variable_Visitor.h"
#include "BE_File_Generator.h"
#include "UDM_Utility_T.h"
#include "boost/bind.hpp"
#include "boost/iterator/filter_iterator.hpp"
#include <algorithm>

//
// CUTS_BE_Variable_Visitor
//
CUTS_BE_Variable_Visitor::
CUTS_BE_Variable_Visitor (const CUTS_BE_File_Generator_Set & generators)
: generators_ (generators)
{

}

//
// ~CUTS_BE_Variable_Visitor
//
CUTS_BE_Variable_Visitor::
~CUTS_BE_Variable_Visitor (void)
{

}

//
// Visit_Component
//
void CUTS_BE_Variable_Visitor::
Visit_Component (const PICML::Component & component)
{
  // Begin writing the variables.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_variables_begin,
                              _1));

  // Write the explicit variables.
  typedef std::vector <PICML::Variable> Variable_Set;
  Variable_Set variables = component.Variable_children ();

  std::for_each (variables.begin (),
                 variables.end (),
                 boost::bind (&Variable_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Write the worker type variables.
  typedef std::vector <PICML::WorkerType> WorkerType_Set;
  WorkerType_Set worker_types = component.WorkerType_children ();

  std::for_each (worker_types.begin (),
                 worker_types.end (),
                 boost::bind (&WorkerType_Set::value_type::Accept,
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

  // End writing the variable section for the component.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_variables_end,
                              _1));
}

//
// Visit_Variable
//
void CUTS_BE_Variable_Visitor::
Visit_Variable (const PICML::Variable & variable)
{
  typedef
  void (CUTS_BE_File_Generator::* BE_METHOD)
       (const PICML::Variable &);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_METHOD> (
                              &CUTS_BE_File_Generator::write_variable),
                              _1,
                              variable));
}

//
// Visit_WorkerType
//
void CUTS_BE_Variable_Visitor::
Visit_WorkerType (const PICML::WorkerType & worker_type)
{
  typedef
  void (CUTS_BE_File_Generator::* BE_METHOD)
       (const PICML::WorkerType &);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_METHOD> (
                              &CUTS_BE_File_Generator::write_variable),
                              _1,
                              worker_type));
}

//
// Visit_Attribute
//
void CUTS_BE_Variable_Visitor::
Visit_Attribute (const PICML::Attribute & attr)
{
  typedef
  void (CUTS_BE_File_Generator::*BE_WRITE_METHOD)
       (const PICML::Attribute &);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_WRITE_METHOD> (
                              &CUTS_BE_File_Generator::write_variable),
                              _1,
                              attr));
}

//
// Visit_ReadonlyAttribute
//
void CUTS_BE_Variable_Visitor::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & attr)
{
  typedef
  void (CUTS_BE_File_Generator::*BE_WRITE_METHOD)
       (const PICML::ReadonlyAttribute &);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (static_cast <BE_WRITE_METHOD> (
                              &CUTS_BE_File_Generator::write_variable),
                              _1,
                              attr));
}
