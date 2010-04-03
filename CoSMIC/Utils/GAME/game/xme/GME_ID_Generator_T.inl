// -*- C++ -*-
// $Id$


namespace GME
{
namespace XME
{
//
// GME_ID_Generator_T
//
template <typename T>
GME_INLINE
GME_ID_Generator_T <T>::~GME_ID_Generator_T (void)
{

}

//
// reset
//
template <typename T>
GME_INLINE
void GME_ID_Generator_T <T>::reset (void)
{
  this->count_ = 0;
}

//
// current_id
//
template <typename T>
GME_INLINE
const ::Utils::XStr & GME_ID_Generator_T <T>::current_id (void) const
{
  return this->id_;
}

}
}
