// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{
//
// Registry_Node
//
GAME_INLINE
Registry_Node::Registry_Node (void)
: node_ (0),
  value_ (0)
{

}

//
// Registry_Node
//
GAME_INLINE
Registry_Node::Registry_Node (const Registry_Node & node)
: node_ (node.node_),
  value_ (node.value_)
{

}

//
// Registry_Node
//
GAME_INLINE
Registry_Node::Registry_Node (xercesc::DOMElement * node, bool existing)
: node_ (node),
  value_ (0)
{
  if (!existing)
    this->new_value ();
}

//
// ~Registry_Node
//
GAME_INLINE
Registry_Node::~Registry_Node (void)
{

}

//
// operator =
//
GAME_INLINE
const Registry_Node & Registry_Node::operator = (const Registry_Node & node)
{
  this->node_ = node.node_;
  this->value_ = node.value_;
  return *this;
}

//
// operator =
//
GAME_INLINE
const XMLCh * Registry_Node::name (void) const
{
  return this->node_->getAttribute (ATTR_NAME);
}

}
}
