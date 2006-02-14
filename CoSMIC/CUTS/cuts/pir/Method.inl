// $Id$

namespace CUTS_PIR
{
  //
  // actions
  //
  CUTS_INLINE
  Method::Worker_Actions & Method::actions (void)
  {
    return this->actions_;
  }

  CUTS_INLINE
  const Method::Worker_Actions & Method::actions (void) const
  {
    return this->actions_;
  }
}
