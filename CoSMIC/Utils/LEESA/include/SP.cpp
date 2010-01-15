#ifndef __SP_CPP
#define __SP_CPP

#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/copy_if.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>

#include <set>

 
#define FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OP)                  \
  template <class X, class Y, class Z>                                      \
  OP##Op<X, Y, Z>                                                           \
  OP (X, Y const & y, Z) {                                                  \
    typedef typename ET<X>::argument_kind argument_kind;                    \
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind, Z>));     \
    return OP##Op<X, Y, Z> (y);                                             \
  }                                                                         \
  template <class X, class Y>                                               \
  OP##Op<X, Y, Default>                                                     \
  OP (X, Y const & y)  {                                                    \
    typedef typename ET<X>::argument_kind argument_kind;                    \
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));        \
    return OP##Op<X, Y, LEESA::Default> (y);                                \
  }

/**********************************************************************************/

#define FUNCTIONS_FOR_SP_OP_WITH_2CUSTOMIZABLE_STRATEGIES(OP)               \
  template <class W, class X, class Y, class Z>                             \
  OP##Op<W, X, Y, Z>                                                        \
  OP (W, X const &x, Y const & y, Z) {                                      \
    typedef typename ET<W>::argument_kind argument_kind;                    \
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind, Z>));     \
    return OP##Op<W, X, Y, Z> (x, y);                                       \
  }                                                                         \
  template <class W, class X, class Y>                                      \
  OP##Op<W, X, Y, Default>                                                  \
  OP (W, X const &x, Y const & y)  {                                        \
    typedef typename ET<W>::argument_kind argument_kind;                    \
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));        \
    return OP##Op<W, X, Y, LEESA::Default> (x, y);                          \
  }

/**********************************************************************************/

#define FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(OP)                                   \
  template <class K, class Strategy1, class Strategy2>                            \
  OP##Op<typename ET<K>::argument_type, Strategy1, Strategy2>                     \
  OP (K, Strategy1 const & s1, Strategy2 const & s2) {                            \
    typedef typename ET<K>::argument_kind argument_kind;                          \
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));              \
    return OP##Op<typename ET<K>::argument_type, Strategy1, Strategy2> (s1, s2);  \
}  

/**********************************************************************************/

#define FUNCTION_FOR_SP_OP_WITH_1STRATEGY(OP)                                     \
  template <class K, class Strategy>                                              \
  OP##Op<typename ET<K>::argument_type, Strategy>                                 \
  OP (K, Strategy const & s) {                                                    \
    typedef typename ET<K>::argument_kind argument_kind;                          \
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));              \
    return OP##Op<typename ET<K>::argument_type, Strategy> (s);                   \
}  

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OP)                             \
template <class K,                                                                 \
          class Strategy = Carrier<K>,                                             \
          class Custom = LEESA::Default>                                           \
struct OP##Op : LEESAUnaryFunction <K>, OpBase, _StrategyBase                      \
{                                                                                  \
    typedef ChainExpr<K, OP##Op> expression_type;                                  \
    typedef LEESAUnaryFunction <K> Super;                                          \
    SUPER_TYPEDEFS(Super);                                                         \
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind, Custom>));       \
                                                                                   \
    template <class U>                                                             \
    struct rebind                                                                  \
    {                                                                              \
      typedef OP##Op<U, typename Strategy::template rebind<U>::type, Custom> type; \
    };                                                                             \
                                                                                   \
    Strategy strategy_;                                                            \
                                                                                   \
    template <class X, class Y, class Z>                                           \
    explicit OP##Op (OP##Op<X, Y, Z> & f)                                          \
      : strategy_(f.strategy_)                                                     \
    {}                                                                             \
                                                                                   \
    explicit OP##Op (Strategy const & s)                                           \
      : strategy_(s) {}                                                            \
                                                                                   \
    result_type operator () (argument_type const & arg)                            \
    {                                                                              \
      BOOST_FOREACH(argument_kind const & kind, arg)                               \
      {                                                                            \
        (*this)(kind);                                                             \
      }                                                                            \
      return arg;                                                                  \
    }

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_2CUSTOMIZABLE_STRATEGIES(OP)                    \
template <class K,                                                           \
          class Strategy1 = Carrier<K>,                                      \
          class Strategy2 = Carrier<K>,                                      \
          class Custom = LEESA::Default>                                     \
