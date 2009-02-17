/*
  Copyright (c) Vanderbilt University, 2000-2001
  ALL RIGHTS RESERVED
  Vanderbilt University disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall Vanderbilt University be liable for
  any special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/


// UdmApp.cpp: implementation of the CUdmApp class.
// This file was automatically generated as UdmApp.cpp
// by UDM Interpreter Wizard on Monday, May 13, 2002 13:45:42

// Tihamér Levendovszky 05-13-02

#include "stdafx.h"
#pragma warning( disable : 4290 )

#include <windows.h>
#include <shlobj.h>
#include "resource.h"
#include <stdlib.h>
#include <sstream>
#include <algorithm>

#include "UdmStatic.h"
#include "UmlExt.h"
#include "UdmUtil.h"

#include "UdmApp.h"
#include "UdmConfig.h"

#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"

#include "HFSM.h"

#include "ace/High_Res_Timer.h"

extern void dummy(void); // Dummy function for UDM meta initialization

// Initialization function. The framework calls it before preparing the
// backend. Initialize here the settings in the config static object.
// Return 0 if successful.
int CUdmApp::Initialize()
{
  return 0;
}
/*
  Remarks to CUdmApp::UdmMain(...):
  0. The p_backend points to an already open backend, and the framework
  closes it automatically. DO NOT OPEN OR CLOSE IT! To commit changes
  use p_backend->CommitEditSequence(). To abort changes use
  p_backend->AbortEditSequence(). To save changes to a different file
  use p_backend->SaveAs() or p_backend->CloseAs().

  1. Focus is the currently open model.

  2. The possible values for param (from GME DecoratorLib.h
  component_startmode_enum):
  GME_MAIN_START		=   0,
  GME_BROWSER_START		=   1,
  GME_CONTEXT_START		=   2,
  GME_EMBEDDED_START		=   3,
  GME_MENU_START		=  16,
  GME_BGCONTEXT_START	=  18,
  GME_ICON_START		=  32,
  METAMODEL_CHECK_SYNTAX	= 101

  3. The framework catches all the exceptions and reports the error in a
  message box, clean up and close the transactions aborting the changes.
  You can override this behavior by catching udm_exception. Use
  udm_exception::what() to form an error message.
*/
/*
using namespace HFSM;
class CountVisitor : public HFSM::Visitor 
{
  int count_;
public:
  CountVisitor () : count_(0) {}
  void Visit_RootFolder(const RootFolder &rf) {
    std::string name = std::string("RootFolder: ") + std::string(rf.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  void Visit_Transition(const Transition &t) {
    std::string name = std::string("Transition: ") + std::string(t.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  void Visit_State(const State &s) {
    std::string name = std::string("State: ") + std::string(s.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    count_++;
  }
  void Visit_StartState(const StartState &s) {
    std::string name = std::string("StartState: ") + std::string(s.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    count_++;
  }
  void Visit_FinalState(const FinalState &s) {
    std::string name = std::string("FinalState: ") + std::string(s.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    count_++;
  }
  void Visit_BaseState(const BaseState &s) {
    std::string name = std::string("BaseState: ") + std::string(s.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    count_++;
  }
  void Visit_InputSequence(const InputSequence &i) {
    std::string name = std::string("InputSequence: ") + std::string(i.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  void Visit_Sequence(const Sequence &s) {
    std::string name = std::string("Sequence: ") + std::string(s.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  void Visit_Events(const Events &e) {
    std::string name = std::string("Events: ") + std::string(e.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  void Visit_StateMachine(const StateMachine &e) {
    std::string name = std::string("StateMachine: ") + std::string(e.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    //throw LEESA::LEESAException("Exception in StateMachine.");
  }
  //void Visit_Object(const Udm::Object &) const {}
  int get_count() { return count_; }
};
*/

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
    /*std::set<Entity> se = c.children_kind<Entity>();
    s.insert(se.begin(),se.end());
    std::set<DataFlow> sd = c.children_kind<DataFlow>();
    s.insert(sd.begin(),sd.end());*/
  }
  else if (Udm::IsDerivedFrom(o.type(), Process::meta))  
  {
    Process c = Process::Cast(o);
    std::set<Process> sp = c.children_kind<Process>();
    s.insert(sp.begin(),sp.end());
    /*std::set<Entity> se = c.children_kind<Entity>();
    s.insert(se.begin(),se.end());
    std::set<DataFlow> sd = c.children_kind<DataFlow>();
    s.insert(sd.begin(),sd.end());
    std::set<DataStore> sds = c.children_kind<DataStore>();
    s.insert(sds.begin(),sds.end());*/
  }
  return s;
}

class All : public Udm::BaseVisitor
{
    Udm::BaseVisitor * visitor_;
  public:
    All (Udm::BaseVisitor * v) : visitor_(v) {}
    virtual void Visit_Object (const Udm::Object &o)
    {
      //std::set<Udm::Object> s = o.GetChildObjects();
      std::set<Udm::Object> s = GetChildrenTyped(o);
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
      //AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
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
    AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
  }
  catch(const std::runtime_error & e) {
    AfxMessageBox (e.what(), MB_OK| MB_ICONINFORMATION);
  }

  return 0;
}


/***********************************************/
/* Main entry point for Udm-based Interpreter  */
/***********************************************/
void CUdmApp::UdmMain(Udm::DataNetwork* p_backend,      // Backend pointer
                                                        // (already open!)
                      Udm::Object focusObject,          // Focus object
                      set<Udm::Object> selectedObjects,	// Selected objects
                      long param)			// Parameters
{
  HFSM::RootFolder rf = HFSM::RootFolder::Cast (p_backend->GetRootObject());
  
  int n = leesa_example(rf);
  std::ostringstream ostr;
  ostr << "UDM_DSL finished: " << n;

  //AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
}
