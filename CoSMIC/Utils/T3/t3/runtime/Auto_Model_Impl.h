#ifndef _T3_AUTO_MODEL_IMPL_H_
#define _T3_AUTO_MODEL_IMPL_H_

#include "Runtime_export.h"
#include "game/Collection_T.h"
#include "game/Object.h"

namespace T3
{
class T3_RUNTIME_Export Auto_Model_Impl
{
public:
  Auto_Model_Impl (void);

  Auto_Model_Impl (const ::GAME::Object & model);

  ~Auto_Model_Impl (void);

  ::GAME::Object & model (void);

  const ::GAME::Object & model (void) const;

  void inc_refcount (void);

  void dec_refcount (void);

  void handle_new_object (const GAME::Object & obj);

  size_t refcount (void) const;

private:
  void store (const ::GAME::Object & model);

  void cleanup (void);

  ::GAME::Object model_;

  /// Collection of existing models.
  std::vector <::GAME::Object> existing_;

  size_t ref_count_;

  Auto_Model_Impl (const Auto_Model_Impl &);
  const Auto_Model_Impl & operator = (const Auto_Model_Impl &);
};

}

#include "Auto_Model_Impl.inl"

#endif  // !defined _T3_AUTO_MODEL_T_H_
