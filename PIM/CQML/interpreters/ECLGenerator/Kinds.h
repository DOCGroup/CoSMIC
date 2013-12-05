#ifndef __KINDS_H
#define __KINDS_H

#include "BON.h"

#include <map>
#include <set>
#include <list>
#include <string>

namespace CQML 
{
  struct AbstractKind
  {
    BON::Object m_instance_;

  public:
    // ctor
    AbstractKind (BON::Object & instance);

	std::string name () const;
	std::string meta_type () const;
	std::string kind () const;

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
