// $Id: Message_Handler.cpp,v 1.1.4.2 2006/03/12 01:48:05 hillj Exp $

#include "cuts/Message_Handler.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Message_Handler.inl"
#endif

//
// CUTS_Message_Handler
//
CUTS_Message_Handler::CUTS_Message_Handler (void)
: errors_ (0),
  warnings_ (0)
{

}

//
// ~CUTS_Message_Handler
//
CUTS_Message_Handler::~CUTS_Message_Handler (void)
{

}
