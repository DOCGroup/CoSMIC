package edu.vanderbilt.dre.WSML.WSDLImporter;

import java.io.*;
import javax.wsdl.*;
import javax.wsdl.factory.*;
import javax.wsdl.xml.*;
import javax.xml.*;
import javax.xml.bind.*;
import javax.xml.parsers.*;
import javax.xml.namespace.*;
import javax.xml.validation.*;
import java.util.*;
import edu.vanderbilt.isis.gme.xme.*;
import org.w3c.dom.*;
import org.w3c.dom.ls.*;
import org.xml.sax.*;
import java.lang.*;
import java.net.*;

public class WSDLImporter {

    public static void main (String[] args) {

        if (args == null || args.length < 2) {
            System.err.println("Usage: java edu.vanderbilt.dre.WSML.WSDLImporter <InputWSDL.wsdl> <OutputXme.xme>");
            return;
        }
        String wsdlURI = new String (args[0]);
        String outputFileName = new String (args[1]);
        try {
            SchemaFactory sf
                = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
            URL schemaURL
                = new URL ("http://schemas.xmlsoap.org/wsdl/2003-02-11.xsd");
            Schema wsdl = sf.newSchema (schemaURL);
            DocumentBuilderFactory
                dbf = DocumentBuilderFactory.newInstance();
            dbf.setIgnoringComments (true);
            dbf.setNamespaceAware (true);
            dbf.setValidating (false);
            dbf.setSchema (wsdl);

            DocumentBuilder db = dbf.newDocumentBuilder();
            Document wsdlDoc = db.parse (wsdlURI);

            WSDLFactory factory = WSDLFactory.newInstance();
            WSDLReader reader = factory.newWSDLReader();
            reader.setFeature("javax.wsdl.verbose", true);
            reader.setFeature("javax.wsdl.importDocuments", true);

            Definition def = reader.readWSDL(wsdlDoc.getDocumentURI(),
                                             wsdlDoc);
            XmlExportVisitor visitor
                = new XmlExportVisitor(def.getQName().getLocalPart(),
                                       outputFileName);
            visitor.visitDefinition(def);
            visitor.dump();
        } catch (ParserConfigurationException e) {
            e.printStackTrace();
        } catch (SAXException e) {
            e.printStackTrace();
        } catch (NullPointerException e) {
            e.printStackTrace();
        } catch (WSDLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
