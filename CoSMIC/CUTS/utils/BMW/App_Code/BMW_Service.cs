// -*- C# -*-

//=============================================================================
/**
 * @file    BMW_Service.cs
 *
 * $Id$
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
      new CUTS.Data.Database (ConfigurationManager.AppSettings["MySQL"]);
  }

  /**
   * CUTS database utility component. This object is created
   * at construction time and a the default connection is
   * established. The methods do not have to worry about
   * closing the connection because it is handled when the
   * object is destroyed.
   */
  private CUTS.Data.Database util_;
}
