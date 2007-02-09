// $Id$

#include "GEMS.h"

#if !defined (__CUTS_INLINE__)
#include "GEMS.inl"
#endif

#include "orbsvcs/orbsvcs/CosNamingC.h"
#include <algorithm>
#include <iostream>
#include <sstream>

namespace GEMS
{
  //
  // stringify
  //
  std::string stringify (const std::string & str)
  {
    std::string tempstr (1, '\'');
    tempstr += str + '\'';
    return tempstr;
  }

  //
  // destringify
  //
  std::string destringify (const std::string & str)
  {
    size_t length = str.length ();

    if (str[0] == '\'' && str[length - 1] == '\'')
      return str.substr (1, length - 2);
    else
      return str;
  }

  //===========================================================================
  /*
   * Model
   */
  //===========================================================================

  //
  // create
  //
  Model * Model::create (GEMS::Model * parent, const std::string & type)
  {
    // Create a new model.
    size_t id = GEMS::Model_Manager::instance ()->next_id ();
    GEMS::Model * model = new GEMS::Model (id);

    // Set the model's type and parent, then add the model to
    // the parent's children.
    model->type_ = type;
    model->parent_ = parent;
    parent->children_.insert (model);

    // Resize the <changes_> collection to take account for
    // the two new additions to the knowledge base.
    size_t length = Model_Manager::instance ()->changes_.length ();
    Model_Manager::instance ()->changes_.length (length + 2);

    char idstr[7];
    GEMSServer::EntityRecord entity;
    entity.op = GEMSServer::Insert;
    entity.params.length (2);
    entity.params[0] = ::CORBA::string_dup (ACE_OS::itoa (model->id (), idstr, 10));

    // Add the new model type to the knowledge base.
    entity.predicate = ::CORBA::string_dup ("self_type");
    entity.params[1] = ::CORBA::string_dup (type.c_str ());
    Model_Manager::instance ()->changes_[length] = entity;

    // Add the parent for the model and add to the knowledge base.
    entity.predicate = ::CORBA::string_dup ("self_parent");
    entity.params[1] = ::CORBA::string_dup (ACE_OS::itoa (parent->id (), idstr, 10));
    Model_Manager::instance ()->changes_[length + 1] = entity;

    return model;
  }

  //
  // Model
  //
  Model::Model (size_t id)
    : id_ (id),
      parent_ (0)
  {

  }

  //
  // ~Model
  //
  Model::~Model (void)
  {

  }

  //
  // children
  //
  Model_Set Model::children (const std::string & type)
  {
    Model_Set children;

    for (Model_Set::iterator iter = this->children_.begin ();
         iter != this->children_.end ();
         iter ++)
    {
      if ((*iter)->type () == type)
        children.insert (*iter);
    }

    return children;
  }

  //
  // role
  //
  void Model::role (const std::string & role,
                    const std::string & value)
  {
    this->roles_[role] = value;

    std::string predicate ("self_");
    predicate.append (role);

    ::GEMSServer::EntityRecord rec;
    rec.op = ::GEMSServer::Insert;
    rec.predicate = ::CORBA::string_dup (predicate.c_str ());

    char idstr[7];

    rec.params.length (2);
    rec.params[0] = ::CORBA::string_dup (ACE_OS::itoa (this->id_, idstr, 10));
    rec.params[1] = ::CORBA::string_dup (stringify (value).c_str ());

    // Resize the <changes_> collection.
    ::CORBA::ULong length = Model_Manager::instance ()->changes_.length ();
    Model_Manager::instance ()->changes_.length (length + 1);
    Model_Manager::instance ()->changes_[length] = rec;
  }

  //===========================================================================
  /*
   * Connection
   */
  //===========================================================================

  //
  // Connection
  //
  Connection::Connection (size_t id)
    : Model (id),
      target_ (0),
      source_ (0)
  {

  }

  //
  // Connection
  //
  Connection::~Connection (void)
  {

  }

  //
  // target
  //
  Model * Connection::target (Model * model)
  {
    // Save the current target.
    Model * prev_target = this->target_i (model);

    // TODO: Update the model with the new target.

    // Return the previous target.
    return prev_target;
  }

  //
  // target_i
  //
  Model * Connection::target_i (Model * model)
  {
    if (this->target_ != model)
    {
      std::swap (this->target_, model);

      // Remove previous target from the children collection.
      if (model)
        this->children_.erase (model);

      // Save the new target in the children collection.
      if (this->target_)
        this->children_.insert (this->target_);
    }

    // Return the previous target.
    return model;
  }

