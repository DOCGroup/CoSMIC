#ifndef __KINDAGGREGATOR_CPP
#define __KINDAGGREGATOR_CPP

#include "KindAggregator.h"
#include <functional>

namespace CQML
{
  template <class T>
  KindAggregator<T>::KindAggregator(const BON::Project& project,
    std::string kindname)
    : bon_project_ (project),
      kindlist_ (1, kindname)
  {
  }

  // ctor that takes a list of kinds and aggregates them collectively
  template <class T>
  KindAggregator<T>::KindAggregator (const BON::Project& project, 
    const std::list<std::string>& kindlist)
    : bon_project_ (project),
    kindlist_ (kindlist)
  {
  }

  template <class T>
  KindAggregator<T>::~KindAggregator(void)
  {
  }

  template <class T>
  void 
    KindAggregator<T>::insert (std::string instance_name, T kind_instance)
  {
    m_kind_instances_.insert (
      std::make_pair (instance_name, kind_instance));
  }


  template <class T>
  typename KindAggregator<T>::KindMap 
    KindAggregator<T>::aggregate()
  {
    try
    {
      for_each (this->kindlist_.begin (),
        this->kindlist_.end (),
        insertKindInstances <std::string> (this));
    } 
    catch (MON::Exception& ex)
    {
      this->bon_project_->consoleMsg (
        /*this->kindname_+std::string(" kind does not exist in this model.")+*/
        ex.getErrorMessage(), MSG_ERROR);		
    } 
    catch (...)
    {
      this->bon_project_->consoleMsg ("Unknown exception.", MSG_ERROR);

    }

    return this->m_kind_instances_;
  }

  template <class T>
  typename KindAggregator<T>::KindMap 
    KindAggregator<T>::getKindMap ()
  {
    return this->m_kind_instances_;
  }

}

#endif /* __KINDAGGREGATOR_CPP */