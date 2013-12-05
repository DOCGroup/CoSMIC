#ifndef _LAYOUT_MANAGER_H_
#define _LAYOUT_MANAGER_H_

#include "t3/runtime/Event_Listener.h"
#include <stack>
#include <vector>
#include <set>

/**
 * @class Layout_Manager
 *
 * An event listener that controls the layout of PICML objects.
 */
class Layout_Manager : public T3_Event_Listener
{
public:
  /// Default constructor.
  Layout_Manager (void);

  /// Destructor.
  virtual ~Layout_Manager (void);

  /**
   * We are starting a new model. This will save the current
   * state of the event handler.
   */
  virtual void handle_open_model (GAME::Mga::Object_in obj);

  /**
   * Handle the closing of a model. When this method is invoked,
   * we can correctly arrange the elements in the model.
   */
  virtual void handle_close_model (GAME::Mga::Object_in obj);

  virtual void handle_new_object (GAME::Mga::Object_in obj);

private:
  void arrange_objects (bool vertical);

  typedef std::vector <GAME::Mga::Object> object_list;

  object_list * current_;

  std::stack < object_list * > stack_;

  static std::set <std::string> horizontal_models_;

  static std::set <std::string> vertical_models_;
};

#endif  // !defined _LAYOUT_MANAGER_H_
