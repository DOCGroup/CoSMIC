using System;
using System.Collections;
using System.Configuration;
using System.ComponentModel;
using System.Data;
using System.Data.Odbc;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

using WebChart;
using MySql.Data;
using MySql.Data.MySqlClient;

namespace CUTS
{
  public partial class Critical_Path_Timeline : System.Web.UI.Page
  {
    private long test_;

    private long path_;

    private void Page_Load(object sender, System.EventArgs e)
    {
      // Get the query string information.
      if (Request.QueryString["t"] != null &&
          Request.QueryString["p"] != null)
      {
        this.test_ = System.Int32.Parse(Request.QueryString["t"]);
        this.path_ = System.Int32.Parse (Request.QueryString["p"]);

        MySqlConnection conn =
          new MySqlConnection (ConfigurationManager.AppSettings["MySQL"]);

        try
        {
          // Open the connection to the database.
          conn.Open ();

          // Get the critical path deadline
          Int32 deadline = get_deadline(conn);

          // Get the metrics of the critical path components and create the
          // performance graphs of the metrics.
          MySqlDataReader reader = create_path_reader (conn);
          create_performance_graphs (reader, deadline);

          // Close the reader and the connection to the database.
          reader.Close ();
          conn.Close ();
        }
        catch (OdbcException ex)
        {
          this.exception_label_.ForeColor = Color.Red;
          this.exception_label_.Text = "ODBC Exception: " + ex.Message;
        }
        catch (Exception ex)
        {
          this.exception_label_.ForeColor = Color.Red;
          this.exception_label_.Text = "Unknown Exception: " + ex.Message;
        }
        finally
        {
          if (conn.State == ConnectionState.Open)
          {
            conn.Close ();
          }
        }
      }
    }

    private void create_performance_graphs (MySqlDataReader metrics,
                                            Int32 deadline)
    {
      // Bypass all the empty metrics in the collection and store
      // the first DateTime value as the <collection_time>.
      while (metrics.Read () && metrics["collection_time"] == DBNull.Value);
      long best_time = 0, worst_time = 0;
      float average_time = 0.0F;
      bool done = false;

      // Create the collection of points for the best, average and
      // worse execution time charts.
      ChartPointCollection best_points = new ChartPointCollection ();
      ChartPointCollection average_points = new ChartPointCollection ();
      ChartPointCollection worse_points = new ChartPointCollection ();
      ChartPointCollection deadline_points = new ChartPointCollection ();

      do
      {
        bool create_point = false;

        // Get the collection_date, component, src and dst port and create
        // a path element out of it.
        DateTime collection_time = (DateTime) metrics["collection_time"];

        // Right now we are checking for the sender. We are just going
        // to add the metrics to this collection point.
        best_time    += (Int32)metrics["best_time"];
        average_time += float.Parse (metrics["avg_time"].ToString ());
        worst_time   += (Int32)metrics["worst_time"];

        // Determine if this is the last record in the listing. If it
        // is not then we need to see if the next record is part of this
        // collection period. If this is the last record then we have
        // to create a new point regardless.
        if (metrics.Read ())
        {
          if (collection_time != (DateTime) metrics["collection_time"])
            create_point = true;
        }
        else
        {
          create_point = true;
          done = true;
        }

        if (create_point)
        {
          // Create a new point for each of the charts using the
          // summations of the metrics collected.
          best_points.Add (new ChartPoint (collection_time.ToString (), best_time));
          average_points.Add (new ChartPoint (collection_time.ToString (), average_time));
          worse_points.Add (new ChartPoint (collection_time.ToString (), worst_time));
          deadline_points.Add (new ChartPoint (collection_time.ToString (), deadline));

          // Reset the time values.
          best_time = worst_time = 0;
          average_time = 0.0F;
        }
      } while (!done);

      // Create the chart that will display the execution times for
      // the best execution time for the path.
      WebChart.LineChart best_chart =
        new WebChart.LineChart (best_points, Color.Green);
      best_chart.Legend = "Best Time";
      best_chart.Fill.Color = Color.Green;
      this.timeline_.Charts.Add (best_chart);

      // Create the chart that will display the execution times for
      // the average execution time for the path.
      WebChart.LineChart average_chart =
        new WebChart.LineChart (average_points, Color.Blue);
      average_chart.Legend = "Average Time";
      average_chart.Fill.Color = Color.Blue;
      this.timeline_.Charts.Add (average_chart);

      // Create the chart that will display the execution times for
      // the worse execution time for the path.
      WebChart.LineChart worse_chart =
        new WebChart.LineChart (worse_points, Color.Red);
      worse_chart.Legend = "Worst Time";
      worse_chart.Fill.Color = Color.Red;
      this.timeline_.Charts.Add (worse_chart);

      // Create the deadline chart and display it as a orange line.
      WebChart.LineChart deadline_chart =
        new WebChart.LineChart(deadline_points, Color.Orange);
      deadline_chart.ShowLineMarkers = true;
      deadline_chart.ShowLegend = false;
      this.timeline_.Charts.Add(deadline_chart);

      // Redraw the charts.
      this.timeline_.RedrawChart ();
    }

    private int get_deadline(MySqlConnection conn)
    {
      MySqlCommand command = conn.CreateCommand();
      command.CommandText = "SELECT cuts.get_execution_path_deadline_i(?path)";
      command.Parameters.AddWithValue("?path", this.path_);

      return (int) command.ExecuteScalar();
    }

    private MySqlDataReader create_path_element_reader (MySqlConnection conn)
    {
      // Create the MySQL command.
      MySqlCommand command = conn.CreateCommand ();
      command.CommandText = "CALL cuts.select_execution_path_elements_i (?path)";

      // Initailize the parameters
      command.Parameters.AddWithValue ("?path", this.path_);
      return command.ExecuteReader ();
    }

    private MySqlDataReader create_path_reader (MySqlConnection conn)
    {
      // Create the MySQL command.
      MySqlCommand command = conn.CreateCommand ();
      command.CommandText = "CALL cuts.select_execution_path_times_i (?test, ?path)";

      // Initailize the parameters
      command.Parameters.AddWithValue("?test", this.test_);
      command.Parameters.AddWithValue("?path", this.path_);

      return command.ExecuteReader ();
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
