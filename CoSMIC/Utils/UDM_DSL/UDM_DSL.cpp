#include <iostream>
#include <sstream>
#include <set>

#include "stdafx.h"

#include "UDM_DSL.h"
#include "HFSM.h"
#include "uml.h"

#include <boost/typeof/typeof.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>
#include <boost/regex.hpp>
#include <loki/TypeManip.h>

using namespace HFSM;
using namespace boost;
using namespace Udm;
using namespace Loki;

template <class ParentKind, class ChildKind>
struct ParentChildConcept
{
	typedef typename ParentKind::ChildrenKinds ChildrenKinds;
	void constraints()
	{
		enum { val = Loki::TL::IndexOf<ChildrenKinds, ChildKind>::value < 0 ? -1 : 1 };
		char temp[val];
		boost::ignore_unused_variable_warning(temp);
	}
};

#ifdef ENABLE_BOOST_MPL
#include "boost/mpl/vector.hpp"
#include "boost/mpl/size.hpp"
#include <boost/mpl/if.hpp>

template <class ParentKind, class ChildKind>
struct ParentOfChildN 
{
	typedef typename ParentKind::ChildrenKinds ChildrenKinds;
	void constraints()
	{
		BOOST_MPL_ASSERT((boost::mpl::contains<ChildrenKinds, ChildKind > ));
	}
};

#endif // ENABLE_BOOST_MPL

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

template <class Kind>
class KindLit
{
	Kind temp_kind_;
	std::set<Kind> s_;
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmObjectConcept);
	// This is an important concept. Don't remove.

public:
    typedef KindLit<Kind> expression_type;
	typedef KindLit<Kind> result_type;
	typedef KindLit<Kind> parameter_type;
	typedef Kind result_kind;
	typedef typename std::set<Kind>::iterator iterator;
	typedef typename std::set<Kind>::const_iterator const_iterator;

	explicit KindLit () {}
	KindLit (KindLit const & k) : s_ (k.s_) {}
	KindLit (Kind const & k) { s_.insert(k); }	
	KindLit (std::set<Kind> const & s) : s_(s) { }	
	//KindLit (Udm::ChildrenAttr<Kind> const & c) : s_(c) {}
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
	//std::set<Kind> & get_inner_set () { return s_; } 
	iterator begin() { return s_.begin(); }
	const_iterator begin() const { return s_.begin(); }

	iterator end() { return s_.end(); }
	const_iterator end() const { return s_.end(); }

	result_kind * operator -> ()
	{ 
		if (this->isEmpty())
		{
			std::ostringstream ostr;
			ostr << "Dereferencing an empty set of \"" 
				<< std::string(Kind::meta.name()) << "\"";
			throw std::runtime_error(ostr.str().c_str());
		}
		temp_kind_ = *(this->begin()); 
		return &temp_kind_;
	} 
	bool isEmpty() const 
	{
		return s_.empty();
	}
	operator std::set<Kind> () const { return s_; } 
	result_type operator () () const { return *this; }
	result_type operator () (parameter_type p) const { return p; }
};

template <class E, class OP>
struct UnaryExpr
{
	typedef UnaryExpr<E, OP> expression_type;
	typedef typename OP::result_type result_type;
	typedef typename result_type::result_kind result_kind;
	typedef typename E::parameter_type parameter_type;

	//BOOST_CONCEPT_ASSERT((boost::is_same<typename E::parameter_type,
	//									 typename OP::parameter_type));

	E e_;
	OP op_;
	explicit UnaryExpr () {} 
	UnaryExpr (UnaryExpr const & u) 
		: e_(u.e_), op_(u.op_) 
	{}
    explicit UnaryExpr (E const &e, OP const & op) 
		: e_(e), op_(op) {}
	result_type operator () () { return op_.apply (e_()); }
	result_type operator () (parameter_type p) { return op_.apply (e_(p)); }
};

template <class E>
struct TExpr 
{
	typedef TExpr<E> expression_type;
	typedef typename E::result_type result_type;
	typedef typename result_type::result_kind result_kind;
	typedef typename E::parameter_type parameter_type;

	E expr_;
	explicit TExpr() {} 
	TExpr(E const &e) : expr_ (e) {}
	result_type operator () () { return expr_(); }
	result_type operator () (parameter_type p) { return expr_(p); }
};

