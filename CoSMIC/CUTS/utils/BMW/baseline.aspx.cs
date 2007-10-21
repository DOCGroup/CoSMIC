// -*- C# -*-

//=============================================================================
/**
 * @file      baseline.aspx.cs
 *
 * Implements the code behind for baseline.aspx
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

  public partial class Baseline_Metrics : System.Web.UI.Page
  {
    private CUTS_Database_Utility cuts_ =
      new CUTS_Database_Utility(ConfigurationManager.AppSettings["MySQL"]);

    /**
     * Callback method for when the page is loading.
     *
     * @param[in]       sender        Sender of the event.
     * @param[in]       e             Event arguments.
     */
    private void Page_Load(object sender, System.EventArgs e)
    {
      if (!this.IsPostBack)
        this.load_baseline ();
    }

    /// Helper method that loads baseline data from database.
    private void load_baseline()
    {
      IDataReader reader = null;

      try
      {
        // Get the baseline data from the database.
        reader = this.cuts_.get_baseline_data();


        if (reader.Read())
        {
          bool complete = false;
          Control control;

          do
          {
            // Create a new component performance grid control.
            control = this.LoadControl("~/controls/ComponentPerformanceGrid.ascx");
            CUTS.ComponentPerformanceGrid grid = (CUTS.ComponentPerformanceGrid)control;

            // Set the id of the control.
            grid.ID = reader["instance"].ToString();
            grid.Title = (string)reader["component_name"];

            // We are now going to iterate over all the different hosts
            // in the baseline for this instance. Each host will serve
            // as a new category for the component's performance grid.
            do
            {
              // Create a new category for the next host.
              control = LoadControl("~/controls/ComponentPerformanceCategory.ascx");
              CUTS.ComponentPerformanceCategory category = (CUTS.ComponentPerformanceCategory)control;

              // Set the title of the category.
              category.Title = (string)reader["hostname"];

              do
              {
                // Create a new port performance control.
                Control temp = LoadControl("~/controls/PortPerformance.ascx");
                CUTS.PortPerformance port = (CUTS.PortPerformance)temp;

                // Set the properties.
                port.PortID = (int)reader["inport"];
                port.PortName = (string)reader["sink"];

                do
                {
                  // Create a new exit point for this port.
                  CUTS.ExitPoint ep = new CUTS.ExitPoint();

                  // Set the properties/attributes of the exit point.
                  ep.Name = (string)reader["source"];
                  ep.Performance.Count = (int)reader["event_count"];
                  ep.Performance.Minimum = (int)reader["best_time"];
                  ep.Performance.Average = double.Parse(reader["avg_time"].ToString());
                  ep.Performance.Maximum = (int)reader["worst_time"];

                  // Insert the new exit point into the control.
                  port.ExitTimes.Add(ep);

                  // Move the to the next record. If we have reached the
                  // end then we need to just stop.
                  if (!reader.Read())
                    complete = true;

                } while ((int)reader["inport"] == port.PortID &&
                         (string)reader["hostname"] == category.Title &&
                         reader["instance"].ToString() == grid.ID && !complete);

                // Insert the port performance into the parent control.
                category.Ports.Controls.Add(port);

              } while ((string)reader["hostname"] == category.Title &&
                       reader["instance"].ToString() == grid.ID && !complete);

              // Bind the data for the category and add it to the
              // performance grid for the component.
              category.DataBind();
              grid.Categories.Add(category);

            } while (reader["instance"].ToString() == grid.ID && !complete);

            // Insert the component performance grid into the page.
            this.grid_placeholder_.Controls.Add(grid);
          } while (!complete);
        }
      }
      catch (Exception ex)
      {
        this.message_.Text = ex.Message;
        this.message_.ForeColor = Color.Red;
      }
      finally
      {
        if (reader != null)
          reader.Close();
      }
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
