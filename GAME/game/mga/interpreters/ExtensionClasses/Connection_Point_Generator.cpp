// $Id$

#include "StdAfx.h"
#include "Connection_Point_Generator.h"
#include "Functors.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaAtom.h"

#include <fstream>

namespace GAME
{
namespace Mga
{

//
// Connection_Point_Generator
//
Connection_Point_Generator::
Connection_Point_Generator (FCO_in fco,
                            const std::string & classname,
                            std::ofstream & header,
                            std::ofstream & source)
: fco_ (fco),
  classname_ (classname),
  header_ (header),
  source_ (source)
{

}

//
// ~Connection_Point_Generator
//
Connection_Point_Generator::~Connection_Point_Generator (void)
{

}

//
// visit_Connection
//
void Connection_Point_Generator::visit_Connection (Connection_in c)
{
  FCO connector = c->dst () == this->fco_ ? c->src () : c->dst ();
  connector->accept (this);
}

//
// visit_Atom
//
void Connection_Point_Generator::visit_Atom (Atom_in connector)
{
  // Locate the source connection point method.
  std::vector <Connection> in_connections;
  connector->in_connections ("SourceToConnector", in_connections);

  Connection conn = in_connections.front ();
  std::string rolename = conn->attribute ("srcRolename")->string_value ();
  std::string connpt_type = conn->src ()->name ();

  // Write the source connection point method.
  this->generate_connection_point (rolename, connpt_type);

  // Locate the destination connection point.
  in_connections.clear ();
  connector->in_connections ("ConnectorToDestination", in_connections);

  conn = in_connections.front ();
  rolename = conn->attribute ("dstRolename")->string_value ();
  connpt_type = conn->dst ()->name ();

  // Write the destination connection point.
  this->generate_connection_point (rolename, connpt_type);
}

//
// generate_connection_point
//
void Connection_Point_Generator::
generate_connection_point (const std::string & rolename,
                           const std::string & pt_type)
{
  const std::string func_name = rolename + "_" + pt_type;

  // Write the connection point method.
  this->header_
    << std::endl
    << "/// Get the " << rolename << " " << pt_type << " connection point." << std::endl
    << pt_type << " " << func_name << " (void);";

  this->source_
    << function_header_t (func_name)
    << pt_type << " " << this->classname_ << "::"
    << func_name << " (void)"
    << "{"
    << "GAME::Mga::FCO target = this->connection_point (\"" << rolename << "\")->target ();"
    << "return " << pt_type << "::_narrow (target);"
    << "}";
}

}
}
