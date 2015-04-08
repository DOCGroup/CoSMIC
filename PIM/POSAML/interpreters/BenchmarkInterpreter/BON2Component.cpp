//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON2Component.cpp
//
//###############################################################################################################################################

/*
	Copyright (c) Vanderbilt University, 2000-2004
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

#include <stdafx.h>
#include "BON2Component.h"

void XML_Writer::add_child(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument *doc,DOMElement *root,const String &child,int data)
{
  XMLCh *temp=XMLString::transcode(child.c_str());
  DOMElement *child_ele=doc->createElement(temp);
  XMLString::binToText(data,temp,5,10);
  child_ele->setTextContent(temp);
  root->appendChild(child_ele);
  XMLString::release(&temp);
}

void XML_Writer::add_child(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument *doc,DOMElement *root,const String &child,const String &data)
{
  XMLCh *temp=XMLString::transcode(child.c_str());
  DOMElement *child_ele=doc->createElement(temp);
  temp=XMLString::transcode(data.c_str()); 
  child_ele->setTextContent(temp);
  root->appendChild(child_ele);
  XMLString::release(&temp);
}

bool XML_Writer::write_file(const String &xml_file)
{
  XMLPlatformUtils::Initialize();
  XMLCh *temp=XMLString::transcode("Core");
  DOMImplementation *impl=DOMImplementationRegistry::getDOMImplementation(temp);
  XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument *doc=impl->createDocument();

  temp=XMLString::transcode("1.0");
  doc->setXmlVersion(temp);
  temp=XMLString::transcode("benchmark_inputs");
  DOMElement *root=doc->createElement(temp);
  doc->appendChild(root);
   
  //add_child(doc,root,"iterations",this->no_iterations_);
  add_child(doc,root,"connections",this->no_connections_);
  add_child(doc,root,"data",this->data_);
  add_child(doc,root,"data_exchanges",this->no_data_exchanges_);

  temp=XMLString::transcode("reactor_inputs");
  DOMElement *reactor_child=doc->createElement(temp);
 
  add_child(doc,reactor_child,"reactor_type",this->reactor_type_);
  add_child(doc,reactor_child,"handlers",this->no_handlers_);

  root->appendChild(reactor_child);
 
  XMLFormatTarget *myFormTarget = new LocalFileFormatTarget(xml_file.c_str());
  DOMElement *serialize_doc=doc->getDocumentElement();
  temp=XMLString::transcode("utf-8");

  // The following lines are commented out because of compilation errors
  // Xerces 3.0 API should be used.
  //DOMWriter *writer=impl->createDOMWriter();
  //writer->setEncoding(temp);
  //writer->writeNode(myFormTarget,*serialize_doc);

  myFormTarget->flush();
  delete myFormTarget;
  XMLString::release(&temp);
  XMLPlatformUtils::Terminate();
 
  return true;

}

namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Component
//
//###############################################################################################################################################

Component::Component()
	: m_bIsInteractive( false )
{
}

Component::~Component()
{
	if ( m_project ) {
		m_project->finalizeObjects();
		finalize( m_project );
		m_project = NULL;
	}
}
bool Component::process_benchmarking(MON::Aspect &aspect,Model &model,XML_Writer &writer)
{
  BON::Project project=model->getProject();

  Atom_Set atom_set=model->getChildAtoms(aspect);
  Atom_Set::iterator iter;
  for(iter=atom_set.begin();iter!=atom_set.end();iter++)
  {
	if((*iter)->getName()=="Threads")
	{
	  BON::Attribute attr=(*iter)->getAttribute("number_of_threads");
	  writer.set_connections(attr->getIntegerValue());
	}		
	else if((*iter)->getName()=="RoundtripLatency")
	{
	  BON::Attribute data_attr=(*iter)->getAttribute("data_exchanges");
	  writer.set_data_exchanges(data_attr->getIntegerValue());
	  BON::Attribute data_string_attr=(*iter)->getAttribute("StringData");
	  writer.set_data(data_string_attr->getStringValue()); 

	  /*BON::Attribute data_iter=(*iter)->getAttribute("iterations");
	  writer.set_iterations(data_iter->getIntegerValue()); */
	}
	else if((*iter)->getName()=="Throughput")
	{
	  BON::Attribute data_attr=(*iter)->getAttribute("data_exchanges");
	  writer.set_data_exchanges(data_attr->getIntegerValue());
	 /* BON::Attribute data_iter=(*iter)->getAttribute("iterations");
	  writer.set_iterations(data_iter->getIntegerValue()); */
	  BON::Attribute data_string_attr=(*iter)->getAttribute("StringData");
	  writer.set_data(data_string_attr->getStringValue()); 
	
	}
  }
  Aspect_Set aspect_set = project->getProjectMeta().aspects();  
  MON::Aspect feat_asp,reactor_asp;
  for(Aspect_Set::iterator asp_it=aspect_set.begin();asp_it!=aspect_set.end();asp_it++)
  {
	if((*asp_it).name()=="Features")
	{
	  feat_asp =*asp_it;
	}
	else if((*asp_it).name()=="Reactor_Aspect")
	{
	  reactor_asp=*asp_it;
	}
  }
  Atom_Set feat_set=model->getChildAtoms(feat_asp);
  for(Atom_Set::iterator feat_it=feat_set.begin();feat_it!=feat_set.end();feat_it++)
  {
	
	if((*feat_it)->getName()=="Reactor_Type")
	{
	  BON::Attribute type_att=(*feat_it)->getAttribute("Reactor_Type_Options");
	  writer.set_reactor_type(type_att->getStringValue());
	}
  }
  Model_Set model_set=model->getChildModels(aspect);
  BON::Model reactor_model;
  for(Model_Set::iterator mod_it=model_set.begin();mod_it!=model_set.end();mod_it++)
  {
    if((*mod_it)->getObjectMeta().name()=="Reactor_Pattern")
	{
	  reactor_model=(*mod_it);
	}

  }
  Set_Set handle_set=reactor_model->getChildSets(reactor_asp);
  for(Set_Set::iterator set_it=handle_set.begin();set_it!=handle_set.end();set_it++)
  {
	if((*set_it)->getName()=="Handle_Set")
	{
	  int cnt=(*set_it)->getMembers(reactor_asp).size();
	  writer.set_no_handlers(cnt);
	}
  }
  writer.write_file("benchmark_inputs.xml");
  project->consoleMsg("Input file for benchmarking generated",msgtype_enum(1)); 
  return true;
}

