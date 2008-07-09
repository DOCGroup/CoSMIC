#include <iostream>
#include <sstream>
#include <set>
#include <functional>

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
	virtual void Visit_Transition(const Transition &t)
	{
		std::ostringstream ostr;
		ostr << "Visiting Transition: " << t.name();
		AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
	}
	virtual void Visit_RootFolder(const RootFolder&)
	{
		AfxMessageBox ("Visiting RootFolder", MB_OK| MB_ICONINFORMATION);
	}
	virtual void Visit_Object(const Udm::Object&){};
	virtual ~TestVisitor(){};
};

template <class Kind>
class KindLit : public unary_function <KindLit<Kind>, KindLit<Kind> >
{
	typedef std::vector<Kind> Container;
	Kind temp_kind_;
	Container s_;
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmObjectConcept);
	// This is an important concept. Don't remove.

public:
    typedef KindLit<Kind> expression_type;
	typedef Kind kind;
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	explicit KindLit () {}
	KindLit (KindLit const & k) : s_ (k.s_) {}
	KindLit (Kind const & k) { s_.push_back(k); }	
	KindLit & operator = (KindLit const & rhs) 
	{ 
		if (this != &rhs)
		{
			temp_kind_ = rhs.temp_kind_;
			s_ = rhs.s_; 
		}
		return *this;
	}	
	KindLit (Container const & s) : s_(s) { }	
	//KindLit (Udm::ChildrenAttr<Kind> const & c) : s_(c) {}
	void Union(Kind const & k)
	{
		s_.push_back(k);
	}
	void Union(Udm::ChildrenAttr<Kind> const & c) 
	{
		Container s = c;
		std::copy(s.begin(), s.end(), std::back_inserter(s_));
	}
	void Union(Udm::ParentAttr<Kind> const & c) 
	{
		Kind k = c;
		s_.push_back(k);
	}
	void Union(std::vector<Kind> const & v)
	{
		std::copy(v.begin(), v.end(), std::back_inserter(s_));
	}
	//Container & get_inner_set () { return s_; } 
	iterator begin() { return s_.begin(); }
	const_iterator begin() const { return s_.begin(); }

	iterator end() { return s_.end(); }
	const_iterator end() const { return s_.end(); }

	kind * operator -> ()
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
	operator Container () const { return s_; } 
	//result_type operator () () const { return *this; }
	result_type operator () (argument_type p) const { return p; }
};

template <class T>
struct ET
{
	/* BOOST_CLASS_REQUIRE(T, Udm, UdmObjectConcept);
	   UdmObjectConcept check is disabled because user-defined
	   visitor types are possible parameters of this trait class.
	   In such a case, the following associated types do not make
	   sense. However, they are never instantiated and hence we are ok. */
	typedef KindLit<T> expression_type;
	typedef KindLit<T> result_type;
	typedef KindLit<T> argument_type;
	typedef T kind;
};

template <class T, class U>
struct ET <T (*) (U)>
	: public ET <U> {};

template <class Kind>
struct ET <std::set<Kind> >
{
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmObjectConcept);
	typedef typename KindLit<Kind> expression_type;
	typedef typename KindLit<Kind> result_type;
	typedef typename KindLit<Kind> argument_type;
	typedef typename Kind kind;
};

template <class Kind>
struct ET <std::vector<Kind> >
{
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmObjectConcept);
	typedef typename KindLit<Kind> expression_type;
	typedef typename KindLit<Kind> result_type;
	typedef typename KindLit<Kind> argument_type;
	typedef typename Kind kind;
};

template <class E, class OP>
struct ChainExpr : public unary_function <typename E::argument_type,
						          	      typename OP::result_type>
{
	typedef ChainExpr<E, OP> expression_type;
	typedef typename ET<result_type>::kind kind;

	//BOOST_CONCEPT_ASSERT((boost::is_same<typename E::argument_type,
	//									 typename OP::argument_type));

	E e_;
	OP op_;
	explicit ChainExpr () {} 
	ChainExpr (ChainExpr const & u) 
		: e_(u.e_), op_(u.op_) 
	{}
    explicit ChainExpr (E const &e, OP const & op) 
		: e_(e), op_(op) {}
	//result_type operator () () { return op_(e_()); }
	result_type operator () (argument_type p) { return op_(e_(p)); }
};

