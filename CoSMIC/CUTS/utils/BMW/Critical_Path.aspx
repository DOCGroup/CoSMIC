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
  <td style="width:200px">
    <div class="title">Path Name:</div>
    <div><asp:textbox runat="server" id="path_name_" /></div>
    <div class="title">Deadline (ms):</div>
    <div><asp:textbox runat="server" id="deadline_" /></div>
    <div>&nbsp;</div>
    <asp:button runat="server" text="Create..." id="create_path_" onclick="button_create_path" />
  </td>
  <td>
    <asp:datagrid runat="server" id="critical_paths_" forecolor="white" 
                  autogeneratecolumns="false" allowpaging="True"
                  pagesize="10" width="100%">
      <headerstyle backcolor="darkblue" forecolor="white" horizontalalign="center" font-bold="true" />
      <footerstyle backcolor="darkgray" />
      <alternatingitemstyle backcolor="#cccccc" forecolor="black" />
      <itemstyle horizontalalign="center" forecolor="black" />
      <pagerstyle mode="NumericPages" />
      <columns>
        <asp:boundcolumn datafield="path_name" 
                         headertext="Name of Path" 
                         itemstyle-horizontalalign="Left" />
        <asp:boundcolumn datafield="deadline" 
                         headertext="Deadline (ms)" 
                         itemstyle-horizontalalign="Center"
                         itemstyle-width="100" />
        <asp:hyperlinkcolumn datanavigateurlfield="path_id" 
                             datanavigateurlformatstring="Critical_Path.aspx?p={0}"
                             text='<img src="images/edit.gif" border="0" />' />
      </columns>
    </asp:datagrid>
    <div>&nbsp;</div>
    <asp:button runat="server" id="save_paths_" text="Save..." onclick="button_update_path" />
  </td>
</tr>
</table>
<asp:label runat="server" id="message_" />

<asp:panel runat="server" id="element_panel_">
  <hr />
  
  <h2>Critical Path Elements</h2>
  <asp:datagrid id="path_elements_" runat="server" width="100%" pagesize="15" allowpaging="True"
    autogeneratecolumns="False" showfooter="False" onitemcreated="handle_item_created_path_grid">
    <headerstyle backcolor="darkblue" forecolor="white" horizontalalign="center" font-bold="true" />
    <footerstyle backcolor="darkgray" />
    <alternatingitemstyle backcolor="#cccccc" forecolor="black" />
    <itemstyle horizontalalign="center" forecolor="black" />
    <pagerstyle mode="NumericPages" />
    <columns>
      <asp:boundcolumn datafield="path_order" 
                       headertext="Index" />
      <asp:boundcolumn datafield="component_name" 
                       headertext="Instance Name" />
      <asp:boundcolumn datafield="src" 
                       headertext="Source Port" />
      <asp:boundcolumn datafield="dst" 
                       headertext="Destination Port" />
    </columns>
  </asp:datagrid>
  
  <div>&nbsp;</div>
  
  <span class="title">Next Index:</span>
  <asp:textbox id="order_" runat="server" width="75" maxlength="11"></asp:textbox>
  <span class="title">Instance:</span>
  <asp:dropdownlist id="instance_" runat="server" datatextfield="component_name" datavaluefield="component_id"></asp:dropdownlist>
  <br clear="all" />
  <span class="title">Source Port: </span>
  <asp:textbox id="src_" runat="server"></asp:textbox>
  <span class="title">Destination Port: </span>
  <asp:textbox id="dst_" runat="server"></asp:textbox>
  <div>&nbsp;</div>
  <asp:button id="Button1" onclick="insert_path_element" runat="server" text="Insert"></asp:button>
  <asp:button id="Button2" onclick="commit_path_element" runat="server" text="Save..."></asp:button>
</asp:panel>
</asp:content>
