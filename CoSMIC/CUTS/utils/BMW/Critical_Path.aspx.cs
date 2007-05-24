// $Id$

//=============================================================================
/**
 * @file    Critical_Path.aspx.cs
 */
//=============================================================================

using System;
using System.Collections;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

using MySql.Data;
using MySql.Data.MySqlClient;

namespace CUTS
{
  public partial class Critical_Path : System.Web.UI.Page
  {
    static private string TABLE_NAME = "critical_path";

    static private string PATH_ELEMENTS_TABLE = "critical_path_elements";

    static private string INSTANCE_TABLE = "component_instances";

    private MySqlConnection conn =
      new MySqlConnection (ConfigurationManager.AppSettings["MySQL"]);

    /**
     * Callback method for when the page is loading.
     *
     * @param[in]         sender          Sender of the event.
     * @param[in]         e               Event arguments.
     */
    private void Page_Load(object sender, System.EventArgs e)
    {
      try
      {
        if (!Page.IsPostBack)
        {
          // Open the connection and create an adapter.
          this.conn.Open ();
          MySqlDataAdapter adapter = Critical_Path.create_adapter (conn);

          DataSet ds = new DataSet ();
          // Create a new dataset for the data.
          adapter.Fill (ds, Critical_Path.TABLE_NAME);

          // Setup the <auto_increment> column;
          DataTable table = ds.Tables[Critical_Path.TABLE_NAME];
          DataColumn path_id_column = table.Columns["path_id"];
          path_id_column.AutoIncrement = true;

          // Calculate the next value of the path_id.
          Object result = table.Compute ("MAX(path_id)", "");
          int seed = result != System.DBNull.Value ? (int) result + 1 : 1;
          path_id_column.AutoIncrementSeed = seed;
          path_id_column.AutoIncrementStep = 1;

          // Setup the primary keys for this table.
          DataColumn [] primary_key = new DataColumn [1];
          primary_key[0] = path_id_column;
          table.PrimaryKey = primary_key;

          // Determine if there is a request to display a path.
          string p_query = Request.QueryString["p"];

          if (p_query != null)
          {
            // Get the path to query.
            long path_id = Int32.Parse (p_query);
            Session["path_id"] = path_id;

            // Fill the adapter w/ the path element data.
            MySqlDataAdapter path_adapter = create_path_element_adapter (conn, path_id);
            path_adapter.Fill (ds, PATH_ELEMENTS_TABLE);

            table = ds.Tables[PATH_ELEMENTS_TABLE];
            primary_key = new DataColumn[1];
            primary_key[0] = table.Columns["path_order"];
            table.PrimaryKey = primary_key;

            // Fill the dataset with the instance data.
            MySqlDataAdapter inst_adapter = Critical_Path.create_instance_adapter (conn);
            inst_adapter.Fill (ds, Critical_Path.INSTANCE_TABLE);

            // Show the controls in the area.
            this.element_panel_.Visible = true;
          }
          else
            this.element_panel_.Visible = false;

          // Update the view.
          UpdateView (ds);
          Session["dataset"] = ds;
        }
      }
      catch (MySqlException ex)
      {
        this.message_.ForeColor = Color.Red;
        this.message_.Text = "ODBC exception: " + ex.Message;
      }
      catch (Exception ex)
      {
        this.message_.ForeColor = Color.Red;
        this.message_.Text = "Unknown exception: " + ex.Message;
      }
      finally
      {
        if (conn.State == ConnectionState.Open)
        {
          conn.Close ();
        }
      }
    }

    protected void button_create_path (Object sender, EventArgs e)
    {
      try
      {
        // Get the cached dataset and create a new row.
        DataSet ds = (DataSet) Session["dataset"];
        DataRow dr = ds.Tables[Critical_Path.TABLE_NAME].NewRow ();

        // Insert the data into the new row.
        dr["path_name"] = this.path_name_.Text;
        dr["deadline"] = Int32.Parse (this.deadline_.Text);
        ds.Tables[Critical_Path.TABLE_NAME].Rows.Add (dr);

        // Update the view.
        UpdateView (ds);
        Session["dataset"] = ds;
      }
      catch (MySqlException ex)
      {
        this.message_.Text = "ODBC exception: " + ex.Message;
      }
      catch (Exception ex)
      {
        this.message_.Text = "Unknown exception: " + ex.Message;
      }
      finally
      {

      }
    }

