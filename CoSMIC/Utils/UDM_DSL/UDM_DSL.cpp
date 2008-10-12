#include <iostream>
//#include <strstream>
#include <functional>
#include <boost/mpl/accumulate.hpp>
#include <boost/mpl/inserter.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/unique.hpp>
#include <boost/type_traits.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/front.hpp>

#include "stdafx.h"
#include "UDM_DSL.h"

using namespace HFSM;
using namespace boost;
//using namespace boost::mpl;
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
};

namespace HFSM {

template <class Kind>
class KindLit : public std::unary_function <KindLit<Kind>, KindLit<Kind> >
{
	typedef std::vector<Kind> Container;
	Kind temp_kind_;
	Container s_;
	BOOST_CLASS_REQUIRE(Kind, Udm, UdmKindConcept);
	// This is an important concept. Don't remove.

public:
    typedef KindLit<Kind> expression_type;
	typedef Kind result_kind;
	typedef Kind argument_kind;
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
	operator Container () const { return s_; } 
	result_type operator () (argument_type p) const { return p; }
};

template <class L, class R>
struct ChainExpr : public std::unary_function <typename ET<L>::argument_type,
	           	                               typename ET<R>::result_type>
{
	typedef typename ET<L>::argument_kind argument_kind;
	typedef typename ET<R>::result_kind result_kind;
	typedef ChainExpr<L, R> expression_type;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<typename ET<L>::result_kind, 
											  typename ET<R>::argument_kind>));

	L l_;
	R r_;
	//explicit ChainExpr () {} 
	ChainExpr (ChainExpr const & c) 
		: l_(c.l_), r_(c.r_) 
	{}
    explicit ChainExpr (L const &l, R const & r) 
		: l_(l), r_(r) {}
	result_type operator () (argument_type p) { return r_(l_(p)); }
};

template <class L, class R>
struct SequenceExpr : public std::unary_function <typename ET<L>::argument_type,
	                                              void>
{
	typedef typename ET<L>::argument_kind argument_kind;
	typedef void result_kind;
	typedef typename SequenceExpr<L, R> expression_type;
	typedef typename ET<R>::argument_kind child_kind;
	BOOST_CONCEPT_ASSERT((ParentChildConcept<argument_kind, child_kind>));

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
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			std::vector<child_kind> cvector = kind.children_kind<child_kind>();
			BOOST_FOREACH(child_kind ckind, cvector)
			{ 
				r_(ckind); 
			}
		}

	}
};


class DFSChildrenOpBase {};
template <class LExpr, class RExpr>
struct DFSChildrenOp : std::unary_function<typename ET<LExpr>::result_type, 
	                                       void>,
					   DFSChildrenOpBase
{
	typedef DFSChildrenOp<LExpr, RExpr> Self;
	typedef typename 
		ChainExpr<LExpr, DFSChildrenOp<LExpr, RExpr> > expression_type;
	typedef void result_kind;
	typedef typename ET<LExpr>::result_kind argument_kind;

	RExpr expr_;
	explicit DFSChildrenOp () {}
	explicit DFSChildrenOp (RExpr const & e) : expr_(e) {}

	DFSChildrenOp (DFSChildrenOp const &d) : expr_(d.expr_) {}
	result_type operator () (argument_type const & arg)
	{
		typedef typename ET<RExpr>::argument_kind child_kind;
		typedef typename ET<LExpr>::result_kind parent_kind;

		BOOST_CONCEPT_ASSERT((ParentChildConcept<parent_kind, child_kind>));

		std::vector<parent_kind> v = arg;
		BOOST_FOREACH(parent_kind kind, v)
		{
			std::vector<child_kind> children = kind.children_kind<child_kind>();
			std::for_each(children.begin(), children.end(), expr_);
		}
	}
};

