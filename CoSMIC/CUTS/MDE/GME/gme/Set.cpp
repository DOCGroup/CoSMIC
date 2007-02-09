// $Id$

#include "Set.h"

namespace GME
{
  //
  // Set
  //
  Set::Set (void)
  {

  }

  //
  // Set
  //
  Set::Set (IMgaSet * set)
    : FCO (set)
  {

  }

  //
  // Set
  //
  Set::Set (const Set & set)
    : FCO (set)
  {

  }

  //
  // ~Set
  //
  Set::~Set (void)
  {

  }

  //
  // clear
  //
  void Set::clear (void)
  {
    VERIFY_HRESULT (this->impl ()->RemoveAll ());
  }

  //
  // insert
  //
  void Set::insert (const FCO & fco)
  {
    VERIFY_HRESULT (this->impl ()->AddMember (fco));
  }

  //
  // remove
  //
  void Set::remove (const FCO & fco)
  {
    VERIFY_HRESULT (this->impl ()->RemoveMember (fco));
  }

  //
  // insert
  //
  bool Set::contains (const FCO & fco)
  {
    VARIANT_BOOL is_member;
    VERIFY_HRESULT (this->impl ()->get_IsMember (fco, &is_member));

    return is_member == VARIANT_TRUE ? true : false;
  }

  //
  // members
  //
  std::vector <FCO> Set::members (void) const
  {
    // Get all the members in the set.
    CComPtr <IMgaFCOs> fcos;
    VERIFY_HRESULT (this->impl ()->get_Members (&fcos));

    // Determine the number of members in the set.
    long count;
    VERIFY_HRESULT (fcos->get_Count (&count));
    std::vector <FCO> members (count);

    if (count > 0)
    {
      // Get the interface to all the members.
      CComPtr <IMgaFCO> * array = new CComPtr <IMgaFCO> [count];
      VERIFY_HRESULT (fcos->GetAll (count, &(*array)));

      // Store the members in a collection.
      for (long i = 0; i < count; i ++)
        members[i].attach (array[i]);

      // Release the temp storage.
      delete [] array;
    }

    return members;
  }

  //
  // impl
  //
  IMgaSet * Set::impl (void) const
  {
    if (this->set_.p != this->object_.p)
      VERIFY_HRESULT (this->object_.QueryInterface (&this->set_));

    return this->set_;
  }

  //
  // impl
  //
  const Set & Set::operator = (const Set & set)
  {
    if (this != &set)
      this->object_ = set.object_;

    return *this;
  }
}
