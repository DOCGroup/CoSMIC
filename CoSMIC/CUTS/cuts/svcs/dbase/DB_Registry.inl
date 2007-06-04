// $Id$

//
// attach
//
CUTS_INLINE
void CUTS_DB_Registry::attach (CUTS_DB_Connection * conn)
{
  this->conn_ = conn;
}

//
// detach
//
CUTS_INLINE
void CUTS_DB_Registry::detach (void)
{
  this->conn_ = 0;
}

//
// is_attached
//
CUTS_INLINE
bool CUTS_DB_Registry::is_attached (void) const
{
  return this->conn_ != 0;
}

//
// register_component_type
//
CUTS_INLINE
bool CUTS_DB_Registry::
register_component_type (const CUTS_Component_Type & type)
{
  long type_id;
  return this->register_component_type (type, type_id);
}
