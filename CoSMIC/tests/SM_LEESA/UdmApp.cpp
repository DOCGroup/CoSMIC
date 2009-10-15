#include "stdafx.h"
#include "UdmApp.h"
#include "UdmConfig.h"
#include "Uml.h"

#include <string>

#include "SM.h"

#define PARADIGM_NAMESPACE_FOR_LEESA SM
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
	virtual void Visit_BaseState(const BaseState & s) {
		show(s);
	}
};

void CUdmApp::UdmMain(
					 Udm::DataNetwork* p_backend,		// Backend pointer(already open!)
					 Udm::Object focusObject,			// Focus object
					 set<Udm::Object> selectedObjects,	// Selected objects
					 long param)						// Parameters
{	
	using namespace LEESA;
	try {
		RootFolder rf = RootFolder::Cast (p_backend->GetRootObject());
		SMVisitor v;
		evaluate(rf, RootFolder() 
						>> StateMachine() 
						>> BaseState() 
						>> v);
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
