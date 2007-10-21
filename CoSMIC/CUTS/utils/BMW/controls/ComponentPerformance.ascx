<%@ control language="C#"
            codefile="ComponentPerformance.ascx.cs"
            inherits="CUTS.ComponentPerformance"
            autoeventwireup="false" %>

<%@ reference control="~/controls/PortPerformance.ascx" %>
<%@ reference control="~/controls/CumulativePortPerformance.ascx" %>

<div style="margin-bottom:15px">
  <!-- The header for the component's metrics. It allows you to
       expand and collapse the metrics to improve viewing. -->
  <h3><asp:image runat="server"
                 imageurl="~/images/minus.gif"
                 alternatetext="hide" /> <%= this.instance_name_ %></h3>

  <asp:table runat="server"
             id="component_perf_table_"
             cssclass="performance">
    <asp:tablerow runat="server">
      <asp:tablecell runat="server"
                     verticalalign="top"
                     id="current_tablecell_">
        <div style="font-style:italic">Current Snapshot Performance</div>
        <asp:placeholder runat="server" id="current_" />
      </asp:tablecell>
      <asp:tablecell runat="server"
                     verticalalign="top"
                     id="cumulative_tablecell_">
        <div style="font-style:italic">Cumulative Snapshot Performance</div>
        <asp:placeholder runat="server" id="cumulative_" />
      </asp:tablecell>
    </asp:tablerow>
  </asp:table>
</div>
