// -*- C++ -*-
// $Id$

//
// Project_Generator
//
inline
Project_Generator::
Project_Generator (const PICML_File_Creator & files,
                   GAME::XME::Project & proj)
: files_ (files),
  proj_ (proj)
{
  this->initialize ();
}

//
// ~Project_Generator
//
inline
Project_Generator::~Project_Generator (void)
{

}
