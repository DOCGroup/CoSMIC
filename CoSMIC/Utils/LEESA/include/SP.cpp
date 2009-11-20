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
#include <boost/mpl/contains.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/utility/enable_if.hpp>

#include <set>


#define FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OP)            \
  template <class X, class Y, class Z>                                \
  OP##Op<X, Y, Z>                                                     \
  OP (X, Y const & y, Z) {                                            \
    typedef typename ET<X>::argument_kind argument_kind;              \
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));     \
    return OP##Op<X, Y, Z> (y);                                       \
  }                                                                   \
  template <class X, class Y>                                         \
  OP##Op<X, Y, Default>                                               \
  OP (X, Y const & y)  {                                              \
    typedef typename ET<X>::argument_kind argument_kind;              \
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));     \
    return OP##Op<X, Y, LEESA::Default> (y);                          \
  }

/**********************************************************************************/

#define FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(OP)                                   \
  template <class K, class Strategy1, class Strategy2>                            \
  OP##Op<typename ET<K>::argument_type, Strategy1, Strategy2>                     \
  OP (K, Strategy1 const & s1, Strategy2 const & s2) {                            \
    typedef typename ET<K>::argument_kind argument_kind;                          \
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));                 \
    return OP##Op<typename ET<K>::argument_type, Strategy1, Strategy2> (s1, s2);  \
}  

/**********************************************************************************/

#define FUNCTION_FOR_SP_OP_WITH_1STRATEGY(OP)                                     \
  template <class K, class Strategy>                                              \
  OP##Op<typename ET<K>::argument_type, Strategy>                                 \
  OP (K, Strategy const & s) {                                                    \
    typedef typename ET<K>::argument_kind argument_kind;                          \
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));                 \
    return OP##Op<typename ET<K>::argument_type, Strategy> (s);                   \
}  

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OP)                             \
template <class K,                                                                 \
          class Strategy = KindLit<K>,                                             \
          class Custom = LEESA::Default>                                           \
struct OP##Op : LEESAUnaryFunction <K>, OpBase, _StrategyBase                      \
{                                                                                  \
    typedef ChainExpr<K, OP##Op> expression_type;                                  \
    typedef LEESAUnaryFunction <K> Super;                                          \
    SUPER_TYPEDEFS(Super);                                                         \
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));                  \
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
      BOOST_FOREACH(argument_kind kind, arg)                                       \
      {                                                                            \
        (*this)(kind);                                                             \
      }                                                                            \
      return arg;                                                                  \
    }

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_2STRATEGIES(OP)                                 \
template <class K,                                                           \
          class Strategy1 = KindLit<K>,                                      \
          class Strategy2 = KindLit<K> >                                     \
struct OP##Op : LEESAUnaryFunction <K>, OpBase, _StrategyBase                \
{                                                                            \
  typedef ChainExpr<K, OP##Op> expression_type;                              \
  typedef LEESAUnaryFunction <K> Super;                                      \
  SUPER_TYPEDEFS(Super);                                                     \
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));              \
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
    : s1_(s1), s2_ (s2) {}                                                   \
                                                                             \
  result_type operator () (argument_type const & arg)                        \
  {                                                                          \
    BOOST_FOREACH(argument_kind kind, arg)                                   \
    {                                                                        \
      (*this)(kind);                                                         \
    }                                                                        \
    return arg;                                                              \
  }

/**********************************************************************************/

#define CLASS_FOR_SP_OP_WITH_1STRATEGY(OP)                                  \
template <class K, class Strategy = KindLit<K> >                            \
struct OP##Op : LEESAUnaryFunction <K>, OpBase, _StrategyBase               \
{                                                                           \
    typedef ChainExpr<K, OP##Op> expression_type;                           \
    typedef LEESAUnaryFunction <K> Super;                                   \
	  SUPER_TYPEDEFS(Super);                                                  \
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));           \
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
      BOOST_FOREACH(argument_kind kind, arg)                                \
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
using boost::mpl::or_;
using boost::mpl::contains;
using boost::mpl::push_back;
using boost::mpl::empty;

using boost::disable_if_c;

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

typedef std::set<Udm::Object> ObjectSet;
ObjectSet VISITED;

struct Default
{
  static ObjectSet GetChildObjects(Udm::Object o)
  {
    return o.GetChildObjects();
  };
};

template <class Custom, class T>
struct ChildrenKinds;

template <class T>
struct ChildrenKinds <Default, T>
{
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<T>));
  typedef typename T::ChildrenKinds type;
};


#ifdef PARADIGM_HAS_DESCENDANT_PAIRS

template <class Parent, class Descendant, class Customizer>
struct IsDescendantKind;

template <class Parent, class Descendant>
struct IsDescendantKind <Parent, Descendant, Default>
{
  typedef IsDescendantKind type;
  enum { value = PARADIGM_NAMESPACE_FOR_LEESA::IsDescendant<Parent, Descendant>::value };
};

