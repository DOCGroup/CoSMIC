// -*- C++ -*-

//=============================================================================
/**
 * @file      GEMS.h
 *
 * @brief     Defines classes related to interacting with GEMS via its
 *            CORBA remoting implementation.
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GEMS_H_
#define _GEMS_H_

#include "GEMS_CRN_export.h"
#include "GEMSServerC.h"
#include "tao/ORB.h"

// STL headers
#include <string>
#include <set>
#include <map>

//=============================================================================
/**
 * @namespace GEMS
 *
 * Defines elements that are specific to using the GEMS CORBA remoting
 * features.
 */
//=============================================================================

namespace GEMS
{
  // Forward decl.
  class Model;

  // Forward decl.
  class Connection;

  // Forward decl.
  class Model_Manager;

  /// Type definition for a collection of models.
  typedef std::set <Model *> Model_Set;

  /// Type definition for a collection of connections.
  typedef std::set <Connection *> Connection_Set;

  //===========================================================================
  /**
   * @class Model
   *
   * Implementation of a GEMS model element. The model element is the
   * bese type of all elements in GEMS.
   */
  //===========================================================================

  class GEMS_CRN_Export Model
  {
    // Friend decl.
    friend class Model_Manager;

  public:
    /// Type definition for mapping roles to their respective values.
    typedef std::map <std::string, std::string> Role_Map;

    /**
     * Create a new model element.
     *
     * @param[in]       parent      The parent of the model.
     * @param[in]       type        The model's type.
     * @return          The newly created model, or 0 if the creation
     *                  fails.
     *
     * @todo            Throw an exception in the event of a failure.
     */
    static Model * create (Model * parent, const std::string & type);

    /// Destructor.
    virtual ~Model (void);

    /**
     * Get the id of the element. The id will be a unique identifier
     * with respect to all the other element contained in the model.
     *
     * @return          Unique id of the element.
     */
    size_t id (void) const;

    /**
     * Get the type name of the element. This name will correspond
     * to a type in the metamodel.
     *
     * @param[in]       The type name of the element.
     */
    const std::string & type (void) const;

    /**
     * Get the parent of the element. If there is no parent, then the
     * element is a <i>root</i> element. There should never be a case
     * when the return value is 0 and the element is not a <i>root</i>
     * element.
     *
     * @return          Pointer to the parent.
     */
    Model * parent (void) const;

    /**
     * Get the children of the element. This version of the method
     * returns all the children regarless of their types. If you need
     * to retrieve all the children of a specific type, then use the
     * children (const std::string & type) method.
     *
     * @return          The children of the element.
     */
    Model_Set & children (void);

    /**
     * Get the children of a the element. This method is more selective
     * because it return only the chilren of a specific type. If you
     * need to get all the children regardless of their type, then use
     * the children () method.
     *
     * @
     */
    Model_Set children (const std::string & type);

    /**
     * Update the role's value of the element. If the role is not
     * valid for the element type, then nothing happens.
     *
     * @param[in]       role        The role to update.
     * @param[in]       value       The new value of the role.
     */
    void role (const std::string & role,
               const std::string & value);

    /**
     * Get the value of a role.
     *
     * @return          The value of a role.
     */
    std::string role (const std::string & role);

    /**
     * Get all the roles for the element.
     *
     * @return          The collection of roles.
     */
    Role_Map & roles (void);

  protected:
    /**
     * Initializing constructor. This will creates a model and assign
     * it the \id as its unique identifier. Currently, the client has
     * to guarantee the \id is unique. Otherwise, it will overwrite
     * an existing item.
     *
     * @param[in]       id        Unique id of the model.
     */
    Model (size_t id);

    /// Id of the model.
    size_t id_;

    /// Annotation for the model.
    std::string type_;

    /// The parent of the model.
    Model * parent_;

    /// The children of the model.
    Model_Set children_;

    /// The roles for the model.
    Role_Map roles_;

  private:
    // prevent the following operations
    Model (const Model &);
    const Model & operator = (const Model &);
  };

  //===========================================================================
  /**
   * @class Connection
   *
   * Implementation of a GEMS connection element. The connection is a
   * specialization of a GEMS::Model element. We made this design choice
   * because a connection has all the same elements of a model. A connection,
   * however, can only have 2 children, i.e., a source and destination model.
   * You can explicitly access the source and destination method explicitly
   * via the source () and target () methods, respectively.
   */
  //===========================================================================

  class GEMS_CRN_Export Connection : public GEMS::Model
  {
    // Friend decl.
    friend class Model_Manager;

  public:
    /// Destructor.
    virtual ~Connection (void);

    /**
     * Get the source model of the connection.
     *
     * @return      Pointer to the source model.
     */
    Model * source (void) const;

    /**
     * Set the source model of the connection. This will replace
     * the existing source model and return it to client.
     *
     * @param[in]       source      The source model.
     * @return          The previous source element.
     */
    Model * source (Model * source);

