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
//typedef boost::mpl::vector0<boost::mpl::na> EmptyMPLVector;
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

struct LEESAException : public std::runtime_error
{
  LEESAException (const std::string &s = "")
    : std::runtime_error (std::string("LEESAException: ") + s) 
  {}
};

struct FullTD_Custom
{
  template <class T>
  struct ChildrenKinds
  {
    typedef typename T::ChildrenKinds type;
  };
};

struct All_Custom
{
  template <class T>
  struct ChildrenKinds
  {
    typedef typename T::ChildrenKinds type;
  };
};

template <class T, class Func> struct CallerOp;

template <class T, class U>
struct ET <CallerOp<T, U> > 
	: public ETBase <CallerOp<T, U> > {};

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

#define CALLER_OP CallerOp<K, Expr>
GT_PARA_OPERATOR_DEFINITION_3T(L,K,Expr,CALLER_OP);


template <class E, class Func>
CallerOp<typename ET<E>::result_type, Func> 
CallStrategy (E, Func f)
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<result_kind, typename Func::argument_type>));
	
  return CallerOp<typename ET<E>::result_type, Func> (f);
}

template <class E, class Arg, class Result>
CallerOp<typename ET<E>::result_type, 
         std::pointer_to_unary_function<Arg, Result> > 
CallStrategy (E, Result (*f) (Arg))
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
	
	CallerOp<typename ET<E>::result_type, 
           std::pointer_to_unary_function<Arg, Result> > 
		caller(std::ptr_fun(f));
	return caller;
}

template <class K, class Strategy = KindLit>
struct FullTD : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, FullTD> expression_type;  
	  typedef void result_kind;
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
    enum { MODEL_OR_FOLDER = 
      boost::is_same<typename K::MetaKind, Udm::ModelMetaTag>::value |
      boost::is_same<typename K::MetaKind, Udm::FolderMetaTag>::value };
    BOOST_MPL_ASSERT_RELATION(MODEL_OR_FOLDER, !=, 0);

    template <class U>
    struct rebind
    {
      typedef FullTD<U, typename Strategy::template rebind<U>::type > type;
    };

    Strategy strategy_;
    explicit FullTD (Strategy const & s) 
      : strategy_(s) {} 
    result_type operator () (argument_type const & arg)
    {
      strategy_(arg);
      children(arg, typename argument_kind::MetaKind());
      return arg;
    }

  private:
    /* Called when MetaTag is ModelMetaTag. */
    template <class Kind>
    void children (Kind kind, Udm::ModelMetaTag)
    {
      typedef typename ET<Kind>::argument_kind K;
      typedef typename FullTD_Custom::template ChildrenKinds<K>::type Custom;
      typedef typename Intersection <Custom, K::ChildrenKinds>::type Members;
      has_member <Kind> (kind, Members());
    }
    /* Called when MetaTag is FolderMetaTag. */
    template <class Kind>
    void children (Kind kind, Udm::FolderMetaTag)
    {
      typedef typename ET<Kind>::argument_kind K;
      typedef typename FullTD_Custom::template ChildrenKinds<K>::type Custom;
      typedef typename Intersection <Custom, K::ChildrenKinds>::type Members;
      has_member <Kind> (kind, Members());
    }
    /* Called when MetaTag is something other that Model, Folder. */
    template <class Kind>
    void children (Kind, Udm::MetaTagBase const &)
    {
    }
    /* Called when ChildrenVector is non-empty. */
    template <class Kind, class ChildrenVector>
    void has_member(Kind kind, ChildrenVector)
    {
      typedef typename front<ChildrenVector>::type head;
      typedef typename pop_front<ChildrenVector>::type tail;
      evaluate(kind, MembersOf(Kind(), head() >> 
        ForEach(head(), std::bind1st(std::mem_fun1(&FullTD::recurse<head>), this))));
      has_member <Kind> (kind, tail());
    }
    /* Called when ChildrenVector is empty. */
    template <class Kind>
    void has_member (Kind k, EmptyMPLVector)
    {
    }
    template <class Kind>
    void recurse(Kind k)
    {
      typename Strategy::template rebind<Kind>::type s(strategy_);
      s(k);
      children(k, typename Kind::MetaKind());
    }
};


