#include "UdmApp-SM.h"
#include "UdmConfig-SM.h"
#include "Uml.h"

#include <string>

#include "SM.h"

#define AfxMessageBox(...) 

#define DOMAIN_HAS_MUTUAL_RECURSION
#define DOMAIN_NAMESPACE SM
#include "LEESA.h"

void show(unsigned int t)
{
	std::ostringstream ostr;
	ostr << "Showing " << typeid(t).name() << " = " << t;
	AfxMessageBox(ostr.str().c_str());
}

template <class T>
void show(T t)
{
	std::string s = std::string("Showing ") + typeid(t).name()
						+ " = " + std::string(t.name());
	AfxMessageBox(s.c_str());
}

using namespace SM;

class SMVisitor : public SM::Visitor
{
public:
	virtual void Visit_State(const State & s) {
		show(s);
	}
	virtual void Visit_BaseState(const BaseState & b) {
		show(b);
	}
	virtual void Visit_StartState(const StartState & ss) {
		show(ss);
	}
	virtual void Visit_StateMachine(const StateMachine & sm) {
		show(sm);
	}
	virtual void Visit_RootFolder(const RootFolder & rf) {
		show(rf);
	}
	virtual void Visit_Transition(const Transition & tr) {
		show(tr);
	}
};

void CUdmApp::UdmMain( Udm::DataNetwork* p_backend,		// Backend pointer(already open!)
                       Udm::Object focusObject,			// Focus object
                       set<Udm::Object> selectedObjects,	// Selected objects
                       long param)						// Parameters
{	
	using namespace LEESA;
	try {
          
		RootFolder rf = RootFolder::Cast (p_backend->GetRootObject());
		SMVisitor visitor;
	    
		std::vector<StartState> vector = 
		evaluate(rf, RootFolder() >> StateMachine()
					>> visitor
					>> BaseState() 
					>> CastFromTo(BaseState(), StartState())
					>> visitor);

		show(vector.size());

		evaluate(rf, RootFolder() >> FullTD(RootFolder(), VisitStrategy(visitor)));

		BOOST_AUTO(v_state, State() >> visitor);
		BOOST_AUTO(v_transition, Transition() >> visitor);
		BOOST_AUTO(sm, RootFolder() >> StateMachine());
		evaluate(rf, sm >>= MembersOf(StateMachine(), v_state, v_transition));

		evaluate(rf, sm >>= Transition() 
			>> Association(Transition::dstTransition_end)
			>> visitor);
		
    
    evaluate (rf, RootFolder() >> DescendantsOf(RootFolder(), State()));
    evaluate (rf, RootFolder() >> DescendantsOf(RootFolder(), Transition()));
    
    evaluate(rf, RootFolder() 
                  >> AP(VisitStrategy(visitor),
                        FROM(RootFolder),
                        TO(Transition),
                        THROUGH(StateMachine)));
    
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

}


