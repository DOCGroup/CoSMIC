#ifndef _PICML_DEPLOYMENT_PLAN_VISITOR_H_
#define _PICML_DEPLOYMENT_PLAN_VISITOR_H_

#include <memory>
#include <stack>
#include <map>
#include <set>

#include "PICML/PICML.h"
#include "PICML/Visitor.h"
#include "Deployment_Handler.h"

#include "game/xml/Document.h"

// Forward decl.
class Configuration;

namespace PICML
{
namespace Deployment
{

/**
 * @class Deployment_Plan_Visitor
 */
class Deployment_Plan_Visitor :
  public Visitor,
  public Deployment_Handler
{
public:
  /**
   * Initializing constructor.
   */
  Deployment_Plan_Visitor (const Configuration & config);

  /// Destructor.
  virtual ~Deployment_Plan_Visitor (void);

  virtual void visit_RootFolder (PICML::RootFolder_in);

  virtual void visit_DeploymentPlans (PICML::DeploymentPlans_in);

  virtual void visit_DeploymentPlan (PICML::DeploymentPlan_in);

  virtual void visit_NodeReference (PICML::NodeReference_in);

  virtual void visit_InstanceMapping (PICML::InstanceMapping_in);

  virtual void visit_CollocationGroup (PICML::CollocationGroup_in);

  virtual void visit_CollocationGroupProperty (PICML::CollocationGroupProperty_in);

  virtual void visit_ComponentInstanceRef (PICML::ComponentInstanceRef_in);

  virtual void visit_ComponentInstance (PICML::ComponentInstance_in);

  virtual void visit_ComponentInstanceType (PICML::ComponentInstanceType_in);

  virtual void visit_MonolithicImplementation (PICML::MonolithicImplementation_in);

  virtual void visit_MonolithprimaryArtifact (PICML::MonolithprimaryArtifact_in mpa);

  virtual void visit_ImplementationArtifactReference (PICML::ImplementationArtifactReference_in );

  virtual void visit_ImplementationArtifact (PICML::ImplementationArtifact_in );

  virtual void visit_MonolithExecParameter (PICML::MonolithExecParameter_in );

  virtual void visit_ArtifactDependsOn (PICML::ArtifactDependsOn_in );

  virtual void visit_SimpleProperty (PICML::SimpleProperty_in );

  virtual void visit_ComplexProperty (PICML::ComplexProperty_in );

  virtual void visit_ArtifactExecParameter (PICML::ArtifactExecParameter_in );

  virtual void visit_ComponentImplementationArtifact (PICML::ComponentImplementationArtifact_in );

  virtual void visit_ComponentServantArtifact (PICML::ComponentServantArtifact_in );

  virtual void visit_ConfigProperty (PICML::ConfigProperty_in );

  virtual void visit_AssemblyConfigProperty (PICML::AssemblyConfigProperty_in);

  virtual void visit_ComponentAssemblyReference (PICML::ComponentAssemblyReference_in );

  virtual void visit_ComponentAssembly (PICML::ComponentAssembly_in );

  virtual void visit_AttributeInstance (PICML::AttributeInstance_in );

  virtual void visit_AttributeValue (PICML::AttributeValue_in );

  virtual void visit_ConnectorImplementationType (PICML::ConnectorImplementationType_in);

  virtual void visit_ConnectorImplementation (PICML::ConnectorImplementation_in);

  virtual void deploy_connector_fragment (
    PICML::ConnectorInstance_in connector, 
    PICML::ComponentInstance_in component);

private:
  void visit_MonolithicImplementationBase (PICML::MonolithicImplementationBase_in );

  void begin_document (const std::string & uuid, const std::string & label);
  void write_document (const std::string & filename);

  void reset_state (void);

  void write_artifact_execParameter (const std::string & name, const std::string & value);

  GAME::Xml::LS_Document document_;

  /// The configuration for the generator.
  const Configuration & config_;

  /// The current node for the iteration.
  PICML::NodeReference current_node_;

  /// Collection of instances in the current deployment.
  std::map <PICML::ComponentInstance, GAME::Xml::Fragment> insts_;

  std::map <std::string, GAME::Xml::Fragment> connector_insts_;

  std::set <GAME::Xml::Fragment> locality_insts_;

  /// Collection of implementation in the current deployment.
  std::map <PICML::Implemenation, GAME::Xml::Fragment> impls_;

  /// Collection of artifacts in the current deployment.
  std::map <PICML::ImplementationArtifact, GAME::Xml::Fragment> artifacts_;

  /// Collection of connections in the current deployment.
  std::vector <GAME::Xml::Fragment> conns_;

  std::map <PICML::ComponentInstance, PICML::CollocationGroup> mappings_;

  /// Collection of plan localities in the current deployment.
  std::map <PICML::CollocationGroup, GAME::Xml::Fragment> locality_;

  GAME::Xml::Fragment curr_locality_;

  GAME::Xml::Fragment curr_instance_;

  GAME::Xml::Fragment curr_impl_;

  GAME::Xml::Fragment curr_artifact_;

  GAME::Xml::Fragment param_parent_;

  GAME::Xml::Fragment curr_param_;

  GAME::Xml::Fragment curr_value_;

  PICML::ComponentImplementationArtifact impl_artifact_;

  PICML::ComponentServantArtifact svnt_artifact_;

  PICML::CollocationGroup current_group_;

  std::string parameter_type_;
};

}
}

#endif /* FLATPLAN_VISITOR_H */

