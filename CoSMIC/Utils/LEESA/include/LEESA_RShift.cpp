#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>
#include <boost/mpl/if.hpp>

using boost::disable_if_c;
using boost::disable_if;
using boost::enable_if_c;
using boost::enable_if;
using boost::mpl::if_;
using boost::is_base_of;

namespace LEESA {

template <class T>
struct IsVisitorAsIndexBaseOf
{
  typedef IsVisitorAsIndexBaseOf type;
#ifndef LEESA_NO_VISITOR
  enum { value = is_base_of<VisitorAsIndexBase, T>::value };
#else
  enum { value = 0 };
#endif // LEESA_NO_VISITOR
};

template <class T>
struct IsDomainVisitorBaseOf
{
  typedef IsDomainVisitorBaseOf type;
#ifndef LEESA_NO_VISITOR
  enum { value = is_base_of<SchemaVisitor, T>::value };
#else
  enum { value = 0 };
#endif // LEESA_NO_VISITOR
};


#ifndef LEESA_NO_VISITOR

template <class L>
typename 
  disable_if_c<is_base_of<std::ios_base, L>::value |
               IsVisitorAsIndexBaseOf<L>::value    | 
               IsDomainVisitorBaseOf<L>::value, 
               ChainExpr<typename ET<L>::expression_type, 
                         VisitorOp<typename ET<L>::result_type> > 
              >::type
operator >> (L const &l, SchemaVisitor & v)
{
  typedef VisitorOp<typename ET<L>::result_type> OP;
  LOCAL_TYPEDEFS(L, OP);
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<ParentKind, ChildKind>));

  return ChainExpr(ParentKindExpr(l), OP(v));
}

template <class L, class H>
typename 
  disable_if_c<is_base_of<std::ios_base, L>::value | 
               IsDomainVisitorBaseOf<L>::value |  
               IsVisitorAsIndexBaseOf<L>::value, 
               ChainExpr<ChainExpr<typename ET<L>::expression_type,
                                   GetChildrenOp<typename ET<L>::result_type,
                                                 typename ET<H>::expression_type>
                                  >,
                         VisitorOp<typename ET<H>::result_type>
                        > 
              >::type
operator >> (L const &l, VisitorAsIndex<H> vi)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<H>::result_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind, ChildKind>));

  return l >> H() >> vi.getVisitor();
}

template <class L, class H>
typename 
disable_if_c <IsDomainVisitorBaseOf<H>::value |
              IsVisitorAsIndexBaseOf<H>::value, 
              ChainExpr<ChainExpr<typename ET<L>::expression_type, 
                                VisitorOp<typename ET<L>::result_type> 
                               >,
                        typename if_<is_base_of<OpBase, H>,
                                     H,
                                     GetChildrenOp<typename ET<L>::result_type,  
                                                   typename ET<H>::result_type>
                                    >::type
                       > 
             >::type
operator >> (VisitorAsIndex<L> vi, H const &h)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<H>::argument_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind, ChildKind>));

  return L() >> vi.getVisitor() >> h;
}

template <class L>
  ChainExpr<ChainExpr<typename ET<L>::expression_type, 
                      VisitorOp<typename ET<L>::result_type> 
                     >,
            VisitorOp<typename ET<L>::result_type> > 
operator >> (VisitorAsIndex<L> vi, SchemaVisitor & v)
{
  typedef typename ET<L>::result_kind result_kind;
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept <result_kind>));

  return L() >> vi.getVisitor() >> v;
}

template <class L, class H>
ChainExpr<ChainExpr<ChainExpr<typename ET<L>::expression_type, 
                              VisitorOp<typename ET<L>::result_type> 
                             >,
                    GetChildrenOp<typename ET<L>::result_type,  
                                  typename ET<H>::result_type>
                   >,
          VisitorOp<typename ET<H>::result_type> 
         >
operator >> (VisitorAsIndex<L> vl, VisitorAsIndex<H> vh)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<H>::result_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind, ChildKind>));

  return L() >> vl.getVisitor() >> H() >> vh.getVisitor();
}

template <class L, class H, class X>
ChainExpr<ChainExpr<typename ET<L>::expression_type,
                    VisitorOp<typename ET<L>::result_type> >, 
          SequenceExpr<H,X> >
operator >> (VisitorAsIndex<L> vl, SequenceExpr<H,X> const & s)
{  
  typedef typename ET<L>::result_kind LKind;
  typedef typename ET<H>::argument_kind RKind;
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept <LKind, RKind>));
  
  return L() >> vl.getVisitor() >> s;
}

template <class L, class R>
typename disable_if_c <
  IsDomainVisitorBaseOf<L>::value |
  IsVisitorAsIndexBaseOf<L>::value |
  is_base_of<OpBase,L>::value,
  ChainExpr<typename ET<L>::expression_type, 
            GetChildrenOp<typename ET<L>::result_type,
                          ChainExpr<typename ET<R>::expression_type, 
                                    VisitorOp<typename ET<R>::result_type> 
                                   > 
                         > 
           > >::type