  //
  // source
  //
  Model * Connection::source (Model * model)
  {
    // Set the new source model.
    Model * prev_source = this->source_i (model);

    // TODO: Update the model with the new source.

    // Return the previous source.
    return prev_source;
  }

  //
  // source_i
  //
  Model * Connection::source_i (Model * model)
  {
    if (this->source_ != model)
    {
      // Save the new source element.
      std::swap (this->source_, model);

      // Remove previous source from the children collection.
      if (model)
        this->children_.erase (model);

      // Store the new source in the children collection.
      if (this->target_)
        this->children_.insert (this->target_);
    }

    // Return the previous source.
    return model;
  }

  //===========================================================================
  /*
   * Model_Manager
   */
  //===========================================================================

  //
  // instance_
  //
  Model_Manager * Model_Manager::instance_ = 0;

  //
  // instance
  //
  Model_Manager * Model_Manager::instance (void)
  {
    if (Model_Manager::instance_ == 0)
      Model_Manager::instance_ = new Model_Manager ();

    return Model_Manager::instance_;
  }

  //
  // close_singleton
  //
  void Model_Manager::close_singleton (void)
  {
    if (Model_Manager::instance_ != 0)
    {
      delete Model_Manager::instance_;
      Model_Manager::instance_ = 0;
    }
  }

  //
  // Model_Manager
  //
  Model_Manager::Model_Manager (void)
    : root_ (0),
      next_id_ (0)
  {

  }

  //
  // ~Model_Manager
  //
  Model_Manager::~Model_Manager (void)
  {
    for (Model_Map::iterator iter = this->models_.begin ();
         iter != this->models_.end ();
         iter ++)
    {
      delete iter->second;
    }

    for (Connection_Map::iterator iter = this->conns_.begin ();
         iter != this->conns_.end ();
         iter ++)
    {
      delete iter->second;
    }
  }

  //
  // next_id
  //
  size_t Model_Manager::next_id (void)
  {
    return this->next_id_ ++;
  }

