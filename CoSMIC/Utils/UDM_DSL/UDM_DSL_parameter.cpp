#include <iostream>
#include <sstream>
#include <set>

#include "stdafx.h"

#include "UDM_DSL.h"
#include "HFSM.h"
#include "boost/mpl/vector.hpp"
#include "boost/mpl/size.hpp"
#include <boost/mpl/if.hpp>
#include <boost/type_traits.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/regex.hpp>

using namespace HFSM;
using namespace boost;
using namespace Udm;

class TestVisitor : public Visitor
{
public:
	virtual void Visit_InputSequence(const InputSequence&)
	{	}
	virtual void Visit_Events(const Events &e)
	{
		std::ostringstream ostr;
		ostr << "Visiting Event: " << e.name();
		AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
	}
	virtual void Visit_Sequence(const HFSM::Sequence&){};
	virtual void Visit_State(const State &s)
	{
		std::ostringstream ostr;
		ostr << "Visiting State: " << s.name();
		AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
	}
	virtual void Visit_Transition(const Transition&){};
	virtual void Visit_RootFolder(const RootFolder&)
	{
		AfxMessageBox ("Visiting RootFolder", MB_OK| MB_ICONINFORMATION);
	}
	virtual void Visit_Object(const Udm::Object&){};
	virtual ~TestVisitor(){};
};

template <class T>
struct ExpressionTraits;

template <class ParentKind, class ChildKind>
struct GetChildrenOp;

template <class Kind>
class KindLit
{
	std::set<Kind> s_;
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmObjectConcept);

public:
    typedef KindLit<Kind> expression_type;
	typedef KindLit<Kind> result_type;
	typedef Kind kind_type;

	explicit KindLit () {}
	KindLit (KindLit const & k) : s_ (k.s_) {}
	KindLit (Kind const & k) { s_.insert(k); }	
	//explicit KindLit (Udm::ChildrenAttr<Kind> const & c) : s_(c) {}
	void Union(Kind const & k)
	{
		s_.insert(k);
	}
	void Union(Udm::ChildrenAttr<Kind> const & c) 
	{
		std::set<Kind> s = c;
		s_.insert(s.begin(), s.end());
	}
	void Union(Udm::ParentAttr<Kind> const & c) 
	{
		Kind k = c;
		s_.insert(k);
	}
	operator std::set<Kind> () const { return s_; } 
	result_type operator () () const { return *this; }
	result_type operator () (Kind k) const { return KindLit<kind>(k); }
};

template </*class E,*/ class OP>
struct UnaryExpr
{
	typedef UnaryExpr</*E, */OP> expression_type;
	typedef typename OP::parameter_type parameter_type;
	typedef typename OP::result_type result_type;
	typedef typename result_type::kind_type kind_type;

	//E e_;
	OP op_;
	explicit UnaryExpr () {} 
	UnaryExpr (UnaryExpr const & u) 
		: /*e_(u.e_),*/ op_(u.op_) 
	{}
    explicit UnaryExpr (/*E const &e,*/ OP const & op) 
		: /*e_(e), */op_(op) {}
	//result_type operator () () { return op_.apply (e_()); }
	result_type operator () (parameter_type p) { return op_.apply (p); }
};

template <class E>
struct TExpr 
{
	typedef TExpr<E> expression_type;
	typedef typename E::parameter_type parameter_type;
	typedef typename E::result_type result_type;
	typedef typename result_type::kind_type kind_type;

	//E expr_;
	//explicit TExpr() {} 
	//TExpr(E const &e) : expr_ (e) {}
	TExpr() {}
	//result_type operator () () { return expr_(); }
	result_type operator () (parameter_type p) { E e; return /*expr_(p)*/ e(p); }
};

template <class T>
struct ExpressionTraits
{
	typedef KindLit<T> expression_type;
	typedef KindLit<T> result_type;
};

template <class T>
struct ExpressionTraits <KindLit<T> >
{
	typedef typename KindLit<T> expression_type;
	typedef typename KindLit<T>::result_type result_type;
};

template </*class T,*/ class X>
struct ExpressionTraits <UnaryExpr</*T,*/X> >
{
	typedef typename UnaryExpr</*T,*/X> expression_type;
	typedef typename X::result_type result_type;
};

template <class T>
struct ExpressionTraits <TExpr<T> >
{
	typedef typename TExpr<T> expression_type;
	typedef typename TExpr<T>::result_type result_type;
};

