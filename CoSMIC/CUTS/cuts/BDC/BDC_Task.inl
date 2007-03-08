// $Id$

namespace CUTS
{
  //
  // register_handler
  //
  CUTS_INLINE
  int BDC_Task::register_handler (CUTS_System_Metric_Handler * handler)
  {
    return this->handles_.insert (handler);
  }

  //
  // unregister_handler
  //
  CUTS_INLINE
  int BDC_Task::unregister_handler (CUTS_System_Metric_Handler * handler)
  {
    return this->handles_.remove (handler);
  }
}
