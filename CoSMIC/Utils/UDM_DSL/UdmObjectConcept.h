#ifndef __UDM_OBJECT_CONCEPT_H
#define __UDM_OBJECT_CONCEPT_H

#include <boost/mpl/vector.hpp>
#include <boost/mpl/contains.hpp>

//#define ENABLE_BOOST_MPL
#define ENABLE_LOKI

#ifdef ENABLE_LOKI

struct ModelMetaTag {};
struct AtomMetaTag {};
struct ConnectionMetaTag {};
struct ReferenceMetaTag {};
struct SetMetaTag {};

typedef LOKI_TYPELIST_5 (ModelMetaTag, AtomMetaTag, 
ConnectionMetaTag, ReferenceMetaTag, SetMetaTag) MetaTagList;

template <class T>
struct UdmObjectConcept {
	typedef typename T::MetaKind meta_kind;
	void constraints()
	{
		enum { val = Loki::TL::IndexOf<MetaTagList, meta_kind>::value < 0 ? -1 : 1 };
		char temp[val];
		boost::ignore_unused_variable_warning(temp);
	}
};

template <class T, class U>
struct SameUdmKindsConcept
{
	void constraints()
	{
		enum { val = Loki::IsSameType<T, U>::value ? 
			Loki::IsSameType<T::MetaKind, U::MetaKind>::value ? 1 : -1 : -1 };
		char temp[val];
		boost::ignore_unused_variable_warning(temp);
	}
};

#endif // ENABLE_LOKI

#ifdef ENABLE_BOOST_MPL
	//#include <boost/mpl/vector.hpp>
	//#include <boost/mpl/contains.hpp>
    //#include <boost/mpl/assert.hpp>

struct ModelMetaTag {};
struct AtomMetaTag {};
struct ConnectionMetaTag {};
struct ReferenceMetaTag {};
struct SetMetaTag {};

typedef boost::mpl::vector <ModelMetaTag, AtomMetaTag, 
ConnectionMetaTag, ReferenceMetaTag, SetMetaTag> MetaTagList;

template <class T>
struct UdmObjectConcept {
	typedef typename T::MetaKind meta_kind;
	void constraints()
	{
		BOOST_MPL_ASSERT((boost::mpl::contains<MetaTagList, meta_kind> ));
	}
};

template <class T, class U>
struct SameUdmKindsConcept 
{
	void constraints()
	{
		BOOST_MPL_ASSERT((boost::is_same<T, U>));
		BOOST_MPL_ASSERT((boost::is_same<T::MetaTag, U::MetaTag>));
	}
};

#endif // ENABLE_BOOST_MPL

#endif // __UDM_OBJECT_CONCEPT_H
