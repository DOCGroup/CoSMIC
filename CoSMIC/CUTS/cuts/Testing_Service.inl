// $Id$

//
// CUTS_Testing_Service
//
CUTS_INLINE
CUTS_Testing_Service::CUTS_Testing_Service (void)
{

}

//
// ~CUTS_Testing_Service
//
CUTS_INLINE
CUTS_Testing_Service::~CUTS_Testing_Service (void)
{

}

//
// registry
//
CUTS_INLINE
const CUTS_Component_Registry & CUTS_Testing_Service::registry (void) const
{
  return this->registry_;
}

//
// registry
//
CUTS_INLINE
CUTS_Component_Registry & CUTS_Testing_Service::registry (void)
{
  return this->registry_;
}
