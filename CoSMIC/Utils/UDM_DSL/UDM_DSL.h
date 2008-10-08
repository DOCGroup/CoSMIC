#ifndef __UDM_DSL_H
#define __UDM_DSL_H

#include <vector>

#include "HFSM.h"
#include "uml.h"

#include <boost/typeof/typeof.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>
#include <boost/regex.hpp>
#include <boost/foreach.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/if.hpp>

#include "UdmObjectConcept.h"

int foo (HFSM::RootFolder &);

template <class ParentKind, class ChildKind>
struct ParentChildConcept 
{
	void constraints()
	{
    typedef typename ParentKind::ChildrenKinds ChildrenKinds;
		BOOST_MPL_ASSERT((boost::mpl::contains<ChildrenKinds, ChildKind > ));
	}
};

namespace HFSM {

template <class Kind> class KindLit;
template <class L, class R> struct ChainExpr;
template <class L, class R> struct SequenceExpr;

//template <class A, class B, class C> struct Members2Op;
//template <class A, class B, class C, class D> struct Members3Op;
//template <class A, class B, class C, class D, class E> struct Members4Op;
//template <class A, class B, class C, class D, class E, class F> struct Members5Op;

template <class L, class R> struct GetChildrenOp;
template <class L, class R> struct DFSChildrenOp;
template <class L, class R> struct DFSOp;
template <class L, class R> struct GetParentOp;
template <class L, class R> struct CastOp;
template <class RESULT, class TARGETCLASS> struct AssociationOp;
template <class RESULT, class TARGETCLASS> struct AssociationEndOp;
template <class RESULT, class TARGETCLASS> struct AssociationManyOp;

template <class E> struct SelectorOp;
template <class E> struct VisitorOp;
template <class E> struct RegexOp;

template <class E, class Func> struct FilterOp;
template <class E, class Comp> struct SortOp;
template <class E, class BinPred> struct UniqueOp;

template <class T>
struct ET
{
	/* BOOST_CLASS_REQUIRE(T, Udm, UdmKindConcept);
	   UdmKindConcept check is disabled because user-defined
	   visitor types are possible parameters of this trait class.
	   In such a case, the following associated types do not make
	   sense. However, they are never instantiated and hence we are ok. */
	typedef KindLit<T> expression_type;
	typedef KindLit<T> result_type;
	typedef KindLit<T> argument_type;
	typedef T result_kind;
	typedef T argument_kind;
};

template <class T, class U>
struct ET <T (*) (U)>
{
	typedef KindLit<U> expression_type;
	typedef KindLit<T> result_type;
	typedef KindLit<U> argument_type;
	typedef T result_kind;
	typedef U argument_kind;
};

template <class Kind>
struct ET <std::set<Kind> >
{
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmKindConcept);
	typedef typename KindLit<Kind> expression_type;
	typedef typename KindLit<Kind> result_type;
	typedef typename KindLit<Kind> argument_type;
	typedef typename Kind result_kind;
	typedef typename Kind argument_kind;
};

template <class Kind>
struct ET <std::vector<Kind> >
{
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmKindConcept);
	typedef typename KindLit<Kind> expression_type;
	typedef typename KindLit<Kind> result_type;
	typedef typename KindLit<Kind> argument_type;
	typedef typename Kind result_kind;
	typedef typename Kind argument_kind;
};

template <class T>
struct ETBase
{
	typedef typename T::expression_type expression_type;
	typedef typename T::result_type result_type;
	typedef typename T::argument_type argument_type;
	typedef typename T::result_kind result_kind;
	typedef typename T::argument_kind argument_kind;
};

template <class T>
struct ET <KindLit<T> >	
	: public ETBase<KindLit<T> > {};

template <class T, class X>
struct ET <ChainExpr<T, X> > 
	: public ETBase <ChainExpr<T, X> > {};

template <class T, class X>
struct ET <SequenceExpr<T, X> > 
	: public ETBase <SequenceExpr<T, X> > {};

