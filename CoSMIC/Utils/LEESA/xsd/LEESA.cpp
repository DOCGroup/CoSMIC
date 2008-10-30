#ifndef __LEESA_CPP
#define __LEESA_CPP

#include "LEESA.h"
//#include "LEESA_VisitorAsIndex.h"
#include "LEESAConcepts.h"
#include "xsd/cxx/tree/containers.hxx"

#include <boost/typeof/typeof.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>
#include <boost/foreach.hpp>
#include <boost/regex.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/mpl/if.hpp>

#include <functional>
#include <ios>

#define SUPER_TYPEDEFS(Super)                                               \
  typedef typename Super::argument_kind argument_kind;                      \
  typedef typename Super::result_kind result_kind;                          \
  typedef typename Super::argument_type argument_type;                      \
  typedef typename Super::result_type result_type;             

#define LOCAL_TYPEDEFS(L, OP)                                                   \
  typedef typename ET< L >::expression_type ParentKindExpr;                     \
  typedef typename ET< OP >::argument_kind ChildKind;                           \
  typedef typename ParentKindExpr::result_kind ParentKind;                      \
  typedef ChainExpr<ParentKindExpr, OP > ChainExpr;                             \
  BOOST_CONCEPT_ASSERT((LEESA::SameElementsConcept<ParentKind, ChildKind>));

/*
#define GT_PARA_OPERATOR_DEFINITION_2T(L,H,OPERATOR)               \
template < class L, class H >                                      \
typename disable_if_c<                                             \
  is_base_of< VisitorAsIndexBase, L >::value |                     \
  is_base_of<std::ios_base, L>::value,                             \
  ChainExpr<typename ET< L >::expression_type, OPERATOR > >::type  \
operator >> (L const &l, OPERATOR op) {                            \
	LOCAL_TYPEDEFS(L, OPERATOR);                               \
	return ChainExpr(ParentKindExpr(l), op);                   \
}


#define GT_PARA_OPERATOR_DEFINITION_3T(L,H,X,OPERATOR)             \
template <class L, class H, class X >                              \
typename disable_if_c<                                             \
  is_base_of< VisitorAsIndexBase, L >::value |                     \
  is_base_of<std::ios_base, L>::value,                             \
  ChainExpr<typename ET< L >::expression_type, OPERATOR > >::type  \
operator >> (L const &l, OPERATOR op) {                            \
	LOCAL_TYPEDEFS(L, OPERATOR);                               \
	return ChainExpr(ParentKindExpr(l), op);                   \
}
*/
namespace LEESA {

template <class Kind> class KindLit;
template <class L, class R> struct ChainExpr;
//template <class L, class R> struct SequenceExpr;

template <class L, class R> struct GetChildrenOp;
/*
template <class L, class R> struct DFSChildrenOp;
template <class L, class R> struct DFSOp;
template <class L, class R> struct GetParentOp;
template <class L, class R> struct CastOp;
template <class RESULT, class TARGETCLASS> struct AssociationOp;
template <class RESULT, class TARGETCLASS> struct AssociationEndOp;
template <class RESULT, class TARGETCLASS> struct AssociationManyOp;
*/

template <class E> struct SelectorOp;
/*
template <class E> struct VisitorOp;
template <class E> struct RegexOp;
*/
template <class E, class Func> struct FilterOp;
template <class E, class Func> struct ForEachOp;
/*
template <class E, class Comp> struct SortOp;
template <class E, class BinPred> struct UniqueOp;
*/
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
/*
template <class Kind>
struct ET <std::set<Kind> >
{
	BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<Kind>));
	typedef typename KindLit<Kind> expression_type;
	typedef typename KindLit<Kind> result_type;
	typedef typename KindLit<Kind> argument_type;
	typedef typename Kind result_kind;
	typedef typename Kind argument_kind;
};

template <class Kind>
struct ET <std::vector<Kind> >
{
	BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<Kind>));
	typedef typename KindLit<Kind> expression_type;
	typedef typename KindLit<Kind> result_type;
	typedef typename KindLit<Kind> argument_type;
	typedef typename Kind result_kind;
	typedef typename Kind argument_kind;
};
*/
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

//template <class T, class X>
//struct ET <SequenceExpr<T, X> > 
//	: public ETBase <SequenceExpr<T, X> > {};

template <class T, class U> 
struct ET <GetChildrenOp<T, U> > 
	: public ETBase <GetChildrenOp<T, U> > {};


template <class T>
struct ET <SelectorOp<T> > 
	: public ETBase <SelectorOp<T> > { };
/*
template <class T>
struct ET <RegexOp<T> >	
	: public ETBase <RegexOp<T> > {};

template <class T>
struct ET <VisitorOp<T> > 
	: public ETBase <VisitorOp<T> > { };

template <class T, class U> 
struct ET <DFSChildrenOp<T, U> > 
	: public ETBase <DFSChildrenOp<T, U> > {};

template <class T, class U> 
struct ET <DFSOp<T, U> > 
	: public ETBase <DFSOp<T, U> > {};

template <class T, class U>
struct ET <GetParentOp<T, U> > 
	: public ETBase <GetParentOp<T, U> > {};
*/

template <class T, class U>
struct ET <FilterOp<T, U> > 
	: public ETBase <FilterOp<T, U> > {};

template <class T, class U>
struct ET <ForEachOp<T, U> > 
	: public ETBase <ForEachOp<T, U> > {};
/*
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
*/

template <class L, class R = L>
struct LEESAUnaryFunction 
	: public std::unary_function <typename ET<L>::argument_type,
	           	              typename ET<R>::result_type>
{
	typedef typename ET<L>::argument_kind argument_kind;
	typedef typename ET<R>::result_kind result_kind;

	//BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<result_kind>));
	BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<argument_kind>));
};

