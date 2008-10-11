#ifndef __LEESA_H
#define __LEESA_H

#ifndef PARADIGM_NAMESPACE_FOR_LEESA
#error "Please define PARADIGM_NAMESPACE_FOR_LEESA, which contains the base Visitor class."
#endif // PARADIGM_NAMESPACE_FOR_LEESA

#include <functional>
#include <vector>
#include <set>

#include <boost/typeof/typeof.hpp>
#include <boost/type_traits.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>

#include "UdmObjectConcept.h"

namespace LEESA {

template <class Kind> class KindLit;
template <class L, class R> struct ChainExpr;
template <class L, class R> struct SequenceExpr;

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

} // end namespace LEESA

#include "LEESA.cpp"

#endif // __LEESA_H

//*****************************************************************************
// LEESA EXAMPLES                                                             
// Note: These examples are written using the default HFSM paradigm that            
//       ships with GME. 
//*****************************************************************************

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
std::vector<Transition> leesa_example1(RootFolder rf)
{
  using namespace LEESA;
  return evaluate(rf, RootFolder() >> State() >> Transition());
}
*/

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
std::vector<Transition> leesa_example2(RootFolder rf)
{
  using namespace LEESA;
  BOOST_AUTO(tran_set, RootFolder() >> State() >> Transition());
  std::vector<Transition> v = evaluate(rf, tran_set);
  return v;
}
*/

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
std::vector<State> leesa_example3(RootFolder rf)
{
  using namespace LEESA;
  // This example must link with boost-regex library.
  BOOST_AUTO(states, RootFolder() >> State() >> State());
  BOOST_AUTO(state_end_three, states >> SelectByName(State(), ".*3"));
  return evaluate(rf, state_end_three);
}
*/

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
std::vector<State> leesa_example4(RootFolder rf)
{
  // Note "!!" before SelectByName. One "!" means a logical NOT.
  // "!!" means NOT of NOT, which is same as the original logical expression.
  // This example must link with boost-regex library.
  using namespace LEESA;
  BOOST_AUTO(states, RootFolder() >> State() >> State());
  BOOST_AUTO(state_end_three, states >> !!SelectByName(State(), ".*3"));
  return evaluate(rf, state_end_three);
}
*/

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
bool always_true (State)
{
  return true;
}
std::vector<State> leesa_example5(RootFolder rf)
{
  // Operators: Unique, SelectByName, CastFromTo, Select, SelectSubSet
  using namespace LEESA;
  BOOST_AUTO(states, RootFolder() >> State() >> State() >> State());
  std::vector<State> v = evaluate(rf, states);
  BOOST_AUTO(parent_of_s11_s12, State() << State() 
                                        >> Unique(State())
                                        >> Select(State(), always_true));
  return evaluate(v, parent_of_s11_s12);
}
*/

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
std::vector<State> leesa_example6(RootFolder rf)
{
  // Traversing srcTransition association using srcTransition_end.
  using namespace LEESA;
  BOOST_AUTO(states, RootFolder() >> State() >> State());
  std::vector<State> v = evaluate(rf, states);
  BOOST_AUTO(s11, v >> Transition() >>& Transition::srcTransition_end);
  return evaluate(v, s11);
}
*/

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
class CountVisitor : public HFSM::Visitor 
{
  int count_;
public:
  CountVisitor () : count_(0) {}
  void Visit_Transition(const Transition &t) {
    ++count_;
  }
  int get_count() { return count_; }
};
#define DEPTH_FIRST >>=
int leesa_example7(RootFolder rf)
{
  using namespace LEESA;
  CountVisitor cv;
  evaluate(rf, RootFolder() DEPTH_FIRST State() >> Transition() >> cv);
  return cv.get_count();
}
*/

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
class CountVisitor : public HFSM::Visitor 
{
  int seq_count_;
  int state_count_;
public:
  CountVisitor () : seq_count_(0), state_count_(0) {}
  void Visit_InputSequnce(const InputSequence &i) {
    ++seq_count_;
  }
  void Visit_State(const State &t) {
    ++state_count_;
  }
  int get_states() { return state_count_; }
  int get_seq() { return seq_count_; }
};
int leesa_example8(RootFolder rf)
{
  // MembersOf is used to visit different sibling types under a common parent.
  // E.g., In HFSM, there are State and InputSequence under RootFolder.
  using namespace LEESA;
  CountVisitor cv;
  BOOST_AUTO(visit_input_sequence, InputSequence() >> cv);
  BOOST_AUTO(visit_state, State() >> cv);
  evaluate(rf, RootFolder() 
    >> MembersOf(RootFolder(), visit_input_sequence && visit_state));
  return cv.get_states();
}
*/

/*
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"
using namespace HFSM;
std::vector<Transition> leesa_example9(RootFolder rf)
{
  // This will not compile because RootFolder has no Transition directly
  // under it.
  using namespace LEESA;
  return evaluate(rf, RootFolder() >> Transition()); 
}
*/

