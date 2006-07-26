package edu.vanderbilt.dre.WSML.WSDLExporter;

import java.io.*;
import javax.wsdl.*;
import javax.wsdl.factory.*;
import javax.wsdl.xml.*;
import javax.wsdl.extensions.*;
import javax.wsdl.extensions.soap.*;
import javax.wsdl.extensions.schema.*;
import javax.xml.*;
import javax.xml.parsers.*;
import javax.xml.namespace.*;
import java.util.*;
import org.w3c.dom.*;
import org.w3c.dom.ls.*;
import java.lang.*;
import edu.vanderbilt.isis.wsml.*;
import edu.vanderbilt.isis.udm.*;
import edu.vanderbilt.dre.WSML.*;

public class WSDLExporter {

    public static void main (String[] args) {
        if (args == null || args.length < 2) {
            System.err.println("Usage: java edu.vanderbilt.dre.WSML.WSDLExporter <InputModel.xml> <OutputWSDL.wsdl>");
            return;
        }
        String inputModel = new String (args[0]);
        String outputFile = new String (args[1]);

        try {

        // open the data network
        RootFolderFileFactory gtf
            = FactoryRepository.getWSMLRootFolderFileFactory();
        RootFolder root = gtf.open(inputModel);

        WSDLFactory factory = WSDLFactory.newInstance();
        WSDLExportVisitor visitor = new WSDLExportVisitor (factory, outputFile);
        visitor.visitRootFolder (root);

        // check constraints
        gtf.checkConstraints();

        // close and save the data network
        gtf.save();

        } catch (WSDLException e) {
            e.printStackTrace();
        } catch (UdmException e) {
            e.printStackTrace();
        }
    }
}
