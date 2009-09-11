#ifndef __LEESA_CONCEPTS_H
#define __LEESA_CONCEPTS_H

#include <boost/concept_check.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/type_traits.hpp>

namespace LEESA 
{
  typedef boost::mpl::vector<>  EmptyMPLVectorB;
  typedef boost::mpl::vector0<> EmptyMPLVector;

  template <class Where, class T>
  struct ChildrenKinds;

  template <class Where, class T>
  struct DescendantKinds;

  template <class T>
	struct UdmKindConcept 
	{
		void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    typedef typename T::MetaKind MetaKind;
    typedef UdmKindConcept type;
    enum { value = boost::mpl::contains<Udm::MetaTagList, MetaKind>::value }; 
	};

	template <class L, class H>
	struct SameUdmKindsConcept
	{
		BOOST_CLASS_REQUIRE(L, LEESA, UdmKindConcept);
		BOOST_CLASS_REQUIRE(H, LEESA, UdmKindConcept);
    
		void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}
    
    typedef SameUdmKindsConcept type;
    enum { value = UdmKindConcept<L>::value &&
                   UdmKindConcept<H>::value && 
                   boost::is_same<L, H>::value &&  
                   boost::is_same<typename L::MetaKind, 
                                  typename H::MetaKind>::value }; 
	};

	template <class L, class H>
	struct ConvertibleUdmKindsConcept
	{
		BOOST_CLASS_REQUIRE(L, LEESA, UdmKindConcept);
		BOOST_CLASS_REQUIRE(H, LEESA, UdmKindConcept);
    
		void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}
    
    typedef ConvertibleUdmKindsConcept type;
    enum { value = UdmKindConcept<L>::value &&
                   UdmKindConcept<H>::value && 
                   boost::is_convertible<L, H>::value }; 
	};

	template <class ParentKind, class ChildKind>
	struct ParentChildConcept 
	{
		BOOST_CLASS_REQUIRE(ParentKind, LEESA, UdmKindConcept);
		BOOST_CLASS_REQUIRE(ChildKind, LEESA, UdmKindConcept);
		
    void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    // Finds out if the Vector contains a base of Kind.
    template <class Vector, class Kind>
    struct contains_base
    {
      typedef typename boost::mpl::front<Vector>::type Head;
      typedef typename boost::mpl::pop_front<Vector>::type Tail;
      enum { value = boost::is_base_of<Head, Kind>::value ||
                     contains_base<Tail, Kind>::value };
    };
    typedef boost::mpl::vector<> EmptyMPLVectorB;
    typedef boost::mpl::vector0<> EmptyMPLVector;
    template <class Kind>
    struct contains_base <EmptyMPLVector, Kind>
    {
      enum { value = 0 };
    };
    template <class Kind>
    struct contains_base <EmptyMPLVectorB, Kind>
    {
      enum { value = 0 };
    };
    
 	  typedef typename ParentKind::ChildrenKinds ChildrenKinds;
    typedef ParentChildConcept type;
    enum { value = UdmKindConcept<ParentKind>::value &&
                   UdmKindConcept<ChildKind>::value && 
                   (boost::mpl::contains<ChildrenKinds, ChildKind>::value ||
                    // If the ChildrenKindss contains a base of ChildKind
                    contains_base<ChildrenKinds, ChildKind>::value) }; 
	};

	template <class ChildKind, class ParentKind>
	struct ChildToParentConcept 
	{
		BOOST_CLASS_REQUIRE(ParentKind, LEESA, UdmKindConcept);
		BOOST_CLASS_REQUIRE(ChildKind, LEESA, UdmKindConcept);
		
    void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    typedef typename ChildKind::ParentKinds ParentKinds;
    typedef ChildToParentConcept type;
    enum { value = UdmKindConcept<ParentKind>::value &&
                   UdmKindConcept<ChildKind>::value && 
                   boost::mpl::contains<ParentKinds, ParentKind>::value }; 
	};

  template <class ParentKind, class DescendantKind, class Customizer>
	struct DescendantKindConcept
	{
		BOOST_CLASS_REQUIRE(ParentKind, LEESA, UdmKindConcept);
		BOOST_CLASS_REQUIRE(DescendantKind, LEESA, UdmKindConcept);
		
    void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    typedef typename LEESA::DescendantKinds<Customizer, ParentKind>::type DescendantKinds;
    typedef DescendantKindConcept type;
    enum { value = UdmKindConcept<ParentKind>::value &&
                   UdmKindConcept<DescendantKind>::value && 
                   boost::mpl::contains<DescendantKinds, DescendantKind>::value }; 
	};

  template <bool Check, class StartVector, class Target>
	struct ReachableConcept
	{
    template <class StartVector, class Target>
    struct IsDescendant
    {
      typedef IsDescendant type;
      typedef typename boost::mpl::front<StartVector>::type Head;
      typedef typename boost::mpl::pop_front<StartVector>::type Tail;
      enum { value = DescendantKindConcept<Head, Target>::value ||
                     IsDescendant<Tail, Target>::value };
    };
    template <class Target>
    struct IsDescendant<EmptyMPLVector, Target> 
    { 
      enum { value = 0 };
    };
    template <class Target>
    struct IsDescendant<EmptyMPLVectorB, Target> 
    { 
      enum { value = 0 };
    };

    void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    typedef ReachableConcept type;
    enum { value = Check? IsDescendant<StartVector, Target>::value : 1 }; 
	};

} // namespace LEESA

#endif // __LEESA_CONCEPTS_H

