// $Id$

#include "stdafx.h"
#include "Property_Replacer_Guard.h"
#include "parser/Property_Expander.hpp"

#include "game/mga/FCO.h"
#include "game/mga/Attribute.h"
#include "game/mga/Transaction.h"

//
// Property_Replacer_Guard
//
Property_Replacer_Guard::
Property_Replacer_Guard (GAME::Mga::Project proj,
                         const Property_Map & props,
                         std::set <GAME::Mga::Object> & names,
                         std::vector <GAME::Mga::Attribute> & attrs)
: proj_ (proj),
  props_ (props)
{
  GAME::Mga::Transaction t (this->proj_, TRANSACTION_GENERAL);
  this->replace_properties (props, names, attrs);
  t.commit ();
}

//
// ~Property_Replacer_Guard
//
Property_Replacer_Guard::~Property_Replacer_Guard (void)
{
  GAME::Mga::Transaction t (this->proj_, TRANSACTION_GENERAL);
  this->reset_model ();
  t.commit ();
}

//
// replace_properties
//
void Property_Replacer_Guard::
replace_properties (const Property_Map & props,
                    std::set <GAME::Mga::Object> & names,
                    std::vector <GAME::Mga::Attribute> & attrs)
{
  // Initialize the property tag expander.
  Property_Tag_Config config;
  config.tags_.first  = "<%";
  config.tags_.second = "%>";

  Property_Expander expander (config);

  // Replace the names in the objects.
  std::set <GAME::Mga::Object>::iterator
    name_iter = names.begin (), name_iter_end = names.end ();

  for (; name_iter != name_iter_end; ++ name_iter)
  {
    std::string result_str;
    const std::string name = (*name_iter)->name ();

    if (expander.evaluate (name.begin (), name.end (), props, result_str))
    {
      // Update the name with its expanded version.
      (*name_iter)->name (result_str);

      // Save the original name so we can restore it.
      this->orig_names_.push_back (std::make_pair (*name_iter, name));
    }
  }

  // Replace the attribute values.
  std::vector <GAME::Mga::Attribute>::iterator
    attr_iter = attrs.begin (), attr_iter_end = attrs.end ();

  for (; attr_iter != attr_iter_end; ++ attr_iter)
  {
    std::string result_str;
    const std::string value = (*attr_iter)->string_value ();

    if (expander.evaluate (value.begin (), value.end (), props, result_str))
    {
      // Update the name with its expanded version.
      (*attr_iter)->string_value (result_str);

      // Save the original name so we can restore it.
      this->orig_attrs_.push_back (std::make_pair (*attr_iter, value));
    }
  }
}

//
// reset_model
//
void Property_Replacer_Guard::reset_model (void)
{
  // Let's restore the original attribute values.
  Original_Attribute_Vector::iterator
    orig_attr_iter = this->orig_attrs_.begin (),
    orig_attr_iter_end = this->orig_attrs_.end ();

  for ( ; orig_attr_iter != orig_attr_iter_end; ++ orig_attr_iter)
  {
    // Get the attribute and original string value.
    GAME::Mga::Attribute attr = orig_attr_iter->first;
    std::string str_value = orig_attr_iter->second;

    // Reset the string value.
    attr->string_value (str_value);
  }

  // Let's restore the original name values.
  Original_Name_Vector::iterator
    orig_name_iter = this->orig_names_.begin (),
    orig_name_iter_end = this->orig_names_.end ();

  for ( ; orig_name_iter != orig_name_iter_end; ++ orig_name_iter)
  {
    // Get the attribute and original string value.
    GAME::Mga::Object obj = orig_name_iter->first;
    std::string orig_name = orig_name_iter->second;

    // Reset the string value.
    obj->name (orig_name);
  }
}
