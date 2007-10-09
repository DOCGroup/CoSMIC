// $Id$

//
// CUTS_Component_Registry_Node
//
CUTS_INLINE
CUTS_Component_Registry_Node::CUTS_Component_Registry_Node (void)
: info_ (reinterpret_cast <size_t> (this)),
  delete_ (false)
{

}

//
// ~CUTS_Component_Registry_Node
//
CUTS_INLINE
CUTS_Component_Registry_Node::~CUTS_Component_Registry_Node (void)
{

}
