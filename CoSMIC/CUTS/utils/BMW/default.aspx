<%@ Page language="c#" codefile="default.aspx.cs" inherits="CUTS.Test" 
         masterpagefile="~/BMW.master" %>

<asp:content runat="server" id="content_" contentplaceholderid="MainContent">
<asp:datagrid 
  id="tests_" runat="server" autogeneratecolumns="false" cellpadding="2"
  cellspacing="0" datakeyfield="test_number" borderstyle="solid"
  allowpaging="true" pagesize="20" width="100%" showheader="true"
  showfooter="false" onpageindexchanged="handle_page_index_changed"
  onitemcreated="handle_on_item_created"
  onitemcommand="handle_on_item_command">

  <headerstyle
    backcolor="darkblue" forecolor="white" horizontalalign="center"
    font-bold="true" />
  <footerstyle backcolor="darkgray"/>
  <alternatingitemstyle backcolor="#cccccc" />
  <pagerstyle mode="NumericPages" />
  <itemstyle horizontalalign="center" />

  <columns>
    <asp:boundcolumn datafield="test_number" headertext="Test #" />
    <asp:boundcolumn datafield="test_name" headertext="Deployment" />
    <asp:boundcolumn datafield="start_time" headertext="Start Time" />
    <asp:boundcolumn datafield="stop_time" headertext="Stop Time" />

    <asp:templatecolumn headertext="Status">
      <itemtemplate>
        <asp:image 
          runat="server"
          imageurl='<%# "images/" + DataBinder.Eval (Container.DataItem, "status") + ".gif" %>'
          alternatetext='<%# DataBinder.Eval (Container.DataItem, "status") %>' />
      </itemtemplate>
    </asp:templatecolumn>

    <asp:hyperlinkcolumn 
      headertext="Results"
      datanavigateurlfield="test_number"
      datanavigateurlformatstring="Execution_Times.aspx?test={0}"
      text='<img src="images/table.gif" border="0" />' />

    <asp:buttoncolumn
      headertext="Delete"
      text='<img src="images/delete.gif" border="0" />'
      commandname="delete" />
      
  </columns>
</asp:datagrid>
<asp:label runat="server" id="message_" />
</asp:content>
