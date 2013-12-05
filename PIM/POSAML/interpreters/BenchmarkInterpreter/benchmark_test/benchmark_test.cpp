#include "benchmark_test.h"
using namespace xercesc;


void create_reactor(String reactor_type)
{
  ACE_Reactor_Impl *impl = 0;
  if(reactor_type=="wfmo")
	ACE_NEW (impl,
		   ACE_WFMO_Reactor);
  else if(reactor_type=="select_st"||reactor_type=="select_mt")
	ACE_NEW (impl,
			  ACE_Select_Reactor);
  ACE_Reactor *reactor = 0;
  ACE_NEW (reactor,
           ACE_Reactor (impl));
  ACE_Reactor::instance (reactor);
}
static const char *output_file="benchmark_output.txt";
//XERCES_CPP_NAMESPACE_USE

int Read_Handler::connections_=0;
String data;
String reactor_type;
int data_exchanges;
int connections; 
int handlers;

bool XML_Reader::read_file(String file_name)
{
  bool success=true;
  /// initialize the XML library.
  XMLPlatformUtils::Initialize();
  /// create new parser instance.
  XercesDOMParser *parser = new XercesDOMParser;
  if (parser)
  {
    parser->setValidationScheme(XercesDOMParser::Val_Auto);
    parser->setDoNamespaces(false);
    parser->setDoSchema(false);
    parser->setCreateEntityReferenceNodes(false);
    try
    {
      parser->parse(file_name.c_str());
    }
    catch (...)
    {
      std::cerr << "An exception while parsing ";
	  success=false;
    }
    if (success)
	{
	  /// Parse document	 
	  DOMNode *doc_ptr = parser->getDocument();
	  DOMNode *root_node=doc_ptr->getFirstChild(); 
	  DOMNodeList *child_nodes=root_node->getChildNodes();
	  DOMNode *child;
	  char *temp1;
	  char *temp2;
	  for(int i=0;i<child_nodes->getLength();i++)
	  {
		child = child_nodes->item(i);
		String temp("data");
		temp1=XMLString::transcode(child->getNodeName());
		temp2=XMLString::transcode(child->getTextContent());
		if(!temp.compare(temp1))
		  this->data_ = temp2;
		temp="connections";
		if(!temp.compare(temp1))
  		  this->no_connections_ = atoi(temp2);
		temp="data_exchanges";
		if(!temp.compare(temp1))
  		  this->no_data_exchanges_ = atoi(temp2);
		temp="reactor_inputs";
		if(!temp.compare(temp1))
		{
		  DOMNode *reactor_type=child->getFirstChild();
		  temp1=XMLString::transcode(reactor_type->getTextContent());
		  this->reactor_type_ = temp1;
		  DOMNode *handlers=reactor_type->getNextSibling();
		  temp1=XMLString::transcode(handlers->getTextContent());
		  this->no_handlers_ = atoi(temp1);
		  
		}

	  }
	  XMLString::release(&temp1);
	  XMLString::release(&temp2); 
	  doc_ptr->release(); 
	} 	
  }
   
  XMLPlatformUtils::Terminate();
  return success;
}


// Initialize the Svc_Handler
int
Read_Handler::open (void *)
{
  reactor ()->register_handler (this, READ_MASK);
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%t) created svc_handler for handle %d\n"),
              get_handle ()));
  return 0;
}

int
Read_Handler::handle_input (ACE_HANDLE handle)
{
  //ACE_UNUSED_ARG (handle);
  do
  {
  }while(&handle==0);

  char buf[BUFSIZ];
  while (1)
    {
	  ///non-blocking
	  this->peer ().enable (ACE_NONBLOCK);
      ssize_t result = this->peer ().recv (buf, sizeof (buf) - 1);
      if (result < 0)
        {
          if (errno == EWOULDBLOCK)
            return 0;
          else
            {
			  /// close handle      
			  return -1;
            }
        }
      else if(result==0)// result == 0
        {
          // This will cause handle_close to get called.
          return -1;
        }
    }
 return 0;
}


int
Read_Handler::handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask)
{
  do
  {
  }while(&handle==0||&close_mask==0);
  //ACE_UNUSED_ARG (handle);
  //ACE_UNUSED_ARG (close_mask);

  // Reduce count.
  connections_--;

  // If no connections are open.
  if (connections_ == 0)
    ACE_Reactor::instance ()->end_reactor_event_loop ();

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%t) Read_Handler::handle_close closing down\n")));

  // Shutdown
  this->destroy ();
  return 0;
}

int
Write_Handler::open (void *)
{
  return 0;
}

int
Write_Handler::send_data ()
{
  int send_size = data.size(); 
  this->peer ().send_n (data.c_str(),
                            send_size);
  return 0;
}


typedef ACE_Connector<Write_Handler, ACE_SOCK_CONNECTOR> CONNECTOR;
typedef ACE_Acceptor<Read_Handler, ACE_SOCK_ACCEPTOR> ACCEPTOR;

