#include "stdafx.h"
#include <cstring>
#include <iostream>

#include "HFSM.h"
#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"

#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
//#include <ace/High_Res_Timer.h>

using namespace HFSM;
using namespace boost;
using namespace HFSM;

class CountVisitor : public HFSM::Visitor 
{
  int count_;
public:
  CountVisitor () : count_(0) {}
  void Visit_RootFolder(const RootFolder &rf) {
    std::string name = std::string("RootFolder: ") + std::string(rf.name());
    std::cout << name << std::endl;
  }
  void Visit_Transition(const Transition &t) {
    std::string name = std::string("Transition: ") + std::string(t.name());
    std::cout << name << std::endl;
  }
  void Visit_State(const State &s) {
    std::string name = std::string("State: ") + std::string(s.name());
    std::cout << name << std::endl;
    count_++;
  }
  void Visit_Reference(const Reference &r) {
    std::string name = std::string("Reference: ") + std::string(r.name());
    std::cout << name << std::endl;
    count_++;
  }
  void Visit_InputSequence(const InputSequence &i) {
    std::string name = std::string("InputSequence: ") + std::string(i.name());
    std::cout << name << std::endl;
  }
  void Visit_Sequence(const HFSM::Sequence &s) {
    std::string name = std::string("Sequence: ") + std::string(s.name());
    std::cout << name << std::endl;
  }
  void Visit_Events(const Events &e) {
    std::string name = std::string("Events: ") + std::string(e.name());
    std::cout << name << std::endl;
  }
  void Visit_StateMachine(const StateMachine &e) {
    std::string name = std::string("StateMachine: ") + std::string(e.name());
    std::cout << name << std::endl;
    //throw LEESA::LEESAException("Exception in StateMachine.");
  }
  //void Visit_Object(const Udm::Object &) const {}
  int get_count() { return count_; }
};

struct ReferenceCustom : public LEESA::Default
{
  // See gcc bug #39906 related to explicit specialization
  // of class member templates.
  // http://gcc.gnu.org/bugzilla/show_bug.cgi?id=39906

  using LEESA::Default::GetChildObjects;
  static std::set<Udm::Object> GetChildObjects(HFSM::Reference r)
  {
    HFSM::State s = r.ref();
    if (s != Udm::null)
    {
      LEESA::VISITED.insert(s);
      return s.GetChildObjects();
    }
    return LEESA::ObjectSet();
  };
};

template <class T>
struct LEESA::ChildrenKinds <ReferenceCustom, T> : ChildrenKinds<LEESA::Default, T>
{
};  

template <class T>
struct LEESA::DescendantKinds <ReferenceCustom, T> : ChildrenKinds<LEESA::Default, T>
{
};

/*
struct Foo : ReferenceCustom
{
  using ReferenceCustom::ChildrenKinds;
  template <>
  struct ChildrenKinds <int>
  {
    typedef int type;
  };  
};*/

/* According to the C++ language standard, explicit specialization
   of the member template must be defined in the namespace scope. */
/*template <>
struct ReferenceCustom::ChildrenKinds<HFSM::Reference> {
  typedef HFSM::State::ChildrenKinds type;
};
template <>
struct ReferenceCustom::DescendantKinds<HFSM::Reference> {
  typedef HFSM::State::DescendantKinds type;
};
*/

RootFolder create(Udm::SmartDataNetwork & nw, const char * const);
RootFolder open(Udm::SmartDataNetwork & nw, const char * const);
int _tmain(int argc, _TCHAR* argv[])
{
	try {
    if(argc < 3) {
      std::cerr << "Usage: " << argv[0] << " [-c | -o] <filename>" << std::endl;
      return -1;
    }

    using namespace LEESA;
    CountVisitor cv;
    VisitStrategy vs(cv);
    //FullTD<VisitStrategy> fulltd (VS);
    Udm::SmartDataNetwork nw(diagram);
    RootFolder rf;

    if (strcmp(argv[1], "-c") == 0)
    {
      rf = create(nw, argv[2]);
    }
    else if(strcmp(argv[1], "-o") == 0)
    {
      rf = open(nw, argv[2]);
    }
    else
      std::cerr << "Invalid arguments." << std::endl;

/*    evaluate(rf, RootFolder()
      >> MembersOf(RootFolder(), 
                   StateMachine() >>= MembersOf(StateMachine(), FinalState() >> FullTD(FinalState(), vs)),
                   InputSequence() >> cv));
   
    evaluate (rf, AP(vs,
                     FROM(RootFolder), 
                     TO(HFSM::Sequence, Events),
                     THROUGH(InputSequence)));

    typedef BaseState DesiredType;
    std::vector<StateMachine> sm_set = 
      evaluate(rf, RootFolder() >> StateMachine());
    StateMachine sm = *sm_set.begin();
    std::set<Udm::Object> o_set = sm.GetChildObjects();
    std::cout << "size = " << o_set.size() << std::endl;
    BOOST_FOREACH(Udm::Object o, o_set)
    {
      std::cout << (o.type() == Transition::meta) << std::endl;
    }
*/
    //evaluate(rf, RootFolder() >> FullTDGraph(RootFolder(), vs, ReferenceCustom()));
    //LEESA::VISITED.clear();

    evaluate(rf, RootFolder() 
      >> StateMachine()
      >> SelectByName(StateMachine(), "SM1")
      >> GraphDescendantsOf(StateMachine(), State(), ReferenceCustom()) >> cv);
    /*evaluate (rf, AP(vs,
                     FROM(RootFolder), 
                     TO(HFSM::Reference),
                     THROUGH(HFSM::State),
                     CUSTOMIZER(ReferenceCustom)
                     ));*/
  }
  catch(const udm_exception &e)
	{
		cout << "Exception: " << e.what() << endl;
		return(-1);
	} 

  return 0;
}

