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

#define FROM(X)        X()
#define TO(...)        boost::mpl::vector<__VA_ARGS__>()
#define THROUGH(...)   Through_Vector_is<boost::mpl::vector<__VA_ARGS__> >()
#define BYPASS(...)    Bypass_Vector_is<boost::mpl::vector<__VA_ARGS__> >()
#define CUSTOMIZER(X)  Customizer_is<X>()


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
template <class L, class H, class Custom> struct DescendantGraphOp;
template <class Strategy, class From, class ToVector, 
          class ThroughVector, class BypassVector, class Customizer> class APOp;

ExpressionTraits3Para(DescendantOp);
ExpressionTraits3Para(DescendantGraphOp);


template <class Vector, class ResultKind, class Customizer>
struct FilterChildrenIfNotDescendant
{
  typedef typename front<Vector>::type Head;
  typedef typename pop_front<Vector>::type Tail;
  typedef typename 
    if_c<is_same<Head, ResultKind>::value |
         IsDescendantKind<Head, ResultKind, Customizer>::value,
         typename push_back<typename FilterChildrenIfNotDescendant<Tail, ResultKind, Customizer>::type,
                  Head>::type,
         typename FilterChildrenIfNotDescendant<Tail, ResultKind, Customizer>::type 
    >::type type;
};
template <class ResultKind, class Customizer>
struct FilterChildrenIfNotDescendant <EmptyMPLVector, ResultKind, Customizer> {
  typedef EmptyMPLVector type;
};
template <class ResultKind, class Customizer>
struct FilterChildrenIfNotDescendant <EmptyMPLVectorB, ResultKind, Customizer> {
  typedef EmptyMPLVector type;
}; 


template <class L, class H, class Custom, class T>
struct ChildrenKinds <DescendantOp<L, H, Custom>, T>
{
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<T>));
    typedef typename ChildrenKinds<Custom, T>::type Children;
    typedef typename 
      FilterChildrenIfNotDescendant<Children, 
                                    typename ET<H>::result_kind, 
                                    Custom>::type type;
};

template <class Strategy, 
          class From, 
          class ToVector, 
          class ThroughVector, 
          class BypassVector,
          class Customizer>
struct ET <APOp<Strategy, From, ToVector, ThroughVector, BypassVector, Customizer> >
  : public ETBase <APOp<Strategy, From, ToVector, ThroughVector, BypassVector, Customizer> > {};

template <class L, 
          class H, 
          class Customizer = LEESA::Default >
struct DescendantOp : LEESAUnaryFunction<L, H>,
                      OpBase, 
                      LEESA::Default // inherit GetChildObjects()
{
  typedef DescendantOp Self;
  typedef LEESA::LEESAUnaryFunction<L, H> Super;
  SUPER_TYPEDEFS(Super);
	typedef ChainExpr<L, DescendantOp> expression_type;

  BOOST_CONCEPT_ASSERT((LEESA::
  DescendantKindConcept<argument_kind, result_kind, Customizer>));

protected:
  result_type retval_;

  struct Accumulate : public _StrategyBase
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
      //std::cout << typeid(K).name() << arg.isEmpty() << std::endl;
      retval_.Union(evaluate(arg, Kind() >> CastFromTo(Kind(), result_kind())));
    }
    void operator () (result_type k)
    {
		  retval_.Union(k);
    }
  };

public:

  result_type operator () (argument_type const & arg)
  {
    Accumulate acc(retval_);
    evaluate(arg, argument_kind() >> FullTD(argument_kind(), acc, Self()));
    return retval_;
  }
};

template <class L, 
          class H, 
          class Customizer = LEESA::Default >
struct DescendantGraphOp : DescendantOp<L, H, Customizer>
{
  typedef DescendantOp<L, H, Customizer> Super;
  SUPER_TYPEDEFS(Super);
	typedef ChainExpr<L, DescendantGraphOp> expression_type;

  BOOST_CONCEPT_ASSERT((LEESA::
    DescendantKindConcept<argument_kind, result_kind, Customizer>));

