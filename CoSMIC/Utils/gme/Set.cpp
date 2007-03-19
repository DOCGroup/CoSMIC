// $Id$

#include "Set.h"
#include "Model.h"

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
  size_t Set::members (std::vector <FCO> & elements) const
  {
    // Get all the members in the set.
    CComPtr <IMgaFCOs> fcos;
    VERIFY_HRESULT (this->impl ()->get_Members (&fcos));

    // Determine the number of members in the set.
    long count;
    VERIFY_HRESULT (fcos->get_Count (&count));
    elements.resize (count);

    if (count > 0)
    {
      // Get the interface to all the members.
      CComPtr <IMgaFCO> * array = new CComPtr <IMgaFCO> [count];
      VERIFY_HRESULT (fcos->GetAll (count, &(*array)));

      // Store the members in a collection.
      for (long i = 0; i < count; i ++)
        elements[i].attach (array[i]);

      // Release the temp storage.
      delete [] array;
    }

    return count;
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

  //
  // _narrow
  //
  Set Set::_narrow (FCO & fco)
  {
    CComPtr <IMgaSet> set;
    VERIFY_HRESULT (fco.impl ()->QueryInterface (&set));

    return set.p;
  }

  //
  // _create
  //
  Set Set::_create (const std::string & role,
                    Model & parent)
  {
    CComPtr <IMgaFCO> child;
    MetaRole metarole = parent.meta ().role (role);

    VERIFY_HRESULT (
      parent.impl ()->CreateChildObject (metarole, &child));

    return Set::_narrow (FCO (child));
  }

  //
  // attach
  //
  void Set::attach (IMgaSet * set)
  {
    FCO::attach (set);
  }
}
