// $Id: Port_Measurement_Pool.inl,v 1.1.2.1 2006/05/18 15:17:12 hillj Exp $

//
// size
//
CUTS_INLINE
size_t CUTS_Port_Measurement_Pool::size (void) const
{
  return this->size_ + 1;
}

