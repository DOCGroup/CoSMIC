// $Id$

#if !defined (__CUTS_INLINE__)
#include "BE_Depend_Graph_T.inl"
#endif

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
}

//
// find
//
template <typename T>
int CUTS_BE_Depend_Graph_T <T>::
find (const std::string & name, T * &node)
{
  int retval = -1;
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
      retval = 1;
    }
    else
      retval = 0;
  }
  else
  {
    node = iter->second;
    retval = 1;
  }

  return retval;
}

//
// find
//
template <typename T>
bool CUTS_BE_Depend_Graph_T <T>::
find (const std::string & name, const T * &node) const
{
  Node_Map::const_iterator iter = this->graph_.find (name);

  if (iter == this->graph_.end ())
    return false;

  node = iter->second;
  return true;
}

//
// remove
//
template <typename T>
void CUTS_BE_Depend_Graph_T <T>::remove (const std::string & name)
{
  Node_Map::iterator iter = this->graph_.find (name);

  if (iter != this->graph_.end ())
  {
    delete iter->second;
    this->graph_.erase (iter);
  }
}
