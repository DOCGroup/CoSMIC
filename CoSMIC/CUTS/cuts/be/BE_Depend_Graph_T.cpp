// $Id$

#if !defined (__CUTS_INLINE__)
#include "BE_Depend_Graph_T.inl"
#endif

#include "boost/bind.hpp"
#include <algorithm>

//
// CUTS_BE_Depend_Graph_T
//
template <typename T>
CUTS_BE_Depend_Graph_T <T>::CUTS_BE_Depend_Graph_T (void)
{

}

//
// ~CUTS_BE_Depend_Graph_T
//
template <typename T>
CUTS_BE_Depend_Graph_T <T>::~CUTS_BE_Depend_Graph_T (void)
{
  for (Node_Map::iterator iter = this->graph_.begin ();
       iter != this->graph_.end ();
       iter ++)
  {
    delete iter->second;
  }

  //std::for_each (this->graph_.begin (),
  //               this->graph_.end (),
  //               boost::bind (boost::lambda::delete_ptr (),
  //               boost::bind (&Node_Map::value_type::second, _1)));
}

//
// find
//
template <typename T>
void CUTS_BE_Depend_Graph_T <T>::
find (const std::string & name, T * &node)
{
  Node_Map::iterator iter = this->graph_.find (name);

  if (iter == this->graph_.end ())
  {
    node = new T (name);

    std::pair <Node_Map::iterator, bool> result =
      this->graph_.insert (Node_Map::value_type (name, node));

    if (!result.second)
    {
      delete node;
      node = iter->second;
    }
  }
  else
    node = iter->second;
}
