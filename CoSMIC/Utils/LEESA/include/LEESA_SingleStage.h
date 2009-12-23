#ifndef __LEESA_SINGLE_STAGE_H_
#define __LEESA_SINGLE_STAGE_H_

#ifndef DOMAIN_NAMESPACE
#error "Please #define DOMAIN_NAMESPACE"
#endif

#include "Kind_Traits.h"
#include "LEESA_Concepts.h"

#include <boost/foreach.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>
#include <vector>

namespace LEESA {

namespace SingleStage {

template <class Kind>
struct KindLit : public ContainerTraits<Kind>::Container
{
  typedef typename ContainerTraits<Kind>::Container super;

  KindLit () {}

  KindLit (const Kind & k) 
  {
    this->push_back(k);
  }

  KindLit (const KindLit & k) : super(k) {}
 
  using super::push_back;
  void push_back(KindLit const & k)
  {
    this->insert(this->end(), k.begin(), k.end());
  }

  void push_back(super const & in)
  {
    this->insert(this->end(), in.begin(), in.end());
  }

#ifdef LEESA_FOR_UDM

  KindLit (Udm::ParentAttr<Kind> const & c) 
  {
    this->push_back(c);
  }

  void push_back(Udm::ParentAttr<Kind> const & c) 
  {
    this->push_back(c);
  }

  KindLit(Udm::ChildrenAttr<Kind> const & ca) 
  {
    this->push_back(ca);
  }

  void push_back(Udm::ChildrenAttr<Kind> const & ca) 
  {
    this->push_back(ca);
  }

#else 

  KindLit (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional const & o)
  {
    this->push_back(o);
  }

  void push_back (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional const & o)
  {
    if (o.present()) 
    {
      this->push_back(o.get());
    }
  }

#endif // LEESA_FOR_UDM

};

template <class T>
struct IsDomainVisitorBaseOf
{
  typedef IsDomainVisitorBaseOf type;
#ifndef LEESA_NO_VISITOR
  enum { value = boost::is_base_of<SchemaVisitor, T>::value };
#else
  enum { value = 0 };
#endif // LEESA_NO_VISITOR
};

template <class ParentKind, class ChildKind>
typename 
  boost::disable_if <IsDomainVisitorBaseOf<ChildKind>,
                     KindLit<ChildKind> >::type
operator >> (KindLit<ParentKind> const & k, ChildKind)
{
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<ParentKind, ChildKind>));
  KindLit<ChildKind> retval;
  BOOST_FOREACH(ParentKind parent, k)
  {
#ifdef LEESA_FOR_UDM
    retval.push_back(parent.template children_kind<ChildKind>());
#else
    retval.push_back(children_kind(parent, ChildKind()));
#endif // LEESA_FOR_UDM
  }
  return retval;
}

template <class Kind>
KindLit<Kind>
operator >> (KindLit<Kind> const & k, SchemaVisitor & v)
{
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<Kind>));
  BOOST_FOREACH(Kind kind, k)
  {
#ifdef LEESA_FOR_UDM
    kind.Accept(v);
#else
    kind.accept(v);
#endif // LEESA_FOR_UDM
  }
  return k;
}

} // namespace SingleStage
} // namespace LEESA



#endif // __LEESA_SINGLE_STAGE_H_

