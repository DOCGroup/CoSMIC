<%@ Page language="c#" codefile="Component_Instances.aspx.cs" 
         autoeventwireup="true" inherits="CUTS.Component_Instances" 
         masterpagefile="~/BMW.master" %>

<asp:content runat="server" 
             id="main_content" 
             contentplaceholderid="MainContent">
<h2>Registered Component Instances</h2>
<asp:datagrid runat="server" 
              id="component_instances_" 
              autogeneratecolumns="false"
              width="100%">
  <headerstyle backcolor="darkblue" forecolor="white"
               horizontalalign="center" font-bold="true" />
  <footerstyle backcolor="darkgray"/>
  <alternatingitemstyle backcolor="#cccccc" />
  <pagerstyle mode="NumericPages" />

  <columns>
    <asp:boundcolumn datafield="component_id" 
                     headertext="ID" 
                     itemstyle-horizontalalign="center" 
                     itemstyle-width="50" />
    <asp:boundcolumn datafield="component_name" 
                     headertext="Component Instance Name" />
  </columns>
</asp:datagrid>
</asp:content>
