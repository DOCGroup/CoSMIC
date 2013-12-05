#ifndef _T3_AUTO_MODEL_IMPL_H_
#define _T3_AUTO_MODEL_IMPL_H_

#include "Runtime_export.h"

#include "game/mga/Collection_T.h"
#include "game/mga/Object.h"

namespace T3
{
/**
 * @class Auto_Model_Impl
 *
 * Implementation of the auto model proxy.
 */
class T3_RUNTIME_Export Auto_Model_Impl
{
public:
  /// Default constructor.
  Auto_Model_Impl (void);

  Auto_Model_Impl (const GAME::Mga::Object_in obj);

  /// Destructor.
  ~Auto_Model_Impl (void);

  GAME::Mga::Object model (void);

  const GAME::Mga::Object model (void) const;

  void inc_refcount (void);

  void dec_refcount (void);

  void handle_new_object (const GAME::Mga::Object_in obj);

  size_t refcount (void) const;

private:
  void store (const GAME::Mga::Object_in obj);

  void cleanup (void);

  GAME::Mga::Object model_;

  /// Collection of existing models.
  std::vector <GAME::Mga::Object> existing_;

  size_t ref_count_;

  Auto_Model_Impl (const Auto_Model_Impl &);
  const Auto_Model_Impl & operator = (const Auto_Model_Impl &);
};

}

#include "Auto_Model_Impl.inl"

#endif  // !defined _T3_AUTO_MODEL_T_H_
