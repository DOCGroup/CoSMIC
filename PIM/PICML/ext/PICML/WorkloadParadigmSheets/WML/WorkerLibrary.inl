// -*- C++ -*-
namespace PICML
{
  //
  // WorkerLibrary_Impl
  //
  GAME_INLINE WorkerLibrary_Impl::WorkerLibrary_Impl (void)
  {
  }

  //
  // WorkerLibrary_Impl
  //
  GAME_INLINE WorkerLibrary_Impl::WorkerLibrary_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkerLibrary_Impl
  //
  GAME_INLINE WorkerLibrary_Impl::~WorkerLibrary_Impl (void)
  {
  }

  //
  // Location
  //
  GAME_INLINE void WorkerLibrary_Impl::Location (const std::string & val)
  {
    static const std::string attr_name ("Location");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Location
  //
  GAME_INLINE std::string WorkerLibrary_Impl::Location (void) const
  {
    static const std::string attr_name ("Location");
    return this->attribute (attr_name)->string_value ();
  }
}

