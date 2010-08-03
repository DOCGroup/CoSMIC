/* -*- C++ -*- */

//=============================================================================
/**
 * @file      PICMLManager_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_IMPL_H_
#define _PICML_MANAGER_IMPL_H_

#include <set>
#include "game/be/Event_Handler_Impl.h"
#include "game/FCO.h"
#include "game/Connection.h"
#include "game/Project.h"

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

namespace GAME
{
// Forward decl.
class FCO;
}

/**
 * @class PICMLManager_Impl
 *
 * Raw COM implementation of the PICML manager add-on.
 */
class PICMLManager_Impl : public GAME::Event_Handler_Impl
{
public:
  /// Constructor.
  PICMLManager_Impl (void);

  /// Destructor.
  virtual ~PICMLManager_Impl (void);

  virtual int initialize (GAME::Project & project);

  virtual int handle_global_event (long global_event);

  virtual int handle_object_event (GAME::Object & obj, unsigned long mask);

  void set_implementation_folder (const std::string & name);
  void set_artifact_folder (const std::string & name);
  void reset_configuration (void);

private:
  int handle_AttributeMember (unsigned long eventmask, GAME::Object & obj);
  int handle_AttributeValue (unsigned long eventmask, GAME::Object & obj);
  int handle_ExternalDelegate (unsigned long eventmask, GAME::Object & obj);
  int handle_PublishConnector (unsigned long eventmask, GAME::Object & obj);
  int handle_DeploymentPlan (unsigned long eventmask, GAME::Object & obj);
  int handle_ComponentAssembly (unsigned long eventmask, GAME::Object & obj);
  int handle_ComponentPackage (unsigned long eventmask, GAME::Object & obj);

  int handle_MirrorPortInstance (unsigned long eventmask, GAME::Object & obj);
  int handle_ExtendedPortInstance (unsigned long eventmask, GAME::Object & obj);

  int handle_ComponentRef (unsigned long eventmask, GAME::Object & obj);

  int handle_ConnectorObject (unsigned long eventmask, GAME::Object & obj);
  int handle_Component (unsigned long eventmask, GAME::Object & obj);

  int handle_ComponentInstance (unsigned long eventmask, GAME::Object & obj);
  int handle_ConnectorInstance (unsigned long eventmask, GAME::Object & obj);

  int handle_ComponentFactoryInstance (unsigned long eventmask, GAME::Object & obj);
  int handle_Domain (unsigned long eventmask, GAME::Object & obj);
 
  int handle_MonolithicImplementation (unsigned long eventmask, GAME::Object & obj);
  int handle_ConnectorImplementation (unsigned long eventmask, GAME::Object & obj);
  int handle_ComponentImplementation (unsigned long eventmask, GAME::Object & obj);

  int handle_ComponentInstanceType (unsigned long eventmask, GAME::Object & obj);

  int handle_ImplementationArtifact (unsigned long eventmask, GAME::Object & obj);
  int handle_PackageConfiguration (unsigned long eventmask, GAME::Object & obj);
  int handle_NodeReference (unsigned long eventmask, GAME::Object & obj);
  int handle_CollocationGroup (unsigned long eventmask, GAME::Object & obj);
  
  int handle_ComplexTypeReference (unsigned long eventmask, GAME::Object & obj);

  int handle_Publish (unsigned long eventmask, GAME::Object & obj);
  int handle_Consume (unsigned long eventmask, GAME::Object & obj);

	void handle_UUID (unsigned long eventmask, GAME::FCO & fco);

  void generate_port_instances (GAME::Model inst, 
                                const GAME::Model & component);

  /**
   * Create a UUID for the FCO.
   *
   * @param[in]       fco         Target FCO.
   */
  void create_uuid (const GAME::FCO & fco);

  /**
   * Verify the UUID of an FCO.
   *
   * @param[in]       fco         Target FCO.
   */
  void verify_uuid (const GAME::FCO & fco);

  /// This verifies all UUID's in the project.
  void verify_all_uuids (void);

  void handle_pending (void);

  bool get_connector_type (const GAME::Model & inst, GAME::Model & conn);

  int handle_connector_porttype_connection (const GAME::Model & connector,
                                            const GAME::FCO & port,
                                            GAME::Connection & connection);


  void create_DataValue (GAME::Model & container, const GAME::FCO & member);

  /**
   * Get the UUID from a FCO object.
   *
   * @param[in]     fco       Source FCO
   * @param[out]    attr      Pointer to the UUID attribute.
   * @retval        true      The attribute was found.
   * @retval        false     The attribute was not found.
   */
  bool get_uuid_i (const GAME::FCO & fco, GAME::Attribute & attr);

  void set_property_type (GAME::Model & prop, const GAME::FCO & type);

  void verify_property_datatype (GAME::ConnectionPoint & attr,
                                 const GAME::FCO & attr_type);

  void verify_property_datatype_entry (GAME::ConnectionPoints::value_type & attr,
                                       const GAME::FCO & attr_type);

  /// The project is in import mode.
  int importing_;

  /// Collection of pending FCO's to validate.
  std::vector <GAME::FCO> pending_;

  /// Interface pointer to the hosting project.
  GAME::Project project_;

  /// PICML types with a UUID attribute.
  std::set <std::string> uuid_types_;

  typedef
    int (PICMLManager_Impl::*_member_function)
    (unsigned long, GAME::Object &);

  ACE_Hash_Map_Manager <std::string,
                        _member_function,
                        ACE_Null_Mutex> handlers_;

  /// Latest member of the collocation group.
  GAME::FCO cg_member_;

  std::string impl_folder_;

  std::string artifact_folder_;
};

#endif // _PICML_MANAGER_IMPL_H_
