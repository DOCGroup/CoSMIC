// $Id$

#include "Data_Value.h"
#include "Data_Value_Visitor.h"
#include "Data_Value_Parser.h"
#include <sstream>

///////////////////////////////////////////////////////////////////////////////
// class PICML_Data_Value

//
// PICML_Data_Value
//
PICML_Data_Value::
PICML_Data_Value (const std::string & name, PICML_Data_Value * parent)
: name_ (name),
  parent_ (parent),
  is_uptodate_ (true)
{

}

//
// PICML_Data_Value
//
PICML_Data_Value::~PICML_Data_Value (void)
{

}

//
// value
//
void PICML_Data_Value::value (const std::string & v)
{
  // Set the new value and invalidate the object.
  this->is_uptodate_ = false;
  this->value_ = v;

  // Notify all parents that they are invalid.
  PICML_Data_Value * parent = this->parent_;

  while (parent != 0)
  {
    parent->is_uptodate_ = false;
    parent = parent->parent_;
  }
}

//
// value
//
const std::string & PICML_Data_Value::value (void) const
{
  this->is_uptodate_ = true;
  return this->value_;
}

//
// name
//
const std::string & PICML_Data_Value::name (void) const
{
  return this->name_;
}

//
// name
//
bool PICML_Data_Value::is_uptodate (void) const
{
  return this->is_uptodate_;
}

