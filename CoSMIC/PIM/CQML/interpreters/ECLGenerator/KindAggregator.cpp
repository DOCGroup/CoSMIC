#include "KindAggregator.h"
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
  }

  Kind::~Kind(void)
  {
  }

  template <class T>
  KindAggregator<T>::KindAggregator(const BON::Project& project,
    std::string& kindname)
    : bon_project_ (project),
    kindname_ (kindname)
  {
  }

  template <class T>
  KindAggregator<T>::~KindAggregator(void)
  {
  }

  template <class T>
  typename KindAggregator<T>::KindMap 
    KindAggregator<T>::collect()
  {
    this->bon_project_->findByKind(this->kindname_);
  }

  template <class T>
  typename KindAggregator<T>::KindMap 
    KindAggregator<T>::getKindMap ()
  {
    return this->m_components_;
  }

}