class DFSOpBase {};
template <class LExpr, class RExpr>
struct DFSOp : std::unary_function<typename ET<LExpr>::result_type, 
	                               void>,
			   DFSOpBase
{
	typedef DFSOp<LExpr, RExpr> Self;
	typedef typename 
		ChainExpr<LExpr, DFSOp<LExpr, RExpr> > expression_type;
	typedef void result_kind;
	typedef typename ET<LExpr>::result_kind argument_kind;
	typedef typename ET<LExpr>::result_kind LKind;
	typedef typename ET<RExpr>::argument_kind RKind;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<LKind, RKind>));

	RExpr expr_;
	explicit DFSOp () {}
	explicit DFSOp (RExpr const & e) : expr_(e) {}

	DFSOp (DFSOp const &d) : expr_(d.expr_) {}
	result_type operator () (argument_type const & arg)
	{
		std::vector<argument_kind> v = arg;
		std::for_each(v.begin(), v.end(), expr_);
	}
};

class DFSParentOpBase {};
template <class LExpr, class RExpr>
struct DFSParentOp : std::unary_function<typename ET<LExpr>::result_type, 
	                                     void>,
					 DFSParentOpBase
{
	typedef DFSParentOp<LExpr, RExpr> Self;
	typedef typename 
		ChainExpr<LExpr, DFSParentOp<LExpr, RExpr> > expression_type;
	typedef void result_kind;
	typedef typename ET<LExpr>::result_kind argument_kind;

	RExpr expr_;
	explicit DFSParentOp () {}
	explicit DFSParentOp (RExpr const & e) : expr_(e) {}

	DFSParentOp (DFSParentOp const &d) : expr_(d.expr_) {}
	result_type operator () (argument_type const & arg)
	{
		typedef typename ET<RExpr>::argument_kind parent_kind;
		typedef typename ET<LExpr>::result_kind child_kind;

		BOOST_CONCEPT_ASSERT((ParentChildConcept<parent_kind, child_kind>));

		std::vector<child_kind> v = arg;
		BOOST_FOREACH(child_kind kind, v)
		{
			parent_kind parent = kind.parent_kind<parent_kind>();
			expr_(parent);
		}
	}
};

struct SelectorOpBase{};
template <class E>
struct SelectorOp : public MyUnaryFunction <E>, 
	                public SelectorOpBase
{
	typedef typename ChainExpr<E, SelectorOp<E> > expression_type;
	
	std::vector<argument_kind> s_;
	bool logical_not_; 
	//explicit SelectorOp (result_kind const & k) { s_.push_back(k); }
	//explicit SelectorOp (std::vector<kind_lit> const & s) : s_(s) { }
	explicit SelectorOp (argument_type const & kl, bool logical_not = false) 
		: s_(kl), logical_not_(logical_not) {}
	SelectorOp (SelectorOp const & sop) 
		: logical_not_(sop.logical_not_), s_(sop.s_) {}
	result_type operator () (argument_type const & arg)
	{
		result_type retval;
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			std::vector<argument_kind>::iterator i = 
				std::find(s_.begin(), s_.end(), kind);
			if ((i != s_.end()) ^ logical_not_) // Logical not of match, if required
				retval.Union(kind);
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
struct GetChildrenOp : public MyUnaryFunction <L,H>,
	                   public GetChildrenOpBase
{
	typedef GetChildrenOp<L, H> Self;
	typedef typename 
		ChainExpr<L, GetChildrenOp<argument_type, result_type> > expression_type;

	explicit GetChildrenOp () {}

	GetChildrenOp (GetChildrenOp const &) {}
	result_type operator () (argument_type const & arg)
	{
		BOOST_CONCEPT_ASSERT((ParentChildConcept<argument_kind, result_kind>));

		result_type retval;
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			retval.Union(kind.children_kind<result_kind>());
		}
		return retval;
	}
};

class GetParentOpBase {};
template <class L, class H>
struct GetParentOp : public MyUnaryFunction <L, H>,
					 public GetParentOpBase
{
	typedef typename 
		ChainExpr<L, GetParentOp<argument_type, result_type> > expression_type;

	explicit GetParentOp () {}
	GetParentOp (GetParentOp const &) {}
	result_type operator () (argument_type const & arg)
	{
		BOOST_CONCEPT_ASSERT((ParentChildConcept<result_kind, argument_kind>));

		result_type retval;
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			retval.Union(kind.parent_kind<result_kind>());
		}
		return retval;
	}
};