struct OP##Op : LEESAUnaryFunction <K>, OpBase, _StrategyBase                \
{                                                                            \
  typedef ChainExpr<K, OP##Op> expression_type;                              \
  typedef LEESAUnaryFunction <K> Super;                                      \
  SUPER_TYPEDEFS(Super);                                                     \
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind, Custom>));   \
                                                                             \
  template <class U>                                                         \
  struct rebind                                                              \
  {                                                                          \
    typedef OP##Op<U,                                                        \
                   typename Strategy1::template rebind<U>::type,             \
                   typename Strategy2::template rebind<U>::type,             \
                   Custom> type;                                             \
  };                                                                         \
                                                                             \
  Strategy1 s1_;                                                             \
  Strategy2 s2_;                                                             \
                                                                             \
  template <class W, class X, class Y, class Z>                              \
  explicit OP##Op (OP##Op<W, X, Y, Z> const & op)                            \
    : s1_(op.s1_), s2_(op.s2_)                                               \
  {}                                                                         \
                                                                             \
  explicit OP##Op (Strategy1 const &s1, Strategy2 const &s2)                 \
    : s1_(s1), s2_ (s2) {}                                                   \
                                                                             \
  result_type operator () (argument_type const & arg)                        \
  {                                                                          \
    BOOST_FOREACH(argument_kind const & kind, arg)                           \
    {                                                                        \
      (*this)(kind);                                                         \
    }                                                                        \
    return arg;                                                              \
  }

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_2STRATEGIES(OP)                                 \
template <class K,                                                           \
          class Strategy1 = Carrier<K>,                                      \
          class Strategy2 = Carrier<K> >                                     \
struct OP##Op : LEESAUnaryFunction <K>, OpBase, _StrategyBase        \
{                                                                            \
  typedef ChainExpr<K, OP##Op> expression_type;                              \
  typedef LEESAUnaryFunction <K> Super;                                      \
  SUPER_TYPEDEFS(Super);                                                     \
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));           \
                                                                             \
  template <class U>                                                         \
  struct rebind                                                              \
  {                                                                          \
    typedef OP##Op<U,                                                        \
                   typename Strategy1::template rebind<U>::type,             \
                   typename Strategy2::template rebind<U>::type> type;       \
  };                                                                         \
                                                                             \
  Strategy1 s1_;                                                             \
  Strategy2 s2_;                                                             \
                                                                             \
  template <class X, class Y, class Z>                                       \
  explicit OP##Op (OP##Op<X, Y, Z> const & op)                               \
    : s1_(op.s1_), s2_(op.s2_)                                               \
  {}                                                                         \
                                                                             \
  explicit OP##Op (Strategy1 const &s1, Strategy2 const &s2)                 \
    : s1_(s1), s2_ (s2) {}                                                   \
                                                                             \
  result_type operator () (argument_type const & arg)                        \
  {                                                                          \
    BOOST_FOREACH(argument_kind const & kind, arg)                           \
    {                                                                        \
      (*this)(kind);                                                         \
    }                                                                        \
    return arg;                                                              \
  }

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_1STRATEGY(OP)                                  \
template <class K, class Strategy = Carrier<K> >                            \
struct OP##Op : LEESAUnaryFunction <K>, OpBase, _StrategyBase               \
{                                                                           \
    typedef ChainExpr<K, OP##Op> expression_type;                           \
    typedef LEESAUnaryFunction <K> Super;                                   \
    SUPER_TYPEDEFS(Super);                                                  \
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));        \
                                                                            \
    template <class U>                                                      \
    struct rebind                                                           \
    {                                                                       \
      typedef OP##Op<U, typename Strategy::template rebind<U>::type> type;  \
    };                                                                      \
                                                                            \
    Strategy strategy_;                                                     \
                                                                            \
    template <class X, class Y>                                             \
    explicit OP##Op (OP##Op<X, Y> & o)                                      \
      : strategy_(o.strategy_)                                              \
    {}                                                                      \
                                                                            \
    explicit OP##Op (Strategy const & s)                                    \
      : strategy_(s) {}                                                     \
                                                                            \
    result_type operator () (argument_type const & arg)                     \
    {                                                                       \
      BOOST_FOREACH(argument_kind const & kind, arg)                        \
      {                                                                     \
        (*this)(kind);                                                      \
      }                                                                     \
      return arg;                                                           \
    }

