<%@ Page language="c#" codefile="Menu.aspx.cs" autoeventwireup="true"
         inherits="CUTS.Menu" %>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <title>Main Menu</title>
  <style type="text/css">
  * { font-size: x-small; font-family:verdana }
  .menu_item { padding-left:5px; }
  </style>
</head>

<body>
  <div class="menu_item">
    <a href="Test.aspx" target="content">Tests</a>
  </div>
  <div class="menu_item">
    <a href="Component_Instances.aspx" target="content">Component Instances</a>
  </div>
  <div class="menu_item">
    <a href="Critical_Path.aspx" target="content">Critical Paths</a>
  </div>
</body>
</html>
