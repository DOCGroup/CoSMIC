// -*- C++ -*-
// $Id$

//
// PICML_File_Creator
//
inline
PICML_File_Creator::PICML_File_Creator (GAME::XME::Project & proj)
: proj_ (proj)
{

}

//
// files
//
inline
const PICML_File_Creator::item_map & PICML_File_Creator::files (void) const
{
  return this->files_;
}