class OpBase {}; // Base of all the operators
class VisitorAsIndexBase{};
class Visitor{};

/*
template <class Kind>
class VisitorAsIndex : public VisitorAsIndexBase
{
    PARADIGM_NAMESPACE_FOR_LEESA::Visitor & visitor_;
    BOOST_CLASS_REQUIRE(Kind, LEESA, ElementConcept);

  public:
    VisitorAsIndex (PARADIGM_NAMESPACE_FOR_LEESA::Visitor & v) : visitor_(v) {}
    PARADIGM_NAMESPACE_FOR_LEESA::Visitor & getVisitor() { return visitor_; }
};

template <class Kind>
VisitorAsIndex<Kind> VisitorAsIndex_CRTP<Kind>::operator [] 
(PARADIGM_NAMESPACE_FOR_LEESA::Visitor &v) const 
{ 
  return VisitorAsIndex<Kind> (v);
}
*/

using boost::disable_if_c;
using boost::enable_if_c;
using boost::disable_if;
using boost::enable_if;
using boost::is_base_of;
using boost::mpl::if_;

template <class T>
struct ContainerGen
{
  typedef typename ::xsd::cxx::tree::sequence <T> type;
};

template <class Kind>
class KindLit : public std::unary_function <KindLit<Kind>, KindLit<Kind> >
{
        typedef typename ContainerGen<Kind>::type Container;
	Kind temp_kind_;
	Container s_;

public:
        typedef KindLit<Kind> expression_type;
	typedef Kind result_kind;
	typedef Kind argument_kind;
        typedef KindLit<Kind> result_type;
        typedef KindLit<Kind> argument_type;
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<Kind>));
	// This is an important concept. Don't remove.

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
        /*
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
        */
	void Union(Container const & v)
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
  typedef typename ET<L>::argument_type argument_type;
  typedef typename ET<R>::result_type result_type;
  typedef ChainExpr<L, R> expression_type;

  BOOST_CONCEPT_ASSERT((LEESA::SameElementsConcept<typename ET<L>::result_kind, 
					           typename ET<R>::argument_kind>));

  L l_;
  R r_;
  ChainExpr (ChainExpr const & c) 
    : l_(c.l_), r_(c.r_) 
  {}
  explicit ChainExpr (L const &l, R const & r) 
    : l_(l), r_(r) {}
  result_type operator () (argument_type p) { return r_(l_(p)); }
};
/*
template <class L, class R>
struct SequenceExpr : public std::unary_function <typename ET<L>::argument_type,
	                                              void>
{
	typedef typename ET<L>::argument_kind argument_kind;
	typedef void result_kind;
	typedef typename SequenceExpr<L, R> expression_type;
	typedef typename ET<R>::argument_kind child_kind;
        BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<argument_kind, child_kind>));

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

template <class LExpr, class RExpr>
struct DFSChildrenOp : std::unary_function<typename ET<LExpr>::result_type, void>,
					             OpBase
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

    BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept<parent_kind, child_kind>));

		std::vector<parent_kind> v = arg;
		BOOST_FOREACH(parent_kind kind, v)
		{
			std::vector<child_kind> children = kind.children_kind<child_kind>();
			std::for_each(children.begin(), children.end(), expr_);
		}
	}
};

template <class LExpr, class RExpr>
struct DFSOp : std::unary_function<typename ET<LExpr>::result_type, void>,
			         OpBase
{
	typedef DFSOp<LExpr, RExpr> Self;
	typedef typename 
		ChainExpr<LExpr, DFSOp<LExpr, RExpr> > expression_type;
	typedef void result_kind;
	typedef typename ET<LExpr>::result_kind argument_kind;
	typedef typename ET<LExpr>::result_kind LKind;
	typedef typename ET<RExpr>::argument_kind RKind;

  BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<LKind, RKind>));

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

template <class LExpr, class RExpr>
struct DFSParentOp : std::unary_function<typename ET<LExpr>::result_type, void>,
					           OpBase
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

    BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept<parent_kind, child_kind>));

		std::vector<child_kind> v = arg;
		BOOST_FOREACH(child_kind kind, v)
		{
			parent_kind parent = kind.parent_kind<parent_kind>();
			expr_(parent);
		}
	}
};
*/