template <class L, class H>
struct GetChildrenOp
{
	typedef typename ExpressionTraits<L>::result_type parent_lit;
	typedef typename ExpressionTraits<H>::result_type child_lit;
	typedef parent_lit parameter_type;
	typedef child_lit result_type;

	explicit GetChildrenOp () {}
	GetChildrenOp (typename ExpressionTraits<H>::expression_type) {}
	GetChildrenOp (GetChildrenOp const &) {}
	result_type apply (parameter_type const & p)
	{
		typedef typename parent_lit::kind_type parent_kind;
		typedef typename child_lit::kind_type child_kind;
		boost::function_requires <Udm::ParentOfChildN<parent_kind, child_kind> > ();

		result_type retval;
		std::set<parent_kind> s = p();
		for (std::set<parent_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			retval.Union((*iter).kind_children<child_kind>());
		}
		return retval;
	}
};

template <class L, class H>
struct GetParentOp
{
	typedef typename ExpressionTraits<L>::result_type child_lit;
	typedef typename ExpressionTraits<H>::result_type parent_lit;
	typedef child_lit parameter_type;
	typedef parent_lit result_type;

	explicit GetParentOp () {}
	GetParentOp (typename ExpressionTraits<H>::expression_type) {}
	GetParentOp (GetParentOp const &) {}
	result_type apply (parameter_type const & c)
	{
		typedef typename parent_lit::kind_type parent_kind;
		typedef typename child_lit::kind_type child_kind;
		boost::function_requires <Udm::ParentOfChildN<parent_kind, child_kind> > ();

		result_type retval;
		std::set<child_kind> s = c();
		for (std::set<child_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			retval.Union((*iter).parent<parent_kind>());
		}
		return retval;
	}
};


template <class E, class V>
struct VisitorOp
{
	typedef typename ExpressionTraits<E>::result_type kind_lit;
	typedef kind_lit result_type;
	typedef kind_lit parameter_type;
	typedef typename kind_lit::kind_type kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	V visitor_;
	explicit VisitorOp (V v) : visitor_ (v) {}
	VisitorOp (VisitorOp const & vop) : visitor_ (vop.visitor_) {}
	result_type apply (parameter_type const & k)
	{
		std::set<kind> s = k();
		for (std::set<kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			(*iter).Accept(visitor_);
		}
		return k;
	}
};

template <class E>
struct RegexOp
{
	typedef typename ExpressionTraits<E>::result_type kind_lit;
	typedef kind_lit result_type;
	typedef kind_lit parameter_type;
	typedef typename kind_lit::kind_type kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	std::string regex_;
	explicit RegexOp (std::string const & re) : regex_(re) {}
	RegexOp (RegexOp const & reop) : regex_ (reop.regex_) {}
	result_type apply (parameter_type const & k)
	{
		result_type retval;
		std::set<kind> s = k();
		for (std::set<kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			boost::regex re;
			re.assign(regex_);
			if (boost::regex_match(std::string((*iter).name()), re))
				retval.Union((*iter));
			
			if (regex_ == std::string((*iter).name()))
				retval.Union((*iter));
		}
		return retval;
	}
};

template <class L, class H>
struct GTOpSelector
{
	typedef typename
		boost::mpl::if_c<
			boost::is_convertible<H, Udm::BaseVisitor>::value,
			VisitorOp<typename ExpressionTraits<L>::expression_type, H>,
			typename boost::mpl::if_c<
				boost::is_convertible<H, const char *>::value,
					RegexOp <typename ExpressionTraits<L>::expression_type>,
					GetChildrenOp<typename ExpressionTraits<L>::expression_type,
					              typename ExpressionTraits<H>::expression_type>
							>::type  
		>::type Op;
};


template <class L, class H>
TExpr<UnaryExpr</*typename ExpressionTraits<L>::expression_type, */
				typename GTOpSelector<L,H>::Op
				>
	 >
//operator > (L const &l, H h)
operator > (L, H)
{
	typedef typename ExpressionTraits<L>::expression_type ParentKindExpr;
	typedef UnaryExpr</*ParentKindExpr, */
		              typename GTOpSelector<L,H>::Op > UnaryExpr;
	typedef TExpr<UnaryExpr> Expr;
	//typename GTOpSelector<L,H>::Op op(h);
	//typename GTOpSelector<L,H>::Op op;
	//return Expr (UnaryExpr(ParentKindExpr(l), op));
	//UnaryExpr ue(op);
	Expr e;
	return e;
}

