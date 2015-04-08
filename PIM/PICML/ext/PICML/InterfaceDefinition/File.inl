// -*- C++ -*-
namespace PICML
{
  //
  // File_Impl
  //
  GAME_INLINE File_Impl::File_Impl (void)
  {
  }

  //
  // File_Impl
  //
  GAME_INLINE File_Impl::File_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~File_Impl
  //
  GAME_INLINE File_Impl::~File_Impl (void)
  {
  }

  //
  // Path
  //
  GAME_INLINE void File_Impl::Path (const std::string & val)
  {
    static const std::string attr_name ("Path");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Path
  //
  GAME_INLINE std::string File_Impl::Path (void) const
  {
    static const std::string attr_name ("Path");
    return this->attribute (attr_name)->string_value ();
  }
}

