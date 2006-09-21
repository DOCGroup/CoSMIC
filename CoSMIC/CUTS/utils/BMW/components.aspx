<%@ Page language="c#" codefile="components.aspx.cs" 
         autoeventwireup="true" inherits="CUTS.Components" 
         masterpagefile="~/BMW.master" %>

<asp:content runat="server" 
             id="main_content" 
             contentplaceholderid="MainContent">
             
<h2>Registered Component Types / Instances</h2>
<asp:label id="message_" 
           runat="server"
           forecolor="red" />

<asp:datagrid runat="server" 
              id="components_" 
              autogeneratecolumns="false" 
              borderstyle="solid"
              cellpadding="4" 
              cellspacing="0" 
              allowpaging="true" 
              pagesize="25" 
              width="100%" 
              showheader="false"
              onitemcreated="handle_onitemcreated"
              onpageindexchanged="handle_onpageindexchanged" 
              onitemcommand="handle_onitemcommand"
              datakeyfield="typeid">
              
  <footerstyle cssclass="footer"/>
  <pagerstyle mode="NumericPages" />

  <columns>
    <asp:buttoncolumn itemstyle-width="10" 
                      itemstyle-horizontalalign="center" 
                      buttontype="LinkButton"
                      text='<img src="images/plus.gif" alt="show" border="0" />'
                      commandname="instances" />
    
    <asp:boundcolumn datafield="typename" 
                     headertext="Registered Component Types" />
  </columns>
</asp:datagrid>

<!-- 
  -- link buttons at the bottom of page for showing/collapsing all the
  -- node details
  -->
<p>
<asp:linkbutton id="show_all_"
                runat="server" 
                text="Show All" 
                causesvalidation="false"
                font-underline="true"
                commandname="show-all"
                forecolor="blue"
                oncommand="show_all" />
<asp:linkbutton runat="server" 
                id="collapse_all_"
                text="Collapse All" 
                causesvalidation="false"
                font-underline="true"
                commandname="collapse-all"
                forecolor="blue"
                oncommand="collapse_all" />
</p>


</asp:content>
