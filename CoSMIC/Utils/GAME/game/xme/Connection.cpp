// $Id$

#include "Connection.h"

#if !defined (__GME_INLINE__)
#include "Connection.inl"
#endif

#include "GME_ID_Generator.h"
#include "Model.h"

namespace GME
{
namespace XME
{
const ::Utils::XStr Connection::TAGNAME ("connection");
const ::Utils::XStr Connection::TAGNAME_CONNPOINT ("connpoint");
const ::Utils::XStr Connection::CONNPOINT_SRC ("src");
const ::Utils::XStr Connection::CONNPOINT_DST ("dst");
const ::Utils::XStr Connection::ATTR_TARGET ("target");

//
// _create
//
Connection Connection::
_create (Model & parent,
         const ::Utils::XStr & kind,
         const FCO & src,
         const FCO & dst)
{
  // Generate the relative id for the new folder.
  size_t counter = parent.relid_counter ();
  parent.relid_counter (counter + 1);

  // Create the new folder element.
  return Connection (parent.ptr (), kind, counter, src, dst);
}

//
// Connection
//
GME_INLINE
Connection::
Connection (xercesc::DOMElement * parent,
            const ::Utils::XStr & kind,
            size_t relid,
            const FCO & src,
            const FCO & dst)
: FCO (parent,
       TAGNAME,
       GME_XME_ID_GENERATOR (Connection)->generate_id (),
       kind,
       kind,
       relid)
{
  using xercesc::DOMElement;
  using xercesc::DOMDocument;

  DOMDocument * doc = parent->getOwnerDocument ();

  // Create the source connection point.
  DOMElement * point = doc->createElement (TAGNAME_CONNPOINT);
  point->setAttribute (ATTR_ROLE, CONNPOINT_SRC);
  point->setAttribute (ATTR_TARGET, src.id ());
  this->obj_->appendChild (point);
  this->src_ = src;

  // Create the destination connection point.
  point = doc->createElement (TAGNAME_CONNPOINT);
  point->setAttribute (ATTR_ROLE, CONNPOINT_DST);
  point->setAttribute (ATTR_TARGET, dst.id ());
  this->obj_->appendChild (point);
  this->dst_ = dst;
}

//
// src
//
void Connection::src (const FCO & fco)
{
  using xercesc::DOMNode;
  using xercesc::DOMElement;

  // The first child node is always the name. The second child
  // node is the source connection point.
  DOMNode * name = this->obj_->getFirstChild ();
  DOMNode * cp = name->getNextSibling ();

  // Update the id for the attribute.
  DOMElement * e = dynamic_cast <DOMElement *> (cp);
  e->setAttribute (ATTR_TARGET, fco.id ());
  this->src_ = fco;
}

//
// dst
//
void Connection::dst (const FCO & fco)
{
  using xercesc::DOMNode;
  using xercesc::DOMElement;

  // The first child node is always the name. The second child
  // node is the source connection point.
  DOMNode * name = this->obj_->getFirstChild ();
  DOMNode * cp = name->getNextSibling ()->getNextSibling ();

  // Update the id for the attribute.
  DOMElement * e = dynamic_cast <DOMElement *> (cp);
  e->setAttribute (ATTR_TARGET, fco.id ());
  this->dst_ = fco;
}

//
// src
//
const FCO & Connection::src (void) const
{
  if (this->is_nil () || !this->src_.is_nil ())
    return this->src_;

  using xercesc::DOMNode;
  using xercesc::DOMElement;

  // Locate source connection in XML document.
  DOMNode * node = this->obj_->getFirstChild ();
  DOMNode * cp = node->getNextSibling ();
  DOMElement * e = dynamic_cast <DOMElement *> (cp);

  using xercesc::DOMDocument;
  DOMDocument * doc = this->obj_->getOwnerDocument ();
  const XMLCh * target = e->getAttribute (ATTR_TARGET);
  e = doc->getElementById (target);

  if (e)
    this->src_.attach (e);

  return this->src_;
}

//
// dst
//
const FCO & Connection::dst (void) const
{
  if (this->is_nil () || !this->dst_.is_nil ())
    return this->dst_;

  using xercesc::DOMNode;
  using xercesc::DOMElement;

  // Locate destination connection in XML document.
  DOMNode * node = this->obj_->getFirstChild ();
  const XMLCh * name = node->getNodeName ();

  DOMNode * cp = node->getNextSibling ()->getNextSibling ();
  DOMElement * e = dynamic_cast <DOMElement *> (cp);

  using xercesc::DOMDocument;
  DOMDocument * doc = e->getOwnerDocument ();
  const XMLCh * target = e->getAttribute (ATTR_TARGET);
  e = doc->getElementById (target);

  if (e)
    this->dst_.attach (e);

  return this->dst_;
}

//
// release
//
xercesc::DOMElement * Connection::release (void)
{
  this->src_.release ();
  this->dst_.release ();

  return FCO::release ();
}

//
// attach
//
void Connection::attach (xercesc::DOMElement * e, bool validate)
{
  FCO::attach (e, validate);

  // Make sure we release our current connections. Otherwise,
  // we can end up in a bad state.
  this->src_.release ();
  this->dst_.release ();
}

}
}
