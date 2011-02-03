// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// Project
//
GAME_INLINE
Project::Project (void)
{

}

//
// Project
//
GAME_INLINE
Project::Project (const Project & p)
: proj_ (p.proj_)
{

}

//
// Project
//
GAME_INLINE
Project::Project (IMgaMetaProject * p)
: proj_ (p)
{

}

//
// ~Project
//
GAME_INLINE
Project::~Project (void)
{

}

//
// attach
//
GAME_INLINE
void Project::attach (IMgaMetaProject * p)
{
  this->proj_.Attach (p);
}

//
// release
//
GAME_INLINE
void Project::release (void)
{
  this->proj_.Release ();
}

//
// impl
//
GAME_INLINE
IMgaMetaProject * Project::impl (void) const
{
  return this->proj_.p;
}

}

}
}
