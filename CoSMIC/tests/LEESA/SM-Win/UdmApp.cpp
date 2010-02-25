#include "stdafx.h"
#include "UdmApp.h"
#include "UdmConfig.h"
#include "Uml.h"

#include <string>

#include "SM.h"

#define DOMAIN_HAS_MUTUAL_RECURSION
#define DOMAIN_NAMESPACE SM
#include "LEESA.h"

/*********************************************************************************/
/* Initialization function. The framework calls it before preparing the backend. */
/* Initialize here the settings in the config global object.					 */
/* Return 0 if successful.														 */
/*********************************************************************************/
int CUdmApp::Initialize()
{


	// TODO: Your initialization code comes here...
	return 0;
}



/* 
Remarks to CUdmApp::UdmMain(...):
0.	The p_backend points to an already open backend, and the framework 
	closes it automatically. DO NOT OPEN OR CLOSE IT!
	To commit changes use p_backend->CommitEditSequence().
	To abort changes use p_backend->AbortEditSequence().
	To save changes to a different file use p_backend->SaveAs() or p_backend->CloseAs().

1.	Focus is the currently open model.

2.	The possible values for param (from GME DecoratorLib.h component_startmode_enum):
	GME_MAIN_START			=   0,
	GME_BROWSER_START		=   1,
	GME_CONTEXT_START		=   2,
	GME_EMBEDDED_START		=   3,
	GME_MENU_START			=  16,
	GME_BGCONTEXT_START		=  18,
	GME_ICON_START			=  32,
	METAMODEL_CHECK_SYNTAX	= 101

 3. The framework catches all the exceptions and reports the error in a message box,
	clean up and close the transactions aborting the changes. You can override this 
	behavior by catching udm_exception. Use udm_exception::what() to form an error 
	message.
*/

/***********************************************/
/* Main entry point for Udm-based Interpreter  */
/***********************************************/

void show(unsigned int t, std::string message)
{
	std::ostringstream ostr;
	ostr << message << typeid(t).name() << " = " << t;
	AfxMessageBox(ostr.str().c_str());
}

template <class T>
void show(T t, std::string message)
{
	std::string s = message + " " + typeid(t).name()
						+ " = " + std::string(t.name());
	AfxMessageBox(s.c_str());
}

using namespace SM;

class SMVisitor : public SM::Visitor
{
public:
	virtual void Visit_State(const State & s) {
		show(s, "Showing");
	}
	virtual void Visit_BaseState(const BaseState & b) {
		show(b, "Showing");
	}
	virtual void Visit_StartState(const StartState & ss) {
		show(ss, "Showing");
	}
	virtual void Visit_StateMachine(const StateMachine & sm) {
		show(sm, "Showing");
	}
	virtual void Visit_RootFolder(const RootFolder & rf) {
		show(rf, "Showing");
	}
	virtual void Visit_Transition(const Transition & tr) {
		show(tr, "Showing");
	}

  virtual void Leave_State(const State & s) {
		show(s, "Leaving");
	}
	virtual void Leave_BaseState(const BaseState & b) {
		show(b, "Leaving");
	}
	virtual void Leave_StartState(const StartState & ss) {
		show(ss, "Leaving");
	}
	virtual void Leave_StateMachine(const StateMachine & sm) {
		show(sm, "Leaving");
	}
	virtual void Leave_RootFolder(const RootFolder & rf) {
		show(rf, "Leaving");
	}
	virtual void Leave_Transition(const Transition & tr) {
		show(tr, "Leaving");
	}
};

struct VarUser : public std::unary_function<State, void>
{
  StateMachine & sm_;
  State & s_;

  VarUser(StateMachine & sm, State & s) 
    : sm_(sm), s_(s)
  {}
  
  void operator () (State s) const
  {
    std::string str = "StateMachine = " + std::string(sm_.name()) + "\n"
                       + "State = " + std::string(s.name());
	  AfxMessageBox(str.c_str());
  }
};