template <class L, class H>
struct LTOpSelector
{
	typedef typename
		boost::mpl::if_c<
			boost::is_convertible<H, Udm::BaseVisitor>::value,
			VisitorOp<typename ExpressionTraits<L>::expression_type, H>,
			typename boost::mpl::if_c<
				boost::is_convertible<H, const char *>::value,
					RegexOp <typename ExpressionTraits<L>::expression_type>,
					GetParentOp<typename ExpressionTraits<L>::expression_type,
			 				    typename ExpressionTraits<H>::expression_type>
							>::type
		>::type Op;
};

template <class L, class H>
TExpr<UnaryExpr</*typename ExpressionTraits<L>::expression_type, */
				typename LTOpSelector<L,H>::Op
				>
	 >
//operator < (L const &l, H h)
operator < (L, H)
{
	typedef typename ExpressionTraits<L>::expression_type ParentKindExpr;
	typedef UnaryExpr</*ParentKindExpr, */
		              typename LTOpSelector<L,H>::Op > UnaryExpr;
	typedef TExpr<UnaryExpr> Expr;
	//typename LTOpSelector<L,H>::Op op(h);
	typename LTOpSelector<L,H>::Op op;
	//return Expr (UnaryExpr(ParentKindExpr(l), op));
	return Expr (UnaryExpr(op));
}

template <class Expr>
typename Expr::result_type
evaluate (Expr &e)
{
	return e();
}

int foo (HFSM::RootFolder & rf)
{
/*	typedef TExpr<KindLit<RootFolder> > RootFolderExpr;
    typedef TExpr<KindLit<State> > StateExpr;
	typedef GetChildrenOp<RootFolderExpr, StateExpr> R_S_Getter;

	typedef DBinExpr<RootFolderExpr, StateExpr, R_S_Getter> BinExpr;
	typedef TExpr<BinExpr> Expr;
	RootFolderExpr rf_expr(rf);
	Expr e1(BinExpr (rf_expr, StateExpr(), R_S_Getter()));

	typedef GetChildrenOp<StateExpr, StateExpr> S_S_Getter;
	typedef DBinExpr<Expr, StateExpr, S_S_Getter> BinExpr2;
	typedef TExpr <BinExpr2> Expr2;
	Expr2 e2(BinExpr2(
				Expr (BinExpr(rf_expr, StateExpr(), R_S_Getter())), 
				StateExpr(), 
				S_S_Getter()
				));
*/
	try {
		TestVisitor tv;
		//BOOST_AUTO(result, evaluate(rf > tv > State() > tv > State() > tv));
		BOOST_AUTO(e, RootFolder() > State() > State());
		//evaluate (e > State() > tv);
		e(rf);
		//evaluate (rf > InputSequence() > State());
	}
	catch (std::exception & e)
	{
		std::ostringstream ostr;
		ostr << "Exception: " << e.what();
		AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
	}


	typedef mpl::vector <int, long, float, double> Numericals;
	return mpl::size<Numericals>::type::value;
}

/*
template <class L, class H, class OP>
struct DBinExpr
{
	typedef DBinExpr<L, H, OP> expression_type;
	typedef typename OP::result_type result_type;
	typedef typename result_type::kind_type kind_type;

	L l_;
	H h_;
	OP op_;
	explicit DBinExpr () {}
	DBinExpr (DBinExpr const & e) 
		: l_(e.l_), h_(e.h_), op_(e.op_) 
	{}
    explicit DBinExpr (L const &l, H const &h, OP const & op) 
		: l_(l), h_(h), op_(op) {}
	result_type operator () () const { return op_.apply (l_(), h_()); }
};
*/

/*
template <class Expr>
TExpr<UnaryExpr<typename ExpressionTraits<Expr>::expression_type,
                RegexOp<typename ExpressionTraits<Expr>::expression_type> 
			   > 
	 >
Select (Expr, std::string const &str)
{
	typedef UnaryExpr<typename ExpressionTraits<Expr>::expression_type,
		              RegexOp<typename ExpressionTraits<Expr>::expression_type> >
			UExpr;
	return TExpr<UExpr> (UExpr(Reg));
}
*/

/*
template <class T, class U, class X>
struct ExpressionTraits <DBinExpr<T,U,X> >
{
	typedef typename DBinExpr<T,U,X> expression_type;
	typedef typename DBinExpr<T,U,X>::result_type result_type;
};
*/