class VisitorOpBase {};
template <class E>
struct VisitorOp : public MyUnaryFunction <E>,
				   public VisitorOpBase
{
	typedef typename 
		ChainExpr<E, VisitorOp<argument_type> > expression_type;

	Visitor & visitor_;
	explicit VisitorOp (Visitor const &v) 
		: visitor_ (const_cast<Visitor &> (v)) {}
	VisitorOp (VisitorOp const & vop) : visitor_ (vop.visitor_) {}
	result_type operator () (argument_type const & arg)
	{
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			kind.Accept(visitor_);
		}
		return arg;
	}
};


class RegexOpBase {};
template <class E>
struct RegexOp : public MyUnaryFunction <E>,
			           public RegexOpBase
{
	typedef typename 
		ChainExpr<E, RegexOp<argument_type> > expression_type;

	//boost::regex regex_;
	std::string regex_;
	bool logical_not_; 
	explicit RegexOp (std::string const & str = ".*", bool logical_not = false) 
		: logical_not_ (logical_not) { regex_.assign(str); }
	RegexOp (RegexOp const & reop) 
		: logical_not_ (reop.logical_not_), regex_ (reop.regex_) {}
	result_type operator () (argument_type const & arg)
	{
		result_type retval;
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			//bool match = boost::regex_match(std::string((*iter).name()), regex_);
			bool match = (regex_ == std::string(kind.name()));
			if (match ^ logical_not_) // Logical not of match, if required
				retval.Union(kind);
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
struct FilterOp : public MyUnaryFunction <E>,
				  public FilterOpBase
{
	typedef typename 
		ChainExpr<E, FilterOp<E, Func> > expression_type;

	Func func_;
	bool logical_not_; 
	explicit FilterOp (Func f, bool logical_not = false) 
		: func_(f), logical_not_ (logical_not) { }
	FilterOp (FilterOp const & fop) 
		: func_(fop.func_), logical_not_ (fop.logical_not_) {}
	result_type operator () (argument_type const & arg)
	{
		result_type retval;
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			if (func_(kind) ^ logical_not_) // Logical not of match, if required
				retval.Union(kind);
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
struct CastOp : public MyUnaryFunction <L, H>,
				public CastOpBase
{
	typedef typename 
		ChainExpr<L, CastOp<argument_type, result_type> > expression_type;

	explicit CastOp () {}
	explicit CastOp (H) {} // dummy
	CastOp (CastOp const &) {} 
	result_type operator () (argument_type const & arg)
	{
		result_type retval;
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			if (Udm::IsDerivedFrom (kind.type(), result_kind::meta))
			{
				result_kind r = result_kind::Cast(kind);
				retval.Union(r);
			}
		}
		return retval;
	}
};

class SortOpBase {};
template <class E, class Comp>
struct SortOp : public MyUnaryFunction <E>,
			    public SortOpBase
{
	typedef typename 
		ChainExpr<E, SortOp<E, Comp> > expression_type;

	Comp comp_;
	explicit SortOp (Comp c) : comp_(c) {}
	SortOp (SortOp const & sop) : comp_(sop.comp_) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<argument_kind> s = k;
		std::sort(s.begin(), s.end(), comp_);
		return s;
	}
};


class UniqueOpBase {};
template <class E, class BinPred>
struct UniqueOp : public MyUnaryFunction <E>,
				  public UniqueOpBase
{
	typedef typename 
		ChainExpr<E ,UniqueOp<E, BinPred> > expression_type;

	BinPred pred_;
	explicit UniqueOp (BinPred p) : pred_(p) {}
	UniqueOp (UniqueOp const & uop) : pred_(uop.pred_) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<argument_kind> s = k;
		std::vector<argument_kind>::iterator new_end = 
			std::unique(s.begin(), s.end(), pred_);
		return std::vector<result_kind>(s.begin(), new_end);
	}
};


class AssociationOpBase {};
template <class RESULT, class TARGETCLASS>
struct AssociationOp : public MyUnaryFunction <TARGETCLASS, RESULT>,
					   public AssociationOpBase
{
	typedef typename 
		ChainExpr<RESULT, AssociationOp<RESULT, TARGETCLASS> > 
			expression_type;

	typedef Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*FUNC)() const;
	FUNC func_;

	explicit AssociationOp (FUNC f) : func_(f) {}
	result_type operator () (argument_type const & arg)
	{
		std::vector<argument_kind> v = arg;
		result_type retval;
		BOOST_FOREACH(argument_kind kind, v)
		{
			result_kind r = (kind.*func_)();
			if (r != Udm::null)
				retval.Union(r);
		}
		return retval;
	}
};