template <class E>
struct TExpr : public unary_function <typename E::argument_type,
						          	  typename E::result_type>
{
	typedef TExpr<E> expression_type;
	typedef typename ET<result_type>::kind kind;

	E expr_;
	explicit TExpr() {} 
	TExpr(E const &e) : expr_ (e) {}
	//result_type operator () () { return expr_(); }
	result_type operator () (argument_type p) { return expr_(p); }
};


template <class T>
struct ETBase
{
	typedef typename T::expression_type expression_type;
	typedef typename T::result_type result_type;
	typedef typename T::argument_type argument_type;
	typedef typename T::kind kind;
};

template <class T>
struct ET <KindLit<T> >
	: public ETBase<KindLit<T> > {};

//template <class T, class U, class X>
//struct ET <DBinExpr<T,U,X> > 
//	: public ETBase <DBinExpr<T,U,X> > {};

template <class T, class X>
struct ET <ChainExpr<T,X> > 
	: public ETBase <ChainExpr<T,X> > {};

template <class T>
struct ET <TExpr<T> >
	: ETBase <TExpr<T> > {};

struct SelectorOpBase{};

template <class E>
struct SelectorOp : public unary_function <typename E::argument_type,
						          	       typename E::result_type>,
				    public SelectorOpBase
{
	typedef typename TExpr<ChainExpr<E, SelectorOp<E> > > expression_type;
	typedef typename ET<E>::result_type kind_lit;
	typedef typename kind_lit::kind kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	std::vector<kind> s_;
	bool logical_not_; 
	//explicit SelectorOp (kind const & k) { s_.push_back(k); }
	//explicit SelectorOp (std::vector<kind_lit> const & s) : s_(s) { }
	explicit SelectorOp (kind_lit const & kl, bool logical_not = false) 
		: s_(kl), logical_not_(logical_not) {}
	SelectorOp (SelectorOp const & sop) 
		: logical_not_(sop.logical_not_), s_(sop.s_) {}
	result_type operator () (argument_type const & k)
	{
		result_type retval;
		std::vector<kind> s = k();
		for (std::vector<kind>::iterator iter(s.begin());
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
struct GetChildrenOp : public unary_function <typename L::argument_type,
						          	          typename H::result_type>,
					   public GetChildrenOpBase
{
	typedef GetChildrenOp<L,H> Self;
	typedef typename ET<L>::result_type parent_lit;
	typedef typename ET<H>::result_type child_lit;
	typedef typename 
		TExpr<ChainExpr<L,GetChildrenOp<parent_lit, child_lit> > > expression_type;
	typedef typename child_lit::kind kind;

	explicit GetChildrenOp () {}

	GetChildrenOp (GetChildrenOp const &) {}
	result_type operator () (argument_type const & p)
	{
		typedef typename parent_lit::kind parent_kind;
		typedef typename child_lit::kind child_kind;
		BOOST_CONCEPT_ASSERT((ParentChildConcept<parent_kind, child_kind>));

		result_type retval;
		std::vector<parent_kind> s = p;
		for (std::vector<parent_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			retval.Union((*iter).children_kind<child_kind>());
		}
		return retval;
	}
};

class DFSChildrenOpBase {};

template <class L, class Expr>
struct DFSChildrenOp : public unary_function <typename L::argument_type,
						          	          typename Expr::result_type>,
					   public DFSChildrenOpBase
{
	typedef DFSChildrenOp<L,Expr> Self;
	typedef typename ET<L>::argument_type parent_argument_type;
	typedef typename ET<Expr>::argument_type child_argument_type;
	typedef typename 
		TExpr<ChainExpr<Expr, DFSChildrenOp<parent_argument_type, 
		                                 child_argument_type> > > expression_type;

	Expr expr_;
	explicit DFSChildrenOp () {}
	explicit DFSChildrenOp (Expr const & e) : expr_(e) {}

	DFSChildrenOp (DFSChildrenOp const &) {}
	result_type operator () (parent_argument_type const & p)
	{
		typedef typename parent_argument_type::kind parent_kind;
		typedef typename child_argument_type::kind child_kind;
		BOOST_CONCEPT_ASSERT((ParentChildConcept<parent_kind, child_kind>));

		std::vector<parent_kind> v = p;
		for (std::vector<parent_kind>::iterator iter(v.begin());
			 iter != v.end();
			 ++iter)
		{
			std::vector<child_kind> v = (*iter).children_kind<child_kind>();
			std::for_each(v.begin(), v.end(), expr_);
		}
	}
};

class GetParentOpBase {};

template <class L, class H>
struct GetParentOp : public unary_function <typename L::argument_type,
						          	        typename H::result_type>,
					   public GetParentOpBase
{
	typedef typename ET<L>::result_type child_lit;
	typedef typename ET<H>::result_type parent_lit;
	typedef typename 
		TExpr<ChainExpr<L,GetParentOp<child_lit, parent_lit> > > expression_type;

	typedef typename parent_lit::kind kind;

	explicit GetParentOp () {}
	//GetParentOp (typename ET<H>::expression_type) {}
	GetParentOp (GetParentOp const &) {}
	result_type operator () (argument_type const & c)
	{
		typedef typename parent_lit::kind parent_kind;
		typedef typename child_lit::kind child_kind;
		BOOST_CONCEPT_ASSERT((ParentChildConcept<parent_kind, child_kind>));

		result_type retval;
		std::vector<child_kind> s = c;
		for (std::vector<child_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			retval.Union((*iter).parent_kind<parent_kind>());
		}
		return retval;
	}
};

class VisitorOpBase {};

template <class E>
struct VisitorOp : public unary_function <typename E::argument_type,
						          	      typename E::result_type>,
				   public VisitorOpBase
{
	typedef typename ET<E>::result_type kind_lit;
	typedef typename 
		TExpr<ChainExpr<E,VisitorOp<kind_lit> > > expression_type;

	typedef typename kind_lit::kind kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	Visitor & visitor_;
	explicit VisitorOp (Visitor const &v) 
		: visitor_ (const_cast<Visitor &> (v)) {}
	VisitorOp (VisitorOp const & vop) : visitor_ (vop.visitor_) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<kind> s = k;
		for (std::vector<kind>::iterator iter(s.begin());
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
struct RegexOp : public unary_function <typename E::argument_type,
						          	    typename E::result_type>,
			     public RegexOpBase
{
	typedef typename ET<E>::result_type kind_lit;
	typedef typename 
		TExpr<ChainExpr<E,RegexOp<kind_lit> > > expression_type;

	typedef typename kind_lit::kind kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	//boost::regex regex_;
	std::string regex_;
	bool logical_not_; 
	explicit RegexOp (std::string const & str = ".*", bool logical_not = false) 
		: logical_not_ (logical_not) { regex_.assign(str); }
	RegexOp (RegexOp const & reop) 
		: logical_not_ (reop.logical_not_), regex_ (reop.regex_) {}
	result_type operator () (argument_type const & k)
	{
		result_type retval;
		std::vector<kind> s = k;
		for (std::vector<kind>::iterator iter(s.begin());
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

template <class E, class Func>
struct FilterOp : public unary_function <typename E::argument_type,
						          	     typename E::result_type>,
				  public FilterOpBase
{
	typedef typename ET<E>::result_type kind_lit;
	typedef typename 
		TExpr<ChainExpr<kind_lit,FilterOp<E, Func> > > expression_type;

	typedef typename kind_lit::kind kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	Func func_;
	bool logical_not_; 
	explicit FilterOp (Func f, bool logical_not = false) 
		: func_(f), logical_not_ (logical_not) { }
	FilterOp (FilterOp const & fop) 
		: func_(fop.func_), logical_not_ (fop.logical_not_) {}
	result_type operator () (argument_type const & k)
	{
		result_type retval;
		std::vector<kind> s = k;
		for (std::vector<kind>::iterator iter(s.begin());
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

class CastOpBase {};

template <class L, class H>
struct CastOp : public unary_function <typename L::argument_type,
						          	   typename H::result_type>,
					   public CastOpBase
{
	typedef typename 
		TExpr<ChainExpr<L,CastOp<argument_type, result_type> > > expression_type;
	typedef typename argument_type::kind kind;

	explicit CastOp () {}
	explicit CastOp (H) {} // dummy
	CastOp (CastOp const &) {} 
	result_type operator () (argument_type const & p)
	{
		typedef typename argument_type::kind argument_kind;
		typedef typename result_type::kind kind;

		result_type retval;
		std::vector<argument_kind> s = p;
		for (std::vector<argument_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			if (Udm::IsDerivedFrom ((*iter).type(), kind::meta))
			{
				kind r = kind::Cast(*iter);
				retval.Union(r);
			}
		}
		return retval;
	}
};

class SortOpBase {};

template <class E, class Comp>
struct SortOp : public unary_function <typename ET<E>::argument_type,
					        	       typename ET<E>::result_type>,
					   public SortOpBase
{
	typedef typename ET<E>::result_type kind_lit;
	typedef typename 
		TExpr<ChainExpr<kind_lit,SortOp<E, Comp> > > expression_type;

	typedef typename kind_lit::kind kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	Comp comp_;
	explicit SortOp (Comp c) : comp_(c) {}
	SortOp (SortOp const & sop) : comp_(sop.comp_) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<kind> s = k;
		std::sort(s.begin(), s.end(), comp_);
		return s;
	}
};

class UniqueOpBase {};

template <class E, class BinPred>
struct UniqueOp : public unary_function <typename ET<E>::argument_type,
					         	         typename ET<E>::result_type>,
				  public UniqueOpBase
{
	typedef typename ET<E>::result_type kind_lit;
	typedef typename 
		TExpr<ChainExpr<kind_lit,UniqueOp<E, BinPred> > > expression_type;

	typedef typename kind_lit::kind kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	BinPred pred_;
	explicit UniqueOp (BinPred p) : pred_(p) {}
	UniqueOp (UniqueOp const & uop) : pred_(uop.pred_) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<kind> s = k;
		std::vector<kind>::iterator new_end = 
			std::unique(s.begin(), s.end(), pred_);
		return std::vector<kind>(s.begin(), new_end);
	}
};

class AssociationOpBase {};

template <class RESULT, class TARGETCLASS>
struct AssociationOp : public unary_function <typename ET<TARGETCLASS>::argument_type,
						          	          typename ET<RESULT>::result_type>,
					   public AssociationOpBase
{
	typedef typename 
		TExpr<ChainExpr<result_type, AssociationOp<RESULT, TARGETCLASS> > > 
			expression_type;

	typedef RESULT kind;
	typedef TARGETCLASS argument_kind;

	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);
	BOOST_CLASS_REQUIRE(argument_kind, Udm, UdmObjectConcept);

	typedef Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*FUNC)() const;
	FUNC func_;

	explicit AssociationOp (FUNC f) : func_(f) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<argument_kind> s = k;
		result_type retval;
		for (std::vector<argument_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			kind r = ((*iter).*func_)();
			if (r != Udm::null)
				retval.Union(r);
		}
		return retval;
	}
};

class AssociationManyOpBase {};

template <class RESULT, class TARGETCLASS>
struct AssociationManyOp : public unary_function <typename ET<TARGETCLASS>::argument_type,
						          	              typename ET<RESULT>::result_type>,
					       public AssociationManyOpBase
{
	typedef typename 
		TExpr<ChainExpr<result_type, AssociationManyOp<RESULT, TARGETCLASS> > > 
			expression_type;

	typedef RESULT kind;
	typedef TARGETCLASS argument_kind;

	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);
	BOOST_CLASS_REQUIRE(argument_kind, Udm, UdmObjectConcept);

	typedef Udm::AClassAssocAttr<RESULT, TARGETCLASS> (TARGETCLASS::*FUNC)() const;
	FUNC func_;

	explicit AssociationManyOp (FUNC f) : func_(f) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<argument_kind> s = k;
		result_type retval;
		for (std::vector<argument_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			std::vector<kind> r = ((*iter).*func_)();
			retval.Union(r);
		}
		return retval;
	}
};

class AssociationEndOpBase {};

template <class RESULT, class TARGETCLASS>
struct AssociationEndOp : public unary_function <typename ET<TARGETCLASS>::argument_type,
						          	             typename ET<RESULT>::result_type>,
					      public AssociationEndOpBase
{
	typedef typename 
		TExpr<ChainExpr<result_type, AssociationEndOp<RESULT, TARGETCLASS> > > 
			expression_type;

	typedef RESULT kind;
	typedef TARGETCLASS argument_kind;

	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);
	BOOST_CLASS_REQUIRE(argument_kind, Udm, UdmObjectConcept);

	typedef Udm::AssocEndAttr<RESULT> (TARGETCLASS::*FUNC)() const;
	FUNC func_;

	explicit AssociationEndOp (FUNC f) : func_(f) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<argument_kind> s = k;
		result_type retval;
		for (std::vector<argument_kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			kind r = ((*iter).*func_)();
			if (r != Udm::null)
				retval.Union(r);
		}
		return retval;
	}
};

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
struct ET <Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*)() const>
	: public ETBase <AssociationOp<RESULT, TARGETCLASS> > {};

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AClassAssocAttr<RESULT, TARGETCLASS> (TARGETCLASS::*)() const>
	: public ETBase <AssociationManyOp<RESULT, TARGETCLASS> > {};

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AssocEndAttr<RESULT> (TARGETCLASS::*)() const>
	: public ETBase <AssociationEndOp<RESULT, TARGETCLASS> > {};


template <class T>
RegexOp<typename ET<T>::result_type> 
SelectByName (T, const char * str)
{
	typedef typename ET<T>::result_type result_type;
	typedef typename result_type::kind kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<kind>));
	RegexOp<result_type> regex(str);
	return regex;
}