    protected void save_paths_onclick (Object sender, EventArgs e)
    {
      try
      {
        // Open the connection and get an adapter to the the
        // "critical_path" table.
        this.conn.Open ();
        MySqlDataAdapter adapter = Critical_Path.create_adapter (conn);

        DataSet ds = (DataSet) Session["dataset"];
        int result = adapter.Update (ds, Critical_Path.TABLE_NAME);
        this.conn.Close ();

        this.message_.ForeColor = Color.Black;
        this.message_.Text = "Successfully updated " + result + " row(s)...";
      }
      catch (MySqlException ex)
      {
        this.message_.ForeColor = Color.Red;
        this.message_.Text = "ODBC exception: " + ex.Message;
      }
      catch (Exception ex)
      {
        this.message_.ForeColor = Color.Red;
        this.message_.Text = "Unknown exception: " + ex.Message;
      }
      finally
      {
        if (conn.State == ConnectionState.Open)
        {
          conn.Close ();
        }
      }
    }

    protected void path_elements_OnItemCreated(Object sender,
                                               DataGridItemEventArgs e)
    {
      ListItemType type = e.Item.ItemType;

      switch (e.Item.ItemType)
      {
        case ListItemType.Item:
        case ListItemType.AlternatingItem:
          e.Item.Cells[3].Text = "my name";

          break;

        case ListItemType.Pager:
          // Update the pager so that it spans the entire grid.
          Label page_label = new Label();
          page_label.Text = "Page(s): ";

          TableCell pager = (TableCell)e.Item.Controls[0];
          pager.Controls.AddAt(0, page_label);
          break;
      }
    }

    protected void button_delete_path (Object sender, EventArgs e)
    {

    }

    protected void PathElement_Insert (Object sender, EventArgs e)
    {
      // Get the dataset for the session.
      DataSet ds = (DataSet) Session["dataset"];

      // Get the path table from the dataset and create a new row.
      DataTable table = ds.Tables[Critical_Path.PATH_ELEMENTS_TABLE];
      DataRow dr = table.NewRow ();

      // Initialize all the elements in the row. This will mean setting
      // the id and text of all the cells.
      dr["path_id"] = Session["path_id"];
      dr["path_order"] = Int32.Parse (this.order_.Text);

      dr["component_name"] = this.instance_.SelectedItem.Text;
      dr["instance"] = Int32.Parse (this.instance_.SelectedValue);

      dr["src"] = this.src_.SelectedValue;
      dr["srcname"] = this.src_.SelectedItem.Text;

      dr["dst"] = this.dst_.SelectedValue;
      dr["dstname"] = this.dst_.SelectedItem.Text;

      // Insert the row at the end of6 the list.
      table.Rows.Add (dr);

      UpdateView (ds);
      Session["dataset"] = ds;
    }

    protected void PathElement_Commit (Object sender, EventArgs e)
    {
      // Get the dataset for the session.
      DataSet ds = (DataSet) Session["dataset"];

      try
      {
        // Update the information in the database.
        MySqlDataAdapter adapter = create_path_element_adapter (conn, (long)Session["path_id"]);
        adapter.Update (ds, Critical_Path.PATH_ELEMENTS_TABLE);

        // Refresh the view.
        UpdateView (ds);
      }
      catch (MySqlException ex)
      {
        this.message_.ForeColor = Color.Red;
        this.message_.Text = "ODBC exception: " + ex.Message;
      }
      catch (Exception ex)
      {
        this.message_.ForeColor = Color.Red;
        this.message_.Text = "Unknown exception: " + ex.Message;
      }
    }

