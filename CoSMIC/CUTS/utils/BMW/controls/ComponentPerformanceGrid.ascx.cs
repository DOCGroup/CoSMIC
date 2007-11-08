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

    }

    /// Get/set the title of the grid.
    public string Title
    {
      get { return this.title_.Text; }
      set { this.title_.Text = value; }
    }

    public CUTS.ComponentPerformanceCategory FindCategory(string name)
    {
      foreach (CUTS.ComponentPerformanceCategory item in this.categories_.Controls)
      {
        if (item.Title == name)
          return item;
      }

      Control control = this.LoadControl ("~/controls/ComponentPerformanceCategory.ascx");
      this.categories_.Controls.Add(control);

      CUTS.ComponentPerformanceCategory category = (CUTS.ComponentPerformanceCategory)control;
      category.Title = name;

      return category;
    }
  }
}
