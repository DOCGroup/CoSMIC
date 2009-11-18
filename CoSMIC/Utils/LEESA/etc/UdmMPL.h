/*
Copyright (c) Vanderbilt University, 2008
ALL RIGHTS RESERVED
Vanderbilt University disclaims all warranties with regard to this
software, including all implied warranties of merchantability
and fitness.  In no event shall Vanderbilt University be liable for
any special, indirect or consequential damages or any damages
whatsoever resulting from loss of use, data or profits, whether
in an action of contract, negligence or other tortious action,
arising out of or in connection with the use or performance of
this software.
*/

#ifndef MOBIES_UDMMPL_H
#define MOBIES_UDMMPL_H

#include <boost/concept_check.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/type_traits.hpp>
#include <boost/version.hpp>

namespace Udm
{
  struct MetaTagBase {};
  struct AtomMetaTag       : MetaTagBase {};
	struct ConnectionMetaTag : MetaTagBase {};
	struct FCOMetaTag        : MetaTagBase {};
	struct FolderMetaTag     : MetaTagBase {};
	struct ModelMetaTag      : MetaTagBase {};
	struct ReferenceMetaTag  : MetaTagBase {};
	struct SetMetaTag        : MetaTagBase {};
	struct UnknownMetaTag    : MetaTagBase {};

	typedef boost::mpl::vector<AtomMetaTag, ConnectionMetaTag, FCOMetaTag, FolderMetaTag, ModelMetaTag, ReferenceMetaTag, SetMetaTag, UnknownMetaTag> MetaTagList;

	// Concepts

	// The typelist contains an element that is a the same type as
	// ReturnType or is derived from ReturnType
	template <class ReturnType, class TList>
	struct InTListConcept
	{
		void constraints()
		{
#if BOOST_VERSION >= 103500
			typedef typename
			boost::mpl::find_if<
				TList,
				boost::mpl::or_<
					boost::is_base_of<
						ReturnType,
						boost::mpl::placeholders::_1
					>,
          boost::is_base_of<
						boost::mpl::placeholders::_1,
            ReturnType
					>
				>
			>::type iter;
#else
			typedef typename
			boost::mpl::find_if<
				TList,
				boost::mpl::or_<
					boost::is_same<
						ReturnType,
						boost::mpl::placeholders::_1
					>,
					boost::is_base_of<
						ReturnType,
						boost::mpl::placeholders::_1
					>,
          boost::is_base_of<
						boost::mpl::placeholders::_1,
            ReturnType
					>
				>
			>::type iter;
#endif
			BOOST_MPL_ASSERT_NOT(( boost::is_same<iter, typename boost::mpl::end<TList>::type> ));
		}
	};

	// The typelist contains elements of type
	// boost::mpl::pair<ReturnType, RoleType>.
	// We want to find if the pair formed by the first two parameters can
	// be found in the typelist this way: the role type must be the same
	// and the return type template parameter is a public base of the
	// return type from the typelist pair, or an alias.
	template <class ReturnType, class RoleType, class TList>
	struct WithRoleInTListConcept
	{
		void constraints()
		{
#if BOOST_VERSION >= 103500
			typedef typename
			boost::mpl::find_if<
				TList,
				boost::mpl::and_<
					boost::is_same<
						RoleType,
						boost::mpl::second< boost::mpl::placeholders::_1 >
					>,
					boost::is_base_of<
						ReturnType,
						boost::mpl::first< boost::mpl::placeholders::_1 >
					>
				>
			>::type iter;
#else
			typedef typename
			boost::mpl::find_if<
				TList,
				boost::mpl::and_<
					boost::is_same<
						RoleType,
						boost::mpl::second< boost::mpl::placeholders::_1 >
					>,
					boost::mpl::or_<
						boost::is_same<
							ReturnType,
							boost::mpl::first< boost::mpl::placeholders::_1 >
						>,
						boost::is_base_of<
							ReturnType,
							boost::mpl::first< boost::mpl::placeholders::_1 >
						>
					>
				>
			>::type iter;
#endif
			BOOST_MPL_ASSERT_NOT(( boost::is_same<iter, typename boost::mpl::end<TList>::type> ));
		}
	};


