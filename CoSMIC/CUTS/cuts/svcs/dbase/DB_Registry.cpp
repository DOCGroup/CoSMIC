// $Id$

#include "DB_Registry.h"

#if !defined (__CUTS_INLINE__)
#include "DB_Registry.inl"
#endif

#include "cuts/utils/ODBC/ODBC_Connection.h"
#include "cuts/utils/ODBC/ODBC_Query.h"
#include "cuts/utils/ODBC/ODBC_Record.h"
#include "cuts/utils/ODBC/ODBC_Parameter.h"
#include "cuts/utils/ODBC/ODBC_Types.h"
#include "ace/Log_Msg.h"

#define MAX_VARCHAR_LENGTH 256

//
// CUTS_DB_Registry
//
CUTS_DB_Registry::CUTS_DB_Registry (void)
{
  // Right now we are binding directly to ODBC. In the future we would
  // like to ask the <CUTS_DB_Manager> for a connection object.
  ODBC_Connection * conn = 0;
  ACE_NEW (conn, ODBC_Connection ());

  this->conn_.reset (conn);
}

//
// ~CUTS_DB_Registry
//
CUTS_DB_Registry::~CUTS_DB_Registry (void)
{
  this->disconnect ();
}

//
// connect
//
bool CUTS_DB_Registry::connect (const char * username,
                               const char * password,
                               const char * server,
                               long port)
{
  // Remove the existing connection.
  this->disconnect ();

  try
  {
    // Establish a new connection.
    this->conn_->connect (username, password, server, port);
    return this->conn_->is_connected ();
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (connect): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (connect): caught unknown exception\n"));
  }

  return false;
}

//
// disconnect
//
void CUTS_DB_Registry::disconnect (void)
{
  try
  {
    if (this->conn_->is_connected ())
      this->conn_->disconnect ();
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (disconnect): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (disconnect): caught unknown exception\n"));
  }
}

//
// register_component
//
bool CUTS_DB_Registry::
register_component (const char * inst,
                    const char * type,
                    long * instid)
{
  // Get the <type_id> for the component. We do not care if the
  // operation succeeds or fails.
  long type_id = 0;

  if (!this->get_component_typeid (type, &type_id))
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (register_component): "
                       "failed to locate type; not registering component\n"),
                       false);
  }

  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());
  if (query.get () == 0)
    return false;

  try
  {
    // Prepare a SQL statement and its parameters.
    const char * query_stmt =
      "SELECT component_id FROM component_instances WHERE component_name = ?";

    query->prepare (query_stmt);
    query->parameter (0)->bind (const_cast <char *> (inst), 0);

    CUTS_DB_Record * record = query->execute ();

    if (record->count () != 0)
    {
      // Get the component id so that we can update its type information.
      // We always update its type information just in case its type has
      // somehow been modified.
      long component_id;

      record->fetch ();
      record->get_data (1, component_id);

      // Update the <typeid> for the component just in case.
      query_stmt =
        "UPDATE component_instances SET typeid = ? WHERE component_id = ?";

      query->prepare (query_stmt);
      query->parameter (0)->bind (&type_id);
      query->parameter (1)->bind (&component_id);

      // Execute the query and then save the id if requested.
      query->execute_no_record ();

      if (instid != 0)
        *instid = component_id;
    }
    else
    {
      // Create a new id since the component does not exist.
      query_stmt =
        "INSERT INTO component_instances (component_name, typeid) VALUES (?, ?)";

      query->prepare (query_stmt);
      query->parameter (1)->bind (&type_id);

      // Execute the statement and if the caller wants the id of
      // the id, then we need to retrieve it.
      query->execute_no_record ();

      if (instid != 0)
        *instid = query->last_insert_id ();
    }

    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (register_component): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (register_component): caught unknown exception\n"));
  }

  return false;
}



//
// register_host
//
bool CUTS_DB_Registry::register_host (const char * ipaddr,
                                     const char * hostname,
                                     long * hostid)
{
  // Before we continue, we should check to see if the host has already
  // been registered. This will prevent any exceptions from occuring
  // because of duplicate data.

  if (this->get_hostid_by_ipaddr (ipaddr, hostid))
    return true;

  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());
  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * str_stmt =
      "INSERT INTO ipaddr_host_map (ipaddr, hostname) VALUES (?, ?)";
    query->prepare (str_stmt);

    // Bind the parameters for the statement then execute the
    // prepared statement.
    query->parameter (0)->bind (const_cast <char *> (ipaddr), 0);
    query->parameter (1)->bind (const_cast <char *> (hostname), 0);
    query->execute ();

    if (hostid != 0)
      *hostid = query->last_insert_id ();

    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (register_host): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (register_host): caught unknown exception\n"));
  }

  return false;
}

