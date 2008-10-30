#ifndef __LEESA_CONCEPTS_H
#define __LEESA_CONCEPTS_H

#include <boost/mpl/contains.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept/assert.hpp>

namespace LEESA {
 
template <class T>
struct ElementConcept 
{
   void constraints()
   {
     BOOST_MPL_ASSERT((ST<T>));
   }
};

template <class L, class H>
struct SameElementsConcept
{
  void constraints()
  {
    BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<L>));
    BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<H>));
    BOOST_MPL_ASSERT((boost::is_same<L, H>));
  }
};

template <class Parent, class Child>
struct ParentChildConcept 
{
  void constraints()
  {
    BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<Parent>));
    BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<Child>));
    typedef typename SCHEMA_NAMESPACE_FOR_LEESA::ST<Parent>::Children Children;
    BOOST_MPL_ASSERT((boost::mpl::contains<Children, Child> ));
  }
};


} // end namespace LEESA

#endif // __LEESA_CONCEPTS_H
