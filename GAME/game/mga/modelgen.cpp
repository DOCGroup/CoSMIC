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
  typedef typename T::value_type value_type;
  typedef typename value_type::impl_type::type_tag type_tag;

  get_children_impl <GAME::Mga::assertion::element_is_folder <type_tag>::result_type, P, T, META> impl;
  return impl (parent, metaname, element);
}

//
// get_children_impl
//
template <typename P, typename T, typename META>
size_t get_children <Mga_t>::get_children_impl <true, P, T, META>::
operator () (P parent, const META & metaname, T & element)
{
  return parent->folders (metaname, element);
}

//
// get_children_impl
//
template <typename P, typename T, typename META>
size_t get_children <Mga_t>::get_children_impl <false, P, T, META>::
operator () (P parent, const META & metaname, T & element)
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
