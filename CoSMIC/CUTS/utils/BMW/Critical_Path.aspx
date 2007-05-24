<%@ Page language="c#"
         codefile="Critical_Path.aspx.cs"
         autoeventwireup="true"
         inherits="CUTS.Critical_Path"
         masterpagefile="~/BMW.master" %>

<asp:content runat="server"
             id="main_content_"
             contentplaceholderid="MainContent">

<h2>Critical Paths / Paths of Interest</h2>

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
      <asp:button runat="server"
                  text="Create"
                  id="create_path_"
                  onclick="button_create_path"
                  validationgroup="createpath" />
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
                             datanavigateurlformatstring="Critical_Path.aspx?p={0}"
                             text='<img src="images/edit.gif" border="0" alt="edit path elements" />'
                             itemstyle-horizontalalign="center" />
      </columns>
    </asp:datagrid>
    <div>&nbsp;</div>
    <asp:button runat="server" id="save_paths_"
                text="Save"
                onclick="save_paths_onclick"
                causesvalidation="false" />
  </td>
</tr>
</table>
<asp:label runat="server" id="message_" />

<asp:panel runat="server" id="element_panel_">
  <hr />

  <h2>Critical Path Components</h2>

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
                        datavaluefield="portid" datatextfield="portname"
                        width="200" />
      <span class="title">Destination Port: </span>
      <asp:dropdownlist id="dst_" runat="server"
                        datavaluefield="portid" datatextfield="portname"
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
                width="100%" pagesize="15" allowpaging="true"
                autogeneratecolumns="false" showfooter="false"
                borderstyle="solid" cellpadding="4" cellspacing="0"
                onitemcreated="path_elements_OnItemCreated">

    <headerstyle cssclass="header" />
    <footerstyle cssclass="footer" />
    <alternatingitemstyle cssclass="alternate-row" />
    <pagerstyle mode="NumericPages" />

    <columns>
      <asp:boundcolumn datafield="path_order" headertext="Index"
                       itemstyle-horizontalalign="Center" />
      <asp:boundcolumn datafield="component_name" headertext="Instance Name" />
      <asp:boundcolumn datafield="srcname" headertext="Source Port" />
      <asp:boundcolumn datafield="dstname" headertext="Destination Port" />

      <asp:templatecolumn headertext="Delete"
                          itemstyle-horizontalalign="Center">
        <itemtemplate>
          <asp:imagebutton id="Imagebutton1" runat="server" imageurl="~/images/delete.gif"
                           commandname="DeletePathElement"
                           commandargument='<%# DataBinder.Eval (Container.DataItem, "path_order") %>'
                           oncommand="OnCommand" />
        </itemtemplate>
      </asp:templatecolumn>
    </columns>
  </asp:datagrid>

  <asp:linkbutton id="button_CommitPathElements" onclick="PathElement_Commit"
                  runat="server" text="Commit Changes" />

</asp:panel>
</asp:content>
