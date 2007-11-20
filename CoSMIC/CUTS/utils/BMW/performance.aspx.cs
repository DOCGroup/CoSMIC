// -*- C# -*-

//=============================================================================
/**
 * @file      performance.aspx.cs
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
using System.Text;

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

  public partial class Performance : System.Web.UI.Page
  {
    /**
     * Get the current test number for the page. This is the same
     * test number submitted in the query string.
     *
     * @return      Current test number.
     */
    public int TestNumber
    {
      get { return this.test_number_; }
    }

    /**
     * Get the current collection time for the page. This is the
     * same time submitted in the query string.
     */
    public DateTime CollectionTime
    {
      get { return this.collection_time_; }
    }

    /**
     * Callback method for when the page is loading.
     *
     * @param[in]       sender        Sender of the event.
     * @param[in]       e             Event arguments.
     */
    private void Page_Load(object sender, System.EventArgs e)
    {
      // Get the test number from the query string.
      String value = Request.QueryString["t"];

      if (value != null)
        this.test_number_ = System.Int32.Parse(value);

      if (!this.Page.IsPostBack)
      {
        // Load the collection times into the control
        this.load_collection_times();

        try
        {
          // Since this isn't a postback, we are going to show the
          // latest collection time for this test.
          this.collection_time_ =
            this.cutsdb_.get_latest_collection_time(this.test_number_);

          DataSet ds = new DataSet();
          this.cutsdb_.get_critical_paths(ref ds);
          this.execution_path_.DataSource = ds;
          this.execution_path_.DataMember = "critical_path";
          this.execution_path_.DataBind();

          this.collection_times_.SelectedValue = this.collection_time_.ToString();
          this.load_execution_times();
        }
        catch (Exception ex)
        {
          this.show_error_message(ex.Message);
        }
      }
    }

    /**
     * Get a listing of all the collection times for the
     * current test.
     */
    private void load_collection_times()
    {
      // Get the collection times from the database
      DataSet ds = new DataSet();
      this.cutsdb_.get_collection_times (this.test_number_, ref ds);

      // Bind the results to the control.
      this.collection_times_.DataSource = ds;
      this.collection_times_.DataMember = "collection_time";
      this.collection_times_.DataBind();
    }

    private void load_execution_times()
    {
      DataSet ds = new DataSet();

      // Get all the execution times from the database.
      this.cutsdb_.get_execution_times(this.test_number_,
                                       this.collection_time_,
                                       ref ds,
                                       "execution_time");

      // Bind the metrics to the system performance control.
      this.sysperf_.DataSource = ds;
      this.sysperf_.DataMember = "execution_time";
      this.sysperf_.DataBind();

    }

    private void load_cumulative_times()
    {
      DataSet ds = new DataSet();

      // Get the cumulative performance metrics for this test.
      this.cutsdb_.select_execution_time_cumulative(this.test_number_,
                                                    ref ds,
                                                    "cumulative");

      // Bind the cumulative metrics to the control.
      this.cumulative_sysperf_.DataSource = ds;
      this.cumulative_sysperf_.DataMember = "cumulative";
      this.cumulative_sysperf_.DataBind();
    }

    protected void on_collection_time_changed(Object sender, EventArgs e)
    {
      this.collection_time_ =
        DateTime.Parse(this.collection_times_.SelectedValue);

      try
      {
        this.load_execution_times();
      }
      catch (Exception ex)
      {
        this.show_error_message(ex.Message);
      }
    }

    #region Event Handlers
    protected void handle_on_command(Object sender, CommandEventArgs e)
    {
      if (e.CommandName == "viewpath")
      {
        String url = String.Format ("~/Critical_Path_Timeline.aspx?t={0}&p={1}",
                                    this.test_number_,
                                    this.execution_path_.SelectedValue);

        this.Response.Redirect(url);
      }
    }

    protected void handle_onmenuitemclick(Object sender, MenuEventArgs e)
    {
      this.multiview_.ActiveViewIndex = int.Parse (e.Item.Value);
    }

    protected void handle_onactiveviewchanged(Object sender, EventArgs e)
    {
      switch (this.multiview_.ActiveViewIndex)
      {
        case 0:
          if (this.Page.IsPostBack)
            this.collection_time_ = DateTime.Parse(this.collection_times_.SelectedValue);

          this.load_execution_times();
          break;

        case 1:
          this.load_cumulative_times();
          break;
      }
    }
    #endregion
    /**
     * Show an error message. This formats the message
     * and displays it to the user.
     *
     * @param[in]     message       Message to show.
     */
    private void show_error_message(string message)
    {
      Label label = (Label) this.Master.FindControl("message_");

      label.Text = message;
      label.ForeColor = Color.Red;
    }

#region Web Form Designer generated code
    override protected void OnInit(EventArgs e)
    {
      // Initialize the component.
      InitializeComponent();

      // Pass control to the base class.
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

    #region Member Variables
    /// Utility class for interacting with the CUTS database.
    private CUTS.Data.Database cutsdb_ =
      new CUTS.Data.Database(ConfigurationManager.AppSettings["MySQL"]);

    /// The current test number for the performance metrics.
    private int test_number_;

    /// The current collection time for the performance metrics.
    private DateTime collection_time_;
    #endregion
  }
}
