// -*- C# -*-

//=============================================================================
/**
 * @file        PortPerformance.ascx.cs
 *
 * User control for displaying performance metrics for input ports
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

using System;
using System.Collections;
using System.Configuration;
using System.Data;
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
   * @class PortPerformance
   *
   * Partial class for the PortPerformance user control.
   */
  //===========================================================================

  public partial class PortPerformance : System.Web.UI.UserControl
  {
    protected void Page_Load(object sender, EventArgs e)
    {
    }

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

    public void InsertExitPoint (CUTS.ExitPoint ep)
    {
      if (!this.exittime_row_.Visible)
        this.exittime_row_.Visible = true;

      // Create a new row for the exit point.
      this.exittimes_.Add(ep);
      TableRow row = new TableRow();

      // Create the cell that contains the name.
      TableCell cell = new TableCell();
      cell.Text = ep.Name + ":";
      cell.CssClass = "performance-name";
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

    /// Number of events on this port.
    protected long event_count_;

    /// The name of the port.
    protected string portname_;

    /// The queuing time for the port.
    protected CUTS.PerformanceTimes queuing_time_;

    /// The process time for the port.
    protected CUTS.PerformanceTimes service_time_;

    /// Unique id for the port.
    private long portid_;

    /// Collection of exit times for the component
    private ArrayList exittimes_ = new ArrayList();
  }
}
