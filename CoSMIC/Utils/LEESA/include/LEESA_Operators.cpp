#include <boost/regex.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/type_traits/add_reference.hpp>

namespace LEESA {

class OpBase {}; // Base of all the operators

template <class LExpr, class RExpr>
struct DFSOp : LEESAUnaryFunction <typename ET<LExpr>::result_type, 
                                   typename ET<RExpr>::argument_type>,
               OpBase
{
  typedef LEESAUnaryFunction <typename ET<LExpr>::result_type, 
                              typename ET<RExpr>::argument_type> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<LExpr, DFSOp<LExpr, RExpr> > expression_type;
  typedef typename ET<LExpr>::result_kind LKind;
  typedef typename ET<RExpr>::argument_kind RKind;

  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<LKind, RKind>));

  RExpr expr_;
  
  explicit DFSOp () {}
  
  explicit DFSOp (RExpr const & e) : expr_(e) {}

  DFSOp (DFSOp const &d) : expr_(d.expr_) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    std::for_each(v.begin(), v.end(), expr_);
    return arg;
  }
};

template <class E>
struct SelectorOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESA::LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, SelectorOp> expression_type;
  typedef typename KindTraits<argument_kind>::Container Container;

  Container c_;
  bool logical_not_; 
  
  explicit SelectorOp (argument_type const & kl, bool logical_not = false) 
    : c_(kl), logical_not_(logical_not) {}
  
  explicit SelectorOp (Container const & c, bool logical_not = false) 
    : c_(c), logical_not_(logical_not) {}
  
  // Iterator-pair idiom
  template <class Iter>
  explicit SelectorOp (Iter begin, Iter end, bool logical_not = false) 
    : c_(begin, end), logical_not_(logical_not) {}
  
  SelectorOp (SelectorOp const & sop) 
    : logical_not_(sop.logical_not_), c_(sop.c_) {}
  
  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      typename KindTraits<argument_kind>::Container::iterator i = 
        std::find(c_.begin(), c_.end(), kind);
      if ((i != c_.end()) ^ logical_not_) // Logical not of match, if required
        retval.push_back(kind);
    }
    return retval;
  }
  SelectorOp operator ! () const
  {
    SelectorOp selector(*this);
    selector.logical_not_ = !this->logical_not_;
    return selector;
  }
};

template <class L, class H>
struct GetChildrenOp :
  LEESAUnaryFunction <typename ET<L>::result_type,
                      typename ET<H>::argument_type>, OpBase
{
  typedef LEESA::LEESAUnaryFunction<typename ET<L>::result_type, 
                                    typename ET<H>::argument_type> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, GetChildrenOp> expression_type;

  H expr_;
  
  explicit GetChildrenOp (H const & h) : expr_(h) {}

  GetChildrenOp (GetChildrenOp const &g) : expr_(g.expr_) {}

  result_type operator () (argument_type const & arg)
  {
    BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<argument_kind, result_kind>));
    /* Do not refactor this code with the function below, even though the
     * refactoing of the loop is obvious. The carrier data structure is
     * optimized for this loop and can't beat its performance. Only rvalue
     * reference can beat it.
     * */
    result_type retval;
    BOOST_FOREACH(argument_kind & kind, arg)
    {
      result_type temp;
#ifdef LEESA_FOR_UDM
      temp.push_back(kind.template children_kind<result_kind>());
#else
      temp.push_back(children_kind (kind, static_cast<result_kind *>(0)));
#endif // LEESA_FOR_UDM
      dispatch_depth_first(temp, expr_);
      /* NOTE: move semantics here. Similar to std::list<T>::splice. */
      retval.move_carrier(temp);
    }
    return retval;
  }

  result_type operator () (argument_kind const & kind)
  {
    BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<argument_kind, result_kind>));

    result_type retval;
#ifdef LEESA_FOR_UDM
    retval.push_back(kind.template children_kind<result_kind>());
#else
    retval.push_back(children_kind (kind, static_cast<result_kind *>(0)));
#endif // LEESA_FOR_UDM
    dispatch_depth_first(retval, expr_);
    return retval;
  }

