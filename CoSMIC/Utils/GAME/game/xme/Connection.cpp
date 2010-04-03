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

  // Create the destination connection point.
  point = doc->createElement (TAGNAME_CONNPOINT);
  point->setAttribute (ATTR_ROLE, CONNPOINT_DST);
  point->setAttribute (ATTR_TARGET, dst.id ());
  this->obj_->appendChild (point);
}

}
}
