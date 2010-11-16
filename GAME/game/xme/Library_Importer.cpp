// $Id$

#include "Library_Importer.h"
#include "Library.h"

#include "GME_ID_Generator.h"
#include "ID_Generator_Repo.h"
#include "boost/bind.hpp"

namespace GAME
{
namespace XME
{
const GAME::Xml::String Library_Importer::ATTR_ID ("id");
const GAME::Xml::String Library_Importer::ATTR_REFERRED ("referred");
const GAME::Xml::String Library_Importer::ATTR_TARGET ("target");

//
// Library_Importer
//
Library_Importer::Library_Importer (GME_ID_Generator * idgen)
: idgen_ (idgen)
{

}

//
// ~Library_Importer
//
Library_Importer::~Library_Importer (void)
{

}

//
// import
//
void Library_Importer::import (Folder & folder)
{
  this->handle_folder (folder);

  // Finally, fix any unresolved references.
  std::for_each (this->unresolved_refs_.begin (),
                 this->unresolved_refs_.end (),
                 boost::bind (&Library_Importer::resolve_reference,
                              boost::ref (this),
                              _1));

  std::for_each (this->unresolved_conns_.begin (),
                 this->unresolved_conns_.end (),
                 boost::bind (&Library_Importer::resolved_connection,
                              boost::ref (this),
                              _1));
}

//
// handle_folder
//
void Library_Importer::handle_folder (Folder & folder)
{
  // Update the id for the folder element.
  this->handle_import_common (folder, this->idgen_->generate_folder_id ());

  // Update the children in this folder.
  std::vector <Folder> child_folders;
  folder.children (child_folders);

  std::for_each (child_folders.begin (),
                 child_folders.end (),
                 boost::bind (&Library_Importer::handle_folder,
                              boost::ref (this),
                              _1));

  std::vector <FCO> child_fcos;
  folder.children (child_fcos);

  std::for_each (child_fcos.begin (),
                 child_fcos.end (),
                 boost::bind (&Library_Importer::handle_import_fco,
                              boost::ref (this),
                              _1));
}

//
// handle_import_fco
//
void Library_Importer::handle_import_fco (FCO & fco)
{
  switch (fco.type ())
  {
  case Object_Type::OT_ATOM:
    this->handle_import_atom (fco);
    break;

  case Object_Type::OT_CONNECTION:
    this->handle_import_connection (fco);
    break;

  case Object_Type::OT_MODEL:
    this->handle_import_model (fco);
    break;

  case Object_Type::OT_REFERENCE:
    this->handle_import_reference (fco);
    break;
  }
}

//
// handle_import_common
//
template <typename T>
void Library_Importer::handle_import_common (T & e, const GAME::Xml::String & newid)
{
  using xercesc::XMLString;

  // Get the old id and convert it to lowercase.
  GAME::Xml::String old_id (e.id (), false);
  XMLString::lowerCase (old_id);

  GAME::Xml::String name (e.name (), false);
  GAME::Xml::String kind (e.kind (), false);

  // Store the old id and set a new id.
  this->id_map_[old_id] = newid;
  e.ptr ()->setAttribute (ATTR_ID, newid);
}

//
// handle_import_atom
//
void Library_Importer::handle_import_atom (FCO & fco)
{
  Atom atom = Atom::_narrow (fco);
  this->handle_import_common (atom, this->idgen_->generate_atom_id ());
}

//
// handle_import_model
//
void Library_Importer::handle_import_model (FCO & fco)
{
  Model model = Model::_narrow (fco);
  this->handle_import_common (model, this->idgen_->generate_model_id ());

  // Now, visit all the children in the model.
  std::vector <FCO> children;
  model.children (children);

  std::for_each (children.begin (),
                 children.end (),
                 boost::bind (&Library_Importer::handle_import_fco,
                              boost::ref (this),
                              _1));
}

//
// handle_import_reference
//
void Library_Importer::handle_import_reference (FCO & fco)
{
  Reference ref = Reference::_narrow (fco);
  this->handle_import_common (ref, this->idgen_->generate_reference_id ());

  // Store the reference id for resolution later.
  this->unresolved_refs_.push_back (ref);
}

//
// handle_import_connection
//
void Library_Importer::handle_import_connection (FCO & fco)
{
  Connection conn = Connection::_narrow (fco);
  this->handle_import_common (conn, this->idgen_->generate_connection_id ());

  // Store the connection for later resolution.
  this->unresolved_conns_.push_back (conn);
}

//
// resolve_reference
//
void Library_Importer::resolve_reference (Reference & ref)
{
  using xercesc::XMLString;

  if (!ref.ptr ()->hasAttribute (ATTR_REFERRED))
    return;

  GAME::Xml::String old_id (ref.ptr ()->getAttribute (ATTR_REFERRED));
  XMLString::lowerCase (old_id);

  id_map_t::iterator iter = this->id_map_.find (old_id);

  if (iter != this->id_map_.end ())
    ref.ptr ()->setAttribute (ATTR_REFERRED, iter->second);
}

//
// resolved_connection
//
void Library_Importer::resolved_connection (Connection & conn)
{
  using xercesc::XMLString;

  xercesc::DOMElement * p1 = conn.ptr ()->getFirstElementChild ()->getNextElementSibling ();
  xercesc::DOMElement * p2 = p1->getNextElementSibling ();

  GAME::Xml::String p1_old_id (p1->getAttribute (ATTR_TARGET));
  XMLString::lowerCase (p1_old_id);

  GAME::Xml::String p2_old_id (p2->getAttribute (ATTR_TARGET));
  XMLString::lowerCase (p2_old_id);

  id_map_t::iterator iter = this->id_map_.find (p1_old_id);

  if (iter != this->id_map_.end ())
    p1->setAttribute (ATTR_TARGET, iter->second);

  iter = this->id_map_.find (p2_old_id);

  if (iter != this->id_map_.end ())
    p2->setAttribute (ATTR_TARGET, iter->second);
}

//
// operator ()
//
bool Library_Importer::
insensitive_id::operator () (const GAME::Xml::String & lid, const GAME::Xml::String & rid) const
{
  using xercesc::XMLString;
  return XMLString::compareNIString (lid, rid, lid.length ()) < 0;
}

}
}
