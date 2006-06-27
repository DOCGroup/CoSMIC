// $Id$

using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Data.Odbc;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace CUTS
{
  /// <summary>
  /// Summary description for Component_Instances.
  /// </summary>
  public partial class Component_Instances : System.Web.UI.Page
  {
    protected OdbcConnection conn_;

    private void Page_Load(object sender, System.EventArgs e)
    {
      Session["current_page"] = "Component_Instances.aspx";

      string connstr =
        "Driver={MySQL ODBC 3.51 Driver};SERVER=localhost;DATABASE=cuts;USER=cuts;PASSWORD=cuts;";
      this.conn_ = new OdbcConnection (connstr);

      try
      {
        // Try and open a connection to the database using the current
        // connection string.
        this.conn_.Open ();

        // Create a new <DataAdapter> to ease the creation of the dataset.
        OdbcDataAdapter adapter = new OdbcDataAdapter ();
        adapter.SelectCommand =
          new OdbcCommand ("SELECT * FROM component_instances ORDER BY component_id",
                           this.conn_);

        // Fill the <dataset> by executing the <SelectCommand> for the
        // <adapater>.
        DataSet dataset = new DataSet ();
        adapter.Fill (dataset, "component_instances");

        // Expose the <DefaultView> of the result.
        this.component_instances_.DataSource = dataset.Tables["component_instances"];
        this.component_instances_.DataBind ();

        // Close the connection.
        this.conn_.Close ();
      }
      catch (OdbcException)
      {

      }

      // Initialize the current page of the table.
      this.component_instances_.CurrentPageIndex = 0;
    }

    //
    // change_page_index
    //
    protected void change_page_index (Object sender, DataGridPageChangedEventArgs e)
    {
      this.component_instances_.CurrentPageIndex = e.NewPageIndex;
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