template <class T>
struct ExpressionTraits
{
	/* BOOST_CLASS_REQUIRE(T, Udm, UdmObjectConcept);
	   UdmObjectConcept check is disabled because user-defined
	   visitor types are possible parameters of this trait class.
	   In such a case, the following associated types do not make
	   sense. However, they are never instantiated and hence we are ok. */
	typedef KindLit<T> expression_type;
	typedef KindLit<T> result_type;
	typedef KindLit<T> parameter_type;
	typedef T result_kind;
};

template <class T, class U>
struct ExpressionTraits <T (*) (U)>
	: public ExpressionTraits <U> {};

template <class Kind>
struct ExpressionTraits <std::set<Kind> >
{
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmObjectConcept);
	typedef typename KindLit<Kind> expression_type;
	typedef typename KindLit<Kind> result_type;
	typedef typename KindLit<Kind> parameter_type;
	typedef typename Kind result_kind;
};

template <class T>
struct ETBase
{
	typedef typename T::expression_type expression_type;
	typedef typename T::result_type result_type;
	typedef typename T::parameter_type parameter_type;
	typedef typename T::result_kind result_kind;
};

template <class T>
struct ExpressionTraits <KindLit<T> >
	: public ETBase<KindLit<T> > {};

//template <class T, class U, class X>
//struct ExpressionTraits <DBinExpr<T,U,X> > 
//	: public ETBase <DBinExpr<T,U,X> > {};

template <class T, class X>
struct ExpressionTraits <UnaryExpr<T,X> > 
	: public ETBase <UnaryExpr<T,X> > {};

template <class T>
struct ExpressionTraits <TExpr<T> >
	: ETBase <TExpr<T> > {};

class SelectorOpBase {};

template <class E>
struct SelectorOp : public SelectorOpBase
{
	typedef typename TExpr<UnaryExpr<E, SelectorOp<E> > > expression_type;
	typedef typename ExpressionTraits<E>::result_type kind_lit;
	typedef kind_lit result_type;
	typedef kind_lit parameter_type;
	typedef typename kind_lit::result_kind result_kind;
	BOOST_CLASS_REQUIRE(result_kind, Udm, UdmObjectConcept);

