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
  size_t Set::members (GME::Collection_T <GME::FCO> & members) const
  {
    // Get all the members in the set.
    CComPtr <IMgaFCOs> fcos;
    VERIFY_HRESULT (this->impl ()->get_Members (&fcos));

    // Attach the implementation to the collection. We also need
    // to return the size of the set.
    members.attach (fcos);
    return members.size ();
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
  Set Set::_narrow (GME::Object & object)
  {
    CComPtr <IMgaSet> set;
    VERIFY_HRESULT (object.impl ()->QueryInterface (&set));

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
