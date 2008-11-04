#ifndef __UDM_OBJECT_CONCEPT_H
#define __UDM_OBJECT_CONCEPT_H
/*
#include <boost/mpl/vector.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept/assert.hpp>

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

template <class ParentKind, class ChildKind>
struct ParentChildConcept 
{
  BOOST_CLASS_REQUIRE(ParentKind, Udm, UdmKindConcept);
  BOOST_CLASS_REQUIRE(ChildKind, Udm, UdmKindConcept);
	
  void constraints()
	{
    typedef typename ParentKind::ChildrenKinds ChildrenKinds;
		BOOST_MPL_ASSERT((boost::mpl::contains<ChildrenKinds, ChildKind > ));
	}
};


} // end namespace Udm
*/
#endif // __UDM_OBJECT_CONCEPT_H
