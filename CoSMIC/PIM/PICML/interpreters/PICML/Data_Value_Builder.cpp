// $Id$

// The following is a hack!!
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif

#include "game/Mga.h"
#include "Data_Value_Builder.h"
#include "Data_Value.h"
#include "game/GAME.h"
#include "Uml.h"
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
build_complex (const std::string & name,
               const GAME::FCO & datatype,
               PICML_Data_Value * & value,
               PICML_Data_Value * parent)
{
  std::string meta = datatype.meta ().name ();
  return this->build_complex_i (name, meta, datatype, value, parent);
}

//
// build_complex
//
bool PICML_Data_Value_Builder::
build_complex_i (const std::string & name,
                 const std::string & meta,
                 const GAME::FCO & fco,
                 PICML_Data_Value * & value,
                 PICML_Data_Value * parent)
{
  if (meta == "Aggregate")
    return this->build_aggregate (name, GAME::Model::_narrow (fco), value, parent);
  else if (meta  == "Enum")
    return this->build_enum (name, GAME::Model::_narrow (fco), value, parent);
  else if (meta == "Collection")
    return this->build_collection (name, GAME::Reference::_narrow (fco), value, parent);
  else if (meta == "Alias")
    return this->build_alias (name, GAME::Reference::_narrow (fco), value, parent);
  else if (meta == "Event")
    return this->build_event (name, GAME::Model::_narrow (fco), value, parent);
  else
    return false;
}

//
// build_aggregate
//
bool PICML_Data_Value_Builder::
build_aggregate (const std::string & name,
                 const GAME::Model & aggregate,
                 PICML_Data_Value * & value,
                 PICML_Data_Value * parent)
{
  PICML_Aggregate_Data_Value * aggr = new PICML_Aggregate_Data_Value (name, parent);
  std::auto_ptr <PICML_Aggregate_Data_Value> auto_clean (aggr);

  typedef std::vector <GAME::Reference> Member_Set;
  Member_Set members;

  if (aggregate.children ("Member", members) > 0)
  {
    Member_Set::iterator
      iter = members.begin (),
      iter_end = members.end ();

    PICML_Data_Value * temp = 0;

    for (; iter != iter_end; iter ++)
    {
      if (this->create_data_value (iter->name (), iter->refers_to (), temp, aggr))
        aggr->insert_member (temp);
      else
        return false;
    }
  }

  value = auto_clean.release ();
  return true;
}