#ifdef __GXX_EXPERIMENTAL_CXX0X__  
  result_type operator () (argument_type && arg)
  {
    BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<argument_kind, result_kind>));

    result_type retval;
    BOOST_FOREACH(argument_kind & kind, arg)
    {
      result_type temp(children_kind (kind, static_cast<result_kind *>(0)));
      dispatch_depth_first(temp, expr_);
      retval.push_back(temp);
    }
    return retval;
  }
#endif // __GXX_EXPERIMENTAL_CXX0X__  

  template <class Left, class Right>
  void dispatch_depth_first(result_type & r, ChainExpr<Left, Right> & expr)
  {
    // If expr_ is a ChainExpr, that means some non-trivial depth-first expression
    // is present, which must be executed one object at a time.
    std::for_each(r.begin(), r.end(), expr);
  }
  void dispatch_depth_first(result_type & c, typename ET<H>::argument_type &)
  { 
    // If expr_ is a Carrier, it is basically a no-op.
  }
};

template <class E>
struct StoreAtOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, StoreAtOp<argument_type> > expression_type;

  typedef typename KindTraits<argument_kind>::Container Container;
  Container & store_;

  StoreAtOp (Container & c) 
    : store_ (c) {}
  
  StoreAtOp (const StoreAtOp & sop) : store_(sop.store_) { }
  
  result_type operator () (argument_type const & arg)
  {
    store_ = arg;
  }
  
#ifdef __GXX_EXPERIMENTAL_CXX0X__  
  result_type operator () (argument_type && arg)
  {
    store_ = std::move(arg);
  }
#endif // __GXX_EXPERIMENTAL_CXX0X__  
};

#ifndef LEESA_NO_VISITOR

template <class E>
struct VisitorOp : LEESAUnaryFunction <E>,
                   OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, VisitorOp<argument_type> > expression_type;

  SchemaVisitor & visitor_;

  VisitorOp (SchemaVisitor const &v) 
    : visitor_ (const_cast<SchemaVisitor &> (v)) {}
  
  VisitorOp (const VisitorOp & vop) : visitor_ (vop.visitor_) {}
  
  result_type operator () (argument_type const & arg)
  {
    BOOST_FOREACH(argument_kind & kind, arg)
    {
#ifdef LEESA_FOR_UDM      
      kind.Accept(visitor_);
#else
      kind.accept(visitor_);
#endif // LEESA_FOR_UDM
    }
    return arg;
  }
  
#ifdef __GXX_EXPERIMENTAL_CXX0X__  
  result_type operator () (argument_type && arg)
  {
    BOOST_FOREACH(argument_kind & kind, arg)
    {
      kind.accept(visitor_);
    }
    return std::move(arg);
  }
#endif // __GXX_EXPERIMENTAL_CXX0X__  
};

template <class E>
struct LeaveCallerOp : LEESAUnaryFunction <E>,
                        OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, LeaveCallerOp> expression_type;

  SchemaVisitor & visitor_;

  LeaveCallerOp (SchemaVisitor const &v) 
    : visitor_ (const_cast<SchemaVisitor &> (v)) {}
  
  LeaveCallerOp (const LeaveCallerOp & vop) : visitor_ (vop.visitor_) {}
  
  result_type operator () (argument_type const & arg)
  {
    BOOST_FOREACH(argument_kind & kind, arg)
    {
#ifdef LEESA_FOR_UDM      
      kind.Leave(visitor_);
#else
      kind.leave(visitor_);
#endif // LEESA_FOR_UDM
    }
    return arg;
  }
  
#ifdef __GXX_EXPERIMENTAL_CXX0X__  
  result_type operator () (argument_type && arg)
  {
    BOOST_FOREACH(argument_kind & kind, arg)
    {
      kind.leave(visitor_);
    }
    return std::move(arg);
  }
#endif // __GXX_EXPERIMENTAL_CXX0X__  
};

