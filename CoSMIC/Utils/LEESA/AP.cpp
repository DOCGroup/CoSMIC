#ifndef __AP_CPP
#define __AP_CPP

#include <boost/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/placeholders.hpp>

#define FROM(X)      X()
#define TO(...)      boost::mpl::vector<__VA_ARGS__>()
#define THROUGH(...) Through_Vector_is<boost::mpl::vector<__VA_ARGS__> >()
#define BYPASS(...)  Bypass_Vector_is<boost::mpl::vector<__VA_ARGS__> >()

namespace LEESA {

using boost::mpl::if_c;
using boost::disable_if_c;
using boost::mpl::contains;
using boost::mpl::push_back;
using boost::mpl::front;
using boost::mpl::pop_front;
using boost::mpl::vector;
using boost::mpl::empty;
using boost::mpl::equal;
using boost::mpl::remove_if;
using boost::is_same;
using boost::is_base_of;


template <class L, class H, class Custom> struct DescendantOp;
template <class Strategy, class From, class ToVector, 
          class ThroughVector, class BypassVector> class APOp;

ExpressionTraits3Para(DescendantOp);

template <class Strategy, class From, class ToVector, class ThroughVector, class BypassVector>
struct ET <APOp<Strategy, From, ToVector, ThroughVector, BypassVector> >
  : public ETBase <APOp<Strategy, From, ToVector, ThroughVector, BypassVector> > {};

template <class L, class H, class Custom = AllChildrenKinds>
struct DescendantOp : LEESAUnaryFunction<L, H>, OpBase
{
  typedef LEESA::LEESAUnaryFunction<L, H> Super;
  SUPER_TYPEDEFS(Super);
	typedef typename ChainExpr<L, DescendantOp> expression_type;

  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<argument_kind, result_kind>));

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
      //std::cout << typeid(K).name() << arg.isEmpty() << std::endl;
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
    evaluate(arg, argument_kind() >> FullTD(argument_kind(), acc, FastDescendants()));
    return retval_;
  }
  struct FastDescendants 
  {
    template <class Vector>
    struct FilterChildrenIfNotDescendant
    {
      typedef typename front<Vector>::type Head;
      typedef typename pop_front<Vector>::type Tail;
      typedef typename 
        if_c<is_same<Head, result_kind>::value |
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
      BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<K>));
      typedef typename 
        Custom::template ChildrenKinds<K, result_kind>::type Children;
      typedef typename 
        FilterChildrenIfNotDescendant<Children>::type type;
    };
    
  };
};

struct __ANY {};
struct Through_tag {};
struct Bypass_tag {};

template <class ThroughVector>
struct Through_Vector_is
{
  typedef Through_tag tag;
  typedef ThroughVector type; 
};

template <class BypassVector>
struct Bypass_Vector_is
{
  typedef Bypass_tag tag;
  typedef BypassVector type; 
};

template <class Strategy, 
          class From, 
          class ToVector, 
          class ThroughVector, 
          class BypassVector>
class APOp : LEESAUnaryFunction <From>, OpBase
{
public:
  typedef LEESA::LEESAUnaryFunction<From> Super;
  SUPER_TYPEDEFS(Super);
	typedef typename ChainExpr<From, APOp> expression_type;

private:

  struct RemoveBypassingTypes
  {
    template <class K, class ToKind>
    struct ChildrenKinds
    {
      typedef typename 
        remove_if <typename K::ChildrenKinds, 
          contains<BypassVector, ::boost::mpl::placeholders::_1> >::type type;

      // Check the ReachableConcept only when they are not equal.
      // i.e. something was bypassed from the children list.
      enum { check = !equal<typename K::ChildrenKinds, type>::value };
      BOOST_CONCEPT_ASSERT((LEESA::ReachableConcept <check, type, ToKind>));
    };
  };


  template <class F, class ThroughVector>
  void from_through(F from, ThroughVector)
  {
    typedef typename mpl::front<ThroughVector>::type Head;
    typedef typename mpl::pop_front<ThroughVector>::type Tail;
    typedef typename ET<From>::argument_kind FromKind;
    typename ContainerGen<Head>::type through_set
      = evaluate(from, FromKind() >> 
          DescendantsOf(FromKind(), Head(), RemoveBypassingTypes()));
    BOOST_FOREACH(Head h, through_set)
    {
      strategy_(h);
      through_to(h, ToVector());
    }
  }
  template <class F> void from_through(F, EmptyMPLVector) { }
  template <class F> void from_through(F, EmptyMPLVectorB) { }
  template <class F> 
  void from_through(F from, boost::mpl::vector<__ANY>) 
  { 
    through_to(from, ToVector());
  }

  template <class Through, class ToVector>
  void through_to(Through through, ToVector)
  {
    typedef typename mpl::front<ToVector>::type Head;
    typedef typename mpl::pop_front<ToVector>::type Tail;
    typedef typename ET<Through>::argument_kind ThroughKind;
    strategy_(evaluate(through, ThroughKind() 
          >> DescendantsOf(ThroughKind(), Head(), RemoveBypassingTypes())));
    through_to(through, Tail());
  }
  template <class F> void through_to(F, EmptyMPLVector) { }
  template <class F> void through_to(F, EmptyMPLVectorB) { }

