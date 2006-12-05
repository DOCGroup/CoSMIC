// -*- C++ -*-

//=============================================================================
/**
 * @file      GEMS.h
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
#include <string>
#include <set>
#include <map>

namespace GEMS
{
  GEMS_CRN_Export
  std::string & destringify (std::string & str);

  GEMS_CRN_Export
  std::string & stringify (std::string & str);

  // Forward decl.
  class Model;

  class Connection;

  // Forward decl.
  class Model_Manager;

  typedef std::set <Model *> Model_Set;

  typedef std::set <Connection *> Connection_Set;

  //===========================================================================
  /**
   * @class Model
   */
  //===========================================================================

  class GEMS_CRN_Export Model
  {
    /// Friend decl.
    friend class Model_Manager;

  public:
    typedef std::map <std::string, std::string> Role_Map;

    static Model * create (Model * parent, const std::string & type);

    Model (size_t id);

    virtual ~Model (void);

    size_t id (void) const;

    const std::string & type (void) const;

    Model * parent (void) const;

    Model_Set & children (void);

    Model_Set children (const std::string & type);

    void role (const std::string & role,
               const std::string & value);

    std::string role (const std::string & role);

    Role_Map & roles (void);

  private:
    /// Id of the model.
    size_t id_;

    /// Annotation for the model.
    std::string type_;

    Model * parent_;

    Model_Set children_;

    Role_Map roles_;
  };

  //===========================================================================
  /**
   * @class Connection
   */
  //===========================================================================

  class GEMS_CRN_Export Connection
  {
    friend class Model_Manager;

  public:
    Connection (size_t id);

    virtual ~Connection (void);

    Model * source (void);

    Model * target (void);

    size_t id (void) const;

    const std::string & type (void) const;

  private:
    size_t id_;

    Model * source_;

    Model * target_;

    std::string type_;
  };

  //===========================================================================
  /**
   * @class Model_Manager
   */
  //===========================================================================

  class GEMS_CRN_Export Model_Manager
  {
  public:
    friend class Model;
    friend class Connection;

    int build (GEMSServer::Model_ptr model);

    void dump (void) const;

    Model * root (void) const;

    Connection_Set connections (const std::string & type);

    static Model_Manager * instance (void);

    static void close_singleton (void);

    int apply_changes (void);

  private:
    Model_Manager (void);

    ~Model_Manager (void);

    size_t next_id (void);

    const char * get_role (GEMSServer::EntityRecord & rec);

    size_t get_id (GEMSServer::EntityRecord & rec);

    Model * get_model (GEMSServer::EntityRecord & rec);

    Model * get_model (size_t id);

    Connection * get_connection (GEMSServer::EntityRecord & rec);

    Connection * get_connection (size_t id);

    int is_parameter_list (const char * param);

    int is_string_value (const char * param);

    static Model_Manager * instance_;

    typedef std::map <size_t, GEMS::Model *> Model_Map;

    Model_Map models_;

    typedef std::map <size_t, GEMS::Connection *> Connection_Map;

    Connection_Map conns_;

    mutable Model * root_;

    GEMSServer::Model_var gems_model_;

    GEMSServer::EntityRecordSeq changes_;

    size_t next_id_;
  };
}

#if defined (__CUTS_INLINE__)
#include "GEMS.inl"
#endif

#endif  // !defined _GEMS_H_
