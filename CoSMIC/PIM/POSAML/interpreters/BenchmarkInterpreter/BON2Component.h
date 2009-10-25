//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON2Component.h
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

#ifndef BON2Component_h
#define BON2Component_h

#include "BON.h"
#include "BONImpl.h"
#include <ComponentConfig.h>




#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMImplementationRegistry.hpp>
//#include <xercesc/dom/DOMBuilder.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMError.hpp>
#include <xercesc/dom/DOMLocator.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>


#include<iostream>
#include<fstream>
#include<string>


typedef std::string String;

XERCES_CPP_NAMESPACE_USE

class XML_Writer
{
public:
  bool write_file(const String &);  
  void set_iterations(int no_it)
  {
	no_iterations_=no_it; 
  }
  void set_connections(int no_con)
  {
	no_connections_=no_con;
  }
  void set_data(const String &data)
  {
	data_=data; 
  }
  void set_reactor_type(const String &r_type)
  {
	reactor_type_=r_type;
  }
  void set_data_exchanges(int data_ex)
  {
	no_data_exchanges_=data_ex;
  }
  void set_no_handlers(int no_han)
  {
	no_handlers_=no_han;
  }
 void add_child(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument *doc,DOMElement *root,const String &child,const String &data);
 void add_child(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument *doc,DOMElement *root,const String &child,int data);
private:
  int no_iterations_;
  String reactor_type_;
  String data_;
  int no_data_exchanges_;
  int no_handlers_;
  int no_connections_;
};



namespace BON
{
  typedef std::string String;
  typedef std::set<BON::Model> Model_Set;
  typedef std::set<std::string> String_Set;
  typedef std::set<MON::Aspect> Aspect_Set; 
  typedef std::set<BON::Atom> Atom_Set;
  typedef std::set<BON::Attribute> Attribute_Set;
  typedef std::set<BON::Set> Set_Set;
//###############################################################################################################################################
//
// 	C L A S S : BON::Component
//
//###############################################################################################################################################

class Component
{
	//==============================================================
	// IMPLEMENTOR SPECIFIC PART
	// Insert application specific members and method deifinitions here

	//==============================================================
	// BON2 SPECIFIC PART
	// Do not modify anything below

	// Member variables
	public :
		Project 	m_project;
		bool		m_bIsInteractive;

	public:
		Component();
		~Component();

	public:
		void initialize( Project& project );
		void finalize( Project& project );
		void invoke( Project& project, const std::set<FCO>& setModels, long lParam );
		void invokeEx( Project& project, FCO& currentFCO, const std::set<FCO>& setSelectedFCOs, long lParam );
		void objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam );
		Util::Variant getParameter( const std::string& strName );
		void setParameter( const std::string& strName, const Util::Variant& varValue );

	#ifdef GME_ADDON
		void globalEventPerformed( globalevent_enum event );
		void objectEventPerformed( Object& object, unsigned long event, VARIANT v );
	#endif
private:
  bool process_benchmarking(MON::Aspect &aspect,BON::Model &model,XML_Writer &writer);
  bool process_middleware(Project &project,XML_Writer &writer);
  
};

}; // namespace BON
#endif // Bon2Component_H