/**********************************************************************************/

namespace LEESA {

using boost::mpl::front;
using boost::mpl::size;
using boost::mpl::pop_front;
using boost::mpl::if_;
using boost::mpl::copy_if;
using boost::mpl::or_;
using boost::mpl::not_;
using boost::mpl::remove_if;
using boost::mpl::contains;
using boost::mpl::push_back;
using boost::mpl::empty;

using boost::is_same;
using boost::disable_if;
using boost::enable_if;

/********* 5.6. Sequence Equality (C++ Template Metaprogramming) *********
   It's important, particularly when handling computed results, not to 
   fall into the trap of relying on sequence type identity. For example, 
   you should not expect the following assertion to pass:

    BOOST_STATIC_ASSERT((      // error
      boost::is_same<
          mpl::pop_back<mpl::vector<int, short> >::type
        , mpl::vector<int>
      >::value
    ));
   For most purposes, the two types being compared above will act the same, 
   and most of the time you'll never notice a difference. That said, the 
   result of using mpl::pop_back on a specialization of mpl::vector will 
   not be another specialization of mpl::vector!

template <class T = EmptyMPLVector0 >
struct EmptyVector
{
  typedef typename 
    if_<boost::mpl::equal<T, EmptyMPLVector0 >,
        EmptyMPLVector0, 
        T>::type type;
};
*/

template <class T = void>
struct LEESAException : public std::runtime_error
{
  LEESAException (const std::string &s = "")
    : std::runtime_error (std::string("LEESAException (") +
                          typeid(T).name() + "): " + s) 
  {}
};

typedef boost::mpl::vector<>  EmptyMPLVector;
typedef boost::mpl::vector0<> EmptyMPLVector0;

#ifdef LEESA_FOR_UDM
ObjectSet VISITED;
#endif // LEESA_FOR_UDM

class _StrategyBase {}; // Base class of all the strategies. Just for documentation.

template <class K> struct FailOp;

template <class T, class Func> struct CallerOp;
template <class X, class Y> struct TryOp;
template <class X, class Y> struct RepeatOp;
template <class X, class Y> struct RepeatLoopOp;

template <class X, class Y, class Z> struct ChoiceOp;
template <class X, class Y, class Z> struct SeqOp;
template <class X, class Y, class Z> struct OneOp;
template <class X, class Y, class Z> struct AllOp;

#ifdef LEESA_FOR_UDM
template <class X, class Y, class Z> struct AllGraphOp;
template <class X, class Y, class Z> struct FullTDGraphOp;
#endif // LEESA_FOR_UDM

template <class X, class Y, class Z> struct FullTDOp;
template <class X, class Y, class Z> struct FullBUOp;
template <class X, class Y, class Z> struct OnceTDOp;
template <class X, class Y, class Z> struct OnceBUOp;
template <class X, class Y, class Z> struct StopTDOp;
template <class X, class Y, class Z> struct NaiveInnermostOp;
template <class X, class Y, class Z> struct InnermostOp;

template <class W, class X, class Y, class Z> struct AroundFullTDOp;

EXPRESSION_TRAITS_1PARA(FailOp);

EXPRESSION_TRAITS_2PARA(CallerOp);
EXPRESSION_TRAITS_2PARA(TryOp);
EXPRESSION_TRAITS_2PARA(RepeatOp);
EXPRESSION_TRAITS_2PARA(RepeatLoopOp);

EXPRESSION_TRAITS_3PARA(SeqOp);
EXPRESSION_TRAITS_3PARA(ChoiceOp);
EXPRESSION_TRAITS_3PARA(OneOp);
EXPRESSION_TRAITS_3PARA(AllOp);

#ifdef LEESA_FOR_UDM
EXPRESSION_TRAITS_3PARA(AllGraphOp);
EXPRESSION_TRAITS_3PARA(FullTDGraphOp);
#endif // LEESA_FOR_UDM

EXPRESSION_TRAITS_3PARA(FullTDOp);
EXPRESSION_TRAITS_3PARA(FullBUOp);
EXPRESSION_TRAITS_3PARA(OnceTDOp);
EXPRESSION_TRAITS_3PARA(OnceBUOp);
EXPRESSION_TRAITS_3PARA(StopTDOp);
EXPRESSION_TRAITS_3PARA(NaiveInnermostOp);
EXPRESSION_TRAITS_3PARA(InnermostOp);

EXPRESSION_TRAITS_4PARA(AroundFullTDOp);

template <class E, class Func>
struct CallerOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, CallerOp > expression_type;