template <class E, class Func = E>
struct PairCallerOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, PairCallerOp> expression_type;

  SchemaVisitor & visitor_;
  Func func_;

  PairCallerOp (SchemaVisitor const &v, Func f = Func()) 
    : visitor_ (const_cast<SchemaVisitor &> (v)),
      func_(f)
  {}
  
  PairCallerOp (const PairCallerOp & vop) 
    : visitor_ (vop.visitor_),
      func_(vop.func_)
  {}
  
  result_type operator () (argument_type const & arg)
  {
    BOOST_FOREACH(argument_kind & kind, arg)
    {
#ifdef LEESA_FOR_UDM      
      kind.Accept(visitor_);
      func_(kind);
      kind.Leave(visitor_);
#else
      kind.accept(visitor_);
      func_(kind);
      kind.leave(visitor_);
#endif // LEESA_FOR_UDM
    }
    return arg;
  }
  
#ifdef __GXX_EXPERIMENTAL_CXX0X__  
  result_type operator () (argument_type && arg)
  {
    BOOST_FOREACH(argument_kind & kind, arg)
    {
      kind.accept(visitor_);
      func_(kind);
      kind.leave(visitor_);
    }
    return std::move(arg);
  }
#endif // __GXX_EXPERIMENTAL_CXX0X__  
};

#endif // LEESA_NO_VISITOR

template <class E>
struct RegexOp : LEESAUnaryFunction <E>,
                 OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, RegexOp<argument_type> > expression_type;

  boost::regex regex_;
  //std::string regex_;
  bool logical_not_; 
  
  explicit RegexOp (std::string const & str = ".*", bool logical_not = false) 
    : regex_(str), logical_not_ (logical_not) {  }
  
  RegexOp (RegexOp const & reop) 
    : logical_not_ (reop.logical_not_), regex_ (reop.regex_) {}
  
  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      bool match = boost::regex_match(std::string(kind.name()), regex_);
      //bool match = (regex_ == std::string(kind.name()));
      if (match ^ logical_not_) // Logical not of match, if required
        retval.push_back(kind);
    }
    return retval;
  }
  RegexOp operator ! () 
  {
    RegexOp r(*this);
    r.logical_not_ = !this->logical_not_;
    return r;
  }
};

template <class L, class H>
struct CastOp : LEESAUnaryFunction <L, H>, OpBase
{
  typedef LEESAUnaryFunction <L, H> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, CastOp<argument_type, result_type> > expression_type;

  explicit CastOp () {}

  explicit CastOp (H) {} // dummy

  CastOp (CastOp const &) {}

#ifdef LEESA_FOR_UDM

  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    BOOST_FOREACH(argument_kind kind, arg)
    {
      if (Udm::IsDerivedFrom (kind.type(), result_kind::meta))
      {
        result_kind r = result_kind::Cast(kind);
        retval.push_back(r);
      }
    }
    return retval;
  }

#else

  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    for(typename argument_type::const_iterator iter(arg.begin());
        iter != arg.end();
        ++iter)
    {
      if (const result_kind * r = dynamic_cast<const result_kind *> (&*iter))
      {
        retval.push_back(*r);
      }
    }
    return retval;
  }
#endif  // LEESA_FOR_UDM
};

#ifdef LEESA_FOR_UDM

template <class E>
struct NonNullOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, NonNullOp<argument_type> > expression_type;

  bool logical_not_; 
  
  explicit NonNullOp (bool logical_not = false) 
    : logical_not_ (logical_not) {  }
  
  NonNullOp (NonNullOp const & nnop) 
    : logical_not_ (nnop.logical_not_) {}
  
  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename KindTraits<argument_kind>::Container c = arg;
    BOOST_FOREACH(argument_kind kind, c)
    {
      bool match = (Udm::null != kind);
      if (match ^ logical_not_) // Logical not of match, if required
        retval.push_back(kind);
    }
    return retval;
  }
  NonNullOp operator ! () 
  {
    NonNullOp n(*this);
    n.logical_not_ = !this->logical_not_;
    return n;
  }
};

