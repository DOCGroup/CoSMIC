// $Id$

//
// is_type::operator ()
//
template <typename T>
CUTS_INLINE
bool is_type <T>::operator () (const T & element)
{
  return (std::string)T::meta.name () ==
         (std::string)element.type ().name ();
}