bool Component::process_middleware(Project &project,XML_Writer &writer)
{
  BON::Folder root = project->getRootFolder( ); // Get the root folder
  Model_Set model_set = root->getChildModels();
  int len = model_set.size();
  if(len < 0)
  {
    
       return false;
    }
  for (Model_Set::iterator iter = model_set.begin();
			iter != model_set.end();
			++iter)
    {
	
        BON::Model model = (*iter);
        String model_name = model->getObjectMeta().name();
        if(model_name == "Middleware")
        {
            MON::Project this_project = project->getProjectMeta();
            Aspect_Set aspects = this_project.aspects();

            for (Aspect_Set::iterator iter_aspect = aspects.begin();
	            iter_aspect != aspects.end();
	            ++iter_aspect)
            {
                MON::Aspect aspect = (*iter_aspect);
                String aspect_name = aspect.name();
                if(aspect_name == "Benchmarking")
                {
				    process_benchmarking(aspect,model,writer);
                    break;
                }
            }
        }
      
    }
    return true;
}


// ====================================================
// This method is called after all the generic initialization is done
// This should be empty unless application-specific initialization is needed

void Component::initialize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This method is called before the whole BON2 project released and disposed
// This should be empty unless application-specific finalization is needed

void Component::finalize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This is the obsolete component interface
// This present implementation either tries to call InvokeEx, or does nothing except of a notification

void Component::invoke( Project& project, const std::set<FCO>& setModels, long lParam )
{
	#ifdef SUPPORT_OLD_INVOKE
		Object focus;
		invokeEx( project, focus, setModels, lParam );
	#else
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support the obsolete invoke mechanism!");
	#endif
}

// ====================================================
// This is the main component method for Interpereters and Plugins.
// May also be used in case of invokeable Add-Ons

void Component::invokeEx( Project& project, FCO& currentFCO, const std::set<FCO>& setSelectedFCOs, long lParam )
{
#ifdef GME_ADDON
	project->setAutoCommit( false);
#endif
	// ======================
	// Insert application specific code here
project->consoleMsg("Starting benchmarking interpreter...",msgtype_enum(1)); 
	BON::Folder root = project->getRootFolder( ); // Get the root folder
   
    if ( !root )
    {
        AfxMessageBox("Could not find RootFolder" );
        return;
    }
    XML_Writer writer;
 
	
    process_middleware(project,writer);
    return;
  

}

// ====================================================
// GME currently does not use this function
// You only need to implement it if other invokation mechanisms are used

void Component::objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam )
	{
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support objectInvokeEx method!");
	}

// ====================================================
// Implement application specific parameter-mechanism in these functions

Util::Variant Component::getParameter( const std::string& strName )
{
	// ======================
	// Insert application specific code here

	return Util::Variant();
}

void Component::setParameter( const std::string& strName, const Util::Variant& varValue )
{
	// ======================
	// Insert application specific code here
}

#ifdef GME_ADDON

// ====================================================
// If the component is an Add-On, then this method is called for every Global Event

void Component::globalEventPerformed( globalevent_enum event )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// If the component is an Add-On, then this method is called for every Object Event

void Component::objectEventPerformed( Object& object, unsigned long event, VARIANT v )
{
	// ======================
	// Insert application specific code here
}

#endif // GME_ADDON

}; // namespace BON