template <class E>
struct SelectorOp : LEESA::LEESAUnaryFunction <E>, OpBase
{
  typedef LEESA::LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  
  typedef typename LEESA::ChainExpr<E, SelectorOp<E> > expression_type;
	
  typename ContainerGen<argument_kind>::type s_;
  bool logical_not_; 
  explicit SelectorOp (argument_type const & kl, bool logical_not = false) 
    : s_(kl), logical_not_(logical_not) {}
  SelectorOp (SelectorOp const & sop) 
    : logical_not_(sop.logical_not_), s_(sop.s_) {}
  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename ContainerGen<argument_kind>::type v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      typename ContainerGen<argument_kind>::type::iterator i = 
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


template <class L, class H>
struct GetChildrenOp : LEESA::LEESAUnaryFunction <L,H>, OpBase
{
  typedef LEESA::LEESAUnaryFunction <L, H> Super;
  SUPER_TYPEDEFS(Super);
  
  typedef typename LEESA::GetChildrenOp<argument_type, result_type> Self;
  typedef typename LEESA::ChainExpr<L, Self> expression_type;

  explicit GetChildrenOp () {}

  GetChildrenOp (GetChildrenOp const &) {}
  result_type operator () (argument_type const & arg)
  {
    BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<argument_kind, result_kind>));

    result_type retval;
    typename ContainerGen<argument_kind>::type v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      SCHEMA_NAMESPACE_FOR_LEESA::GetChildren<argument_kind, result_kind> gc;
      retval.Union(gc(kind));
    }
    return retval;
  }
};
/*
template <class L, class H>
struct GetParentOp : LEESAUnaryFunction <L, H>,
					           OpBase
{
	typedef typename 
		ChainExpr<L, GetParentOp<argument_type, result_type> > expression_type;

	explicit GetParentOp () {}
	GetParentOp (GetParentOp const &) {}
	result_type operator () (argument_type const & arg)
	{
    BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept<result_kind, argument_kind>));

		result_type retval;
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			retval.Union(kind.parent_kind<result_kind>());
		}
		return retval;
	}
};

template <class E>
struct VisitorOp : LEESAUnaryFunction <E>,
				           OpBase
{
	typedef typename 
		ChainExpr<E, VisitorOp<argument_type> > expression_type;

  PARADIGM_NAMESPACE_FOR_LEESA::Visitor & visitor_;
  explicit VisitorOp (PARADIGM_NAMESPACE_FOR_LEESA::Visitor const &v) 
    : visitor_ (const_cast<PARADIGM_NAMESPACE_FOR_LEESA::Visitor &> (v)) {}
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

template <class E>
struct RegexOp : LEESAUnaryFunction <E>,
			           OpBase
{
	typedef typename 
		ChainExpr<E, RegexOp<argument_type> > expression_type;

	boost::regex regex_;
	//std::string regex_;
	bool logical_not_; 
	explicit RegexOp (std::string const & str = ".*", bool logical_not = false) 
		: regex_(str), logical_not_ (logical_not) {  }
	RegexOp (RegexOp const & reop) 
		: logical_not_ (reop.logical_not_), regex_ (reop.regex_) {}
	result_type operator () (argument_type const & arg)
	{
		result_type retval;
		std::vector<argument_kind> v = arg;
		BOOST_FOREACH(argument_kind kind, v)
		{
			bool match = boost::regex_match(std::string(kind.name()), regex_);
			//bool match = (regex_ == std::string(kind.name()));
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
*/
template <class E, class Func>
struct FilterOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESAUnaryFunction<E> Super;
  SUPER_TYPEDEFS(Super);

  typedef typename LEESA::ChainExpr<E, FilterOp<E, Func> > expression_type;

  Func func_;
  bool logical_not_; 
  explicit FilterOp (Func f, bool logical_not = false) 
    : func_(f), logical_not_ (logical_not) { }
  FilterOp (FilterOp const & fop) 
    : func_(fop.func_), logical_not_ (fop.logical_not_) {}
  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename LEESA::ContainerGen<argument_kind>::type v = arg;
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