//
// build_event
//
bool PICML_Data_Value_Builder::
build_event (const std::string & name,
             const GAME::Model & evt,
             PICML_Data_Value * & value,
             PICML_Data_Value * parent)
{
  PICML_Event_Data_Value * ev = new PICML_Event_Data_Value (name, parent);
  std::auto_ptr <PICML_Event_Data_Value> auto_clean (ev);

  typedef std::vector <GAME::Reference> Member_Set;
  Member_Set members;

  if (evt.children ("Member", members) > 0)
  {
    Member_Set::iterator
      iter = members.begin (),
      iter_end = members.end ();

    PICML_Data_Value * temp = 0;

    for (; iter != iter_end; iter ++)
    {
      if (this->create_data_value (iter->name (), iter->refers_to (), temp, ev))
        ev->insert_member (temp);
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
build_collection (const std::string & name,
                  const GAME::Reference & collection,
                  PICML_Data_Value * & value,
                  PICML_Data_Value * parent)
{
  GAME::FCO mt = collection.refers_to ();

  if (!mt)
    return false;

  PICML_Data_Value * type = 0;

  if (!this->create_data_value (mt.name (), mt, type))
    return false;

  value = new PICML_Sequence_Data_Value (name, type, parent);
  return true;
}

//
// build_enum
//
bool PICML_Data_Value_Builder::
build_alias (const std::string & name,
             const GAME::Reference & alias,
             PICML_Data_Value * & value,
             PICML_Data_Value * parent)
{
  // Get the alias type.
  GAME::FCO ref = alias.refers_to ();

  if (ref)
    return this->create_data_value (name, ref, value, parent);
  else
    return false;
}

//
// build_enum
//
bool PICML_Data_Value_Builder::
build_enum (const std::string & name,
            const GAME::Model & e,
            PICML_Data_Value * & value,
            PICML_Data_Value * parent)
{
  PICML_Enum_Data_Value * e_val = new PICML_Enum_Data_Value (name, parent);
  std::auto_ptr <PICML_Enum_Data_Value> auto_clean (e_val);

  typedef std::vector <GAME::Atom> EnumValue_Set;
  EnumValue_Set opts;

  if (e.children ("EnumValue", opts) > 0)
  {
    EnumValue_Set::iterator
      iter = opts.begin (),
      iter_end = opts.end ();

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
create_data_value (const std::string & name,
                   const GAME::FCO & type,
                   PICML_Data_Value * & value,
                   PICML_Data_Value * parent)
{
  std::string meta = type.meta ().name ();

  if (meta == "String")
  {
    value = new PICML_String_Data_Value (name, parent);
  }
  else if (meta == "LongInteger")
  {
    value = new PICML_Long_Data_Value (name, parent);
  }
  else if (meta == "Byte")
  {
    value = new PICML_Char_Data_Value (name, parent);
  }
  else if (meta == "ShortInteger")
  {
    value = new PICML_Short_Data_Value (name, parent);
  }
  else if (meta == "Boolean")
  {
    value = new PICML_Boolean_Data_Value (name, parent);
  }
  else
    return this->build_complex_i (name, meta, type, value, parent);

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
build (const std::string & name,
       const PICML::Collection & collection,
       PICML_Data_Value * & value)
{
  PICML::MemberType mt = collection.ref ();

  if (mt == Udm::null)
    return false;

  PICML_Data_Value * type = 0;

  if (!this->create_data_value (name, mt, type))
    return false;

  value = new PICML_Sequence_Data_Value (name, type);
  return true;
}

//
// build
//
bool Data_Value_Builder::
build (const std::string & name,
       const PICML::Alias & alias,
       PICML_Data_Value * & value)
{
  PICML::MemberType ref = alias.ref ();

  if (ref != Udm::null)
    return this->create_data_value (name, ref, value);
  else
    return false;
}

//
// build
//
bool Data_Value_Builder::
build (const std::string & name,
       const PICML::Enum & e,
       PICML_Data_Value * & value)
{
  PICML_Enum_Data_Value * e_val = new PICML_Enum_Data_Value (name);
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
build (const std::string & name,
       const PICML::Aggregate & aggregate,
       PICML_Data_Value * & value)
{
  PICML_Aggregate_Data_Value * aggr = new PICML_Aggregate_Data_Value (name);
  std::auto_ptr <PICML_Aggregate_Data_Value> auto_clean (aggr);

  typedef std::vector <PICML::Member> Member_Set;
  Member_Set members = aggregate.Member_children ();

  Member_Set::iterator
    iter = members.begin (),
    iter_end = members.end ();

  PICML_Data_Value * temp = 0;

  for (; iter != iter_end; iter ++)
  {
    if (this->create_data_value (iter->name (), iter->ref (), temp))
      aggr->insert_member (temp);
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
create_data_value (const std::string & name,
                   const PICML::MemberType & type,
                   PICML_Data_Value * & value)
{
  Uml::Class meta = type.type ();

  if (meta == PICML::String::meta)
  {
    value = new PICML_String_Data_Value (name);
  }
  else if (meta == PICML::LongInteger::meta)
  {
    value = new PICML_Long_Data_Value (name);
  }
  else if (meta == PICML::Byte::meta)
  {
    value = new PICML_Char_Data_Value (name);
  }
  else if (meta == PICML::ShortInteger::meta)
  {
    value = new PICML_Short_Data_Value (name);
  }
  else if (meta == PICML::Boolean::meta)
  {
    value = new PICML_Boolean_Data_Value (name);
  }
  else if (meta == PICML::Enum::meta)
  {
    return this->build (name, PICML::Enum::Cast (type), value);
  }
  else if (meta == PICML::Aggregate::meta)
  {
    return this->build (name, PICML::Aggregate::Cast (type), value);
  }
  else if (meta == PICML::Collection::meta)
  {
    return this->build (name, PICML::Collection::Cast (type), value);
  }
  else if (meta == PICML::Alias::meta)
  {
    return this->build (name, PICML::Alias::Cast (type), value);
  }
  else
    return false;

  return true;
}

void
Data_Value_Builder::create_repositoryID_Impl (const ::PICML::MgaObject &type,
                RepoID &repoid)
{
  ::Uml::Class const &metatype = type.type ();

  if (metatype != PICML::File::meta)
    create_repositoryID_Impl (::PICML::MgaObject::Cast (type.parent ()), repoid);
  else
    {
      repoid.format = "IDL";
      repoid.version = "1.0"; // Default version
      Prefixable pfx = Prefixable::Cast (type);
      repoid.prefix = pfx.PrefixTag ();
      return;
    }

  // at this point, all of our parents are properly included in the repository ID
  if (metatype == PICML::Package::meta)
    {
      Package pkg = Package::Cast (type);
      repoid.prefix = pkg.PrefixTag ();
      repoid.rest += "/";
      repoid.rest += pkg.name ();
      return;
    }

  // In theory, if we get to this point, we are NOT a package and NOT a file
  // so it is PROBABLY safe to assume this is the end of the repoid.

  // Check if there is a version
  try
    {
      Taggable tg = Taggable::Cast (type);
      repoid.version = tg.VersionTag ();
    }
  catch (...) {}

  repoid.rest += "/";
  repoid.rest += type.name ();
  return;
}

std::string
Data_Value_Builder::create_repo_id (const ::PICML::MgaObject &type)
{
  try
    { // Check to see if the element has a hardcoded
      // RepoId
      Taggable tg = Taggable::Cast (type);
      if (std::string (tg.SpecifyIdTag ()) != "")
  return tg.SpecifyIdTag ();
      }
  catch (...) {}

  RepoID repoid;
  create_repositoryID_Impl (type, repoid);

  std::string retval (repoid.format + ':' + repoid.prefix + repoid.rest);

  if (repoid.version != "")
    retval += ":" + repoid.version;

  return retval;
}

}
