// $Id$

using System;
using System.Data;
using System.Data.Odbc;
using System.Drawing;
using System.Web;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace CUTS
{
  /// <summary>
  ///    Summary description for Component_Metrics.
  /// </summary>
  public partial class Sender_Metrics : System.Web.UI.UserControl
  {
    protected string instance_name_;

    protected long instance_id_;

    protected long test_;

    protected long owner_;

    private System.Data.DataTable data_;

    public System.Data.DataTable Data
    {
      set
      {
        // Save the new data table.
        this.data_ = value;

        // Bind the data table to the data grid.
        this.bind_data ();
      }
    }

    public string InstanceName
    {
      get { return this.instance_name_; }
      set { this.instance_name_ = value; }
    }

    public long InstanceID
    {
      get { return this.instance_id_; }
      set { this.instance_id_ = value; }
    }

    public long Owner
    {
      get { return this.owner_; }
      set { this.owner_ = value; }
    }

    public void BindDataSource (OdbcConnection conn, DateTime time)
    {
      OdbcParameter p1 = new OdbcParameter ("@test_number", OdbcType.Int);
      p1.Direction = ParameterDirection.Input;
      p1.Value = this.test_;

      OdbcParameter p2 = new OdbcParameter("@collection_time", OdbcType.DateTime);
      p2.Direction = ParameterDirection.Input;
      p2.Value = time;

      OdbcParameter p3 = new OdbcParameter("@component", OdbcType.Int);
      p3.Direction = ParameterDirection.Input;
      p3.Value = this.owner_;

      OdbcParameter p4 = new OdbcParameter("@sender", OdbcType.Int);
      p4.Direction = ParameterDirection.Input;
      p4.Value = this.instance_id_;

      String sqlstmt = "CALL select_execution_time_ex (?,?,?,?)";
      OdbcCommand command = new OdbcCommand(sqlstmt, conn);

      command.Parameters.Add (p1);
      command.Parameters.Add (p2);
      command.Parameters.Add (p3);
      command.Parameters.Add (p4);

      OdbcDataAdapter adapter = new OdbcDataAdapter (command);

      DataSet ds = new DataSet ();
      adapter.Fill (ds, "metrics");

      this.metrics_.DataSource = ds.Tables["metrics"];
      this.metrics_.DataBind ();
    }

    protected void handle_page_index_changed (
      object sender,
      DataGridPageChangedEventArgs e)
    {
      // Change the page index of the data grid.
      this.metrics_.CurrentPageIndex = e.NewPageIndex;

      // Rebind the data in the data grid.
      this.bind_data ();
    }

    public long Test
    {
      set { this.test_ = value; }
      get { return this.test_; }
    }

    private void bind_data ()
    {
      this.metrics_.DataSource = this.data_;
      this.metrics_.DataBind ();
    }

    private void Page_Load(object sender, System.EventArgs e)
    {

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
