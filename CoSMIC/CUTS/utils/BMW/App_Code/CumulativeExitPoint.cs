using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// Summary description for CumulativeExitPointTime
/// </summary>
namespace CUTS
{
  public class CumulativeExitPoint : CUTS.ExitPoint
  {
    public CumulativeExitPoint()
    {
    }

    public string TimelineURLQuery
    {
      get { return this.timeline_url_query_; }
      set { this.timeline_url_query_ = value; }
    }

    private string timeline_url_query_;
  }
}
