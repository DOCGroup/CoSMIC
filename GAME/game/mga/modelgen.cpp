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
template <typename P, typename COLL, typename META>
size_t get_children <Mga_t>::get_children_impl <true, P, COLL, META>::
operator () (P parent, const META & metaname, COLL & coll)
{
  return parent->folders (metaname, coll);
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
  return T::impl_type::_create (parent);
}

//
// create_element (Folder)
//
template <typename P, typename META>
GAME::Mga::Folder create_element <Mga_t, GAME::Mga::Folder>::
operator () (P parent, const META & metaname)
{
  return GAME::Mga::Folder::impl_type::_create (parent, metaname);
}

//
// create_element (Atom)
//
template <typename P, typename META>
GAME::Mga::Atom create_element <Mga_t, GAME::Mga::Atom>::
operator () (P parent, const META & metaname)
{
  return GAME::Mga::Atom::impl_type::_create (parent, metaname);
}

//
// create_element (Model)
//
template <typename P, typename META>
GAME::Mga::Model create_element <Mga_t, GAME::Mga::Model>::
operator () (P parent, const META & metaname)
{
  return GAME::Mga::Model::impl_type::_create (parent, metaname);
}

//
// create_element (Set)
//
template <typename P, typename META>
GAME::Mga::Set create_element <Mga_t, GAME::Mga::Set>::
operator () (P parent, const META & metaname)
{
  return GAME::Mga::Set::impl_type::_create (parent, metaname);
}

//
// create_element (Reference)
//
template <typename P, typename META>
GAME::Mga::Reference create_element <Mga_t, GAME::Mga::Reference>::
operator () (P parent, const META & metaname)
{
  return GAME::Mga::Reference::impl_type::_create (parent, metaname);
}

}
