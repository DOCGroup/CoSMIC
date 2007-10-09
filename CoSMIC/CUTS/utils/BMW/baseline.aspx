<%@ Page language="c#" codefile="baseline.aspx.cs"
         autoeventwireup="true" inherits="CUTS.Baseline_Metrics"
         masterpagefile="~/BMW.master" %>

<asp:content runat="server" id="content_" contentplaceholderid="MainContent">

<h2>Baseline Metrics</h2>
<asp:datagrid id="baseline_"
              runat="server"
              autogeneratecolumns="false"
              datakeyfield="bid"
              borderstyle="solid"
              cellpadding="2"
              cellspacing="0"
              pagesize="25"
              width="100%"
              showheader="true"
              showfooter="false"
              enableviewstate="true">

  <headerstyle cssclass="header" />
  <footerstyle cssclass="footer" />
  <alternatingitemstyle cssclass="alternate-row" />
  <pagerstyle mode="NumericPages" />
  <itemstyle horizontalalign="center" />

  <columns>
    <asp:boundcolumn datafield="hostname" headertext="Hostname" />

    <asp:boundcolumn datafield="component_name"
                     headertext="Instance Name"
                     itemstyle-horizontalalign="left" />

    <asp:boundcolumn datafield="sink" headertext="Input Port" />
    <asp:boundcolumn datafield="source" headertext="Output Port" />

    <asp:boundcolumn datafield="best_time" headertext="Best Time" />
    <asp:boundcolumn datafield="avg_time" headertext="Average Time" />
    <asp:boundcolumn datafield="worst_time" headertext="Worst Time" />
  </columns>
</asp:datagrid>


</asp:content>