  Func func_;
  explicit CallerOp (Func f) : func_(f) { }
  CallerOp (CallerOp const & fop) : func_(fop.func_) {}
  result_type operator () (argument_type const & arg)
  {
    func_(arg);
    return arg;
  }
};

template <class Kind>
struct FailOp : public LEESAUnaryFunction<Kind>, OpBase, _StrategyBase
{
  public:
    typedef ChainExpr<Kind, FailOp> expression_type;
    typedef LEESAUnaryFunction <Kind> Super;
    SUPER_TYPEDEFS(Super);
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));

    template <class U>
    struct rebind
    {
      typedef FailOp<U> type;
    };

    explicit FailOp () {}

    template <class U>
    explicit FailOp (FailOp<U> const &) {}

    result_type operator ()(argument_type k)
    {
      throw LEESA::LEESAException<argument_type> ("FailOp: ");      
      return k;
    }
};

template <class H, class Custom> 
/* By default Custom is LEESA::Default. Check in DescendantOp. */
struct FilterChildrenIfNotDescendantCarry : Custom
{};

template <class Vector, class ResultKind, class Custom>
/* By default Custom is LEESA::Default. Check in DescendantOp. */
struct FilterChildrenIfNotDescendantImpl
{
  typedef typename 
    copy_if<Vector, 
            or_<is_same<boost::mpl::placeholders::_1, ResultKind>,
                IsDescendantKind<boost::mpl::placeholders::_1, 
                                 ResultKind, 
                                 Custom> > >::type type;
};

template <class T, class H, class Custom>
/* By default Custom is LEESA::Default. Check in DescendantOp. */
struct KindTraits <T, FilterChildrenIfNotDescendantCarry <H, Custom> >
  : public KindTraits<T, Custom>
{
    BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<T>));
    /* Pipes-and-filter architecture of meta-programs is in action here.
     * If Custom is anything different from LEESA::Default, ChildrenKinds
     * are obtained from that specialization of KindTraits. For exmaple,
     * APOp specializes KindTraits for Custom=RemoveBypassingTypesCarry.
     * This allows AP to remove 'bypass' types before
     * FilterChildrenIfNotDescendantImpl meta-function is applied. */
    typedef typename KindTraits<T, Custom>::ChildrenKinds Children;
    typedef typename 
      FilterChildrenIfNotDescendantImpl<Children, 
                                        typename ET<H>::result_kind, 
                                        Custom>::type ChildrenKinds;
};

CLASS_FOR_SP_OP_WITH_2STRATEGIES(Choice)
    result_kind operator () (argument_kind const & arg)                        
    {
      try {
        s1_(arg);
      }
      catch(...) {
        s2_(arg);
      }
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_2STRATEGIES(Seq)
result_kind operator () (argument_kind const & arg)
    {
      s1_(arg);
      s2_(arg);
      return arg;
    }
};

// This traversal scheme is designed for hierarchical visitor, which
// calls Visit_* on ingress and Leave_* on egress.
CLASS_FOR_SP_OP_WITH_2CUSTOMIZABLE_STRATEGIES(AroundFullTD)
result_kind operator () (argument_kind const & arg)
    {
      typedef AllOp<K, AroundFullTDOp, Custom> All;
      typedef SeqOp<K, Strategy1, All> HalfStrategy;
      typedef SeqOp<K, HalfStrategy, Strategy2> AroundFullTD;
      HalfStrategy hs(s1_, All(*this));
      AroundFullTD around (hs, s2_);
      around(arg);
      return arg;
    }
};


template <class K,
          class Strategy = Carrier<K>,
          class Custom = Default>
