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
    private CUTS.Data.Database cutsdb_ =
      new CUTS.Data.Database(ConfigurationManager.AppSettings["MySQL"]);

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
        this.load_component_types();
        this.load_component_instances();

        this.components_.CurrentPageIndex = 0;
      }
      else
        this.load_component_instances();
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
     * Helper method for loading the component instances.
     */
    private void load_component_instances()
    {
      try
      {
        // Get all the instances from the database. We have to do this 
        // just in case one of the component types is out of data. There
        // is no way to know ahead of time.

        DataSet ds = new DataSet();
        this.cutsdb_.get_component_instances(ref ds);
        DataTable dt = ds.Tables["component_instances"];

        // Get the underlying table control from the datagrid.
        Table table = (Table)this.components_.Controls[0];

        foreach (DataGridItem item in this.components_.Items)
        {
          ListItemType type = item.ItemType;

          if (type == ListItemType.Item ||
              type == ListItemType.AlternatingItem)
          {
            // Get the detail row and control for the current datagrid item.
            TableRow details = table.Rows[table.Rows.GetRowIndex(item) + 1];
            BulletedList list = (BulletedList)details.Cells[1].Controls[0];

            // Select only the rows that are of the current component type
            // from the component instances in the dataset.
            System.Int32 typeid = 
              (System.Int32)this.components_.DataKeys[item.ItemIndex];

            DataRow [] instances = dt.Select(String.Format("typeid = {0}", 
                                                           typeid));

            // Update the listing if necessary. We are assuming tha the 
            // listing can only be updated if the current number of displayed
            // items are not equal to the number in the listing. This will
            // protect against the unknown multiple "Page_Load" invocations
            // by the Microsoft .NET framework!!!

            if (instances.Length != list.Items.Count)
            {
              // We need to clear the previously added items b/c the state
              // of the control preserves items, and we are not trying to 
              // parse the control to figure out what items are missing.
              list.Items.Clear();

              // Now, let's add the items to the listing.
              foreach (DataRow instance in instances)
              {
                list.Items.Add(new ListItem(instance["component_name"].ToString(),
                                            instance["component_id"].ToString()));
              }
            }
          }
        }
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
      // Change the current page index.
      this.components_.CurrentPageIndex = e.NewPageIndex;

      // Reload the component types and instances.
      this.load_component_types();
      this.load_component_instances();
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

      if (this.prev_item_ != null)
      {
        Table table = (Table)datagrid.Controls[0];

        // We are making sure we can actaully add the new row without
        // causing any range exceptions.
        if (table.Rows.Count == this.prev_item_.ItemIndex)
          table.Rows.AddAt(this.prev_item_.ItemIndex, this.prev_item_);

        this.prev_item_ = null;
      }

      switch (itemtype)
      {
        case ListItemType.Item:
        case ListItemType.AlternatingItem:
          TableCell cell = new TableCell();
          cell.ColumnSpan = datagrid.Columns.Count - 1;

          // Create the bullet list and add to the control.
          BulletedList listing = new BulletedList();
          listing.BulletStyle = BulletStyle.Disc;
          cell.Controls.Add(listing);

          // Create a <DataGridItem> to hold the new row.
          int index = (2 * e.Item.ItemIndex) + 3;
          DataGridItem item = new DataGridItem(index, -1, ListItemType.Item);
          item.Visible = false;

          TableCell empty = new TableCell();
          empty.CssClass = "alternate-row";

          item.Cells.Add(empty);
          item.Cells.Add(cell);

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
        this.toggle_details(e.Item);
    }

    /**
     * Helper method for showing the details for a datagrid item.
     * 
     * @param[in]     item          Target datagrid item.
     * @param[in]     show          Visibility state.
     */
    private void show_details(DataGridItem item, bool show)
    {
      Table table = (Table)this.components_.Controls[0];

      // Set the visibility of the details row.
      TableRow details = table.Rows[table.Rows.GetRowIndex(item) + 1];
      details.Visible = show;
      
      // Update the link button.
      Components.update_link_button(ref item, ref details);
    }

    /**
     * Helper method for toggling the visibility of the 
     * details for a datagrid item.
     * 
     * @param[in]         item        Target item.
     */
    private void toggle_details(DataGridItem item)
    {
      Table table = (Table)this.components_.Controls[0];

      // Set the visibility of the details row.
      TableRow details = table.Rows[table.Rows.GetRowIndex(item) + 1];
      details.Visible = !details.Visible;

      // Update the link button.
      Components.update_link_button(ref item, ref details);
    }

    /**
     * Helper method for setting the image of the link button to
     * the current one. 
     * 
     * @param[in]       header      Reference to the header (DataGridItem)
     * @param[in]       details     Details row for the header.
     */
    static public void update_link_button(ref DataGridItem header,
                                          ref TableRow details)
    {
      LinkButton button = (LinkButton)header.Cells[0].Controls[0];

      if (details.Visible)
        button.Text = "<img src=\"images/minus.gif\" alt=\"hide\" border=\"0\" />";
      else
        button.Text = "<img src=\"images/plus.gif\" alt=\"show\" border=\"0\" />";
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
      foreach (DataGridItem item in this.components_.Items)
        this.show_details (item, true);
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
      foreach (DataGridItem item in this.components_.Items)
        this.show_details(item, false);
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
