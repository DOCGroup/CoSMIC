#ifndef __LEESA_CONCEPTS_H
#define __LEESA_CONCEPTS_H

#include "Kind_Traits.h"

#include <boost/mpl/count_if.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept_check.hpp>

namespace LEESA 
{
  template <class T, class Custom = Default>
	struct DomainKindConcept 
	{
		void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    typedef typename MetaKind<T, Custom>::type MK;
    typedef DomainKindConcept type;
    enum { value = boost::mpl::contains<LEESA::MetaTagList, MK>::value }; 
	};

	template <class L, class H, class Custom = Default>
	struct SameKindsConcept
	{
		BOOST_CLASS_REQUIRE(L, LEESA, DomainKindConcept);
		BOOST_CLASS_REQUIRE(H, LEESA, DomainKindConcept);
    
		void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}
    
    typedef SameKindsConcept type;
    enum { value = DomainKindConcept<L, Custom>::value &&
                   DomainKindConcept<H, Custom>::value && 
                   boost::is_same<L, H>::value &&  
                   boost::is_same<typename MetaKind<L, Custom>::type, 
                                  typename MetaKind<H, Custom>::type>::value }; 
	};

	template <class L, class H, class Custom = Default>
	struct ConvertibleDomainKindsConcept
	{
		BOOST_CLASS_REQUIRE(L, LEESA, DomainKindConcept);
		BOOST_CLASS_REQUIRE(H, LEESA, DomainKindConcept);
    
		void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}
    
    typedef ConvertibleDomainKindsConcept type;
    enum { value = DomainKindConcept<L, Custom>::value &&
                   DomainKindConcept<H, Custom>::value && 
                   boost::is_convertible<L, H>::value }; 
	};

	template <class ParentKind, class ChildKind, class Custom = Default>
	struct ParentChildConcept 
	{
		BOOST_CLASS_REQUIRE(ParentKind, LEESA, DomainKindConcept);
		BOOST_CLASS_REQUIRE(ChildKind, LEESA, DomainKindConcept);
		
    void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    typedef typename ChildrenKinds<ParentKind, Custom>::type ChildrenKinds;
    typedef ParentChildConcept type;
    enum { value = DomainKindConcept<ParentKind, Custom>::value &&
                   DomainKindConcept<ChildKind, Custom>::value && 
                   (boost::mpl::contains<ChildrenKinds, ChildKind>::value ||
                    // If the ChildrenKindss contains a base of ChildKind
                    boost::mpl::count_if <ChildrenKinds, 
                                          boost::is_base_of <boost::mpl::placeholders::_1, 
                                                             ChildKind> 
                                         >::value)    }; 
  };

	template <class ChildKind, class ParentKind, class Custom = Default>
	struct ChildToParentConcept 
	{
		BOOST_CLASS_REQUIRE(ParentKind, LEESA, DomainKindConcept);
		BOOST_CLASS_REQUIRE(ChildKind, LEESA, DomainKindConcept);
		
    void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    typedef typename ParentKinds<ChildKind, Custom>::type ParentKinds;
    typedef ChildToParentConcept type;
    enum { value = DomainKindConcept<ParentKind, Custom>::value &&
                   DomainKindConcept<ChildKind, Custom>::value && 
                   boost::mpl::contains<ParentKinds, ParentKind>::value }; 
	};

  template <class ParentKind, class DescendantKind, class Customizer>
  struct DescendantKindConcept
	{
    BOOST_CLASS_REQUIRE(ParentKind, LEESA, DomainKindConcept);
    BOOST_CLASS_REQUIRE(DescendantKind, LEESA, DomainKindConcept);
		
    void constraints()
    {
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
    }

    typedef DescendantKindConcept type;
    enum { value = 
            DomainKindConcept<ParentKind>::value &&
            DomainKindConcept<DescendantKind>::value && 
            IsDescendantKind<ParentKind, DescendantKind, Customizer>::value }; 
	};
/*
  template <bool Check, class StartVector, class Target>
  struct ReachableConcept
  {

    void constraints()
    {
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
	  }

    typedef ReachableConcept type;
    enum { value = Check? IsDescendant<StartVector, Target>::value : 1 }; 
  };
*/
} // namespace LEESA

#endif // __LEESA_CONCEPTS_H

