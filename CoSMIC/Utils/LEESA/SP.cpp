#ifndef __SP_CPP
#define __SP_CPP

#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>

#define CUSTOM_COMMON                            \
  template <class T>                             \
  struct ChildrenKinds {                         \
     typedef typename T::ChildrenKinds type;     \
  };                                             \

#define CUSTOM_PARENT(T, ...)                          \
  template <>                                          \
  struct ChildrenKinds <T> {                           \
    typedef boost::mpl::vector< __VA_ARGS__ > type;    \
  };                                                   \

#define CUSTOM_PARENT_EMPTY(T)                         \
  template <>                                          \
  struct ChildrenKinds <T> {                           \
    typedef EmptyMPLVector type;                       \
  };                                                   \

#define CHILDREN(...) __VA_ARGS__

/**********************************************************************************/

#define FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OP)          \
  template <class X, class Y, class Z>                              \
  OP##Op<X, Y, Z>                                                   \
  OP (X, Y const & y, Z) {                                          \
	typedef typename ET<X>::argument_kind argument_kind;              \
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));       \
    return OP##Op<X, Y, Z> (y);                                     \
  }                                                                 \
  template <class X, class Y>                                       \
  OP##Op<X, Y, AllChildrenKinds>                                    \
  OP (X, Y const & y)  {                                            \
	typedef typename ET<X>::argument_kind argument_kind;              \
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));       \
    return OP##Op<X, Y, AllChildrenKinds> (y);                      \
  }

/**********************************************************************************/

#define FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(OP)                                  \
  template <class K, class Strategy1, class Strategy2>                            \
  OP##Op<typename ET<K>::argument_type, Strategy1, Strategy2>                     \
  OP (K, Strategy1 const & s1, Strategy2 const & s2) {                            \
	  typedef typename ET<K>::argument_kind argument_kind;                          \
	  BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));                   \
    return OP##Op<typename ET<K>::argument_type, Strategy1, Strategy2> (s1, s2);  \
}  

/**********************************************************************************/

#define FUNCTION_FOR_SP_OP_WITH_1STRATEGY(OP)                                    \
  template <class K, class Strategy>                                              \
  OP##Op<typename ET<K>::argument_type, Strategy>                                 \
  OP (K, Strategy const & s) {                                                    \
	  typedef typename ET<K>::argument_kind argument_kind;                          \
	  BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));                   \
    return OP##Op<typename ET<K>::argument_type, Strategy> (s);                   \
}  

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OP)                             \
template <class K,                                                                 \
          class Strategy = KindLit<K>,                                             \
          class Custom = AllChildrenKinds>                                         \
struct OP##Op : LEESAUnaryFunction <K>, OpBase                                     \
{                                                                                  \
    typedef typename ChainExpr<K, OP##Op> expression_type;                         \
    typedef typename ET<K>::result_kind argument_kind;                             \
    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));                    \
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
      : strategy_(s) {}

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_2STRATEGIES(OP)                                 \
template <class K,                                                           \
          class Strategy1 = KindLit<K>,                                      \
          class Strategy2 = KindLit<K> >                                     \
struct OP##Op : LEESAUnaryFunction <K>, OpBase                               \
{                                                                            \
  typedef typename ChainExpr<K, OP##Op> expression_type;                     \
  typedef typename ET<K>::result_kind argument_kind;                         \
  BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));                \
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
    : s1_(op.s1), s2_(op.s2)                                                 \
  {}                                                                         \
                                                                             \
  explicit OP##Op (Strategy1 const &s1, Strategy2 const &s2)                 \
    : s1_(s1), s2_ (s2)                                                      \
  {}

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_1STRATEGY(OP)                                  \
template <class K, class Strategy = KindLit<K> >                            \
struct OP##Op : LEESAUnaryFunction <K>, OpBase                              \
{                                                                           \
    typedef typename ChainExpr<K, OP##Op> expression_type;                  \
	  typedef typename ET<K>::result_kind argument_kind;                      \
    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));             \
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
      : strategy_(s) {}