template <class T>
SelectorOp<typename ET<T>::result_type> 
SelectSubSet (T const &t)
{
	typedef typename ET<T>::result_type result_type;
	typedef typename result_type::kind kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<kind>));
	result_type kind_lit(t);
	SelectorOp<result_type> selector(kind_lit);
	return selector;
}

template <class E, class Func>
FilterOp<E, Func> 
Select (E, Func f)
{
	typedef typename ET<E>::kind kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Func::argument_type, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Func::result_type, bool>));
	FilterOp<E, Func> filter(f);
	return filter;
}

template <class E, class Arg, class Result>
FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
Select (E, Result (*f) (Arg))
{
	typedef typename ET<E>::kind kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Arg, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Result, bool>));
	FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
		filter(std::ptr_fun(f));
	return filter;
}

template <class L, class H>
CastOp<typename ET<L>::result_type, 
       typename ET<H>::result_type> 
CastFromTo (L, H)
{
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<L>));
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<H>));

	typedef typename ET<L>::result_type argument_type;
	typedef typename ET<H>::result_type result_type;

	return CastOp<argument_type, result_type>();
}

template <class E, class Comp>
SortOp<E, Comp> 
Sort (E, Comp c)
{
	typedef typename ET<E>::kind kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Comp::first_argument_type, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Comp::second_argument_type, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Comp::result_type, bool>));
	SortOp<E, Comp> sorter(c);
	return sorter;
}

