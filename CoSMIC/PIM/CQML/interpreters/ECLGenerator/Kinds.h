#ifndef __KINDS_H
#define __KINDS_H

#include "BON.h"

#include <map>
#include <set>
#include <list>
#include <string>

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

  typedef std::set<AbstractAssembly> AssemblySet;
  typedef std::set<AbstractComponent> ComponentSet;
  typedef std::set<AbstractNode> NodeSet;

  typedef std::map<std::string, AbstractAssembly> AssemblyMap;
  typedef std::map<std::string, AbstractComponent> ComponentMap;
  typedef std::map<std::string, AbstractNode> NodeMap;
}

#endif /* __KINDS_H */
