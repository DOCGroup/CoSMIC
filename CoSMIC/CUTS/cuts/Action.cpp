// $Id: Action.cpp,v 1.1.2.2 2006/06/03 00:56:44 hillj Exp $

#include "cuts/Action.h"

//
// CUTS_Action
//
CUTS_Action::CUTS_Action (void)
{

}

//
// CUTS_Action
//
CUTS_Action::CUTS_Action (const CUTS_Action &)
{

}

//
// release
//
void CUTS_Action::release (void)
{
  delete this;
}
