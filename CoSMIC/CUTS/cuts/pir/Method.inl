// $Id$

namespace CUTS_PIR
{
  //
  // actions
  //
  Method::Worker_Actions & Method::actions (void)
  {
    return this->actions_;
  }

  const Method::Worker_Actions & Method::actions (void) const
  {
    return this->actions_;
  }
}