template <class E, class Func>
struct ForEachOp : LEESA::LEESAUnaryFunction <E>, OpBase
{
  typedef LEESAUnaryFunction<E> Super;
  SUPER_TYPEDEFS(Super);

  typedef typename LEESA::ChainExpr<E, LEESA::ForEachOp<E, Func> > expression_type;

  Func func_;
  explicit ForEachOp (Func f) 
    : func_(f) { }
  ForEachOp (ForEachOp const & fop) 
    : func_(fop.func_) {}
  result_type operator () (argument_type const & arg)
  {
    typename ContainerGen<argument_kind>::type v = arg;
    std::for_each (v.begin(), v.end(), func_);
    return arg;
  }
};
/*
template <class L, class H>
struct CastOp : LEESAUnaryFunction <L, H>,
				        OpBase
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

template <class E, class Comp>
struct SortOp : LEESAUnaryFunction <E>,
			          OpBase
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

template <class E, class BinPred>
struct UniqueOp : LEESAUnaryFunction <E>,
				          OpBase
{
	typedef typename 
		ChainExpr<E ,UniqueOp<E, BinPred> > expression_type;

	BinPred pred_;
	explicit UniqueOp (BinPred p) : pred_(p) {}
	UniqueOp (UniqueOp const & uop) : pred_(uop.pred_) {}
	result_type operator () (argument_type const & k)
	{
		std::vector<argument_kind> s = k;
    std::vector<result_kind> retval;
		BOOST_FOREACH(argument_kind kind, s)
    {  
      if (std::count (retval.begin(), retval.end(), kind) == 0)
        retval.push_back(kind);
    }
		return retval;
	}
};

template <class RESULT, class TARGETCLASS>
struct AssociationOp : LEESAUnaryFunction <TARGETCLASS, RESULT>,
					             OpBase
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

template <class RESULT, class TARGETCLASS>
struct AssociationManyOp : LEESAUnaryFunction <TARGETCLASS,RESULT>,
					                 OpBase
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

template <class RESULT, class TARGETCLASS>
struct AssociationEndOp : LEESAUnaryFunction <TARGETCLASS,RESULT>,
					                OpBase
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
*/
template <class T>
SelectorOp<typename ET<T>::result_type> 
SelectSubSet (T const &t)
{
	typedef typename ET<T>::result_type result_type;
	typedef typename ET<T>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<result_kind>));
	return SelectorOp<result_type> (t);
}

template <class E, class Func>
LEESA::FilterOp<E, Func> 
Select (E, Func f)
{
  typedef typename ET<E>::result_kind result_kind;
	
  BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Func::argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Func::result_type, bool>));
	
  return LEESA::FilterOp<E, Func> (f);
}

template <class E, class Arg, class Result>
LEESA::FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
Select (E, Result (*f) (Arg))
{
  typedef typename ET<E>::result_kind result_kind;
	
  BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Result, bool>));
	
  LEESA::FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
	filter(std::ptr_fun(f));
  return filter;
}

template <class E, class Func>
LEESA::ForEachOp<E, Func> 
ForEach (E, Func f)
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<typename Func::argument_type, result_kind>));
	
	return LEESA::ForEachOp<E, Func> (f);
}