void *
client (void * arg)
{

  ACE_INET_Addr *connection_addr =
    reinterpret_cast<ACE_INET_Addr *> (arg);
  CONNECTOR connector;
  int i;

  // Automagic memory cleanup.
  Write_Handler **temp_writers;
  ACE_NEW_RETURN (temp_writers,
                  Write_Handler *[connections],
                  0);
  ACE_Auto_Basic_Array_Ptr <Write_Handler *> writers (temp_writers);

  ACE_TCHAR *temp_failed;
  ACE_NEW_RETURN (temp_failed,
                  ACE_TCHAR[connections],
                  0);
  ACE_Auto_Basic_Array_Ptr <ACE_TCHAR> failed_svc_handlers (temp_failed);

  // Automagic memory cleanup.
  ACE_INET_Addr *temp_addresses;
  ACE_NEW_RETURN (temp_addresses,
                  ACE_INET_Addr [connections],
                  0);
  ACE_Auto_Array_Ptr <ACE_INET_Addr> addresses (temp_addresses);

  // Initialize array.
  for (i = 0; i < connections; i++)
    {
      writers[i] = 0;
      addresses[i] = *connection_addr;
    }

  // Connection all <connections> svc_handlers
  int result = connector.connect_n (connections,
                                    writers.get (),
                                    addresses.get (),
                                    failed_svc_handlers.get ());
  if (result == -1)
    {
      // Print out the connections that failed...
      for (i = 0; i < connections; i++)
        if (failed_svc_handlers.get ()[i])
          {
            ACE_INET_Addr failed_addr = addresses.get()[i];
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("(%t) connection failed to %s, %d\n"),
                        failed_addr.get_host_name (),
                        failed_addr.get_port_number ()));
          }
      return 0;
    }

  // If no connections failed (result == 0) then there should be valid
  // ACE_Svc_handler pointers in each writers[] position.  Iterate to
  // send data
  for (int j = 0; j < data_exchanges; j++)
    for (i = 0; i < connections; i++)
      writers[i]->send_data ();
  // Cleanup
  for (i = 0; i < connections; i++)
    writers[i]->destroy ();
  return 0;
}

void
print_results (ACE_Profile_Timer::ACE_Elapsed_Time &et)
{
  std::ofstream out_f(output_file,ios::app);
  out_f<<"Reactor_Performance Test statistics:"<<std::endl;
  out_f<<"Reactor Type:"<<reactor_type<<std::endl;
  out_f<<"Connections:"<<connections<<std::endl;
  out_f<<"Elapsed Time"<<std::endl;
  out_f<<et.real_time<<" secs"<<std::endl;
  out_f.close();
}


int main(int argc, char *argv[])
{
  XML_Reader xml_reader;
  xml_reader.read_file("benchmark_inputs.xml"); 
  reactor_type=xml_reader.get_reactor_type(); 
  data=xml_reader.get_data(); 
  data_exchanges=xml_reader.get_data_exchanges(); 
  connections=xml_reader.get_connections(); 

  create_reactor(reactor_type);

  // Manage memory automagically.

 auto_ptr<ACE_Reactor> reactor (ACE_Reactor::instance ());
 auto_ptr<ACE_Reactor_Impl> impl;

  // If we are using other that the default implementation, we must
  // clean up.
  if (reactor_type=="wfmo"||reactor_type=="select_st")
    {
	 //auto_ptr<ACE_Reactor_Impl> auto_impl (ACE_Reactor::instance ()->implementation ());
     //impl = auto_impl;
    }
	Read_Handler::set_connections(connections);  
  // Acceptor
  ACCEPTOR acceptor;
  ACE_INET_Addr server_addr;
  
  // Bind acceptor to any port and then find out what the port was.
  if (acceptor.open (ACE_sap_any_cast (const ACE_INET_Addr &)) == -1
      || acceptor.acceptor ().get_local_addr (server_addr) == -1)
  {
	std::cout<<"Error with acceptor!"<<std::endl;
  }
  std::cout<< "starting server at port: "<<server_addr.get_port_number ();

  ACE_INET_Addr connection_addr (server_addr.get_port_number (),
                                 ACE_DEFAULT_SERVER_HOST);


  /// Spawn client thread
  if (ACE_Thread_Manager::instance ()->spawn
      (ACE_THR_FUNC (client),
       (void *) &connection_addr,
       THR_NEW_LWP | THR_DETACHED) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("(%t) %p\n"),
                ACE_TEXT ("thread create failed")));

  ACE_Time_Value run_limit (data_exchanges/ 10);
  ACE_Profile_Timer timer;
  timer.start ();
  const int status =
    ACE_Reactor::instance ()->run_reactor_event_loop (run_limit);
  timer.stop ();
  ACE_Profile_Timer::ACE_Elapsed_Time et;
  timer.elapsed_time (et);

  // Print results
  print_results (et);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%t) waiting for the client thread...\n")));

  ACE_Thread_Manager::instance ()->wait ();
  std::cout<<"Client done!"<<std::endl;
  return status;
}
