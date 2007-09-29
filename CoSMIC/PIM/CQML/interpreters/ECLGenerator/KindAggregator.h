#ifndef __CQMLKINDAGGREGATOR_H
#define __CQMLKINDAGGREGATOR_H

#include "BON.h"
#include "MON.h"

#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>

namespace CQML 
{
  enum Entity
  {
    K_AbstractPort = 0,
    K_OutputPortBase,
    K_InputPortBase,
    K_AbstractAssembly,
    K_AbstractComponent,
    K_AbstractNode
  };

  struct AbstractKind
  {
    const BON::Object & m_instance_;

  public:
    // ctor
    AbstractKind (BON::Object & instance);

    // dtor
    ~AbstractKind (void);
  };

  struct Kind : public AbstractKind
  {
    std::list<BON::Object> ancestors_;

  public:
    // ctor
    Kind (BON::Object & instance);

    // dtor
    ~Kind (void);

  };

  typedef Kind AbstractAssembly;
  typedef Kind AbstractComponent;
  typedef Kind AbstractNode;

  typedef std::map<std::string, AbstractAssembly> AssemblyMap;
  typedef std::map<std::string, AbstractComponent> ComponentMap;
  typedef std::map<std::string, AbstractNode> NodeMap;

  template <class T>
  class KindAggregator
  {
  public:
    // ctor
    KindAggregator (const BON::Project& project, std::string& kindname);

    // dtor
    ~KindAggregator (void);

    typedef std::map<std::string, T> KindMap;

    KindMap collect ();

    KindMap getKindMap ();

  private:
    // The GME project
    const BON::Project & bon_project_;

    // Concrete model kind whose instances to collect
    std::string kindname_;

    KindMap m_kind_instances_;
  };
}

#endif /* __CQMLKINDAGGREGATOR_H */