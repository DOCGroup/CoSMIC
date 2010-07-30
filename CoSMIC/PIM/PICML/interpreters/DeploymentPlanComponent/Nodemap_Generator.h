#ifndef NODEMAP_GENERATOR_H
#define NODEMAP_GENERATOR_H

#include "PICML/PICML.h"

#include "DeploymentPlan_Export.h"

/**
 * @class Nodemap_Generator
 */
class Nodemap_Generator : 
  public PICML::Visitor
{
  public:
  /**
   * Initializing constructor.
   */
  Nodemap_Generator (const std::string & outputPath);

  /// Destructor.
  virtual ~Nodemap_Generator (void);

  virtual void Visit_DeploymentPlan (const PICML::DeploymentPlan &);
  
  virtual void Visit_NodeReference (const PICML::NodeReference &);
  
  virtual void Visit_PropertyMapping (const PICML::PropertyMapping &);
  
  virtual void Visit_Property (const PICML::Property & );

  virtual void Visit_DataValue (const PICML::DataValue & );

  private:

  std::string outputPath_;

  std::string curr_node_ref_name_;

  std::string curr_prop_name_;

  std::string nodemap_contents_;
};

#endif