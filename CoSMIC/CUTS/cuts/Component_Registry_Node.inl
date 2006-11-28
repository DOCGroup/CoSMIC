// $Id$

//
// ~CUTS_Component_Registry_Node
//
CUTS_INLINE
CUTS_Component_Registry_Node::
~CUTS_Component_Registry_Node (void)
{

}

//
// info
//
CUTS_INLINE
const CUTS_Component_Info &
CUTS_Component_Registry_Node::info (void) const
{
  return this->info_;
}

CUTS_INLINE
CUTS_Component_Info &
CUTS_Component_Registry_Node::info (void)
{
  return this->info_;
}
