#ifndef __LEESA_CPP
#define __LEESA_CPP

#include "Kind_Traits.h"
#include "LEESA_Concepts.h"
#include "LEESA_VisitorAsIndex.h"

#include <boost/typeof/typeof.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>
#include <boost/foreach.hpp>
#include <boost/utility/enable_if.hpp>

#include <functional>
#include <ios>

#define SUPER_TYPEDEFS(Super)                                               \
  typedef typename Super::argument_kind argument_kind;                      \
  typedef typename Super::result_kind result_kind;                          \
  typedef typename Super::argument_type argument_type;                      \
  typedef typename Super::result_type result_type;             

#define LOCAL_TYPEDEFS(L, OP)                                               \
  typedef typename ET< L >::expression_type ParentKindExpr;                 \
  typedef typename ET< OP >::argument_kind ChildKind;                       \
  typedef typename ParentKindExpr::result_kind ParentKind;                  \
  typedef ChainExpr<ParentKindExpr, OP > ChainExpr;

// Forward declarations of operators. Definitions in LEESA_Operators.cpp
// Forward declarations are necessary here for Expression_Traits (defined next)
namespace LEESA {

template <class Kind> class KindLit;
template <class L, class R> struct ChainExpr;
template <class L, class R> struct SequenceExpr;

template <class L, class R> struct GetChildrenOp;
template <class L, class R> struct DFSChildrenOp;
template <class L, class R> struct DFSOp;

#ifndef LEESA_NO_VISITOR

template <class E> struct VisitorOp;

#endif // LEESA_NO_VISITOR

template <class E> struct RegexOp;
template <class E> struct SelectorOp;
template <class E, class Func> struct FilterOp;
template <class E, class Func> struct ForEachOp;
template <class E, class Comp> struct SortOp;
template <class E, class BinPred> struct UniqueOp;

#ifdef LEESA_FOR_UDM

template <class E> struct NonNullOp;
template <class L, class R> struct CastOp;
template <class L, class R> struct GetParentOp;
template <class L, class R> struct DFSParentOp;
template <class RESULT, class TARGETCLASS> struct AssociationOp;
template <class RESULT, class TARGETCLASS> struct AssociationEndOp;
template <class ASSOC, class SOURCECLASS, class TARGETCLASS> struct AssociationManyOp;

#endif // LEESA_FOR_UDM

} // namespace LEESA

// Expression Traits must be defined before everything else.
// Do not remove from this place.
#include "Expression_Traits.h"

namespace LEESA {

using boost::disable_if_c;
using boost::disable_if;
using boost::is_base_of;
using boost::is_pointer;


template <class Kind>
class KindLit : public std::unary_function <KindLit<Kind>, KindLit<Kind> >
{
  typedef typename KindTraits<Kind>::Container Container;
  Container c_;
  BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);
  BOOST_MPL_ASSERT((LEESA::DomainKindConcept<Kind>));
  // This is an important concept. Don't remove.

public:
  typedef KindLit<Kind> expression_type;
  typedef Kind result_kind;
  typedef Kind argument_kind;
  typedef KindLit<Kind> result_type;
  typedef KindLit<Kind> argument_type;
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;

  template <class U>
  struct rebind
  {
    typedef KindLit<U> type;
  };

  explicit KindLit () {}
 
  template <class U>
  KindLit (KindLit<U> const & ukindlit)
  {
    BOOST_MPL_ASSERT((is_base_of<Kind,U>));
    //c_.insert(c_.end(), ukindlit.c_.begin(), ukindlit.c_.end());
    std::copy(ukindlit.c_.begin(), ukindlit.c_.end(), std::back_inserter(c_));
  }
  KindLit (KindLit const & k) : c_ (k.c_) {}
  KindLit (Kind const & k) { c_.push_back(k); }  
  KindLit (Container const & c) : c_(c) { }

#ifdef LEESA_FOR_UDM

  void Union(Udm::ParentAttr<Kind> const & c) 
  {
    Kind k = c;
    c_.push_back(k);
  }
  void Union(Udm::ChildrenAttr<Kind> const & ca) 
  {
    Container c = ca;
    std::copy(c.begin(), c.end(), std::back_inserter(c_));
  }

#else 

  void Union (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional o)
  {
    if (o.present()) 
    {
      c_.push_back(o.get());
    }
  }

#endif // LEESA_FOR_UDM

  void Union(Kind const & k)
  {
    c_.push_back(k);
  }
  
  void Union(Container const & in)
  {
    std::copy(in.begin(), in.end(), std::back_inserter(c_));
  }
  
  iterator begin() { return c_.begin(); }
  const_iterator begin() const { return c_.begin(); }

  iterator end() { return c_.end(); }
  const_iterator end() const { return c_.end(); }
  
