// $Id$

//
// CUTS_BE_Manager_Factory_Repo
//
CUTS_INLINE
CUTS_BE_Manager_Factory_Repo::CUTS_BE_Manager_Factory_Repo (void)
{

}

//
// ~CUTS_BE_Manager_Factory_Repo
//
CUTS_INLINE
CUTS_BE_Manager_Factory_Repo::~CUTS_BE_Manager_Factory_Repo (void)
{
  this->unload_all ();
}

//
// factories
//
CUTS_INLINE
const CUTS_BE_Manager_Factory_Set &
CUTS_BE_Manager_Factory_Repo::factories (void) const
{
  return this->factories_;
}