class AssociationManyOpBase {};
template <class RESULT, class TARGETCLASS>
struct AssociationManyOp : public MyUnaryFunction <TARGETCLASS,RESULT>,
					       public AssociationManyOpBase
{
	typedef typename 
		ChainExpr<RESULT, AssociationManyOp<RESULT, TARGETCLASS> >
			expression_type;

	typedef Udm::AClassAssocAttr<RESULT, TARGETCLASS> (TARGETCLASS::*FUNC)() const;
	FUNC func_;

	explicit AssociationManyOp (FUNC f) : func_(f) {}
	result_type operator () (argument_type const & arg)
	{
		std::vector<argument_kind> v = arg;
		result_type retval;
		BOOST_FOREACH(argument_kind kind, v)
		{
			std::vector<result_kind> r = (kind.*func_)();
			retval.Union(r);
		}
		return retval;
	}
};
class AssociationEndOpBase {};
template <class RESULT, class TARGETCLASS>
struct AssociationEndOp : public MyUnaryFunction <TARGETCLASS,RESULT>,
					      public AssociationEndOpBase
{
	typedef typename 
		ChainExpr<RESULT, AssociationEndOp<RESULT, TARGETCLASS> >
			expression_type;

	typedef Udm::AssocEndAttr<RESULT> (TARGETCLASS::*FUNC)() const;
	FUNC func_;

	explicit AssociationEndOp (FUNC f) : func_(f) {}
	result_type operator () (argument_type const & arg)
	{
		std::vector<argument_kind> v = arg;
		result_type retval;
		BOOST_FOREACH(argument_kind kind, v)
		{
			result_kind r = (kind.*func_)();
			if (r != Udm::null)
				retval.Union(r);
		}
		return retval;
	}
};



template <class T>
RegexOp<typename ET<T>::result_type> 
SelectByName (T, const char * str)
{
	typedef typename ET<T>::result_type result_type;
	typedef typename ET<T>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	RegexOp<result_type> regex(str);
	return regex;
}

template <class T>
SelectorOp<typename ET<T>::result_type> 
SelectSubSet (T const &t)
{
	typedef typename ET<T>::result_type result_type;
	typedef typename ET<T>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	return SelectorOp<result_type> (t);
}

template <class E, class Func>
FilterOp<E, Func> 
Select (E, Func f)
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Func::argument_type, result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Func::result_type, bool>));
	
	return FilterOp<E, Func> (f);
}

template <class E, class Arg, class Result>
FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
Select (E, Result (*f) (Arg))
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
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
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<L>));
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<H>));

	typedef typename ET<L>::argument_type argument_type;
	typedef typename ET<H>::result_type result_type;

	return CastOp<argument_type, result_type>();
}

template <class E, class Comp>
SortOp<E, Comp> 
Sort (E, Comp c)
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Comp::first_argument_type, result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Comp::second_argument_type, result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Comp::result_type, bool>));
	
	return SortOp<E, Comp> (c);
}

