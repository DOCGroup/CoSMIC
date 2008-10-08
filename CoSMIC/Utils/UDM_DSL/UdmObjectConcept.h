#ifndef __UDM_OBJECT_CONCEPT_H
#define __UDM_OBJECT_CONCEPT_H

#include <boost/mpl/vector.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/type_traits.hpp>

namespace Udm {

template <class T>
struct UdmKindConcept 
{
   void constraints()
   {
     typedef typename T::MetaKind MetaKind;
     BOOST_MPL_ASSERT((boost::mpl::contains<Udm::MetaTagList, MetaKind> ));
   }
};

template <class L, class H>
struct SameUdmKindsConcept
{
  BOOST_CLASS_REQUIRE(L, Udm, UdmKindConcept);
  BOOST_CLASS_REQUIRE(H, Udm, UdmKindConcept);

  void constraints()
  {
    BOOST_MPL_ASSERT((boost::is_same<L, H>));
    BOOST_MPL_ASSERT((boost::is_same<L::MetaKind, H::MetaKind> ));
  }
};

} // namespace Udm

#endif // __UDM_OBJECT_CONCEPT_H
