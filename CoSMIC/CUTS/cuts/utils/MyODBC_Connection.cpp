// $Id$

#include "ODBC_Connection.h"
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
  std::ostringstream str;

#if defined (_WIN32) || defined (WIN32)
  str << "Driver={MySQL ODBC 3.51 Driver};"
      << "Uid=" << username << ";"
      << "Pwd=" << password << ";"
#else
  str << "Dsn=myodbc3;"
      << "User=" << username << ";"
      << "Password=" << password << ";"
#endif  // defined _WIN32
      << "Database=cuts;"
      << "Server=" << server << ";"
      << "Port=" << port << ";"
      << "Option=3;" << std::ends;

  if (!ODBC_Connection::connect (str.str ().c_str ()))
  {
    throw ODBC_Connection_Exception (this->conn_);
  }
}