//
// reset
//
void PICML_Data_Value::reset (void)
{
  this->value_.clear ();
  this->is_uptodate_ = false;
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_String_Data_Value

//
// PICML_String_Data_Value
//
PICML_String_Data_Value::
PICML_String_Data_Value (const std::string & name, PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_String_Data_Value
//
PICML_String_Data_Value::~PICML_String_Data_Value (void)
{

}

void PICML_String_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_String_Data_Value (*this);
}

PICML_Data_Value *
PICML_String_Data_Value::_create (const std::string & name,
                                  PICML_Data_Value * parent) const
{
  return new PICML_String_Data_Value (name, parent);
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Char_Data_Value

//
// PICML_Char_Data_Value
//
PICML_Char_Data_Value::
PICML_Char_Data_Value (const std::string & name, PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_String_Data_Value
//
PICML_Char_Data_Value::~PICML_Char_Data_Value (void)
{

}

void PICML_Char_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_Char_Data_Value (*this);
}

PICML_Data_Value *
PICML_Char_Data_Value::_create (const std::string & name,
                                PICML_Data_Value * parent) const
{
  return new PICML_Char_Data_Value (name, parent);
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Short_Data_Value

//
// PICML_Short_Data_Value
//
PICML_Short_Data_Value::
PICML_Short_Data_Value (const std::string & name, PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_Short_Data_Value
//
PICML_Short_Data_Value::~PICML_Short_Data_Value (void)
{

}

void PICML_Short_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_Short_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value *
PICML_Short_Data_Value::
_create (const std::string & name, PICML_Data_Value * parent) const
{
  return new PICML_Short_Data_Value (name, parent);
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_UShort_Data_Value

//
// PICML_UShort_Data_Value
//
PICML_UShort_Data_Value::
PICML_UShort_Data_Value (const std::string & name, PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_Short_Data_Value
//
PICML_UShort_Data_Value::~PICML_UShort_Data_Value (void)
{

}

void PICML_UShort_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_UShort_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value *
PICML_UShort_Data_Value::
_create (const std::string & name, PICML_Data_Value * parent) const
{
  return new PICML_UShort_Data_Value (name, parent);
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Long_Data_Value

//
// PICML_Long_Data_Value
//
PICML_Long_Data_Value::
PICML_Long_Data_Value (const std::string & name, PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_Short_Data_Value
//
PICML_Long_Data_Value::~PICML_Long_Data_Value (void)
{

}

void PICML_Long_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_Long_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value *
PICML_Long_Data_Value::
_create (const std::string & name, PICML_Data_Value * parent) const
{
  return new PICML_Long_Data_Value (name, parent);
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_ULong_Data_Value

//
// PICML_ULong_Data_Value
//
PICML_ULong_Data_Value::
PICML_ULong_Data_Value (const std::string & name,
                        PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_ULong_Data_Value
//
PICML_ULong_Data_Value::~PICML_ULong_Data_Value (void)
{

}

void PICML_ULong_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_ULong_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value *
PICML_ULong_Data_Value::
_create (const std::string & name, PICML_Data_Value * parent) const
{
  return new PICML_ULong_Data_Value (name, parent);
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Boolean_Data_Value

//
// PICML_Boolean_Data_Value
//
PICML_Boolean_Data_Value::
PICML_Boolean_Data_Value (const std::string & name, PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_Boolean_Data_Value
//
PICML_Boolean_Data_Value::~PICML_Boolean_Data_Value (void)
{

}

void PICML_Boolean_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_Boolean_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value *
PICML_Boolean_Data_Value::
_create (const std::string & name, PICML_Data_Value * parent) const
{
  return new PICML_Boolean_Data_Value (name, parent);
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Enum_Data_Value

//
// PICML_Enum_Data_Value
//
PICML_Enum_Data_Value::
PICML_Enum_Data_Value (const std::string & name, PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_Enum_Data_Value
//
PICML_Enum_Data_Value::~PICML_Enum_Data_Value (void)
{

}

void PICML_Enum_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_Enum_Data_Value (*this);
}

//
// insert_option
//
void PICML_Enum_Data_Value::insert_option (const std::string & opt)
{
  this->options_.insert (opt);
}

//
// options
//
const PICML_Enum_Data_Value::container_type &
PICML_Enum_Data_Value::options (void) const
{
  return this->options_;
}

//
// _create
//
PICML_Data_Value *
PICML_Enum_Data_Value::
_create (const std::string & name, PICML_Data_Value * parent) const
{
  PICML_Enum_Data_Value * value =
    new PICML_Enum_Data_Value (name, parent);

  container_type::const_iterator
    iter = this->options_.begin (),
    iter_end = this->options_.end ();

  for (; iter != iter_end; iter ++)
    value->insert_option (*iter);

  return value;
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Aggregate_Data_Value

//
// PICML_Aggregate_Data_Value
//
PICML_Aggregate_Data_Value::
PICML_Aggregate_Data_Value (const std::string & name,
                            PICML_Data_Value * parent)
: PICML_Data_Value (name, parent)
{

}

//
// ~PICML_Aggregate_Data_Value
//
PICML_Aggregate_Data_Value::~PICML_Aggregate_Data_Value (void)
{
  container_type::iterator
    iter = this->members_.begin (),
    iter_end = this->members_.end ();

  for ( ; iter != iter_end; iter ++)
  {
    if (iter->second != 0)
      delete iter->second;
  }
}

//
// _create
//
PICML_Data_Value *
PICML_Aggregate_Data_Value::
_create (const std::string & name, PICML_Data_Value * parent) const
{
  std::auto_ptr <PICML_Aggregate_Data_Value>
    value (new PICML_Aggregate_Data_Value (name, parent));

  const_iterator
    iter = this->members_.begin (),
    iter_end = this->members_.end ();

  for (; iter != iter_end; iter ++)
  {
    // Create the new member for the aggregate.
    PICML_Data_Value * member =
      iter->second->_create (iter->first, value.get ());

    value->insert_member (member);
  }

  return value.release ();
}

//
// reset
//
void PICML_Aggregate_Data_Value::reset (void)
{
  PICML_Data_Value::reset ();

  container_type::iterator
    iter = this->members_.begin (),
    iter_end = this->members_.end ();

  for (; iter != iter_end; iter ++)
    iter->second->reset ();
}

//
// accept
//
void PICML_Aggregate_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_Aggregate_Data_Value (*this);
}

//
// value
//
void PICML_Aggregate_Data_Value::value (const std::string & v)
{
  // Reset our before parsing the new value.
  this->reset ();

  PICML_Data_Value_Parser p (this);

  if (boost::spirit::parse (v.c_str (),
                            p.use_parser <PICML_Data_Value_Parser::aggregate> (),
                            boost::spirit::space_p).full)
  {
    PICML_Data_Value::value (v);
  }
}

//
// insert_member
//
void PICML_Aggregate_Data_Value::
insert_member (PICML_Data_Value * value)
{
  PICML_Data_Value * temp = 0;

  // Make sure the parent is this object.
  if (value->parent_ != this)
    value->parent_ = this;

  if (this->find_member (value->name (), temp))
  {
    // Delete the old data value.
    delete temp;

    // Save the new value.
    this->members_[value->name ()] = value;
  }
  else
    this->members_.insert (std::make_pair (value->name (), value));
}

//
// remove_member
//
void PICML_Aggregate_Data_Value::
remove_member (const std::string & name)
{
  container_type::iterator iter = this->members_.find (name);

  if (iter != this->members_.end ())
  {
    // Delete the data value.
    delete iter->second;

    // Remove the member for the collection.
    this->members_.erase (iter);
  }
}

//
// find_member
//
bool PICML_Aggregate_Data_Value::
find_member (const std::string & name, PICML_Data_Value * & member) const
{
  container_type::const_iterator iter = this->members_.find (name);

  if (iter != this->members_.end ())
  {
    member = iter->second;
    return true;
  }

  return false;
}

//
// operator []
//
const PICML_Data_Value * PICML_Aggregate_Data_Value::
operator [] (const std::string & name)
{
  return this->members_[name];
}

//
// begin
//
PICML_Aggregate_Data_Value::const_iterator
PICML_Aggregate_Data_Value::begin (void) const
{
  return this->members_.begin ();
}

//
// begin
//
PICML_Aggregate_Data_Value::iterator
PICML_Aggregate_Data_Value::begin (void)
{
  return this->members_.begin ();
}

//
// end
//
PICML_Aggregate_Data_Value::const_iterator
PICML_Aggregate_Data_Value::end (void) const
{
  return this->members_.end ();
}

//
// end
//
PICML_Aggregate_Data_Value::iterator
PICML_Aggregate_Data_Value::end (void)
{
  return this->members_.end ();
}


//
// value
//
const std::string &
PICML_Aggregate_Data_Value::value (void)
{
  if (!this->is_uptodate_)
  {
    // Reconstruct the value of the aggregate.
    std::ostringstream ostr;
    ostr << "{";

    container_type::const_iterator
      iter = this->members_.begin (),
      iter_end = this->members_.end ();

    if (iter != iter_end)
    {
      ostr << " " << iter->first << "=" << iter->second->value ();

      for (++ iter; iter != iter_end; iter ++)
        ostr << "; " << iter->first << "=" << iter->second->value ();
    }

    ostr << "}";

    // Save the value. This will force all the parents to
    // update themselves as well.
    PICML_Data_Value::value (ostr.str ());
  }

  return PICML_Data_Value::value ();
}

//
// size
//
size_t PICML_Aggregate_Data_Value::size (void) const
{
  return this->members_.size ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Sequence_Data_Value

//
// PICML_Sequence_Data_Value
//
PICML_Sequence_Data_Value::
PICML_Sequence_Data_Value (const std::string & name,
                           PICML_Data_Value * type,
                           PICML_Data_Value * parent)
: PICML_Data_Value (name, parent),
  type_ (type)
{

}

//
// ~PICML_Sequence_Data_Value
//
PICML_Sequence_Data_Value::~PICML_Sequence_Data_Value (void)
{
  container_type::iterator
    iter = this->sequence_.begin (),
    iter_end = this->sequence_.end ();

  for ( ; iter != iter_end; iter ++)
    delete *iter;
}

void PICML_Sequence_Data_Value::
accept (PICML_Data_Value_Visitor & visitor) const
{
  visitor.visit_PICML_Sequence_Data_Value (*this);
}

//
// operator []
//
PICML_Data_Value * PICML_Sequence_Data_Value::
operator [] (int index)
{
  return this->sequence_[index];
}

//
// operator []
//
const PICML_Data_Value *
PICML_Sequence_Data_Value::operator [] (int index) const
{
  return this->sequence_[index];
}

//
// begin
//
PICML_Sequence_Data_Value::iterator
PICML_Sequence_Data_Value::begin (void)
{
  return this->sequence_.begin ();
}

//
// begin
//
PICML_Sequence_Data_Value::const_iterator
PICML_Sequence_Data_Value::begin (void) const
{
  return this->sequence_.begin ();
}

//
// end
//
PICML_Sequence_Data_Value::iterator
PICML_Sequence_Data_Value::end (void)
{
  return this->sequence_.end ();
}

//
// end
//
PICML_Sequence_Data_Value::const_iterator
PICML_Sequence_Data_Value::end (void) const
{
  return this->sequence_.end ();
}

//
// size
//
size_t PICML_Sequence_Data_Value::size (void) const
{
  return this->sequence_.size ();
}

//
// _create
//
PICML_Data_Value * PICML_Sequence_Data_Value::
_create (const std::string & name, PICML_Data_Value * parent) const
{
  // Create a new type for the sequence, which has no parent.
  std::auto_ptr <PICML_Data_Value>
    type (this->type_->_create (this->type_->name ()));

  // Create the new sequence data type.
  PICML_Sequence_Data_Value * value =
    new PICML_Sequence_Data_Value (name, type.get (), parent);

  // Release the auto pointer.
  type.release ();

  return value;
}

//
// new_element
//
PICML_Data_Value * PICML_Sequence_Data_Value::new_element (void)
{
  std::ostringstream ostr;
  ostr << "[" << this->sequence_.size () << "]";

  // Create a new sequence element.
  PICML_Data_Value * value = this->type_->_create (ostr.str (), this);
  std::auto_ptr <PICML_Data_Value> auto_clean (value);

  // Insert the element into the end of the list.
  this->sequence_.push_back (value);
  auto_clean.release ();

  // We are not up-to-date.
  this->is_uptodate_ = false;

  return value;
}

//
// remove
//
void PICML_Sequence_Data_Value::remove (size_t index)
{
  if (index < this->sequence_.size ())
    this->remove_i (index);
}

//
// remove
//
void PICML_Sequence_Data_Value::remove (PICML_Data_Value * value)
{
  size_t index;

  if (this->get_index (value, index))
    this->remove_i (index);
}

//
// remove_i
//
void PICML_Sequence_Data_Value::remove_i (size_t index)
{
  // Delete the data value at the specified index.
  delete this->sequence_[index];

  // Remove the data value from the collection.
  this->sequence_.erase ((this->begin () + index));

  // Force ourselves to update.
  this->is_uptodate_ = false;
  PICML_Data_Value::value (PICML_Data_Value::value ());

  // Update names of all elements after the deleted items.
  container_type::iterator
    iter = this->sequence_.begin () + index,
    iter_end = this->sequence_.end ();

  std::ostringstream ostr;

  for (; iter != iter_end; iter ++)
  {
    // Set the name of the item.
    ostr << "[" << index ++ << "]";
    (*iter)->name_ = ostr.str ();

    // Reset the stream.
    ostr.str ("");
    ostr.clear ();
  }
}

//
// value
//
void PICML_Sequence_Data_Value::value (const std::string & v)
{
  // Reset our value first.
  this->reset ();

  PICML_Data_Value_Parser p (this);

  if (boost::spirit::parse (v.c_str (),
                            p.use_parser <PICML_Data_Value_Parser::sequence> (),
                            boost::spirit::space_p).full)
  {
    PICML_Data_Value::value (v);
  }
}

//
// value
//
const std::string &
PICML_Sequence_Data_Value::value (void)
{
  if (!this->is_uptodate_)
  {
    std::ostringstream ostr;

    container_type::const_iterator
      iter = this->sequence_.begin (),
      iter_end = this->sequence_.end ();

    if (iter != iter_end)
    {
      // Reconstruct the value of the aggregate.
      ostr << "[" << (*iter)->value ();

      for (++ iter; iter != iter_end; iter ++)
        ostr << "; " << (*iter)->value ();

      ostr << "]";
    }

    // Save the new value. This will cause all parent to
    // update themselves as well.
    PICML_Data_Value::value (ostr.str ());
  }

  return PICML_Data_Value::value ();
}

//
// reset
//
void PICML_Sequence_Data_Value::reset (void)
{
  PICML_Data_Value::reset ();

  container_type::iterator
    iter = this->sequence_.begin (),
    iter_end = this->sequence_.end ();

  for (; iter != iter_end; iter ++)
    delete (*iter);

  this->sequence_.resize (0);
}

//
// move_up
//
bool PICML_Sequence_Data_Value::move_up (PICML_Data_Value * value)
{
  size_t index;

  if (this->get_index (value, index))
  {
    if (index != 0)
    {
      size_t swap_index = index - 1;
      PICML_Data_Value * prev = this->sequence_[swap_index];

      // Swap the 'index' names of the items.
      std::swap (value->name_, prev->name_);

      // Swap the actual items.
      std::swap (this->sequence_[index], this->sequence_[swap_index]);
      return true;
    }
  }

  return false;
}

//
// move_down
//
bool PICML_Sequence_Data_Value::move_down (PICML_Data_Value * value)
{
  size_t index;

  if (this->get_index (value, index))
  {
    if (index != this->sequence_.size () - 1)
    {
      size_t swap_index = index + 1;
      PICML_Data_Value * next = this->sequence_[swap_index];

      // Swap the 'index' names of the items.
      std::swap (value->name_, next->name_);

      // Swap the actual items.
      std::swap (this->sequence_[index], this->sequence_[swap_index]);
      return true;
    }
  }

  return false;
}

//
// get_index
//
bool PICML_Sequence_Data_Value::
get_index (const PICML_Data_Value * value, size_t & index) const
{
  container_type::const_iterator
    iter = this->sequence_.begin (),
    iter_end = this->sequence_.end ();

  size_t i = 0;

  // Search the list in sequential order.
  for (; iter != iter_end; iter ++)
  {
    if (*iter == value)
    {
      // We found the value.
      index = i;
      return true;
    }

    // Move the the next index.
    ++ i;
  }

  return false;
}