  result_type operator () (argument_type const & arg)
  {
    typename Super::Accumulate acc(Super::retval_);
    evaluate(arg, argument_kind() 
      >> FullTDGraph(argument_kind(), acc, Super()));
    return Super::retval_;
  }
};



template <class L, class H>                                          
DescendantOp<typename ET<L>::result_type,                                  
             typename ET<H>::result_type>                                  
DescendantsOf (L, H)                                                        
{                                                                    
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<L>));                  
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<H>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<L,H, LEESA::Default>));         
                                                                     
	typedef typename ET<L>::argument_type argument_type;               
	typedef typename ET<H>::result_type result_type;                   
                                                                     
  return DescendantOp<argument_type, result_type, LEESA::Default>();                       
}                                                                    
                                                                     
template <class L, class H, class Custom>                            
DescendantOp<typename ET<L>::result_type,                                  
             typename ET<H>::result_type,                                  
             Custom>                                                       
DescendantsOf (L, H, Custom)                                                
{                                                                    
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<L>));                  
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<H>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<L,H,Custom>));
	typedef typename ET<L>::argument_type argument_type;               
	typedef typename ET<H>::result_type result_type;                   
                                                                     
  return DescendantOp<argument_type, result_type, Custom>();               
}

template <class L, class H>                                          
DescendantGraphOp<typename ET<L>::result_type,                                  
                  typename ET<H>::result_type>                                  
GraphDescendantsOf (L, H)                                                        
{                                                                    
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<L>));                  
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<H>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<L,H,LEESA::Default>));         
                                                                     
	typedef typename ET<L>::argument_type argument_type;               
	typedef typename ET<H>::result_type result_type;                   
                                                                     
  return DescendantGraphOp<argument_type, result_type>();                       
}                                                                    
                                                                     
template <class L, class H, class Custom>                            
DescendantGraphOp<typename ET<L>::result_type,                                  
                  typename ET<H>::result_type,                                  
                  Custom>                                                       
GraphDescendantsOf (L, H, Custom)                                                
{                                                                    
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<L>));                  
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<H>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<L, H, Custom>));                                                                              \
	typedef typename ET<L>::argument_type argument_type;               
	typedef typename ET<H>::result_type result_type;                   
                                                                     
  return DescendantGraphOp<argument_type, result_type, Custom>();               
}



struct __ANY {};
struct Through_tag {};
struct Bypass_tag {};
struct Customizer_tag {};

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

template <class Customizer>
struct Customizer_is
{
  typedef Customizer_tag tag;
  typedef Customizer type; 
};

template <class Strategy, 
          class From, 
          class ToVector, 
          class ThroughVector, 
          class BypassVector,
          class Customizer,
          class T>
struct ChildrenKinds <APOp<Strategy, From, ToVector, ThroughVector, BypassVector, Customizer>, T>
{
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<T>));
    typedef typename ChildrenKinds<Customizer, T>::type Children;
    typedef typename 
      APOp<Strategy, From, ToVector, ThroughVector,BypassVector, Customizer>::template
        RemoveBypassingTypes<Children>::type type;
};

template <class Parent, 
          class Descendant, 
          class Strategy, 
          class From, 
          class ToVector, 
          class ThroughVector, 
          class BypassVector,
          class Customizer>
struct IsDescendantKind <Parent, 
                         Descendant,
                         APOp<Strategy, From, ToVector, ThroughVector, BypassVector, Customizer> >
  : LEESA::IsDescendantKind <Parent, Descendant, Customizer>
{ };


template <class Strategy, 
          class From, 
          class ToVector, 
          class ThroughVector, 
          class BypassVector,
          class Customizer>
class APOp : LEESAUnaryFunction <From>, OpBase
{
  typedef APOp Self;

public:
  
  typedef LEESA::LEESAUnaryFunction<From> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<From, APOp> expression_type;

  template <class ChildrenVector>
  struct RemoveBypassingTypes
  {
    typedef typename 
      remove_if <ChildrenVector, 
        contains<BypassVector, ::boost::mpl::placeholders::_1> >::type type;

      // Check the ReachableConcept only when they are not equal.
      // i.e. something was bypassed from the children list.
      // enum { check = !equal<Children, type>::value };
      // BOOST_CONCEPT_ASSERT((LEESA::ReachableConcept <check, type, ToKind>));
  };

private:

