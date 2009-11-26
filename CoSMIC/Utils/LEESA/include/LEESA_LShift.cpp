
namespace LEESA {


template <class L, class H>
typename disable_if_c
  <IsDomainVisitorBaseOf<H>::value |
   is_base_of<std::ios_base, L>::value |
   is_base_of <OpBase, H>::value,
   typename ChainedOperator<L,H,GetParentOp>::Op>::type
operator << (L const &l, H)
{
	// Don't replace the following with LOCAL_TYPEDEFS.
	typedef GetParentOp<typename ET<L>::result_type, 
                      typename ET<H>::argument_type>  OP;
	typedef typename ET<L>::expression_type ChildKindExpr;
	typedef typename ET<H>::argument_kind ParentKind;
	typedef typename ET<L>::result_kind ChildKind;
	typedef ChainExpr<ChildKindExpr, OP> ChainExpr;

  BOOST_CONCEPT_ASSERT((LEESA::ChildToParentConcept <ChildKind, ParentKind>));

	return ChainExpr(ChildKindExpr(l), OP());
}

template <class L, class H>
typename disable_if
  <IsDomainVisitorBaseOf<H>,
   ChainExpr<typename ET<L>::expression_type, 
 		         DFSParentOp<typename ET<L>::expression_type,
		 			               typename ET<H>::expression_type>
		        >
  >::type
operator <<= (L const &l, H const & h)
{
  BOOST_MPL_ASSERT_NOT((is_base_of<OpBase, H>));

	typedef typename ET<L>::expression_type ParentExpr;
	typedef typename ET<H>::expression_type ChildExpr;
	typedef DFSParentOp<ParentExpr, ChildExpr> Operator;
	typedef typename ET<L>::result_kind ChildKind;
	typedef typename ET<H>::argument_kind ParentKind;
	typedef ChainExpr<ParentExpr, Operator> ChainExpr;

  BOOST_CONCEPT_ASSERT((LEESA::ChildToParentConcept <ChildKind, ParentKind>));

  Operator op(h);
	return ChainExpr(ParentExpr(l), op);
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

#ifndef LEESA_NO_VISITOR

template <class L, class R>
ChainExpr<ChainExpr<typename ET<L>::expression_type,
                    VisitorOp<typename ET<L>::result_type>
                   >,
          DFSParentOp <ChainExpr<typename ET<L>::expression_type,
                                 VisitorOp<typename ET<L>::result_type>
                                >,
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
operator << (L const &l, DOMAIN_NAMESPACE::Visitor & v)
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
             ChainExpr<typename ChainedOperator<L,H,GetParentOp>::Op,
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

} // namespace LEESA
