// $Id$

#include "StdAfx.h"
#include "InConnection_Generator.h"
#include "Functors.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaAtom.h"

namespace GAME
{
namespace Mga
{

//
// InConnection_Generator
//
InConnection_Generator::
InConnection_Generator (const std::string & classname,
                     std::ofstream & header,
                     std::ofstream & source)
: classname_ (classname),
  header_ (header),
  source_ (source)
{

}

//
// ~InConnection_Generator
//
InConnection_Generator::~InConnection_Generator (void)
{

}

//
// visit_Connection
//
void InConnection_Generator::visit_Connection (Connection_in c)
{
  const std::string metaname = c->meta ()->name ();

  if (metaname == "SourceToConnector")
    c->dst ()->accept (this);
  else if (metaname == "ConnectorToDestination")
    c->src ()->accept (this);
}

//
// visit_Atom
//
void InConnection_Generator::visit_Atom (Atom_in a)
{
  const std::string metaname = a->meta ()->name ();

  if (metaname == "Connector")
  {
    // There should be only one association class. We need to visit
    // that only
    std::vector <Connection> assocation_classes;
    a->in_connections ("AssociationClass", assocation_classes);

    if (!assocation_classes.empty ())
    {
      // Determine the order of the connection. For some reason, the
      // MetaGME paradigm supports bi-directional connections for its
      // AssociationClass connection. So, we need to make sure we
      // visit the endpoint that is not this atom.
      Connection association = assocation_classes.front ();

      if (association->src ()->is_equal_to (a))
        association->dst ()->accept (this);
      else
        association->src ()->accept (this);
    }
  }
  else if (metaname == "Connection")
  {
    const std::string name = a->name ();
    const std::string method_name = "in_" + name + "_connections";

    // Declare the function.
    this->header_
      << std::endl
      << "size_t " << method_name << " (std::vector <" << name << "> & conns) const;";

    // Implement the function.
    this->source_
      << function_header_t (method_name)
      << "size_t " << this->classname_ << "::"
      << method_name << " (std::vector <" << name << "> & conns) const"
      << "{"
      << "return this->in_connections (conns);"
      << "}";
  }
}

}
}
