#ifndef __LEESA_H
#define __LEESA_H

#ifndef SCHEMA_NAMESPACE_FOR_LEESA
#error "Please define SCHEMA_NAMESPACE_FOR_LEESA."
#endif // SCHEMA_NAMESPACE_FOR_LEESA

#define MembersOf(A,B) A && B
#define DEPTH_FIRST    >>=
#define BREADTH_FIRST  >>
#define FOLLOWED_BY    &&

/* LEESA Operators 

SelectByName (Kind, String)
SelectSubSet (Kind, set)
Select       (Kind, predicate)
CastFromTo   (From, To)
Sort         (Kind, Comparator c)
Unique       (Kind, BinPred c)
Unique       (Kind)
ForEach      (Kind, unary function)

*/

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
