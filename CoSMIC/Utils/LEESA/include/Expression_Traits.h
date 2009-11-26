#include <set>
#include <vector>

#define ExpressionTraits1Para(OP)     \
template <class T>                    \
struct ET <OP<T> >                    \
  : public ETBase <OP<T> > {};

#define ExpressionTraits2Para(OP)     \
template <class T, class U>           \
struct ET <OP<T, U> >                 \
  : public ETBase <OP<T, U> > {};

#define ExpressionTraits3Para(OP)     \
template <class X, class Y, class Z>  \
struct ET <OP<X, Y, Z> >              \
  : public ETBase <OP<X, Y, Z> > {};


namespace LEESA {

template <class T>
struct ET
{
	/* BOOST_CLASS_REQUIRE(T, LEESA, DomainKindConcept);
	   DomainKindConcept check is disabled because user-defined
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
	BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);
	typedef KindLit<Kind> expression_type;
	typedef KindLit<Kind> result_type;
	typedef KindLit<Kind> argument_type;
	typedef Kind result_kind;
	typedef Kind argument_kind;
};

template <class Kind>
struct ET <std::vector<Kind> >
{
	BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);
	typedef KindLit<Kind> expression_type;
	typedef KindLit<Kind> result_type;
	typedef KindLit<Kind> argument_type;
	typedef Kind result_kind;
	typedef Kind argument_kind;
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

ExpressionTraits1Para(KindLit);
ExpressionTraits1Para(SelectorOp);
ExpressionTraits1Para(RegexOp);
#ifndef LEESA_NO_VISITOR
ExpressionTraits1Para(VisitorOp);
#endif // LEESA_NO_VISITOR

ExpressionTraits2Para(ChainExpr);
ExpressionTraits2Para(SequenceExpr);
ExpressionTraits2Para(GetChildrenOp);
ExpressionTraits2Para(DFSChildrenOp);
ExpressionTraits2Para(DFSParentOp);
ExpressionTraits2Para(GetParentOp);
ExpressionTraits2Para(DFSOp);
ExpressionTraits2Para(FilterOp);
ExpressionTraits2Para(ForEachOp);
ExpressionTraits2Para(SortOp);
ExpressionTraits2Para(UniqueOp);

#ifdef LEESA_FOR_UDM

ExpressionTraits1Para(NonNullOp);
ExpressionTraits2Para(CastOp);
ExpressionTraits2Para(AssociationOp);
ExpressionTraits2Para(AssociationEndOp);
ExpressionTraits3Para(AssociationManyOp);

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*)() const>
	: public ETBase <AssociationOp<RESULT, TARGETCLASS> > {};

template <class ASSOC, class SOURCECLASS, class TARGETCLASS>
struct ET <Udm::AClassAssocAttr<ASSOC, TARGETCLASS> (SOURCECLASS::*)() const>
	: public ETBase <AssociationManyOp<ASSOC, SOURCECLASS, TARGETCLASS> > {};

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AssocEndAttr<RESULT> (TARGETCLASS::*)() const>
	: public ETBase <AssociationEndOp<RESULT, TARGETCLASS> > {};

#endif // LEESA_FOR_UDM


template <class L, class R = L>
struct LEESAUnaryFunction 
	: public std::unary_function <typename ET<L>::argument_type,
	           	                  typename ET<R>::result_type>
{
  typedef typename ET<L>::argument_kind argument_kind;
  typedef typename ET<L>::argument_type argument_type;
  typedef typename ET<R>::result_kind result_kind;
  typedef typename ET<R>::result_type result_type;

	//BOOST_CLASS_REQUIRE(result_kind, LEESA, DomainKindConcept);
	BOOST_CLASS_REQUIRE(argument_kind, LEESA, DomainKindConcept);
};

template <class L>
struct LEESAUnaryFunction <L, void> 
	: public std::unary_function <typename ET<L>::argument_type,
	           	                  void>
{
  typedef typename ET<L>::argument_kind argument_kind;
  typedef typename ET<L>::argument_type argument_type;
  typedef void result_kind;
  typedef void result_type;

	//BOOST_CLASS_REQUIRE(result_kind, LEESA, DomainKindConcept);
	BOOST_CLASS_REQUIRE(argument_kind, LEESA, DomainKindConcept);
};


} // namespace LEESA
