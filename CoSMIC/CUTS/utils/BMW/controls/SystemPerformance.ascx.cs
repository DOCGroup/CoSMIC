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
  public partial class SystemPerformance : System.Web.UI.UserControl
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      if (!this.Page.IsPostBack)
        this.DataBind();
    }

    public object DataSource
    {
      set { this.dataset_ = value; }
      get { return this.dataset_; }
    }

    public string ExecutionTimeDataMember
    {
      get { return this.exectime_member_; }
      set { this.exectime_member_ = value; }
    }

    public string DistinctComponentDataMember
    {
      get { return this.distinct_member_; }
      set { this.distinct_member_ = value; }
    }

    public string CumulativeDataMember
    {
      get { return this.cumulative_member_; }
      set { this.cumulative_member_ = value; }
    }

    public override void DataBind()
    {
      // Get the correct tables from the dataset.
      DataSet ds = (DataSet)this.dataset_;
      DataTable exectime = ds.Tables[this.exectime_member_];
      DataTable distinct = ds.Tables[this.distinct_member_];
      DataTable cumulative = ds.Tables[this.cumulative_member_];

      // Perform our data binding operation.
      int inst_id;
      Control control;
      CUTS.ComponentPerformance comperf;

      foreach (DataRow row in distinct.Rows)
      {
        // Get the id of the instance.
        inst_id = int.Parse(row["component"].ToString());

        // Create a new control for the instance.
        control = this.LoadControl("~/controls/ComponentPerformance.ascx");
        comperf = (CUTS.ComponentPerformance)control;

        // Set the controls properties.
        comperf.InstanceID = inst_id;
        comperf.InstanceName = row["component_name"].ToString();
        comperf.CurrentDataSource = exectime.Select("component = " + inst_id);
        comperf.CumulativeDataSource = cumulative.Select("component = " + inst_id);

        // Add the control to this control.
        this.Controls.Add(comperf);
      }

      // Pass control to the base class.
      base.DataBind();
    }

    /// The data set for the system performance metrics.
    private object dataset_;

    /// The data member for the current snapshot.
    private string exectime_member_;

    /// The data member for cumulative snapshot.
    private string cumulative_member_;

    /// The data member that list the distinct components.
    private string distinct_member_;
  }
}
