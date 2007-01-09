// $Id$

CUTS_INLINE
std::ofstream & CUTS_BE_File_Traits::outfile (void)
{
  return *this->outfile_.get ();
}
