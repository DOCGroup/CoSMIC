#ifndef __AP_CPP
#define __AP_CPP

#include <boost/mpl/if.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/copy_if.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/or.hpp>
#include <boost/type_traits.hpp>
#include <boost/static_assert.hpp>


#define FROM(X)        X()
#define TO(...)        boost::mpl::vector<__VA_ARGS__>()
#define THROUGH(...)   Through_Vector_is<boost::mpl::vector<__VA_ARGS__> >()
#define BYPASS(...)    Bypass_Vector_is<boost::mpl::vector<__VA_ARGS__> >()
#define CUSTOMIZER(X)  Custom_is<X>()


namespace LEESA {

using boost::mpl::if_c;
using boost::mpl::contains;
using boost::mpl::size;
using boost::mpl::push_back;
using boost::mpl::front;
using boost::mpl::pop_front;
using boost::mpl::vector;
using boost::mpl::empty;
using boost::mpl::equal;
using boost::mpl::remove_if;
using boost::mpl::copy_if;
using boost::is_same;
using boost::is_base_of;
using boost::disable_if_c;

template <class L, class H, class Custom> struct DescendantOp;
EXPRESSION_TRAITS_3PARA(DescendantOp);

#ifdef LEESA_FOR_UDM
template <class L, class H, class Custom> struct DescendantGraphOp;
template <class Strategy, 
          class From, 
          class ToVector, 
          class ThroughVector, 
          class BypassVector, 
          class Custom> struct APOp;

EXPRESSION_TRAITS_3PARA(DescendantGraphOp);
#endif // LEESA_FOR_UDM


#ifdef LEESA_FOR_UDM

template <class Strategy, 
          class From, 
          class ToVector, 
          class ThroughVector, 
          class BypassVector,
          class Custom>
struct ET <APOp<Strategy, From, ToVector, ThroughVector, BypassVector, Custom> >
  : public ETBase <APOp<Strategy, From, ToVector, ThroughVector, BypassVector, Custom> > {};

#endif // LEESA_FOR_UDM

template <class L, 
          class H, 
          class Custom = LEESA::Default >
struct DescendantOp : LEESAUnaryFunction<L, H>, OpBase
{
  typedef LEESA::LEESAUnaryFunction<L, H> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, DescendantOp> expression_type;

  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<argument_kind, result_kind, Custom>));

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
    void operator () (K const & arg)
    {
      /* For any type other than result_type and result_kind, simply neglect
       * the argument. Noop. For desired types, push them in the retval. */
    }
    void operator () (result_type const & k)
    {
      retval_.push_back(k);
    }
    void operator () (result_kind const & k)
    {
      retval_.push_back(k);
    }
  };

public:

  result_type operator () (argument_type const & arg)
  {
    result_type retval; 
    typedef FilterChildrenIfNotDescendantCarry<H, Custom> Customizer;
    typedef CollectBFS<result_type, Customizer> CollectBFS;
    typedef Star<CollectBFS, result_type, Customizer> Star;

    Star star(retval);
    star.template apply<argument_kind>(arg);
    return retval;
  }
};

template <class L, class H>                                          
DescendantOp<typename ET<L>::result_type,                                  
             typename ET<H>::result_type>                                  
DescendantsOf (L, H)                                                        
{                                                                    
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<L>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<H>));                  
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
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<L>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<H>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<L,H,Custom>));
  typedef typename ET<L>::argument_type argument_type;               
  typedef typename ET<H>::result_type result_type;                   
                                                                     
  return DescendantOp<argument_type, result_type, Custom>();               
}

#ifdef LEESA_FOR_UDM

template <class L, 
          class H, 
          class Custom = LEESA::Default >
struct DescendantGraphOp : DescendantOp<L, H, Custom>
{
  typedef DescendantOp<L, H, Custom> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, DescendantGraphOp> expression_type;

  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<argument_kind, result_kind, Custom>));

  result_type operator () (argument_type const & arg)
  {
    typename Super::Accumulate acc(Super::retval_);
    evaluate(arg, argument_kind() 
      >> FullTDGraph(argument_kind(), acc, FilterChildrenIfNotDescendantCarry<H, Custom>()));
    return Super::retval_;
  }
};

template <class L, class H>                                          
DescendantGraphOp<typename ET<L>::result_type,                                  
                  typename ET<H>::result_type>                                  