struct OneOp : LEESAUnaryFunction <K>, OpBase, _StrategyBase
{
  typedef ChainExpr<K, OneOp> expression_type;                         
  typedef LEESAUnaryFunction <K> Super;
  SUPER_TYPEDEFS(Super);
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind, Custom>));
  
  template <class U>
  struct rebind
  {
    typedef OneOp<U, typename Strategy::template rebind<U>::type, Custom> type; 
  };                                                                             
  Strategy strategy_;
  bool success_;
  
  template <class X, class Y, class Z>                                           
  explicit OneOp (OneOp<X, Y, Z> & f)
    : strategy_(f.strategy_), success_(false)
  {}

  explicit OneOp (Strategy const & s)
    : strategy_(s), success_(false) {}
  
  result_type operator () (argument_type const & arg)
  {
    if (arg.empty())
        throw LEESAException<argument_type>();
    else
    {
      BOOST_FOREACH(argument_kind kind, arg)
      {                 
        try {
          success_ = false;
          (*this)(kind); 
          success_ = true;
          break;
        }
        catch (...) {
        }
      }
      if(!success_) 
        throw LEESAException<argument_type>();
    }
    return arg;
  }

#ifdef LEESA_FOR_UDM

  result_kind operator () (argument_kind const & arg)
  {
    typedef typename KindTraits<argument_kind, Custom>::ChildrenKinds Children;
    ObjectSet objects = Custom::GetChildObjects(arg);
    success_ = false;
    BOOST_FOREACH(Udm::Object o, objects)
    {
      dispatch(o, Children());
    }
    if(!success_) 
      throw LEESAException<argument_type>();
    return arg;
  }

  private:
    // Called when ChildrenVector is non-empty. 
    template <class ChildrenVector>
    typename disable_if<empty<ChildrenVector>, void>::type 
    dispatch(Udm::Object o, ChildrenVector)
    {
      typedef typename front<ChildrenVector>::type Head;
      typedef typename pop_front<ChildrenVector>::type Tail;
      if (o.type() == Head::meta)
      {
        try {
          typedef typename Strategy::template rebind<Head>::type HeadStrategy;
          HeadStrategy hs(strategy_);
          Head arg = Head::Cast(o);
          hs(arg);
          success_ = true;
        }
        catch (...) {
        }
      }
      else
        dispatch(o, Tail());
    }
    // Called when ChildrenVector is empty as in EmptyMPLVector0.
    void dispatch(Udm::Object, EmptyMPLVector0) { }
    
    // Called when ChildrenVector is empty as in EmptyMPLVector.
    // I think the following function is unnecessary because 
    // empty vector is either (1) exactly same as EmptyMPLVector0
    // or (2) convertible to EmptyMPLVector0. 
    void dispatch(Udm::Object, EmptyMPLVector) { }

#else

  result_kind operator () (argument_kind const & arg)
  {
    typedef typename KindTraits<argument_kind, Custom>::ChildrenKinds Children;
    success_ = false;
    dispatch(arg, Children());
    if(!success_) 
      throw LEESAException<argument_type>();
    return arg;
  }

  private:
    // Called when ChildrenVector is non-empty. 
    template <class ChildrenVector>
    typename disable_if<empty<ChildrenVector>, void>::type 
    dispatch(argument_kind const & arg, ChildrenVector)
    {
      typedef typename front<ChildrenVector>::type Head;
      typedef typename pop_front<ChildrenVector>::type Tail;
      typedef typename Strategy::template rebind<Head>::type HeadStrategy;
      HeadStrategy hs(strategy_);
      typename KindTraits<Head, Custom>::Container head_container =
        LEESA::evaluate(arg, argument_kind() >> Head());
      BOOST_FOREACH(Head h, head_container)
      {
        try {
          hs(h);
          success_ = true;
          break;
        }
        catch (...) {
        }
      }
      if(!success_)
        dispatch(arg, Tail());
    }
    // Called when ChildrenVector is empty as in EmptyMPLVector0.
    void dispatch(argument_kind const &,  EmptyMPLVector0) { }
    
    // Called when ChildrenVector is empty as in EmptyMPLVector.
    // I think the following function is unnecessary because 
    // empty vector is either (1) exactly same as EmptyMPLVector0
    // or (2) convertible to EmptyMPLVector0. 
    void dispatch(argument_kind const &, EmptyMPLVector) { }

