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
  public partial class CumulativePortPerformance : System.Web.UI.UserControl
  {
    /**
     *
     */
    protected void Page_Load(object sender, EventArgs e)
    {
      if (this.service_timeline_url_query_ != null)
      {
        this.service_timeline_link_.NavigateUrl =
          "~/timeline.aspx?" + this.service_timeline_url_query_;
      }

      if (this.queueing_timeline_url_query_ != null)
      {
        this.queueing_timeline_link_.NavigateUrl =
          "~/timeline.aspx?" + this.queueing_timeline_url_query_;
      }
    }

    /// Get/set the port name for the performance metrics.
    public string PortName
    {
      set { this.portname_ = value; }
      get { return this.portname_; }
    }

    public long PortID
    {
      set { this.portid_ = value; }
      get { return this.portid_; }
    }

    public CUTS.PerformanceTimes QueuingTime
    {
      get { return this.queuing_time_; }
      set { this.queuing_time_ = value; }
    }

    public CUTS.PerformanceTimes ServiceTime
    {
      get { return this.service_time_; }
      set { this.service_time_ = value; }
    }

    public ArrayList ExitTimes
    {
      get { return this.exittimes_; }
    }

    public override void DataBind()
    {
      if (this.exittimes_.Count > 0)
      {
        this.exittime_row_.Visible = true;

        foreach (object item in this.exittimes_)
        {
          try
          {
            // Create a new row for the exit point.
            CUTS.CumulativeExitPoint ep = (CUTS.CumulativeExitPoint)item;
            TableRow row = new TableRow();

            // Create the cell that contains the name.
            TableCell cell = new TableCell();
            cell.Text = ep.Name + ":";
            cell.CssClass = "performance-name";
            row.Cells.Add(cell);

            // Create the timeline cell for the new row
            HyperLink link = new HyperLink();
            link.ImageUrl = "~/images/graph.gif";
            link.NavigateUrl = "~/timeline.aspx?" + ep.TimelineURLQuery;

            cell = new TableCell();
            cell.Controls.Add(link);
            cell.CssClass = "performance-data";
            row.Cells.Add(cell);

            // Create cells for each of the performance metrics.
            cell = new TableCell();
            cell.Text = ep.Performance.Count.ToString();
            cell.CssClass = "performance-data";
            row.Cells.Add(cell);

            cell = new TableCell();
            cell.Text = ep.Performance.Minimum.ToString();
            cell.CssClass = "performance-data";
            row.Cells.Add(cell);

            cell = new TableCell();
            cell.Text = Math.Round(ep.Performance.Average, 2).ToString();
            cell.CssClass = "performance-data";
            row.Cells.Add(cell);

            cell = new TableCell();
            cell.Text = ep.Performance.Maximum.ToString();
            cell.CssClass = "performance-data";
            row.Cells.Add(cell);

            // Add the new row to the table.
            this.portperf_table_.Rows.Add(row);
          }
          catch (Exception)
          {

          }
        }
      }
      // Pass control to the base class.
      base.DataBind();
    }

    public string QueueingTimelineURLQuery
    {
      get { return this.queueing_timeline_url_query_; }
      set { this.queueing_timeline_url_query_ = value; }
    }

    public string ServiceTimelineURLQuery
    {
      get { return this.service_timeline_url_query_; }
      set { this.service_timeline_url_query_ = value; }
    }

    /// Number of events on this port.
    protected long event_count_;

    /// The name of the port.
    protected string portname_;

    /// The queuing time for the port.
    protected CUTS.PerformanceTimes queuing_time_;

    /// The process time for the port.
    protected CUTS.PerformanceTimes service_time_;

    /// Navigation URL for the queueing timeline.
    protected string queueing_timeline_url_query_;

    /// Navigation URL for the service timeline.
    protected string service_timeline_url_query_;

    /// Unique id for the port.
    private long portid_;

    /// Collection of exit times for the component
    private ArrayList exittimes_ = new ArrayList();
  }
}
