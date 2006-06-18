// $Id$

#include "ODBC_Connection.h"
#include "ace/String_Base.h"
#include <sstream>

//
// MyODBC_Connection
//
MyODBC_Connection::MyODBC_Connection (void)
{

}

//
// ~MyODBC_Connection
//
MyODBC_Connection::~MyODBC_Connection (void)
{

}

//
// connect
//
void MyODBC_Connection::connect (const char * username,
                                 const char * password,
                                 const char * server,
                                 int port)
  throw (ODBC_Connection_Exception)
{
  std::ostringstream connstr;

#if defined (_WIN32) || defined (WIN32)
  connstr << "Driver={MySQL ODBC 3.51 Driver};"
          << "Uid=" << username << ";"
          << "Pwd=" << password << ";"
#else
  connstr << "Dsn=myodbc3;"
          << "User=" << username << ";"
          << "Password=" << password << ";"
#endif  // defined _WIN32
          << "Database=cuts;"
          << "Server=" << server << ";"
          << "Port=" << port << ";"
          << "Option=3;" << std::ends;

  // Connect to the database.
  this->connect_i (connstr.str ().c_str ());
}
