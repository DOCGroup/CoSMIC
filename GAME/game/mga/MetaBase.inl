// $Id$

#include "ace/ACE.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// Base_Impl
//
GAME_INLINE
Base_Impl::Base_Impl (void)
{

}

//
// Base_Impl
//
GAME_INLINE
Base_Impl::Base_Impl (IMgaMetaBase * meta)
: metabase_ (meta)
{

}

//
// ~Base_Impl
//
GAME_INLINE
Base_Impl::~Base_Impl (void)
{

}

//
// attach
//
GAME_INLINE
void Base_Impl::attach (IMgaMetaBase * metabase)
{
  this->metabase_.Attach (metabase);
}

//
// impl
//
GAME_INLINE
IMgaMetaBase * Base_Impl::impl (void) const
{
  return this->metabase_;
}

//
// release
//
GAME_INLINE
void Base_Impl::release (void)
{
  this->metabase_.Release ();
}

//
// hash
//
GAME_INLINE
unsigned long Base_Impl::hash (void) const
{
  return ACE::hash_pjw (this->name ().c_str ());
}

//
// is_equal_to
//
GAME_INLINE
bool Base_Impl::is_equal_to (const Base_Impl * impl) const
{
  return this == impl ? true : this->name () == impl->name ();
}

}
}
}