template <class L, class H>
struct GetParentOp :
  LEESAUnaryFunction <typename ET<L>::result_type,
                      typename ET<H>::argument_type>, OpBase
{
  typedef LEESAUnaryFunction <typename ET<L>::result_type,
                              typename ET<H>::argument_type> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, GetParentOp> expression_type;

  H expr_;
  
  GetParentOp (H const & h) : expr_(h) {}

  GetParentOp (GetParentOp const & g) : expr_(g.expr_) {}
  
  result_type operator () (argument_type const & arg)
  {
    BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<result_kind, argument_kind>));

    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      result_kind parent = kind.template parent_kind<result_kind>();
      if (std::count (retval.begin(), retval.end(), parent) == 0)
      {
        retval.push_back(parent);
        dispatch_depth_first(parent, expr_);
      }
    }
    return retval;
  }
  template <class Left, class Right>
  void dispatch_depth_first(result_kind const & c, ChainExpr<Left, Right> & expr)
  {
    // If expr_ is a ChainExpr, that means some non-trivial depth-first expression
    // is present, which must be executed.
    expr(c);
  }
  void dispatch_depth_first(result_kind const &, typename ET<H>::argument_type const &)
  { 
    // If expr_ is a Carrier, it is basically a no-op.
  }
};

template <class RESULT, class TARGETCLASS>
struct AssociationOp : LEESAUnaryFunction <TARGETCLASS, RESULT>,
                       OpBase
{
  typedef LEESAUnaryFunction <TARGETCLASS, RESULT> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<RESULT, AssociationOp<RESULT, TARGETCLASS> > 
      expression_type;

  typedef Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*FUNC)() const;
  FUNC func_;

  explicit AssociationOp (FUNC f) : func_(f) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    result_type retval;
    BOOST_FOREACH(argument_kind kind, v)
    {
      result_kind r = (kind.*func_)();
      if (r != Udm::null) // This check is important. Don't remove.
        retval.push_back(r);
    }
    return retval;
  }
};

template <class ASSOC, class SOURCECLASS, class TARGETCLASS>
struct AssociationManyOp : LEESAUnaryFunction <SOURCECLASS,ASSOC>, OpBase
{
  typedef LEESAUnaryFunction <SOURCECLASS, ASSOC> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<ASSOC, AssociationManyOp> expression_type;

  typedef Udm::AClassAssocAttr<ASSOC, TARGETCLASS> (SOURCECLASS::*FUNC)() const;
  FUNC func_;

  explicit AssociationManyOp (FUNC f) : func_(f) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    result_type retval;
    BOOST_FOREACH(argument_kind kind, v)
    {
      retval.push_back((kind.*func_)());
    }
    return retval;
  }
};

template <class RESULT, class TARGETCLASS>
struct AssociationEndOp : LEESAUnaryFunction <TARGETCLASS,RESULT>,
                          OpBase
{
  typedef LEESAUnaryFunction <TARGETCLASS, RESULT> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<RESULT, AssociationEndOp<RESULT, TARGETCLASS> >
      expression_type;

  typedef Udm::AssocEndAttr<RESULT> (TARGETCLASS::*FUNC)() const;
  FUNC func_;

  explicit AssociationEndOp (FUNC f) : func_(f) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    result_type retval;
    BOOST_FOREACH(argument_kind kind, v)
    {
      result_kind r = (kind.*func_)();
      if (r != Udm::null) // This check is important. Don't remove.
        retval.push_back(r);
    }
    return retval;
  }
};

#endif // LEESA_FOR_UDM

#ifndef LEESA_FOR_UDM

template <class Kind, class Tuple>
struct Concept_Violation_If_Not_Child
{
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<Kind, typename Tuple::head_type>));  
  typedef typename Concept_Violation_If_Not_Child<Kind, typename Tuple::tail_type>::type type;
};

template <class Kind>
struct Concept_Violation_If_Not_Child<Kind, boost::tuples::null_type>
{ 
  typedef typename boost::tuples::null_type type;
};


template <class Tuple> struct AddPointerTuple;

template <class A>
struct AddPointerTuple <boost::tuples::tuple<A> > {
  typedef boost::tuples::tuple<typename boost::add_pointer<A>::type> type;
};

template <class A, class B>
struct AddPointerTuple <boost::tuples::tuple<A, B> > {
  typedef boost::tuples::tuple<typename boost::add_pointer<A>::type, 
                               typename boost::add_pointer<B>::type> type;
};

template <class A, class B, class C>
struct AddPointerTuple <boost::tuples::tuple<A, B, C> > {
  typedef boost::tuples::tuple<typename boost::add_pointer<A>::type, 
                               typename boost::add_pointer<B>::type,
                               typename boost::add_pointer<C>::type> type;
};