template <class E, class Arg1, class Arg2, class Result>
SortOp<E, std::pointer_to_binary_function<Arg1, Arg2, Result> > 
Sort (E, Result (*f) (Arg1, Arg2))
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Arg1, result_kind>));	
	BOOST_MPL_ASSERT((boost::is_convertible<Arg2, result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Result, bool>));
	
	SortOp<E, std::pointer_to_binary_function<Arg1, Arg2, Result> > 
		sorter(std::ptr_fun(f));
	return sorter;
}

template <class E, class BinPred>
UniqueOp<E, BinPred> 
Unique (E, BinPred c)
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<BinPred::first_argument_type, result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<BinPred::second_argument_type, result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<BinPred::result_type, bool>));
	
	return UniqueOp<E, BinPred> (c);
}

template <class E>
UniqueOp<E, std::equal_to<typename ET<E>::result_kind> > 
Unique (E)
{
	typedef typename ET<E>::result_kind result_kind;
	typedef std::equal_to<result_kind> EQ;	

	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<EQ::first_argument_type, result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<EQ::second_argument_type, result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<EQ::result_type, bool>));
	
	return UniqueOp<E, EQ>(EQ());
}

template <class L>
ChainExpr<typename ET<L>::expression_type, 
 		  typename VisitorOp<typename ET<L>::result_type>
		 >
operator >> (L const &l, Visitor & v)
{
	typedef VisitorOp<typename ET<L>::result_type> OP;
	LOCAL_TYPEDEFS(L, OP);

	return ChainExpr(ParentKindExpr(l), OP(v));
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
ChainExpr<typename ET<L>::expression_type, 
		      typename OpSelector<L,H,GetChildrenOp>::Op::Self
		 >
operator >> (L const &l, H)
{
	typedef OpSelector<L,H,GetChildrenOp>::Op::Self OP;
	LOCAL_TYPEDEFS(L, OP);

	return ChainExpr(ParentKindExpr(l), OP());
}

#define REGEX_OP RegexOp<H>
GT_PARA_OPERATOR_DEFINITION_2T(L,H,REGEX_OP);

#define SELECTOR_OP SelectorOp<H>
GT_PARA_OPERATOR_DEFINITION_2T(L,H,SELECTOR_OP);

#define FILTER_OP FilterOp<H, Func>
GT_PARA_OPERATOR_DEFINITION_3T(L,H,Func,FILTER_OP);

#define SORT_OP SortOp<H, Comp>
GT_PARA_OPERATOR_DEFINITION_3T(L,H,Comp,SORT_OP);

#define CAST_OP CastOp<TARGET, RESULT>
GT_PARA_OPERATOR_DEFINITION_3T(L,TARGET,RESULT,CAST_OP);

#define UNIQUE_OP UniqueOp<H, BinPred>
GT_PARA_OPERATOR_DEFINITION_3T(L,H,BinPred,UNIQUE_OP);

template <class L, class RESULT, class TARGETCLASS>
ChainExpr<typename ET<L>::expression_type, 
		  typename AssociationOp<RESULT, TARGETCLASS>
     	 >
operator >> (L const &l, 
			Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*func)() const)
{
	typedef AssociationOp<RESULT, TARGETCLASS> OP;
	LOCAL_TYPEDEFS(L, OP); 

	return ChainExpr(ParentKindExpr(l), OP(func));
}

template <class L, class RESULT, class TARGETCLASS>
ChainExpr<typename ET<L>::expression_type, 
		  typename AssociationEndOp<RESULT, TARGETCLASS>
		 >
operator >> (L const &l, 
			Udm::AssocEndAttr<RESULT> (TARGETCLASS::*func)() const)
{
	typedef AssociationEndOp<RESULT, TARGETCLASS> OP;
	LOCAL_TYPEDEFS(L, OP); 

	return ChainExpr(ParentKindExpr(l), OP(func));
}

