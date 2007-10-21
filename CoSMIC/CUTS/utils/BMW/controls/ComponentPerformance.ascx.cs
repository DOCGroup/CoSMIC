// -*- C# -*-

//=============================================================================
/**
 * @file      ComponentDetails.ascx
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

using System;
using System.Data;
using System.Drawing;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace CUTS
{

  //===========================================================================
  /**
   * @class ComponentPerformance
   *
   * User defined control for displaying the performance metrics
   * of a specific component instanace.
   */
  //===========================================================================

  public partial class ComponentPerformance : System.Web.UI.UserControl
  {
    /// Get/set the instance id
    public int InstanceID
    {
      get { return this.instance_id_; }
      set { this.instance_id_ = value; }
    }

    /// Get/set the instance name for the performance metrics.
    public string InstanceName
    {
      set { this.instance_name_ = value; }
      get { return this.instance_name_; }
    }

    public object CurrentDataSource
    {
      set { this.current_datasource_ = value; }
      get { return this.current_datasource_; }
    }

    public object CumulativeDataSource
    {
      set { this.cumulative_datasource_ = value; }
      get { return this.cumulative_datasource_; }
    }

    public override void DataBind()
    {
      this.load_current_performance_data();
      this.load_cumulative_performance_data();

      base.DataBind();
    }

    private void Page_Load(Object sender, System.EventArgs e)
    {
      if (this.current_datasource_ == null)
        this.current_tablecell_.Visible = false;

      if (this.cumulative_datasource_ == null)
        this.cumulative_tablecell_.Visible = false;
    }

    private void load_current_performance_data()
    {
      DataRow[] rows = (DataRow[])this.current_datasource_;

      long src_id;
      CUTS.PortPerformance portperf = null;

      foreach (DataRow row in rows)
      {
        src_id = long.Parse(row["src"].ToString());

        if (portperf == null || src_id != portperf.PortID)
        {
          if (portperf != null)
            this.current_.Controls.Add(portperf);

          Control control = this.LoadControl("~/controls/PortPerformance.ascx");
          portperf = (CUTS.PortPerformance)control;

          portperf.PortID = src_id;
          portperf.PortName = row["srcname"].ToString();
        }

        if (row["metric_type"].ToString() == "process" &&
            row["dst"] != DBNull.Value)
        {
          // Create a new exit point.
          CUTS.ExitPoint ep = new CUTS.ExitPoint();

          // Initialize its values.
          ep.Name = row["dstname"].ToString();
          ep.Performance.Count = long.Parse(row["metric_count"].ToString());
          ep.Performance.Minimum = long.Parse(row["best_time"].ToString());
          ep.Performance.Average = double.Parse(row["avg_time"].ToString());
          ep.Performance.Maximum = long.Parse(row["worst_time"].ToString());

          // Add it to the collection.
          portperf.ExitTimes.Add(ep);
        }
        else if (row["metric_type"].ToString() == "process" &&
                 row["dst"] == DBNull.Value)
        {
          // We have encountered row that has the overall performance
          // metrics for service time.
          CUTS.PerformanceTimes pt = new CUTS.PerformanceTimes();
          pt.Count = long.Parse(row["metric_count"].ToString());
          pt.Minimum = long.Parse(row["best_time"].ToString());
          pt.Average = double.Parse(row["avg_time"].ToString());
          pt.Maximum = long.Parse(row["worst_time"].ToString());

          portperf.ServiceTime = pt;
        }
        else if (row["metric_type"].ToString() == "queue")
        {
          // We have encountered row that has the overall performance
          // metrics for queuing time.
          CUTS.PerformanceTimes pt = new CUTS.PerformanceTimes();
          pt.Count = long.Parse(row["metric_count"].ToString());
          pt.Minimum = long.Parse(row["best_time"].ToString());
          pt.Average = double.Parse(row["avg_time"].ToString());
          pt.Maximum = long.Parse(row["worst_time"].ToString());

          portperf.QueuingTime = pt;
        }
      }

      if (portperf != null)
        this.current_.Controls.Add(portperf);
    }

    private void load_cumulative_performance_data()
    {
      DataRow[] rows = (DataRow[])this.cumulative_datasource_;

      long src_id;
      CUTS.CumulativePortPerformance portperf = null;

      foreach (DataRow row in rows)
      {
        src_id = long.Parse(row["src"].ToString());

        if (portperf == null || src_id != portperf.PortID)
        {
          if (portperf != null)
            this.cumulative_.Controls.Add(portperf);

          Control control = this.LoadControl("~/controls/CumulativePortPerformance.ascx");
          portperf = (CUTS.CumulativePortPerformance)control;

          portperf.PortID = src_id;
          portperf.PortName = row["srcname"].ToString();
        }

        if (row["metric_type"].ToString() == "process" &&
            row["dst"] != DBNull.Value)
        {
          // Create a new exit point.
          CUTS.CumulativeExitPoint ep = new CUTS.CumulativeExitPoint();

          // Initialize its values.
          ep.Name = row["dstname"].ToString();
          ep.TimelineURLQuery =
            "t=" + row["test_number"].ToString() +
            "&c=" + row["component"].ToString() +
            "&m=" + row["metric_type"].ToString() +
            "&src=" + row["src"].ToString() +
            "&dst=" + row["dst"];

          ep.Performance.Count = long.Parse(row["metric_count"].ToString());
          ep.Performance.Minimum = long.Parse(row["best_time"].ToString());
          ep.Performance.Average = double.Parse(row["avg_time"].ToString());
          ep.Performance.Maximum = long.Parse(row["worst_time"].ToString());

          // Add it to the collection.
          portperf.ExitTimes.Add(ep);
        }
        else if (row["metric_type"].ToString() == "process" &&
                 row["dst"] == DBNull.Value)
        {
          portperf.ServiceTimelineURLQuery =
            "t=" + row["test_number"].ToString() +
            "&c=" + row["component"].ToString() +
            "&m=" + row["metric_type"].ToString() +
            "&src=" + row["src"].ToString();

          // We have encountered row that has the overall performance
          // metrics for service time.
          CUTS.PerformanceTimes pt = new CUTS.PerformanceTimes();
          pt.Count = long.Parse(row["metric_count"].ToString());
          pt.Minimum = long.Parse(row["best_time"].ToString());
          pt.Average = double.Parse(row["avg_time"].ToString());
          pt.Maximum = long.Parse(row["worst_time"].ToString());

          portperf.ServiceTime = pt;
        }
        else if (row["metric_type"].ToString() == "queue" &&
                 row["dst"] == DBNull.Value)
        {
          portperf.QueueingTimelineURLQuery =
            "t=" + row["test_number"].ToString() +
            "&c=" + row["component"].ToString() +
            "&m=" + row["metric_type"].ToString() +
            "&src=" + row["src"].ToString();

          // We have encountered row that has the overall performance
          // metrics for queuing time.
          CUTS.PerformanceTimes pt = new CUTS.PerformanceTimes();
          pt.Count = long.Parse(row["metric_count"].ToString());
          pt.Minimum = long.Parse(row["best_time"].ToString());
          pt.Average = double.Parse(row["avg_time"].ToString());
          pt.Maximum = long.Parse(row["worst_time"].ToString());

          portperf.QueuingTime = pt;
        }
      }

      if (portperf != null)
        this.cumulative_.Controls.Add(portperf);
    }

    /// Name of the component instance.
    protected string instance_name_;

    /// The id of the component instance.
    private int instance_id_;

    /// Data source for the current snapshot.
    private object current_datasource_;

    /// Data source for the cumulative snapshot.
    private object cumulative_datasource_;

    #region Web Form Designer generated code
    override protected void OnInit(EventArgs e)
    {
      InitializeComponent();

      base.OnInit(e);
    }

    /// <summary>
    ///    Required method for Designer support - do not modify
    ///    the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.Load += new System.EventHandler(this.Page_Load);

    }
    #endregion
  }
}
