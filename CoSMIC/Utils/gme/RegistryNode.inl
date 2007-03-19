// $Id$

namespace GME
{
  //
  // RegistryNode
  //
  GME_INLINE
  RegistryNode::RegistryNode (void)
  {

  }

  //
  // RegistryNode
  //
  GME_INLINE
  RegistryNode::RegistryNode (IMgaRegNode * node)
  : node_ (node)
  {

  }

  //
  // RegistryNode
  //
  GME_INLINE
  RegistryNode::RegistryNode (const RegistryNode & node)
  : node_ (node.node_)
  {

  }

  //
  // RegistryNode
  //
  GME_INLINE
  RegistryNode::~RegistryNode (void)
  {

  }

  //
  // operator bool
  //
  GME_INLINE
  RegistryNode::operator bool (void) const
  {
    return this->node_.p != 0;
  }

  //
  // operator IMgaRegNode *
  //
  GME_INLINE
  RegistryNode::operator IMgaRegNode * (void) const
  {
    return this->node_.p;
  }

  //
  // status_here
  //
  GME_INLINE
  bool RegistryNode::status_here (void) const
  {
    return this->status () == 0;
  }

  //
  // status_meta
  //
  GME_INLINE
  bool RegistryNode::status_meta (void) const
  {
    return this->status () == -1;
  }

  //
  // status_inherited
  //
  GME_INLINE
  bool RegistryNode::status_inherited (void) const
  {
    return this->status () > 0;
  }

  //
  // attach
  //
  GME_INLINE
  void RegistryNode::attach (IMgaRegNode * node)
  {
    this->node_.Attach (node);
  }

  //
  // operator =
  //
  GME_INLINE
  const RegistryNode & RegistryNode::operator = (const RegistryNode & node)
  {
    if (this->node_ != node.node_)
      this->node_ = node.node_;

    return *this;
  }
}
