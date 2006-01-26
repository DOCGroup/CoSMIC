#ifndef _CUTS_UTIL_FUNCTOR_T_H_
#define _CUTS_UTIL_FUNCTOR_T_H_

#include "cuts/config.h"

template <typename ELEMENT>
struct Delete_Element
{
  void operator () (ELEMENT * element)
  {
    delete element;
  }
};

template <typename ELEMENT>
struct Delete_Elements
{
  void operator () (ELEMENT * element)
  {
    delete [] element;
  }
};

#endif  // !defined _CUTS_UTIL_FUNCTOR_T_H_
