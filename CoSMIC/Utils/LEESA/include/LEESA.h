#ifndef __LEESA_H
#define __LEESA_H

#ifndef DOMAIN_NAMESPACE
#error "Please define DOMAIN_NAMESPACE."
#endif // DOMAIN_NAMESPACE

#define MembersOf(A,...) ((A, __VA_ARGS__))
#define DEPTH_FIRST    >>=
#define BREADTH_FIRST  >>
#define PARENT         <<
#define FOLLOWED_BY    ,
#define AND            ,
#define Association(X) &X

// FOLLOWED_BY defined above is used in LEESA.cpp
#include "LEESA.cpp"

#endif // __LEESA_H



//*****************************************************************************
// LEESA EXAMPLES                                                             
// Note: These examples are written using the default HFSM paradigm that            
//       ships with GME. 
//*****************************************************************************

/*
#define DOMAIN_NAMESPACE HFSM
#include "LEESA.h"
using namespace HFSM;
std::vector<Transition> leesa_example1(RootFolder rf)
{
  using namespace LEESA;
  return evaluate(rf, RootFolder() >> State() >> Transition());
}
*/

/*
#define DOMAIN_NAMESPACE HFSM
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
#define DOMAIN_NAMESPACE HFSM
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
#define DOMAIN_NAMESPACE HFSM
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
#define DOMAIN_NAMESPACE HFSM
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
  BOOST_AUTO(parent, State() << State() 
                                        >> Unique(State())
                                        >> Select(State(), always_true));
  return evaluate(v, parent);
}
*/

/*
#define DOMAIN_NAMESPACE HFSM
#include "LEESA.h"
using namespace HFSM;
std::vector<State> leesa_example6(RootFolder rf)
{
  // Traversing srcTransition association using srcTransition_end.
  using namespace LEESA;
  BOOST_AUTO(states, RootFolder() >> State() >> State());
  std::vector<State> v = evaluate(rf, states);
  BOOST_AUTO(s11, State() >> Transition() >> Association(Transition::srcTransition_end));
  return evaluate(v, s11);
}
*/

/*
#define DOMAIN_NAMESPACE HFSM
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

int leesa_example7(RootFolder rf)
{
  using namespace LEESA;
  CountVisitor cv;
  evaluate(rf, RootFolder() DEPTH_FIRST State() >> Transition() >> cv);
  return cv.get_count();
}
*/

/*
#define DOMAIN_NAMESPACE HFSM
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
    >> MembersOf(RootFolder(), visit_input_sequence  FOLLOWED_BY  visit_state));
  return cv.get_states();
}
*/

/*
#define DOMAIN_NAMESPACE HFSM
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