template <class A, class B, class C, class D>
struct AddPointerTuple <boost::tuples::tuple<A, B, C, D> > {
  typedef boost::tuples::tuple<typename boost::add_pointer<A>::type, 
                               typename boost::add_pointer<B>::type,
                               typename boost::add_pointer<C>::type,
                               typename boost::add_pointer<D>::type> type;
};

template <class A, class B, class C, class D, class E>
struct AddPointerTuple <boost::tuples::tuple<A, B, C, D, E> > {
  typedef boost::tuples::tuple<typename boost::add_pointer<A>::type, 
                               typename boost::add_pointer<B>::type,
                               typename boost::add_pointer<C>::type,
                               typename boost::add_pointer<D>::type,
                               typename boost::add_pointer<E>::type> type;
};

template <class A, class B, class C, class D, class E, class F>
struct AddPointerTuple <boost::tuples::tuple<A, B, C, D, E, F> > {
  typedef boost::tuples::tuple<typename boost::add_pointer<A>::type, 
                               typename boost::add_pointer<B>::type,
                               typename boost::add_pointer<C>::type,
                               typename boost::add_pointer<D>::type,
                               typename boost::add_pointer<E>::type,
                               typename boost::add_pointer<F>::type> type;
};

template <class Tuple> struct RemovePointerIfAnyTuple;

template <class A>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A> > {
  typedef boost::tuples::tuple<A> type;
};
template <class A>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A *> > {
  typedef typename RemovePointerIfAnyTuple<boost::tuples::tuple<A> >::type type;
};

template <class A, class B>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A, B> > {
  typedef boost::tuples::tuple<typename boost::remove_pointer<A>::type, 
                               typename boost::remove_pointer<B>::type> type;
};
template <class A, class B>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A *, B *> > {
  typedef typename RemovePointerIfAnyTuple<boost::tuples::tuple<A, B> >::type type;
};

template <class A, class B, class C>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A, B, C> > {
  typedef boost::tuples::tuple<typename boost::remove_pointer<A>::type, 
                               typename boost::remove_pointer<B>::type,
                               typename boost::remove_pointer<C>::type> type;
};
template <class A, class B, class C>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A *, B *, C *> > {
  typedef typename RemovePointerIfAnyTuple<boost::tuples::tuple<A, B, C> >::type type;
};

template <class A, class B, class C, class D>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A, B, C, D> > {
  typedef boost::tuples::tuple<typename boost::remove_pointer<A>::type, 
                               typename boost::remove_pointer<B>::type,
                               typename boost::remove_pointer<C>::type,
                               typename boost::remove_pointer<D>::type> type;
};
template <class A, class B, class C, class D>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A *, B *, C *, D *> > {
  typedef typename RemovePointerIfAnyTuple<boost::tuples::tuple<A, B, C, D> >::type type;
};

template <class A, class B, class C, class D, class E>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A, B, C, D, E> > {
  typedef boost::tuples::tuple<typename boost::remove_pointer<A>::type, 
                               typename boost::remove_pointer<B>::type,
                               typename boost::remove_pointer<C>::type,
                               typename boost::remove_pointer<D>::type,
                               typename boost::remove_pointer<E>::type> type;
};
template <class A, class B, class C, class D, class E>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A *, B *, C *, D *, E *> > {
  typedef typename RemovePointerIfAnyTuple<boost::tuples::tuple<A, B, C, D, E> >::type type;
};

template <class A, class B, class C, class D, class E, class F>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A, B, C, D, E, F> > {
  typedef boost::tuples::tuple<typename boost::remove_pointer<A>::type, 
                               typename boost::remove_pointer<B>::type,
                               typename boost::remove_pointer<C>::type,
                               typename boost::remove_pointer<D>::type,
                               typename boost::remove_pointer<E>::type,
                               typename boost::remove_pointer<F>::type> type;
};
template <class A, class B, class C, class D, class E, class F>
struct RemovePointerIfAnyTuple <boost::tuples::tuple<A *, B *, C *, D *, E *, F *> > {
  typedef typename RemovePointerIfAnyTuple<boost::tuples::tuple<A, B, C, D, E, F> >::type type;
};


