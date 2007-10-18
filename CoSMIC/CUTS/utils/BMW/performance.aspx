<%@ page language="c#"
         codefile="performance.aspx.cs"
         autoeventwireup="false"
         inherits="CUTS.Performance"
         masterpagefile="~/BMW.master" %>

<%@ register tagprefix="cuts"
             tagname="systemperformance"
             src="~/controls/SystemPerformance.ascx" %>

<%@ reference control="~/controls/ComponentPerformance.ascx" %>

<asp:content runat="server"
             id="main_content"
             contentplaceholderid="MainContent">
  <h2>System-wide Performance Metrics</h2>

  <!--
    -- Display the basic information about the system metrics. This
    -- includes the test number and collection time. We should also
    -- display the current duration of the test.
    -->
  <table>
    <tr>
      <td style="text-align:right;font-weight:bold">Test Number:</td>
      <td><%= this.TestNumber %></td>
    </tr>
    <tr>
      <td style="text-align:right;font-weight:bold">Collection Time:</td>
      <td><asp:dropdownlist runat="server"
                            id="collection_times_"
                            datatextfield="collection_time"
                            datavaluefield="collection_time"
                            onselectedindexchanged="on_collection_time_changed"
                            autopostback="true" /></td>
    </tr>
  </table>

  <asp:label id="message_" runat="server" />

  <cuts:systemperformance runat="server"
                          id="sysperf_"
                          enableviewstate="true" />
</asp:content>
