// -* C# -*-

using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Collections.Generic;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

namespace CUTS
{

  public partial class ComponentPerformanceCategory : System.Web.UI.UserControl
  {
    public string Title
    {
      set { this.category_.Text = value; }
      get { return this.category_.Text; }
    }

    public Control Ports
    {
      get { return this.ports_; }
    }

    protected void Page_Load(object sender, EventArgs e)
    {

    }
  }
}
