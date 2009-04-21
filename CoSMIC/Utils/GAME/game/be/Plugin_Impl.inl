// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // Plugin_Impl
  //
  GME_INLINE
  Plugin_Impl::Plugin_Impl (const std::string & name, const std::string & progid, bool managed)
    : GME::Interpreter_Impl_Base (name, "*", progid, managed)
  {

  }

  //
  // ~Plugin_Impl
  //
  GME_INLINE
  Plugin_Impl::~Plugin_Impl (void)
  {

  }
}