template <class OrigTuple,
          class ShrinkingTuple = OrigTuple,
          unsigned int TUPLE_INDEX = 0,          
          unsigned int TUPLE_LENGTH = boost::tuples::length<OrigTuple>::value>
struct Transposer
          : Transposer <OrigTuple, 
                         typename ShrinkingTuple::tail_type, 
                         TUPLE_INDEX + 1, 
                         TUPLE_LENGTH - 1>
{
  typedef Transposer <OrigTuple, 
                       typename ShrinkingTuple::tail_type, 
                       TUPLE_INDEX + 1, 
                       TUPLE_LENGTH - 1> super;

  typedef typename ShrinkingTuple::head_type Head;
  typedef Carrier<Head> HeadCarrier;
  typedef typename AddPointerTuple<OrigTuple>::type PointerTuple;
  typedef std::vector<PointerTuple> Transpose;

  using super::add;

  void add (HeadCarrier const & hc)
  {
    this->head_carrier_ = hc;
    this->node_iter_ = this->head_carrier_.begin_node_iterator();
  }

  Transpose get_transpose ()
  {
    Transpose tran;
    tran.reserve(head_carrier_.size());
    while(node_iter_ != head_carrier_.end_node_iterator())
    {
      PointerTuple t;
      this->populate_tuple(t);
      tran.push_back(t);
    }
    return tran;
  }

  private:
  HeadCarrier head_carrier_;
  NodeIterator<Head> node_iter_;

  protected:
  void populate_tuple(PointerTuple & t)
  {
    if(node_iter_ != head_carrier_.end_node_iterator())
    {
      boost::tuples::get<TUPLE_INDEX>(t) = node_iter_.get();
      node_iter_.next();
    }

    super::populate_tuple (t);
  }
};

template <class OrigTuple, class ShrinkingTuple, unsigned int TUPLE_INDEX>
struct Transposer <OrigTuple, ShrinkingTuple, TUPLE_INDEX, 0 /* TUPLE_LENGTH */ >
{
  typedef typename AddPointerTuple<OrigTuple>::type PointerTuple;
  void add (void);
  void populate_tuple(PointerTuple &) { }
};


template <class L, class Tuple>
struct MembersAsTupleOp 
/* Do not inherit from LEESAUnaryFunction because the default
   expression traits for KindTraits<Kind>::Container are undesirable.
*/
  : std::unary_function <typename ET<L>::argument_type, 
                         typename Transposer<Tuple>::Transpose>, OpBase
{
  typedef typename ET<L>::argument_kind argument_kind;
  typedef typename ET<L>::argument_type argument_type;
  typedef typename Transposer<Tuple>::Transpose result_type;
  typedef Tuple result_kind;
  typedef ChainExpr<L, MembersAsTupleOp> expression_type;

  typedef typename Concept_Violation_If_Not_Child<argument_kind, Tuple>::type _NullType;

  explicit MembersAsTupleOp () {}
  
  MembersAsTupleOp (MembersAsTupleOp const & mtop) {}
  
  result_type operator () (argument_type const & arg)
  {
    Transposer<Tuple> th;
    push_children(arg, th, Tuple());
    return th.get_transpose();
  }

  template <class ShrinkingTuple>
  void push_children(argument_type const & arg, Transposer<Tuple> & th, ShrinkingTuple)
  {
    typedef typename ShrinkingTuple::head_type Head;
    typedef typename ET<Head>::result_type result_type;
    typedef typename ShrinkingTuple::tail_type Tail;
    const result_type dummy;
    GetChildrenOp <argument_type, result_type> gcop(dummy);
    th.add(gcop(arg));
    push_children(arg, th, Tail());
  }

  void push_children(argument_type const & arg, Transposer<Tuple> & th, boost::tuples::null_type)
  {  }
};

#endif // LEESA_FOR_UDM

template <class E, class Func>
struct FilterOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESA::LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, FilterOp> expression_type;

  Func func_;
  bool logical_not_; 
  
  explicit FilterOp (Func f, bool logical_not = false) 
    : func_(f), logical_not_ (logical_not) { }

  FilterOp (FilterOp const & fop) 
    : func_(fop.func_), logical_not_ (fop.logical_not_) {}

  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    BOOST_FOREACH(argument_kind & kind, arg)
    {
      if (func_(kind) ^ logical_not_) // Logical not of match, if required
        retval.push_back(kind);
    }
    return retval;
  }
  FilterOp operator ! () 
  {
    FilterOp f(*this);
    f.logical_not_ = !this->logical_not_;
    return f;
  }
};