	// The typelist contains elements of type
	// boost::mpl::pair< ReturnType, pair<AssocClassType, RoleType> >.
	// We want to find if the triplet formed by the first three parameters
	// can be found by a typelist item in this way:
	// - the role type must be the same
	// - the return type template parameter is a public base of or it is an
	//   alias of the return type stored in the item
	// - the association class type template parameter is derived from or
	//   it is an alias of the association class type stored in the item
	template <class ReturnType, class AClassType, class RoleType, class TList>
	struct WithAClassAndRoleInTListConcept
	{
		void constraints()
		{
#if BOOST_VERSION >= 103500
			typedef typename
			boost::mpl::find_if<
				TList,
				boost::mpl::and_<
					boost::is_same<
						RoleType,
						boost::mpl::second< boost::mpl::second< boost::mpl::placeholders::_1 > >
					>,
					boost::mpl::and_<
						boost::is_base_of<
							AClassType,
							boost::mpl::first< boost::mpl::second< boost::mpl::_1 > >
						>,
						boost::is_base_of<
							ReturnType,
							boost::mpl::first< boost::mpl::_1 >
						>
					>
				>
			>::type iter;
#else
			typedef typename
			boost::mpl::find_if<
				TList,
				boost::mpl::and_<
					boost::is_same<
						RoleType,
						boost::mpl::second< boost::mpl::second< boost::mpl::placeholders::_1 > >
					>,
					boost::mpl::and_<
						boost::mpl::or_<
							boost::is_same<
								AClassType,
								boost::mpl::first< boost::mpl::second< boost::mpl::_1 > >
							>,
							boost::is_base_of<
								AClassType,
								boost::mpl::first< boost::mpl::second< boost::mpl::_1 > >
							>
						>,
						boost::mpl::or_<
							boost::is_same<
								ReturnType,
								boost::mpl::first< boost::mpl::_1 >
							>,
							boost::is_base_of<
								ReturnType,
								boost::mpl::first< boost::mpl::_1 >
							>
						>
					>
				>
			>::type iter;
#endif
			BOOST_MPL_ASSERT_NOT(( boost::is_same<iter, typename boost::mpl::end<TList>::type> ));
		}
	};

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
		BOOST_CLASS_REQUIRE(L, Udm, UdmKindConcept);
		BOOST_CLASS_REQUIRE(H, Udm, UdmKindConcept);
    
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
		BOOST_CLASS_REQUIRE(L, Udm, UdmKindConcept);
		BOOST_CLASS_REQUIRE(H, Udm, UdmKindConcept);
    
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
		BOOST_CLASS_REQUIRE(ParentKind, Udm, UdmKindConcept);
		BOOST_CLASS_REQUIRE(ChildKind, Udm, UdmKindConcept);
		
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
		BOOST_CLASS_REQUIRE(ParentKind, Udm, UdmKindConcept);
		BOOST_CLASS_REQUIRE(ChildKind, Udm, UdmKindConcept);
		
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

  template <class ParentKind, class DescendantKind>
	struct DescendantKindConcept
	{
		BOOST_CLASS_REQUIRE(ParentKind, Udm, UdmKindConcept);
		BOOST_CLASS_REQUIRE(DescendantKind, Udm, UdmKindConcept);
		
    void constraints()
		{
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
		}

    typedef typename ParentKind::DescendantKinds DescendantKinds;
    typedef DescendantKindConcept type;
    enum { value = UdmKindConcept<ParentKind>::value &&
                   UdmKindConcept<DescendantKind>::value && 
                   boost::mpl::contains<DescendantKinds, DescendantKind>::value }; 
	};

}

#endif //MOBIES_UDMMPL_H
