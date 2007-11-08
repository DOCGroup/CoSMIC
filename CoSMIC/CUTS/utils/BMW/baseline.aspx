<%@ Page language="c#"
         codefile="baseline.aspx.cs"
         autoeventwireup="false"
         inherits="CUTS.Baseline_Metrics"
         masterpagefile="~/BMW.master" %>

<%@register tagprefix="cuts"
            tagname="systemperformance"
            src="~/controls/SystemPerformance.ascx" %>

<asp:content runat="server" id="content_" contentplaceholderid="MainContent">
  <h2>Component Baseline Performance Metrics</h2>

  <cuts:systemperformance runat="server"
                          id="sysperf_"
                          datacomponentname="component_name"
                          datacategoryname="hostname"
                          datametrictype="metric_type"
                          datasrcname="sink"
                          datadstname="source"
                          dataeventcount="event_count"
                          databesttime="best_time"
                          dataavgtime="avg_time"
                          dataworsttime="worst_time"
                          enableviewstate="false" />
</asp:content>