template <class E, class Func>
struct ForEachOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESA::LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, ForEachOp> expression_type;

  Func func_;
  
  explicit ForEachOp (Func f) 
    : func_(f) { }
  
  ForEachOp (ForEachOp const & fop) 
    : func_(fop.func_) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    std::for_each (v.begin(), v.end(), func_);
    return arg;
  }
};


template <class E, class Comp>
struct SortOp : LEESAUnaryFunction <E>,
                OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, SortOp<E, Comp> > expression_type;

  Comp comp_;
  
  explicit SortOp (Comp c) : comp_(c) {}
  
  SortOp (SortOp const & sop) : comp_(sop.comp_) {}
  
  result_type operator () (argument_type const & k)
  {
    typename KindTraits<argument_kind>::Container s = k;
    std::sort(s.begin(), s.end(), comp_);
    return s;
  }
};

template <class E, class BinPred>
struct UniqueOp : LEESAUnaryFunction <E>,
                  OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr <E, UniqueOp> expression_type;

  BinPred pred_;
  
  explicit UniqueOp (BinPred p) : pred_(p) {}
  
  UniqueOp (UniqueOp const & uop) : pred_(uop.pred_) {}
  
  result_type operator () (argument_type const & k)
  {
    typename KindTraits<argument_kind>::Container s = k;
    typename KindTraits<result_kind>::Container retval;
    BOOST_FOREACH(argument_kind kind, s)
    {  
      if (std::count (retval.begin(), retval.end(), kind) == 0)
        retval.push_back(kind);
    }
    return retval;
  }
};

template <class T>
RegexOp<typename ET<T>::result_type> 
SelectByName (T, const char * str)
{
  typedef typename ET<T>::result_type result_type;
  typedef typename ET<T>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  RegexOp<result_type> regex(str);
  return regex;
}

template <class T>
SelectorOp<typename ET<T>::result_type> 
SelectSubSet (T const &t)
{
  typedef typename ET<T>::result_type result_type;
  typedef typename ET<T>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  return SelectorOp<result_type> (t);
}

template <class Iter>
SelectorOp<typename ET<typename Iter::value_type>::result_type> 
SelectSubSet (Iter begin, Iter end)
{
  typedef typename Iter::value_type Kind;
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<Kind>));

  typedef typename ET<Kind>::result_type result_type;
  typedef typename ET<Kind>::result_kind result_kind;
  
  return SelectorOp<result_type> (begin, end);
}

template <class E, class Func>
FilterOp<E, Func> 
Select (E, Func f)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Func::argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Func::result_type, bool>));
  
  return FilterOp<E, Func> (f);
}

template <class E, class Arg, class Result>
FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
Select (E, Result (*f) (Arg))
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Result, bool>));
  
  FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
    filter(std::ptr_fun(f));
  return filter;
}

template <class E>
StoreAtOp<typename ET<E>::result_type> 
StoreAt (E, typename KindTraits<typename ET<E>::result_kind>::Container & c)
{
  typedef typename ET<E>::result_kind result_kind;
  typedef typename KindTraits<result_kind>::Container Container;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<result_kind, typename Container::value_type>));
  
  return StoreAtOp<typename ET<E>::result_type> (c);
}

template <class E, class Func>
ForEachOp<typename ET<E>::result_type, Func> 
ForEach (E, Func f)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<result_kind, typename Func::argument_type>));
  
  return ForEachOp<typename ET<E>::result_type, Func> (f);
}

template <class E, class Arg, class Result>
ForEachOp<typename ET<E>::result_type, 
          std::pointer_to_unary_function<Arg, Result> > 
ForEach (E, Result (*f) (Arg))
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
  
  ForEachOp<typename ET<E>::result_type, 
            std::pointer_to_unary_function<Arg, Result> > 
    foreach(std::ptr_fun(f));
  return foreach;
}

