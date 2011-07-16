#ifndef NODEMAP_GENERATOR_H
#define NODEMAP_GENERATOR_H

#include "PICML/PICML.h"

#include "DeploymentPlan_Export.h"
#include "Utils/UDM/Abstract_Type_Dispatcher_T.h"

#include <iostream>
#include <fstream>
#include <cstdio>

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

  virtual void Visit_SimpleProperty (const PICML::SimpleProperty &);

private:
  /// Output path for the generated file.
  std::string output_path_;

  /// Target output file.
  std::ofstream out_;

  /// Current node reference name.
  std::string curr_node_ref_name_;

  /// Flag determine if a newline should be generated
  bool generate_newline_;
};

#endif