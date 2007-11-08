<%@ Control language="C#"
            autoeventwireup="false"
            codefile="PortPerformance.ascx.cs"
            inherits="CUTS.PortPerformance" %>

<div style="margin-bottom:10px">
  <!-- exit times for the port -->
  <asp:table id="portperf_table_" runat="server" cssclass="performance">
    <asp:tablerow>
      <asp:tableheadercell runat="server"
                           cssclass="performance-name"><%= this.portname_ %></asp:tableheadercell>
      <asp:tableheadercell runat="server"
                           cssclass="performance-data">Count</asp:tableheadercell>
      <asp:tableheadercell runat="server"
                           cssclass="performance-data">Min. (msec)</asp:tableheadercell>
      <asp:tableheadercell runat="server"
                           cssclass="performance-data">Avg. (msec)</asp:tableheadercell>
      <asp:tableheadercell runat="server"
                           cssclass="performance-data">Max. (msec)</asp:tableheadercell>
    </asp:tablerow>

    <asp:tablerow runat="server" id="queueing_time_row_">
      <asp:tablecell runat="server"
                     cssclass="performance-name"
                     id="queueing_time_name_">Queuing Time:</asp:tablecell>
      <asp:tablecell runat="server"
                     cssclass="performance-data"
                     id="queueing_time_count_">
        <%= this.queuing_time_ != null ? this.queuing_time_.Count.ToString() : "--" %></asp:tablecell>
      <asp:tablecell runat="server"
                     cssclass="performance-data"
                     id="queueing_time_min_">
        <%= this.queuing_time_ != null ? this.queuing_time_.Minimum.ToString() : "--" %></asp:tablecell>
      <asp:tablecell runat="server"
                     cssclass="performance-data"
                     id="queueing_time_avg_">
        <%= this.queuing_time_ != null ? Math.Round(this.queuing_time_.Average, 2).ToString() : "--" %></asp:tablecell>
      <asp:tablecell runat="server"
                     cssclass="performance-data"
                     id="queueing_time_max_">
        <%= this.queuing_time_ != null ? this.queuing_time_.Maximum.ToString() : "--" %></asp:tablecell>
    </asp:tablerow>

    <asp:tablerow runat="server" id="service_time_row_">
      <asp:tablecell runat="server"
                     cssclass="performance-name"
                     id="service_time_name_">Service Time:</asp:tablecell>
      <asp:tablecell runat="server"
                     cssclass="performance-data"
                     id="service_time_count_">
        <%= this.service_time_ != null ? this.service_time_.Count.ToString() : "--" %></asp:tablecell>
      <asp:tablecell runat="server"
                     cssclass="performance-data"
                     id="service_time_min_">
        <%= this.service_time_ != null ? this.service_time_.Minimum.ToString() : "--" %></asp:tablecell>
      <asp:tablecell runat="server"
                     cssclass="performance-data"
                     id="service_time_avg_">
        <%= this.service_time_ != null ? Math.Round(this.service_time_.Average, 2).ToString() : "--" %></asp:tablecell>
      <asp:tablecell runat="server"
                     cssclass="performance-data"
                     id="service_time_max_">
        <%= this.service_time_ != null ? this.service_time_.Maximum.ToString() : "--" %></asp:tablecell>
    </asp:tablerow>

    <asp:tablerow runat="server" id="exittime_row_" visible="false">
      <asp:tablecell runat="server"
                     id="exittime_name_"
                     style="text-decoration:underline">Exit Points:</asp:tablecell>
    </asp:tablerow>
  </asp:table>
</div>
