// $Id$

//
// ACE_Hash <std:string>::operator ()
//
GME_INLINE
unsigned long ACE_Hash <std::string>::
operator () (const std::string & str) const
{
  return ACE::hash_pjw (str.c_str (), str.length ());
}

//
// ACE_Hash <std:wstring>::operator ()
//
GME_INLINE
unsigned long ACE_Hash <std::wstring>::
operator () (const std::wstring & str) const
{
  return ACE::hash_pjw (str.c_str (), str.length ());
}
