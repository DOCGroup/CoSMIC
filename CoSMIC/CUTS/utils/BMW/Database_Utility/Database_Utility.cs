// -*- C# -*-

//=============================================================================
/**
 * @file      CUTS_Database_Utility
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

using System;
using System.Collections;
using System.Data;
using System.Data.Odbc;
using System.Runtime.InteropServices;

using MySql.Data.MySqlClient;
using MySql.Data.Types;

//=============================================================================
/**
 * @struct ExectionTime
 *
 * @brief Structure for returning the execution times used be methods
 * of the web service.
 */
//=============================================================================

public struct ExecutionTime
{
  public long samples;

  public long recentmin;
  public long recentmax;
  public long recentavg;

  public long absmin;
  public long absmax;

  public long avgmin;
  public long avgavg;
  public long avgmax;

  public DateTime lastsample;
}

//=============================================================================
/**
 * @class CUTS_Path_Element
 *
 * @brief Database utility component for accessing the CUTS database
 * from a .NET application.
 */
//=============================================================================

struct CUTS_Path_Element
{
  public CUTS_Path_Element(long component, string src, string dst)
  {
    this.component_ = component;
    this.src_ = src;
    this.dst_ = dst;
  }

  public long component_;
  public string src_;
  public string dst_;
}

//=============================================================================
/**
 * @class CUTS_Database_Utility
 *
 * @brief Database utility component for accessing the CUTS database
 * from a .NET application.
 */
//=============================================================================

public class CUTS_Database_Utility
{
  /**
   * Default constructor.
   */
  public CUTS_Database_Utility()
  {
    this.conn_ = new MySqlConnection();
  }

#if _DEBUG
  [DllImport("CUTS_CORBA_Utilityd")]
#else
  [DllImport("CUTS_CORBA_Utility")]
#endif
  public static extern bool print_message(string filename,
                                          string message);

  /**
   * Initializing constructor. This constructor will open a
   * database connection using the specified connection string.
   *
   * @param[in]     connstr       Connection string.
   */
  public CUTS_Database_Utility(string connstr)
  {
    this.conn_ = new MySqlConnection();
    this.conn_.ConnectionString = connstr;
    this.conn_.Open();
  }

  /**
   * Connect using the specified connection string.
   *
   * @param[in]     connstr     Connection string.
   */
  public void connect(string connstr)
  {
    // If a connection already exist, close it.
    if (this.conn_.State == ConnectionState.Open)
    {
      this.conn_.Close();
    }

    // Save the connection string and open the connection.
    this.conn_.ConnectionString = connstr;
    this.conn_.Open();
  }

  /**
   * Disconnect from the database.
   */
  public void disconnect()
  {
    if (this.conn_.State == ConnectionState.Open)
    {
      this.conn_.Close();
    }
  }

  /**
   * Get the id of a path by name.
   *
   * @param[in]     pathname      Name of the path.
   */
  public System.Int32 path_id_by_name(string pathname)
  {
    MySqlCommand command = this.conn_.CreateCommand();
    command.CommandText =
      "SELECT path_id FROM critical_path WHERE path_name = ?path_name";
    command.Parameters.Add("?path_name", pathname);

    object result = command.ExecuteScalar();

    if (result == null)
    {
      throw new ApplicationException(pathname + " path does not exist");
    }

    return (System.Int32)result;
  }

  /**
   * Get the critical paths as a dataset. The dataset is returned
   * in a table named 'critical_paths'.
   * 
   * @param[in]     dataset     Reference to target dataset.
   */
  public void get_critical_paths(ref DataSet dataset)
  {
    MySqlCommand command = this.conn_.CreateCommand();
    command.CommandText = 
      "SELECT path_id, path_name FROM critical_path ORDER BY path_name";

    // Create an adapter w/ the following select command.
    MySqlDataAdapter adapter = new MySqlDataAdapter(command);

    // Create a new dataset and fill it using the adapter.
    adapter.Fill(dataset, "critical_path");
  }

  /**
   * Get the collection times for a specific test.
   * 
   * @param[in]       test        The id of the test.
   * @param[out]      dataset     Reference to target dataset.
   */
  public void get_collection_times(Int32 test,
                                   ref DataSet dataset)
  {
    MySqlParameter p1 = new MySqlParameter("?test", MySqlDbType.Int32);
    p1.Direction = ParameterDirection.Input;
    p1.Value = test;

    System.Text.StringBuilder builder = new System.Text.StringBuilder();
    builder.Append("SELECT DISTINCT collection_time FROM execution_time ");
    builder.Append("WHERE (test_number = ?test)");

    MySqlCommand command = this.conn_.CreateCommand();
    command.CommandText = builder.ToString();
    command.Parameters.Add(p1);

    MySqlDataAdapter adapter = new MySqlDataAdapter(command);
    adapter.Fill(dataset, "collection_time");
  }

