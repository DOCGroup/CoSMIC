#ifndef __ACCEPTOR_H
#define __ACCEPTOR_H

#include <functional>

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

	// The new C++ feature of automatic type deduction using the "auto" keyword, 
	// which is going to be a part of C++09 standard, would simplify the 
	// following macros to a great extent.

	// Visits the MgaObject that is at the "destination" end of the
	// connection with the peer.

#define accept_each_dst(PEER, CONNECTION_TYPE, PEER_DST, VISITOR)                \
	{                                                                            \
	  std::set <CONNECTION_TYPE> _s = PEER.dst##CONNECTION_TYPE ();              \
	  for (std::set <CONNECTION_TYPE>::iterator itr = _s.begin();                \
	       itr != _s.end(); ++itr)  {                                            \
				PEER_DST _o = itr->dst##CONNECTION_TYPE##_end ();                \
				if (Udm::IsDerivedFrom (_o.type(), PEER_DST::meta))  {           \
					PEER_DST _p = PEER_DST::Cast (_o);                           \
					_p.Accept (VISITOR);                                         \
				}                                                                \
		}                                                                        \
	}

    // Visits the MgaObject that is at the "source" end of the
	// connection with the peer.
#define accept_each_src(PEER, CONNECTION_TYPE, PEER_SRC, VISITOR)                \
	{                                                                            \
	  std::set <CONNECTION_TYPE> _s = PEER.src##CONNECTION_TYPE ();              \
	  for (std::set <CONNECTION_TYPE>::iterator itr = _s.begin();                \
		   itr != _s.end(); ++itr) {                                             \
				PEER_SRC _o = itr->src##CONNECTION_TYPE##_end ();                \
				if (Udm::IsDerivedFrom (_o.type(), PEER_SRC::meta))  {           \
					PEER_SRC _p = PEER_SRC::Cast (_o);                           \
					_p.Accept (VISITOR);                                         \
				}                                                                \
		}                                                                        \
	}

    // Visits all the children of type CHILD_TYPE of the parent.
#define accept_each_child(PARENT, CHILD_TYPE, VISITOR)                   \
	{                                                                    \
	  std::set <CHILD_TYPE> _s = PARENT.CHILD_TYPE##_kind_children ();   \
	  accept_each (_s, VISITOR);                                         \
	}
}


/*

#define accept_each_src(PEER, CONNECTION_TYPE, PEER_SRC, VISITOR)                \
	{                                                                            \
	  std::set <CONNECTION_TYPE> _s = PEER.src##CONNECTION_TYPE ();              \
	  for (std::set <CONNECTION_TYPE>::iterator itr = _s.begin();                \
		   itr != _s.end(); ++itr) {                                             \
				MgaObject _o = itr->src##CONNECTION_TYPE##_end ();               \
				if (Udm::IsDerivedFrom (_o.type(), PEER_SRC::meta))  {           \
					PEER_SRC _p = PEER_SRC::Cast (_o);                           \
					_p.Accept (VISITOR);                                         \
				}                                                                \
		}                                                                        \
	}

	template <class MGAOBJECT>
    inline void accept_one (Udm::AssocEndAttr <MGAOBJECT> object, Visitor &v)
    {
		MGAOBJECT o = object;
		o.Accept (v);
    }

    template <class End, class Result, class Connection>
	class ConnectionEndAcceptor : public std::unary_function <End, void>
      {
        public:
			inline ConnectionEndAcceptor (Visitor &v, Result (Connection::*end_func)(void))
            : end_seek_ (end_func),
			  visitor_(&v) {}
          inline result_type operator ()(const argument_type &connection)
            {
				MgaObject o = (connection.*end_seek_)();
				if (Udm::IsDerivedFrom (o.type(), End::meta))  
				{
					End end = End::Cast (o);
					end.Accept (v);
				}
            };
      private:
		  typedef Result (Connection::*EndSeek)(void);
		  EndSeek end_seek_;
          Visitor *visitor_;
      };
*/
#endif // __ACCEPTOR_H

