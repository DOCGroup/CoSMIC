#ifndef _LIBRARY_REFERENCE_HANDLER_H
#define _LIBRARY_REFERENCE_HANDLER_H

#include "game/mga/component/Event_Handler_Impl.h"

/**
 * @class Library_Reference_Handler
 *
 * Handler that is responsible for creating references
 * to objects.
 */
class Library_Reference_Handler :
  public GAME::Mga::Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  Library_Reference_Handler (void);

  /// Destructor.
  virtual ~Library_Reference_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

#endif  // !defined  _LIBRARY_REFERENCE_HANDLER_H
