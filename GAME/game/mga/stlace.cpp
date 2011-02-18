// $Id$

#include "stdafx.h"
#include "stlace.h"

#if defined (ACE_LACKS_STL_STRING_FUNCTORS)
#include "ace/ACE.h"
#include "ace/Functor_T.h"

//
// ACE_Hash <std:string>::operator ()
//
unsigned long ACE_Hash <std::string>::
operator () (const std::string & str) const
{
  return ACE::hash_pjw (str.c_str (), str.length ());
}

//
// ACE_Hash <std:wstring>::operator ()
//
unsigned long ACE_Hash <std::wstring>::
operator () (const std::wstring & str) const
{
  return ACE::hash_pjw (str.c_str (), str.length ());
}
#endif
