#include "Deployment_Node_Visitor.h"

#include "Utils/UDM/Position_Sort_T.h"

#include "boost/bind.hpp"

#include <algorithm>

//
// Deployment_Node_Visitor
//
Deployment_Node_Visitor::
Deployment_Node_Visitor (const std::string & outputPath)
: outputPath_ (outputPath),
  nodemap_contents_ ("")
{
}


//
// ~Deployment_Node_Visitor
//
Deployment_Node_Visitor::
~Deployment_Node_Visitor (void)
{
}


//
// Visit_DeploymentPlan
//
void Deployment_Node_Visitor::
Visit_DeploymentPlan (const PICML::DeploymentPlan & plan)
{
  // Visit all the nodes in the deployment plan.  
  std::vector <PICML::NodeReference> nodes = plan.NodeReference_children ();
  
  std::for_each (nodes.begin (),
                 nodes.end (),
                 boost::bind (&PICML::NodeReference::Accept, 
                              _1, 
                              boost::ref (*this)));

  // Create the document
  this->outputPath_.append("/");
  this->outputPath_.append(plan.name ().operator std::string ().c_str ());
  this->outputPath_.append(".nodemap");

  FILE * nodemap = fopen (this->outputPath_.c_str(),"w");

  if (nodemap != NULL)
  {
    fputs (this->nodemap_contents_.c_str (), nodemap);
    fclose (nodemap);
  }
}


//
// Visit_NodeReference
//
void Deployment_Node_Visitor::
Visit_NodeReference (const PICML::NodeReference & noderef)
{
  this->curr_node_ref_name_ = noderef.name ();
  
  std::set <PICML::PropertyMapping> mapping = noderef.dstPropertyMapping () ;
  std::for_each (mapping.begin (),
                 mapping.end (),
                 boost::bind (&PICML::PropertyMapping::Accept,
                              _1,
                              boost::ref (*this)));
}


//
// Visit_PropertyMapping
//
void Deployment_Node_Visitor::
Visit_PropertyMapping (const PICML::PropertyMapping & pmapping)
{
	PICML::Property prop = pmapping.dstPropertyMapping_end ();
	PICML::Property (prop).Accept (*this);
}


//
// Visit_Property
//
void Deployment_Node_Visitor::
Visit_Property (const PICML::Property & prop)
{
  this->curr_prop_name_ = prop.name ();

  typedef UDM_Position_Sort_T <PICML::DataValue, PS_Top_To_Bottom> sorter_t;
  sorter_t sorter ("DataValueAspect", PS_Top_To_Bottom ());
  std::set <PICML::DataValue, sorter_t> sorted_values (sorter);
  sorted_values = prop.DataValue_kind_children_sorted (sorter);

  std::for_each (sorted_values.begin (),
                 sorted_values.end (),
                 boost::bind (&PICML::DataValue::Accept,
                              _1,
                              boost::ref (*this)));
}


//
// Visit_DataValue
//
void Deployment_Node_Visitor::
Visit_DataValue (const PICML::DataValue & dv)
{
  if (this->curr_prop_name_ == "StringIOR")
  {
	  if(!this->nodemap_contents_.empty ())
    {
      this->nodemap_contents_.append ("\n\n");
    }

    this->nodemap_contents_.append (this->curr_node_ref_name_);
    this->nodemap_contents_.append (" ");
    this->nodemap_contents_.append (dv.Value ());
  }
}