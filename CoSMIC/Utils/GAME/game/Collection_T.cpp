// $Id$

#include "Exception.h"

namespace GME
{
//
// get_collection
//
template <typename ITER, typename T>
size_t get_children (ITER iter, std::vector <T> & coll)
{
  // Resize the collection.
  long count;
  iter->get_Count (&count);
  coll.resize (count);

  if (count == 0)
    return 0;

  // Get the interface to all the members.
  typedef typename collection_traits <
    typename item_traits <T>::collection_type>::
    interface_type interface_type;

  ATL::CComPtr <interface_type> * arr =
    new ATL::CComPtr <interface_type> [count];

  VERIFY_HRESULT (iter->GetAll (count, &(*arr)));

  // Store the members in a collection.
  typename T::interface_type * temp = 0;

  for (long i = 0; i < count; i ++)
  {
    arr[i].QueryInterface (&temp);
    coll[i].attach (temp);

    temp = 0;
  }

  // Release the temp storage.
  delete [] arr;
  return coll.size ();
}

}