template <class E, class Arg1, class Arg2, class Result>
SortOp<E, std::pointer_to_binary_function<Arg1, Arg2, Result> > 
Sort (E, Result (*f) (Arg1, Arg2))
{
	typedef typename ET<E>::kind kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Arg1, kind>));	
	BOOST_MPL_ASSERT((boost::is_convertible<Arg2, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Result, bool>));
	SortOp<E, std::pointer_to_binary_function<Arg1, Arg2, Result> > 
		sorter(std::ptr_fun(f));
	return sorter;
}

template <class E, class BinPred>
UniqueOp<E, BinPred> 
Unique (E, BinPred c)
{
	typedef typename ET<E>::kind kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<BinPred::first_argument_type, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<BinPred::second_argument_type, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<BinPred::result_type, bool>));
	UniqueOp<E, BinPred> uni(c);
	return uni;
}

template <class E>
UniqueOp<E, std::equal_to<typename ET<E>::kind> > 
Unique (E)
{
	typedef typename ET<E>::kind kind;
	typedef std::equal_to<kind> EQ;	

	BOOST_CONCEPT_ASSERT((Udm::UdmObjectConcept<kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<EQ::first_argument_type, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<EQ::second_argument_type, kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<EQ::result_type, bool>));
	
	EQ eq;
	UniqueOp<E, EQ> uni(eq);
	return uni;
}