RootFolder create(Udm::SmartDataNetwork & nw, const char * const filename)
{
    nw.CreateNew(filename,"HFSM", RootFolder::meta);
		RootFolder rf = RootFolder::Cast(nw.GetRootObject());
    rf = RootFolder::Create(rf);
    rf = RootFolder::Create(rf);
    rf.name() = "ROOTFOLDER";
    StateMachine sm = StateMachine::Create(rf);
    sm.name() = "SM1";
    State s = State::Create(sm);
    s.name() = "State1";
    return rf;
}

template <class T>
void print (T const & t)
{
  std::cout << typeid(T).name() << ": " << t.name() << std::endl;
}

RootFolder open(Udm::SmartDataNetwork & nw, const char * const filename)
{
    nw.OpenExisting(filename,"HFSM");
		RootFolder rf = RootFolder::Cast(nw.GetRootObject());
    return rf;
}


int leesa_example(RootFolder const &rf)
{

   return 0;
}


/*
class All : public Udm::BaseVisitor
{
    Udm::BaseVisitor * visitor_;
  public:
    All (Udm::BaseVisitor * v) : visitor_(v) {}
    virtual void Visit_Object (const Udm::Object &o)
    {
      std::set<Udm::Object> s = o.GetChildObjects();
      //std::set<Udm::Object> s = GetChildrenTyped(o);
      for(std::set<Udm::Object>::iterator iter (s.begin());
          iter != s.end();
          ++iter)
      {
        (*iter).Accept(*visitor_);
      }
    }
};

class Sequence : public Udm::BaseVisitor
{
  protected:
    Udm::BaseVisitor * v1_;
    Udm::BaseVisitor * v2_;
  public:
    Sequence (Udm::BaseVisitor * v1, Udm::BaseVisitor * v2)
      : v1_(v1), v2_(v2) {}
    virtual void Visit_Object (const Udm::Object &o)
    {
      o.Accept(*v1_);
      o.Accept(*v2_);
    }
};

class TopDown : public Sequence
{
    All all;
  public:
    TopDown (Udm::BaseVisitor * v) 
      : Sequence(v, 0), all (this)
    {
      Sequence::v2_ = &all;
    }
};
*/

/*
class Fwd : public HFSM::Visitor
{
    Udm::BaseVisitor * visitor_;
  public:
    Fwd(Udm::BaseVisitor * v) : visitor_(v) {}
    virtual void Visit_DataFlow(const HFSM::DataFlow & d) {
      d.Accept(*visitor_);
    }
		virtual void Visit_DataStore(const HFSM::DataStore &d) {
      d.Accept(*visitor_);
    }
		virtual void Visit_Process(const HFSM::Process &p) {
      p.Accept(*visitor_);
    }
		virtual void Visit_Entity(const HFSM::Entity &e) {
      e.Accept(*visitor_);
    }
		virtual void Visit_ContextDFD(const HFSM::ContextDFD &c) {
      c.Accept(*visitor_);
    }
		virtual void Visit_RootFolder(const HFSM::RootFolder &r) {
      r.Accept(*visitor_);
    }
};

typedef ::HFSM::Process DesiredType;
//typedef ::HFSM::DataStore DesiredType;

using namespace HFSM;
class CountVisitor : public HFSM::Visitor 
{
    int count_;
    std::set<DesiredType> s_;

  public:
    CountVisitor () : count_(0) {}

    template <class T>
    void showname(T o) {
      //std::string name = o.name();
      ////AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    }

    virtual void Visit_DataFlow(const HFSM::DataFlow & d) {
      ++count_;
      showname(d);
    }
		virtual void Visit_DataStore(const HFSM::DataStore &d) {
      ++count_;
      showname(d);
      //s_.insert(d);
    }
		virtual void Visit_Process(const HFSM::Process &p) {
      ++count_;
      showname(p);
      s_.insert(p);
    }
		virtual void Visit_Entity(const HFSM::Entity &e) {
      ++count_;
      showname(e);
    }
		virtual void Visit_ContextDFD(const HFSM::ContextDFD &c) {
      ++count_;
      showname(c);
    }
		virtual void Visit_RootFolder(const HFSM::RootFolder &r) {
      ++count_;
      showname(r);
    }

    int get_count() const {
      return count_;
    }
    std::set<DesiredType> get_DesiredType(){
      return s_;
    }
    void reset () { count_ = 0; s_.clear(); }
    ~CountVisitor() {  reset(); }
};

void dispatch (HFSM::Visitor & v, Udm::Object & o)
{
  o.Accept(v);
}


int leesa_example(RootFolder rf)
{
    ACE_High_Res_Timer t;
    ACE_Time_Value tv1, tv2;
          
  try {
    long time1 = 0, time2 = 0;
    long count1 = 0, count2 = 0;
    t.start();
    for(int i=0;i < 100;i++)
    {
      CountVisitor cv;
      TopDown td(&cv);
      Fwd top_down_fwd(&td);
      //t.start();
      top_down_fwd.Visit_RootFolder(rf);
      //t.stop();
      //t.elapsed_time(tv1);
      //time1 += tv1.msec();
      std::set<DesiredType> s1 = cv.get_DesiredType();
      count1 += s1.size();
      cv.reset();

      //t.start();
      //using namespace LEESA;
      //std::set<DesiredType> s2 = evaluate (rf, RootFolder() >> DescendantFrom(RootFolder(),DesiredType()));
      //evaluate (rf, RootFolder() >> FullTD(RootFolder(), VisitStrategy(cv)));
      //t.stop();
      //s2 = cv.get_DesiredType();
      //count2 += s2.size();
      //t.elapsed_time(tv2);
      //time2 += tv2.msec();
    }
    t.stop();
    t.elapsed_time(tv2);
    time2 = tv2.msec();
    ostringstream ostr;
    ostr << "msec1 = " << time1 << ", " << "msec2 = " << time2 << endl;
    ostr << "count1 = " << count1 << ", " << "count2 = " << count2;
    //AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
  }
  catch(const std::runtime_error & e) {
    //AfxMessageBox (e.what(), MB_OK| MB_ICONINFORMATION);
  }

  return 0;
}
*/

