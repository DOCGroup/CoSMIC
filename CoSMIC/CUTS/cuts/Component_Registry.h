#ifndef _CUTS_COMPONENT_REGISTRY_H_
#define _CUTS_COMPONENT_REGISTRY_H_

#include "cuts/Component_Registry_Node.h"
#include "ace/Condition_Thread_Mutex.h"
#include "ace/Message_Queue_T.h"
#include "ace/Unbounded_Set.h"
#include "ace/Synch_Traits.h"

#include <map>
#include <string>

// Forward decl.
struct CUTS_Component_Info;

// Forward decl.
class CUTS_Component_Registry_Handler;

// Forward decl.
class CUTS_Component_Registry_Node;

//=============================================================================
/**
 *
 */
//=============================================================================

typedef std::map <std::string,
                  CUTS_Component_Registry_Node *>
                  CUTS_Component_Registry_Map;


//=============================================================================
/**
 * @class CUTS_Component_Registry
 */
//=============================================================================

class CUTS_Export CUTS_Component_Registry
{
public:
  /// Default constructor.
  CUTS_Component_Registry (void);

  /// Destructor.
  virtual ~CUTS_Component_Registry (void);

  /**
   *
   */
  int open (void);

  /**
   * Close the component registry. This actually causes the
   * service thread to stop, but you can still register components.
   */
  int close (void);

  int is_open (void);

  /**
   *
   */
  int register_handler (CUTS_Component_Registry_Handler * handler);

  int unregister_handler (CUTS_Component_Registry_Handler * handler);

  virtual size_t register_component (const char * uuid);

  virtual void unregister_component (const char * uuid);

  virtual bool is_registered (const char * uuid);

  virtual size_t get_registration (const char * uuid,
                                   bool auto_register = true);

  size_t registry_size (void);

  ACE_RW_Thread_Mutex & lock (void);

  std::string get_component_by_id (long regid) const;

protected:
  CUTS_Component_Registry_Node * get_node (const char * uuid);

  CUTS_Component_Registry_Map registry_;

  ACE_RW_Thread_Mutex lock_;

  typedef ACE_Message_Queue_Ex <
          CUTS_Component_Registry_Node,
          ACE_MT_SYNCH> CUTS_Message_Queue;

  /// Queue that contains the component information.
  CUTS_Message_Queue info_queue_;

private:
  ///
  static ACE_THR_FUNC_RETURN thr_svc (void * param);

  /// Open state for the registry.
  int open_;

  /// Group id of the service thread.
  int grp_id_;

  /// Type definition for a collection of registered handlers.
  typedef ACE_Unbounded_Set <
          CUTS_Component_Registry_Handler *>
          CUTS_Handler_Set;

  /// Collection of registered handlers.
  CUTS_Handler_Set handlers_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Component_Registry.inl"
#endif

#endif  // !defined _CUTS_COMPONENT_REGISTRY_H_
