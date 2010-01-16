#ifndef __SP_BREADTH_FIRST_CPP
#define __SP_BREADTH_FIRST_CPP

namespace LEESA {

template <class A, class D, unsigned int S, class C> struct LevelDescendantsOp;
template <class Strategy, class Descendant, class Custom> struct Star;


template <class A, class D, unsigned int S, class C>
struct ET <LevelDescendantsOp<A, D, S, C> >
  : public ETBase <LevelDescendantsOp<A, D, S, C> > {};

struct Underbar {} _; 

template <class Storage>
struct Collect
{
  Storage & storage_;
  
  Collect (Storage & s) : storage_(s) {}

  // These templates are needed because Star operator
  // expects its parameter strategy to have a member template
  // overloaded apply functions.
  template <class Kind>
  typename    
  disable_if <is_same<typename ET<Storage>::argument_kind,
                      typename ET<Kind>::argument_kind>,
              void>::type
  apply (typename ET<Kind>::argument_type const &)
  {
    // For any type other than result_type and result_kind, simply neglect
    // the argument. Noop. For desired types, push them in the retval. 
  }
  template <class Kind>
  typename    
    enable_if <is_same<typename ET<Storage>::argument_kind,
                       typename ET<Kind>::argument_kind>,
               void>::type
  apply (typename ET<Kind>::argument_type const & arg)
  {
    storage_.push_back(arg);
  }
};

template <class Storage, class Custom = LEESA::Default>
struct CollectBFS 
{
  Storage & storage_;

  CollectBFS (Storage & s) : storage_(s) {}

  // These templates are needed because Star operator
  // expects its parameter strategy to have a member template
  // overloaded apply functions.
  template <class Kind>
  typename    
  disable_if <is_same<typename ET<Storage>::argument_kind,
                      typename ET<Kind>::argument_kind>,
                void>::type
  apply (typename ET<Kind>::argument_type const & arg)
  {
    typedef typename ET<Kind>::argument_kind argument_kind;
    Star<CollectBFS, Storage, Custom> star(storage_);
    star.template apply<argument_kind>(arg);
  }
  template <class Kind>
  typename    
    enable_if <is_same<typename ET<Storage>::argument_kind,
                       typename ET<Kind>::argument_kind>,
               void>::type
  apply (typename ET<Kind>::argument_type const & arg)
  {
    typedef typename ET<Kind>::argument_kind argument_kind;
    storage_.push_back(arg);
    Star<CollectBFS, Storage, Custom> star(storage_);
    star.template apply<argument_kind>(arg);
  }
  
};

template <class Descendant, 
       unsigned int SkipCount, 
       class Custom = LEESA::Default>
struct StarGen
{
typedef Star<typename StarGen<Descendant, 
                              SkipCount - 1,
                              Custom>::type,
             Descendant,
             Custom> type;
};

template <class Descendant, class Custom>
struct StarGen <Descendant, 0, Custom>
{
typedef Collect <typename ET<Descendant>::result_type> type;
};

template <class Ancestor, 
          class Descendant, 
          unsigned int SkipCount, 
          class Custom = LEESA::Default>
struct LevelDescendantsOp : public LEESAUnaryFunction<Ancestor, Descendant>, OpBase
{
public:
  typedef ChainExpr<Ancestor, LevelDescendantsOp> expression_type;
  typedef LEESAUnaryFunction <Ancestor, Descendant> Super;
  SUPER_TYPEDEFS(Super);
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<argument_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<argument_kind, result_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::LevelDescendantKindConcept<argument_kind, result_kind, SkipCount, Custom>));

  explicit LevelDescendantsOp () {}

  result_type operator () (argument_type arg)
  {
    typedef FilterChildrenIfNotDescendantCarry<Descendant, Custom> Customizer;
    result_type result;
    typedef typename 
      StarGen<result_type, 
              SkipCount + 1, 
              Customizer
             >::type NestedStarStrategy;
    NestedStarStrategy strategy(result);
    strategy.template apply<argument_kind>(arg);
    return result;
  }
};

template <class Strategy, class Storage, class Custom = LEESA::Default> 
struct Star 
{
    Storage & store_;
    
    explicit Star (Storage & s): store_(s) {}

    template <class Kind>
    void apply (typename ET<Kind>::argument_type const & arg)
    {
      if(arg.empty())
        return;

      typedef typename KindTraits<Kind, Custom>::ChildrenKinds Children;
      this->template dispatch<Kind, Children>(arg, Children());
    }

  protected:
    // Called when ChildrenVector is non-empty. 
    template <class Kind, class ChildrenVector>
    typename disable_if<empty<ChildrenVector>, void>::type 
    dispatch(typename ET<Kind>::argument_type const & arg, ChildrenVector)
    {
      typedef typename ET<Kind>::argument_kind argument_kind;
      typedef typename ET<Kind>::argument_type argument_type;
      typedef typename front<ChildrenVector>::type Head;
      typedef typename pop_front<ChildrenVector>::type Tail;
      typedef typename ET<Head>::result_type result_type;
      const result_type dummy;
      GetChildrenOp <argument_type, result_type> gcop(dummy);

      Strategy strategy(store_);
      strategy.template apply<Head>(gcop(arg));
      this->template dispatch<Kind, Tail>(arg, Tail());
    }
    // Called when ChildrenVector is empty as in EmptyMPLVector0.
    template <class Kind, class ChildrenVector>
    typename enable_if_c<empty<ChildrenVector>::value, void>::type 
    dispatch(typename ET<Kind>::argument_type const &, ChildrenVector) { }
};


#define LEVEL_DESCENDANTS_OF_FUNCTIONS(x,...)                                                    \
template <class Ancestor, class Descendant>                                                      \
LevelDescendantsOp <typename ET<Ancestor>::argument_type,                                        \
                    typename ET<Descendant>::result_type, x>                                     \
LevelDescendantsOf(Ancestor, __VA_ARGS__, Descendant)                                            \
{                                                                                                \
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<Ancestor, Descendant, LEESA::Default>));    \
                                                                                                 \
  typedef typename ET<Ancestor>::argument_type argument_type;                                    \
  typedef typename ET<Descendant>::result_type result_type;                                      \
                                                                                                 \
  return LevelDescendantsOp<argument_type, result_type, x>();                                    \
}                                                                                                \
                                                                                                 \
template <class Ancestor, class Descendant, class Custom>                                        \
LevelDescendantsOp <typename ET<Ancestor>::argument_type,                                        \
                    typename ET<Descendant>::result_type, x, Custom>                             \
LevelDescendantsOf(Ancestor, __VA_ARGS__, Descendant, Custom)                                    \
{                                                                                                \
  BOOST_CONCEPT_ASSERT((LEESA::DescendantKindConcept<Ancestor, Descendant, Custom>));            \
                                                                                                 \
  typedef typename ET<Ancestor>::argument_type argument_type;                                    \
  typedef typename ET<Descendant>::result_type result_type;                                      \
                                                                                                 \
  return LevelDescendantsOp<argument_type, result_type, x, Custom>();                            \
}


LEVEL_DESCENDANTS_OF_FUNCTIONS(1,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(2,Underbar,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(3,Underbar,Underbar,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(4,Underbar,Underbar,Underbar,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(5,Underbar,Underbar,Underbar,Underbar,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(6,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(7,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(8,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(9,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar);
LEVEL_DESCENDANTS_OF_FUNCTIONS(10,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar,Underbar);

} // namespace LEEESA

#endif // __SP_BREADTH_FIRST_CPP

