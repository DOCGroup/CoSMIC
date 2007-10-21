// -*- C# -*-

//=============================================================================
/**
 * @file          ComponentPerformanceGrid.ascx.cs
 *
 * Defines the component performance grid control.
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

namespace CUTS
{
  //===========================================================================
  /**
   *
   */
  //===========================================================================
  public partial class ComponentPerformanceGrid : System.Web.UI.UserControl
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      if (!this.Page.IsPostBack)
        this.load_categories();
    }

    /// Get the collection of categories.
    public ArrayList Categories
    {
      get { return this.categories_; }
    }

    /// Get/set the title of the grid.
    public string Title
    {
      get { return this.title_.Text; }
      set { this.title_.Text = value; }
    }

    /// Load the category controls into the grid.
    private void load_categories()
    {
      if (this.categories_.Count > 0)
      {
        // Make sure the placeholder is visible.
        this.categories_placeholder_.Visible = true;

        foreach (object item in categories_)
        {
          CUTS.ComponentPerformanceCategory category =
            (CUTS.ComponentPerformanceCategory)item;

          this.categories_placeholder_.Controls.Add(category);
        }
      }
      else
      {
        this.categories_placeholder_.Visible = false;
      }
    }

    /// Collection of ComponentPerformanceCategory controls.
    private ArrayList categories_ = new ArrayList ();
  }
}
