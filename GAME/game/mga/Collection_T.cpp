// $Id$

#include "Exception.h"

namespace GAME
{
namespace Mga
{

template <typename T>
struct collection_traits;

template < >
struct collection_traits <IMgaObjects *>
{
  typedef IMgaObject interface_type;
};

template < >
struct collection_traits <IMgaFCOs *>
{
  typedef IMgaFCO interface_type;
};

template < >
struct collection_traits <IMgaFolders *>
{
  typedef IMgaFolder interface_type;
};

template < >
struct collection_traits <IMgaAttributes *>
{
  typedef IMgaAttribute interface_type;
};

template < >
struct collection_traits <IMgaComponents *>
{
  typedef IMgaComponent interface_type;
};

template < >
struct collection_traits <IMgaConnPoints *>
{
  typedef IMgaConnPoint interface_type;
};

template < >
struct collection_traits <IMgaRegNodes *>
{
  typedef IMgaRegNode interface_type;
};

template < >
struct collection_traits <IMgaMetaFolders *>
{
  typedef IMgaMetaFolder interface_type;
};

template < >
struct collection_traits <IMgaMetaFCOs *>
{
  typedef IMgaMetaFCO interface_type;
};

template < >
struct collection_traits <IMgaMetaParts *>
{
  typedef IMgaMetaPart interface_type;
};

template < >
struct collection_traits <IMgaMetaRoles *>
{
  typedef IMgaMetaRole interface_type;
};

template < >
struct collection_traits <IMgaMetaAspects *>
{
  typedef IMgaMetaAspect interface_type;
};

template < >
struct collection_traits <IMgaMetaAttributes *>
{
  typedef IMgaMetaAttribute interface_type;
};

template < >
struct collection_traits <IMgaConstraints *>
{
  typedef IMgaConstraint interface_type;
};

template < >
struct collection_traits <IMgaMetaConnJoints *>
{
  typedef IMgaMetaConnJoint interface_type;
};

//
// get_collection
//
template <typename ITER, typename T>
size_t iter_to_collection (ITER iter, std::vector <T> & coll)
{
  // Resize the collection.
  long count;
  iter->get_Count (&count);

  // Make space for the elements, but set the collection's size
  // to zero. We will grow the collection as we insert elements.
  coll.reserve (count);
  coll.resize (0);

  if (count == 0)
    return 0;

  // Get the interface to all the members.
  typedef typename collection_traits <ITER>::interface_type interface_type;
  ATL::CComPtr <interface_type> * arr = new ATL::CComPtr <interface_type> [count];

  VERIFY_HRESULT (iter->GetAll (count, &(*arr)));

  // Store the members in a collection.
  ATL::CComPtr <typename T::interface_type> temp;

  for (long i = 0; i < count; i ++)
  {
    if (FAILED (arr[i].QueryInterface (&temp)))
      continue;

    coll.push_back (temp.p);
    temp.Release ();
  }

  // Release the temp storage.
  delete [] arr;
  return coll.size ();
}

}
}