template <class L, class H>
CastOp<typename ET<L>::result_type, 
       typename ET<H>::result_type> 
CastFromTo (L, H)
{
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<L>));
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<H>));

  typedef typename ET<L>::argument_type argument_type;
  typedef typename ET<H>::result_type result_type;

  return CastOp<argument_type, result_type>();
}

#ifdef LEESA_FOR_UDM

template <class T>
NonNullOp<typename ET<T>::result_type> 
SelectNonNull (T)
{
  typedef typename ET<T>::result_type result_type;
  typedef typename ET<T>::result_kind result_kind;
  
  BOOST_MPL_ASSERT((LEESA::DomainKindConcept<result_kind>));
  NonNullOp<result_type> n;
  return n;
}

#endif // LEESA_FOR_UDM

template <class E, class Comp>
SortOp<E, Comp> 
Sort (E, Comp c)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Comp::first_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Comp::second_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Comp::result_type, bool>));
  
  return SortOp<E, Comp> (c);
}

template <class E, class Arg1, class Arg2, class Result>
SortOp<E, std::pointer_to_binary_function<Arg1, Arg2, Result> > 
Sort (E, Result (*f) (Arg1, Arg2))
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Arg1, result_kind>));  
  BOOST_MPL_ASSERT((boost::is_convertible<Arg2, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Result, bool>));
  
  SortOp<E, std::pointer_to_binary_function<Arg1, Arg2, Result> > 
    sorter(std::ptr_fun(f));
  return sorter;
}

template <class E, class BinPred>
UniqueOp<typename ET<E>::result_type, BinPred> 
Unique (E, BinPred c)
{
  typedef typename ET<E>::result_kind result_kind;
  typedef typename ET<E>::result_type result_type;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename BinPred::first_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename BinPred::second_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename BinPred::result_type, bool>));
  
  return UniqueOp<result_type, BinPred> (c);
}

template <class E>
UniqueOp<typename ET<E>::result_type, 
         std::equal_to<typename ET<E>::result_kind> > 
Unique (E)
{
  typedef typename ET<E>::result_kind result_kind;
  typedef typename ET<E>::result_type result_type;
  typedef std::equal_to<result_kind> EQ;  

  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename EQ::first_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename EQ::second_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename EQ::result_type, bool>));
  
  return UniqueOp<result_type, EQ>(EQ());
}

template <class E>
LeaveCallerOp<typename ET<E>::result_type> 
Leave (E, SchemaVisitor & v)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  
  return LeaveCallerOp<typename ET<E>::result_type> (v);
}

template <class E>
VisitorOp<typename ET<E>::result_type> 
Visit (E, SchemaVisitor & v)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  
  return VisitorOp<typename ET<E>::result_type> (v);
}

template <class E, class Func>
PairCallerOp<typename ET<E>::result_type, Func> 
VisitLeave (E, SchemaVisitor & v, Func f)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  
  return PairCallerOp<typename ET<E>::result_type, Func> (v, f);
}

template <class E>
PairCallerOp<typename ET<E>::result_type> 
VisitLeave (E, SchemaVisitor & v)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  
  return PairCallerOp<typename ET<E>::result_type> (v); // Default Func is identity.
}

#ifndef LEESA_FOR_UDM
template <class Kind, class Tuple>
MembersAsTupleOp <typename ET<Kind>::result_kind, 
                  typename RemovePointerIfAnyTuple<Tuple>::type>
MembersAsTupleOf (Kind, Tuple)
{
  return MembersAsTupleOp <typename ET<Kind>::result_kind, 
                           typename RemovePointerIfAnyTuple<Tuple>::type> ();
}
#endif // LEESA_FOR_UDM

/*
template <class K, class C1, class C2>
ChoiceOp<typename ET<K>::result_type, C1, C2> 
Choice (K, C1 c1, C2 c2)
{
  typedef typename ET<K>::result_kind result_kind;
  typedef typename ET<C1>::argument_kind arg1_kind;
  typedef typename ET<C2>::argument_kind arg2_kind;

  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<result_kind, arg1_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<result_kind, arg2_kind>));
  
  return ChoiceOp<typename ET<K>::result_type, C1, C2>(c1, c2);
}
*/

} // namespace LEESA 
