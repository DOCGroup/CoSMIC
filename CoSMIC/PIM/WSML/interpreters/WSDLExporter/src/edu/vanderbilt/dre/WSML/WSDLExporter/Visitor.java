package edu.vanderbilt.dre.WSML.WSDLExporter;

import edu.vanderbilt.isis.wsml.*;
import edu.vanderbilt.isis.udm.*;

public interface Visitor
{
  public void visitRootFolder (RootFolder folder);
}