#endif // LEESA_FOR_UDM
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(All);
#ifdef LEESA_FOR_UDM
    result_kind operator () (argument_kind const & arg)
    {
      /* Pipes-and-filter architecture of meta-programs is in action here.
       * If Custom is anything different from LEESA::Default, ChildrenKinds
       * are obtained from that specialization of KindTraits. For example,
       * DescendantOp specializes KindTraits for Custom=FilterChildrenIfNotDescendantCarry.
       * This allows it to remove types that have no way to reach to the
       * destination type. This chain of meta-functions that prune away
       * undesired types from default ChildrenKinds is the primary mechanism
       * in LEESA that enables schema-aware efficent substructure traversal. 
       * */

      typedef typename KindTraits<argument_kind, Custom>::ChildrenKinds Children;
      ObjectSet objects = Custom::GetChildObjects(arg);
      BOOST_FOREACH(Udm::Object o, objects)
      {
        dispatch(o, Children());
      }
      return arg;
    }

  protected:
    // Called when ChildrenVector is non-empty. 
    template <class ChildrenVector>
    typename disable_if<empty<ChildrenVector>, void>::type 
    dispatch(Udm::Object o, ChildrenVector)
    {
      typedef typename front<ChildrenVector>::type Head;
      typedef typename pop_front<ChildrenVector>::type Tail;
      if(o.type() == Head::meta)
      {
        typedef typename Strategy::template rebind<Head>::type HeadStrategy;
        HeadStrategy hs(strategy_);
        Head arg = Head::Cast(o);
        hs(arg);
      }
      else
        dispatch(o, Tail());
    }
    // Called when ChildrenVector is empty as in EmptyMPLVector0.
    void dispatch(Udm::Object, EmptyMPLVector0) { }

    // Called when ChildrenVector is empty as in EmptyMPLVector.
    // I think the following function is unnecessary because 
    // empty vector is either (1) exactly same as EmptyMPLVector0
    // or (2) convertible to EmptyMPLVector0. 
    void dispatch(Udm::Object, EmptyMPLVector) { }
};

#else

    result_kind operator () (argument_kind const & arg)
    {
      /* Pipes-and-filter architecture of meta-programs is in action here.
       * If Custom is anything different from LEESA::Default, ChildrenKinds
       * are obtained from that specialization of KindTraits. For example,
       * DescendantOp specializes KindTraits for Custom=FilterChildrenIfNotDescendantCarry.
       * This allows it to remove types that have no way to reach to the
       * destination type. This chain of meta-functions that prune away
       * undesired types from default ChildrenKinds is the primary mechanism
       * in LEESA that enables schema-aware efficent substructure traversal. 
       * */

      typedef typename KindTraits<argument_kind, Custom>::ChildrenKinds Children;
      dispatch(arg, Children());
      return arg;
    }

  protected:
    // Called when ChildrenVector is non-empty. 
    template <class ChildrenVector>
    typename disable_if<empty<ChildrenVector>, void>::type 
    dispatch(argument_kind const & arg, ChildrenVector)
    {
      typedef typename front<ChildrenVector>::type Head;
      typedef typename pop_front<ChildrenVector>::type Tail;
      typedef typename Strategy::template rebind<Head>::type HeadStrategy;
      HeadStrategy hs(strategy_);
      const typename ET<Head>::result_type dummy;
      GetChildrenOp <argument_type, typename ET<Head>::result_type> gcop(dummy);
      const Carrier<Head> & head_carrier = gcop(arg);

      BOOST_FOREACH(Head const & h, head_carrier)
      {
        hs(h);
      }
      dispatch(arg, Tail());
    }
    // Called when ChildrenVector is empty as in EmptyMPLVector0.
    void dispatch(argument_kind const &, EmptyMPLVector0) { }

    // Called when ChildrenVector is empty as in EmptyMPLVector.
    // I think the following function is unnecessary because 
    // empty vector is either (1) exactly same as EmptyMPLVector0
    // or (2) convertible to EmptyMPLVector0. 
    void dispatch(argument_kind const &, EmptyMPLVector) { }
};

#endif // LEESA_FOR_UDM

#ifdef LEESA_FOR_UDM

template <class K,
          class Strategy = Carrier<K>,
          class Custom = Default>
