using System;
using System.Collections;
using System.Configuration;
using System.ComponentModel;
using System.Data;
using System.Data.Odbc;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace CUTS
{
  /// <summary>
  /// Summary description for _default.
  /// </summary>
  public partial class Test : System.Web.UI.Page
  {
    //
    // Page_Load
    //
    private void Page_Load (object sender, System.EventArgs e)
    {
      load_test_data ();
    }

    //
    // handle_on_item_command
    //
    protected void handle_on_item_command (Object sender, DataGridCommandEventArgs e)
    {
      if (e.CommandName == "delete")
      {
        OdbcConnection conn = new OdbcConnection(
          ConfigurationManager.AppSettings["ConnectionString"]);

        int test_number = (int)this.tests_.DataKeys[e.Item.ItemIndex];

        try
        {
          conn.Open();

          OdbcCommand command = conn.CreateCommand();
          command.CommandText = "DELETE FROM tests WHERE test_number = ?";
          OdbcParameter p1 = command.Parameters.Add("test_number", OdbcType.Int, 0);
          p1.Value = test_number;

          command.ExecuteNonQuery();
          conn.Close();

          load_test_data();
        }
        catch (OdbcException ex)
        {
          this.message_.Text = ex.Message;
        }
        catch (Exception ex)
        {
          this.message_.Text = ex.Message;
        }
      }
    }

    //
    // handle_page_index_changed
    //
    protected void handle_page_index_changed (Object sender, DataGridPageChangedEventArgs e)
    {
      // Set the new index of the page.
      this.tests_.CurrentPageIndex = e.NewPageIndex;

      // Refresh the test data.
      refresh_test_data ();
    }

    //
    // status_image_filename
    //
    protected string status_image_filename (string status)
    {
      if (status == "active")
      {
        return "stoplight-green.gif";
      }
      else if (status == "inactive")
      {
        return "stoplight-green.gif";
      }
      else
      {
        return "stoplight-blank.gif";
      }
    }

    /// <summary>
    /// handle_on_item_created
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    protected void handle_on_item_created (Object sender, DataGridItemEventArgs e)
    {
      ListItemType item_type = e.Item.ItemType;

      if (item_type == ListItemType.Pager)
      {
        TableCell pager = (TableCell)e.Item.Controls[0];

        //if (pager.Controls.Count > 0)
        //{
        //  pager.Text = "Page: " + pager.Text;
        //}
      }
      else if (item_type == ListItemType.Footer)
      {
        // Get the number of cells in the footer.
        TableCellCollection tcc = e.Item.Cells;
        int cell_count = tcc.Count;

        for (int i = 1; i < cell_count; i ++)
        {
          e.Item.Cells.RemoveAt (1);
        }

        TableCell tc = e.Item.Cells[0];
        tc.ColumnSpan = cell_count;
      }
    }

    //
    // load_test_data
    //
    private bool load_test_data ()
    {
      OdbcConnection conn = new OdbcConnection(
        ConfigurationManager.AppSettings["ConnectionString"]);

      try
      {
        // Open a connection to the database.
        conn.Open ();

        // Create a new <DataAdapter> to ease the creation of the dataset.
        OdbcDataAdapter adapter = new OdbcDataAdapter ();
        adapter.SelectCommand =
          new OdbcCommand ("SELECT * FROM tests ORDER BY test_number", conn);

        // Fill the <dataset> by executing the <SelectCommand> for the
        // <adapater>.
        DataSet ds = new DataSet ();
        adapter.Fill (ds, "tests");

        // Expose the <DefaultView> of the result.
        this.tests_.DataSource = ds.Tables["tests"];
        this.tests_.DataBind ();

        // Save the <DataSet> in the <Session> object.
        Session["tests"] = ds;
        return true;
      }
      catch (Exception)
      {
        return false;
      }
      finally
      {
        if (conn.State == ConnectionState.Open)
        {
          conn.Close ();
        }
      }
    }

    //
    // refresh_test_data
    //
    private void refresh_test_data ()
    {
      try
      {
        // Get the <DataSet> from the <Session> object.
        DataSet ds = (DataSet) Session["tests"];

        // Rebind the data to the control.
        this.tests_.DataSource = ds.Tables["tests"];
        this.tests_.DataBind ();
      }
      catch (Exception)
      {
        // Making the assumption the data doesn't exists. We can
        // therefore try and load a fresh set of data.
        load_test_data ();
      }
    }

    ///
    #region Web Form Designer generated code
    override protected void OnInit(EventArgs e)
    {
      //
      // CODEGEN: This call is required by the ASP.NET Web Form Designer.
      //
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