using boost::mpl::if_c;
using boost::is_base_of;

// This is using the enable_if idiom by not defining an 
// associated type "Self" in the disabler structure. 
// GetChildrenOp has Self defined in it.
struct disabler{};

template <class L, class H, template <class, class> class Op>
// Note that here H can potentially be a type that is not an
// expression. For example, it can be a Visitor, RegexOP, SelectorOp 
// among others.
struct OpSelector
{
	typedef typename ET<L>::result_type LResultType;
	// Don't add expression traits of H here because H can be any new type such
	// as TestVisitor. We don't have traits defined for them. The traits
	// obtained only when required as done below.

	typedef typename 
		if_c<is_base_of<Visitor, H>::value, 
			 disabler,
			 Op<LResultType, typename ET<H>::result_type> 
		    >::type Op;
};

template <class L, class H>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename OpSelector<L,H,GetChildrenOp>::Op::Self
				>
	 >
operator > (L const &l, H)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef typename OpSelector<L,H,GetChildrenOp>::Op::Self Operator;
	typedef typename ET<Operator>::kind ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;

	BOOST_CONCEPT_ASSERT((ParentChildConcept <ParentKind, ChildKind>));

	typedef ChainExpr<ParentKindExpr, 
		typename OpSelector<L,H,GetChildrenOp>::Op::Self> ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	Operator op;
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class H>
TExpr<ChainExpr<typename ET<H>::expression_type, 
				DFSChildrenOp<typename ET<L>::argument_type,
							  typename ET<H>::expression_type
				             >
				>
	 >
