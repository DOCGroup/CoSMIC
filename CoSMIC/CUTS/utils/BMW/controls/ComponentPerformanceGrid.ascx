<%@ control language="C#"
            autoeventwireup="true"
            codefile="ComponentPerformanceGrid.ascx.cs"
            inherits="CUTS.ComponentPerformanceGrid" %>

<%@ reference control="~/controls/ComponentPerformanceCategory.ascx" %>

<div style="margin-bottom:10px">
  <div><asp:image runat="server" imageurl="~/images/minus.gif" />
       <asp:label runat="server" id="title_" font-bold="true" /></div>
  <div><asp:placeholder runat="server" id="categories_" /></div>
</div>