operator >>= (L const &l, VisitorAsIndex<R> vi)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<R>::result_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind,ChildKind>));

  return l >>= R() >> vi.getVisitor();
}

template <class L, class R>
typename disable_if_c <
  is_base_of <OpBase, R>::value |
  IsVisitorAsIndexBaseOf<R>::value,
  ChainExpr<ChainExpr<typename ET<L>::expression_type,
                      VisitorOp<typename ET<L>::result_type>
                     >,
            GetChildrenOp <typename ET<L>::result_type,
                           typename ET<R>::expression_type
                          >
           > >::type
operator >>= (VisitorAsIndex<L> vi, R const &r)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<R>::argument_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind,ChildKind>));

  return L() >> vi.getVisitor() >>= r;
}

template <class L, class Op>
typename enable_if<is_base_of<OpBase, Op>,
                   ChainExpr<ChainExpr<typename ET<L>::expression_type,
                                       VisitorOp<typename ET<L>::result_type>
                                      >,
                             Op> 
                  >::type
operator >>= (VisitorAsIndex<L> vi, Op const & op)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<Op>::argument_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept <ParentKind,ChildKind>));

  return L() >> vi.getVisitor() >> op;
}

template <class L, class R>
ChainExpr<ChainExpr<typename ET<L>::expression_type,
                    VisitorOp<typename ET<L>::result_type>
                   >,
          GetChildrenOp <typename ET<L>::result_type,
                         ChainExpr<typename ET<R>::expression_type,
                                   VisitorOp<typename ET<R>::result_type>
                                  >
                        >
         >
operator >>= (VisitorAsIndex<L> vl, VisitorAsIndex<R> vr)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<R>::argument_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind,ChildKind>));

  return L() >> vl.getVisitor() >>= R() >> vr.getVisitor();
}

template <class L, class R, class X>
ChainExpr<ChainExpr<typename ET<L>::expression_type,
                    VisitorOp<typename ET<L>::result_type> >, 
          DFSOp<ChainExpr<typename ET<L>::expression_type,
                          VisitorOp<typename ET<L>::result_type> >,
          SequenceExpr<R,X>
         >
         >
operator >>= (VisitorAsIndex<L> vl, SequenceExpr<R,X> const &r)
{
  typedef typename ET<L>::result_kind LKind;
  typedef typename ET<R>::argument_kind RKind;
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept <LKind, RKind>));

  return L() >> vl.getVisitor() >>= r;
}

template <class LKind, class R>
typename disable_if_c <
  IsDomainVisitorBaseOf<R>::value |
  is_base_of<OpBase,R>::value,
  ChainExpr<typename ET<LKind>::result_type,
            DFSOp<typename ET<R>::argument_type,
                  ChainExpr<typename ET<R>::result_type, 
                            VisitorOp<typename ET<R>::result_type>
                           >
                 >
           > >::type
operator >>= (Carrier<LKind> const & k, VisitorAsIndex<R> const & vi)
{
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<LKind, R>)); 

  return k >>= R() >> vi.getVisitor();
}

#endif // LEESA_NO_VISITOR

template <class L, class OP>                              
typename disable_if_c<
  IsVisitorAsIndexBaseOf<L>::value |                     
  IsDomainVisitorBaseOf<L>::value |                     
  is_base_of <std::ios_base, L>::value |
  !is_base_of <OpBase, OP>::value,                             
  ChainExpr<typename ET< L >::expression_type, OP> >::type  
/* This function supports all the operators that inherit from OpBase. */
operator >> (L const &l, OP const & op) 
{
  LOCAL_TYPEDEFS(L, OP);                               
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<ParentKind, ChildKind>));
  return ChainExpr(ParentKindExpr(l), op);                   
}

template <class L, class R>
typename disable_if_c<
   IsDomainVisitorBaseOf<R>::value |
   IsDomainVisitorBaseOf<L>::value |
   is_base_of<std::ios_base, L>::value |
   is_base_of <OpBase, R>::value |
   is_base_of <OpBase, L>::value,
   ChainExpr<typename ET<L>::expression_type, 
             GetChildrenOp<typename ET<L>::result_type, 
                           typename ET<R>::expression_type>
             > >::type
operator >> (L const &l, R const &r)
{
  typedef GetChildrenOp<typename ET<L>::result_type, 
                        typename ET<R>::expression_type> GCOp;
                        
  LOCAL_TYPEDEFS(L, GCOp);
  BOOST_CONCEPT_ASSERT((
    LEESA::ParentChildConcept<typename ET<L>::result_kind, 
                              typename ET<R>::argument_kind>));

  GCOp gcop(r);
  return ChainExpr(ParentKindExpr(l), gcop);
}


template <class L, class H, class X>
typename disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<typename ET<L>::expression_type, 
            SequenceExpr<H,X> 
           > >::type
