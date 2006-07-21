package edu.vanderbilt.dre.WSML.WSDLImporter;

import java.io.*;
import javax.wsdl.*;
import javax.wsdl.factory.*;
import javax.wsdl.xml.*;
import javax.wsdl.extensions.*;
import javax.wsdl.extensions.soap.*;
import javax.wsdl.extensions.schema.*;
import javax.xml.*;
import javax.xml.bind.*;
import javax.xml.parsers.*;
import javax.xml.namespace.*;
import java.util.*;
import edu.vanderbilt.isis.gme.xme.*;
import org.w3c.dom.*;
import org.w3c.dom.ls.*;
import java.lang.*;

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
            XmlExportVisitor visitor
                = new XmlExportVisitor(def.getQName().getLocalPart(),
                                       outputFileName);
            visitor.visitDefinition(def);
            visitor.dump();

        } catch (WSDLException e) {
            e.printStackTrace();
        }
    }
}