  bool isEmpty() const 
  {
    return c_.empty();
  }
  
  operator Container () const { return c_; } 
  result_type operator () (argument_type p) const { return p; }
};

template <class L, class R>
struct ChainExpr : LEESAUnaryFunction <L, R>
{
  typedef LEESAUnaryFunction <L, R> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, R> expression_type;

  BOOST_CONCEPT_ASSERT((LEESA::ConvertibleDomainKindsConcept
                        <typename ET<L>::result_kind, 
                         typename ET<R>::argument_kind>));

  L l_;
  R r_;
  ChainExpr (ChainExpr const & c) 
    : l_(c.l_), r_(c.r_) 
  {}
  
  explicit ChainExpr (L const &l, R const & r) 
    : l_(l), r_(r) {}
  
  result_type operator () (argument_type p) { return r_(l_(p)); }
};

template <class L, class R>
struct SequenceExpr : public LEESAUnaryFunction <L, void>
{
  typedef LEESAUnaryFunction <L, void> Super;
  SUPER_TYPEDEFS(Super);
  typedef SequenceExpr<L, R> expression_type;
  typedef typename ET<R>::argument_kind child_kind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<argument_kind, child_kind>));

  L l_;
  R r_;
  
  explicit SequenceExpr () {} 
  
  SequenceExpr (SequenceExpr const & c) 
    : l_(c.l_), r_(c.r_) 
  {}
  
  explicit SequenceExpr (L const &l, R const & r) 
    : l_(l), r_(r) {}
  
  result_type operator () (argument_type arg) 
  { 
    l_(arg); 
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      typename KindTraits<child_kind>::Container c = 
        kind.template children_kind<child_kind>();
      BOOST_FOREACH(child_kind ckind, c)
      { 
        r_(ckind); 
      }
    }

  }
};

#ifndef LEESA_NO_VISITOR

class VisitorAsIndexBase{};

template <class Kind>
class VisitorAsIndex : public VisitorAsIndexBase
{
    SchemaVisitor & visitor_;
    BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);

  public:
    VisitorAsIndex (SchemaVisitor & v) : visitor_(v) {}
    SchemaVisitor & getVisitor() { return visitor_; }
};

template <class Kind, class Visitor>
LEESA::VisitorAsIndex<Kind>
VisitorAsIndex_CRTP<Kind, Visitor>::operator [] (Visitor &v)
{
  return LEESA::VisitorAsIndex<Kind> (v);
}

#endif // LEESA_NO_VISITOR

template <class L, class H>
/* The following overloaded comma operator is picked up from within 
   STL algorithms and causes compilation havoc. I'm totally hacking 
   the problem away by disabling the overloaded operator if H is a 
   pointer. This problem occurs only VisitorAsIndex extensions are used.
*/
typename disable_if_c<is_pointer<typename ET<H>::argument_kind>::value,
                      SequenceExpr<typename ET<L>::expression_type, 
                                   typename ET<H>::expression_type> 
                     >::type 
operator , (L const &l, H const &h)
{
  typedef SequenceExpr<typename ET<L>::expression_type, 
                       typename ET<H>::expression_type > OP;
  return OP(l, h);
}

#ifndef LEESA_NO_VISITOR

template <class L, class H>
SequenceExpr<typename ET<L>::expression_type, 
             ChainExpr<typename ET<H>::result_type,
                       VisitorOp<typename ET<H>::result_type> 
                      >
            >
operator , (L const &l, VisitorAsIndex<H> vh)
{
  return l , H() >> vh.getVisitor();
}


#endif // LEESA_NO_VISITOR

template <class Para, class Expr>
typename Expr::result_type
evaluate (Para const & p, Expr e)
{
  typedef typename ET<Expr>::argument_kind argument_kind;
  typedef typename ET<Para>::result_kind result_kind;
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<argument_kind, result_kind> ));
  BOOST_MPL_ASSERT((LEESA::SameKindsConcept<argument_kind, result_kind> ));

  return e(p);
}

} // namespace LEESA

// The order of #include is very important
#include "LEESA_Operators.cpp"
#include "LEESA_RShift.cpp"
#include "LEESA_LShift.cpp"
#include "SP.cpp"
#include "AP.cpp"

#endif // __LEESA_CPP


/*
template <class L>
typename disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<typename ET<L>::expression_type, 
            typename DFSVisitorOp<typename ET<L>::result_type> > 
  >::type
operator >>= (L const &l, SchemaVisitor & v)
{
  typedef DFSVisitorOp<typename ET<L>::result_type> OP;
  LOCAL_TYPEDEFS(L, OP);
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<ParentKind, ChildKind>));

  return ChainExpr(ParentKindExpr(l), OP(v));
}
*/

