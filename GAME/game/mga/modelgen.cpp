// $Id$

namespace GAME
{

//
// get_children
//
template <typename P, typename T, typename META>
size_t get_children <Mga_t>
::operator () (P parent, const META & metaname, T & element)
{
  return parent->children (metaname, element);
}

//
// create_element
//
template <typename T>
template <typename P, typename META>
T create_element <Mga_t, T>::operator () (P parent, const META & metaname)
{
  return T::impl_type::_create (parent, metaname);
}

}