template <class E, class Arg, class Result>
LEESA::ForEachOp<E, std::pointer_to_unary_function<Arg, Result> > 
ForEach (E, Result (*f) (Arg))
{
	typedef typename ET<E>::result_kind result_kind;
	
	BOOST_CONCEPT_ASSERT((LEESA::ElementConcept<result_kind>));
	BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
	
        LEESA::ForEachOp<E, std::pointer_to_unary_function<Arg, Result> > 
		foreach(std::ptr_fun(f));
	return foreach;
}
/*
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
*/
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
  <is_base_of <Visitor, H>::value |
   is_base_of <std::ios_base, L>::value |
   is_base_of <OpBase, H>::value,                             
   typename ChainedOperator<L,H,GetChildrenOp>::Op>::type
operator >> (L const &l, H)
{
	typedef GetChildrenOp<typename ET<L>::result_type, 
                        typename ET<H>::result_type> OP;
	LOCAL_TYPEDEFS(L, OP);

	return ChainExpr(ParentKindExpr(l), OP());
}
/*
template <class L>
typename disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<typename ET<L>::expression_type, 
            typename VisitorOp<typename ET<L>::result_type> > 
  >::type
operator >> (L const &l, PARADIGM_NAMESPACE_FOR_LEESA::Visitor & v)
{
	typedef VisitorOp<typename ET<L>::result_type> OP;
	LOCAL_TYPEDEFS(L, OP);

	return ChainExpr(ParentKindExpr(l), OP(v));
}

template <class L, class H>
typename disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<typename ChainedOperator<L,H,GetChildrenOp>::Op,
            VisitorOp<typename ET<H>::result_type>
           > >::type
operator >> (L const &l, VisitorAsIndex<H> vi)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<H>::result_kind ChildKind;
  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind, ChildKind>));

  return l >> H() >> vi.getVisitor();
}

template <class L, class H>
  ChainExpr<ChainExpr<typename ET<L>::expression_type, 
                      VisitorOp<typename ET<L>::result_type> 
                     >,
            typename if_<is_base_of<OpBase, H>,
                     H,
                     GetChildrenOp<typename ET<L>::result_type,  
                                   typename ET<H>::result_type>
                     >::type
            > 
operator >> (VisitorAsIndex<L> vi, H const &h)
{
  typedef typename ET<L>::result_kind ParentKind;
  typedef typename ET<H>::argument_kind ChildKind;
  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind, ChildKind>));

  return L() >> vi.getVisitor() >> h;
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
  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind, ChildKind>));

  return L() >> vl.getVisitor() >> H() >> vh.getVisitor();
}

#define REGEX_OP RegexOp<H>
GT_PARA_OPERATOR_DEFINITION_2T(L,H,REGEX_OP);

#define SELECTOR_OP SelectorOp<H>
GT_PARA_OPERATOR_DEFINITION_2T(L,H,SELECTOR_OP);

#define FILTER_OP FilterOp<H, Func>
GT_PARA_OPERATOR_DEFINITION_3T(L,H,Func,FILTER_OP);
*/
template <class L, class OP>                              
typename disable_if_c<                                             
  is_base_of <VisitorAsIndexBase, L>::value |                     
  is_base_of <std::ios_base, L>::value |
  !is_base_of <OpBase, OP>::value,                             
  ChainExpr<typename ET< L >::expression_type, OP> >::type  