operator >>= (L const &l, H const &h)
{
	typedef typename ET<L>::argument_type argument_type;
	typedef typename ET<H>::expression_type ChildExpr;
	typedef typename DFSChildrenOp<argument_type, ChildExpr> Operator;
	typedef typename argument_type::kind ParentKind;
	typedef typename ChildExpr::argument_type::kind ChildKind;

	BOOST_CONCEPT_ASSERT((ParentChildConcept <ParentKind, ChildKind>));

	typedef ChainExpr<ChildExpr, Operator> ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	Operator op(h);
	return Expr (ChainExpr(ChildExpr(h), op));
}

template <class L>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename VisitorOp<typename ET<L>::result_type>
				>
	 >
operator > (L const &l, Visitor & v)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef VisitorOp<typename ET<L>::result_type> Operator;
	typedef typename ET<Operator>::kind ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;

	typedef ChainExpr<ParentKindExpr, Operator> ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	Operator op(v);
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class H>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename RegexOp<H>
				>
	 >
operator > (L const &l, RegexOp<H> op)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef typename ET<RegexOp<H> >::kind ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;
    typedef ChainExpr<ParentKindExpr, RegexOp<H> > ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class H>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename SelectorOp<H>
				>
	 >
operator > (L const &l, SelectorOp<H> op)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef typename ET<SelectorOp<H> >::kind ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;
    typedef ChainExpr<ParentKindExpr, SelectorOp<H> > ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class H, class Func>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename FilterOp<H, Func>
				>
	 >
operator > (L const &l, FilterOp<H, Func> op)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef typename ET<FilterOp<H, Func> >::kind ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;
    typedef ChainExpr<ParentKindExpr, FilterOp<H, Func> > ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class H, class Comp>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename SortOp<H, Comp>
				>
	 >
operator > (L const &l, SortOp<H, Comp> op)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef typename ET<SortOp<H, Comp> >::kind ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;
    typedef ChainExpr<ParentKindExpr, SortOp<H, Comp> > ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class TARGET, class RESULT>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename CastOp<TARGET, RESULT>
				>
	 >
operator > (L const &l, CastOp<TARGET, RESULT> op)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef typename ET<CastOp<TARGET, RESULT> >::kind ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));

    typedef ChainExpr<ParentKindExpr, CastOp<TARGET, RESULT> > ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class H, class BinPred>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename UniqueOp<H, BinPred>
				>
	 >
operator > (L const &l, UniqueOp<H, BinPred> op)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef typename ET<UniqueOp<H, BinPred> >::kind ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;
    typedef ChainExpr<ParentKindExpr, UniqueOp<H, BinPred> > ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, ChildKind>));
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class RESULT, class TARGETCLASS>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename AssociationOp<RESULT, TARGETCLASS>
				>
	 >
operator > (L const &l, 
			Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*func)() const)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef RESULT ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;
    typedef ChainExpr<ParentKindExpr, AssociationOp<RESULT, TARGETCLASS> > ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, TARGETCLASS>));
	AssociationOp<RESULT, TARGETCLASS> op(func);
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class RESULT, class TARGETCLASS>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename AssociationEndOp<RESULT, TARGETCLASS>
				>
	 >
