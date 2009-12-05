#include "UdmApp-PICML.h"
#include "UdmConfig-PICML.h"
#include "Uml.h"

#include <string>

#include "PICML.h"

#define AfxMessageBox(...) 

#define DOMAIN_NAMESPACE PICML
#include "LEESA.h"

using namespace PICML;

class PICMLVisitor : public PICML::Visitor
{
};

void CUdmApp::UdmMain( Udm::DataNetwork* p_backend,		// Backend pointer(already open!)
                       Udm::Object focusObject,			// Focus object
                       set<Udm::Object> selectedObjects,	// Selected objects
                       long param)						// Parameters
{	
	using namespace LEESA;
	try {
          
		RootFolder rf = RootFolder::Cast (p_backend->GetRootObject());
		PICMLVisitor visitor;

    /********************* Warning: Takes long time ***********************
    evaluate (rf, RootFolder() >> AroundFullTD(RootFolder(), VisitStrategy(visitor), LeaveStrategy(visitor)));
    evaluate (rf, RootFolder() >> FullTD(RootFolder(), VisitStrategy(visitor)));
    */
    evaluate (rf, RootFolder() >> DescendantsOf(RootFolder(), Member()));
    evaluate (rf, RootFolder() >> DescendantsOf(RootFolder(), Transition()));
   
    evaluate(rf, RootFolder() 
                  >> AP(VisitStrategy(visitor),
                        FROM(RootFolder),
                        TO(Member),
                        THROUGH(File)));
   
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

