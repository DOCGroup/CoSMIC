// -*- C# -*- 

//=============================================================================
/**
 * @file      Component_Instances.aspx.cs
 * 
 * $Id$
 * 
 * @author    James H. Hill
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

namespace CUTS
{
  //===========================================================================
  /**
   * @class Components
   * 
   * Code-behind implemetation for the Component_Instances.aspx 
   * page.
   */
  //===========================================================================

  public partial class Components : System.Web.UI.Page
  {
    private CUTS_Database_Utility cutsdb_ =
      new CUTS_Database_Utility(ConfigurationManager.AppSettings["MySQL"]);

    private DataGridItem prev_item_ = null;

    /**
     * Callback method for when the page is loading.
     * 
     * @param[in]       sender        Sender of the event.
     * @param[in]       e             Event arguments.
     */
    private void Page_Load(object sender, System.EventArgs e)
    {
      if (!this.IsPostBack)
      {
        this.load_component_types ();
        this.components_.CurrentPageIndex = 0;
      }
    }

    /**
     * Helper method to query the database and populate the 
     * control with the component types.
     */
    private void load_component_types ()
    {
      try
      {
        DataSet ds = new DataSet();
        this.cutsdb_.get_component_types (ref ds);

        // Expose the <DefaultView> of the result.
        this.components_.DataSource = ds.Tables["component_types"];
        this.components_.DataBind();
      }
      catch (Exception ex)
      {
        this.message_.Text = ex.Message;
      }
    }

    /**
     * Callback method for when the page index changes.
     * 
     * @param[in]     sender        Sender of the event.
     * @param[in]     e             Event arguments.
     */
    protected void handle_onpageindexchanged (Object sender, 
                                              DataGridPageChangedEventArgs e)
    {
      this.components_.CurrentPageIndex = e.NewPageIndex;
      this.load_component_types();
    }

    /**
     * Callback method for creating an item in the datagrid.
     * 
     * @param[in]     sender        Sender of the event.
     * @param[in]     e             Event arguments
     */
    protected void handle_onitemcreated(Object sender, DataGridItemEventArgs e)
    {
      ListItemType itemtype = e.Item.ItemType;
      DataGrid datagrid = (DataGrid)sender;

      switch (itemtype)
      {
        case ListItemType.Item:
        case ListItemType.AlternatingItem:
          TableCell cell = new TableCell();
          cell.ColumnSpan = datagrid.Columns.Count - 1;

          // Create the bullet list and add to the control.
          BulletedList listing = new BulletedList();
          listing.DataTextField = "component_name";
          listing.BulletStyle = BulletStyle.Disc;
          cell.Controls.Add(listing);

          // Create a <DataGridItem> to hold the new row.
          int index = (2 * e.Item.ItemIndex) + 3;
          DataGridItem item = new DataGridItem(index, 0, ListItemType.Item);
          item.Visible = false;

          item.Cells.Add(new TableCell());
          item.Cells.Add(cell);

          if (this.prev_item_ != null)
          {
            Table table = (Table)datagrid.Controls[0];

            // We are making sure we can actaully add the new row without
            // causing any range exceptions.
            if (table.Rows.Count == this.prev_item_.ItemIndex)
              table.Rows.AddAt(this.prev_item_.ItemIndex, this.prev_item_);
          }

          this.prev_item_ = item;
          break;

        case ListItemType.Pager:
          /// Create the cool pager for the control. We need to move
          /// this to a global location so it can be used throughout
          /// the entire website.
          TableCell pager = (TableCell)e.Item.Controls[0];
          int count = pager.Controls.Count;

          for (int i = 0; i < count; i += 2)
          {
            Object obj = pager.Controls[i];

            if (obj is LinkButton)
            {
              LinkButton link = (LinkButton)obj;
              link.Font.Underline = true;
              link.ForeColor = Color.Blue;
            }
            else
            {
              Label label = (Label)obj;
              label.Text = "[ " + label.Text + " ]";
            }
          }

          /// Add the page title to the beginning of the text.
          pager.Controls.AddAt(0, new LiteralControl("Page(s): "));
          break;

        case ListItemType.Footer:
          if (this.prev_item_ != null)
          {
            Table table = (Table)datagrid.Controls[0];

            // We are making sure we can actaully add the new row without
            // causing any range exceptions.
            if (table.Rows.Count == this.prev_item_.ItemIndex)
            {
              table.Rows.AddAt(this.prev_item_.ItemIndex, this.prev_item_);
              this.prev_item_ = null;
            }
          }
          break;
      }
    }

    /**
     * Event send when a item command is triggered.
     * 
     * @param[in]       sender      Sender of the event.
     * @param[in]       e           Event arguments.
     */
    protected void handle_onitemcommand(Object sender,
                                        DataGridCommandEventArgs e)
    {
      if (e.CommandName == "instances")
      {
        // Get the <typeid> from the <DataKeys>.
        System.Int32 typeid = 
          (System.Int32)this.components_.DataKeys[e.Item.ItemIndex];

        TableCell cell = (TableCell)e.Item.Controls[0];
        LinkButton linkbtn = (LinkButton)cell.Controls[0];

        // Get the "details" row for the selected item.
        int index = (2 * e.Item.ItemIndex) + 3;
        Table table = (Table)this.components_.Controls[0];
        TableRow row = table.Rows[index];

        this.toggle_details(table.Rows[index - 1], table.Rows[index], typeid);
      }
    }

    /**
     * Helper method to toggle the details view.
     * 
     * @param[in]       header      Header row for the details.
     * @param[in]       row         Row containing the details.
     */
    private void toggle_details(TableRow header, TableRow row, System.Int32 typeid)
    {
      this.show_details_i(header, row, !row.Visible, typeid);
    }

    /**
     * Implemetation method for showing/hiding the details.
     * 
     * @param[in]       header      Header row for the details.
     * @param[in]       row         Row containing the details.
     * @param[in]       show        Show/hide the details.
     */
    private void show_details_i(TableRow header, 
                                TableRow row, 
                                bool show,
                                System.Int32 typeid)
    {
      LinkButton linkbtn = (LinkButton)header.Cells[0].Controls[0];

      if (show)
      {
        // Update the image.
        linkbtn.Text = "<img src=\"images/minus.gif\" alt=\"hide\" border=\"0\" />";

        ControlCollection controls = row.Cells[1].Controls;
        BulletedList listing = (BulletedList)row.Cells[1].Controls[0];

        // Get the component instances from the database.
        DataSet ds = new DataSet();
        this.cutsdb_.get_component_instances(ref ds, typeid);

        // Bind the data to the <listing>.
        listing.DataSource = ds.Tables["component_instances"];
        listing.DataBind();
      }
      else
        linkbtn.Text = "<img src=\"images/plus.gif\" alt=\"show\" border=\"0\" />";

      // Toggle the visibility of the row.
      row.Visible = !row.Visible;
    }

    /**
     * Shows all the details of the visible nodes.
     * 
     * @param[in]         sender          Sender of the command.
     * @param[in]         e               Command arguments.
     */
    protected void show_all(object sender,
                            CommandEventArgs e)
    {
      Table table = (Table)this.components_.Controls[0];
      int maxvalue = table.Rows.Count - 2;

      for (int i = 2; i < maxvalue; i += 2)
      {
        System.Int32 typeid = 
          (System.Int32)this.components_.DataKeys[(i / 2) - 1];

        this.show_details_i(table.Rows[i], table.Rows[i + 1], true, typeid);
      }
    }

    /**
     * Shows all the details of the visible nodes.
     * 
     * @param[in]         sender          Sender of the command.
     * @param[in]         e               Command arguments.
     */
    protected void collapse_all(object sender,
                                CommandEventArgs e)
    {
      Table table = (Table)this.components_.Controls[0];
      int maxvalue = table.Rows.Count - 2;

      for (int i = 2; i < maxvalue; i += 2)
      {
        System.Int32 typeid =
          (System.Int32)this.components_.DataKeys[(i / 2) - 1];

        this.show_details_i(table.Rows[i], table.Rows[i + 1], false, typeid);
      }
    }

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
