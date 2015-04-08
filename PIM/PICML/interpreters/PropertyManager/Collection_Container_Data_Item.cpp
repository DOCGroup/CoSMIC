#include "StdAfx.h"
#include "Collection_Container_Data_Item.h"
#include "Collection_Item.h"
#include "Data_Value_Item.h"

#include "game/mga/MetaFCO.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/utils/Point.h"

#include <algorithm>

//
// is_complex_type
//
static bool is_complex_type (const GAME::Mga::FCO_in fco)
{
  const std::string metaname = fco->meta ()->name ();
  return metaname == "Collection" || metaname == "Aggregate";
}

//
// get_complex_type
//
static bool
get_complex_type (const GAME::Mga::Model_in container, GAME::Mga::FCO& complex)
{
  std::vector <GAME::Mga::Reference> complex_types;
  if (0 == container->children ("ComplexTypeReference", complex_types))
    return false;

  // Get the complex type.
  complex = complex_types.front ()->refers_to ();
  return !complex.is_nil ();
}

//
// Collection_Container_Data_Item
//
Collection_Container_Data_Item::
Collection_Container_Data_Item (const GAME::Mga::Model_in item)
: Container_Data_Item (item),
  is_complex_type_ (false)
{
  GAME::Mga::FCO fco;

  if (::get_complex_type (this->item_, fco))
  {
    // Get the collection's type information.
    GAME::Mga::Reference coll = GAME::Mga::Reference::_narrow (fco);
    this->type_ = coll->refers_to ();

    // Cache the type's complexity.
    this->is_complex_type_ = ::is_complex_type (this->type_);
  }
}

//
// new_item
//
Collection_Item *
Collection_Container_Data_Item::new_item (void)
{
  // The user wants to insert a new item into a sequence. We
  // need to find the parent of this item. This will be the
  // item that's one indentation less than the current one.
  GAME::Mga::FCO value_base;

  if (this->is_complex_type_)
  {
    using GAME::Mga::Model;
    using GAME::Mga::Reference;

    // We need to create a DataValueContainer element.
    Model container = GAME::Mga::Model_Impl::_create (this->item_, "DataValueContainer");
    Reference ctr = GAME::Mga::Reference_Impl::_create (container, "ComplexTypeReference");
    ctr->refers_to (this->type_);

    // Save the container.
    value_base = container;
  }
  else
  {
    // We are create space for a predefined type, or an enumeration.
    GAME::Mga::Reference data_value = GAME::Mga::Reference_Impl::_create (this->item_, "DataValue");
    data_value->refers_to (this->type_);

    value_base = data_value;
  }

  return this->new_item (value_base);
}

//
// new_item
//
Collection_Item *
Collection_Container_Data_Item::new_item (GAME::Mga::FCO item)
{
  // Increase the y-value for the last location to represent the
  // new created item.
  GAME::Mga::Point location (100, 0);

  if (!this->items_.empty ())
    GAME::Mga::position ("DataValueAspect",
                           this->items_.back ()->get_item (),
                           location);

  // Move down to the next location.
  location.shift (0, 100);

  GAME::Mga::position ("DataValueAspect",
                         location,
                         item);

  // Add a new element to the collection to the DataValueContainer.
  std::auto_ptr <Data_Value_Item_Base> data_item;

  if (this->is_complex_type_)
  {
    GAME::Mga::Model container = GAME::Mga::Model::_narrow (item);

    if (this->type_->meta ()->name () == "Collection")
      data_item.reset (new Collection_Container_Data_Item (container));
    else
      data_item.reset (new Container_Data_Item (container));
  }
  else
  {
    data_item.reset (new Data_Value_Item (item));
  }

  // Create the new collection item wrapper for this item.
  std::auto_ptr <Collection_Item> ci (
    new Collection_Item (this,
                         data_item.release (),
                         this->items_.size ()));

  // Insert the item into the parent.
  this->items_.push_back (ci.get ());
  return ci.release ();
}

/**
 * @struct update_index_t
 *
 * Helper functor that will update the index of a collection item.
 */
struct update_index_t
{
  update_index_t (size_t index)
    : index_ (index)
  {

  }

  void operator () (Collection_Item * item)
  {
    item->set_index (this->index_ ++);
  }

private:
  size_t index_;
};

//
// delete_item
//
bool Collection_Container_Data_Item::delete_item (Collection_Item * item)
{
  // Make sure we have the correct item to delete.
  const size_t index = item->get_index ();

  if (this->items_[index] != item)
    return false;

  // Delete the element from the model.
  item->get_item ()->destroy ();

  // Remove the element from the collection.
  this->items_.erase (this->items_.begin () + index);

  // Update the index of the remaining items.
  std::for_each (this->items_.begin () + index,
                 this->items_.end (),
                 update_index_t (index));

  // Finally, delete the collection item.
  delete item;

  return true;
}

//
// get_size
//
size_t Collection_Container_Data_Item::get_size (void) const
{
  return this->items_.size ();
}

//
// move_up
//
bool Collection_Container_Data_Item::move_up (Collection_Item * item)
{
  const size_t index = item->get_index ();

  if (index == 0)
    return false;

  std::swap (this->items_[index], this->items_[index - 1]);
  Collection_Item::swap (this->items_[index], this->items_[index - 1]);

  return true;
}

//
// move_down
//
bool Collection_Container_Data_Item::move_down (Collection_Item * item)
{
  const size_t index = item->get_index ();

  if (index == this->items_.size () - 1)
    return false;

  std::swap (this->items_[index], this->items_[index + 1]);
  Collection_Item::swap (this->items_[index], this->items_[index + 1]);

  return true;
}
