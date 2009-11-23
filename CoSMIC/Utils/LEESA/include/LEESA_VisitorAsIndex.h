#ifndef __LEESA_VISITOR_AS_INDEX_H
#define __LEESA_VISITOR_AS_INDEX_H

namespace LEESA {

  template <class Kind>
  class VisitorAsIndex;

  template <class Kind, class Visitor>
  struct VisitorAsIndex_CRTP 
  {
    LEESA::VisitorAsIndex<Kind> operator [] (Visitor &v);
  };

}

#endif // __LEESA_VISITOR_AS_INDEX_H
