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
          inline Acceptor (Visitor &v)
            : visitor_(&v) {}
          inline result_type operator ()(const argument_type &o)
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

	template <class MGAOBJECT>
    inline void accept_one (Udm::AssocEndAttr <MGAOBJECT> object, Visitor &v)
    {
		MGAOBJECT o = object;
		o.Accept (v);
    }

	// The new C++ feature of automatic type deduction using the "auto" keyword, 
	// which is going to be a part of C++09 standard, would simplify the 
	// following macros to a great extent.

	// Visits the MgaObject that is at the "destination" end of the
	// connection with the peer.
#define accept_each_dst(PEER, CONNECTION_TYPE, VISITOR)                    \
	{                                                                      \
	  std::set <CONNECTION_TYPE> _s = PEER.dst##CONNECTION_TYPE ();        \
	  for (std::set <CONNECTION_TYPE>::iterator itr = _s.begin();          \
	       itr != _s.end(); ++itr)                                         \
	       accept_one (itr->dst##CONNECTION_TYPE##_end (), VISITOR);       \
	}

    // Visits the MgaObject that is at the "source" end of the
	// connection with the peer.
#define accept_each_src(PEER, CONNECTION_TYPE, VISITOR)                    \
	{                                                                      \
	  std::set <CONNECTION_TYPE> _s = PEER.src##CONNECTION_TYPE ();        \
	  for (std::set <CONNECTION_TYPE>::iterator itr = _s.begin();          \
	       itr != _s.end(); ++itr)                                         \
	       accept_one (itr->src##CONNECTION_TYPE##_end (), VISITOR);       \
	}

    // Visits all the children of type CHILD_TYPE of the parent.
#define accept_each_child(PARENT, CHILD_TYPE, VISITOR)                   \
	{                                                                    \
	  std::set <CHILD_TYPE> _s = PARENT.CHILD_TYPE##_kind_children ();   \
	  accept_each (_s, VISITOR);                                         \
	}
}

#endif // __ACCEPTOR_H

