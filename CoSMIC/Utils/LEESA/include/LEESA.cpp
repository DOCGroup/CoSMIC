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

template <class Kind> class Carrier;
template <class L, class R> struct ChainExpr;
template <class L, class R> struct SequenceExpr;

template <class L, class R> struct GetChildrenOp;
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
template <class L, class R> struct CastOp;
template <class L, class Tuple> struct MembersAsTupleOp;

#ifdef LEESA_FOR_UDM

template <class E> struct NonNullOp;
template <class L, class R> struct GetParentOp;
template <class RESULT, class TARGETCLASS> struct AssociationOp;
template <class RESULT, class TARGETCLASS> struct AssociationEndOp;
template <class ASSOC, class SOURCECLASS, class TARGETCLASS> struct AssociationManyOp;

#endif // LEESA_FOR_UDM

} // namespace LEESA

// Expression Traits must be defined before everything else.
// Do not remove from this place.
#include "Expression_Traits.h"

namespace LEESA {

using boost::enable_if_c;
using boost::enable_if;
using boost::is_base_of;
using boost::is_pointer;


template <class Kind>
class Carrier : public std::unary_function <Carrier<Kind>, Carrier<Kind> >
{
  typedef typename KindTraits<Kind>::Container Container;
  Container c_;
  BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);
  BOOST_MPL_ASSERT((LEESA::DomainKindConcept<Kind>));
  // This is an important concept. Don't remove.

public:
  typedef Carrier<Kind> expression_type;
  typedef Kind result_kind;
  typedef Kind argument_kind;
  typedef Carrier<Kind> result_type;
  typedef Carrier<Kind> argument_type;
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;

  template <class U>
  struct rebind
  {
    typedef Carrier<U> type;
  };

  explicit Carrier () {}
 
  template <class U>
  Carrier (Carrier<U> const & u_carrier)
  {
    BOOST_MPL_ASSERT((is_base_of<Kind,U>));
    std::copy(u_carrier.c_.begin(), u_carrier.c_.end(), std::back_inserter(c_));
  }
  Carrier (Carrier const & k) : c_ (k.c_) {}
  Carrier (Kind const & k) { this->push_back(k); }  
  Carrier (Container const & c) : c_(c) { }
  
  void push_back(Carrier const & k)
  {
    std::copy(k.begin(), k.end(), std::back_inserter(c_));
  }

  void push_back(Kind const & k)
  {
    c_.push_back(k);
  }
  
  void push_back(Container const & in)
  {
    std::copy(in.begin(), in.end(), std::back_inserter(c_));
  }

#ifdef LEESA_FOR_UDM

  Carrier (Udm::ParentAttr<Kind> const & c) 
  {
    this->push_back(c);
  }

  void push_back(Udm::ParentAttr<Kind> const & c) 
  {
    Kind k = c;
    c_.push_back(k);
  }

  Carrier(Udm::ChildrenAttr<Kind> const & ca) 
  {
    this->push_back(ca);
  }

  void push_back(Udm::ChildrenAttr<Kind> const & ca) 
  {
    Container c = ca;
    std::copy(c.begin(), c.end(), std::back_inserter(c_));
  }

#else 

  Carrier (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional o)
  {
    this->push_back(o);
  }

  void push_back (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional o)
  {
    if (o.present()) 
    {
      c_.push_back(o.get());
    }
  }

#endif // LEESA_FOR_UDM

  iterator begin() { return c_.begin(); }
  const_iterator begin() const { return c_.begin(); }

  iterator end() { return c_.end(); }
  const_iterator end() const { return c_.end(); }
  
  bool isEmpty() const 
  {
    return c_.empty();
  }
  
  operator Container () const { return c_; } 
  result_type & operator () (argument_type & p) const { return p; }
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
struct SequenceExpr : public LEESAUnaryFunction <L, typename ET<L>::argument_type>
{
  typedef LEESAUnaryFunction <L, typename ET<L>::argument_type> Super;
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
    return arg;
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
    SchemaVisitor & getVisitor() const { return visitor_; }
};

template <class Kind, class Visitor>
LEESA::VisitorAsIndex<Kind>
VisitorAsIndex_CRTP<Kind, Visitor>::operator [] (Visitor &v)
{
  return LEESA::VisitorAsIndex<Kind> (v);
}

#endif // LEESA_NO_VISITOR

/* When FOLLOWED_BY is a comma, the following operator is picked up from within 
   STL algorithms and causes compilation havoc. Specifically, it matches with
   a comma seperated list of iterators incremented inside a for-loop in xutility.
   This is quite embarassing and dangerous in general. IsSchemaType trait is 
   designed to prevent this problem. Its value is true if its parameter inherits 
   from a base type found in the DOMAIN_NAMESPACE only. See the definition in 
   KindTraits.h. Its implementation is specific to the underlying OO API. Another 
   somewhat less desirable solution is to change the #define FOLLOWED_BY in 
   LEESA.h to &&. 
*/
template <class L, class H>
typename enable_if<IsSchemaType<typename ET<L>::argument_kind>,
                   SequenceExpr<typename ET<L>::expression_type, 
                                typename ET<H>::expression_type> 
                  >::type 
// See #define FOLLOWED_BY in LEESA.h
operator FOLLOWED_BY (L const &l, H const &h)
{
  typedef SequenceExpr<typename ET<L>::expression_type, 
                       typename ET<H>::expression_type > Seq;
  return Seq(l, h);
}

#ifndef LEESA_NO_VISITOR

template <class L, class H>
SequenceExpr<typename ET<L>::expression_type, 
             ChainExpr<typename ET<H>::result_type,
                       VisitorOp<typename ET<H>::result_type> 
                      >
            >
// See #define FOLLOWED_BY in LEESA.h
operator FOLLOWED_BY (L const &l, VisitorAsIndex<H> vh)
{
  return l FOLLOWED_BY H() >> vh.getVisitor();
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