operator >> (L const &l, OP op) 
{                            
  LOCAL_TYPEDEFS(L, OP);                               
  return ChainExpr(ParentKindExpr(l), op);                   
}
/*
#define FOREACH_OP ForEachOp<H, Func>
GT_PARA_OPERATOR_DEFINITION_3T(L,H,Func,FOREACH_OP);

#define SORT_OP SortOp<H, Comp>
GT_PARA_OPERATOR_DEFINITION_3T(L,H,Comp,SORT_OP);

#define CAST_OP CastOp<TARGET, RESULT>
GT_PARA_OPERATOR_DEFINITION_3T(L,TARGET,RESULT,CAST_OP);

#define UNIQUE_OP UniqueOp<H, BinPred>
GT_PARA_OPERATOR_DEFINITION_3T(L,H,BinPred,UNIQUE_OP);

template <class L, class RESULT, class TARGETCLASS>
typename disable_if<is_base_of<std::ios_base, L>, 
          ChainExpr<typename ET<L>::expression_type, 
		      typename AssociationOp<RESULT, TARGETCLASS>
          > >::type
operator >> (L const &l, 
   	     Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*func)() const)
{
	typedef AssociationOp<RESULT, TARGETCLASS> OP;
	LOCAL_TYPEDEFS(L, OP); 

	return ChainExpr(ParentKindExpr(l), OP(func));
}

template <class L, class RESULT, class TARGETCLASS>
typename disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<typename ET<L>::expression_type, 
		      typename AssociationEndOp<RESULT, TARGETCLASS>
  > >::type
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

template <class L, class H>
SequenceExpr<typename ET<L>::expression_type, 
             ChainExpr<typename ET<H>::result_type,
                       VisitorOp<typename ET<H>::result_type> 
                      >
		        >
operator && (L const &l, VisitorAsIndex<H> vh)
{
	return l && H() >> vh.getVisitor();
}


template <class L, class H, class X>
typename disable_if<is_base_of<std::ios_base, L>, 
  ChainExpr<typename ET<L>::expression_type, 
            SequenceExpr<H,X> 
           > >::type
operator >> (L const &l, SequenceExpr<H,X> const & s)
{	
	typedef typename SequenceExpr<H,X> OP;
	typedef typename ET<L>::expression_type LExpr;
	typedef typename ET<L>::result_kind LKind;
	typedef typename ET<OP>::argument_kind RKind;
	typedef typename ChainExpr<LExpr, OP> ChainExpr;

  BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<LKind, RKind>));
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
  BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept <LKind, RKind>));
  
  return L() >> vl.getVisitor() >> s;
}

template <class L, class H>
typename disable_if_c
  <is_base_of<PARADIGM_NAMESPACE_FOR_LEESA::Visitor, H>::value |
   is_base_of<std::ios_base, L>::value,
   typename ChainedOperator<L,H,GetParentOp>::Op>::type
operator << (L const &l, H)
{
	//BOOST_CONCEPT_ASSERT((Convertible<H, OpBase>));
	BOOST_MPL_ASSERT_NOT((boost::is_base_of<OpBase, H>));
  BOOST_MPL_ASSERT_NOT((boost::is_base_of<PARADIGM_NAMESPACE_FOR_LEESA::Visitor, H>));
	
	// Don't replace the following with LOCAL_TYPEDEFS.
	typedef GetParentOp<typename ET<L>::result_type, 
                      typename ET<H>::result_type>  OP;
	typedef typename ET<L>::expression_type ChildKindExpr;
	typedef typename ET<H>::result_kind ParentKind;
	typedef typename ChildKindExpr::result_kind ChildKind;
	typedef ChainExpr<ChildKindExpr, OP> ChainExpr;

  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind, ChildKind>));

	return ChainExpr(ChildKindExpr(l), OP());
}

template <class L, class R>
typename disable_if
<is_base_of<Visitor, R>,
 ChainExpr<typename ET<L>::expression_type, 
 	   DFSChildrenOp<typename ET<L>::expression_type,
	                 typename ET<R>::expression_type>
	  >
>::type
operator >>= (L const &l, R const &r)
{
	typedef typename ET<L>::expression_type ParentExpr;
	typedef typename ET<R>::expression_type ChildExpr;
	typedef typename DFSChildrenOp<ParentExpr, ChildExpr> Operator;
	typedef typename ET<L>::result_kind ParentKind;
	typedef typename ET<R>::argument_kind ChildKind;

  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind, ChildKind>));

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
  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind,ChildKind>));

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
  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind,ChildKind>));

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
  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind,ChildKind>));

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
  BOOST_CONCEPT_ASSERT((Udm::ParentChildConcept <ParentKind,ChildKind>));

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
	typedef typename SequenceExpr<R,X> OP;
	typedef typename ET<L>::expression_type LExpr;
	typedef typename ET<OP>::expression_type RExpr;
	typedef typename DFSOp<LExpr, RExpr> Operator;
	typedef typename ET<L>::result_kind LKind;
	typedef typename ET<Operator>::argument_kind RKind;

  BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept<LKind, RKind>));

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
  BOOST_CONCEPT_ASSERT((Udm::SameUdmKindsConcept <LKind, RKind>));

  return L() >> vl.getVisitor() >>= r;
}
*/


template <class Para, class Expr>
typename Expr::result_type
evaluate (Para const & p, Expr &e)
{
  BOOST_CONCEPT_ASSERT((LEESA::SameElementsConcept<typename ET<Expr>::argument_kind, 
						   typename ET<Para>::result_kind>));

  return e(p);
}



} // end namespace LEESA

#endif // __LEESA_CPP
