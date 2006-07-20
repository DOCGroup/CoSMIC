package edu.vanderbilt.dre.WSML.WSDLImporter;

import javax.wsdl.*;
import javax.wsdl.factory.*;
import javax.wsdl.xml.*;
import java.io.*;

public class WSDLImporter {

    public static void main (String[] args) {

        if (args == null) {
            System.out.println("Specify a input WSDL file!");
            return;
        }
        String wsdlURI = new String (args[0]);
        String outputFileName = new String (args[1]);
        try {
            WSDLFactory factory = WSDLFactory.newInstance();
            WSDLReader reader = factory.newWSDLReader();
            reader.setFeature("javax.wsdl.verbose", true);
            reader.setFeature("javax.wsdl.importDocuments", true);

            Definition def = reader.readWSDL(wsdlURI);
            XmlExportVisitor visitor = new XmlExportVisitor(outputFileName);
            visitor.visitDefinition(def);
            visitor.dump();

        } catch (WSDLException e) {
            e.printStackTrace();
        }
    }
}
