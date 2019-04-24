
#ifndef BENCHMARK_TEST_H_
#define BENCHMARK_TEST_H_


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


#include<iostream>
#include<fstream>
#include<string>


#include "ace/SOCK_Stream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "ace/Svc_Handler.h"

#include "ace/Profile_Timer.h"
#include "ace/SOCK_Connector.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Acceptor.h"
#include "ace/Connector.h"
#include "ace/Reactor.h"
#include "ace/WFMO_Reactor.h"
#include "ace/Select_Reactor.h"
#include "ace/Auto_Ptr.h"

typedef std::string String;

using namespace xercesc;
class XML_Reader
{
public:
  bool read_file(String);
  int get_connections()
  {
	return this->no_connections_;
  }
  String get_data()
  {
	return this->data_;
  }
  String get_reactor_type()
  {
	return this->reactor_type_;
  }
  int get_data_exchanges()
  {
	return this->no_data_exchanges_;
  }
  int get_no_handlers()
  {
	return this->no_handlers_;
  }
private:
  String reactor_type_;
  String data_;
  int no_data_exchanges_;
  int no_handlers_;
  int no_connections_;
};

class Read_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_SYNCH>
{
  // = TITLE
  //   Simple class for reading in the data
public:
  static void set_connections (int connections)
  {
	connections_=connections;
  };

  virtual int open (void *);
  /// The Svc_Handler callbacks.
  virtual int handle_input (ACE_HANDLE h);
  virtual int handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask);


private:
  static int connections_;
  // How many connections are we waiting for.
};

class Write_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_SYNCH>
{
  // = TITLE
  //   This Svc_Handler simply connects to a server and sends some
  //   output to it.  Its purpose is to feed the test.
public:
  virtual int open (void *);
  virtual int send_data ();
};



#endif /*BENCHMARK_TEST_H_*/