#else // PARADIGM_HAS_DESCENDANT_PAIRS

// The following metaprogram is suitable for elements with SELF as well as 
// MUTUAL-RECURSION. This meta-program could be used as a substitute for the 
// gen-pairs.pl program. However, because of heavy metaprogramming it is slow
// and for paradigms with mutual recursion, the "visited" vector may grow too 
// big to handle for boost and/or the compiler. It is therefore advisible to
// #define a boolean macro called PARADIGM_HAS_MUTUAL_RECURSION before including
// LEESA.h if you know that the paradigm has mutual recursion. By default it is 
// disabled and my result into very long compilation errors saying that 'value'
// is not defined ...

template <class Parent, class Target, class Customizer, class VisitedVector>
struct RecursiveIsDescendantKind;

template <class Parent, class Descendant, class Customizer>
struct IsDescendantKind
{
  typedef IsDescendantKind type;
  typedef boost::mpl::vector1<Parent> Visited;
  enum { value = RecursiveIsDescendantKind <Parent, Descendant, Customizer, Visited>::value };
};

template <class StartVector, unsigned int SIZE, class Target, class Customizer, class VisitedVector>
struct IsDescendantVector;

template <class Parent, class Descendant, class Customizer, class VisitedVector>
struct RecursiveIsDescendantKind
{
  typedef RecursiveIsDescendantKind type;
  typedef typename ChildrenKinds<Customizer, Parent>::type ChildrenKinds;
  typedef typename 
    boost::mpl::remove_if <ChildrenKinds, 
        contains<VisitedVector, boost::mpl::placeholders::_1> >::type SkippedVisitedVector;

  enum { value = 
          or_<contains <ChildrenKinds, Descendant>,
              IsDescendantVector<SkippedVisitedVector, size<SkippedVisitedVector>::value, 
                                 Descendant, Customizer, VisitedVector> >::value };
};

template <class StartVector, class Target, class Customizer, class VisitedVector>
struct IsDescendantVector<StartVector, 0, Target, Customizer, VisitedVector> 
{
  typedef IsDescendantVector type;
  enum { value = 0 };
};

template <class StartVector, unsigned int SIZE, class Target, class Customizer, class VisitedVector>
struct IsDescendantVector
{
  typedef IsDescendantVector type;
  typedef typename front<StartVector>::type Head;
  typedef typename pop_front<StartVector>::type Tail;

#ifdef PARADIGM_HAS_MUTUAL_RECURSION
  typedef typename push_back<VisitedVector, Head>::type Visited;
#else // Otherwise paradigm may have just self recursion.
  typedef typename boost::mpl::vector1<Head> Visited;
#endif // PARADIGM_HAS_MUTUAL_RECURSION

  enum { value = or_<RecursiveIsDescendantKind<Head, Target, Customizer, Visited>,
                     IsDescendantVector<Tail, SIZE-1, Target, Customizer, Visited> >::value };
};

#endif //PARADIGM_HAS_DESCENDANT_PAIRS


class _StrategyBase {}; // Base class of all the strategies. Just for documentation.


template <class T, class Func> struct CallerOp;
template <class K> struct FailOp;
template <class X, class Y, class Z> struct ChoiceOp;
template <class X, class Y, class Z> struct SeqOp;
template <class X, class Y, class Z> struct OneOp;
template <class X, class Y, class Z> struct AllOp;
template <class X, class Y, class Z> struct AllGraphOp;
template <class X, class Y, class Z> struct FullTDOp;
template <class X, class Y, class Z> struct FullTDGraphOp;
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

ExpressionTraits3Para(SeqOp);
ExpressionTraits3Para(ChoiceOp);
ExpressionTraits3Para(OneOp);
ExpressionTraits3Para(AllOp);
ExpressionTraits3Para(AllGraphOp);
ExpressionTraits3Para(FullTDOp);
ExpressionTraits3Para(FullTDGraphOp);
ExpressionTraits3Para(FullBUOp);
ExpressionTraits3Para(OnceTDOp);
ExpressionTraits3Para(OnceBUOp);
ExpressionTraits3Para(StopTDOp);
ExpressionTraits3Para(NaiveInnermostOp);
ExpressionTraits3Para(InnermostOp);


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
    BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));

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

  BOOST_CONCEPT_ASSERT((LEESA::SameUdmKindsConcept<argument_kind, s1_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::SameUdmKindsConcept<argument_kind, s2_kind>));
*/

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


template <class K,                                                                 
          class Strategy = KindLit<K>,                                             
          class Custom = Default>                                         