struct AllGraphOp : public AllOp<K, Strategy, Custom>
{
  typedef ChainExpr<K, AllGraphOp> expression_type;
  typedef AllOp<K, Strategy, Custom> Super;
  SUPER_TYPEDEFS(Super);
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind, Custom>));

  template <class U>
  struct rebind
  {
    typedef AllGraphOp<U, typename Strategy::template rebind<U>::type, Custom> type; 
  };
  
  template <class X, class Y, class Z>
  explicit AllGraphOp (AllGraphOp<X, Y, Z> & f)
    : Super(f.strategy_)
  {}
  
  explicit AllGraphOp (Strategy const & s)
    : Super(s) {}

  result_type operator () (argument_type const & arg)
  {
    BOOST_FOREACH(argument_kind kind, arg)
    {
      (*this)(kind);
    }
    return arg;
  }

  result_kind operator () (argument_kind const & kind)
  {
    LEESA::VISITED.insert(kind);
    typedef typename KindTraits<argument_kind, Custom>::ChildrenKinds Children;
    ObjectSet objects = Custom::GetChildObjects(kind);
    BOOST_FOREACH(Udm::Object o, objects)
    {
      ObjectSet::iterator iter = LEESA::VISITED.find(o);
      if (iter == LEESA::VISITED.end()) // visit if not visited already.
      {
        Super::dispatch(o, Children());
      }
    }
    return kind;
  }
};

#endif // LEESA_FOR_UDM

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTD);
    result_kind operator () (argument_kind const & arg)
    {
      typedef AllOp<K, FullTDOp, Custom> All;
      SeqOp<K, Strategy, All> s(strategy_, All(*this));
      s(arg);
      return arg;
    }
};

#ifdef LEESA_FOR_UDM

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTDGraph);
    result_kind operator () (argument_kind const & arg)
    {
      typedef AllGraphOp<K, FullTDGraphOp, Custom> AllGraph;
      SeqOp<K, Strategy, AllGraph> s(strategy_, AllGraph(*this));
      ObjectSet::iterator iter = LEESA::VISITED.find(arg);
      if (iter == LEESA::VISITED.end()) // visit if not visited already.
      {
        LEESA::VISITED.insert(arg);
        s(arg);
      }
      return arg;
    }
};

