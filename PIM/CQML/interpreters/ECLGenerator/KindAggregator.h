#ifndef __KINDAGGREGATOR_H
#define __KINDAGGREGATOR_H

#include "Kinds.h"

namespace CQML 
{
  template<class T> 
  struct print : public std::unary_function<T, void>
  {
    // ctor
    print(BON::Project bon_project) 
      : bon_project_ (bon_project),
      count(0) 
    {

    }

    // overloaded function operator
    void operator() (T x) 
    { 
      this->bon_project_->consoleMsg (x->getName (), MSG_INFO);		
      this->count++;
    }

    BON::Project bon_project_;
    int count;
  };

  // T is the kind you want to aggregate
  template <class T>
  class KindAggregator
  {
  public:

    typedef std::map<std::string, T> KindMap;

    // ctor that takes a single kind
    KindAggregator (const BON::Project& project, std::string kindname);

    // ctor that takes a list of kinds and aggregates them collectively
    KindAggregator (const BON::Project& project, const std::list<std::string>& kindlist);

    // dtor
    ~KindAggregator (void);

    KindMap aggregate ();

    KindMap getKindMap ();

  private:

    template<class I> 
    struct insertKindInstances : public std::unary_function<I, void>
    {
      // ctor
      insertKindInstances (KindAggregator<T>* outer) 
        : outer_ (outer),
        count (0) 
      {

      }

      // overloaded function operator
      void operator() (I x) 
      { 
        std::set<BON::Object> bon_instances 
          = this->outer_->bon_project_->findByKind (x);

        // Insert the instances into the KindMap
        for_each (bon_instances.begin (), 
          bon_instances.end (), 
          insertKindInstance <BON::Object> (this->outer_));
        
        //this->bon_project_->consoleMsg (
        // x + std::string("Instances Found: "), MSG_INFO);		

        //for_each (bon_instances.begin (), 
        //  bon_instances.end (), 
        //  print<BON::Object> (this->bon_project_));

        // this->bon_project_->consoleMsg ("\n", MSG_INFO);
        this->count++;
      }

      KindAggregator<T>* outer_;

      int count;
    };


    /// Functor that takes a BON kind instance converts it to 
    /// a CQML::Kind instance and inserts it into the kind map
    template<class I> 
    struct insertKindInstance : public std::unary_function<I, void>
    {
      /// ctor
      insertKindInstance (KindAggregator<T>* outer) 
        : outer_ (outer),
        count (0) 
      {
      }

      // overloaded function operator
      void operator() (I x) 
      { 
        T kind_instance (x);

        //this->outer_->bon_project_->consoleMsg ("Ancestors: ", MSG_INFO);	
        //for_each (kind_instance.ancestors_.begin (), 
        //kind_instance.ancestors_.end (), 
        //print<BON::Object> (outer_->bon_project_));

        this->outer_->insert (x->getName(), kind_instance);

        this->count++;
      }

      KindAggregator<T>* outer_;

      int count;
    };

  private:
     void insert (std::string instance_name, T kind_instance);

	  // The GME project
    const BON::Project & bon_project_;

    // Concrete model kind list whose instances to collect
    std::list<std::string> kindlist_;

    KindMap m_kind_instances_;
  };
}

#include "KindAggregator.cpp"
#endif /* __KINDAGGREGATOR_H */
