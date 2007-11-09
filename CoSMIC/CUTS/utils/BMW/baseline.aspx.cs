// -*- C# -*-

//=============================================================================
/**
 * @file      baseline.aspx.cs
 *
 * Implements the code behind for baseline.aspx
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

  public partial class Baseline_Metrics : System.Web.UI.Page
  {
    private CUTS.Data.Database cuts_ =
      new CUTS.Data.Database(ConfigurationManager.AppSettings["MySQL"]);

    /**
     * Callback method for when the page is loading.
     *
     * @param[in]       sender        Sender of the event.
     * @param[in]       e             Event arguments.
     */
    private void Page_Load(object sender, System.EventArgs e)
    {
      if (!this.IsPostBack)
        this.load_baseline ();
    }

    /// Helper method that loads baseline data from database.
    private void load_baseline()
    {
      DataSet ds = new DataSet();
      this.cuts_.get_baseline_data(ref ds, "baseline");

      this.sysperf_.DataSource = ds;
      this.sysperf_.DataMember = "baseline";
      this.sysperf_.DataBind();
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