GraphDescendantsOf (L, H)                                                        
{                                                                    
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<L>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<H>));                  
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
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<L>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<H>));                  
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<L, H, Custom>));

  typedef typename ET<L>::argument_type argument_type;               
  typedef typename ET<H>::result_type result_type;                   
                                                                     
  return DescendantGraphOp<argument_type, result_type, Custom>();               
}



struct __ANY {};
struct Through_tag {};
struct Bypass_tag {};
struct Custom_tag {};

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

template <class Custom>
struct Custom_is
{
  typedef Custom_tag tag;
  typedef Custom type; 
};

template <class BypassVector, class Custom>
/* By default Custom is LEESA::Default. Check in APOp. */
struct RemoveBypassingTypesCarry : Custom
{ };

template <class ChildrenVector, class BypassVector>
/* By default Custom is LEESA::Default. Check in APOp. */
struct RemoveBypassingTypesImpl
{
  typedef typename 
    remove_if <ChildrenVector, 
               contains<BypassVector, ::boost::mpl::placeholders::_1> >::type type;

    // Check the ReachableConcept only when they are not equal.
    // i.e. something was bypassed from the children list.
    // enum { check = !equal<Children, type>::value };
    // BOOST_CONCEPT_ASSERT((LEESA::ReachableConcept <check, type, ToKind>));
};

template <class T, 
          class BypassVector,
          class Custom>
/* By default Custom is LEESA::Default. Check in APOp. */
struct KindTraits <T, RemoveBypassingTypesCarry<BypassVector, Custom> >
  : public KindTraits <T, Custom>
{
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<T>));
    typedef typename KindTraits<T, Custom>::ChildrenKinds Children;
    typedef typename RemoveBypassingTypesImpl<Children, BypassVector>::type ChildrenKinds;
};

template <class Parent, 
          class Descendant, 
          class BypassVector,
          class Custom>
struct IsDescendantKind <Parent, 
                         Descendant,
                         RemoveBypassingTypesCarry<BypassVector, Custom> >
  : LEESA::IsDescendantKind <Parent, Descendant, Custom>
{ 
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<Parent>));
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<Descendant>));
};

template <class Strategy, 
          class From, 
          class ToVector, 
          class ThroughVector, 
          class BypassVector,
          class Custom /* APGen provides the default value of the Custom = LEESA::Default */ >
struct APOp : LEESAUnaryFunction <From>, OpBase 
{
  typedef LEESA::LEESAUnaryFunction<From> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<From, APOp> expression_type;

  APOp (Strategy s) : strategy_(s) { }
  
  result_type operator () (argument_type from)
  {
    ObjectSet old_visited;
    old_visited.swap(LEESA::VISITED);
    from_through(from, ThroughVector());
    old_visited.swap(LEESA::VISITED);
    return from;
  }

private:

  template <class F, class ThroughV>
  typename disable_if_c<empty<ThroughV>::value, void>::type  
  from_through(F from, ThroughV)
  {
    typedef typename front<ThroughV>::type Head;
    typedef typename pop_front<ThroughV>::type Tail;
    typedef typename ET<From>::argument_kind FromKind;
    typedef typename ET<From>::argument_type FromType;
    typedef typename ET<Head>::result_type HeadType;

    DescendantGraphOp <FromType, HeadType, RemoveBypassingTypesCarry<BypassVector, Custom> > d;
    typename KindTraits<Head>::Container through_set 
      = evaluate(from, FromKind() >> d);
    BOOST_FOREACH(Head h, through_set)
    {
      strategy_(h);
      LEESA::VISITED.erase(h);
      through_to(h, ToVector());
    }
  }
  template <class F> void from_through(F, EmptyMPLVector0) { }
  template <class F> void from_through(F, EmptyMPLVector) { }
  
  template <class F> 
  void from_through(F from, boost::mpl::vector<__ANY>) 
  { 
    through_to(from, ToVector());
  }

  template <class Through, class ToV>
  typename disable_if_c<empty<ToV>::value, void>::type   
  through_to(Through through, ToV)
  {
    typedef typename front<ToV>::type Head;
    typedef typename pop_front<ToV>::type Tail;
    typedef typename ET<Through>::argument_kind ThroughKind;
    typedef typename ET<Through>::argument_type ThroughType;
    typedef typename ET<Head>::result_type HeadType;
    
    DescendantGraphOp<ThroughType, HeadType, RemoveBypassingTypesCarry<BypassVector, Custom> > d;
    strategy_(evaluate(through, ThroughKind() >> d));

    through_to(through, Tail());
  }
  template <class F> void through_to(F, EmptyMPLVector0) { }
  template <class F> void through_to(F, EmptyMPLVector) { }