//
// get_hostid_by_ipaddr
//
bool CUTS_DB_Registry::
get_hostid_by_ipaddr (const char * ipaddr, long * hostid)
{
  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());
  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * str_stmt =
      "SELECT hostid FROM ipaddr_host_map WHERE ipaddr = ?";

    query->prepare (str_stmt);
    query->parameter (0)->bind (const_cast <char *> (ipaddr), 0);

    // Get the results from executing the query. If the query returns
    // nothing then this will throw an exception.
    CUTS_DB_Record * record = query->execute ();

    if (record->count () == 0)
      return false;

    // We need to store the host id if the caller requests.
    if (hostid != 0)
    {
      record->fetch ();
      record->get_data (1, *hostid);
    }

    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (get_hostid_by_ipaddr): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (get_hostid_by_ipaddr): caught unknown exception\n"));
  }
  return false;
}


//
// get_hostid_by_hostname
//
bool CUTS_DB_Registry::
get_hostid_by_hostname (const char * hostname, long * hostid)
{
  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());
  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * str_stmt =
      "SELECT hostid FROM ipaddr_host_map WHERE hostname = ?";

    query->prepare (str_stmt);
    query->parameter (0)->bind (const_cast <char *> (hostname), 0);

    // Get the results from executing the query. If the query returns
    // nothing then this will throw an exception.
    CUTS_DB_Record * record = query->execute ();

    if (record->count () == 0)
      return false;

    // We need to store the host id if the caller requests.
    if (hostid != 0)
    {
      record->fetch ();
      record->get_data (1, *hostid);
    }

    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (get_hostid_by_hostname): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (get_hostid_by_hostname): caught unknown exception\n"));
  }
  return false;
}

//
// get_instance_id
//
bool CUTS_DB_Registry::
get_instance_id (const char * inst, long * instid)
{
  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());

  if (query.get () == 0)
    return false;

  try
  {
    // Prepare the statement to select the component_id of the component
    // with the specified name.
    const char * query_stmt =
      "SELECT component_id FROM component_instances WHERE component_name = ?";

    query->prepare (query_stmt);
    query->parameter (0)->bind (const_cast <char *> (inst), 0);

    // Execute the statement and get the returned id.
    CUTS_DB_Record * record = query->execute ();
    size_t count = record->count ();

    if (count > 0 && instid != 0)
    {
      record->fetch ();
      record->get_data (1, *instid);
    }

    return count > 0;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (get_instance_id): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (get_instance_id): caught unknown exception\n"));
  }

  return false;
}

//
// create_query
//
ODBC_Query * CUTS_DB_Registry::create_query (void)
{
  if (!this->conn_->is_connected ())
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (create_query): "
                       "no database connection exist\n"),
                       0);
  }

  return this->conn_->create_odbc_query ();
}

//
// get_component_type_id
//
bool CUTS_DB_Registry::get_component_typeid (const char * type,
                                            long * type_id,
                                            bool auto_register)
{
  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());

  if (query.get () == 0)
    return false;

  try
  {
    // Prepare a SQL query for execution.
    const char * query_stmt =
      "SELECT typeid FROM component_types WHERE typename = ?";
    query->prepare (query_stmt);
    query->parameter (0)->bind (const_cast <char *> (type), 0);

    // Execute the query.
    CUTS_DB_Record * record = query->execute ();

    if (record->count () > 0)
    {
      if (type_id != 0)
      {
        record->fetch ();
        record->get_data (1, *type_id);
      }

      return true;
    }
    else if (auto_register)
    {
      // Insert the <typename> into the database.
      query_stmt = "INSERT INTO component_types (typename) VALUES (?)";
      query->prepare (query_stmt);
      query->execute_no_record ();

      // Get the LAST_INSERT_ID () and store it in <type_id>.
      if (type_id != 0)
        *type_id = query->last_insert_id ();

      return true;
    }
    else
      return false;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (get_component_typeid): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (get_component_typeid): caught unknown exception\n"));
  }

  return false;
}

//
// set_test_uuid
//
bool CUTS_DB_Registry::set_test_uuid (long test, const char * uuid)
{
  ACE_Auto_Ptr <ODBC_Query> query (this->create_query ());

  if (query.get () == 0)
    return false;

  try
  {
    // Prepare a SQL query for execution.
    const char * query_stmt =
      "UPDATE tests SET test_uuid = ? WHERE test_number = ?";

    query->prepare (query_stmt);
    query->parameter (0)->bind (const_cast <char *> (uuid), 0);
    query->parameter (1)->bind (&test);

    // Execute the query.
    query->execute_no_record ();
    return true;
  }
  catch (CUTS_DB_Exception & ex)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (set_test_uuid): %s\n",
                ex.message ().c_str ()));
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (set_test_uuid): caught unknown exception\n"));
  }

  return false;
}

