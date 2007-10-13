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
          this.InitializeCritialPaths();

          // Determine if there is a request to display a path.
          string p_query = Request.QueryString["p"];

          if (p_query != null)
          {
            // Get the path to query.
            long path_id = Int32.Parse (p_query);
            Session["path_id"] = path_id;

            // Update the name of the selected path.
            DataView paths = (DataView)this.critical_paths_.DataSource;
            DataRow[] rows = paths.Table.Select(String.Format("path_id = {0}", path_id));
            this.selected_path_.Text = rows[0]["path_name"].ToString() + " ";

            DataSet ds = new DataSet();

            // Fill the adapter w/ the path element data.
            MySqlDataAdapter path_adapter = this.CreatePathElementAdapter(conn, path_id);
            path_adapter.Fill (ds, PATH_ELEMENTS_TABLE);

            DataTable table = ds.Tables[PATH_ELEMENTS_TABLE];
            DataColumn []  primary_key = new DataColumn[1];
            primary_key[0] = table.Columns["path_order"];
            table.PrimaryKey = primary_key;

            // Fill the dataset with the instance data.
            MySqlDataAdapter inst_adapter = Critical_Path.create_instance_adapter (conn);
            inst_adapter.Fill (ds, Critical_Path.INSTANCE_TABLE);

            // Update the view.
            UpdateView(ds);
            Session["dataset"] = ds;
          }
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

    /**
     * Event handler for clicking the button to create a critical
     * path. The critical path is created by inserting a new record
     * into the database and then requesting the new information form
     * the database.
     *
     * @param[in]     sender        Sender of the event.
     * @param[in]     e             Event arguments.
     */
    protected void CreateCritcalPath (Object sender, EventArgs e)
    {
      try
      {
        // Create the SQL string for creating the critical path.
        System.Text.StringBuilder insert_sql = new System.Text.StringBuilder ();
        insert_sql.Append ("INSERT INTO critical_path (path_name, deadline) ");
        insert_sql.Append ("VALUES (?path_name, ?deadline)");

        // Open the connection.
        if (this.conn.State == ConnectionState.Closed)
          this.conn.Open();

        // Create the SQL command.
        MySqlCommand command = this.conn.CreateCommand();
        command.CommandText = insert_sql.ToString ();
        command.Parameters.AddWithValue("?path_name", this.path_name_.Text);
        command.Parameters.AddWithValue("?deadline", Int32.Parse(this.deadline_.Text));

        // Execute the command to create the critical path.
        command.ExecuteNonQuery();

        // Reinitialize the critical path table,
        this.InitializeCritialPaths();
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
        if (this.conn.State == ConnectionState.Open)
          this.conn.Close();
      }
    }

    /**
     * Helper method for initializing the critical paths table. This
     * method contacts the database and retrieve the latest information
     * about the registered critical paths.
     */
    private void InitializeCritialPaths()
    {
      MySqlCommand command = this.conn.CreateCommand();
      command.CommandText = "SELECT * FROM critical_path ORDER BY path_name";

      DataSet ds = new DataSet();
      MySqlDataAdapter adapter = new MySqlDataAdapter(command);
      adapter.Fill(ds, "critical_paths");

      this.critical_paths_.DataSource = ds.Tables["critical_paths"].DefaultView;
      this.critical_paths_.DataBind();
    }

    protected void path_elements_OnItemCreated(Object sender,
                                               DataGridItemEventArgs e)
    {
      ListItemType type = e.Item.ItemType;

      switch (e.Item.ItemType)
      {
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

      dr["instance"] = Int32.Parse (this.instance_.SelectedValue);
      dr["instance_name"] = this.instance_.SelectedItem.Text;

      dr["src"] = this.src_.SelectedValue;
      dr["src_portname"] = this.src_.SelectedItem.Text;

      dr["dst"] = this.dst_.SelectedValue;
      dr["dst_portname"] = this.dst_.SelectedItem.Text;

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
        long path_id = (long)Session["path_id"];
        MySqlDataAdapter adapter = this.CreatePathElementAdapter(conn, path_id);
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

    private MySqlDataAdapter CreatePathElementAdapter (MySqlConnection conn,
                                                       long path_id)
    {
      // SQL command for selecting the elements in the critical path
      // for the specified path.
      MySqlCommand select_command =
        new MySqlCommand ("CALL cuts.select_execution_path_elements_i(?path_id)", conn);

      select_command.Parameters.AddWithValue ("?path_id", path_id);
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
      command.Parameters.AddWithValue("?inst", this.instance_.SelectedValue);

      MySqlDataAdapter adapter = new MySqlDataAdapter(command);
      DataSet ds = new DataSet();

      // Get all the event sinks for the component.
      command.CommandText = "CALL cuts.select_component_portnames_i(?inst, 'sink')";
      adapter.Fill(ds, "sinks");

      // Get all the event sources for the component.
      command.CommandText = "CALL cuts.select_component_portnames_i(?inst, 'source')";
      adapter.Fill(ds, "sources");

      // Bind the different ports to their respective controls.
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

    /**
     * Callback method for selecting all the test on the
     * current page.
     *
     * @param[in]       e       Arguments for the event.
     */
    protected void ToggleDelete(object sender, System.EventArgs e)
    {
      // The sender of this event is a <CheckBox>
      CheckBox check = (CheckBox)sender;

      if (check != null)
        this.toggle_action_i(check.Checked);
    }

    /**
     * Helper method for toggling all the "action_" checkboxes
     * on the current page.
     *
     * @param[in]     state         Enable state for the item.
     */
    private void toggle_action_i(bool state)
    {
      foreach (DataGridItem item in this.path_elements_.Items)
      {
        CheckBox action = (CheckBox)item.FindControl("delete_");

        if (action != null)
          action.Checked = state;
      }
    }

    /**
     * Callback method for clicking the "Delete All" link.
     *
     * @param[in]       sender        Sender of the event.
     */
    protected void PathElement_Delete(object sender, System.EventArgs e)
    {
      // Get the dataset for the path elements.
      DataSet ds = (DataSet)Session["dataset"];

      if (ds == null)
        return;


      foreach (DataGridItem item in this.path_elements_.Items)
      {
        // Locate the <action_> control since it's the checkbox
        // that determines the action of the current test.
        CheckBox action = (CheckBox)item.FindControl("delete_");

        if (action != null && action.Checked)
        {
          object key = this.path_elements_.DataKeys[item.ItemIndex];
          DataRow row = ds.Tables[PATH_ELEMENTS_TABLE].Rows.Find(key);

          if (row != null)
            row.Delete();
        }
      }

      this.UpdateView(ds);
      Session["dataset"] = ds;
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
