// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Assembly_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_ASSEMBLY_GENERATOR_H_
#define _CUTS_BE_ASSEMBLY_GENERATOR_H_

#include "BE_export.h"
#include "PICML/PICML.h"
#include <stack>

//=============================================================================
/**
 * @class BE_Assembly_Generator
 *
 * Replicates existing component assemblies as proxy assemblies. The
 * proxy assemblies allow developers to monitor the performance of
 * both real and emulated components.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Assembly_Generator :
  public PICML::Visitor
{
public:
  /// Default constructor
  CUTS_BE_Assembly_Generator (void);

  /// Destructor
  virtual ~CUTS_BE_Assembly_Generator (void);

protected:
  void Visit_RootFolder (
    const PICML::RootFolder & folder);

  void Visit_ComponentImplementations (
    const PICML::ComponentImplementations & folder);

  void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer & container);

  void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation & monoimpl);

  void Visit_ComponentAssembly (
    const PICML::ComponentAssembly & assembly);

  void Visit_Component (
    const PICML::Component & component);

  void Visit_OutEventPort (
    const PICML::OutEventPort & outevent);

  void Visit_InEventPort (
    const PICML::InEventPort & inevent);

  void Visit_emit (
    const PICML::emit & emit);

  void Visit_publish (
    const PICML::publish & publish);

  void Visit_PublishConnector (
    const PICML::PublishConnector & connector);

  void Visit_deliverTo (
    const PICML::deliverTo & deliverTo);

  void Visit_MonolithprimaryArtifact (
    const PICML::MonolithprimaryArtifact & primary);

  void Visit_ImplementationArtifact (
    const PICML::ImplementationArtifact & artifact);

  void Visit_ArtifactExecParameter (
    const PICML::ArtifactExecParameter & param);

  void Visit_Implements (
    const PICML::Implements & implements);

private:
  bool locate_proxy (const PICML::Component &, PICML::Component &);

  bool locate_proxy_type (const PICML::Component &, PICML::Component &);

  bool locate_executor_entry_point (const PICML::Component & component);

  bool create_attribute_property (const PICML::ReadonlyAttribute & attr,
                                  const Udm::Object & parent,
                                  PICML::Property & property);

  void generate_scoped_instance_name (const PICML::Component & component,
                                      std::string & name);

  /// Type definition for a queue of components.
  typedef std::set <PICML::Component> Component_Set;

  typedef std::stack <PICML::Port> Source_Port_Stack;

  /// Collection of components pending replication.
  Component_Set pending_components_;

  Source_Port_Stack previous_port_;

  PICML::ComponentImplementations target_folder_;

  PICML::ComponentImplementationContainer target_container_;

  PICML::ComponentAssembly target_assembly_;

  PICML::InEventPort target_inevent_;

  PICML::OutEventPort target_outevent_;

  typedef std::map <PICML::Component, PICML::Component> Proxy_Type_Map;

  Proxy_Type_Map proxy_type_map_;

  typedef std::map <std::string, PICML::Component> Proxy_Map;

  Proxy_Map proxy_map_;

  typedef std::map <std::string, PICML::PublishConnector> PublishConnector_Map;

  PublishConnector_Map connector_map_;

  std::string artifact_name_;

  std::string entry_point_;
};

#if defined (__CUTS_INLINE__)
#include "BE_Assembly_Generator.inl"
#endif

#endif
