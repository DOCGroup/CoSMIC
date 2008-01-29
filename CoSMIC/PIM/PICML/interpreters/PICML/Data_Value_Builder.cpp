// $Id$

// The following is a hack!!
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif

#include "Data_Value_Builder.h"
#include "Data_Value.h"
#include "Uml.h"
#include "gme/GME.h"
#include <memory>

namespace GME
{
//
// PICML_Data_Value_Builder
//
PICML_Data_Value_Builder::PICML_Data_Value_Builder (void)
{

}

//
//
//
PICML_Data_Value_Builder::~PICML_Data_Value_Builder (void)
{

}

//
// build_complex
//
bool PICML_Data_Value_Builder::
build_complex (const GME::FCO & datatype, PICML_Data_Value * & value)
{
  std::string name = datatype.meta ().name ();
  return this->build_complex_i (name, datatype, value);
}

//
// build_complex
//
bool PICML_Data_Value_Builder::
build_complex_i (const std::string & name,
                 const GME::FCO & fco,
                 PICML_Data_Value * & value)
{
  if (name == "Aggregate")
    return this->build_aggregate (GME::Model::_narrow (fco), value);
  else if (name  == "Enum")
    return this->build_enum (GME::Model::_narrow (fco), value);
  else if (name == "Collection")
    return this->build_collection (GME::Reference::_narrow (fco), value);
  else
    return false;
}

//
// build_aggregate
//
bool PICML_Data_Value_Builder::
build_aggregate (const GME::Model & aggregate,
                 PICML_Data_Value * & value)
{
  PICML_Aggregate_Data_Value * aggr = new PICML_Aggregate_Data_Value ();
  std::auto_ptr <PICML_Aggregate_Data_Value> auto_clean (aggr);

  typedef GME::Collection_T <GME::Reference> Member_Set;
  Member_Set members;

  if (aggregate.references ("Member", members) > 0)
  {
    Member_Set::iterator
      iter = members.items ().begin (),
      iter_end = members.items ().end ();

    PICML_Data_Value * temp = 0;

    for (; iter != iter_end; iter ++)
    {
      if (this->create_data_value (iter->refers_to (), temp))
        aggr->insert_member (iter->name (), temp);
      else
        return false;
    }
  }

  value = auto_clean.release ();
  return true;
}

//
// build_collection
//
bool PICML_Data_Value_Builder::
build_collection (const GME::Reference & collection,
                  PICML_Data_Value * & value)
{
  GME::FCO mt = collection.refers_to ();

  if (!mt)
    return false;

  PICML_Data_Value * type = 0;

  if (!this->create_data_value (mt, type))
    return false;

  value = new PICML_Sequence_Data_Value (type);
  return true;
}

//
// build_enum
//
bool PICML_Data_Value_Builder::
build_enum (const GME::Model & e, PICML_Data_Value * & value)
{
  PICML_Enum_Data_Value * e_val = new PICML_Enum_Data_Value ();
  std::auto_ptr <PICML_Enum_Data_Value> auto_clean (e_val);

  typedef GME::Collection_T <GME::Atom> EnumValue_Set;
  EnumValue_Set opts;

  if (e.atoms ("EnumValue", opts) > 0)
  {
    EnumValue_Set::iterator
      iter = opts.items ().begin (),
      iter_end = opts.items ().end ();

    for (; iter != iter_end; iter ++)
      e_val->insert_option (iter->name ());
  }

  value = auto_clean.release ();
  return true;
}

//
// create_data_value
//
bool PICML_Data_Value_Builder::
create_data_value (const GME::FCO & type, PICML_Data_Value * & value)
{
  std::string meta = type.meta ().name ();

  if (meta == "String")
  {
    value = new PICML_String_Data_Value ();
  }
  else if (meta == "LongInteger")
  {
    value = new PICML_Long_Data_Value ();
  }
  else if (meta == "Byte")
  {
    value = new PICML_Char_Data_Value ();
  }
  else if (meta == "ShortInteger")
  {
    value = new PICML_Short_Data_Value ();
  }
  else if (meta == "Boolean")
  {
    value = new PICML_Boolean_Data_Value ();
  }
  else
    return this->build_complex_i (meta, type, value);

  return true;
}
}

namespace PICML
{
//
// Data_Value_Builder
//
Data_Value_Builder::Data_Value_Builder (void)
{

}

//
// Data_Value_Builder
//
Data_Value_Builder::~Data_Value_Builder (void)
{

}

//
// build
//
bool Data_Value_Builder::
build (const PICML::Collection & collection, PICML_Data_Value * & value)
{
  PICML::MemberType mt = collection.ref ();

  if (mt == Udm::null)
    return false;

  PICML_Data_Value * type = 0;

  if (!this->create_data_value (mt, type))
    return false;

  value = new PICML_Sequence_Data_Value (type);
  return true;
}

//
// build
//
bool Data_Value_Builder::
build (const PICML::Enum & e, PICML_Data_Value * & value)
{
  PICML_Enum_Data_Value * e_val = new PICML_Enum_Data_Value ();
  std::auto_ptr <PICML_Enum_Data_Value> auto_clean (e_val);

  typedef std::vector <PICML::EnumValue> EnumValue_Set;
  EnumValue_Set opts = e.EnumValue_children ();

  EnumValue_Set::iterator
    iter = opts.begin (),
    iter_end = opts.end ();

  for (; iter != iter_end; iter ++)
    e_val->insert_option (iter->name ());

  value = auto_clean.release ();
  return true;
}

//
// build
//
bool Data_Value_Builder::
build (const PICML::Aggregate & aggregate, PICML_Data_Value * & value)
{
  PICML_Aggregate_Data_Value * aggr = new PICML_Aggregate_Data_Value ();
  std::auto_ptr <PICML_Aggregate_Data_Value> auto_clean (aggr);

  typedef std::vector <PICML::Member> Member_Set;
  Member_Set members = aggregate.Member_children ();

  Member_Set::iterator
    iter = members.begin (),
    iter_end = members.end ();

  PICML_Data_Value * temp = 0;

  for (; iter != iter_end; iter ++)
  {
    if (this->create_data_value (iter->ref (), temp))
      aggr->insert_member (iter->name (), temp);
    else
      return false;
  }

  value = auto_clean.release ();
  return true;
}

//
// create_data_value
//
bool Data_Value_Builder::
create_data_value (const PICML::MemberType & type, PICML_Data_Value * & value)
{
  Uml::Class meta = type.type ();

  if (meta == PICML::String::meta)
  {
    value = new PICML_String_Data_Value ();
  }
  else if (meta == PICML::LongInteger::meta)
  {
    value = new PICML_Long_Data_Value ();
  }
  else if (meta == PICML::Byte::meta)
  {
    value = new PICML_Char_Data_Value ();
  }
  else if (meta == PICML::ShortInteger::meta)
  {
    value = new PICML_Short_Data_Value ();
  }
  else if (meta == PICML::Boolean::meta)
  {
    value = new PICML_Boolean_Data_Value ();
  }
  else if (meta == PICML::Enum::meta)
  {
    return this->build (PICML::Enum::Cast (type), value);
  }
  else if (meta == PICML::Aggregate::meta)
  {
    return this->build (PICML::Aggregate::Cast (type), value);
  }
  else if (meta == PICML::Collection::meta)
  {
    return this->build (PICML::Collection::Cast (type), value);
  }
  else
    return false;

  return true;
}

}