/*
class CountVisitor : public HFSM::Visitor 
{
  int count_;
public:
  CountVisitor () : count_(0) {}
  void Visit_RootFolder(const RootFolder &rf) {
    std::string name = std::string("RootFolder: ") + std::string(rf.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
  }
  void Visit_Transition(const Transition &t) {
    std::string name = std::string("Transition: ") + std::string(t.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
  }
  void Visit_State(const State &s) {
    std::string name = std::string("State: ") + std::string(s.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
    count_++;
  }
  void Visit_StartState(const StartState &s) {
    std::string name = std::string("StartState: ") + std::string(s.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
    count_++;
  }
  void Visit_FinalState(const FinalState &s) {
    std::string name = std::string("FinalState: ") + std::string(s.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
    count_++;
  }
  void Visit_BaseState(const BaseState &s) {
    std::string name = std::string("BaseState: ") + std::string(s.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
    count_++;
  }
  void Visit_InputSequence(const InputSequence &i) {
    std::string name = std::string("InputSequence: ") + std::string(i.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
  }
  void Visit_Sequence(const HFSM::Sequence &s) {
    std::string name = std::string("Sequence: ") + std::string(s.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
  }
  void Visit_Events(const Events &e) {
    std::string name = std::string("Events: ") + std::string(e.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
  }
  void Visit_StateMachine(const StateMachine &e) {
    std::string name = std::string("StateMachine: ") + std::string(e.name());
    //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    std::cout << name << std::endl;
    //throw LEESA::LEESAException("Exception in StateMachine.");
  }
  //void Visit_Object(const Udm::Object &) const {}
  int get_count() { return count_; }
};
*/


/*
std::set<Udm::Object> GetChildrenTyped (Udm::Object o)
{
  using namespace Udm;
  using namespace HFSM;
  std::set<Object> s;
  if (Udm::IsDerivedFrom(o.type(), RootFolder::meta))  
  {
    RootFolder rf = RootFolder::Cast(o);
    std::set<ContextDFD> cs = rf.children_kind<ContextDFD>();
    s.insert(cs.begin(),cs.end());
  }
  else if (Udm::IsDerivedFrom(o.type(), ContextDFD::meta))  
  {
    ContextDFD c = ContextDFD::Cast(o);
    std::set<Process> sp = c.children_kind<Process>();
    s.insert(sp.begin(),sp.end());
    std::set<Entity> se = c.children_kind<Entity>();
    s.insert(se.begin(),se.end());
    std::set<DataFlow> sd = c.children_kind<DataFlow>();
    s.insert(sd.begin(),sd.end());
  }
  else if (Udm::IsDerivedFrom(o.type(), Process::meta))  
  {
    Process c = Process::Cast(o);
    std::set<Process> sp = c.children_kind<Process>();
    s.insert(sp.begin(),sp.end());
    std::set<Entity> se = c.children_kind<Entity>();
    s.insert(se.begin(),se.end());
    std::set<DataFlow> sd = c.children_kind<DataFlow>();
    s.insert(sd.begin(),sd.end());
    std::set<DataStore> sds = c.children_kind<DataStore>();
    s.insert(sds.begin(),sds.end());
  }
  return s;
}
*/