  Strategy strategy_;

public:

  APOp (Strategy s) : strategy_(s) { }
  result_type operator () (argument_type from)
  {
    from_through(from, ThroughVector());
    return from;
  }
};


template <class L, class H>
DescendantOp<typename ET<L>::result_type, 
             typename ET<H>::result_type> 
DescendantsOf (L, H)
{
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<L>));
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<H>));
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<L,H>));

	typedef typename ET<L>::argument_type argument_type;
	typedef typename ET<H>::result_type result_type;

	return DescendantOp<argument_type, result_type>();
}

template <class L, class H, class Custom>
DescendantOp<typename ET<L>::result_type, 
             typename ET<H>::result_type,
             Custom> 
DescendantsOf (L, H, Custom)
{
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<L>));
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<H>));
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<L,H>));

	typedef typename ET<L>::argument_type argument_type;
	typedef typename ET<H>::result_type result_type;

	return DescendantOp<argument_type, result_type, Custom>();
}

// APGen type generator implements the "Named Template Parameter" idiom.
template <class Strategy,
          class From, 
          class ToVector, 
          class Through = Through_Vector_is<boost::mpl::vector<__ANY> >,
          class Bypass = Bypass_Vector_is<EmptyMPLVector> >
struct APGen
{
  template <class Vector, class Key>
  struct find_param 
  {
    typedef typename front<Vector>::type Head;
    typedef typename pop_front<Vector>::type Tail;
    typedef typename 
      if_c<is_same<typename Head::tag, Key>::value,
           typename Head::type,
           typename find_param<Tail, Key>::type>::type type;
  };
  template < >
  struct find_param <EmptyMPLVector, Through_tag>
  {
    typedef boost::mpl::vector<__ANY> type;
  };
  template < >
  struct find_param <EmptyMPLVectorB, Through_tag>
  {
    typedef boost::mpl::vector<__ANY> type;
  };
  template < >
  struct find_param <EmptyMPLVector, Bypass_tag>
  {
    typedef EmptyMPLVector type;
  };
  template < >
  struct find_param <EmptyMPLVectorB, Bypass_tag>
  {
    typedef EmptyMPLVector type;
  };
  typedef boost::mpl::vector<Through, Bypass> Configuration;
  typedef typename 
    find_param<Configuration, Through_tag>::type ThroughVector;
  typedef typename 
    find_param<Configuration, Bypass_tag>::type BypassVector;

  template <class V1, class V2>
  struct Intersection
  {
    typedef typename front<V2>::type Head;
    typedef typename pop_front<V2>::type Tail;
    typedef typename 
      if_<typename contains<V1, Head>,
          typename push_back<typename Intersection<V1, Tail>::type, Head>::type,
          typename Intersection<V1, Tail>::type
      >::type type;
  };

  template <class V1>
  struct Intersection <V1, EmptyMPLVector >
  {
    typedef EmptyMPLVector type;
  };

  template <class V1>
  struct Intersection <V1, EmptyMPLVectorB >
  {
    typedef EmptyMPLVector type;
  };

  enum { VALID_PARAMETERIZATION 
    = !empty<ToVector>::value &&
       empty<typename Intersection<ThroughVector, BypassVector>::type>::value &&
       empty<typename Intersection<ToVector, BypassVector>::type>::value &&
      !contains<BypassVector, typename ET<From>::argument_kind>::value };

  BOOST_MPL_ASSERT_RELATION( VALID_PARAMETERIZATION, ==, 1 );

  typedef typename APOp<Strategy, From, ToVector, ThroughVector, BypassVector> type;
};

template <class Strategy, class From, class To, class Through, class Bypass>
typename APGen<Strategy, typename ET<From>::result_type, To, Through, Bypass>::type
AP(Strategy const & s, From, To, Through, Bypass)
{
  typedef typename ET<From>::argument_kind from_kind;
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<from_kind>));
  return typename 
    APGen<Strategy, typename ET<From>::result_type, To, Through, Bypass>::type(s);
}

template <class Strategy, class From, class To, class TB>
typename APGen<Strategy, typename ET<From>::result_type, To, TB>::type
AP(Strategy const & s, From, To, TB)
{
  typedef typename ET<From>::argument_kind from_kind;
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<from_kind>));
  return typename APGen<Strategy, typename ET<From>::result_type, To, TB>::type(s);
}

template <class Strategy, class From, class To>
typename APGen<Strategy, typename ET<From>::result_type, To>::type
AP(Strategy const & s, From, To)
{
  typedef typename ET<From>::argument_kind from_kind;
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<from_kind>));
  return typename APGen<typename ET<From>::result_type, To>::type(s);
}


} // namespace LEESA

#endif // __AP_CPP 

