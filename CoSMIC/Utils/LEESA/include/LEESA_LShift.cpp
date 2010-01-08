
namespace LEESA {

#ifdef LEESA_FOR_UDM

template <class L, class H>
typename disable_if_c
  <IsDomainVisitorBaseOf<H>::value |
   is_base_of<std::ios_base, L>::value |
   is_base_of <OpBase, H>::value,
   ChainExpr<typename ET<L>::expression_type,
             GetParentOp<typename ET<L>::result_type,
                         typename ET<H>::expression_type>
            > >::type
operator << (L const &l, H const & h)
{
  // Don't replace the following with LOCAL_TYPEDEFS.
  typedef GetParentOp<typename ET<L>::result_type, 
                      typename ET<H>::expression_type>  GPOp;
  typedef typename ET<L>::expression_type ChildKindExpr;
  typedef typename ET<H>::argument_kind ParentKind;
  typedef typename ET<L>::result_kind ChildKind;
  typedef ChainExpr<ChildKindExpr, GPOp> ChainExpr;

  BOOST_CONCEPT_ASSERT((LEESA::ChildToParentConcept <ChildKind, ParentKind>));

  GPOp gpop(h);
  return ChainExpr(ChildKindExpr(l), gpop);
}

template <class L, class H>
typename disable_if_c
  <IsDomainVisitorBaseOf<H>::value |
   is_base_of<OpBase, H>::value,
   ChainExpr<typename ET<L>::expression_type, 
              GetParentOp<typename ET<L>::result_type,
                          typename ET<H>::expression_type>
            >
  >::type
operator <<= (L const &l, H const & h)
{
  // Don't replace the following with LOCAL_TYPEDEFS.
  typedef GetParentOp<typename ET<L>::result_type, 
                      typename ET<H>::expression_type>  GPOp;
  typedef typename ET<L>::expression_type ChildKindExpr;
  typedef typename ET<H>::argument_kind ParentKind;
  typedef typename ET<L>::result_kind ChildKind;
  typedef ChainExpr<ChildKindExpr, GPOp> ChainExpr;

  BOOST_CONCEPT_ASSERT((LEESA::ChildToParentConcept <ChildKind, ParentKind>));

  GPOp gpop(h);
  return ChainExpr(ChildKindExpr(l), gpop);
}

template <class L, class OP>                              
typename disable_if_c<                                             
  IsDomainVisitorBaseOf<L>::value |                     
  is_base_of <std::ios_base, L>::value |
  !is_base_of <OpBase, OP>::value,                             
  ChainExpr<typename ET< L >::expression_type, OP> >::type  
operator << (L const &l, OP op)
{
  LOCAL_TYPEDEFS(L, OP);
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<ParentKind, ChildKind>));
  return ChainExpr(ParentKindExpr(l), op);                   
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
operator <<= (Carrier<LKind> const & k, VisitorAsIndex<R> const & vi)
{
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<LKind, R>)); 

  return k <<= R() >> vi.getVisitor();
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
operator <<= (Carrier<LKind> const & k, R const & r)
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

#ifndef LEESA_NO_VISITOR

template <class L, class R>
ChainExpr<ChainExpr<typename ET<L>::expression_type,
                    VisitorOp<typename ET<L>::result_type>
                   >,
          GetParentOp <typename ET<L>::result_type,
                       ChainExpr<typename ET<R>::expression_type,
                                 VisitorOp<typename ET<R>::result_type>
                                >
                      >
         >
operator <<= (VisitorAsIndex<L> vl, VisitorAsIndex<R> vr)
{
  typedef typename ET<R>::result_kind ParentKind;
  typedef typename ET<L>::argument_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind,ChildKind>));

  return L() >> vl.getVisitor() <<= R() >> vr.getVisitor();
}

template <class L>
typename disable_if<
  is_base_of<std::ios_base, L>, 
  ChainExpr<typename ET<L>::expression_type, 
            VisitorOp<typename ET<L>::result_type> > 
  >::type
operator << (L const &l, SchemaVisitor & v)
{
  BOOST_MPL_ASSERT_NOT((is_base_of<OpBase, L>));

  typedef VisitorOp<typename ET<L>::result_type> OP;
  LOCAL_TYPEDEFS(L, OP);
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<ParentKind, ChildKind>));

  return ChainExpr(ParentKindExpr(l), OP(v));
}

template <class L, class H>
typename 
  disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<ChainExpr<typename ET<L>::expression_type,
                      GetParentOp<typename ET<L>::result_type,
                                  typename ET<H>::expression_type>
                     >,
            VisitorOp<typename ET<H>::result_type>
           > >::type
operator << (L const &l, VisitorAsIndex<H> vi)
{
  typedef typename ET<L>::result_kind ChildKind;
  typedef typename ET<H>::result_kind ParentKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind, ChildKind>));

  return l << H() >> vi.getVisitor();
}

template <class L, class H>
ChainExpr<ChainExpr<ChainExpr<typename ET<L>::expression_type, 
                              VisitorOp<typename ET<L>::result_type> 
                             >,
                    GetParentOp<typename ET<L>::result_type,
                                typename ET<H>::result_type>
                   >,
          VisitorOp<typename ET<H>::result_type> 
         >
operator << (VisitorAsIndex<L> vl, VisitorAsIndex<H> vh)
{
  typedef typename ET<H>::result_kind ParentKind;
  typedef typename ET<L>::result_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind, ChildKind>));

  return L() >> vl.getVisitor() << H() >> vh.getVisitor();
}

#endif // LEESA_NO_VISITOR

#endif // LEESA_FOR_UDM

} // namespace LEESA

