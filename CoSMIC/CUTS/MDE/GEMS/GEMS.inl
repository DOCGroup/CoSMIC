// $Id$

namespace GEMS
{
  //===========================================================================
  /*
   * Model_Manager
   */
  //===========================================================================

  CUTS_INLINE
  Connection * Model_Manager::
  get_connection (GEMSServer::EntityRecord & rec)
  {
    return this->get_connection (this->get_id (rec));
  }

  CUTS_INLINE
  Model * Model_Manager::get_model (GEMSServer::EntityRecord & rec)
  {
    return this->get_model (this->get_id (rec));
  }

  CUTS_INLINE
  const char * Model_Manager::get_role (GEMSServer::EntityRecord & rec)
  {
    return rec.predicate.in () + 5;   /* bypass the self_ */
  }

  CUTS_INLINE
  size_t Model_Manager::get_id (GEMSServer::EntityRecord & rec)
  {
    return ACE_OS::atoi (rec.params[0].in ());
  }

  CUTS_INLINE
  int Model_Manager::is_parameter_list (const char * param)
  {
    return param[0] == '[' ? 1 : 0;
  }

  CUTS_INLINE
  int Model_Manager::is_string_value (const char * param)
  {
    return param[0] == '\'' ? 1 : 0;
  }

  //===========================================================================
  /*
   * Model
   */
  //===========================================================================

  CUTS_INLINE
  size_t Model::id (void) const
  {
    return this->id_;
  }

  CUTS_INLINE
  const std::string & Model::type (void) const
  {
    return this->type_;
  }

  CUTS_INLINE
  Model * Model::parent (void) const
  {
    return this->parent_;
  }

  CUTS_INLINE
  Model_Set & Model::children (void)
  {
    return this->children_;
  }

  CUTS_INLINE
  std::string Model::role (const std::string & role)
  {
    return this->roles_[role];
  }

  CUTS_INLINE
  Model::Role_Map & Model::roles (void)
  {
    return this->roles_;
  }

  //===========================================================================
  /*
   * Connection
   */
  //===========================================================================

  CUTS_INLINE
  Model * Connection::source (void) const
  {
    return this->source_;
  }

  CUTS_INLINE
  Model * Connection::target (void) const
  {
    return this->target_;
  }
}