  Strategy strategy_;
};


template <class Vector, unsigned int SIZE, class Key>
struct find_param 
{
  typedef typename front<Vector>::type Head;
  typedef typename pop_front<Vector>::type Tail;
  typedef typename 
    if_c<is_same<typename Head::tag, Key>::value,
         typename Head::type,
         typename find_param<Tail, SIZE-1, Key>::type>::type type;
};

template <class Vector>
struct find_param <Vector, 0, Through_tag>
{
  typedef boost::mpl::vector1<__ANY> type;
};

template <class Vector>
struct find_param <Vector, 0, Bypass_tag>
{
  typedef EmptyMPLVector0 type;
};

template <class Vector>
struct find_param <Vector, 0, Custom_tag>
{
  typedef LEESA::Default type;
};

template <class V1, class V2>
struct Intersection
{
  typedef typename
    copy_if<V1, contains<V2, boost::mpl::placeholders::_1> >::type type;
};


// APGen type generator implements the "Named Template Parameter" idiom.
template <class Strategy,
          class From, 
          class ToVector, 
          class Through = Through_Vector_is<boost::mpl::vector1<__ANY> >,
          class Bypass = Bypass_Vector_is<EmptyMPLVector0>,
          class Custom = Custom_is<LEESA::Default> >
struct APGen
{
private:

  typedef boost::mpl::vector3<Through, Bypass, Custom> Configuration;
  typedef typename 
    find_param<Configuration, size<Configuration>::value, Through_tag>::type ThroughVector;
  typedef typename 
    find_param<Configuration, size<Configuration>::value, Bypass_tag>::type BypassVector;
  typedef typename 
    find_param<Configuration, size<Configuration>::value, Custom_tag>::type CustomInner;

  enum { VALID_PARAMETERIZATION 
          = !empty<ToVector>::value &&
             empty<typename Intersection<ThroughVector, BypassVector>::type>::value &&
             empty<typename Intersection<ToVector, BypassVector>::type>::value &&
            !contains<BypassVector, typename ET<From>::argument_kind>::value };

  BOOST_MPL_ASSERT_RELATION( VALID_PARAMETERIZATION, ==, 1 );

public:
  typedef  
    APOp<Strategy, From, ToVector, ThroughVector, BypassVector, CustomInner> type;
};

template <class Strategy, class From, class To, class Through, class Bypass, class Custom>
typename 
  APGen<Strategy, typename ET<From>::result_type, To, Through, Bypass, Custom>::type
AP(Strategy const & s, From, To, Through, Bypass, Custom)
{
  typedef typename ET<From>::argument_kind from_kind;
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<from_kind>));
  return typename 
    APGen<Strategy, typename ET<From>::result_type, To, Through, Bypass, Custom>::type(s);
}

template <class Strategy, class From, class To, class Through, class Bypass>
typename APGen<Strategy, typename ET<From>::result_type, To, Through, Bypass>::type
AP(Strategy const & s, From, To, Through, Bypass)
{
  typedef typename ET<From>::argument_kind from_kind;
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<from_kind>));
  return typename 
    APGen<Strategy, typename ET<From>::result_type, To, Through, Bypass>::type(s);
}

template <class Strategy, class From, class To, class TB>
typename APGen<Strategy, typename ET<From>::result_type, To, TB>::type
AP(Strategy const & s, From, To, TB)
{
  typedef typename ET<From>::argument_kind from_kind;
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<from_kind>));
  return typename APGen<Strategy, typename ET<From>::result_type, To, TB>::type(s);
}

template <class Strategy, class From, class To>
typename APGen<Strategy, typename ET<From>::result_type, To>::type
AP(Strategy const & s, From, To)
{
  typedef typename ET<From>::argument_kind from_kind;
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<from_kind>));
  return typename APGen<Strategy, typename ET<From>::result_type, To>::type(s);
}

#endif // LEESA_FOR_UDM


} // namespace LEESA

#endif // __AP_CPP 

