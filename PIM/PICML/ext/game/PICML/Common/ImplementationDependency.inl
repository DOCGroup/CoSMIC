// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ImplementationDependency_Impl
  //
  GAME_INLINE ImplementationDependency_Impl::ImplementationDependency_Impl (void)
  {
  }

  //
  // ImplementationDependency_Impl
  //
  GAME_INLINE ImplementationDependency_Impl::ImplementationDependency_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationDependency_Impl
  //
  GAME_INLINE ImplementationDependency_Impl::~ImplementationDependency_Impl (void)
  {
  }

  //
  // requiredType
  //
  GAME_INLINE void ImplementationDependency_Impl::requiredType (const std::string & val)
  {
    static const std::string attr_name ("requiredType");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // requiredType
  //
  GAME_INLINE std::string ImplementationDependency_Impl::requiredType (void) const
  {
    static const std::string attr_name ("requiredType");
    return this->attribute (attr_name)->string_value ();
  }
}