operator > (L const &l, 
			Udm::AssocEndAttr<RESULT> (TARGETCLASS::*func)() const)
{
	typedef typename ET<L>::expression_type ParentKindExpr;
	typedef RESULT ChildKind;
	typedef typename ParentKindExpr::kind ParentKind;
    typedef ChainExpr<ParentKindExpr, AssociationEndOp<RESULT, TARGETCLASS> > ChainExpr;
	typedef TExpr<ChainExpr> Expr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<ParentKind, TARGETCLASS>));

	AssociationEndOp<RESULT, TARGETCLASS> op(func);
	return Expr (ChainExpr(ParentKindExpr(l), op));
}

template <class L, class H>
TExpr<ChainExpr<typename ET<L>::expression_type, 
				typename OpSelector<L,H,GetParentOp>::Op
				>
	 >
operator < (L const &l, H)
{
	//BOOST_CONCEPT_ASSERT((Convertible<H, RegexOpBase>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<RegexOpBase, H>));
	//BOOST_CONCEPT_ASSERT((Convertible<H, SelectorOpBase>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<SelectorOpBase, H>));
	//BOOST_CONCEPT_ASSERT((Convertible<H, Visitor>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<Visitor, H>));
	

	typedef typename ET<L>::expression_type ChildKindExpr;
	typedef typename ET<H>::kind ParentKind;
	typedef typename ChildKindExpr::kind ChildKind;

	BOOST_CONCEPT_ASSERT((ParentChildConcept <ParentKind, ChildKind>));
	
	typedef ChainExpr<ChildKindExpr, 
		              typename OpSelector<L,H,GetParentOp>::Op> ChainExpr;
	typedef TExpr<ChainExpr> Expr;
	typename OpSelector<L,H,GetParentOp>::Op op;

	return Expr (ChainExpr(ChildKindExpr(l), op));
}

template <class Expr, class Para>
typename Expr::result_type
evaluate (Expr &e, Para p)
{
	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<
		typename Expr::argument_type, Para>));
	return e(p);
}

template <class T>
T operator * (T t)
{
	return t;
}

struct Predicate : std::unary_function <State, bool> {
	result_type operator () (argument_type) { return true; }
};	

bool pred (State) { return true; }
bool sorter (State s1, State s2) 
{
	return (std::string(s1.name()) < std::string(s2.name()));
}

int foo (HFSM::RootFolder & rf)
{
	try {
		TestVisitor tv;
		BOOST_AUTO(e1, RootFolder() >  State()
                                    >  Sort(State(), sorter) 
                                    >  SelectByName(State(),"State2")
									>  State() < State() > Unique(State()) > State()
									>  CastFromTo(State(), State())
									>  SelectByName(State(),"s50")
									>  Transition()
									>& Transition::srcTransition_end
									>  tv);
		e1(rf);
		BOOST_AUTO(e2, RootFolder() >>= State());
		//evaluate(e2, rf);
		//AfxMessageBox (std::string(s->name()).c_str(), MB_OK| MB_ICONINFORMATION);
		//BOOST_AUTO(e2, e1 > !!!SelectSubSet(s) > tv);
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
	typedef typename result_type::kind kind;

	L l_;
	H h_;
	OP op_;
	explicit DBinExpr () {}
	DBinExpr (DBinExpr const & e) 
		: l_(e.l_), h_(e.h_), op_(e.op_) 
	{}
    explicit DBinExpr (L const &l, H const &h, OP const & op) 
		: l_(l), h_(h), op_(op) {}
	result_type operator () () const { return op_((l_(), h_()); }
};
*/

/*
struct RecurseOpBase {};

template <class E>
struct RecurseOp : public RecurseOpBase
{
	typedef typename ET<E>::result_type kind_lit;
	typedef typename 
		TExpr<ChainExpr<E,RecurseOp<kind_lit> > > expression_type;

	typedef kind_lit result_type;
	typedef kind_lit argument_type;
	typedef typename kind_lit::kind kind;
	BOOST_CLASS_REQUIRE(kind, Udm, UdmObjectConcept);

	std::vector<kind> s_;
	RecurseOp (RecurseOp const & reop) : s_(reop.s_) {}
	result_type operator () (kind_lit const & k)
	{
		result_type retval;
		std::
		std::vector<kind> s = k();
		for (std::vector<kind>::iterator iter(s.begin());
			 iter != s.end();
			 ++iter)
		{
			helper (*iter);
		}
		return retval;
	}
	void helper (kind const & k)
	{
	}
};
*/

