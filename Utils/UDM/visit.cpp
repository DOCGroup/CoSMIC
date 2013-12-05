// $Id$

#include "UdmBase.h"
#include <algorithm>
#include "boost/bind.hpp"

namespace Udm
{
template <typename T, typename V>
void visit_all (T coll, V & v) 
{
  std::for_each (coll.begin (), 
                 coll.end (),
                 boost::bind (&T::value_type::Accept, _1, boost::ref (v)));
}

template <typename T, typename P, typename V>
void visit_all (const P & parent, V & v) 
{
  typedef vector <T> vector_t;
  vector_t children = Udm::ChildrenAttr <T> (parent.__impl (), Udm::NULLCHILDROLE);

  visit_all (children, v);
}
}