    /**
     * Helper method that updates the view of the webpage. This includes
     * updating the table that contains the critical paths, and the table
     * that contains the critical path elements.
     *
     * @param[in]       ds          The source dataset.
     */
    private void UpdateView (DataSet ds)
    {
      // Bind the critical path table.
      if (ds.Tables.Contains (TABLE_NAME))
      {
        this.critical_paths_.DataSource = ds.Tables[TABLE_NAME].DefaultView;
        this.critical_paths_.DataBind ();
      }

      if (this.element_panel_.Visible)
      {
        // Bind the path elements table.
        if (ds.Tables.Contains (PATH_ELEMENTS_TABLE))
        {
          this.path_elements_.DataSource = ds.Tables[PATH_ELEMENTS_TABLE].DefaultView;
          this.path_elements_.DataBind ();

          // Calculate the next index for the user. We do not want to rely on
          // auto increment in this case since the path_order can consist of
          // non-consecutive numbers.
          Object result = ds.Tables[PATH_ELEMENTS_TABLE].Compute ("MAX(path_order)", "");

          if (result != System.DBNull.Value)
            this.order_.Text = String.Format("{0}", (int)result + 1);
          else
            this.order_.Text = "1";
        }

        if (ds.Tables.Contains (INSTANCE_TABLE))
        {
          this.instance_.DataSource = ds.Tables[INSTANCE_TABLE].DefaultView;
          this.instance_.DataBind ();
        }
      }
    }

    static MySqlDataAdapter create_adapter (MySqlConnection conn)
    {
      // Create a new adapter with the default select command.
      MySqlDataAdapter adapter =
        new MySqlDataAdapter ("SELECT * FROM critical_path ORDER BY path_name",
                             conn);

      // Create the insert command for the table.
      System.Text.StringBuilder insert_sql = new System.Text.StringBuilder ();
      insert_sql.Append ("INSERT INTO critical_path (path_id, path_name, deadline) ");
      insert_sql.Append ("VALUES (?path_id, ?path_name, ?deadline)");

      MySqlCommand insert_command = conn.CreateCommand ();
      insert_command.CommandText = insert_sql.ToString ();
      insert_command.Parameters.Add ("?path_id", MySqlDbType.Int32, 0, "path_id");
      insert_command.Parameters.Add ("?path_name", MySqlDbType.VarChar, 32, "path_name");
      insert_command.Parameters.Add ("?deadline", MySqlDbType.Int32, 0, "deadline");
      adapter.InsertCommand = insert_command;

      return adapter;
    }

    static MySqlDataAdapter create_path_element_adapter (MySqlConnection conn,
                                                         long path_id)
    {
      System.Text.StringBuilder select_sql = new System.Text.StringBuilder ();
      select_sql.Append ("SELECT path_id, path_order, instance, component_name, src, srcname, dst, dstname FROM (");
      select_sql.Append ("SELECT path_id, path_order, instance, src, srcname, dst, portname AS dstname FROM (");
      select_sql.Append ("SELECT path_id, path_order, instance, src, portname AS srcname, dst ");
      select_sql.Append ("FROM critical_path_elements, portnames WHERE portid = src) AS tmp1, ");
      select_sql.Append ("portnames WHERE portid = dst) AS tmp2, component_instances ");
      select_sql.Append ("WHERE (path_id = ?path_id AND instance = component_id) ");
      select_sql.Append ("ORDER BY path_order;");

      MySqlCommand select_command = new MySqlCommand (select_sql.ToString (), conn);
      select_command.Parameters.Add ("?path_id", path_id);

      // Create a new adapter with the default select command.
      MySqlDataAdapter adapter = new MySqlDataAdapter (select_command);

      // Create the insert command for the table.
      System.Text.StringBuilder insert_sql = new System.Text.StringBuilder ();
      insert_sql.Append ("INSERT INTO critical_path_elements (path_id, path_order, ");
      insert_sql.Append ("instance, src, dst) VALUES (?path_id, ?path_order, ");
      insert_sql.Append ("?instance, ?src, ?dst)");

      MySqlCommand insert_command = conn.CreateCommand ();
      insert_command.CommandText = insert_sql.ToString ();
      insert_command.Parameters.Add ("?path_id", MySqlDbType.Int32, 0, "path_id");
      insert_command.Parameters.Add ("?path_order", MySqlDbType.Int32, 0, "path_order");
      insert_command.Parameters.Add ("?instance", MySqlDbType.Int32, 0, "instance");
      insert_command.Parameters.Add ("?src", MySqlDbType.Int32, 0, "src");
      insert_command.Parameters.Add ("?dst", MySqlDbType.Int32, 0, "dst");
      adapter.InsertCommand = insert_command;

      System.Text.StringBuilder delete_sql = new System.Text.StringBuilder();
      delete_sql.Append ("DELETE FROM critical_path_elements ");
      delete_sql.Append ("WHERE path_id = ?path_id AND path_order = ?path_order");

      MySqlCommand delete_command = conn.CreateCommand();
      delete_command.CommandText = delete_sql.ToString ();
      delete_command.Parameters.Add ("?path_id", MySqlDbType.Int32, 0, "path_id");
      delete_command.Parameters.Add ("?path_order", MySqlDbType.Int32, 0, "path_order");
      adapter.DeleteCommand = delete_command;

      return adapter;
    }

