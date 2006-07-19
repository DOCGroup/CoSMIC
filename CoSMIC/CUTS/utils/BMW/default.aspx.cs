// -*- C# -*-

//=============================================================================
/**
 * @file      default.aspx.cs
 * 
 * $Id$
 * 
 * @author    James H. Hill
 */
//=============================================================================

using System;
using System.Collections;
using System.Configuration;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace CUTS
{
  //===========================================================================
  /**
   * @class Test  
   * 
   * Backend source for the default.aspx web page.
   */
  //===========================================================================

  public partial class Test : System.Web.UI.Page
  {
    private CUTS_Database_Utility cuts_database_ =
      new CUTS_Database_Utility(ConfigurationManager.AppSettings["MySQL"]);

    //
    // Page_Load
    //
    private void Page_Load (object sender, System.EventArgs e)
    {
      this.load_test_data();
    }

    //
    // handle_on_item_command
    //
    protected void handle_on_item_command (Object sender, DataGridCommandEventArgs e)
    {
      if (e.CommandName == "delete")
      {
        try
        {
          // Get the test number from the selected index.
          System.Int32 test_number = 
            (System.Int32)this.tests_.DataKeys[e.Item.ItemIndex];

          // Delete the test from the <cuts_database_> and reload it
          // from the database. This is very inefficient and needs
          // to be addressed. It would be better to "cache" the dataset
          // and operate on it. Then provide a "commit" button which
          // would all users to commit the changes to the database.
          this.cuts_database_.delete_test(test_number);
          this.load_test_data();

          this.cuts_database_.disconnect();
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
      this.load_test_data ();
    }

    //
    // status_image_filename
    //
    protected string status_image_filename (string status)
    {
      switch (status)
      {
      case "active":
        return "stoplight-green.gif";

      case "inactive":
        return "stoplight-green.gif";

      default:
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

        if (pager.Controls.Count > 0)
        {
          Label label = (Label)pager.Controls[0];
          label.Text = "Page: " + label.Text;
        }
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
    private void load_test_data ()
    {
      try
      {
        // Get all the test from the database.
        DataSet ds = new DataSet();
        this.cuts_database_.get_all_test(ref ds);

        // Expose the <DefaultView> of the result.
        this.tests_.DataSource = ds.Tables["tests"];
        this.tests_.DataBind ();
      }
      catch (Exception ex)
      {
        this.message_.Text = ex.Message;
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
