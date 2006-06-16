// $Id: Path_Measurement_exec_i.inl,v 1.1.4.2 2006/03/12 01:48:06 hillj Exp $

namespace CUTS
{
  //
  // testing_service
  //
  CUTS_INLINE
  void Path_Measurement_exec_i::testing_service (
    Testing_Service_exec_i * testing_service)
  {
    this->testing_service_ = testing_service;
  }
}