  //
  // load_from_string
  //
  int Model_Manager::load_from_string (::CORBA::ORB_ptr orb,
                                       const ACE_CString & str)
  {
    try
    {
      // Try to conver the string to an object.
      ::CORBA::Object_var obj = orb->string_to_object (str.c_str ());

      // If we do have an object, we continue with the loading
      // process. Otherwise, we just fail through and return an
      // error value.
      if (!::CORBA::is_nil (obj.in ()))
        return this->load_from_object (obj.in ());

      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_string): failed to convert string "
                  "to an object\n"));
    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_string): %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_string): caught unknown "
                  "exception\n"));
    }

    return -1;
  }

  //
  // load_from_orb
  //
  int Model_Manager::load_from_init_ref (::CORBA::ORB_ptr orb)
  {
    try
    {
      // Get the initial reference to the GEMS model.
      ::CORBA::Object_var obj =
        orb->resolve_initial_references ("GEMS");

      return this->load_from_object (obj.in ());
    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_orb): %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_orb): caught unknown "
                  "exception\n"));
    }

    return -1;
  }

  //
  // load_from_naming_service
  //
  int Model_Manager::load_from_naming_service (::CORBA::ORB_ptr orb)
  {
    try
    {
      ::CORBA::Object_var name_service =
        orb->resolve_initial_references ("NameService");

      ::CosNaming::NamingContext_var ctx =
        ::CosNaming::NamingContext::_narrow (name_service.in ());

      if (::CORBA::is_nil (ctx.in ()))
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                           "*** error: object is not a naming service\n"),
                           -1);
      }

      // Construct the name for GEMS (i.e., GEMS/Model).
      ::CosNaming::Name name (2);
      name.length (2);
      name[0].id = ::CORBA::string_dup ("GEMS");
      name[1].id = ::CORBA::string_dup ("Model");

      // Try to resolve the object from the nameing service.
      ::CORBA::Object_var obj = ctx->resolve (name);
      return this->load_from_object (obj.in ());
    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_naming_service): %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_naming_service): caught unknown "
                  "exception\n"));
    }

    return -1;
  }

  //
  // load_from_object
  //
  int Model_Manager::load_from_object (::CORBA::Object_ptr obj)
  {
    try
    {
      // Resolve the GEMS model from the generic object.
      this->gems_model_ = ::GEMSServer::Model::_narrow (obj);

      if (::CORBA::is_nil (this->gems_model_.in ()))
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                          "*** error [gems2picml]: resolved object is not a "
                          "GEMS server\n"),
                          -1);
      }

      return this->build_i ();
    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_object): %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (load_from_object): caught unknown "
                  "exception\n"));
    }

    return -1;
  }

  //
  // build
  //
  int Model_Manager::build (::GEMSServer::Model_ptr gems_model)
  {
    this->gems_model_ = ::GEMSServer::Model::_duplicate (gems_model);
    return this->build_i ();
  }

  //
  // build_i
  //
  int Model_Manager::build_i ()
  {
    try
    {
      // Right now, there isn't a predefined max value for the
      // number of records that can be returned.
      GEMSServer::EntityRecordSeq_var recs;
      this->gems_model_->getEntities (0, 5000, recs);
      ::CORBA::ULong length = recs->length ();

      for (::CORBA::ULong i = 0; i < length; i ++)
      {
        GEMSServer::EntityRecord & rec = recs[i];

        // Get the role and the id of the record.
        const char * role = this->get_role (rec);
        size_t id = this->get_id (rec);

        if (this->is_string_value (rec.params[1].in ()) == 0)
        {
          // The value of the second parameter is an id of a existing
          // element, or an type element AFAIK. So this means we need
          // the distinguish between the role and its value so that we
          // can handle it properly.

          if (ACE_OS::strcmp (role, "type") == 0)
          {
            Connection_Map::iterator c_iter = this->conns_.find (id);

            if (c_iter != this->conns_.end ())
            {
              c_iter->second->type_ = rec.params[1].in ();
            }
            else
            {
              GEMS::Model * model = this->get_model (id);
              model->type_ = rec.params[1].in ();
            }
          }
          else if (ACE_OS::strcmp (role, "parent") == 0)
          {
            // Get the current model.
            GEMS::Model * model = this->get_model (id);

            // Get the parent model for this record.
            size_t parent_id = ACE_OS::atoi (rec.params[1].in ());
            GEMS::Model * parent = this->get_model (parent_id);

            // Update the models parent and the parent's children.
            model->parent_ = parent;
            parent->children_.insert (model);
          }
          else if (ACE_OS::strcmp (role, "id") == 0)
          {
            // We are going to use the id role to determine the next valid
            // id. This will ensure we are always greater than current ids
            // of the elements.
            size_t id = ACE_OS::atoi (rec.params[0].in ());

            if (id > this->next_id_)
              this->next_id_ = id + 1;
          }
          else if (ACE_OS::strcmp (role, "source") == 0)
          {
            size_t source_id =  ACE_OS::atoi (rec.params[1].in ());

            Connection * conn = this->get_connection (rec);
            conn->source_i (this->get_model (source_id));
          }
          else if (ACE_OS::strcmp (role, "target") == 0)
          {
            size_t target_id = ACE_OS::atoi (rec.params[1].in ());

            Connection * conn = this->get_connection (rec);
            conn->target_i (this->get_model (target_id));
          }
          else
          {
            // This is the fallback for unknown non-stringified roles.
            GEMS::Model * model = this->get_model (id) ;
            model->roles_[role] = rec.params[1].in ();
          }
        }
        else
        {
          // Since it is a stringified value, we can just store
          // it into the role database for the model.
          GEMS::Model * model = this->get_model (id) ;
          model->roles_[role] = destringify (rec.params[1].in ());
        }

      }

      return 0;
    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (build): %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (build): caught unknown exception\n"));
    }
    return -1;
  }

  //
  // apply_changes
  //
  int Model_Manager::apply_changes (void)
  {
    try
    {
      this->gems_model_->applyChanges (this->changes_);
      this->changes_.length (0);
      return 0;
    }
    catch (const ::GEMSServer::ModelUpdateException & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (apply_changes): %s\n",
                  ex.reason.in ()));
    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (apply_changes): %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (apply_changes): caught unknown exception\n"));
    }

    return -1;
  }

  //
  // get_model
  //
  Model * Model_Manager::get_model (size_t id)
  {
    Model_Map::iterator iter = this->models_.find (id);

    Model * model = 0;
    if (iter != this->models_.end ())
    {
      // Save the already existing model.
      model = iter->second;
    }
    else
    {
      // Create a new model and insert it into the map.
      model = new GEMS::Model (id);
      this->models_.insert (Model_Map::value_type (id, model));
    }

    return model;
  }

  //
  // dump
  //
  void Model_Manager::dump (void) const
  {
    ACE_DEBUG ((LM_DEBUG,
                "Number of models: %d\n"
                "Root Element: %d\n",
                this->models_.size (),
                this->root ("deploymentplan")->id ()));

    for (Model_Map::const_iterator iter = this->models_.begin ();
         iter != this->models_.end ();
         iter ++)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Model ID: %d\n  Type -> %s\n",
                  iter->second->id (),
                  iter->second->type ().c_str ()));

      for (GEMS::Model::Role_Map::iterator r_iter = iter->second->roles ().begin ();
           r_iter != iter->second->roles ().end ();
           r_iter ++)
      {
        ACE_DEBUG ((LM_DEBUG,
                    "  %s -> %s\n",
                    r_iter->first.c_str (),
                    r_iter->second.c_str ()));
      }

      if (iter->second->parent ())
      {
        ACE_DEBUG ((LM_DEBUG, "   Parent     -> %d\n",
                    iter->second->parent ()->id ()));
      }
      else
      {
        ACE_DEBUG ((LM_DEBUG, "   Parent     -> <none>\n"));
      }

      ACE_DEBUG ((LM_DEBUG,
                  "   Children   -> "));

      for (Model_Set::const_iterator m_iter = iter->second->children ().begin ();
           m_iter != iter->second->children ().end ();
           m_iter ++)
      {
        std::cout << (*m_iter)->id () << " ";
      }

      std::cout << std::endl;
    }
  }

  //
  // root
  //
  Model * Model_Manager::root (const std::string & type) const
  {
    // Check for the root element.
    if (this->root_ != 0 && this->root_->type () == type)
      return this->root_;

    // Since we do not have it, we need to locate it. We are
    // going to store it as well for later use.
    for (Model_Map::const_iterator iter = this->models_.begin ();
         iter != this->models_.end ();
         iter ++)
    {
      if (iter->second->parent () == 0 &&
          iter->second->type () == type)
      {
        this->root_ = iter->second;
        break;
      }
    }

    return this->root_;
  }

  //
  // models
  //
  Model_Set Model_Manager::models (const std::string & type) const
  {
    Model_Set models;

    for (Model_Map::const_iterator iter = this->models_.begin ();
         iter != this->models_.end ();
         iter ++)
    {
      if (iter->second->type () == type)
        models.insert (iter->second);
    }

    return models;
  }

  //
  // connections
  //
  Connection_Set Model_Manager::connections (const std::string & type) const
  {
    Connection_Set conns;

    for (Connection_Map::const_iterator iter = this->conns_.begin ();
         iter != this->conns_.end ();
         iter ++)
    {
      if (iter->second->type () == type)
        conns.insert (iter->second);
    }

    return conns;
  }

  //
  // get_connection
  //
  Connection * Model_Manager::get_connection (size_t id)
  {
    Connection * conn = 0;
    Connection_Map::iterator iter = this->conns_.find (id);

    if (iter != this->conns_.end ())
    {
      // Yes, we found the connection!!
      conn = iter->second;
    }
    else
    {
      // So, we haven't seen this connection before!?!?
      conn = new GEMS::Connection (id);
      this->conns_.insert (Connection_Map::value_type (id, conn));

      // Ok, there could be a chance that we mistaked this for a
      // model when indeed it is a connection.
      Model_Map::iterator iter = this->models_.find (id);

      if (iter != this->models_.end ())
      {
        // There could even be a chance that we have already seen
        // it's type as well.
        conn->type_ = iter->second->type_;

        delete iter->second;
        this->models_.erase (iter);
      }
    }

    return conn;
  }

  //
  // run_constraint_solver
  //
  int Model_Manager::
  run_constraint_solver (const std::string & operation,
                         bool apply_changes)
  {
    try
    {
      // Construct the entity record to invoke constraint solver. We have
      // to make sure to stringify the <operation> for GEMS.
      ::GEMSServer::EntityRecord entity;
      entity.op = GEMSServer::Insert;
      entity.predicate = ::CORBA::string_dup ("trigger");

      entity.params.length (1);
      entity.params[0] =
        ::CORBA::string_dup (stringify (operation).c_str ());

      if (apply_changes)
      {
        // Place the <entity> with the rest of the <changes_> so we only
        // have to make one call. This is the batch operation pattern.
        ::CORBA::ULong length = this->changes_.length ();
        this->changes_.length (length + 1);
        this->changes_[length] = entity;

        return this->apply_changes ();
      }
      else
      {
        // Construct a temporary change log that will consist of
        // only the trigger statement.
        ::GEMSServer::EntityRecordSeq records (1);
        records.length (1);
        records[0] = entity;

        this->gems_model_->applyChanges (records);
        return 0;
      }
    }
    catch (const GEMSServer::ModelUpdateException & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (run_constraint_solver): %s\n",
                  ex.reason.in ()));
    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (apply_changes): %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (run_constraint_solver): caught unknown "
                  "exception\n"));
    }

    return -1;
  }
}
