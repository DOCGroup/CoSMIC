// $Id$

//
// parent
//
CUTS_INLINE
void CUTS_Worker::parent (long parent)
{
  this->parent_ = parent;
}

CUTS_INLINE
long CUTS_Worker::parent (void) const
{
  return this->parent_;
}