template <class L, class H>
SequenceExpr<typename ET<L>::expression_type, 
		     typename ET<H>::expression_type
		    >
operator && (L const &l, H const &h)
{
	typedef typename SequenceExpr<typename ET<L>::expression_type, 
		                          typename ET<H>::expression_type
		                         > OP;
	return OP(l, h);
}

template <class L, class H, class X>
ChainExpr<typename ET<L>::expression_type, 
 		  SequenceExpr<H,X> >
operator >> (L const &l, SequenceExpr<H,X> const & s)
{	
	typedef typename SequenceExpr<H,X> OP;
	typedef typename ET<L>::expression_type LExpr;
	typedef typename ET<L>::result_kind LKind;
	typedef typename ET<OP>::argument_kind RKind;
	typedef typename ChainExpr<LExpr, OP> ChainExpr;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<LKind, RKind>));
	return ChainExpr(LExpr(l), OP(s));
}

template <class L, class H>
ChainExpr<typename ET<L>::expression_type, 
		  typename OpSelector<L,H,GetParentOp>::Op
		 >
operator << (L const &l, H)
{
	//BOOST_CONCEPT_ASSERT((Convertible<H, RegexOpBase>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<RegexOpBase, H>));
	//BOOST_CONCEPT_ASSERT((Convertible<H, SelectorOpBase>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<SelectorOpBase, H>));
	//BOOST_CONCEPT_ASSERT((Convertible<H, Visitor>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<Visitor, H>));
	
	// Don't replace the following with LOCAL_TYPEDEFS.
	typedef typename OpSelector<L,H,GetParentOp>::Op OP;
	typedef typename ET<L>::expression_type ChildKindExpr;
	typedef typename ET<H>::result_kind ParentKind;
	typedef typename ChildKindExpr::result_kind ChildKind;
	typedef ChainExpr<ChildKindExpr, OP> ChainExpr;

	BOOST_CONCEPT_ASSERT((ParentChildConcept <ParentKind, ChildKind>));

	return ChainExpr(ChildKindExpr(l), OP());
}


template <class L, class R>
ChainExpr<typename ET<L>::expression_type, 
		  DFSChildrenOp<typename ET<L>::expression_type,
		 			    typename ET<R>::expression_type
				       >
		 >
operator >>= (L const &l, R const &r)
{
	typedef typename ET<L>::expression_type ParentExpr;
	typedef typename ET<R>::expression_type ChildExpr;
	typedef typename DFSChildrenOp<ParentExpr, ChildExpr> Operator;
	typedef typename ET<L>::result_kind ParentKind;
	typedef typename ET<R>::argument_kind ChildKind;

	BOOST_CONCEPT_ASSERT((ParentChildConcept <ParentKind, ChildKind>));

	typedef ChainExpr<ParentExpr, Operator> ChainExpr;

	Operator op(r);
	return ChainExpr(ParentExpr(l), op);
}

template <class L, class R, class X>
ChainExpr<typename ET<L>::expression_type, 
		  DFSOp<typename ET<L>::expression_type,
		 	    typename SequenceExpr<R,X>
			   >
		 >
operator >>= (L const &l, SequenceExpr<R,X> const &r)
{
	typedef typename SequenceExpr<R,X> OP;
	typedef typename ET<L>::expression_type LExpr;
	typedef typename ET<OP>::expression_type RExpr;
	typedef typename DFSOp<LExpr, RExpr> Operator;
	typedef typename ET<L>::result_kind LKind;
	typedef typename ET<Operator>::argument_kind RKind;

	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<LKind, RKind>));

	typedef ChainExpr<LExpr, Operator> ChainExpr;

	Operator op(r);
	return ChainExpr(LExpr(l), op);
}

template <class T, class U>
struct Merge
{
  typedef typename mpl::copy <U, mpl::back_inserter<T> >::type type;
  //typedef typename mpl::insert<T,typename mpl::end<T>::type, U>::type type;
};

