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

#define FUNCTION_FOR_SP_OP(OP)                                      \
  template <class X, class Y, class Z>                              \
  OP##Op<X, Y, Z>                                                   \
  OP (X, Y const & y, Z) {                                          \
	typedef typename ET<X>::argument_kind argument_kind;            \
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));     \
    return OP##Op<X, Y, Z> (y);                                     \
  }                                                                 \
  template <class X, class Y>                                       \
  OP##Op<X, Y, AllChildrenKinds>                                    \
  OP (X, Y const & y)  {                                            \
	typedef typename ET<X>::argument_kind argument_kind;            \
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));     \
    return OP##Op<X, Y, AllChildrenKinds> (y);                      \
  }




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
template <class X, class Y, class Z> struct OneOp;
template <class X, class Y, class Z> struct AllOp;
template <class X, class Y, class Z> struct FullTDOp;

template <class T, class U>
struct ET <CallerOp<T, U> > 
	: public ETBase <CallerOp<T, U> > {};

template <class X, class Y, class Z>
struct ET <OneOp<X, Y, Z> > 
	: public ETBase <OneOp<X, Y, Z> > {};

template <class X, class Y, class Z>
struct ET <AllOp<X, Y, Z> > 
	: public ETBase <AllOp<X, Y, Z> > {};

template <class X, class Y, class Z>
struct ET <FullTDOp<X, Y, Z> > 
	: public ETBase <FullTDOp<X, Y, Z> > {};

template <class E, class Func>
struct CallerOp : LEESAUnaryFunction <E>, OpBase
{
	typedef typename 
		ChainExpr<E, CallerOp > expression_type;

	Func func_;
	explicit CallerOp (Func f) : func_(f) { }
	CallerOp (CallerOp const & fop) : func_(fop.func_) {}
	result_type operator () (argument_type const & arg)
	{
    func_(arg);
		return arg;
	}
};



template <class K, class Strategy = KindLit<K>, class Custom = AllChildrenKinds>
struct OneOp : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, OneOp> expression_type;  
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));

    template <class U>
    struct rebind
    {
      typedef OneOp<U, typename Strategy::template rebind<U>::type, Custom > type;
    };

    Strategy strategy_;
    bool success_;

    explicit OneOp (Strategy const & s)
      : strategy_(s), success_(false) {} 

    template <class X, class Y, class Z>
    explicit OneOp (OneOp <X, Y, Z> const & o)
      : strategy_(o.strategy_)
    {}

    result_type operator () (argument_type const & arg)
    {
      if (!arg.isEmpty())
      {
        typedef typename Custom::template 
          ChildrenKinds<argument_kind>::type CustomChildren;
        typedef typename Intersection <CustomChildren, K::ChildrenKinds>::type 
          CommonChildrenTypes;
        
        success_ = false;
        children(arg, CommonChildrenTypes());
        if(!success_) throw LEESAException<argument_type>();
      }
      else
        throw LEESAException<argument_type>();
      return arg;
    }

  private:
    // Called when ChildrenVector is non-empty. 
    template <class KindLit, class ChildrenVector>
    void children(KindLit arg, ChildrenVector)
    {
      typedef typename ET<KindLit>::argument_kind K;
      typedef typename front<ChildrenVector>::type head;
      typedef typename pop_front<ChildrenVector>::type tail;
      typename Strategy::template rebind<head>::type s(strategy_);
      typedef typename ContainerGen<head>::type HeadVector;
      HeadVector head_vector = evaluate (arg, K() >> head());
      for (HeadVector::iterator iter = head_vector.begin();
           iter != head_vector.end() && !success_;)
      {
        try {
          s(*iter);
          success_ = true;
          break;
        }
        catch (...) {
          ++iter;
        }
      }
      if (!success_)
        children(arg, tail());
    }
    // Called when ChildrenVector is empty.
    template <class KindLit>
    void children(KindLit const & arg, EmptyMPLVector)
    {
    }
};

