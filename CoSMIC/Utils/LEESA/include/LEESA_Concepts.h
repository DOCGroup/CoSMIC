#ifndef __LEESA_CONCEPTS_H
#define __LEESA_CONCEPTS_H

#include "Kind_Traits.h"

#include <boost/mpl/count_if.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept_check.hpp>

using boost::mpl::front;
using boost::mpl::pop_front;
using boost::mpl::size;

namespace LEESA 
{
  template <class T, class Custom = Default>
  struct DomainKindConcept 
  {
    void constraints()
    {
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
    }

    typedef typename KindTraits<T, Custom>::MetaKind MK;
    typedef DomainKindConcept type;
    enum { value = boost::mpl::contains<LEESA::MetaTagList, MK>::value }; 
  };

  template <class L, class H, class Custom = Default>
  struct SameKindsConcept
  {    
    void constraints()
    {
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
    }
    
    typedef SameKindsConcept type;
    enum { value = DomainKindConcept<L, Custom>::value &&
                   DomainKindConcept<H, Custom>::value && 
                   boost::is_same<L, H>::value &&  
                   boost::is_same<typename KindTraits<L, Custom>::MetaKind, 
                                  typename KindTraits<H, Custom>::MetaKind>::value }; 
  };

  template <class L, class H, class Custom = Default>
  struct ConvertibleDomainKindsConcept
  {
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
    void constraints()
    {
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
    }

    typedef typename KindTraits<ParentKind, Custom>::ChildrenKinds Children;
    typedef ParentChildConcept type;
    enum { value = DomainKindConcept<ParentKind, Custom>::value &&
                   DomainKindConcept<ChildKind, Custom>::value && 
                   (boost::mpl::contains<Children, ChildKind>::value ||
                    // If the ChildrenKindss contains a base of ChildKind
                    boost::mpl::count_if <Children, 
                                          boost::is_base_of <boost::mpl::placeholders::_1, 
                                                             ChildKind> 
                                         >::value)    }; 
  };

  template <class ChildKind, class ParentKind, class Custom = Default>
  struct ChildToParentConcept 
  {
    void constraints()
    {
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
    }

    typedef typename KindTraits<ChildKind, Custom>::ParentKinds ParentKinds;
    typedef ChildToParentConcept type;
    enum { value = DomainKindConcept<ParentKind, Custom>::value &&
                   DomainKindConcept<ChildKind, Custom>::value && 
                   boost::mpl::contains<ParentKinds, ParentKind>::value }; 
  };

  template <class ParentKind, class DescendantKind, class Custom = Default>
  struct DescendantKindConcept
  {
    void constraints()
    {
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
    }

    typedef DescendantKindConcept type;
    enum { value = 
            DomainKindConcept<ParentKind, Custom>::value &&
            DomainKindConcept<DescendantKind, Custom>::value && 
            IsDescendantKind<ParentKind, DescendantKind, Custom>::value }; 
  };

  template <class ParentKind, class DescendantKind, unsigned int SkipCount, class Custom> struct CheckExists;

  template <class Vector, 
            unsigned int SIZE, 
            class DescendantKind, 
            unsigned int SkipCount, 
            class Custom>
  struct CheckExistsVector
  {
    typedef CheckExistsVector type;
    typedef typename front<Vector>::type Head;
    typedef typename pop_front<Vector>::type Tail;
    enum { value = CheckExists<Head, DescendantKind, SkipCount, Custom>::value ||
                   CheckExistsVector<Tail, size<Tail>::value, DescendantKind, SkipCount, Custom>::value };
  };

  template <class Vector, 
            class DescendantKind, 
            unsigned int SkipCount, 
            class Custom>
  struct CheckExistsVector <Vector, 0, DescendantKind, SkipCount, Custom> 
  {
    typedef CheckExistsVector type;
    enum { value = 0 };
  };

  template <class ParentKind, class DescendantKind, unsigned int SkipCount, class Custom>
  struct CheckExists
  {
    typedef CheckExists type;
    typedef typename KindTraits<ParentKind, Custom>::ChildrenKinds Children;
    enum { value = CheckExistsVector<Children, 
                                     size<Children>::value, 
                                     DescendantKind, 
                                     SkipCount-1, 
                                     Custom>::value };
  };

  template <class ParentKind, class DescendantKind, class Custom>
  struct CheckExists <ParentKind, DescendantKind, 0, Custom>
  {
    typedef CheckExists type;
    typedef typename KindTraits<ParentKind, Custom>::ChildrenKinds Children;
    enum { value = boost::mpl::contains<Children, DescendantKind>::value };
  };

  template <class ParentKind, class DescendantKind, unsigned int SkipCount, class Custom = Default>
  struct LevelDescendantKindConcept
  {
    void constraints()
    {
      BOOST_MPL_ASSERT_RELATION( value, !=, 0 );
    }

    typedef LevelDescendantKindConcept type;
    enum { value = 
            DomainKindConcept<ParentKind, Custom>::value &&
            DomainKindConcept<DescendantKind, Custom>::value &&
            IsDescendantKind<ParentKind, DescendantKind, Custom>::value &&
            CheckExists<ParentKind, DescendantKind, SkipCount, Custom>::value }; 
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