  /**
   * Get the execution time for the given path.
   *
   * @param[in]     test          Test number with data.
   * @param[in]     pathname      Name of the path.
   */
  public ExecutionTime path_execution_time(int test,
                                           string pathname)
  {
    ExecutionTime et = new ExecutionTime();

    // Create the command and get the id of the path.
    MySqlCommand command = this.conn_.CreateCommand();
    command.CommandText = "SELECT path_id FROM critical_path WHERE " +
                          "path_name = ?pathname";
    command.Parameters.Add("?pathname", pathname);

    object result = command.ExecuteScalar();

    if (result == null)
    {
      throw new ApplicationException (pathname + " path does not exist");
    }

    System.Int32 path_id = (System.Int32)result;
    ArrayList critical_path = new ArrayList ();

    // Get all the elements in the critical path.
    command.CommandText = "CALL select_path (?pathid)";
    command.Parameters.Add("?pathid", path_id);

    MySqlDataReader reader = command.ExecuteReader();

    // Extract all the elements in the collection then close
    // the reader.
    while (reader.Read())
    {
      CUTS_Path_Element element =
        new CUTS_Path_Element(reader.GetInt32(1),
                              reader.GetString(2),
                              reader.GetString(3));
      critical_path.Add(element);
    }

    reader.Close();

    // Get the path information from the database.
    command.CommandText = "CALL select_path_execution_times (?test, ?pathid)";
    command.Parameters.Add("?test", test);

    reader = command.ExecuteReader();

    // Bypass all the empty metrics in the collection and store
    // the first DateTime value as the <collection_time>.
    while (reader.Read() && reader.GetValue(0) == DBNull.Value);
    long best_time = 0, average_time = 0, worse_time = 0;
    bool done = false;
    DateTime collection_time;

    do
    {
      bool create_point = false;

      // Get the collection_date, component, src and dst port and create
      // a path element out of it.
      collection_time = reader.GetDateTime(0);

      CUTS_Path_Element element =
        new CUTS_Path_Element(reader.GetUInt32(1),
                              reader.GetString(3),
                              reader.GetString(4));

      // Locate the following metrics in the collection.
      try
      {
        bool valid = true;
        int index = critical_path.IndexOf(element);

        if (index != 0)
        {
          // Check if the sender of this metric is indeed the previous
          // instance in the critical path for this element.
          CUTS_Path_Element prev_element =
            (CUTS_Path_Element)critical_path[index - 1];

          if (prev_element.component_ != reader.GetInt32(2))
          {
            valid = false;
          }
        }

        // If this is a valid metric then we need to add it's information
        // to the current execution times for this collection time.
        if (valid)
        {
          best_time += reader.GetInt32(7);
          average_time += reader.GetInt32(8);
          worse_time += reader.GetInt32(9);
        }
      }
      catch (Exception)
      {

      }

      // Determine if this is the last record in the listing. If it
      // is not then we need to see if the next record is part of this
      // collection period. If this is the last record then we have
      // to create a new point regardless.
      if (reader.Read())
      {
        if (collection_time != reader.GetDateTime(0))
        {
          create_point = true;
        }
      }
      else
      {
        create_point = true;
        done = true;
      }

      // Create a new collection point in the <et> object.
      if (create_point)
      {
        if (et.samples != 0)
        {
          if (best_time < et.absmin)
          {
            et.absmin = best_time;
          }
          if (worse_time > et.absmax)
          {
            et.absmax = worse_time;
          }
        }
        else
        {
          et.absmin = best_time;
          et.absmax = worse_time;
        }

        et.avgmin += best_time;
        et.avgavg += average_time;
        et.avgmax += worse_time;
        ++ et.samples;

        // Reset the time values.
        if (!done)
        {
          best_time = average_time = worse_time = 0;
        }
      }
    } while (!done);

    // Close the reader.
    reader.Close();

    // Populate the <et> data structure with the appropriate
    // information for the client based on the parsed results.
    if (et.samples != 0)
    {
      et.recentmin = best_time;
      et.recentmax = worse_time;
      et.recentavg = average_time;

      et.avgmin /= et.samples;
      et.avgavg /= et.samples;
      et.avgmax /= et.samples;

      et.lastsample = collection_time;
    }

    return et;
  }

  /**
   * Delete a specific test from the database.
   * 
   * @param[in]   test      The id of the test.
   */
  public void delete_test(System.Int32 test)
  {
    MySqlCommand command = this.conn_.CreateCommand();
    command.CommandText = "DELETE FROM tests WHERE test_number = ?test";
    command.Parameters.Add("?test", test);
    command.ExecuteNonQuery();
  }

  /**
   * Get all the test from the database. This returns the test in
   * the \a test table of the \ds argument.
   * 
   * @param[out]        ds      The target database.
   */
  public void get_all_test(ref DataSet ds)
  {
    // Create the command for the query.
    MySqlCommand command = this.conn_.CreateCommand();
    command.CommandText = "SELECT * FROM tests ORDER BY test_number";

    // Create a new adapter to ease the creation of the dataset.
    MySqlDataAdapter adapter = new MySqlDataAdapter (command);
    adapter.Fill(ds, "tests");
  }
  /// Connection object.
  private MySqlConnection conn_;
}