template <class K, class Strategy = KindLit>
struct All : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, All> expression_type;  
	  typedef void result_kind;
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
    enum { MODEL_OR_FOLDER = 
      boost::is_same<typename K::MetaKind, Udm::ModelMetaTag>::value |
      boost::is_same<typename K::MetaKind, Udm::FolderMetaTag>::value };
    BOOST_MPL_ASSERT_RELATION(MODEL_OR_FOLDER, !=, 0);

    template <class U>
    struct rebind
    {
      typedef All<U, typename Strategy::template rebind<U>::type > type;
    };

    Strategy strategy_;
    explicit All (Strategy const & s)
      : strategy_(s) {} 
    result_type operator () (argument_type const & arg)
    {
      strategy_(arg);
      children(arg, typename argument_kind::MetaKind());
      return arg;
    }

  private:
    // Called when MetaTag is ModelMetaTag.
    template <class Kind>
    void children (Kind kind, Udm::ModelMetaTag)
    {
      typedef typename ET<Kind>::argument_kind K;
      typedef typename All_Custom::template ChildrenKinds<K>::type Custom;
      typedef typename Intersection <Custom, K::ChildrenKinds>::type Members;
      has_member <Kind> (kind, Members());
    }
    // Called when MetaTag is FolderMetaTag.
    template <class Kind>
    void children (Kind kind, Udm::FolderMetaTag)
    {
      typedef typename ET<Kind>::argument_kind K;
      typedef typename All_Custom::template ChildrenKinds<K>::type Custom;
      typedef typename Intersection <Custom, K::ChildrenKinds>::type Members;
      has_member <Kind> (kind, Members());
    }
    // Called when MetaTag is something other that Model, Folder.
    template <class Kind>
    void children (Kind, Udm::MetaTagBase const &)
    {
    }
    // Called when ChildrenVector is non-empty. 
    template <class Kind, class ChildrenVector>
    void has_member(Kind kind, ChildrenVector)
    {
      typedef typename ET<Kind>::argument_kind K;
      typedef typename front<ChildrenVector>::type head;
      typedef typename pop_front<ChildrenVector>::type tail;
      typename Strategy::template rebind<head>::type s(strategy_);
      evaluate(kind, MembersOf(K(), head() >> Call(head(), s)));
      has_member <Kind> (kind, tail());
    }
    // Called when ChildrenVector is empty.
    template <class Kind>
    void has_member (Kind k, EmptyMPLVector)
    {
    }
};

template <class K, class Strategy = KindLit>
struct One : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, One> expression_type;  
	  typedef void result_kind;
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
    enum { MODEL_OR_FOLDER = 
      boost::is_same<typename K::MetaKind, Udm::ModelMetaTag>::value |
      boost::is_same<typename K::MetaKind, Udm::FolderMetaTag>::value };
    BOOST_MPL_ASSERT_RELATION(MODEL_OR_FOLDER, !=, 0);

    template <class U>
    struct rebind
    {
      typedef One<U, typename Strategy::template rebind<U>::type > type;
    };

    Strategy strategy_;
    explicit One (Strategy const & s)
      : strategy_(s) {} 
    result_type operator () (argument_type const & arg)
    {
      try {
        strategy_(arg);
      }
      catch(...) {
        children(arg, typename argument_kind::MetaKind());
      }
      return arg;
    }

  private:
    // Called when MetaTag is ModelMetaTag.
    template <class Kind>
    void children (Kind kind, Udm::ModelMetaTag)
    {
      typedef typename ET<Kind>::argument_kind K;
      typedef typename All_Custom::template ChildrenKinds<K>::type Custom;
      typedef typename Intersection <Custom, K::ChildrenKinds>::type Members;
      has_member <Kind> (kind, Members());
    }
    // Called when MetaTag is FolderMetaTag.
    template <class Kind>
    void children (Kind kind, Udm::FolderMetaTag)
    {
      typedef typename ET<Kind>::argument_kind K;
      typedef typename All_Custom::template ChildrenKinds<K>::type Custom;
      typedef typename Intersection <Custom, K::ChildrenKinds>::type Members;
      has_member <Kind> (kind, Members());
    }
    // Called when MetaTag is something other that Model, Folder.
    template <class Kind>
    void children (Kind, Udm::MetaTagBase const &)
    {
    }
    // Called when ChildrenVector is non-empty. 
    template <class Kind, class ChildrenVector>
    void has_member(Kind kind, ChildrenVector)
    {
      typedef typename ET<Kind>::argument_kind K;
      typedef typename front<ChildrenVector>::type head;
      typedef typename pop_front<ChildrenVector>::type tail;
      typename Strategy::template rebind<head>::type s(strategy_);
      try {
        evaluate(kind, MembersOf(K(), head() >> Call(head(), s)));
      }
      catch (...) {
        has_member <Kind> (kind, tail());
      }
    }
    // Called when ChildrenVector is empty.
    template <class Kind>
    void has_member (Kind k, EmptyMPLVector)
    {
    }
};

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

template <class Kind>
class Fail : public LEESAUnaryFunction<Kind>
{
  public:
    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));

    template <class U>
    struct rebind
    {
      typedef Fail<U> type;
    };

    explicit Fail (){}

    template <class U>
    explicit Fail (Fail<U> const &) {}

    result_type operator ()(argument_type k)
    {
      throw LEESA::LEESAException();      
      return k;
    }
};

template <class Kind>
class VisitStrategy : public LEESAUnaryFunction<Kind>
{
    PARADIGM_NAMESPACE_FOR_LEESA::Visitor & visitor_;
  public:

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));

    template <class U>
    struct rebind
    {
      typedef VisitStrategy<U> type;
    };
  
    template <class U>
    explicit VisitStrategy (VisitStrategy<U> const & vs) 
      : visitor_(vs.getVisitor()) {} 
    explicit VisitStrategy (PARADIGM_NAMESPACE_FOR_LEESA::Visitor & v) 
      : visitor_(v) {} 

    void operator ()(argument_type k)
    {
      using namespace LEESA;
      evaluate(k, Kind() >> visitor_);
    }
    PARADIGM_NAMESPACE_FOR_LEESA::Visitor & getVisitor() const
    {
      return visitor_;
    }
};

} // namespace LEESA


#endif // __SP_CPP

