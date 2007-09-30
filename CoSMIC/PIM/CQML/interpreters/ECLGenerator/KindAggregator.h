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

    // ctor
    KindAggregator (const BON::Project& project, std::string kindname);

    // dtor
    ~KindAggregator (void);

    KindMap aggregate ();

    KindMap getKindMap ();

  private:

    template<class I> 
    struct insertKindInstance : public std::unary_function<I, void>
    {
      // ctor
      insertKindInstance (KindAggregator<T>* outer) 
        : outer_ (outer),
          count (0) 
      {

      }

      // overloaded function operator
      void operator() (I x) 
      { 
        T kind_instance (x);

        outer_->bon_project_->consoleMsg ("Ancestors: ", MSG_INFO);		
        
        for_each (kind_instance.ancestors_.begin (), 
        kind_instance.ancestors_.end (), 
        print<BON::Object> (outer_->bon_project_));

        outer_->insert (x->getName(), kind_instance);
        
        this->count++;
      }

      KindAggregator<T>* outer_;

      int count;
    };

    void insert (std::string instance_name, T kind_instance);

  private:
    // The GME project
    const BON::Project & bon_project_;

    // Concrete model kind whose instances to collect
    std::string kindname_;

    KindMap m_kind_instances_;
  };
}

#include "KindAggregator.cpp"
#endif /* __KINDAGGREGATOR_H */
