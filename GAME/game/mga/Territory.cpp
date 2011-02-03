// $Id$

#include "stdafx.h"
#include "mga.h"
#include "Territory.h"

namespace GAME
{
namespace Mga
{

//
// Territory
//
Territory::Territory (void)
{

}

//
// Territory
//
Territory::Territory (IMgaTerritory * terr)
  : terr_ (terr)
{

}

//
// Territory
//
Territory::Territory (const Territory & terr)
  : terr_ (terr.terr_)
{

}

//
// Territory
//
Territory::~Territory (void)
{

}

//
// close
//
void Territory::close (void)
{
  if (!this->terr_)
    return;

  VERIFY_HRESULT (this->terr_->Destroy ());
  this->terr_.Release ();
}

//
// attach
//
void Territory::attach (IMgaTerritory * terr)
{
  this->terr_.Attach (terr);
}

//
// operator IMgaTerritory *
//
Territory::operator IMgaTerritory * (void) const
{
  return this->terr_;
}

}
}
