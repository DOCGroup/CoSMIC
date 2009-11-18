#include "concepts.h"

namespace LEESA {

template <class T1, class T2>
struct is_same
{
  enum { value = false };
};

template <class T>
struct is_same <T, T>
{
  enum { value = true };
};

struct empty {};
struct true_type {};
struct false_type {};

template <int v>
struct ValueToType
{
  typedef true_type type;
};

template <>
struct ValueToType<0>
{
  typedef false_type type;
};

template < typename T1=empty, typename T2=empty, typename T3=empty, 
           typename T4=empty, typename T5=empty > 
struct typelist;

template <typename T1, typename T2, typename T3, typename T4, typename T5> 
struct typelist
{
    typedef T1 head;
    typedef typelist <T2, T3, T4, T5> tail;
};

template <class List, class T>
struct contains 
{
  enum { value = is_same<typename List::head, T>::value ? 1 : 
                    contains<typename List::tail, T>::value }; 
  typedef typename ValueToType<value>::type type;
};

template <class T>
struct contains <typelist<empty,empty,empty,empty,empty>, T> 
{
  enum { value = 0 }; 
  typedef typename ValueToType<value>::type type;
};

auto concept ElementConcept <typename T> 
  : std::DefaultConstructible<T>,
    std::CopyConstructible<T>
{
  typename Children = typename T::Children;
};

auto concept ParentChildConcept <typename Parent, typename Child>
{
  requires ElementConcept<Parent>;
  requires ElementConcept<Child>;
  typename Children = typename Parent::Children;
  typename ParentContainsChild = typename contains<Children, Child>::type;
  requires std::SameType<ParentContainsChild, true_type>;
  Child children (Parent const &, Child const &);
};

template <class L, class H>
requires ParentChildConcept<L,H>
H children (L const & l, H const & h)
{
  return h;
}

template <typename L, typename H>
requires ParentChildConcept<L,H> 
H operator >> (L const & l, H const & h)
{
  return children(l,h);
}

} // namespace LEESA

struct Root;
struct StateMachine;
struct Transition;
struct State;
struct Property;

using namespace LEESA;

struct Root
{
  typedef typelist<StateMachine> Children;
};

struct StateMachine
{
  typedef typelist<Transition, State> Children;
};

struct State
{
  typedef typelist<State, Transition> Children;
};

struct Transition
{
  typedef typelist<> Children;
};

struct Property
{
  typedef typelist<> Children;
};


int main(void)
{
  Root() >> StateMachine() >> State() >> State();
  StateMachine()>>Property();

  return 0;
}