struct OneOp : LEESAUnaryFunction <K>, OpBase, _StrategyBase
{                                                                                  
  typedef ChainExpr<K, OneOp> expression_type;                         
  typedef LEESAUnaryFunction <K> Super;
  SUPER_TYPEDEFS(Super);
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));                  
                                                                                 
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
    if (arg.isEmpty())
        throw LEESAException<argument_type>();
    else
    {
      success_ = false;
      BOOST_FOREACH(argument_kind kind, arg)                                       
      {                 
        try {
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

  result_kind operator () (argument_kind const & arg)
  {
    typedef typename ChildrenKinds<Custom, argument_kind>::type CustomChildren;
    std::set<Udm::Object> objects = Custom::GetChildObjects(arg);
    success_ = false;
    BOOST_FOREACH(Udm::Object o, objects)
    {
      dispatch(o, CustomChildren());
    }
    if(!success_) 
      throw LEESAException<argument_type>();
    return arg;
  }

  private:
    // Called when ChildrenVector is non-empty. 
    template <class ChildrenVector>
    typename disable_if_c<empty<ChildrenVector>::value, void>::type 
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
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(All);
result_kind operator () (argument_kind const & arg)
    {
      typedef typename ChildrenKinds<Custom, argument_kind>::type CustomChildren;
      std::set<Udm::Object> objects = Custom::GetChildObjects(arg);
      BOOST_FOREACH(Udm::Object o, objects)
      {
        dispatch(o, CustomChildren());
      }
      return arg;
    }

  protected:
    // Called when ChildrenVector is non-empty. 
    template <class ChildrenVector>
    typename disable_if_c<empty<ChildrenVector>::value, void>::type 
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

template <class K,                                                                 
          class Strategy = KindLit<K>,                                             
          class Custom = Default>                                         
struct AllGraphOp : public AllOp<K, Strategy, Custom>
{
  typedef ChainExpr<K, AllGraphOp> expression_type;                         
  typedef AllOp<K, Strategy, Custom> Super;
  SUPER_TYPEDEFS(Super);
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));                  
                                                                                 
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
    typedef typename ChildrenKinds<Custom, argument_kind>::type CustomChildren;
    std::set<Udm::Object> objects = Custom::GetChildObjects(kind);
    BOOST_FOREACH(Udm::Object o, objects)
    {
      std::set<Udm::Object>::iterator iter = LEESA::VISITED.find(o);
      if (iter == LEESA::VISITED.end()) // visit if not visited already.
      {
        Super::dispatch(o, CustomChildren());
      }
    }
    return kind;
  }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTD);
    result_kind operator () (argument_kind const & arg)
    {
      typedef AllOp<K, FullTDOp, Custom> All;
      SeqOp<K, Strategy, All> s(strategy_, All(*this));
      s(arg);
      return arg;
    }
};

CLASS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTDGraph);
    result_kind operator () (argument_kind const & arg)
    {
      typedef AllGraphOp<K, FullTDGraphOp, Custom> AllGraph;
      SeqOp<K, Strategy, AllGraph> s(strategy_, AllGraph(*this));
      std::set<Udm::Object>::iterator iter = LEESA::VISITED.find(arg);
      if (iter == LEESA::VISITED.end()) // visit if not visited already.
      {
        LEESA::VISITED.insert(arg);
        s(arg);
      }
      return arg;
    }
};

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
      typedef KindLit<argument_kind> KIND_LIT;
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

class VisitStrategy : public _StrategyBase
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
      BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<Kind>));
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
	
	BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<result_kind, typename Func::argument_type>));
	
  return CallerOp<typename ET<E>::result_type, Func> (f);
}

template <class E, class Arg, class Result>
CallerOp<typename ET<E>::result_type, 
         std::pointer_to_unary_function<Arg, Result> > 
Call (E, Result (*f) (Arg))
{
	typedef typename ET<E>::result_kind result_kind;
	
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<result_kind>));
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
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));
  FailOp<typename ET<K>::argument_type> f;
  return f;
}  

template <class K>
KindLit<typename ET<K>::argument_kind>
Identity (K) 
{
  typedef typename ET<K>::argument_kind argument_kind;
  BOOST_CONCEPT_ASSERT((LEESA::UdmKindConcept<argument_kind>));
  KindLit<argument_kind> k;
  return k;
}  

FUNCTION_FOR_SP_OP_WITH_1STRATEGY(Try);        // choice (s, id)
FUNCTION_FOR_SP_OP_WITH_1STRATEGY(Repeat);     // try (sequence (s,repeat(s))
FUNCTION_FOR_SP_OP_WITH_1STRATEGY(RepeatLoop); // infinite loop while(true)

FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(Choice);
FUNCTION_FOR_SP_OP_WITH_2STRATEGIES(Seq);

FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(One);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(All);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(AllGraph);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullTDGraph);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(FullBU);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(OnceBU);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(StopTD);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(NaiveInnermost);
FUNCTIONS_FOR_SP_OP_WITH_CUSTOMIZABLE_STRATEGY(Innermost);




} // namespace LEESA


#endif // __SP_CPP

