// -*- C++ -*-

//==============================================================================
/**
 *  @file        Global_Event_Handler.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_MGA_GLOBAL_EVENT_HANDLER_H_
#define _GAME_MGA_GLOBAL_EVENT_HANDLER_H_

#include "Event_Handler.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Global_Event_Handler
 *
 * INSERT CLASS DESCRIPTION HERE
 */
class GAME_MGA_COMPONENT_Export Global_Event_Handler :
  public Event_Handler
{
protected:
  /// Default constructor.
  Global_Event_Handler (unsigned long mask, bool destroy_on_close = true);

public:
  /// Destructor.
  virtual ~Global_Event_Handler (void);

  virtual int handle_project_open (void);
  virtual int handle_project_open_finished (void);
  virtual int handle_save_project (void);
  virtual int handle_project_close (void);

  virtual int handle_territory_create (void);
  virtual int handle_territory_destroy (void);

  virtual int handle_transaction_commit (void);
  virtual int handle_transaction_abort (void);

  virtual int handle_undo (void);
  virtual int handle_redo (void);

  virtual int handle_project_properties (void);
  virtual int handle_notification_ready (void);

  virtual int handle_xml_import_begin (void);
  virtual int handle_xml_import_end (void);

  virtual int handle_xml_import_fcos_begin (void);
  virtual int handle_xml_import_fcos_end (void);

  virtual int handle_xml_import_special_begin (void);
  virtual int handle_xml_import_special_end (void);

  virtual int handle_library_attach_begin (void);
  virtual int handle_library_attach_end (void);

protected:
  /// The project is importing models.
  bool is_importing_;
};

} // namespace GAME
} // namespace Mga

#if defined (__GAME_INLINE__)
#include "Global_Event_Handler.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_MGA_GLOBAL_EVENT_HANDLER_H_