struct ChildrenGetter
{
  template <class Vector, class Kind>
  struct apply
  {
    typedef typename Kind::ChildrenKinds Children;
    typedef typename Merge<Vector, Children>::type type;
  };
};

template <class L>
struct ExpandSearchSet
{
  typedef typename mpl::accumulate<L, mpl::vector<>, ChildrenGetter>::type type1;
  typedef typename mpl::unique<type1, is_same<mpl::_1,mpl::_2> >::type type;
};

template <class Vector, class R>
struct HasPath
{
  typedef HasPath type;
  typedef typename ExpandSearchSet<Vector>::type VExpand1;
  typedef typename ExpandSearchSet<VExpand1>::type VExpand2;
  static const int value = boost::mpl::contains<Vector, R>::value ||
                           boost::mpl::contains<VExpand1, R>::value ||
                           boost::mpl::contains<VExpand2, R>::value;
                           //HasPath<VExpand, R>::value;
};

template <class L, class R>
void BFS(L, R)
{
  typedef boost::mpl::vector<L> SearchSet;
  BOOST_MPL_ASSERT((HasPath<SearchSet, R>));
}

template <class Vector, class R>
struct FindPath
{
  typedef FindPath type;
  typedef typename mpl::front<Vector>::type Head;
  typedef typename mpl::pop_front<Vector>::type Tail;
  typedef typename Head::ChildrenKinds Children;
  enum { value = is_same<Head, R>::value ? 1 : 
                 FindPath<Children, R>::value; };
};

template <class L, class R>
void DFS(L, R)
{
  typedef mpl::vector<L> SearchSet;
  BOOST_MPL_ASSERT((FindPath<SearchSet, R>));
}

template <class Para, class Expr>
typename Expr::result_type
evaluate (Para p, Expr &e)
{
	BOOST_CONCEPT_ASSERT((SameUdmKindsConcept<typename ET<Expr>::argument_kind, 
											  typename ET<Para>::result_kind>));
	return e(p);
}

} // namespace HFSM

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

#define MembersOf(A,B) (A && B)
#define DEPTH_FIRST >>=
#define BREADTH_FIRST >>

int foo (HFSM::RootFolder & rf)
{
	try {
    //BFS(RootFolder(), Transition());
    //DFS(RootFolder(), Transition());
		TestVisitor tv;
		/*
		BOOST_AUTO(e1, RootFolder() >>  State()
								    //>>  SelectSubSet(State())
                  >>  Sort(State(), sorter) 
									>>  Select(State(), pred)
                  >>  SelectByName(State(),"State2")
									>>  State() << State() >> Unique(State()) >> State()
									>>  CastFromTo(State(), State())
									>>  SelectByName(State(),"s50")
									>>  Transition()
									>>& Transition::srcTransition_end
									>>& State::srcTransition
									>>  tv 
									>>  tv);
		e1(rf);
		BOOST_AUTO(e2, RootFolder() >>=  State()
                                >>   tv 
								                >>   SelectByName(State(),"State2")
									              >>   State() << State() >> Unique(State())
									              >>=  State()
                                >>   tv);//>>= Transition());
        
		evaluate(rf, e2); */
		BOOST_AUTO(visit_state, State() >> tv);
		BOOST_AUTO(visit_transition, Transition() >> tv);
		BOOST_AUTO(e3, RootFolder() DEPTH_FIRST State() >> tv
                                DEPTH_FIRST State() >> tv 
                                BREADTH_FIRST State() >> tv);
			           //>>= MembersOf(State(), visit_state && visit_transition));
		evaluate (rf,e3);
		//BOOST_AUTO(e4, RootFolder() >> State() 
		//	                        >> (State() ^ State() >> tv, Transition() >> tv));
		//evaluate(rf, e4);
		//AfxMessageBox (std::string(s->name()).c_str(), MB_OK| MB_ICONINFORMATION);
		//BOOST_AUTO(e2, e1 > !!!SelectSubSet(s) > tv);
	}
	catch (std::exception &)
	{
		//std::ostringstream ostr;
		//ostr << "Exception (UDM_DSL.CPP): " << e.what() << std::endl;
		AfxMessageBox ("Exception (UDM_DSL.CPP)", MB_OK| MB_ICONINFORMATION);
	}

	return 999;
}