    /**
     * Get the target model of the connection.
     *
     * @return      Pointer to the target model.
     */
    Model * target (void) const;

    /**
     * Set the target model of the connection. This will replace
     * the existing target model and return it to client.
     *
     * @param[in]       target      The target model.
     * @return          The previous target element.
     */
    Model * target (Model * target);

  protected:
    /**
     * Initializing constructor. This will creates a connection and assign
     * it the \id as its unique identifier. Currently, the client has
     * to guarantee the \id is unique. Otherwise, it will overwrite
     * an existing item.
     *
     * @param[in]       id        Unique id of the connection.
     */
    Connection (size_t id);

  private:
    /// Helper method that set the new source, but does not generate
    /// the update predicates.
    Model * source_i (Model * source);

    /// Helper method that set the new target, but does not generate
    /// the update predicates.
    Model * target_i (Model * target);

    /// The target element of the connection.
    Model * target_;

    /// The source element of the connection.
    Model * source_;

    // prevent the following operations
    Connection (const Connection & conn);
    const Connection & operator = (const Connection &);
  };

  //===========================================================================
  /**
   * @class Model_Manager
   */
  //===========================================================================

  class GEMS_CRN_Export Model_Manager
  {
    // TODO: determine if friend is necessary.
    friend class Model;

    // TODO: determine if friend is necessary.
    friend class Connection;

  public:
    /**
     * Get the singleton instance of the manager.
     *
     * @return      Pointer to the singleton.
     */
    static Model_Manager * instance (void);

    /// Close the singleton instance and release all resources.
    static void close_singleton (void);

    /**
     * Build a in-memory model of the GEMS model using the CORBA
     * remoting interface.
     *
     * @param[in]     model       The source GEMS model.
     */
    int build (::GEMSServer::Model_ptr model);

    /**
     * Load the model manager using the version of GEMS located
     * in the naming service.
     *
     * @param[in]     orb         Pointer to the CORBA orb.
     * @retval        0           Successfully loaded GEMS.
     * @retval        -1          Failed to load GEMS.
     */
    int load_from_init_ref (::CORBA::ORB_ptr orb);

    int load_from_naming_service (::CORBA::ORB_ptr orb);

    int load_from_object (::CORBA::Object_ptr obj);

    int load_from_string (::CORBA::ORB_ptr orb,
                          const ACE_CString & str);

    /**
     * Apply the current changes back to the GEMS model.
     *
     * @retval      0     Success applying all changes.
     * @retval      -1    Failure applying one or more changes.
     */
    int apply_changes (void);

    /**
     * Get the next available id for an element.
     *
     * @return            Unique id for an element.
     */
    size_t next_id (void);

    /// Dump the contents of the manager.
    void dump (void) const;

    /**
     * Get the root element of the model.
     *
     * @return      Pointer to the root element.
     */
    Model * root (const std::string & type) const;

    /**
     * Get all the models in the project of a specific \a type.
     *
     * @param[in]   type      The type of connection.
     * @return      Collection of models.
     */
    Model_Set models (const std::string & type) const;

    /**
     * Get all the connections in the project of a
     * specific type.
     *
     * @param[in]   type      The type of connection.
     * @return      Collection of connections.
     */
    Connection_Set connections (const std::string & type) const;

    /**
     * Run the constraint solver. This will execute the specified
     * Prolog \a operation in GEMS on the current model. If there
     * are any changes present on the CORBA side, they can be saved
     * to the model before executing \a operation.
     *
     * @param[in]       operation       The constaint method to execute.
     * @param[in]       apply_changes   Apply current changes to the model
     *                                  before executing \a operation.
     * @retval          0               \a operation successful.
     * @retval          -1              \a operation failed.
     */
    int run_constraint_solver (const std::string & operation,
                               bool apply_changes = true);

  private:
    /// Default constructor.
    Model_Manager (void);

    /// Destructor.
    ~Model_Manager (void);

    const char * get_role (GEMSServer::EntityRecord & rec);

    size_t get_id (GEMSServer::EntityRecord & rec);

    Model * get_model (GEMSServer::EntityRecord & rec);

    Model * get_model (size_t id);

    Connection * get_connection (GEMSServer::EntityRecord & rec);

    Connection * get_connection (size_t id);

    int is_parameter_list (const char * param);

    int is_string_value (const char * param);

    int build_i (void);

    static Model_Manager * instance_;

    typedef std::map <size_t, GEMS::Model *> Model_Map;

    Model_Map models_;

    typedef std::map <size_t, GEMS::Connection *> Connection_Map;

    Connection_Map conns_;

    mutable Model * root_;

    ::GEMSServer::Model_var gems_model_;

    ::GEMSServer::EntityRecordSeq changes_;

    size_t next_id_;
  };
}

#define GEMS_MODEL_MANAGER() \
  GEMS::Model_Manager::instance ()

#if defined (__CUTS_INLINE__)
#include "GEMS.inl"
#endif

#endif  // !defined _GEMS_H_
