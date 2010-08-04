#include "Nodemap_Generator.h"

#include "Utils/UDM/Position_Sort_T.h"

#include "boost/bind.hpp"

#include <algorithm>

//
// Nodemap_Generator
//
Nodemap_Generator::
Nodemap_Generator (const std::string & outputPath)
: outputPath_ (outputPath)
{

}

//
// ~Nodemap_Generator
//
Nodemap_Generator::~Nodemap_Generator (void)
{

}

//
// Visit_DeploymentPlan
//
void Nodemap_Generator::
Visit_DeploymentPlan (const PICML::DeploymentPlan & plan)
{
  // Construct the filename.
  std::ostringstream filename;
  filename << this->outputPath_ << "/" << plan.name () << ".nodemap";

  // Open the document for writing.
  this->out.open (filename.str ().c_str ());

  if (!this->out.is_open ())
    return;

  // Visit all the nodes in the deployment plan.
  std::vector <PICML::NodeReference> nodes = plan.NodeReference_children ();
  std::for_each (nodes.begin (),
                 nodes.end (),
                 boost::bind (&PICML::NodeReference::Accept,
                              _1,
                              boost::ref (*this)));

  // Close the output file.
  this->out.close ();
}


//
// Visit_NodeReference
//
void Nodemap_Generator::
Visit_NodeReference (const PICML::NodeReference & noderef)
{
  this->curr_node_ref_name_ = noderef.name ();

  std::set <PICML::PropertyMapping> mapping = noderef.dstPropertyMapping ();
  std::for_each (mapping.begin (),
                 mapping.end (),
                 boost::bind (&PICML::PropertyMapping::Accept,
                              _1,
                              boost::ref (*this)));
}


//
// Visit_PropertyMapping
//
void Nodemap_Generator::
Visit_PropertyMapping (const PICML::PropertyMapping & pmapping)
{
  PICML::Property prop = pmapping.dstPropertyMapping_end ();
  prop.Accept (*this);
}


//
// Visit_Property
//
void Nodemap_Generator::
Visit_Property (const PICML::Property & prop)
{
  const std::string name (prop.name ());

  if (name != "StringIOR")
    return;

  // Since this is a simple type, we only need to get the
  // first element in the collection.
  std::vector <PICML::DataValue> values = prop.DataValue_kind_children ();

  if (values.empty ())
    return;

  values.front ().Accept (*this);
}

//
// Visit_DataValue
//
void Nodemap_Generator::
Visit_DataValue (const PICML::DataValue & dv)
{
  this->out << this->curr_node_ref_name_ << "\t\t\t" << dv.Value () << std::endl;
}
