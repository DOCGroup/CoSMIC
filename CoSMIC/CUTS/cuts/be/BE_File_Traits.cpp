// $Id$

#include "BE_File_Traits.h"

#if !defined (__CUTS_INLINE__)
#include "BE_File_Traits.inl"
#endif

#include <fstream>

//
// CUTS_BE_File_Traits
//
CUTS_BE_File_Traits::CUTS_BE_File_Traits (void)
: outfile_ (new std::ofstream)
{

}

//
// ~CUTS_BE_File_Traits
//
CUTS_BE_File_Traits::~CUTS_BE_File_Traits (void)
{
  if (this->outfile_->is_open ())
    this->outfile_->close ();
}

//
// close_file
//
void CUTS_BE_File_Traits::
close_file (const PICML::ComponentImplementationContainer & container)
{
  this->outfile_->close ();
}
