package edu.vanderbilt.dre.WSML.WSDLImporter;

import javax.wsdl.*;
import javax.wsdl.extensions.soap.*;
import javax.wsdl.extensions.schema.*;
import javax.xml.bind.*;
import javax.xml.parsers.*;
import java.util.*;
import edu.vanderbilt.isis.gme.xme.*;
import org.w3c.dom.*;
import org.w3c.dom.ls.*;

public class XmlExportVisitor implements Visitor
{
    private ObjectFactory objFactory = new ObjectFactory();
    private DocumentBuilderFactory dbf;
    private DocumentBuilder db;
    private DOMImplementation dbimpl;
    private DOMImplementationLS dbimplLS;
    private DocumentType docType;
    private Document doc;
    private JAXBContext jc;
    private Marshaller marshaller;
    private LSSerializer writer;
    private LSOutput output;

    public XmlExportVisitor() {
        try {
            this.dbf = DocumentBuilderFactory.newInstance();
            this.db = dbf.newDocumentBuilder();
            this.dbimpl = db.getDOMImplementation();
            this.dbimplLS =
                (DOMImplementationLS)dbimpl.getFeature ("LS", "3.0");

            this.docType = dbimpl.createDocumentType("project",
                                                     null,
                                                     "mga.dtd");
            this.doc = dbimpl.createDocument (null, "project", docType);
            this.jc = JAXBContext.newInstance("edu.vanderbilt.isis.gme.xme");
            this.marshaller = jc.createMarshaller();

            this.writer = dbimplLS.createLSSerializer();
            this.output = dbimplLS.createLSOutput();
            this.output.setEncoding ("UTF-8");
            this.output.setByteStream (System.out);

            org.w3c.dom.Element docElement = this.doc.getDocumentElement();
            docElement.setAttribute ("metaname", "WSML");

            Name name = this.objFactory.createName();
            name.setContent ("GoogleApi");

            edu.vanderbilt.isis.gme.xme.Comment comment = this.objFactory.createComment();
            comment.setContent ("First try at generating xme");

            Author author = this.objFactory.createAuthor();
            author.setContent ("Lord of the Rings!");

            Folder folder = this.objFactory.createFolder();
            folder.setKind("RootFolder");

            DocumentFragment docFragment = this.doc.createDocumentFragment();
            this.marshaller.marshal (folder, docFragment);
            docElement.appendChild (docFragment);

            this.writer.write (doc, output);

        } catch (ParserConfigurationException e) {
            e.printStackTrace();

        } catch (LSException e) {
            e.printStackTrace();

        } catch (DOMException e) {
            e.printStackTrace();
        } catch (MarshalException e) {
            e.printStackTrace();
        } catch (JAXBException e) {
            e.printStackTrace();
        }
    }


    public void visitBinding (Binding binding)
    {}

    public void visitBindingFault (BindingFault bindingFault)
    {}

    public void visitBindingInput (BindingInput bindingInput)
    {}

    public void visitBindingOperation (BindingOperation bindingOperation)
    {}

    public void visitBindingOutput (BindingOutput bindingOutput)
    {}

    public void visitDefinition (Definition definition) {

        Map imports = definition.getImports();

        Types types = definition.getTypes();
        this.visitTypes (types);

        Map messages = definition.getMessages();

    }

    public void visitFault (Fault fault)
    {}

    public void visitImport (Import imports)
    {}

    public void visitInput (Input input)
    {}

    public void visitMessage (Message message)
    {}

    public void visitOperation (Operation operation)
    {}

    public void visitOutput (Output output)
    {}

    public void visitPart (Part part)
    {}

    public void visitPort (Port port)
    {}

    public void visitPortType (PortType portType)
    {}

    public void visitService (Service service)
    {}

    public void visitTypes (Types types)
    {}

    public void visitSOAPAddress (SOAPAddress soapAddress)
    {}

    public void visitSOAPBinding (SOAPBinding soapBinding)
    {}

    public void visitSOAPBody (SOAPBody soapBody)
    {}

    public void visitSOAPFault (SOAPFault soapFault)
    {}

    public void visitSOAPHeader (SOAPHeader soapHeader)
    {}

    public void visitSOAPHeaderFault (SOAPHeaderFault soapHeaderFault)
    {}

    public void visitSOAPOperation (SOAPOperation soapOperation)
    {}

    public void visitSchema (Schema schema)
    {}

    public void visitSchemaImport (SchemaImport schemaImport)
    {}

    public void visitSchemaReference (SchemaReference schemaReference)
    {}

}
