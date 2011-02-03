// $Id$

namespace GAME
{
namespace Mga
{

//
// RegistryNode_Impl
//
GAME_INLINE
RegistryNode_Impl::RegistryNode_Impl (void)
{

}

//
// RegistryNode_Impl
//
GAME_INLINE
RegistryNode_Impl::RegistryNode_Impl (IMgaRegNode * node)
: node_ (node)
{

}

//
// RegistryNode_Impl
//
GAME_INLINE
RegistryNode_Impl::~RegistryNode_Impl (void)
{

}

//
// status_here
//
GAME_INLINE
bool RegistryNode_Impl::status_here (void) const
{
  return this->status () == 0;
}

//
// status_meta
//
GAME_INLINE
bool RegistryNode_Impl::status_meta (void) const
{
  return this->status () == -1;
}

//
// status_inherited
//
GAME_INLINE
bool RegistryNode_Impl::status_inherited (void) const
{
  return this->status () > 0;
}

//
// attach
//
GAME_INLINE
void RegistryNode_Impl::attach (IMgaRegNode * node)
{
  this->node_.Attach (node);
}

}
}
