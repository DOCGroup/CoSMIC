#ifndef NETQOS_REQUIREMENTS_ITERATOR
#define NETQOS_REQUIREMENTS_ITERATOR

#include "CQML/CQML.h"
#include "common.h"

namespace CQML
  {
  class NetQoSRequirementsIterator
  {
  public:
      NetQoSRequirementsIterator (NetQoSVisitor const &,
                                  NetQoSRequirements::iterator const &);
      NetQoSRequirementsIterator & operator ++ ();
      SharedNetQoS operator *() const;
      bool operator == (NetQoSRequirementsIterator const &) const;
      bool operator != (NetQoSRequirementsIterator const &) const;

  private:
      NetQoSVisitor const *nqv_;
      NetQoSRequirements::iterator current_;
  };


  } //namespace CQML

#include "NetQoSVisitor.h"

#endif // NETQOS_REQUIREMENTS_ITERATOR

