#include "Kinds.h"

#include <BONImpl.h>

namespace CQML
{
  AbstractKind::AbstractKind (BON::Object & instance)
    : m_instance_ (instance)
  {
  }

  AbstractKind::~AbstractKind(void)
  {
  }

  Kind::Kind (BON::Object & instance)
    : AbstractKind (instance)
  {
    BON::Object parent_instance = this->m_instance_;
    std::string parent_name;
    while ( (parent_instance = parent_instance->getParent () ) !=  BON::OT_Null)
    {
      parent_name = parent_instance->getName ();
      this->ancestors_.push_front (parent_instance);
    }
    
  }

  Kind::~Kind(void)
  {
  }
}
