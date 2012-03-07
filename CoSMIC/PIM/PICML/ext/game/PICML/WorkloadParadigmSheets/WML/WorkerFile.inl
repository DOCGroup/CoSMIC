// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // WorkerFile_Impl
  //
  GAME_INLINE WorkerFile_Impl::WorkerFile_Impl (void)
  {
  }

  //
  // WorkerFile_Impl
  //
  GAME_INLINE WorkerFile_Impl::WorkerFile_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkerFile_Impl
  //
  GAME_INLINE WorkerFile_Impl::~WorkerFile_Impl (void)
  {
  }

  //
  // Location
  //
  GAME_INLINE void WorkerFile_Impl::Location (const std::string & val)
  {
    static const std::string attr_name ("Location");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Location
  //
  GAME_INLINE std::string WorkerFile_Impl::Location (void) const
  {
    static const std::string attr_name ("Location");
    return this->attribute (attr_name)->string_value ();
  }
}

