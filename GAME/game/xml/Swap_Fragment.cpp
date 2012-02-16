// $Id$

#include "Swap_Fragment.h"

namespace GAME
{
namespace Xml
{

//
// Swap_Fragment
//
Swap_Fragment::Swap_Fragment (Fragment & current, const Fragment & f)
: Fragment (f),
  current_ (current),
  orig_ (current)
{
  current = f;
}

//
// Swap_Fragment
//
Swap_Fragment::~Swap_Fragment (void)
{
  this->current_ = this->orig_;
}

}
}