/**********************************************************************************/

namespace LEESA {

using boost::mpl::front;
using boost::mpl::pop_front;
using boost::mpl::if_;
using boost::mpl::contains;
using boost::mpl::push_back;

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
*/
typedef boost::mpl::vector<> EmptyMPLVectorB;
typedef boost::mpl::vector0<> EmptyMPLVector;
/*
template <class T = EmptyMPLVector >
struct EmptyVector
{
  typedef typename 
    if_<boost::mpl::equal<T, EmptyMPLVector >,
        EmptyMPLVector, 
        T>::type type;
};
*/
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

template <class T = void>
struct LEESAException : public std::runtime_error
{
  LEESAException (const std::string &s = "")
    : std::runtime_error (std::string("LEESAException (") +
                          typeid(T).name() + "): " + s) 
  {}
};

struct AllChildrenKinds
{
  template <class T>
  struct ChildrenKinds
  {
    typedef typename T::ChildrenKinds type;
  };
};


template <class T, class Func> struct CallerOp;
template <class K> struct FailOp;
template <class X, class Y, class Z> struct ChoiceOp;
template <class X, class Y, class Z> struct SEQOp;
template <class X, class Y, class Z> struct OneOp;
template <class X, class Y, class Z> struct AllOp;
template <class X, class Y, class Z> struct FullTDOp;
template <class X, class Y, class Z> struct FullBUOp;

template <class X, class Y> struct TryOp;
template <class X, class Y> struct RepeatOp;
template <class X, class Y> struct RepeatLoopOp;
template <class X, class Y, class Z> struct OnceTDOp;
template <class X, class Y, class Z> struct OnceBUOp;
template <class X, class Y, class Z> struct StopTDOp;
template <class X, class Y, class Z> struct NaiveInnermostOp;
template <class X, class Y, class Z> struct InnermostOp;

ExpressionTraits1Para(FailOp);

ExpressionTraits2Para(CallerOp);
ExpressionTraits2Para(TryOp);
ExpressionTraits2Para(RepeatOp);
ExpressionTraits2Para(RepeatLoopOp);

ExpressionTraits3Para(SEQOp);
ExpressionTraits3Para(ChoiceOp);
ExpressionTraits3Para(OneOp);
ExpressionTraits3Para(AllOp);
ExpressionTraits3Para(FullTDOp);
ExpressionTraits3Para(FullBUOp);
ExpressionTraits3Para(OnceTDOp);
ExpressionTraits3Para(OnceBUOp);
ExpressionTraits3Para(StopTDOp);
ExpressionTraits3Para(NaiveInnermostOp);
ExpressionTraits3Para(InnermostOp);


template <class E, class Func>
struct CallerOp : LEESAUnaryFunction <E>, OpBase
{
	typedef typename ChainExpr<E, CallerOp > expression_type;

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
struct FailOp : public LEESAUnaryFunction<Kind>, OpBase
{
  public:
    typedef ChainExpr<Kind, FailOp> expression_type;
    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));

    template <class U>
    struct rebind
    {
      typedef FailOp<U> type;
    };

    explicit FailOp (){}

    template <class U>
    explicit FailOp (FailOp<U> const &) {}

    result_type operator ()(argument_type k)
    {
      throw LEESA::LEESAException<argument_type> ("FailOp: ");      
      return k;
    }
};

/* 
  This typechecking of argument kinds in 2 parameter strategies appears to be 
  important but not all strategies are templates (e.g., VisitStrategy)
  In such cases, there is no easy way of telling argument kind.

  typedef typename ET<Strategy1>::argument_kind s1_kind;
  typedef typename ET<Strategy2>::argument_kind s2_kind;

  BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<argument_kind, s1_kind>));
  BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<argument_kind, s2_kind>));
*/

CLASS_FOR_SP_OP_WITH_2STRATEGIES(Choice)
	  result_type operator () (argument_type const & arg)                        
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

