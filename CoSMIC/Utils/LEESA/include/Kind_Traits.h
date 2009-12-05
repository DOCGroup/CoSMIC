#ifndef __KIND_TRAITS_H
#define __KIND_TRAITS_H

#ifndef DOMAIN_NAMESPACE
#error "Please #define DOMAIN_NAMESPACE"
#endif

#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>


namespace DOMAIN_NAMESPACE 
{
  template <class T>
  struct SchemaTraits;
}

namespace LEESA {

  template <class Kind, class Custom>
  struct KindTraits;

  template <class Parent, class Descendant, class Custom>
  struct IsDescendantKind;

#ifdef LEESA_FOR_UDM

  typedef Udm::MetaTagList MetaTagList; 
  typedef std::set<Udm::Object> ObjectSet;

  struct Default
  {
    static ObjectSet GetChildObjects(Udm::Object o)
    {
      return o.GetChildObjects();
    };
  };

  template <class Kind, class Custom = Default>
  struct KindTraits 
  {
    typedef typename std::vector<Kind> Container;
    typedef typename Kind::ChildrenKinds ChildrenKinds;
    typedef typename Kind::ParentKinds ParentKinds;
    typedef typename Kind::MetaKind MetaKind;
  };

#else // LEESA_FOR_UDM

  struct AtomMetaTag {};
  struct ModelMetaTag {};
  struct ReferenceMetaTag {};

  typedef boost::mpl::vector < AtomMetaTag, ModelMetaTag, ReferenceMetaTag > MetaTagList;
	
  struct Default {};

  template <class Kind, class Custom = Default>
  struct KindTraits 
  {
    typedef typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Container Container;
    typedef typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::ChildrenKinds ChildrenKinds;
    typedef typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::ParentKinds ParentKinds;
    typedef typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::MetaKind MetaKind;
  };

#endif // LEESA_FOR_UDM



#ifdef DOMAIN_HAS_DESCENDANT_PAIRS

template <class Parent, class Descendant>
struct IsDescendantKind <Parent, Descendant, Default>
{
  typedef IsDescendantKind type;
  enum { value = DOMAIN_NAMESPACE::IsDescendant<Parent, Descendant>::value };
};

#else // DOMAIN_HAS_DESCENDANT_PAIRS

// The following metaprogram is suitable for elements with SELF as well as 
// MUTUAL-RECURSION. This meta-program could be used as a substitute for the 
// gen-pairs.pl program. However, because of heavy metaprogramming, it is slow
// and for domains with mutual recursion, the "visited" vector may grow too 
// big to handle for boost and/or the compiler. It is therefore advisible to
// #define a macro called DOMAIN_HAS_MUTUAL_RECURSION before including
// LEESA.h if you know that the domain has mutual recursion. By default it is 
// disabled and may result into very long compilation errors saying that 'value'
// is not defined ...

template <class Parent, class Target, class Custom, class VisitedVector>
struct RecursiveIsDescendantKind;

template <class Parent, class Descendant, class Custom>
struct IsDescendantKind
{
  typedef IsDescendantKind type;
  typedef boost::mpl::vector1<Parent> Visited;
  enum { value = RecursiveIsDescendantKind <Parent, Descendant, Custom, Visited>::value };
};

template <class StartVector, unsigned int SIZE, class Target, class Custom, class VisitedVector>
struct IsDescendantVector;

template <class Parent, class Descendant, class Custom, class VisitedVector>
struct RecursiveIsDescendantKind
{
  typedef RecursiveIsDescendantKind type;
  typedef typename KindTraits<Parent, Custom>::ChildrenKinds Children;
  typedef typename 
    boost::mpl::remove_if <Children, 
                           boost::mpl::contains<VisitedVector, 
                                                boost::mpl::placeholders::_1> >::type SkippedVisitedVector;

  enum { value = 
          boost::mpl::or_<boost::mpl::contains <Children, Descendant>,
                          IsDescendantVector<SkippedVisitedVector, 
                                             boost::mpl::size<SkippedVisitedVector>::value, 
                                             Descendant, 
                                             Custom, 
                                             VisitedVector> >::value };
};

template <class StartVector, class Target, class Custom, class VisitedVector>
struct IsDescendantVector<StartVector, 0, Target, Custom, VisitedVector> 
{
  typedef IsDescendantVector type;
  enum { value = 0 };
};

template <class StartVector, unsigned int SIZE, class Target, class Custom, class VisitedVector>
struct IsDescendantVector
{
  typedef IsDescendantVector type;
  typedef typename boost::mpl::front<StartVector>::type Head;
  typedef typename boost::mpl::pop_front<StartVector>::type Tail;

#ifdef DOMAIN_HAS_MUTUAL_RECURSION
  typedef typename boost::mpl::push_back<VisitedVector, Head>::type Visited;
#else // Otherwise paradigm may have just self recursion.
  typedef typename boost::mpl::vector1<Head> Visited;
#endif // DOMAIN_HAS_MUTUAL_RECURSION

  enum { value = boost::mpl::or_<RecursiveIsDescendantKind<Head, Target, Custom, Visited>,
                                 IsDescendantVector<Tail, SIZE-1, Target, Custom, Visited> >::value };
};

#endif // DOMAIN_HAS_DESCENDANT_PAIRS


} // namespace LEESA

#endif // __KIND_TRAITS_H

