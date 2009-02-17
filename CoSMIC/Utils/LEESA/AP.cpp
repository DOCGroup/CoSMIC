#ifndef __AP_CPP
#define __AP_CPP

#include <boost/type_traits.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>

namespace LEESA {

using boost::mpl::if_c;
using boost::mpl::contains;
using boost::is_same;
using boost::is_base_of;
using boost::mpl::push_back;
using boost::mpl::front;
using boost::mpl::pop_front;
using boost::mpl::vector;

template <class L, class H> struct DescendantOp;

template <class L, class H>
struct ET <DescendantOp<L, H> > 
	: public ETBase <DescendantOp<L, H> > {};

template <class L, class H>
struct DescendantOp : LEESAUnaryFunction<L, H>, OpBase
{
  typedef LEESA::LEESAUnaryFunction<L, H> Super;
  SUPER_TYPEDEFS(Super);
	typedef typename ChainExpr<L, DescendantOp> expression_type;

  BOOST_CONCEPT_ASSERT((Udm::DescendantKindConcept<argument_kind, result_kind>));

  result_type retval_;

  struct Accumulate
  {
    template <class K>
    struct rebind 
    {
      typedef Accumulate type;
    };
    
    result_type & retval_;
    Accumulate (result_type & r)
      : retval_(r) {}

    template <class K>
    void operator () (K arg)
    {
      typedef typename ET<K>::argument_kind Kind;
      //AfxMessageBox (typeid(K).name(), MB_OK| MB_ICONINFORMATION);
      retval_.Union(evaluate(arg, Kind() >> CastFromTo(Kind(), result_kind())));
    }
    void operator () (result_type k)
    {
		  retval_.Union(k);
      //AfxMessageBox (typeid(result_type).name(), MB_OK| MB_ICONINFORMATION);
    }
  };
  result_type operator () (argument_type const & arg)
  {
    Accumulate acc(retval_);
    evaluate(arg, argument_kind() >> FullTD(argument_kind(), acc, FullTD_Custom()));
    return retval_;
  }
  struct FullTD_Custom 
  {
    template <class Vector>
    struct FilterChildrenIfNotDescendant
    {
      typedef typename front<Vector>::type Head;
      typedef typename pop_front<Vector>::type Tail;
      typedef typename 
        if_c<//is_same<Head, result_kind>::value |
             contains <typename Head::DescendantKinds, result_kind>::value ,
             typename push_back<typename FilterChildrenIfNotDescendant<Tail>::type,
                                Head>::type,
             typename FilterChildrenIfNotDescendant<Tail>::type 
        >::type type;
    };
    template <>
    struct FilterChildrenIfNotDescendant <EmptyMPLVector> {
      typedef EmptyMPLVector type;
    };
    template <>
    struct FilterChildrenIfNotDescendant <EmptyMPLVectorB> {
      typedef EmptyMPLVector type;
    };
    template <class K>
    struct ChildrenKinds   
    {
      BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<K>));
      typedef typename 
        if_c<//is_same<K, result_kind>::value |
             //is_base_of<K, result_kind>::value |
             contains<typename K::DescendantKinds, result_kind>::value,
             typename FilterChildrenIfNotDescendant<typename K::ChildrenKinds>::type,
             //typename K::ChildrenKinds,
             EmptyMPLVector>::type type;
    };
    
  };
};

template <class L, class H>
DescendantOp<typename ET<L>::result_type, 
             typename ET<H>::result_type> 
DescendantFrom (L, H)
{
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<L>));
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<H>));
  BOOST_CONCEPT_ASSERT((Udm::DescendantKindConcept<L,H>));

	typedef typename ET<L>::argument_type argument_type;
	typedef typename ET<H>::result_type result_type;

	return DescendantOp<argument_type, result_type>();
}




} // namespace LEESA

#endif // __AP_CPP 

