#include "GEMS.h"

#if !defined (__CUTS_INLINE__)
#include "GEMS.inl"
#endif

#include <iostream>
#include <sstream>

namespace GEMS
{
  std::string & stringify (std::string & str)
  {
    str.insert (0, '\'', 1);
    return str.append (1, '\'');
  }

  std::string & destringify (std::string & str)
  {
    size_t length = str.length ();

    if (str[0] == '\'' && str[length - 1] == '\'')
      str.erase (length - 1, 1).erase (0, 1);

    return str;
  }

  //===========================================================================
  /*
   * Model
   */
  //===========================================================================

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
    size_t new_length = Model_Manager::instance ()->changes_.length ();

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
    ACE_DEBUG ((LM_DEBUG,
                "model %d has parent %d\n",
                model->id (),
                parent->id ()));

    entity.params[1] = ::CORBA::string_dup (ACE_OS::itoa (parent->id (), idstr, 10));
    Model_Manager::instance ()->changes_[length] = entity;

    return model;
  }

  Model::Model (size_t id)
    : id_ (id),
      parent_ (0)
  {

  }

  Model::~Model (void)
  {

  }

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

  void Model::role (const std::string & role,
                    const std::string & value)
  {
    char idstr[7];
    this->roles_[role] = value;

    std::string predicate ("self_");
    predicate.append (role);

    GEMSServer::EntityRecord rec;
    rec.op = GEMSServer::Insert;
    rec.predicate = ::CORBA::string_dup (predicate.c_str ());

    rec.params.length (2);
    rec.params[0] = ::CORBA::string_dup (ACE_OS::itoa (this->id_, idstr, 10));
    rec.params[1] = ::CORBA::string_dup (value.c_str ());

    // Resize the <changes_> collection.
    size_t length = Model_Manager::instance ()->changes_.length ();
    Model_Manager::instance ()->changes_.length (length + 1);
    Model_Manager::instance ()->changes_[length] = rec;
  }

  //===========================================================================
  /*
   * Connection
   */
  //===========================================================================

  Connection::Connection (size_t id)
    : id_ (id),
      target_ (0),
      source_ (0)
  {

  }

  Connection::~Connection (void)
  {

  }

  //===========================================================================
  /*
   * Model_Manager
   */
  //===========================================================================

  Model_Manager * Model_Manager::instance_ = 0;

  Model_Manager * Model_Manager::instance (void)
  {
    if (Model_Manager::instance_ == 0)
      Model_Manager::instance_ = new Model_Manager ();
    return Model_Manager::instance_;
  }

  void Model_Manager::close_singleton (void)
  {
    if (Model_Manager::instance_ != 0)
    {
      delete Model_Manager::instance_;
      Model_Manager::instance_ = 0;
    }
  }

  Model_Manager::Model_Manager (void)
    : root_ (0),
      next_id_ (0)
  {

  }

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

  size_t Model_Manager::next_id (void)
  {
    return this->next_id_ ++;
  }

  int Model_Manager::build (GEMSServer::Model_ptr gems_model)
  {
    this->gems_model_ =
      GEMSServer::Model::_duplicate (gems_model);

    try
    {
      GEMSServer::EntityRecordSeq_var recs;
      this->gems_model_->getEntities (0, 3000, recs);
      size_t length = recs->length ();

      for (size_t i = 0; i < length; i ++)
      {
        GEMSServer::EntityRecord & rec = recs[i];

        // Get the role and the id of the record.
        const char * role = this->get_role (rec);
        size_t id = this->get_id (rec);

        if (this->is_parameter_list (rec.params[1].in ()) == 0)
        {
          // Ok, we aren't working with a record that has a parameter
          // list. This means that we have a record where the second
          // parameter is either a string or an id.

          if (this->is_string_value (rec.params[1].in ()))
          {
            // Since it is a stringified value, we can just store
            // it into the role database for the model.
            GEMS::Model * model = this->get_model (rec);
            model->roles_[role] = rec.params[1].in ();
          }
          else
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
            else if (ACE_OS::strcmp (role, "id") == 0)
            {
              size_t id = ACE_OS::atoi (rec.params[0].in ());

              if (id > this->next_id_)
                this->next_id_ = id + 1;
            }
            else if (ACE_OS::strcmp (role, "source") == 0)
            {
              Connection * conn = this->get_connection (rec);

              conn->source_ =
                this->get_model (ACE_OS::atoi (rec.params[1].in ()));
            }
            else if (ACE_OS::strcmp (role, "target") == 0)
            {
              Connection * conn = this->get_connection (rec);

              conn->target_
                = this->get_model (ACE_OS::atoi (rec.params[1].in ()));
            }
          }
        }
        else if (ACE_OS::strcmp (role, "children") == 0)
        {
          // The only parameter list we are concerned with when building
          // the original model is children. For the time being, we can
          // just ignore all the other parameter list since they are really
          // specialization of this role, or connection roles.

          Model * parent = this->get_model (rec);

          std::istringstream istr (rec.params[1].in ());
          istr.ignore ();

          if (istr.peek () != ']')
          {
            // So we indeed have a parameter list and not an
            // empty list at our disposal.
            char ch;
            size_t id;

            do
            {
              // Get the next id in the parameter list. Then we need
              // to locate the model for that id.
              istr >> id >> ch;
              Model * child = this->get_model (id);

              // Update the children of the parent model and attach
              // the parant to the child model for walking the model.
              parent->children_.insert (child);
              child->parent_ = parent;
            } while (ch != ']');
          }
        }
      }

      return 0;
    }
    catch (const CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "CORBA exception: %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "caught unknown exception\n"));
    }
    return -1;
  }

  int Model_Manager::apply_changes (void)
  {
    try
    {
      this->gems_model_->applyChanges (this->changes_);
      this->changes_.length (0);
      return 0;
    }
    catch (...)
    {

    }

    return -1;
  }

  Model * Model_Manager::get_model (size_t id)
  {
    Model_Map::iterator iter = this->models_.find (id);

    Model * model = 0;
    if (iter != this->models_.end ())
      // Save the already existing model.
      model = iter->second;
    else
    {
      // Create a new model and insert it into the map.
      model = new GEMS::Model (id);
      this->models_.insert (Model_Map::value_type (id, model));
    }

    return model;
  }

  void Model_Manager::dump (void) const
  {
    ACE_DEBUG ((LM_DEBUG,
                "Number of models: %d\n\n",
                this->models_.size ()));

    for (Model_Map::const_iterator iter = this->models_.begin ();
         iter != this->models_.end ();
         iter ++)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Model ID: %d\n",
                  iter->second->id ()));

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

  Connection_Set Model_Manager::connections (const std::string & type)
  {
    Connection_Set conns;

    for (Connection_Map::iterator iter = this->conns_.begin ();
         iter != this->conns_.end ();
         iter ++)
    {
      if (iter->second->type () == type)
        conns.insert (iter->second);
    }

    return conns;
  }

  Model * Model_Manager::root (void) const
  {
    if (this->root_ != 0)
      return this->root_;

    for (Model_Map::const_iterator iter = this->models_.begin ();
        iter != this->models_.end ();
        iter ++)
    {
      if (iter->second->parent () == 0)
      {
        this->root_ = iter->second;
        break;
      }
    }

    return this->root_;
  }

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
}
