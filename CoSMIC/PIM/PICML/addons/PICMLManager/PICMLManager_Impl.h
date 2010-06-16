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

private:
  void handle_AttributeMember (unsigned long eventmask, GAME::Object & obj);
  void handle_AttributeValue (unsigned long eventmask, GAME::Object & obj);
  void handle_ExternalDelegate (unsigned long eventmask, GAME::Object & obj);
  void handle_PublishConnector (unsigned long eventmask, GAME::Object & obj);
  void handle_DeploymentPlan (unsigned long eventmask, GAME::Object & obj);
  void handle_ComponentAssembly (unsigned long eventmask, GAME::Object & obj);
  void handle_ComponentPackage (unsigned long eventmask, GAME::Object & obj);

  void handle_ComponentRef (unsigned long eventmask, GAME::Object & obj);

  void handle_ConnectorObject (unsigned long eventmask, GAME::Object & obj);
  void handle_Component (unsigned long eventmask, GAME::Object & obj);

  void handle_ComponentInstance (unsigned long eventmask, GAME::Object & obj);
  void handle_ConnectorInstance (unsigned long eventmask, GAME::Object & obj);

  void handle_ComponentFactoryInstance (unsigned long eventmask, GAME::Object & obj);
  void handle_Domain (unsigned long eventmask, GAME::Object & obj);
 
  void handle_MonolithicImplementation (unsigned long eventmask, GAME::Object & obj);
  void handle_ConnectorImplementation (unsigned long eventmask, GAME::Object & obj);
  void handle_ComponentImplementation (unsigned long eventmask, GAME::Object & obj);

  void handle_ComponentInstanceType (unsigned long eventmask, GAME::Object & obj);

  void handle_ImplementationArtifact (unsigned long eventmask, GAME::Object & obj);
  void handle_PackageConfiguration (unsigned long eventmask, GAME::Object & obj);
  void handle_NodeReference (unsigned long eventmask, GAME::Object & obj);
  void handle_CollocationGroup (unsigned long eventmask, GAME::Object & obj);
  
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

  /**
   * Get the UUID from a FCO object.
   *
   * @param[in]     fco       Source FCO
   * @param[out]    attr      Pointer to the UUID attribute.
   * @retval        true      The attribute was found.
   * @retval        false     The attribute was not found.
   */
  bool get_uuid_i (const GAME::FCO & fco,
                   GAME::Attribute & attr);

  static void set_property_datatype (GAME::Model & property,
                                     const GAME::FCO & type);

  static void verify_property_datatype (GAME::ConnectionPoint & attr,
                                        const GAME::FCO & attr_type);

  static void verify_property_datatype_entry (GAME::ConnectionPoints::value_type & attr,
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
    void (PICMLManager_Impl::*_member_function) (unsigned long,
                                            GAME::Object &);

  ACE_Hash_Map_Manager <std::string,
                        _member_function,
                        ACE_Null_Mutex> handlers_;

  /// Latest member of the collocation group.
  GAME::FCO cg_member_;
};

#endif // _PICML_MANAGER_IMPL_H_
