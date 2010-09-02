// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{

//
// GME_ID_Generator
//
GAME_INLINE
GME_ID_Generator::GME_ID_Generator (xercesc::DOMDocument * proj)
: atom_ (0, "id-0066-00000000"),
  model_ (0, "id-0065-00000000"),
  folder_ (0, "id-006a-00000000"),
  ref_ (0, "id-0067-00000000"),
  conn_ (0, "id-0068-00000000")
{
  this->init (proj);
}

//
// ~GME_ID_Generator
//
GAME_INLINE
GME_ID_Generator::~GME_ID_Generator ()
{
}

//
// generate_folder_id
//
GAME_INLINE
const GAME::Xml::String & GME_ID_Generator::generate_folder_id (void)
{
  return GME_ID_Generator::generate_id (this->folder_);
}

//
// generate_atom_id
//
GAME_INLINE
const GAME::Xml::String & GME_ID_Generator::generate_atom_id (void)
{
  return GME_ID_Generator::generate_id (this->atom_);
}

//
// generate_model_id
//
GAME_INLINE
const GAME::Xml::String & GME_ID_Generator::generate_model_id (void)
{
  return GME_ID_Generator::generate_id (this->model_);
}

//
// generate_reference_id
//
GAME_INLINE
const GAME::Xml::String & GME_ID_Generator::generate_reference_id (void)
{
  return GME_ID_Generator::generate_id (this->ref_);
}

//
// generate_set_id
//
GAME_INLINE
const GAME::Xml::String & GME_ID_Generator::generate_connection_id (void)
{
  return GME_ID_Generator::generate_id (this->conn_);
}

}
}