#endif // LEESA_FOR_UDM

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullBU);
    result_kind operator () (argument_kind const & arg)
    {
      typedef AllOp<K, FullBUOp, Custom> All;
      SeqOp<K, All, Strategy> s(All(*this), strategy_);
      s(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_1STRATEGY(Try)
    result_kind operator () (argument_kind const & arg)
    {
      typedef Carrier<argument_kind> KIND_LIT;
      ChoiceOp<K, Strategy, KIND_LIT> c (strategy_, KIND_LIT());
      c(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_1STRATEGY(Repeat)
result_kind operator () (argument_kind const & arg)
    {
      typedef SeqOp<K, Strategy, RepeatOp> S;
      S s(strategy_, *this);
      TryOp<K, S> t(s);
      t(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_1STRATEGY(RepeatLoop)
result_kind operator () (argument_kind const & arg)
    {
      try {
        while(true)
          strategy_(arg);
      }
      catch(...) {}
      
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceTD);
    result_kind operator () (argument_kind const & arg)
    {
      typedef OneOp<K, OnceTDOp, Custom> ONE;
      ChoiceOp<K, Strategy, ONE> c(strategy_, ONE(*this));
      c(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceBU);    
    result_kind operator () (argument_kind const & arg)
    {
      typedef OneOp<K, OnceBUOp, Custom> ONE;
      ChoiceOp<K, ONE, Strategy> c(ONE(*this), strategy_);
      c(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(StopTD);
    result_kind operator () (argument_kind const & arg)
    {
      typedef AllOp<K, StopTDOp, Custom> ALL;
      ChoiceOp<K, Strategy, ALL> c(strategy_, ALL(*this));
      c(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(NaiveInnermost);
    result_kind operator () (argument_kind const & arg)
    {
      typedef OnceBUOp<K, Strategy, Custom> ONCE_BU;
      ONCE_BU once_bu(strategy_);
      RepeatLoopOp<K, ONCE_BU> r(once_bu);
      r(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(Innermost);
  result_kind operator () (argument_kind const & arg)
  {
    typedef AllOp<K, InnermostOp, Custom>   ALL_IM;
    typedef SeqOp<K, Strategy, InnermostOp> SEQ_IM;
    typedef TryOp<K, SEQ_IM>                TRY_IM;
    typedef SeqOp<K, ALL_IM, TRY_IM>        INNER_MOST;
    ALL_IM all(*this);
    SEQ_IM seq(strategy_, *this);
    TRY_IM t(seq);
    INNER_MOST innermost(all, t);
    innermost(arg);
    return arg;
  }
};

#ifndef LEESA_NO_VISITOR

/* 
  This typechecking of argument kinds in 2 parameter strategies appears to be 
  important but not all strategies are templates (e.g., VisitStrategy)
  In such cases, there is no easy way of telling argument kind.

  typedef typename ET<Strategy1>::argument_kind s1_kind;
  typedef typename ET<Strategy2>::argument_kind s2_kind;

  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<argument_kind, s1_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<argument_kind, s2_kind>));
*/

class VisitStrategy : public _StrategyBase
{
    SchemaVisitor & visitor_;
  
  public:

    template <class U>
    struct rebind
    {
      typedef VisitStrategy type;
    };

    explicit VisitStrategy (SchemaVisitor & v) 
      : visitor_(v) {} 

    template <class U>
    U operator ()(U const & k)
    {
      typedef typename ET<U>::argument_kind Kind;
      BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<Kind>));
      LEESA::evaluate(k, Kind() >> visitor_);
      return k;
    }
    
    SchemaVisitor & getVisitor() const
    {
      return visitor_;
    }
};

class LeaveStrategy : public _StrategyBase
{
    SchemaVisitor & visitor_;
  
  public:

    template <class U>
    struct rebind
    {
      typedef LeaveStrategy type;
    };

    explicit LeaveStrategy (SchemaVisitor & v) 
      : visitor_(v) {} 

    template <class U>
    U operator ()(U const & u)
    {
      typedef typename ET<U>::argument_kind Kind;
      BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<Kind>));
      Kind k = u;
#ifdef LEESA_FOR_UDM
      k.Leave(visitor_);
#else
      k.leave(visitor_);
#endif // LEESA_FOR_UDM
      return k;
    }
    
    SchemaVisitor & getVisitor() const
    {
      return visitor_;
    }
};

#endif // LEESA_NO_VISITOR


template <class E, class Func>
CallerOp<typename ET<E>::result_type, Func> 
Call (E, Func f)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<result_kind, typename Func::argument_type>));
  
  return CallerOp<typename ET<E>::result_type, Func> (f);
}

template <class E, class Arg, class Result>
CallerOp<typename ET<E>::result_type, 
         std::pointer_to_unary_function<Arg, Result> > 
Call (E, Result (*f) (Arg))
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
  
  CallerOp<typename ET<E>::result_type, 
           std::pointer_to_unary_function<Arg, Result> > 
    caller(std::ptr_fun(f));
  return caller;
}

template <class K>
FailOp<typename ET<K>::argument_type>
Fail (K) 
{
  typedef typename ET<K>::argument_kind argument_kind;
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));
  FailOp<typename ET<K>::argument_type> f;
  return f;
}  

template <class K>
Carrier<typename ET<K>::argument_kind>
Identity (K) 
{
  typedef typename ET<K>::argument_kind argument_kind;
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));
  Carrier<argument_kind> k;
  return k;
}  

FUNCTION_FOR_SP_OP_WITH_1STRATEGY(Try);        // choice (s, id)
FUNCTION_FOR_SP_OP_WITH_1STRATEGY(Repeat);     // try (sequence (s,repeat(s))
FUNCTION_FOR_SP_OP_WITH_1STRATEGY(RepeatLoop); // infinite loop while(true)

FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(Choice);
FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(Seq);

FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(One);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(All);

#ifdef LEESA_FOR_UDM
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(AllGraph);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTDGraph);
#endif // LEESA_FOR_UDM

FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullBU);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceBU);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(StopTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(NaiveInnermost);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(Innermost);

FUNCTIONS_FOR_SP_OP_WITH_2CUSTOMIZABLE_STRATEGIES(AroundFullTD);

} // namespace LEESA


#endif // __SP_CPP

