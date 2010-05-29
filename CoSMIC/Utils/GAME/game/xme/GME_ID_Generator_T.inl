// -*- C++ -*-
// $Id$


namespace GAME
{
namespace XME
{
//
// GME_ID_Generator_T
//
template <typename T>
GAME_INLINE
GME_ID_Generator_T <T>::~GME_ID_Generator_T (void)
{

}

//
// reset
//
template <typename T>
GAME_INLINE
void GME_ID_Generator_T <T>::reset (void)
{
  this->count_ = 0;
}

//
// current_id
//
template <typename T>
GAME_INLINE
const ::Utils::XStr & GME_ID_Generator_T <T>::current_id (void) const
{
  return this->id_;
}

}
}