    static private MySqlDataAdapter create_instance_adapter (MySqlConnection conn)
    {
      return
        new MySqlDataAdapter ("SELECT * FROM component_instances ORDER BY component_name",
                              conn);
    }

    /**
     * Handler for the OnSelectedIndexChanged for the instance_ object. When
     * this handler is invoked, it updates the source and sinks for the
     * selected component.
     */
    protected void instance_OnSelectedIndexChanged (Object sender, EventArgs e)
    {
      this.conn.Open();
      MySqlCommand command = this.conn.CreateCommand();

      // Get the type id of the selected component.
      command.CommandText = "SELECT typeid FROM component_instances WHERE component_id = ?cid";
      command.Parameters.Add("?cid", this.instance_.SelectedValue);
      System.Int32 typeid = (System.Int32)command.ExecuteScalar();

      // Get the source and sinks for the component's type.
      command.CommandText = "SELECT sinks, sources FROM component_types WHERE typeid = ?typeid";
      command.Parameters.Add("?typeid", typeid);

      DataSet ds = new DataSet();
      MySqlDataAdapter adapter = new MySqlDataAdapter(command);
      adapter.Fill(ds, "ports");

      command.CommandText =
        String.Format ("SELECT * FROM portnames WHERE portid IN ({0}) ORDER BY portname",
                       ds.Tables["ports"].Rows[0]["sinks"]);
      adapter.Fill(ds, "sinks");

      command.CommandText =
        String.Format("SELECT * FROM portnames WHERE portid IN ({0}) ORDER BY portname",
                       ds.Tables["ports"].Rows[0]["sources"]);
      adapter.Fill(ds, "sources");

      this.src_.DataSource = ds.Tables["sinks"];
      this.src_.DataBind();

      this.dst_.DataSource = ds.Tables["sources"];
      this.dst_.DataBind();
    }

    /**
     * Default handler for the oncommand event.
     *
     * @param[in]       sender        Sender of the event.
     * @param[in]       e             Arguments for the event.
     */
    protected void OnCommand (Object sender, CommandEventArgs e)
    {
      if (e.CommandName == "DeletePathElement")
      {
        DataSet ds = (DataSet)Session["dataset"];
        DataTable dt = ds.Tables[PATH_ELEMENTS_TABLE];
        DataRow row = dt.Rows.Find(e.CommandArgument);

        if (row != null)
        {
          // Delete the row and update the view.
          row.Delete ();
          this.UpdateView(ds);

          // Save the dataset.
          Session["dataset"] = ds;
        }
      }
    }

    #region Web Form Designer generated code
    override protected void OnInit(EventArgs e)
    {
      InitializeComponent();
      base.OnInit(e);
    }

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.Load += new System.EventHandler(this.Page_Load);

    }
    #endregion
  }
}
