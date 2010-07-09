// $Id$

namespace GAME
{
namespace Meta
{
//
// Base
//
GAME_INLINE
Base::Base (void)
{

}

//
// Base
//
GAME_INLINE
Base::Base (IMgaMetaBase * meta)
: metabase_ (meta)
{

}

//
// Base
//
GAME_INLINE
Base::Base (const Base & meta)
  : metabase_ (meta.metabase_)
{

}

//
// ~Base
//
GAME_INLINE
Base::~Base (void)
{

}

//
// attach
//
GAME_INLINE
void Base::attach (IMgaMetaBase * metabase)
{
  this->metabase_.Attach (metabase);
}

//
// operator ==
//
GAME_INLINE
bool Base::operator == (const std::string & name) const
{
  return this->name () == name;
}

//
// operator !=
//
GAME_INLINE
bool Base::operator != (const std::string & name) const
{
  return !(*this == name);
}

//
// operator ==
//
GAME_INLINE
bool Base::operator == (const Base & meta) const
{
  return this->metabase_ == meta.metabase_;
}

//
// operator !=
//
GAME_INLINE
bool Base::operator != (const Base & meta) const
{
  return !(*this == meta);
}

//
// impl
//
GAME_INLINE
IMgaMetaBase * Base::impl (void) const
{
  return this->metabase_;
}

//
// operator bool
//
GAME_INLINE
bool Base::is_nil (void) const
{
  return this->metabase_.p == 0;
}

//
// release
//
GAME_INLINE
void Base::release (void)
{
  this->metabase_.Release ();
}

}
}

//
// operator <
//
GAME_INLINE
bool operator < (const GAME::Meta::Base & lhs, const GAME::Meta::Base & rhs)
{
  return lhs.impl () < rhs.impl ();
}

//
// operator >
//
GAME_INLINE
bool operator > (const GAME::Meta::Base & lhs, const GAME::Meta::Base & rhs)
{
  return lhs.impl () > rhs.impl ();
}

//
// operator <=
//
GAME_INLINE
bool operator <= (const GAME::Meta::Base & lhs, const GAME::Meta::Base & rhs)
{
  return lhs.impl () <= rhs.impl ();
}

//
// operator >=
//
GAME_INLINE
bool operator >= (const GAME::Meta::Base & lhs, const GAME::Meta::Base & rhs)
{
  return lhs.impl () >= rhs.impl ();
}
