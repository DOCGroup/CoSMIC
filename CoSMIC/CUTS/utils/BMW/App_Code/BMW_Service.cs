// -*- C# -*-

//=============================================================================
/**
 * @file    BMW_Service.cs
 *
 * $Id: BMW_Service.cs,v 1.1.2.5 2006/06/14 04:23:46 hillj Exp $
 *
 * @author  James H. Hill
 */
//=============================================================================

using System;
using System.Configuration;
using System.Runtime.InteropServices;
using System.Web;
using System.Web.Services;
using System.Web.Services.Protocols;
using System.Xml;
using MySql.Data.MySqlClient;

using System.Runtime.Remoting.Channels;
using Ch.Elca.Iiop;
using Ch.Elca.Iiop.Services;
using omg.org.CosNaming;
using CUTS;

//=============================================================================
/**
 * @class BMW_Web_Service
 *
 * @brief Web service for the CUTS Benchmark Manager Web utility.
 */
//=============================================================================

[WebService(Namespace = "http://www.dre.vanderbilt.edu/CUTS",
            Name="CUTS BMWeb Service",
            Description="Execute BMW operations programmatically")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
public class BMW_Web_Service : System.Web.Services.WebService
{
  public BMW_Web_Service()
  {
    this.util_ =
      new CUTS_Database_Utility(ConfigurationManager.AppSettings["MySQL"]);
  }

  /**
   * Get the id of a path by its name
   *
   * @param[in]     PathName      Name of the path.
   */
  [WebMethod(Description = "Get the id of a path by name")]
  public System.Int32 PathIDByName(string PathName)
  {
    try
    {
      return this.util_.path_id_by_name(PathName);
    }
    catch (Exception ex)
    {
      throw new SoapException(ex.Message,
                              new XmlQualifiedName("BMWeb.PathIDByName"));
    }
  }

  /**
   * Get the execution time of a path for a given test.
   *
   * @param[in]     TestNumber    The target test number.
   * @param[in]     PathName      Name of the target path.
   */
  [WebMethod (Description="Calculates the execution time for the path of " +
                          "observation the lastest timestamp")]
  public ExecutionTime PathExecutionTime(int TestNumber,
                                                string PathName)
  {
    try
    {
      return this.util_.path_execution_time(TestNumber, PathName);
    }
    catch (Exception ex)
    {
      throw new SoapException(
        ex.Message,
        new XmlQualifiedName("BMWeb.PathExecutionTime"));
    }
  }

  [WebMethod (Description="Get the current test number of the Benchmark " +
                          "Data Collector")]
  public long CurrentTest()
  {
    try
    {
      const string host = "127.0.0.1";
      const int port = 10000;

      // Register the channel...
      IiopClientChannel channel = new IiopClientChannel();
      ChannelServices.RegisterChannel(channel, false);

      // Access the COS naming service (NameService)...
      CorbaInit init = CorbaInit.GetInit();
      NamingContext nameService = init.GetNameService(host, port);

      // Access the IDL-defined module
      // (which maps to a .Net namespace)...
      NameComponent[] moduleName = 
        new NameComponent[] { new NameComponent("CUTS", "") };
      NamingContext ns = (NamingContext)nameService.resolve(moduleName);

      // Access the IDL-defined interface
      // (which maps to a .NET interface class)
      NameComponent[] interfaceName = 
        new NameComponent[] { new NameComponent("Testing_Service", "") };
      CUTS.Testing_Service servant =
            (CUTS.Testing_Service)ns.resolve(interfaceName);

      return 0;
    }
    catch (Exception ex)
    {
      throw new SoapException(ex.Message,
                              new XmlQualifiedName("BMWeb.CurrentTest"));
    }
  }

  /**
   * CUTS database utility component. This object is created
   * at construction time and a the default connection is
   * established. The methods do not have to worry about
   * closing the connection because it is handled when the
   * object is destroyed.
   */
  private CUTS_Database_Utility util_;
}