template <class T>
struct ET <SelectorOp<T> > 
	: public ETBase <SelectorOp<T> > { };

template <class T>
struct ET <RegexOp<T> >	
	: public ETBase <RegexOp<T> > {};

template <class T>
struct ET <VisitorOp<T> > 
	: public ETBase <VisitorOp<T> > { };

template <class T, class U> 
struct ET <GetChildrenOp<T, U> > 
	: public ETBase <GetChildrenOp<T, U> > {};

template <class T, class U> 
struct ET <DFSChildrenOp<T, U> > 
	: public ETBase <DFSChildrenOp<T, U> > {};

template <class T, class U> 
struct ET <DFSOp<T, U> > 
	: public ETBase <DFSOp<T, U> > {};

template <class T, class U>
struct ET <GetParentOp<T, U> > 
	: public ETBase <GetParentOp<T, U> > {};

template <class T, class U>
struct ET <FilterOp<T, U> > 
	: public ETBase <FilterOp<T, U> > {};

template <class T, class Comp>
struct ET <SortOp<T, Comp> > 
	: public ETBase <SortOp<T, Comp> > {};

template <class L, class H>
struct ET <CastOp<L, H> > 
	: public ETBase <CastOp<L, H> > {};

template <class T, class BinPred>
struct ET <UniqueOp<T, BinPred> > 
	: public ETBase <UniqueOp<T, BinPred> > {};

template <class RESULT, class TARGETCLASS>
struct ET <AssociationOp<RESULT, TARGETCLASS> > 
	: public ETBase <AssociationOp<RESULT, TARGETCLASS> > {};

template <class RESULT, class TARGETCLASS>
struct ET <AssociationEndOp<RESULT, TARGETCLASS> > 
	: public ETBase <AssociationOp<RESULT, TARGETCLASS> > {};

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*)() const>
	: public ETBase <AssociationOp<RESULT, TARGETCLASS> > {};

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AClassAssocAttr<RESULT, TARGETCLASS> (TARGETCLASS::*)() const>
	: public ETBase <AssociationManyOp<RESULT, TARGETCLASS> > {};

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AssocEndAttr<RESULT> (TARGETCLASS::*)() const>
	: public ETBase <AssociationEndOp<RESULT, TARGETCLASS> > {};


template <class L, class R = L>
struct MyUnaryFunction 
	: public std::unary_function <typename ET<L>::argument_type,
	           	                  typename ET<R>::result_type>
{
	typedef typename ET<L>::argument_kind argument_kind;
	typedef typename ET<R>::result_kind result_kind;

	//BOOST_CLASS_REQUIRE(result_kind, Udm, UdmKindConcept);
	BOOST_CLASS_REQUIRE(argument_kind, Udm, UdmKindConcept);
};

} // namespace HFSM

#define LOCAL_TYPEDEFS(L, OP)                                           \
	typedef typename ET< L >::expression_type ParentKindExpr;           \
	typedef typename ET< OP >::argument_kind ChildKind;                 \
	typedef typename ParentKindExpr::result_kind ParentKind;            \
    typedef ChainExpr<ParentKindExpr, OP > ChainExpr;                   \
	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));


#define GT_PARA_OPERATOR_DEFINITION_2T(L,H,OPERATOR)               \
template < class L, class H >                                 \
ChainExpr<typename ET< L >::expression_type, OPERATOR >       \
operator >> (L const &l, OPERATOR op) {                        \
	LOCAL_TYPEDEFS(L, OPERATOR);                              \
	return ChainExpr(ParentKindExpr(l), op);                  \
}


#define GT_PARA_OPERATOR_DEFINITION_3T(L,H,X,OPERATOR)          \
template <class L, class H, class X >                      \
ChainExpr<typename ET< L >::expression_type, OPERATOR >    \
operator >> (L const &l, OPERATOR op) {                     \
	LOCAL_TYPEDEFS(L, OPERATOR);                           \
	return ChainExpr(ParentKindExpr(l), op);               \
}




#endif // __UDM_DSL_H
