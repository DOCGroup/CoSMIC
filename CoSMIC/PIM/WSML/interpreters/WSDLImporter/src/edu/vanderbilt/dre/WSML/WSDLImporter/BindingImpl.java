package edu.vanderbilt.dre.WSML.WSDLImporter;

import com.ibm.wsdl.*;

public class BindingImpl extends com.ibm.wsdl.BindingImpl
{
  public void accept (Visitor visitor)
  {
    visitor.visitBinding (this);
  }
}