  template <class F, class ThroughV>
  void from_through(F from, ThroughV)
  {
    typedef typename boost::mpl::front<ThroughV>::type Head;
    typedef typename boost::mpl::pop_front<ThroughV>::type Tail;
    typedef typename ET<From>::argument_kind FromKind;
    typedef typename ET<From>::argument_type FromType;
	  typedef typename ET<Head>::result_type HeadType;

    DescendantGraphOp <FromType, HeadType, Self> d;
    typename ContainerGen<Head>::type through_set 
      = evaluate(from, FromKind() >> d);
    BOOST_FOREACH(Head h, through_set)
    {
      strategy_(h);
      LEESA::VISITED.erase(h);
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

  template <class Through, class ToV>
  void through_to(Through through, ToV)
  {
    typedef typename boost::mpl::front<ToV>::type Head;
    typedef typename boost::mpl::pop_front<ToV>::type Tail;
    typedef typename ET<Through>::argument_kind ThroughKind;
    typedef typename ET<Through>::argument_type ThroughType;
	  typedef typename ET<Head>::result_type HeadType;
    
    DescendantGraphOp<ThroughType, HeadType, Self> d;
    strategy_(evaluate(through, ThroughKind() >> d));

    through_to(through, Tail());
  }
  template <class F> void through_to(F, EmptyMPLVector) { }
  template <class F> void through_to(F, EmptyMPLVectorB) { }

  Strategy strategy_;

public:

  APOp (Strategy s) : strategy_(s) { }
  result_type operator () (argument_type from)
  {
    ObjectSet old_visited;
    old_visited.swap(LEESA::VISITED);
    from_through(from, ThroughVector());
    old_visited.swap(LEESA::VISITED);
    return from;
  }
};


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
template < >
struct find_param <EmptyMPLVector, Customizer_tag>
{
  typedef LEESA::Default type;
};
template < >
struct find_param <EmptyMPLVectorB, Customizer_tag>
{
  typedef LEESA::Default type;
};



template <class V1, class V2>
struct Intersection
{
  typedef typename front<V2>::type Head;
  typedef typename pop_front<V2>::type Tail;
  typedef typename 
    if_<contains<V1, Head>,
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


// APGen type generator implements the "Named Template Parameter" idiom.
template <class Strategy,
          class From, 
          class ToVector, 
          class Through = Through_Vector_is<boost::mpl::vector<__ANY> >,
          class Bypass = Bypass_Vector_is<EmptyMPLVector>,
          class Custom = Customizer_is<LEESA::Default> >
struct APGen
{
private:

  typedef boost::mpl::vector<Through, Bypass, Custom> Configuration;
  typedef typename 
    find_param<Configuration, Through_tag>::type ThroughVector;
  typedef typename 
    find_param<Configuration, Bypass_tag>::type BypassVector;
  typedef typename 
    find_param<Configuration, Customizer_tag>::type Customizer;

  enum { VALID_PARAMETERIZATION 
          = !empty<ToVector>::value &&
             empty<typename Intersection<ThroughVector, BypassVector>::type>::value &&
             empty<typename Intersection<ToVector, BypassVector>::type>::value &&
            !contains<BypassVector, typename ET<From>::argument_kind>::value };

  BOOST_MPL_ASSERT_RELATION( VALID_PARAMETERIZATION, ==, 1 );

public:
  typedef  
    APOp<Strategy, From, ToVector, ThroughVector, BypassVector, Customizer> type;
};

template <class Strategy, class From, class To, class Through, class Bypass, class Custom>
typename 
  APGen<Strategy, typename ET<From>::result_type, To, Through, Bypass, Custom>::type
AP(Strategy const & s, From, To, Through, Bypass, Custom)
{
  typedef typename ET<From>::argument_kind from_kind;
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<from_kind>));
  return typename 
    APGen<Strategy, typename ET<From>::result_type, To, Through, Bypass, Custom>::type(s);
}

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
  return typename APGen<Strategy, typename ET<From>::result_type, To>::type(s);
}


} // namespace LEESA

#endif // __AP_CPP 

