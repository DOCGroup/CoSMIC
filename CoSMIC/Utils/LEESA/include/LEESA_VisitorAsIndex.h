#ifndef __LEESA_VISITOR_AS_INDEX_H
#define __LEESA_VISITOR_AS_INDEX_H

#ifndef LEESA_NO_VISITOR

namespace LEESA {

  template <class Kind>
  class VisitorAsIndex;

  template <class Kind, class Visitor>
  struct VisitorAsIndex_CRTP 
  {
      LEESA::VisitorAsIndex<Kind> operator [] (Visitor &v);
  };

}

#endif // __LEESA_NO_VISITOR

#endif // __LEESA_VISITOR_AS_INDEX_H

