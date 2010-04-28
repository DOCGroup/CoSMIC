// -*- C++ -*-
// $Id$

namespace GME
{
namespace XME
{
//
// Registry_Node
//
GME_INLINE
Registry_Node::Registry_Node (void)
: node_ (0),
  value_ (0)
{

}

//
// Registry_Node
//
GME_INLINE
Registry_Node::Registry_Node (const Registry_Node & node)
: node_ (node.node_),
  value_ (node.value_)
{

}

//
// ~Registry_Node
//
GME_INLINE
Registry_Node::~Registry_Node (void)
{

}

//
// operator =
//
GME_INLINE
const Registry_Node & Registry_Node::operator = (const Registry_Node & node)
{
  this->node_ = node.node_;
  this->value_ = node.value_;
  return *this;
}

//
// operator =
//
GME_INLINE
const XMLCh * Registry_Node::name (void) const
{
  return this->node_->getAttribute (ATTR_NAME);
}

//
// value
//
GME_INLINE
void Registry_Node::value (const ::Utils::XStr & v) const
{
  this->value_->setTextContent (v);
}

//
// value
//
GME_INLINE
const XMLCh * Registry_Node::value (void) const
{
  return this->value_->getTextContent ();
}

}
}
