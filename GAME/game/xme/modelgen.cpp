// $Id$

namespace GAME
{

//
// iter_to_collection
//
template <typename P, typename T, typename META>
size_t get_children <Xme_t>
::operator () (P parent, const META & metaname, T & element)
{
  return parent.children (metaname, element);
}

//
// create_element
//
template <typename T>
template <typename P, typename META>
T create_element <Xme_t, T>::operator () (P parent, const META & metaname)
{
  return T::_create (parent, metaname);
}

}