	std::set<result_kind> s_;
	bool logical_not_; 
	//explicit SelectorOp (result_kind const & k) { s_.insert(k); }
	//explicit SelectorOp (std::set<kind_lit> const & s) : s_(s) { }
	explicit SelectorOp (kind_lit const & kl, bool logical_not = false) 
		: s_(kl), logical_not_(logical_not) {}
	SelectorOp (SelectorOp const & sop) 
		: logical_not_(sop.logical_not_), s_(sop.s_) {}
	result_type apply (kind_lit const & k)
	{
		result_type retval;
		std::set<result_kind> s = k();
		for (std::set<result_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			bool match = (s_.find(*iter) != s_.end());
			if (match ^ logical_not_) // Logical not of match, if required
				retval.Union((*iter));
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

class GetChildrenOpBase {};

template <class L, class H>
struct GetChildrenOp : public GetChildrenOpBase
{
	typedef typename ExpressionTraits<L>::result_type parent_lit;
	typedef typename ExpressionTraits<H>::result_type child_lit;
	typedef typename 
		TExpr<UnaryExpr<L,GetChildrenOp<parent_lit, child_lit> > > expression_type;
	typedef child_lit result_type;
	typedef parent_lit parameter_type;
	typedef typename child_lit::result_kind result_kind;

	explicit GetChildrenOp () {}
	explicit GetChildrenOp (H) {}
	/* A placehold parameter is required in above constructor because
	   other operators take a paramter but GetChildrenOp and GetParentOp
	   don't. So to bring syntactic consistency a dummy parameter is 
	   used here.*/

	GetChildrenOp (GetChildrenOp const &) {}
	result_type apply (parent_lit const & p)
	{
		typedef typename parent_lit::result_kind parent_kind;
		typedef typename child_lit::result_kind child_kind;
		BOOST_CONCEPT_ASSERT((ParentChildConcept<parent_kind, child_kind>));

		result_type retval;
		std::set<parent_kind> s = p();
		for (std::set<parent_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			retval.Union((*iter).children_kind<child_kind>());
		}
		return retval;
	}
};

class GetParentOpBase {};

template <class L, class H>
struct GetParentOp : public GetParentOpBase
{
	typedef typename ExpressionTraits<L>::result_type child_lit;
	typedef typename ExpressionTraits<H>::result_type parent_lit;
	typedef typename 
		TExpr<UnaryExpr<L,GetParentOp<child_lit, parent_lit> > > expression_type;

	typedef parent_lit result_type;
	typedef child_lit parameter_type;
	typedef typename parent_lit::result_kind result_kind;

	explicit GetParentOp () {}
	GetParentOp (typename ExpressionTraits<H>::expression_type) {}
	GetParentOp (GetParentOp const &) {}
	result_type apply (child_lit const & c)
	{
		typedef typename parent_lit::result_kind parent_kind;
		typedef typename child_lit::result_kind child_kind;
		BOOST_CONCEPT_ASSERT((ParentChildConcept<parent_kind, child_kind>));

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

class VisitorOpBase {};

template <class E>
struct VisitorOp : public VisitorOpBase
{
	typedef typename ExpressionTraits<E>::result_type kind_lit;
	typedef typename 
		TExpr<UnaryExpr<E,VisitorOp<kind_lit> > > expression_type;

	typedef kind_lit result_type;
	typedef kind_lit parameter_type;
	typedef typename kind_lit::result_kind result_kind;
	BOOST_CLASS_REQUIRE(result_kind, Udm, UdmObjectConcept);

	Visitor & visitor_;
	explicit VisitorOp (Visitor const &v) 
		: visitor_ (const_cast<Visitor &> (v)) {}
	VisitorOp (VisitorOp const & vop) : visitor_ (vop.visitor_) {}
	result_type apply (kind_lit const & k)
	{
		std::set<result_kind> s = k();
		for (std::set<result_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			(*iter).Accept(visitor_);
		}
		return k;
	}
};

class RegexOpBase {};

template <class E>
struct RegexOp : public RegexOpBase
{
	typedef typename ExpressionTraits<E>::result_type kind_lit;
	typedef typename 
		TExpr<UnaryExpr<E,RegexOp<kind_lit> > > expression_type;

	typedef kind_lit result_type;
	typedef kind_lit parameter_type;
	typedef typename kind_lit::result_kind result_kind;
	BOOST_CLASS_REQUIRE(result_kind, Udm, UdmObjectConcept);

	//boost::regex regex_;
	std::string regex_;
	bool logical_not_; 
	explicit RegexOp (std::string const & str = ".*", bool logical_not = false) 
		: logical_not_ (logical_not) { regex_.assign(str); }
	RegexOp (RegexOp const & reop) 
		: logical_not_ (reop.logical_not_), regex_ (reop.regex_) {}
	result_type apply (kind_lit const & k)
	{
		result_type retval;
		std::set<result_kind> s = k();
		for (std::set<result_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			//bool match = boost::regex_match(std::string((*iter).name()), regex_);
			bool match = (regex_ == std::string((*iter).name()));
			if (match ^ logical_not_) // Logical not of match, if required
				retval.Union((*iter));
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

class FilterOpBase {};

template <class Func>
struct FilterOp : public FilterOpBase
{
	typedef typename ExpressionTraits<Func>::result_type kind_lit;
	typedef typename 
		TExpr<UnaryExpr<kind_lit,FilterOp<Func> > > expression_type;

	typedef kind_lit result_type;
	typedef kind_lit parameter_type;
	typedef typename kind_lit::result_kind result_kind;
	BOOST_CLASS_REQUIRE(result_kind, Udm, UdmObjectConcept);

	Func func_;
	bool logical_not_; 
	explicit FilterOp (Func f, bool logical_not = false) 
		: func_(f), logical_not_ (logical_not) { }
	FilterOp (FilterOp const & fop) 
		: func_(fop.func_), logical_not_ (fop.logical_not_) {}
	result_type apply (kind_lit const & k)
	{
		result_type retval;
		std::set<result_kind> s = k();
		for (std::set<result_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			if (func_(*iter) ^ logical_not_) // Logical not of match, if required
				retval.Union((*iter));
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

template <class T>
struct ExpressionTraits <SelectorOp<T> > 
	: public ETBase <SelectorOp<T> > { };

template <class T>
struct ExpressionTraits <RegexOp<T> >
	: public ETBase <RegexOp<T> > {};

template <class T>
struct ExpressionTraits <VisitorOp<T> > 
	: public ETBase <VisitorOp<T> > { };

template <class T, class U> 
struct ExpressionTraits <GetChildrenOp<T, U> >
	: public ETBase <GetChildrenOp<T, U> > {};

template <class T, class U>
struct ExpressionTraits <GetParentOp<T, U> >
	: public ETBase <GetParentOp<T, U> > {};

template <class T>
RegexOp<typename ExpressionTraits<T>::result_type> 
SelectByName (T, const char * str)
{
	typedef typename ExpressionTraits<T>::result_type result_type;
	typedef typename result_type::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<result_kind>));
	RegexOp<result_type> regex(str);
	return regex;
}

template <class T>
SelectorOp<typename ExpressionTraits<T>::result_type> 
SelectSubSet (T const &t)
{
	typedef typename ExpressionTraits<T>::result_type result_type;
	typedef typename result_type::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<result_kind>));
	result_type kind_lit(t);
	SelectorOp<result_type> selector(kind_lit);
	return selector;
}

template <class Func>
FilterOp<Func> 
Filter (Func f)
{
	//typedef typename ExpressionTraits<Func>::result_type result_type;
	//typedef typename result_type::result_kind result_kind;
	
	//BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<result_kind>));
	FilterOp<Func> filter(f);
	return filter;
}

using boost::mpl::if_c;
using boost::is_base_of;

template <class L, class H, template <class, class> class Op>
// Note that here H can potentially be a type that is not an
// expression. For example, it can be a Visitor, RegexOP, SelectorOp 
// among others.
struct OpSelector
{
	typedef typename ExpressionTraits<L>::result_type LResultType;
	// Don't add expression traits of H here because H can be any new type such
	// as TestVisitor. We don't have traits defined for them. The traits
	// obtained only when required as done below.

	typedef typename 
		if_c<is_base_of<Visitor, H>::value, 
		     VisitorOp<LResultType>,
			 Op<LResultType, typename ExpressionTraits<H>::result_type> 
		    >::type Op;
};


template <class L, class H>
TExpr<UnaryExpr<typename ExpressionTraits<L>::expression_type, 
				typename OpSelector<L,H,GetChildrenOp>::Op
				>
	 >
/* Note that here H can potentially be a type that is not an
expression. For example, it can be a Visitor, RegexOP, SelectorOp 
among others. H must be a const reference to support default 
construction of kinds. */
operator > (L const &l, H const &h)
{
	typedef typename ExpressionTraits<L>::expression_type ParentKindExpr;
	typedef typename OpSelector<L,H,GetChildrenOp>::Op Operator;
	typedef typename ExpressionTraits<Operator>::result_kind ChildKind;
	typedef typename ParentKindExpr::result_kind ParentKind;

	BOOST_CONCEPT_ASSERT((ParentChildConcept <ParentKind, ChildKind>));

	typedef UnaryExpr<ParentKindExpr, 
		              typename OpSelector<L,H,GetChildrenOp>::Op> UnaryExpr;
	typedef TExpr<UnaryExpr> Expr;

	Operator op(h);
	return Expr (UnaryExpr(ParentKindExpr(l), op));
}

template <class L, class H>
TExpr<UnaryExpr<typename ExpressionTraits<L>::expression_type, 
				typename RegexOp<H>
				>
	 >
operator > (L const &l, RegexOp<H> const &h)
{
	typedef typename ExpressionTraits<L>::expression_type ParentKindExpr;
	typedef typename ExpressionTraits<RegexOp<H> >::result_kind ChildKind;
	typedef typename ParentKindExpr::result_kind ParentKind;
    typedef UnaryExpr<ParentKindExpr, RegexOp<H> > UnaryExpr;
	typedef TExpr<UnaryExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));
	RegexOp<H> op(h);
	return Expr (UnaryExpr(ParentKindExpr(l), op));
}

template <class L, class H>
TExpr<UnaryExpr<typename ExpressionTraits<L>::expression_type, 
				typename SelectorOp<H>
				>
	 >
operator > (L const &l, SelectorOp<H> const &h)
{
	typedef typename ExpressionTraits<L>::expression_type ParentKindExpr;
	typedef typename ExpressionTraits<SelectorOp<H> >::result_kind ChildKind;
	typedef typename ParentKindExpr::result_kind ParentKind;
    typedef UnaryExpr<ParentKindExpr, SelectorOp<H> > UnaryExpr;
	typedef TExpr<UnaryExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));
	SelectorOp<H> op(h);
	return Expr (UnaryExpr(ParentKindExpr(l), op));
}

template <class L, class H>
TExpr<UnaryExpr<typename ExpressionTraits<L>::expression_type, 
				typename FilterOp<H>
				>
	 >
operator > (L const &l, FilterOp<H> const &h)
{
	typedef typename ExpressionTraits<L>::expression_type ParentKindExpr;
	typedef typename ExpressionTraits<FilterOp<H> >::result_kind ChildKind;
	typedef typename ParentKindExpr::result_kind ParentKind;
    typedef UnaryExpr<ParentKindExpr, FilterOp<H> > UnaryExpr;
	typedef TExpr<UnaryExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));
	FilterOp<H> op(h);
	return Expr (UnaryExpr(ParentKindExpr(l), op));
}

template <class L, class H>
TExpr<UnaryExpr<typename ExpressionTraits<L>::expression_type, 
				typename OpSelector<L,H,GetParentOp>::Op
				>
	 >
operator < (L const &l, H const &h)
{
	//BOOST_CONCEPT_ASSERT((Convertible<H, RegexOpBase>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<RegexOpBase, H>));
	//BOOST_CONCEPT_ASSERT((Convertible<H, SelectorOpBase>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<SelectorOpBase, H>));
	//BOOST_CONCEPT_ASSERT((Convertible<H, Visitor>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<Visitor, H>));
	

	typedef typename ExpressionTraits<L>::expression_type ChildKindExpr;
	typedef typename ExpressionTraits<H>::result_kind ParentKind;
	typedef typename ChildKindExpr::result_kind ChildKind;

	BOOST_CONCEPT_ASSERT((ParentChildConcept <ParentKind, ChildKind>));
	
	typedef UnaryExpr<ChildKindExpr, 
		              typename OpSelector<L,H,GetParentOp>::Op> UnaryExpr;
	typedef TExpr<UnaryExpr> Expr;
	typename OpSelector<L,H,GetParentOp>::Op op(h);

	return Expr (UnaryExpr(ChildKindExpr(l), op));
}

template <class Expr>
typename Expr::result_type
evaluate (Expr &e)
{
	return e();
}

template <class Expr, class Para>
typename Expr::result_type
evaluate (Expr &e, Para p)
{
	// BOOST_CONCEPT_CHECK(e::parameter_type should be same as p);
	return e(p);
}

template <class T>
T operator * (T t)
{
	return t;
}
bool func (State) { return true; }
int foo (HFSM::RootFolder & rf)
{
	try {
		TestVisitor tv;
		//BOOST_AUTO(e1, RootFolder() > State() > tv);
		//BOOST_AUTO(e1, RootFolder() > State() > SelectByName(State(),"State2") > tv);
		BOOST_AUTO(e1, RootFolder() > State() > Filter(func) > tv);
		BOOST_AUTO(s, e1(rf));
		//AfxMessageBox (std::string(s->name()).c_str(), MB_OK| MB_ICONINFORMATION);
		//BOOST_AUTO(e2, e1 > !!!SelectSubSet(s) > tv);
		//evaluate(e2, rf);
		//BOOST_AUTO(t, evaluate(rf > Transition()));

	}
	catch (std::exception & e)
	{
		std::ostringstream ostr;
		ostr << "Exception: " << e.what();
		AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
	}

	return 999;
}

/*
template <class L, class H, class OP>
struct DBinExpr
{
	typedef DBinExpr<L, H, OP> expression_type;
	typedef typename OP::result_type result_type;
	typedef typename result_type::result_kind result_kind;

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
struct RecurseOpBase {};

template <class E>
struct RecurseOp : public RecurseOpBase
{
	typedef typename ExpressionTraits<E>::result_type kind_lit;
	typedef typename 
		TExpr<UnaryExpr<E,RecurseOp<kind_lit> > > expression_type;

	typedef kind_lit result_type;
	typedef kind_lit parameter_type;
	typedef typename kind_lit::result_kind result_kind;
	BOOST_CLASS_REQUIRE(result_kind, Udm, UdmObjectConcept);

	std::set<result_kind> s_;
	RecurseOp (RecurseOp const & reop) : s_(reop.s_) {}
	result_type apply (kind_lit const & k)
	{
		result_type retval;
		std::
		std::set<result_kind> s = k();
		for (std::set<result_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			helper (*iter);
		}
		return retval;
	}
	void helper (result_kind const & k)
	{
	}
};
*/
