// -*- C++ -*-
// $Id$

//
// Project_Generator
//
inline
Project_Generator::
Project_Generator (const PICML_File_Creator & files,
                   Implementation_Generator & impl_gen,
                   GAME::XME::Project & proj)
: files_ (files),
  impl_gen_ (impl_gen),
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
