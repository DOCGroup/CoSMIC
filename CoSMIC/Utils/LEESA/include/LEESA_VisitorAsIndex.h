#ifndef __LEESA_VISITOR_AS_INDEX_H
#define __LEESA_VISITOR_AS_INDEX_H

namespace LEESA {

  template <class Kind>
  class VisitorAsIndex;

  template <class Kind>
  struct VisitorAsIndex_CRTP 
  {
    LEESA::VisitorAsIndex<Kind> operator [] 
      (DOMAIN_NAMESPACE::Visitor &v) const;
  };

}

#endif // __LEESA_VISITOR_AS_INDEX_H
