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

  std::string AbstractKind::name () const
  {
	  return this->m_instance_->getName ();
  }

  std::string AbstractKind::meta_type () const
  {
	  switch (this->m_instance_->getStereotype())
	  {
	    case MON::OT_Null:
			return "Null";
		case MON::OT_Model:
		    return "Model";
		case MON::OT_Atom:
			return "Atom";
		case MON::OT_Reference:
			return "Reference";
		case MON::OT_Connection:
			return "Connection";
		case MON::OT_Set:
			return "Set";
		case MON::OT_Folder:
			return "Folder";
		case MON::OT_Aspect:
			return "Aspect";
		case MON::OT_Role:
			return "Role";
		case MON::OT_Attribute:
			return "Attribute";
		case MON::OT_Part:
			return "Part";
		default:
			return "";
	  }
  }

  std::string AbstractKind::kind () const
  {
		return this->m_instance_->getObjectMeta().name();
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
