using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

namespace CUTS
{
  public class ExitPoint
  {
    public ExitPoint()
    {

    }

    public string Name
    {
      set { this.name_ = value; }
      get { return this.name_; }
    }

    public CUTS.PerformanceTimes Performance
    {
      get { return this.perf_time_; }
      set { this.perf_time_ = value; }
    }

    /// Name of the exit point.
    private string name_;

    /// Performance times for the exit point.
    CUTS.PerformanceTimes perf_time_ = new CUTS.PerformanceTimes();
  }
}
