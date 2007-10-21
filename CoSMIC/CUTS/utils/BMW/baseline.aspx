<%@ Page language="c#"
         codefile="baseline.aspx.cs"
         autoeventwireup="false"
         inherits="CUTS.Baseline_Metrics"
         masterpagefile="~/BMW.master" %>

<%@ reference control="~/controls/ComponentPerformanceGrid.ascx" %>
<%@ reference control="~/controls/ComponentPerformanceCategory.ascx" %>
<%@ reference control="~/controls/PortPerformance.ascx" %>

<asp:content runat="server" id="content_" contentplaceholderid="MainContent">
  <h2>Component Baseline Performance Metrics</h2>
  <asp:label runat="server" id="message_" />
  <asp:placeholder runat="server" id="grid_placeholder_" />
</asp:content>
