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
// operator IMgaMetaBase *
//
GAME_INLINE
Base::operator IMgaMetaBase * (void) const
{
  return this->metabase_.p;
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
// operator <
//
GAME_INLINE
bool Base::operator < (const Base & meta) const
{
  return this->metabase_.p < meta.metabase_.p;
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
Base::operator bool (void) const
{
  return this->metabase_.p != 0;
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