/*
struct RecurseOpBase {};

template <class E>
struct RecurseOp : public RecurseOpBase
{
	typedef typename ET<E>::result_type kind_lit;
	typedef typename 
		ChainExpr<E,RecurseOp<kind_lit> > expression_type;

	typedef kind_lit result_type;
	typedef kind_lit argument_type;
	typedef typename kind_lit::result_kind result_kind;
	//BOOST_CLASS_REQUIRE(result_kind, Udm, UdmKindConcept);

	std::vector<result_kind> s_;
	RecurseOp (RecurseOp const & reop) : s_(reop.s_) {}
	result_type operator () (kind_lit const & k)
	{
		result_type retval;
		std::
		std::vector<result_kind> s = k();
		for (std::vector<result_kind>::iterator iter(s.begin());
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


class MembersOpBase {};
template <class A, class B, class C>
struct Members2Op : std::unary_function<typename ET<A>::argument_type, 
	                                     void>,
	                 public MembersOpBase
{
	typedef typename ET<A>::expression_type AExpr;
	typedef typename ET<B>::expression_type BExpr;
	typedef typename ET<C>::expression_type CExpr;
	typedef typename ET<A>::argument_kind argument_kind;
	typedef void result_kind;
	typedef typename ET<B>::argument_kind B_arg_kind;
	typedef typename ET<C>::argument_kind C_arg_kind;
	typedef typename ET<A>::result_kind A_result_kind;

	
	typedef typename 
		ChainExpr<AExpr, Members2Op<AExpr, BExpr, CExpr> > expression_type;

	B b_;
	C c_;

	explicit Members2Op () {}
	Members2Op (B b, C c) 
		: b_(b), c_(c) 
	{}

	Members2Op (Members2Op const & mop)
		: b_(mop.b_), c_(mop.c_) 
	{}
	result_type operator () (argument_type const & arg)
	{
		BOOST_CONCEPT_ASSERT((ParentChildConcept<argument_kind, B_arg_kind>));
		BOOST_CONCEPT_ASSERT((ParentChildConcept<argument_kind, C_arg_kind>));
	
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			std::vector<B_arg_kind> bvector = kind.children_kind<B_arg_kind>();
			BOOST_FOREACH(B_arg_kind bkind, bvector)
			{ 
				b_(bkind); 
			}
			std::vector<C_arg_kind> cvector = kind.children_kind<C_arg_kind>();
			BOOST_FOREACH(C_arg_kind ckind, cvector)
			{ 
				c_(ckind); 
			}
		}
	}
};

template <class A, class B, class C>
Members2Op<typename ET<A>::argument_type,
           typename ET<B>::expression_type,
		   typename ET<C>::expression_type> 
Members (A, B b, C c)
{
	typedef typename ET<A>::argument_kind parent_kind;
	typedef typename ET<B>::argument_kind B_arg_kind;
	typedef typename ET<C>::argument_kind C_arg_kind;

	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<parent_kind>));
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<B_arg_kind>));
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<C_arg_kind>));

	BOOST_CONCEPT_ASSERT((ParentChildConcept <parent_kind, B_arg_kind>));
	BOOST_CONCEPT_ASSERT((ParentChildConcept <parent_kind, C_arg_kind>));

	typedef typename ET<A>::argument_type parent_type;
	typedef typename ET<B>::expression_type BExpr;
	typedef typename ET<C>::expression_type CExpr;

	return Members2Op<parent_type, BExpr, CExpr> (b,c);
}



#define MEMBERS2_OP Members2Op<A, B, C>
GT_PARA_OPERATOR_DEFINITION_3T(A,B,C,MEMBERS2_OP);



*/


