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
    kindname_ (kindname)
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
      //this->bon_project_->consoleMsg ("Test", MSG_INFO);		
      std::set<BON::Object> bon_instances 
        = this->bon_project_->findByKind (this->kindname_);

      //for_each (bon_instances.begin (), 
      //  bon_instances.end (), 
      //  print<BON::Object> (this->bon_project_));

     // this->bon_project_->consoleMsg ("\n", MSG_INFO);

      // Insert the instances into the KindMap
      for_each (bon_instances.begin (), 
        bon_instances.end (), 
        insertKindInstance <BON::Object> (this));

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