package edu.vanderbilt.dre.WSML.WSDLImporter;

import java.io.*;
import javax.wsdl.*;
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
    private org.w3c.dom.Element docElement;
    private DocumentFragment docFragment;
    private Folder rootFolder;

    private Model currModel = this.objFactory.createModel();
    private Stack<Model> modelStack = new Stack<Model>();

    private String currNs = new String();
    private Stack<String> nsStack = new Stack<String>();

    private int objCounter = 0;
    private Map<QName, String> idMap = new HashMap<QName, String>();

    private int xPos = 12;
    private int yPos = 12;

    // QNames for top-level Schema elements
    private static final QName SCHEMA
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "schema");
    private static final QName COMPLEXTYPE
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "complexType");
    private static final QName ELEMENT
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "element");
    private static final QName ATTRIBUTE
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "attribute");
    private static final QName SIMPLETYPE
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "simpleType");
    private static final QName ANY
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "any");
    private static final QName ANYATTRIBUTE
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "anyAttribute");
    private static final QName GROUP
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "group");
    private static final QName ATTRIBUTEGROUP
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "attributeGroup");
    private static final QName KEY
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "key");
    private static final QName KEYREF
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "keyref");
    private static final QName UNIQUE
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "unique");
    private static final QName ANNOTATION
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "annotation");
    private static final QName DOCUMENTATION
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "documentation");
    private static final QName APPINFO
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "appinfo");
    private static final QName NOTATION
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "notation");
    private static final QName INCLUDE
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "include");
    private static final QName IMPORT
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "import");
    private static final QName REDEFINE
        = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, "redefine");

    private enum GmeKind {
        Model (0x65),
            Atom(0x66),
            Reference(0x67),
            Connection(0x68),
            Folder(0x6a);

        private int value;

        GmeKind (int value) {
            this.value = value;
        }

        public String toString() {
            return this.name();
        }

        public int value () {
            return this.value;
        }

    }

    public void push (Model ele) {
        this.modelStack.push (this.currModel);
        this.currModel = ele;
    }

    public void pop () {
        this.currModel = this.modelStack.pop();
    }

    public void pushNamespace (String ns) {
        this.nsStack.push (this.currNs);
        this.currNs = ns;
    }

    public void popNamespace() {
        this.currNs = this.nsStack.pop();
    }

    public XmlExportVisitor(String outputFileName) {
        try {
            String folderName
                = outputFileName.substring (0,
                                            outputFileName.lastIndexOf ("."));

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

            FileOutputStream outFile = new FileOutputStream (outputFileName);
            this.writer = dbimplLS.createLSSerializer();
            this.output = dbimplLS.createLSOutput();
            this.output.setEncoding ("UTF-8");
            this.output.setByteStream (outFile);

            this.docElement = this.doc.getDocumentElement();
            this.docElement.setAttribute ("metaname", "WSML");

            Name name = this.objFactory.createName();
            name.setContent (folderName);

            this.docFragment = this.doc.createDocumentFragment();
            this.marshaller.marshal (name, this.docFragment);
            this.docElement.appendChild (this.docFragment);

            edu.vanderbilt.isis.gme.xme.Comment
                comment = this.objFactory.createComment();
            comment.setContent ("First try at generating xme");
            this.marshaller.marshal (comment, this.docFragment);
            this.docElement.appendChild (this.docFragment);

            Author author = this.objFactory.createAuthor();
            author.setContent ("Lord of the Rings!");
            this.marshaller.marshal (author, this.docFragment);
            this.docElement.appendChild (this.docFragment);

            this.rootFolder = this.objFactory.createFolder();
            this.rootFolder.setKind("RootFolder");
            this.rootFolder.setId(createGmeId(GmeKind.Folder));
            this.rootFolder.setName (this.setElementName (folderName));

            // Create the SchemaBuiltins model
            Model schemaBuiltins = this.createSchemaBuiltins();
            this.rootFolder.getRegnodeOrConstraintOrFolder().add(schemaBuiltins);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (SecurityException e) {
            e.printStackTrace();
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

    public void dump () {
        try {
            this.marshaller.marshal (this.rootFolder, this.docFragment);
            this.docElement.appendChild (this.docFragment);
            this.writer.write (this.doc, this.output);

        } catch (JAXBException e) {
            e.printStackTrace();
        }

    }

    public String createGmeId (GmeKind kind) {
        return String.format ("id-%04x-%08x", kind.value(), ++objCounter);
    }

    public Model createGmeModel (String name, String kind, String role) {
        Model model = this.objFactory.createModel();
        model.setId (this.createGmeId(GmeKind.Model));
        model.setName (this.setElementName(name));
        model.setKind (kind);
        return model;
    }

    public Atom createGmeAtom (String name, String kind, String role) {
        Atom atom = this.objFactory.createAtom();
        atom.setId (this.createGmeId(GmeKind.Atom));
        atom.setName (this.setElementName(name));
        atom.setKind (kind);
        atom.setRole (role);
        return atom;
    }

    public Attribute createGmeAttribute (String kind, String status,
                                         String value) {
        Attribute attr = this.objFactory.createAttribute();
        attr.setKind(kind);
        attr.setStatus(status);
        Value val = this.objFactory.createValue();
        val.setContent (value);
        attr.setValue(val);
        return attr;
    }

    public Regnode createGmeRegnode (String name,
                                     String status,
                                     boolean isOpaque) {
        Regnode regNode = this.objFactory.createRegnode();
        regNode.setName (name);
        regNode.setStatus(status);
        if (isOpaque)
            regNode.setIsopaque ("yes");
        return regNode;
    }

    public Regnode createPartRegs (int x, int y) {
        // PartRegs registry node
        Regnode partregs = this.createGmeRegnode ("PartRegs", "undefined",
                                                  false);
        Value value = this.objFactory.createValue();
        value.setContent("");
        partregs.setValue (value);

        // ServiceDefinition registry node
        Regnode service = this.createGmeRegnode ("ServiceDefinition",
                                                 "undefined", false);
        service.setValue(value);
        partregs.getRegnode().add (service);

        // Position registry node
        Regnode pos = this.createGmeRegnode ("Position", null, true);
        Value posValue = this.objFactory.createValue();
        posValue.setContent(String.format ("%d,%d", x, y));
        pos.setValue(posValue);
        service.getRegnode().add(pos);

        return partregs;
    }

    public Name setElementName (String name) {
        Name n = this.objFactory.createName();
        n.setContent (name);
        return n;
    }

    public Model createSchemaBuiltins() {
        String [] builtinTypes = { "string", "base64Binary", "boolean",
                                   "hexBinary", "duration", "float",
                                   "dateTime", "decimal", "time", "double",
                                   "date", "anyURI", "gYearMonth", "QName",
                                   "gYear", "NOTATION", "gMonthDay", "gDay",
                                   "gMonth", "normalizedString", "token",
                                   "language", "name", "NMTOKEN", "NMTOKENS",
                                   "NCName", "ID", "IDREF", "IDREFS", "ENTITY",
                                   "ENTITIES", "integer", "nonPositiveInteger",
                                   "negativeInteger", "long", "int", "short",
                                   "byte", "nonNegativeInteger",
                                   "unsignedLong", "unsignedInt",
                                   "unsignedShort", "unsignedByte",
                                   "positiveInteger" };
        Model model = this.createGmeModel ("SchemaBuiltins", "SchemaBuiltins",
                                           null);
        for (String name : builtinTypes) {
            Atom atom = this.createGmeAtom (name, name, name);
            QName qname = new QName (XMLConstants.W3C_XML_SCHEMA_NS_URI, name);
            this.idMap.put (qname, atom.getId());
            Regnode partRegs = this.createPartRegs(xPos, yPos);
            atom.getRegnodeOrConstraintOrAttribute().add(partRegs);
            model.getRegnodeOrConstraintOrAttribute().add(atom);
            xPos += 84;
            // Wrap around to the next row
            // (based on a screen of width 1600x1200 with GME maximized)
            if (xPos > 1084) {
                xPos = 12;
                yPos += 84;
            }
        }
        xPos = yPos = 12;  // Reset values to the global default
        return model;
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

        // Create the Definitions model
        String defName = definition.getQName().getLocalPart();
        this.pushNamespace(definition.getTargetNamespace());
        Model def = this.createGmeModel(defName, "Definitions", null);
        this.idMap.put (definition.getQName(), def.getId());
        this.push (def);
        Attribute attr = this.createGmeAttribute("name", null, defName);
        this.currModel.getRegnodeOrConstraintOrAttribute().add (attr);
        attr = this.createGmeAttribute("targetNamespace",
                                       null,
                                       definition.getTargetNamespace());
        this.currModel.getRegnodeOrConstraintOrAttribute().add (attr);

        // Create the different namespace attributes
        Map namespaces = definition.getNamespaces();
        Iterator keys = namespaces.keySet().iterator();
        while (keys.hasNext()) {
            String prefix = (String)keys.next();
            String uri = (String)namespaces.get(prefix);
            Atom ns =
                this.createGmeAtom ("xmlns" +
                                    (prefix == "" ? prefix : ":" + prefix),
                                    "Attribute", "Attribute");
            Regnode partregs = this.createPartRegs (xPos, yPos);
            ns.getRegnodeOrConstraintOrAttribute().add(partregs);
            xPos += 84;
            // Wrap around to the next row (based on a screen of width
            // 1600x1200 with GME maximized)
            if (xPos > 1084) {
                xPos = 12;
                yPos += 84;
            }
            Attribute value = this.createGmeAttribute ("Value",
                                                       null,
                                                       uri);
            ns.getRegnodeOrConstraintOrAttribute().add(value);
            this.currModel.getRegnodeOrConstraintOrAttribute().add(ns);
        }
        xPos = yPos = 12;

        Map imports = definition.getImports();
        Iterator iter = imports.values().iterator();
        while (iter.hasNext()) {
            Import imp = (Import)iter.next();
            this.visitImport (imp);
        }

        Types types = definition.getTypes();
        this.visitTypes (types);

        Map messages = definition.getMessages();
        iter = messages.values().iterator();
        while (iter.hasNext()) {
            Message msg = (Message)iter.next();
            this.visitMessage (msg);
        }

        Map portTypes = definition.getPortTypes();
        iter = portTypes.values().iterator();
        while (iter.hasNext()) {
            PortType portType = (PortType)iter.next();
            this.visitPortType (portType);
        }

        Map bindings = definition.getBindings();
        iter = bindings.values().iterator();
        while (iter.hasNext()) {
            Binding binding = (Binding)iter.next();
            this.visitBinding (binding);
        }

        Map services = definition.getServices();
        iter= services.values().iterator();
        while (iter.hasNext()) {
            Service service = (Service)iter.next();
            this.visitService (service);
        }
        this.rootFolder.getRegnodeOrConstraintOrFolder().add(this.currModel);
        this.pop();
        this.popNamespace();
    }

    public void visitFault (Fault fault)
    {}

    public void visitImport (Import imp)
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

    public void visitTypes (Types types) {
        Model typeModel = this.createGmeModel ("Types", "Types", "Types");
        this.currModel.getRegnodeOrConstraintOrAttribute().add (typeModel);
        Regnode partregs = this.createPartRegs (xPos, yPos);
        typeModel.getRegnodeOrConstraintOrAttribute().add(partregs);
        List extElements = types.getExtensibilityElements();
        Iterator iterator = extElements.iterator();
        while (iterator.hasNext()) {
            ExtensibilityElement elem = (ExtensibilityElement)iterator.next();
            QName elementType = elem.getElementType();
            System.out.println (elementType);
            Schema schema = (Schema)elem;
            this.push (typeModel);
            this.visitSchema(schema);
            this.pop();
        }
    }

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

    public void visitElement (org.w3c.dom.Element visitedEle, Model parent, int level) {
        String eleName = visitedEle.getNodeName();
        Model model = this.createGmeModel (eleName, "Element", "Element");
        parent.getRegnodeOrConstraintOrAttribute().add (model);
        xPos = yPos = 12;
        Regnode partregs = this.createPartRegs (xPos, yPos);
        model.getRegnodeOrConstraintOrAttribute().add(partregs);
        NamedNodeMap attrs = visitedEle.getAttributes();
        for (int i = 0; i < attrs.getLength(); ++i) {
            Node attrNode = attrs.item (i);
            String attrName = attrNode.getNodeName();
            String attrValue = attrNode.getNodeValue();
            Atom atom = this.createGmeAtom (attrName, "Attribute", "Attribute");
            Attribute attrVal = this.createGmeAttribute ("Value", null,
                                                         attrValue);
            atom.getRegnodeOrConstraintOrAttribute().add(attrVal);
            Regnode atomregs = this.createPartRegs (xPos, yPos);
            xPos += 84;
            // Wrap around to the next row (based on a screen of width
            // 1600x1200 with GME maximized)
            if (xPos > 1084) {
                xPos = 12;
                yPos += 84;
            }
            atom.getRegnodeOrConstraintOrAttribute().add(atomregs);
            model.getRegnodeOrConstraintOrAttribute().add(atom);
            xPos = yPos = 12;
        }
        String localName = visitedEle.getLocalName();
        String namespaceURI = visitedEle.getNamespaceURI();
        Attribute attr = this.createGmeAttribute ("schemaType",
                                                  null, localName);
        model.getRegnodeOrConstraintOrAttribute().add(attr);
        QName qname = new QName (namespaceURI, localName);
        if (level == 0) {
            if (qname.equals (COMPLEXTYPE) || qname.equals (SIMPLETYPE)
                || qname.equals (ELEMENT)) {
                    String name = visitedEle.getAttribute ("name");
                    QName eleQName = new QName (this.currNs, name);
                    this.idMap.put (eleQName, model.getId());
                } else if (qname.equals (ATTRIBUTE) || qname.equals (ANY)
                           || qname.equals (ANYATTRIBUTE)
                           || qname.equals (GROUP)
                           || qname.equals (ATTRIBUTEGROUP)
                           || qname.equals (KEY)
                           || qname.equals (KEYREF)
                           || qname.equals (UNIQUE)
                           || qname.equals (ANNOTATION)
                           || qname.equals (DOCUMENTATION)
                           || qname.equals (APPINFO)
                           || qname.equals (NOTATION)
                           || qname.equals (INCLUDE)
                           || qname.equals (IMPORT)
                           || qname.equals (REDEFINE)) {
                ;
            } else {
                    System.out.println ("Warning: Unknown element <"
                                        + qname + "> found at top-level of Schema");
            }
        }
        int newLevel = level++;
        NodeList children = visitedEle.getChildNodes();
        for (int i = 0; i < children.getLength(); ++i) {
            org.w3c.dom.Element child = (org.w3c.dom.Element)children.item (i);
            this.visitElement (child, model, newLevel);
        }
    }

    public void visitSchema (Schema schema) {
        System.out.println ("Visiting Schema");
        org.w3c.dom.Element schemaEle = schema.getElement();
        String schemaName = schemaEle.getNodeName();
        Model schemaModel = this.createGmeModel(schemaName, "Schema", "Schema");
        this.currModel.getRegnodeOrConstraintOrAttribute().add (schemaModel);
        xPos = yPos= 12;
        Regnode partregs = this.createPartRegs (xPos, yPos);
        schemaModel.getRegnodeOrConstraintOrAttribute().add(partregs);
        NamedNodeMap attrs = schemaEle.getAttributes();
        for (int i = 0; i < attrs.getLength(); ++i) {
            Node attrNode = attrs.item (i);
            String attrName = attrNode.getNodeName();
            String attrValue = attrNode.getNodeValue();
            if (attrNode.getLocalName().equals ("targetNamespace")) {
                Attribute attr = this.createGmeAttribute (attrName,
                                                          null,
                                                          attrValue);
                schemaModel.getRegnodeOrConstraintOrAttribute().add(attr);
                this.pushNamespace(attrValue);
                continue;
            }
            Atom atom = this.createGmeAtom (attrName, "Attribute", "Attribute");
            Attribute attrVal = this.createGmeAttribute ("Value", null,
                                                         attrValue);
            atom.getRegnodeOrConstraintOrAttribute().add(attrVal);
            Regnode atomregs = this.createPartRegs (xPos, yPos);
            xPos += 84;
            // Wrap around to the next row (based on a screen of width
            // 1600x1200 with GME maximized)
            if (xPos > 1084) {
                xPos = 12;
                yPos += 84;
            }
            atom.getRegnodeOrConstraintOrAttribute().add(atomregs);
            schemaModel.getRegnodeOrConstraintOrAttribute().add(atom);
        }

        xPos = yPos = 12;

        List includes = schema.getIncludes();
        Iterator iter = includes.iterator();
        while (iter.hasNext()) {
            SchemaReference schemaRef = (SchemaReference)iter.next();
            this.push (schemaModel);
            this.visitSchemaReference (schemaRef);
            this.pop();
        }

        Map imports = schema.getImports();
        Iterator values = imports.values().iterator();
        while (values.hasNext()) {
            List importList = (List)values.next();
            iter = importList.iterator();
            while (iter.hasNext()) {
                SchemaImport schemaImport = (SchemaImport)iter.next();
                this.push (schemaModel);
                this.visitSchemaImport(schemaImport);
                this.pop();
            }
        }

        List redefines = schema.getRedefines();
        iter = redefines.iterator();
        while (iter.hasNext()) {
            SchemaReference schemaRef = (SchemaReference)iter.next();
            this.push (schemaModel);
            this.visitSchemaReference (schemaRef);
            this.pop();
        }

        this.visitElement (schemaEle, schemaModel, 0);
    }

    public void visitSchemaImport (SchemaImport schemaImport)
    {}

    public void visitSchemaReference (SchemaReference schemaReference)
    {}

}
