#ifndef __ACCEPTOR_H
#define __ACCEPTOR_H

#include <functional>
#include "CQML/CQML.h"

namespace CQML
{
    template <class Obj>
	class Acceptor : public std::unary_function <Obj, void>
      {
        public:
          Acceptor (Visitor &v)
            : visitor_(&v) {}
          result_type operator ()(const argument_type &o)
            {
              const_cast<Obj &> (o).Accept (*visitor_);
            };
      private:
          Visitor *visitor_;
      };

    // Template that makes the accept code with a single template method call. :-)
    template <class Container>
    inline void accept_each (Container c, Visitor &v)
      {
        std::for_each (c.begin (), c.end(), Acceptor<Container::value_type> (v));            
      }
}

#endif // __ACCEPTOR_H
