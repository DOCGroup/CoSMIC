package edu.vanderbilt.dre.WSML.WSDLExporter;

import edu.vanderbilt.isis.wsml.*;
import edu.vanderbilt.isis.udm.*;
import javax.wsdl.*;
import javax.wsdl.factory.*;
import javax.wsdl.xml.*;
import javax.wsdl.extensions.*;
import javax.wsdl.extensions.soap.*;
import javax.wsdl.extensions.schema.*;
import java.io.*;

public class WSDLExportVisitor implements Visitor {

    private WSDLFactory factory = null;

    private FileOutputStream outputFile = null;

    private Definition def = null;

    public WSDLExportVisitor (WSDLFactory factory, String outputFileName) {
        try {
            this.factory = factory;
            this.outputFile = new FileOutputStream (outputFileName);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (SecurityException e) {
            e.printStackTrace();
        }
    }

    public void dump () {
        try {
            WSDLWriter writer = this.factory.newWSDLWriter();
            writer.setFeature("javax.wsdl.verbose", true);
            writer.setFeature("javax.wsdl.importDocuments", true);
            writer.writeWSDL (this.def, outputFile);
        } catch (WSDLException e) {
            e.printStackTrace();
        }
    }

    public void visitRootFolder (RootFolder folder) {
    }

}
