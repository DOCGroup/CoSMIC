
#ifndef BENCHMARK_XML_H_
#define BENCHMARK_XML_H_


#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMImplementationRegistry.hpp>
#include <xercesc/dom/DOMBuilder.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMError.hpp>
#include <xercesc/dom/DOMLocator.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/util/xmlstring.hpp>
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
private:
  int no_iterations_;
  String reactor_type_;
  String data_;
  int no_data_exchanges_;
  int no_handlers_;
  int no_connections_;
};
#endif /*BENCHMARK_XML_H_*/