template <class K, class Strategy = KindLit<K>, class Custom = AllChildrenKinds>
struct AllOp : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, AllOp> expression_type;  
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));

    template <class U>
    struct rebind
    {
      typedef AllOp<U, typename Strategy::template rebind<U>::type, Custom> type;
    };

    Strategy strategy_;
    explicit AllOp (Strategy const & s)
      : strategy_(s) {} 

    template <class X, class Y, class Z>
    explicit AllOp (AllOp <X, Y, Z> const & a)
      : strategy_(a.strategy_)
    {}

    result_type operator () (argument_type const & arg)
    {
      if (!arg.isEmpty())
      {
        typedef typename Custom::template 
          ChildrenKinds<argument_kind>::type CustomChildren;
        typedef typename Intersection <CustomChildren, K::ChildrenKinds>::type 
          CommonChildrenTypes;
        children(arg, CommonChildrenTypes());
      }
      return arg;
    }

  private:
    // Called when ChildrenVector is non-empty. 
    template <class KindLit, class ChildrenVector>
    void children(KindLit arg, ChildrenVector)
    {
      typedef typename ET<KindLit>::argument_kind K;
      typedef typename front<ChildrenVector>::type head;
      typedef typename pop_front<ChildrenVector>::type tail;
      typedef typename Strategy::template rebind<head>::type HeadStrategy;
      HeadStrategy hs(strategy_);
      //hs(evaluate(arg, K() >> head()));
      typedef GetChildrenOp<KindLit, typename ET<head>::argument_type > GC;
      GC gc;
      ChainExpr<KindLit, GC> c(KindLit(), gc);
      hs(evaluate(arg, c));
      children(arg, tail());
    }
    // Called when ChildrenVector is empty as in EmptyMPLVector.
    template <class KindLit>
    void children(KindLit, EmptyMPLVector)
    {
    }
    // Called when ChildrenVector is empty as in EmptyMPLVectorB.
    template <class KindLit>
    void children(KindLit, EmptyMPLVectorB)
    {
    }
};

template <class K, class Strategy, class Custom = AllChildrenKinds>
struct FullTDOp : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, FullTDOp> expression_type;  
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));

    template <class U>
    struct rebind
    {
      typedef FullTDOp<U, typename Strategy::template rebind<U>::type, Custom> type;
    };

    Strategy strategy_;

    template <class X, class Y, class Z>
    explicit FullTDOp (FullTDOp<X, Y, Z> const & f)
      : strategy_(f.strategy_)
    {}

    explicit FullTDOp (Strategy const & s) 
      : strategy_(s) {} 

    result_type operator () (argument_type const & arg)
    {
      if (!arg.isEmpty())
      {
        strategy_(arg);
        AllOp<K, FullTDOp, Custom> all(*this);
        all(arg);
      }
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

FUNCTION_FOR_SP_OP(One);
FUNCTION_FOR_SP_OP(All);
FUNCTION_FOR_SP_OP(FullTD);


} // namespace LEESA


#endif // __SP_CPP


/*
template <class Kind, 
          class Strategy1 = KindLit<Kind>, 
          class Strategy2 = KindLit<Kind> >
class Choice : public LEESAUnaryFunction<Kind>
{
  public:
    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
    BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<argument_kind,
                                                   Strategy1::argument_kind>));
    BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<argument_kind,
                                                   Strategy2::argument_kind>));
    
    template <class U>
    struct rebind
    {
      typedef Choice<U, 
        typename Strategy1::template rebind<U>::type, 
        typename Strategy2::template rebind<U>::type> type;
    };

    Strategy1 strategy1_;
    Strategy2 strategy2_;

    explicit Choice (Strategy1 const & s1,
                     Strategy2 const & s2)
      : strategy1_(s1), 
        strategy2_(s2) {}
    
    template <class X, class Y, class Z>
    explicit Choice (Choice <X, Y, Z> const & c)
      : strategy1_(c.strategy1_), 
        strategy2_(c.strategy2_)
    {}
    result_type operator ()(argument_type k)
    {
      using namespace LEESA;
      try {
        evaluate(k, Call(Kind(), strategy1_));
      }
      catch (...) {
        evaluate(k, Call(Kind(), strategy2_));
      }
      return k;
    }
};

*/

/*
template <class Kind, 
          class Strategy1 = KindLit<Kind>, 
          class Strategy2 = KindLit<Kind> >
class Sequence : public LEESAUnaryFunction<Kind>
{
  public:
    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
    BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<argument_kind,
                                                   Strategy1::argument_kind>));
    BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<argument_kind,
                                                   Strategy2::argument_kind>));
    
    template <class U>
    struct rebind
    {
      typedef Sequence<U, 
        typename Strategy1::template rebind<U>::type, 
        typename Strategy2::template rebind<U>::type> type;
    };

    Strategy1 strategy1_;
    Strategy2 strategy2_;

    explicit Sequence (Strategy1 const & s1,
                       Strategy2 const & s2)
      : strategy1_(s1), 
        strategy2_(s2) 
    {}
    
    template <class X, class Y, class Z>
    explicit Sequence (Sequence <X, Y, Z> const & c)
      : strategy1_(c.strategy1_), 
        strategy2_(c.strategy2_)
    {}
    result_type operator ()(argument_type k)
    {
      using namespace LEESA;
      evaluate(k, Call(Kind(), strategy1_));
      evaluate(k, Call(Kind(), strategy2_));
      return k;
    }
};
*/
