#include <boost/utility/enable_if.hpp>
#include <boost/mpl/if.hpp>

using boost::enable_if_c;
using boost::enable_if;
using boost::mpl::if_;

namespace LEESA {


template <class L, class R, template<class, class> class Operator>
struct ChainedOperator
{
  typedef ChainExpr<typename ET<L>::expression_type, 
		                Operator<typename ET<L>::result_type,  
                             typename ET<R>::result_type>
		               > Op;
};


template <class L, class H>
typename disable_if_c
  <is_base_of<DOMAIN_NAMESPACE::Visitor, H>::value |
   is_base_of<std::ios_base, L>::value |
   is_base_of <OpBase, H>::value,
   typename ChainedOperator<L,H,GetChildrenOp>::Op>::type
operator >> (L const &l, H)
{
	typedef GetChildrenOp<typename ET<L>::result_type, 
                        typename ET<H>::result_type> OP;
	LOCAL_TYPEDEFS(L, OP);
	BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<ParentKind, ChildKind>));

	return ChainExpr(ParentKindExpr(l), OP());
}

template <class L>
typename 
  disable_if_c<is_base_of<std::ios_base, L>::value |
               is_base_of<VisitorAsIndexBase, L>::value, 
               ChainExpr<typename ET<L>::expression_type, 
                         VisitorOp<typename ET<L>::result_type> > 
              >::type
operator >> (L const &l, DOMAIN_NAMESPACE::Visitor & v)
{
	typedef VisitorOp<typename ET<L>::result_type> OP;
	LOCAL_TYPEDEFS(L, OP);
	BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<ParentKind, ChildKind>));

	return ChainExpr(ParentKindExpr(l), OP(v));
}

template <class L, class H>
typename 
  disable_if<is_base_of<std::ios_base, L>, 
             ChainExpr<typename ChainedOperator<L,H,GetChildrenOp>::Op,
             VisitorOp<typename ET<H>::result_type>
            > >::type
operator >> (L const &l, VisitorAsIndex<H> vi)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<H>::result_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind, ChildKind>));

  return l >> H() >> vi.getVisitor();
}

template <class L, class H>
typename 
disable_if <is_base_of<DOMAIN_NAMESPACE::Visitor, H>,
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
operator >> (VisitorAsIndex<L> vi, DOMAIN_NAMESPACE::Visitor & v)
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

template <class L, class OP>                              
typename disable_if_c<                                             
  is_base_of <VisitorAsIndexBase, L>::value |                     
  is_base_of <std::ios_base, L>::value |
  !is_base_of <OpBase, OP>::value,                             
  ChainExpr<typename ET< L >::expression_type, OP> >::type  
operator >> (L const &l, OP op) 
{                            
  LOCAL_TYPEDEFS(L, OP);                               
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<ParentKind, ChildKind>));
  return ChainExpr(ParentKindExpr(l), op);                   
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
typename disable_if
<is_base_of<DOMAIN_NAMESPACE::Visitor, R>,
 ChainExpr<typename ET<L>::expression_type, 
 		       DFSChildrenOp<typename ET<L>::expression_type,
		 			               typename ET<R>::expression_type>
		      >
>::type
operator >>= (L const &l, R const &r)
{
	BOOST_MPL_ASSERT_NOT((is_base_of<OpBase, R>));

	typedef typename ET<L>::expression_type ParentExpr;
	typedef typename ET<R>::expression_type ChildExpr;
	typedef DFSChildrenOp<ParentExpr, ChildExpr> Operator;
	typedef typename ET<L>::result_kind ParentKind;
	typedef typename ET<R>::argument_kind ChildKind;

  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind, ChildKind>));

	typedef ChainExpr<ParentExpr, Operator> ChainExpr;

	Operator op(r);
	return ChainExpr(ParentExpr(l), op);
}

template <class L, class R>
ChainExpr<typename ET<L>::expression_type, 
          DFSChildrenOp<typename ET<L>::expression_type,
                        ChainExpr<typename ET<R>::expression_type, 
                                  VisitorOp<typename ET<R>::result_type> 
                                 > 
                       > 
         >
operator >>= (L const &l, VisitorAsIndex<R> vi)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<R>::result_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind,ChildKind>));

  return l >>= R() >> vi.getVisitor();
}

template <class L, class R>
typename disable_if <is_base_of <OpBase, R>,
         ChainExpr<ChainExpr<typename ET<L>::expression_type,
                    VisitorOp<typename ET<L>::result_type>
                   >,
          DFSChildrenOp <ChainExpr<typename ET<L>::expression_type,
                                   VisitorOp<typename ET<L>::result_type>
                                  >,
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

template <class L, class R>
typename enable_if<is_base_of<OpBase, R>,
                   ChainExpr<ChainExpr<typename ET<L>::expression_type,
                                       VisitorOp<typename ET<L>::result_type>
                                      >,
                             R> 
                  >::type
operator >>= (VisitorAsIndex<L> vi, R const &r)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<R>::argument_kind ChildKind;
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept <ParentKind,ChildKind>));

  return L() >> vi.getVisitor() >> r;
}

template <class L, class R>
ChainExpr<ChainExpr<typename ET<L>::expression_type,
                    VisitorOp<typename ET<L>::result_type>
                   >,
          DFSChildrenOp <ChainExpr<typename ET<L>::expression_type,
                                   VisitorOp<typename ET<L>::result_type>
                                  >,
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

  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<LKind, RKind>));

	typedef ChainExpr<LExpr, Operator> ChainExpr;

	Operator op(r);
	return ChainExpr(LExpr(l), op);
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

} // namespace LEESA
