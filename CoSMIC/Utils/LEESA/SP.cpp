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

template <class K, template <class> class Strategy> struct FullTDOp;
template <class K, template <class> class Strategy> struct AllOp;

template <class K, class Strategy>
struct ET <FullTDOp<K, Strategy> > 
	: public ETBase <FullTDOp<K, Strategy> > {};

template <class K, class Strategy>
struct ET <AllOp<K, Strategy> > 
	: public ETBase <AllOp<K, Strategy> > {};

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

template <class K, template <class> class Strategy = KindLit>
struct FullTDOp : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, FullTDOp> expression_type;  
	  typedef void result_kind;
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
    enum { MODEL_OR_FOLDER = 
      boost::is_same<typename K::MetaKind, Udm::ModelMetaTag>::value |
      boost::is_same<typename K::MetaKind, Udm::FolderMetaTag>::value };
    BOOST_MPL_ASSERT_RELATION(MODEL_OR_FOLDER, !=, 0);

    Strategy<K> strategy_;
    explicit FullTDOp (Strategy<K> const & s = Strategy<K>()) 
      : strategy_(s) {} 
    result_type operator () (argument_type const & arg)
    {
      //typename ContainerGen<argument_kind>::type v = arg;
		  //BOOST_FOREACH(argument_kind kind, v)
      //{
      //  strategy_(kind);
      //  children(kind, typename argument_kind::MetaKind());
      //}
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
        ForEach(head(), std::bind1st(std::mem_fun1(&FullTDOp::recurse<head>), this))));
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
      Strategy<Kind> s(strategy_);
      s(k);
      children(k, typename Kind::MetaKind());
    }
};


template <class K, template <class> class Strategy = KindLit>
struct AllOp : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, AllOp> expression_type;  
	  typedef void result_kind;
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
    enum { MODEL_OR_FOLDER = 
      boost::is_same<typename K::MetaKind, Udm::ModelMetaTag>::value |
      boost::is_same<typename K::MetaKind, Udm::FolderMetaTag>::value };
    BOOST_MPL_ASSERT_RELATION(MODEL_OR_FOLDER, !=, 0);

    Strategy<K> strategy_;
    explicit AllOp (Strategy<K> const & s = Strategy<K>())
      : strategy_(s) {} 
    result_type operator () (argument_type const & arg)
    {
      //typename ContainerGen<argument_kind>::type v = arg;
		  //BOOST_FOREACH(argument_kind kind, v)
      //{
      //  strategy_(kind);
      //  children(kind, typename argument_kind::MetaKind());
      //}
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
      typedef typename Intersection <Custom, Kind::ChildrenKinds>::type Members;
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
      //evaluate(kind, MembersOf(Kind(), head() >> 
      //  ForEach(head(), std::bind1st(std::mem_fun1(&AllOp::apply<head>), this))));
      evaluate(kind, MembersOf(K(), head() >> Call(head(), Strategy<head>(strategy_))));
      has_member <Kind> (kind, tail());
    }
    // Called when ChildrenVector is empty.
    template <class Kind>
    void has_member (Kind k, EmptyMPLVector)
    {
    }
    template <class Kind>
    void apply(Kind kind)
    {
      strategy_(kind);
    }
};

template <class Kind>
class VisitStrategy : public LEESAUnaryFunction<Kind>
{
  PARADIGM_NAMESPACE_FOR_LEESA::Visitor & visitor_;
  public:
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



/*
template <class K, class Strategy = IdStrategy>
struct FullTDOp : LEESAUnaryFunction <K>, OpBase
{
    typedef typename 
		  ChainExpr<K, FullTDOp> expression_type;  
	  typedef void result_kind;
	  typedef typename ET<K>::result_kind argument_kind;

    BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<argument_kind>));
    enum { MODEL_OR_FOLDER = 
      boost::is_same<typename K::MetaKind, Udm::ModelMetaTag>::value |
      boost::is_same<typename K::MetaKind, Udm::FolderMetaTag>::value };
    BOOST_MPL_ASSERT_RELATION(MODEL_OR_FOLDER, !=, 0);

    Strategy strategy_;
    explicit FullTDOp (Strategy const & s = IdStrategy()) 
      : strategy_(s) {} 
    result_type operator () (argument_type const & arg)
    {
      typename ContainerGen<argument_kind>::type v = arg;
		  BOOST_FOREACH(argument_kind kind, v)
      {
        strategy_(kind);
        children(kind, typename argument_kind::MetaKind());
      }
      return arg;
    }

  private:
    // Called when MetaTag is ModelMetaTag. 
    template <class Kind>
    void children (Kind kind, Udm::ModelMetaTag)
    {
      typedef typename FullTD_Custom::template ChildrenKinds<Kind>::type Custom;
      typedef typename Intersection <Custom, Kind::ChildrenKinds>::type Members;
      has_member <Kind> (kind, Members());
    }
    // Called when MetaTag is FolderMetaTag.
    template <class Kind>
    void children (Kind kind, Udm::FolderMetaTag)
    {
      typedef typename FullTD_Custom::template ChildrenKinds<Kind>::type Custom;
      typedef typename Intersection <Custom, Kind::ChildrenKinds>::type Members;
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
      typedef typename front<ChildrenVector>::type head;
      typedef typename pop_front<ChildrenVector>::type tail;
      evaluate(kind, MembersOf(Kind(), head() >> 
        ForEach(head(), std::bind1st(std::mem_fun1(&FullTDOp::recurse<head>), this))));
      has_member <Kind> (kind, tail());
    }
    // Called when ChildrenVector is empty. 
    template <class Kind>
    void has_member (Kind k, EmptyMPLVector)
    {
    }
    template <class Kind>
    void recurse(Kind k)
    {
      strategy_(k);
      children(k, typename Kind::MetaKind());
    }
};

*/