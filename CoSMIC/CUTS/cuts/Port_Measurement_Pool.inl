// $Id$

//
// ~CUTS_Port_Measurement_Pool
//
CUTS_INLINE
CUTS_Port_Measurement_Pool::~CUTS_Port_Measurement_Pool (void)
{

}

//
// size
//
CUTS_INLINE
size_t CUTS_Port_Measurement_Pool::size (void) const
{
  return this->size_ + 1;
}

