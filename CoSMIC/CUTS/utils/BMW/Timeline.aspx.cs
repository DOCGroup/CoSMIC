// $Id$

using System;
using System.Collections;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.Odbc;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

using WebChart;

namespace CUTS
{
  /// <summary>
  /// Summary description for Timeline.
  /// </summary>
  public partial class Timeline : System.Web.UI.Page
  {
    /// Utility class for interacting with the CUTS database.
    private CUTS.Data.Database cutsdb_ =
      new CUTS.Data.Database(ConfigurationManager.AppSettings["MySQL"]);

    protected string component_name_;

    protected string sender_name_;

    private void Page_Load(object sender, System.EventArgs e)
    {
      try
      {
        // Get the appropriate values from the query string.
        int test_number = int.Parse (Request.QueryString["t"]);
        int component = int.Parse (Request.QueryString["c"]);
        string metric = Request.QueryString["m"];
        int src = int.Parse(Request.QueryString["src"]);
        int dst = -1;

        if (Request.QueryString["dst"] != null)
          dst = int.Parse(Request.QueryString["dst"]);

        // Update the navigation link.
        this.return_link_.NavigateUrl = "~/performance.aspx?t=" + test_number;

        // Construct the title of the chart.
        this.component_name_ = this.cutsdb_.get_component_name(component);
        string src_name = this.cutsdb_.get_component_portname(src);

        this.timeline_.ChartTitle.Text =
          this.component_name_ +
          "\n[metric = '" + metric + "' AND input = '" + src_name + "'";

        if (dst != -1)
        {
          this.timeline_.ChartTitle.Text +=
            " AND output = '" + this.cutsdb_.get_component_portname(dst) + "'";
        }

        this.timeline_.ChartTitle.Text += "]";

        // Get the execution times for the timeline.
        DataSet ds = new DataSet ();
        this.cutsdb_.get_component_execution_times(test_number,
                                                   component,
                                                   1,
                                                   metric,
                                                   src,
                                                   dst,
                                                   ref ds);

        // Get the max time for the worse execution time and update
        // the chart so that the Y-axis is 10 msec more that the
        // max value.
        this.timeline_.YCustomEnd =
          this.cutsdb_.get_worst_execution_time(test_number, component) + 10;

        // Create the execution time charts.
        DataTable execution_time = ds.Tables["execution_time"];
        create_execution_time_charts (execution_time);
      }
      catch (OdbcException ex)
      {
        this.exception_label_.Text =
          "ODBC exception has occured; " + ex.Message;
      }
      catch (Exception ex)
      {
        this.exception_label_.Text =
          "Unknown exeception has occurred; " + ex.Message;
      }
      finally
      {
        this.timeline_.RedrawChart ();
      }
    }

    /// <summary>
    /// Creates the execution time charts given the data table. The table
    /// must contain the following fields: collection_time, best_time,
    /// average_time and worst_time.
    /// </summary>
    /// <param name="table"></param>
    private void create_execution_time_charts (DataTable table)
    {
      // Create the <best_time> execution time chart.
      LineChart best_time = new LineChart ();
      best_time.Legend = "Best Time";
      best_time.DataSource = table.DefaultView;
      best_time.DataXValueField = "collection_time";
      best_time.DataYValueField = "best_time";
      best_time.Line.Color = Color.Green;
      best_time.Fill.Color = Color.Green;
      best_time.DataBind ();
      this.timeline_.Charts.Add (best_time);

      // Create the <average_time> execution time chart.
      LineChart average_time = new LineChart ();
      average_time.Legend = "Average Time";
      average_time.DataSource = table.DefaultView;
      average_time.DataXValueField = "collection_time";
      average_time.DataYValueField = "average_time";
      average_time.Line.Color = Color.Blue;
      average_time.Fill.Color = Color.Blue;
      average_time.DataBind ();
      this.timeline_.Charts.Add (average_time);

      // Create the <worst_time> execution time chart.
      LineChart worst_time = new LineChart ();
      worst_time.Legend = "Worst Time";
      worst_time.DataSource = table.DefaultView;
      worst_time.DataXValueField = "collection_time";
      worst_time.DataYValueField = "worst_time";
      worst_time.Line.Color = Color.Red;
      worst_time.Fill.Color = Color.Red;
      worst_time.DataBind ();
      this.timeline_.Charts.Add (worst_time);
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