CLASS_FOR_SP_OP_WITH_2STRATEGIES(SEQ)
result_type operator () (argument_type const & arg)
    {
      s1_(arg);
      s2_(arg);
      return arg;
    }
};


CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(One);
result_type operator () (argument_type const & arg)
    {
      if (arg.isEmpty())
          throw LEESAException<argument_type>();
      else
      {
        typedef typename Custom::template 
          ChildrenKinds<argument_kind>::type CustomChildren;
        typedef typename Intersection <CustomChildren, K::ChildrenKinds>::type 
          CommonChildrenTypes;
        
        bool success = false;
        children(arg, CommonChildrenTypes(), success);
        if(!success) 
            throw LEESAException<argument_type>();
      }
      return arg;
    }

  private:
    // Called when ChildrenVector is non-empty. 
    template <class ChildrenVector>
    void children(argument_type arg, ChildrenVector, bool &success)
    {
      typedef typename ET<argument_type>::argument_kind K;
      typedef typename front<ChildrenVector>::type head;
      typedef typename pop_front<ChildrenVector>::type tail;
      typename Strategy::template rebind<head>::type s(strategy_);
      typedef typename ContainerGen<head>::type HeadVector;
      HeadVector head_vector = evaluate (arg, K() >> head());
      for (HeadVector::iterator iter = head_vector.begin();
           iter != head_vector.end();)
      {
        try {
          s(*iter);
          success = true;
          return;
        }
        catch (...) {
          ++iter;
        }
      }
      if (!success)
        children(arg, tail(), success);
    }
    // Called when ChildrenVector is empty as in EmptyMPLVector.
    void children(argument_type, EmptyMPLVector, bool)
    {
    }
	  // Called when ChildrenVector is empty as in EmptyMPLVectorB.
    void children(argument_type, EmptyMPLVectorB, bool)
    {
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(All);
result_type operator () (argument_type const & arg)
    {
      if (!arg.isEmpty())
      {
        typedef typename Custom::template 
          ChildrenKinds<argument_kind>::type CustomChildren;
        typedef typename Intersection <CustomChildren, typename K::ChildrenKinds>::type 
          CommonChildrenTypes;
        children(arg, CommonChildrenTypes());
      }
      return arg;
    }

  private:
    // Called when ChildrenVector is non-empty. 
    template <class ChildrenVector>
    void children(argument_type arg, ChildrenVector)
    {
      typedef typename ET<argument_type>::argument_kind K;
      typedef typename front<ChildrenVector>::type head;
      typedef typename pop_front<ChildrenVector>::type tail;
      typedef typename Strategy::template rebind<head>::type HeadStrategy;
      HeadStrategy hs(strategy_);
      hs(evaluate(arg, K() >> head()));
      /*typedef GetChildrenOp<KindLit, typename ET<head>::argument_type > GC;
      GC gc;
      ChainExpr<KindLit, GC> c(KindLit(), gc);
      hs(evaluate(arg, c));*/
      children(arg, tail());
    }
    // Called when ChildrenVector is empty as in EmptyMPLVector.
    void children(argument_type, EmptyMPLVector)
    { }
    // Called when ChildrenVector is empty as in EmptyMPLVectorB.
    void children(argument_type, EmptyMPLVectorB)
    { }
};


CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTD);
    result_type operator () (argument_type const & arg)
    {
      typedef AllOp<K, FullTDOp, Custom> All;
      SEQOp<K, Strategy, All> s(strategy_, All(*this));
      s(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullBU);
    result_type operator () (argument_type const & arg)
    {
      typedef AllOp<K, FullBUOp, Custom> All;
      SEQOp<K, All, Strategy> s(All(*this), strategy_);
      s(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_1STRATEGY(Try)
    result_type operator () (argument_type const & arg)
    {
      typedef KindLit<argument_kind> KIND_LIT;
      ChoiceOp<K, Strategy, KIND_LIT> c (strategy_, KIND_LIT());
      c(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_1STRATEGY(Repeat)
result_type operator () (argument_type const & arg)
    {
      typedef SEQOp<K, Strategy, RepeatOp> S;
      S s(strategy_, *this);
      TryOp<K, S> t(s);
      t(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_1STRATEGY(RepeatLoop)
result_type operator () (argument_type const & arg)
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
    result_type operator () (argument_type const & arg)
    {
      typedef OneOp<K, OnceTDOp, Custom> ONE;
      ChoiceOp<K, Strategy, ONE> c(strategy_, ONE(*this));
      c(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceBU);    
    result_type operator () (argument_type const & arg)
    {
      typedef OneOp<K, OnceBUOp, Custom> ONE;
      ChoiceOp<K, ONE, Strategy> c(ONE(*this), strategy_);
      c(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(StopTD);
    result_type operator () (argument_type const & arg)
    {
      typedef AllOp<K, StopTDOp, Custom> ALL;
      ChoiceOp<K, Strategy, ALL> c(strategy_, ALL(*this));
      c(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(NaiveInnermost);
    result_type operator () (argument_type const & arg)
    {
      typedef OnceBUOp<K, Strategy, Custom> ONCE_BU;
      ONCE_BU once_bu(strategy_);
      RepeatLoopOp<K, ONCE_BU> r(once_bu);
      r(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(Innermost);
    result_type operator () (argument_type const & arg)
    {
      typedef AllOp<K, InnermostOp, Custom>   ALL;
      typedef SEQOp<K, Strategy, InnermostOp> SEQ;
      typedef TryOp<K, SEQ>                   TRY;
      typedef SEQOp<K, ALL, TRY>              IM;
      ALL all(*this);
      SEQ seq(strategy_, *this);
      TRY t(seq);
      IM innermost(all, t);
      innermost(arg);
      return arg;
    }
};

class VisitStrategy
{
    PARADIGM_NAMESPACE_FOR_LEESA::Visitor & visitor_;
  public:

    template <class U>
    struct rebind
    {
      typedef VisitStrategy type;
    };

    explicit VisitStrategy (PARADIGM_NAMESPACE_FOR_LEESA::Visitor & v) 
      : visitor_(v) {} 

    template <class U>
    U operator ()(U const & k)
    {
      using namespace LEESA;
      typedef typename ET<U>::argument_kind Kind;
      BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<Kind>));
      evaluate(k, Kind() >> visitor_);
      return k;
    }
    PARADIGM_NAMESPACE_FOR_LEESA::Visitor & getVisitor() const
    {
      return visitor_;
    }
};

template <class E, class Func>
CallerOp<typename ET<E>::result_type, Func> 
Call (E, Func f)
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<result_kind, typename Func::argument_type>));
	
  return CallerOp<typename ET<E>::result_type, Func> (f);
}

template <class E, class Arg, class Result>
CallerOp<typename ET<E>::result_type, 
         std::pointer_to_unary_function<Arg, Result> > 
Call (E, Result (*f) (Arg))
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
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
  BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
  FailOp<typename ET<K>::argument_type> f;
  return f;
}  

template <class K>
KindLit<typename ET<K>::argument_kind>
Identity (K) 
{
  typedef typename ET<K>::argument_kind argument_kind;
  BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
  KindLit<argument_kind> k;
  return k;
}  

FUNCTION_FOR_SP_OP_WITH_1STRATEGY(Try);        // choice (s, id)
FUNCTION_FOR_SP_OP_WITH_1STRATEGY(Repeat);     // try (sequence (s,repeat(s))
FUNCTION_FOR_SP_OP_WITH_1STRATEGY(RepeatLoop); // infinite loop while(true)

FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(Choice);
FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(SEQ);

FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(One);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(All);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullBU);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceBU);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(StopTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(NaiveInnermost);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(Innermost);




} // namespace LEESA


#endif // __SP_CPP

