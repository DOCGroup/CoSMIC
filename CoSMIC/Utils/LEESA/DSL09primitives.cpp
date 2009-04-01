template <class Strategy>
class ALL 
{
  Strategy strategy_;
public:
  ALL(Strategy s) : strategy_(s) {}
  template <class T>
  void apply (T arg) 
  {
    children(arg, typename T::ChildrenKinds());
  }
private:
  template <class T, class Children>
  void children (T arg, Children) 
  {
    typedef typename mpl::front<Children>::type Head;
    typedef typename mpl::pop_front<Children>::type Tail;
    std::set<Head> set = arg.children_kind<Head>();
    BOOST_FOREACH(Head h, set)
    {
      strategy_.apply<Head>(h);
    }
    children(arg, Tail()); 
  }
  template <class T>
  void children(T, LEESA::EmptyMPLVector) { }
  template <class T>
  void children(T, LEESA::EmptyMPLVectorB) { }
};

template <class S1, class S2>
class SEQ 
{
  S1 s1_;
  S2 s2_;
public:
  SEQ(S1 s1, S2 s2) : s1_(s1), s2_(s2) {}
  template <class T>
  void apply (T arg) 
  {
    s1_.apply(arg);
    s2_.apply(arg);
  }
};

template <class Strategy>
class FULLTD
{
  Strategy strategy_;
public:
  FULLTD(Strategy s) : strategy_(s) {}
  template <class T>
  void apply (T arg) 
  {
    ALL<FULLTD> all(*this);
    SEQ<Strategy, ALL<FULLTD> > seq(strategy_, all);
    seq.apply(arg);
  }
};

class VisitStrategy
{
  Visitor & visitor_;
public:
  VisitStrategy (HFSM::Visitor & v) : visitor_(v) {}
  template <class T>
  void apply (T arg)
  {
    arg.Accept(visitor_);
  }
};
