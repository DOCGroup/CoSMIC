// $Id$

#if !defined (__CUTS_INLINE__)
#include "Port_Manager_T.inl"
#endif

//
// CUTS_UDM_Port_Manager_T
//
template <typename PORTTYPE>
CUTS_UDM_Port_Manager_T <PORTTYPE>::
CUTS_UDM_Port_Manager_T (void)
{

}

//
// ~CUTS_UDM_Port_Manager_T
//
template <typename PORTTYPE>
CUTS_UDM_Port_Manager_T <PORTTYPE>::
~CUTS_UDM_Port_Manager_T (void)
{

}

//
// insert
//
template <typename PORTTYPE>
bool CUTS_UDM_Port_Manager_T <PORTTYPE>::
insert (PORTTYPE & port)
{
  // Get the scoped names of the port type.
  std::string scoped_name;
  this->get_scoped_typename_i (port, scoped_name);

  // Save the new information.
  return this->insert_i (port, scoped_name);
}

//
// insert_i
//
template <typename PORTTYPE>
bool CUTS_UDM_Port_Manager_T <PORTTYPE>::
insert_i (PORTTYPE & port, std::string & scoped_name)
{
  std::pair <Port_Map::iterator, bool> result =
    this->ports_.insert (Port_Map::value_type (port.name (), scoped_name));

  return result.first != this->ports_.end ();
}

//
// get_scoped_typename
//
template <typename PORTTYPE>
bool CUTS_UDM_Port_Manager_T <PORTTYPE>::
get_scoped_typename (const std::string & portname,
                     std::string & scoped_name)
{
  std::string scoped_typename;
  Port_Map::iterator iter = this->ports_.find (portname);

  if (iter != this->ports_.end ())
  {
    scoped_name = iter->second;
    return true;
  }
  else
    return false;
}

//
// get_scoped_typename_i
//
template <typename PORTTYPE>
void CUTS_UDM_Port_Manager_T <PORTTYPE>::
get_scoped_typename_i (PORTTYPE & port, std::string & dest)
{
  PICML::MgaObject object = PICML::MgaObject::Cast (port.ref ());
  PICML::MgaObject parent = PICML::MgaObject::Cast (object.parent ());

  dest = object.name ();

  while ((std::string)parent.type ().name () !=
         (std::string)PICML::File::meta.name ())
  {
    dest.insert (0, "::");
    dest.insert (0, parent.name ());

    parent = PICML::MgaObject::Cast (parent.parent ());
  }
}