void breadth_first_tests(RootFolder rf)
{
  SMVisitor visitor;

  evaluate(rf, RootFolder() >> StateMachine() >> State());
  evaluate(rf, RootFolder() >> visitor >> StateMachine() >> visitor >> State() >> visitor);
  evaluate(rf, RootFolder()[visitor] >> StateMachine()[visitor]);
  evaluate(rf, RootFolder()[visitor] >> StateMachine()[visitor] >> State()[visitor]);
  evaluate(rf, RootFolder()[visitor] >> StateMachine()[visitor] >> State() >> visitor);
  evaluate(rf, RootFolder()[visitor] >> visitor >> visitor);

  std::vector<StateMachine> smv = evaluate(rf, RootFolder() >> StateMachine());
  evaluate(smv, StateMachine() >> State());
  evaluate(smv, StateMachine()[visitor] >> State());
}

template <class Kind>
bool always_true (Kind)
{
  return true;
}

template <class Kind>
void apply (Kind)
{ }

void breadth_first_operator_tests(RootFolder rf)
{
  SMVisitor visitor;

  std::vector<StateMachine> smv = 
  evaluate(rf, RootFolder() >> SelectByName(RootFolder(), "R.*") >> StateMachine());
  evaluate(smv, StateMachine() >> Select(StateMachine(), always_true<StateMachine>));
  evaluate(smv, StateMachine() >> SelectSubSet(smv));
  evaluate(smv, StateMachine() >> SelectSubSet(smv.begin(), smv.end()));
  evaluate(smv, StateMachine() >> ForEach(StateMachine(), apply<StateMachine>));
  evaluate(smv, StateMachine() >> Unique(StateMachine()));
  evaluate(smv, StateMachine() >> BaseState() >> CastFromTo(BaseState(), State()));
}

