<%@ Page language="c#"
         codefile="Critical_Path.aspx.cs"
         autoeventwireup="true"
         inherits="CUTS.Critical_Path"
         masterpagefile="~/BMW.master" %>

<asp:content runat="server"
             id="main_content_"
             contentplaceholderid="MainContent">

<h2>Execution Paths</h2>

<table width="100%" border="0">
<tr valign="top">
  <!-- table form for creating critical paths -->
  <td style="width:45%">
  <table>
  <tr>
    <td class="title">Path Name:</td>
    <td>
      <asp:textbox runat="server" id="path_name_" />
      <asp:requiredfieldvalidator id="path_name_validator_" runat="server"
                                  controltovalidate="path_name_"
                                  errormessage="path name is required"
                                  forecolor="red"
                                  validationgroup="createpath" />
    </td>
  </tr>
  <tr>
    <td class="title">Deadline (ms):</td>
    <td>
      <asp:textbox runat="server" id="deadline_" />
      <asp:requiredfieldvalidator id="deadline_validator_"
                                  runat="server"
                                  controltovalidate="deadline_"
                                  errormessage="deadline is required"
                                  forecolor="red"
                                  validationgroup="createpath"
                                  display="dynamic" />
      <asp:rangevalidator id="deadline_value_validator_"
                          runat="server"
                          minimumvalue="1"
                          maximumvalue="4294967296"
                          controltovalidate="deadline_"
                          validationgroup="createpath"
                          errormessage="invalid deadline"
                          display="dynamic" />
    </td>
  </tr>
  <tr>
    <td colspan="2">
      <asp:button runat="server" text="Create Critical Path" id="create_path_"
                  onclick="CreateCritcalPath" validationgroup="createpath" />
      </td>
  </tr>
  </table>
  </td>

  <!-- portion of page for displaying current paths -->
  <td>
    <asp:datagrid runat="server" id="critical_paths_"
                  borderstyle="solid" cellpadding="4" cellspacing="0"
                  allowpaging="true" pagesize="10" width="100%"
                  autogeneratecolumns="false"
                  showheader="true" showfooter="false">

      <headerstyle cssclass="header" />
      <footerstyle cssclass="footer" />
      <alternatingitemstyle cssclass="alternate-row" />
      <pagerstyle mode="NumericPages" />

      <columns>
        <asp:boundcolumn datafield="path_name"
                         headertext="Current Paths"
                         itemstyle-horizontalalign="Left" />

        <asp:boundcolumn datafield="deadline"
                         headertext="Deadline (ms)"
                         itemstyle-horizontalalign="Center"
                         itemstyle-width="100" />

        <asp:hyperlinkcolumn datanavigateurlfield="path_id"
                             headertext="Edit"
                             datanavigateurlformatstring="Critical_Path.aspx?p={0}"
                             text='<img src="images/edit.gif" border="0" alt="edit path elements" />'
                             itemstyle-horizontalalign="center" />
      </columns>
    </asp:datagrid>
  </td>
</tr>
</table>
<asp:label runat="server" id="message_" />

<h2><asp:label id="selected_path_" runat="server"
               font-bold="true" font-size="medium" />Execution Path</h2>
<table>
<tr>
  <td class="title">Next Index:</td>
  <td><asp:textbox id="order_" runat="server" width="75" maxlength="11"></asp:textbox></td>
</tr>
<tr>
  <td class="title">Instance:</td>
  <td><asp:dropdownlist id="instance_" runat="server"
                        datatextfield="component_name" datavaluefield="component_id"
                        onselectedindexchanged="instance_OnSelectedIndexChanged"
                        autopostback="true" /></td>
</tr>

<tr>
  <td class="title">Source Port:</td>
  <td>
    <asp:dropdownlist  id="src_" runat="server"
                      datavaluefield="pid" datatextfield="portname"
                      width="200" />
    <span class="title">Destination Port: </span>
    <asp:dropdownlist id="dst_" runat="server"
                      datavaluefield="pid" datatextfield="portname"
                      width="200" />
  </td>
</tr>

<tr>
  <td colspan="2">
    <asp:button id="button_PathElementInsert" onclick="PathElement_Insert"
                runat="server" text="Insert Component" />
  </td>
</tr>
</table>

<asp:datagrid id="path_elements_" runat="server"
              datakeyfield="path_order" width="100%" pagesize="15"
              allowpaging="true" autogeneratecolumns="false" showfooter="false"
              borderstyle="solid" cellpadding="4" cellspacing="0"
              onitemcreated="path_elements_OnItemCreated">

  <headerstyle cssclass="header" />
  <footerstyle cssclass="footer" />
  <alternatingitemstyle cssclass="alternate-row" />
  <pagerstyle mode="NumericPages" />

  <columns>
    <asp:boundcolumn datafield="path_order" headertext="Index"
                     itemstyle-horizontalalign="Center" />
    <asp:boundcolumn datafield="instance_name" headertext="Instance Name" />
    <asp:boundcolumn datafield="src_portname" headertext="Source Port" />
    <asp:boundcolumn datafield="dst_portname" headertext="Destination Port" />

    <asp:templatecolumn>
      <headertemplate>
        <asp:checkbox runat="server" id="delete_"
                      oncheckedchanged="ToggleDelete"
                      causesvalidation="false" autopostback="true" />
      </headertemplate>
      <itemtemplate>
        <asp:checkbox runat="server" id="delete_" />
      </itemtemplate>
    </asp:templatecolumn>
  </columns>
</asp:datagrid>

<p>
  <asp:linkbutton id="button_CommitPathElements" onclick="PathElement_Commit"
                  runat="server" text="Commit Changes" />

  <!-- controls at the bottom of page used for batch processing -->
  <asp:linkbutton runat="server" id="button_DeletePathElements"
                  onclick="PathElement_Delete"
                  text="Delete Selected"
                  causesvalidation="false" />
</p>
</asp:content>