operator >> (L const &l, SequenceExpr<H,X> const & s)
{
  typedef SequenceExpr<H,X> OP;
  typedef typename ET<L>::expression_type LExpr;
  typedef typename ET<L>::result_kind LKind;
  typedef typename ET<OP>::argument_kind RKind;
  typedef ChainExpr<LExpr, OP> ChainExpr;

  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<LKind, RKind>));
  return ChainExpr(LExpr(l), OP(s));
}

#ifdef LEESA_FOR_UDM

template <class L, class RESULT, class TARGETCLASS>
typename disable_if<is_base_of<std::ios_base, L>, 
          ChainExpr<typename ET<L>::expression_type, 
                    AssociationOp<RESULT, TARGETCLASS>
          > >::type
operator >> (L const &l, Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*func)() const)
{
  typedef AssociationOp<RESULT, TARGETCLASS> OP;
  LOCAL_TYPEDEFS(L, OP); 
  BOOST_CONCEPT_ASSERT((LEESA::ConvertibleDomainKindsConcept<ParentKind, ChildKind>));

  return ChainExpr(ParentKindExpr(l), OP(func));
}


template <class L, class ASSOC, class SOURCECLASS, class TARGETCLASS>
typename disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<typename ET<L>::expression_type, 
            AssociationManyOp<ASSOC, SOURCECLASS, TARGETCLASS>
  > >::type
operator >> (L const &l, Udm::AClassAssocAttr<ASSOC, TARGETCLASS> (SOURCECLASS::*func)() const)
{
  typedef AssociationManyOp<ASSOC, SOURCECLASS, TARGETCLASS> OP;
  LOCAL_TYPEDEFS(L, OP); 
  BOOST_CONCEPT_ASSERT((LEESA::ConvertibleDomainKindsConcept<ParentKind, ChildKind>));

  return ChainExpr(ParentKindExpr(l), OP(func));
}

template <class L, class RESULT, class TARGETCLASS>
typename disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<typename ET<L>::expression_type, 
            AssociationEndOp<RESULT, TARGETCLASS>
  > >::type
operator >> (L const &l, Udm::AssocEndAttr<RESULT> (TARGETCLASS::*func)() const)
{
  typedef AssociationEndOp<RESULT, TARGETCLASS> OP;
  LOCAL_TYPEDEFS(L, OP); 
  BOOST_CONCEPT_ASSERT((LEESA::ConvertibleDomainKindsConcept<ParentKind, ChildKind>));

  return ChainExpr(ParentKindExpr(l), OP(func));
}

#endif // LEESA_FOR_UDM

template <class L, class R>
typename disable_if_c
  <IsDomainVisitorBaseOf<R>::value |
   IsDomainVisitorBaseOf<L>::value |
   is_base_of<OpBase,R>::value |
   is_base_of<OpBase,L>::value,
   ChainExpr<typename ET<L>::expression_type, 
             GetChildrenOp <typename ET<L>::result_type,
                            typename ET<R>::expression_type>
            >
            >::type
operator >>= (L const &l, R const &r)
{
  typedef GetChildrenOp<typename ET<L>::result_type, 
                        typename ET<R>::expression_type> GCOp;
                        
  LOCAL_TYPEDEFS(L, GCOp);
  BOOST_CONCEPT_ASSERT((
    LEESA::ParentChildConcept<typename ET<L>::result_kind, 
                              typename ET<R>::argument_kind>));

  GCOp gcop(r);
  return ChainExpr(ParentKindExpr(l), gcop);
}

template <class LKind, class R>
typename disable_if_c <
  IsDomainVisitorBaseOf<R>::value |
  IsVisitorAsIndexBaseOf<R>::value |
  is_base_of<OpBase,R>::value,
  ChainExpr<typename ET<LKind>::result_type, 
            DFSOp<typename ET<R>::argument_type,
                  typename ET<R>::expression_type>
           > >::type
operator >>= (Carrier<LKind> const & k, R const & r)
{
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<LKind, typename ET<R>::argument_kind>)); 

  typedef typename ET<LKind>::result_type LResult;
  typedef typename ET<R>::argument_type RArg;
  typedef typename ET<R>::expression_type RExpr;
  typedef DFSOp<RArg, RExpr> DFSOperator;
  DFSOperator dfsop(r);
  typedef ChainExpr <LResult, DFSOperator> ChainExpr;

  return ChainExpr(k, dfsop);
}

template <class L, class R, class X>
ChainExpr<typename ET<L>::expression_type, 
          DFSOp<typename ET<L>::expression_type,
                 SequenceExpr<R,X>
         >
     >
operator >>= (L const &l, SequenceExpr<R,X> const &r)
{
  typedef SequenceExpr<R,X> OP;
  typedef typename ET<L>::expression_type LExpr;
  typedef typename ET<OP>::expression_type RExpr;
  typedef DFSOp<LExpr, RExpr> Operator;
  typedef typename ET<L>::result_kind LKind;
  typedef typename ET<Operator>::argument_kind RKind;
  typedef ChainExpr<LExpr, Operator> ChainExpr;

  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<LKind, RKind>));

  Operator op(r);
  return ChainExpr(LExpr(l), op);
}


} // namespace LEESA