void CUdmApp::UdmMain(
					 Udm::DataNetwork* p_backend,		// Backend pointer(already open!)
					 Udm::Object focusObject,			// Focus object
					 set<Udm::Object> selectedObjects,	// Selected objects
					 long param)						// Parameters
{	
	using namespace LEESA;
  using namespace boost::tuples;

	try {
    
		RootFolder rf = RootFolder::Cast (p_backend->GetRootObject());
    SMVisitor visitor;

    //breadth_first_tests(rf);
    //breadth_first_operator_tests(rf);
/*
    BOOST_AUTO(test2, RootFolder() >> StateMachine() >>= State() >>  visitor);
    std::vector<State> sv = evaluate(rf, test2);
*/
    std::vector<StateMachine> smv =
    evaluate(rf, RootFolder() >> StateMachine()[visitor]);
    
    typedef tuple<State, StartState> TestTuple;
    std::vector<TestTuple > vt = 
      evaluate(smv, StateMachine() >> MembersAsTupleOf(StateMachine(), TestTuple()));
    
    evaluate(rf, RootFolder() >> LevelDescendantsOf(RootFolder(), _, _, StateMachine()));
    evaluate(smv, StateMachine() >> DescendantsOf(StateMachine(), State()));
    evaluate(rf, RootFolder() >> VisitLeave(RootFolder(), visitor,
                                 RootFolder() >>= StateMachine() 
                                 >> VisitLeave(StateMachine(), visitor,
                                    StateMachine() >>= State()
                                    >> VisitLeave(State(), visitor))));

    BOOST_FOREACH(TestTuple t, vt)
    {
      std::string ostr = std::string() 
                         + "element<0>::type = " + typeid(element<0, TestTuple>::type).name() + "\n"
                         + "get<0>::value = " + std::string(get<0>(t).name()) + "\n"
                         + "element<1>::type = " + typeid(element<1, TestTuple>::type).name() + "\n"
                         + "get<1>::value = " + std::string(get<1>(t).name()) + "\n";

      AfxMessageBox(ostr.c_str());
    }
/*  
		std::vector<StartState> SSvector = 
		evaluate(rf, RootFolder()
					>> StateMachine()
					>> visitor
					>> BaseState() 
					>> CastFromTo(BaseState(), StartState())
          >> visitor);

		show(SSvector.size(), "SSvector.size() = ");

    evaluate(SSvector, StartState()[visitor] <<= StateMachine()[visitor]);
*/
    /*
    evaluate(rf, RootFolder()
          >> StateMachine() 
          >> State()
          << StateMachine()[visitor]
          << RootFolder()[visitor]);

		evaluate(rf, RootFolder() 
              >> AroundFullTD(RootFolder(), VisitStrategy(visitor), LeaveStrategy(visitor)));

		BOOST_AUTO(v_state, State() >> visitor);
		BOOST_AUTO(v_transition, Transition() >> visitor);
		BOOST_AUTO(sm, RootFolder() >> StateMachine());
		evaluate(rf, sm >>= MembersOf(StateMachine(), v_state, v_transition));
    evaluate(rf, sm >>= MembersOf(StateMachine(), State()[visitor], Transition()[visitor]));

		evaluate(rf, sm >>= Transition() 
			>> Association(Transition::dstTransition_end)
			>> visitor);		

    evaluate (rf, RootFolder() >> DescendantsOf(RootFolder(), BaseState()) >> visitor);

    evaluate (rf, RootFolder() >> DescendantsOf(RootFolder(), Transition()));
    evaluate(rf, RootFolder() 
                  >> StateMachine()
                  >> State() 
                  >> DescendantsOf(State(), BaseState()));
    
    evaluate(rf, RootFolder() >>
                    AP(VisitStrategy(visitor),
                       FROM(RootFolder),
                       TO(State),
                       THROUGH(StateMachine)));
*/
	}
	catch (boost::regex_error & e)
	{
		std::string error = std::string("boost::regex_error = ") + e.what();
		AfxMessageBox(error.c_str());
	}
	catch (std::runtime_error & e)
	{
		AfxMessageBox(e.what());
	}
	catch(...)
	{
		AfxMessageBox("An unknown exception was caught!");
	}






#ifdef _DEBUG
	// Displaying the name of the root object meta
	Udm::Object rootObject=p_backend->GetRootObject();
	string rootObjectName("Root Object's Class Name: ");
	rootObjectName+=ExtractName(rootObject.type());
	AfxMessageBox(rootObjectName.c_str());

	// Displaying the focus object
	if(focusObject!=&Udm::_null)
	{
		string focusObjectName("Focus Object Name: ");
		focusObjectName+=ExtractName(focusObject);
		AfxMessageBox(focusObjectName.c_str());
	}

	// Displaying selected objects
	if(!selectedObjects.empty())
	{
		string selObjNames("Selected Objects:\r\n");
		// Iterate set
		for(set<Udm::Object>::iterator i=selectedObjects.begin();
														i!=selectedObjects.end();i++)
		{
			selObjNames+=ExtractName(*i);
			selObjNames+="\r\n";
		}
		AfxMessageBox(selObjNames.c_str());	
	}
#endif
/****************************** Demo Code End *************************/
													
}



#ifdef _DEBUG
/*****************************************************/
/* Debug time helper function. If the object has an  */
/* attribute called "name", this function retreives  */
/* it to help you to find it in the model during the */
/* application development.	Usually every GME Object */
/* has a "name" attribute. If an object hapens not	 */
/* to have it,function retreives <no name specified>.*/
/*****************************************************/
string CUdmApp::ExtractName(Udm::Object ob)
{
	Uml::Class cls= ob.type();				
	set<Uml::Attribute> attrs=cls.attributes();		
	
	// Adding parent attributes
	set<Uml::Attribute> aattrs=Uml::AncestorAttributes(cls);
	attrs.insert(aattrs.begin(),aattrs.end());

	for(set<Uml::Attribute>::iterator ai = attrs.begin();ai != attrs.end(); ai++) 
	{
		if(string(ai->type())=="String")
		{
			string str=ai->name();
			if(str=="name")
			{
				string value=ob.getStringAttr(*ai);
				if(value.empty())value="<empty string>";
				return value;
			}			
		}				
	}	
	return string("<no name specified>");
}
#endif
