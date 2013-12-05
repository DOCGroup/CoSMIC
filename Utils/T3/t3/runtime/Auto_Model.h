#ifndef _T3_AUTO_MODEL_H_
#define _T3_AUTO_MODEL_H_

#include "Runtime_Engine.h"
#include "Auto_Model_Impl.h"

namespace T3
{
class T3_RUNTIME_Export Auto_Model
{
public:
  Auto_Model (void);

  Auto_Model (const GAME::Mga::Object_in model);

  Auto_Model (const Auto_Model & copy);

  ~Auto_Model (void);

  const Auto_Model & operator = (const Auto_Model & rhs);

  void attach (const GAME::Mga::Object_in obj);

  GAME::Mga::Object model (void);

  const GAME::Mga::Object model (void) const;

  GAME::Mga::Object create_element (const std::string & type);

  bool create_unique_reference (const std::string & symbol,
                                const std::string & type);

  template <typename Cond>
  GAME::Mga::Object create_element_if_not (const std::string & type, Cond cond)
  {
    GAME::Mga::Object object =
      T3_RUNTIME_ENGINE->create_element_if_not (this->impl_->model (),
                                                type,
                                                cond);

    this->impl_->handle_new_object (object);

    return object;
  }

private:
  Auto_Model_Impl * impl_;
};

}

#include "Auto_Model.inl"

#endif  // !defined _T3_AUTO_MODEL_T_H_
