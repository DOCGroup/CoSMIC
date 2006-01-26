// $Id$

#include "ODBC_Connection.h"

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
bool MyODBC_Connection::connect (const char * username, 
																 const char * password, 
																 const char * server,
																 int port)
{
	ostrstream str;
#ifdef _WIN32
	str << "Driver={MySQL ODBC 3.51 Driver};" 
      << "Uid=" << username << ";"
			<< "Pwd=" << password << ";"
#else
	str << "Dsn=myodbc3;" 
			<< "User=" << username << ";"
			<< "Password=" << password << ";"
#endif  // defined _WIN32
			<< "Database=wlgbenchmark;"
			<< "Server=" << server << ";"
			<< "Port=" << port << ";"
			<< "Option=3;" << ends; 

	return ODBC_Connection::connect (str.str ());
}
