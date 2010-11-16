// $Id$

namespace GAME
{
  //
  // RegistryNode
  //
  GAME_INLINE
  RegistryNode::RegistryNode (void)
  {

  }

  //
  // RegistryNode
  //
  GAME_INLINE
  RegistryNode::RegistryNode (IMgaRegNode * node)
  : node_ (node)
  {

  }

  //
  // RegistryNode
  //
  GAME_INLINE
  RegistryNode::RegistryNode (const RegistryNode & node)
  : node_ (node.node_)
  {

  }

  //
  // RegistryNode
  //
  GAME_INLINE
  RegistryNode::~RegistryNode (void)
  {

  }

  //
  // operator bool
  //
  GAME_INLINE
  RegistryNode::operator bool (void) const
  {
    return this->node_.p != 0;
  }

  //
  // operator IMgaRegNode *
  //
  GAME_INLINE
  RegistryNode::operator IMgaRegNode * (void) const
  {
    return this->node_.p;
  }

  //
  // status_here
  //
  GAME_INLINE
  bool RegistryNode::status_here (void) const
  {
    return this->status () == 0;
  }

  //
  // status_meta
  //
  GAME_INLINE
  bool RegistryNode::status_meta (void) const
  {
    return this->status () == -1;
  }

  //
  // status_inherited
  //
  GAME_INLINE
  bool RegistryNode::status_inherited (void) const
  {
    return this->status () > 0;
  }

  //
  // attach
  //
  GAME_INLINE
  void RegistryNode::attach (IMgaRegNode * node)
  {
    this->node_.Attach (node);
  }

  //
  // operator =
  //
  GAME_INLINE
  const RegistryNode & RegistryNode::operator = (const RegistryNode & node)
  {
    if (this->node_ != node.node_)
      this->node_ = node.node_;

    return *this;
  }
}
