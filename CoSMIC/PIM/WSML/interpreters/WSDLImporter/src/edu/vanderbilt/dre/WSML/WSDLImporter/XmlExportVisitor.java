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
import org.w3c.dom.Element;
import org.w3c.dom.ls.*;
import java.lang.*;

public class XmlExportVisitor implements Visitor {
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

    private Operation currOp = null;

    private int objCounter = 0;

    private Map<QName, Object> typeMap = new HashMap<QName, Object>();

    private Map<QName, Model> messageMap = new HashMap<QName, Model>();

    private Map<QName, Model> portTypeMap = new HashMap<QName, Model>();

    private Map<QName, Model> bindingMap = new HashMap<QName, Model>();

    private Map<QName, Model> serviceMap = new HashMap<QName, Model>();

    private Map<QName, Model> importMap = new HashMap<QName, Model>();

    private Map<Operation, Model> operMap = new HashMap<Operation, Model>();

    private Map<Input, Model> inputMap = new HashMap<Input, Model>();

    private Map<Output, Model> outputMap = new HashMap<Output, Model>();

    private Map<Fault, Model> faultMap = new HashMap<Fault, Model>();

    private Map<QName, Reference> partMap = new HashMap<QName, Reference>();

    private int xPos = 12;
    private int yPos = 12;

    private static final String EMPTYSTRING = new String();

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

    public XmlExportVisitor(String defName, String outputFileName) {
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

            FileOutputStream outFile = new FileOutputStream (outputFileName);
            this.writer = dbimplLS.createLSSerializer();
            this.output = dbimplLS.createLSOutput();
            this.output.setEncoding ("UTF-8");
            this.output.setByteStream (outFile);

            this.docElement = this.doc.getDocumentElement();
            this.docElement.setAttribute ("metaname", "WSML");

            Name name = this.objFactory.createName();
            name.setContent (defName);

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
            this.rootFolder.setName (this.setElementName (defName));

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

    public Reference createGmeReference (String name, String kind,
                                         String role) {
        Reference ref = this.objFactory.createReference();
        ref.setId (this.createGmeId(GmeKind.Reference));
        ref.setName(this.setElementName(name));
        ref.setKind(kind);
        ref.setRole(role);
        return ref;
    }

    public Connection createGmeConnection (String name, String kind,
                                           String role) {
        Connection conn = this.objFactory.createConnection();
        conn.setId (this.createGmeId(GmeKind.Connection));
        conn.setName(this.setElementName(name));
        conn.setKind(kind);
        conn.setRole(role);
        return conn;
    }

    public Connpoint createGmeConnpoint (String role) {
        Connpoint conn = this.objFactory.createConnpoint();
        conn.setRole(role);
        return conn;
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

    public Regnode createAutoRouterPref (String value) {
        // autorouterpref registry node
        Regnode autorouterpref = this.createGmeRegnode ("autorouterPref",
                                                        null,
                                                        true);
        Value val = this.objFactory.createValue();
        val.setContent(value);
        autorouterpref.setValue (val);

        return autorouterpref;
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
            this.typeMap.put (qname, atom);
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


    public void visitBinding (Binding binding) {
        String localName = binding.getQName().getLocalPart();
        Model bindingModel = this.createGmeModel (localName, "Binding",
                                                  "Binding");
        Regnode partregs = this.createPartRegs (xPos, yPos);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(bindingModel);
        PortType bindingPortType = binding.getPortType();
        Model refPortType = this.portTypeMap.get(bindingPortType.getQName());
        Connection portType = this.createGmeConnection ("BindingPortType",
                                                        "BindingPortType",
                                                        "BindingPortType");
        Regnode autoRouter = this.createAutoRouterPref("We");
        portType.getRegnodeOrConstraintOrConnpoint().add(autoRouter);

        Connpoint src = this.createGmeConnpoint ("src");
        src.setTarget(bindingModel);
        portType.getRegnodeOrConstraintOrConnpoint().add(src);
        Connpoint dst = this.createGmeConnpoint ("dst");
        dst.setTarget(refPortType);
        portType.getRegnodeOrConstraintOrConnpoint().add(dst);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(portType);

        List extElements = binding.getExtensibilityElements();
        Iterator iterator = extElements.iterator();
        while (iterator.hasNext()) {
            ExtensibilityElement elem = (ExtensibilityElement)iterator.next();
            if (elem instanceof SOAPBinding) {
                SOAPBinding soapBinding = (SOAPBinding)elem;
                this.push (bindingModel);
                xPos = yPos = 12;
                this.visitSOAPBinding(soapBinding);
                this.pop();
            }
        }

        List bindingOperations = binding.getBindingOperations();
        iterator = bindingOperations.iterator();
        while (iterator.hasNext()) {
            BindingOperation bindOp = (BindingOperation)iterator.next();
            this.push(bindingModel);
            this.visitBindingOperation(bindOp);
            this.pop();
        }
    }

    public void visitBindingFault (BindingFault bindingFault)
    {}

    public void visitBindingInput (BindingInput bindingInput) {


    }

    public void visitBindingOperation (BindingOperation bindingOperation) {
        String localName = bindingOperation.getName();
        Model bindOp = this.createGmeModel (localName, "BindingOperation",
                                            "BindingOperation");
        this.currModel.getRegnodeOrConstraintOrAttribute().add (bindOp);
        Regnode partregs = this.createPartRegs (xPos, yPos);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(bindOp);

        List extElements = bindingOperation.getExtensibilityElements();
        Iterator iterator = extElements.iterator();
        while (iterator.hasNext()) {
            ExtensibilityElement elem = (ExtensibilityElement)iterator.next();
            if (elem instanceof SOAPOperation) {
                SOAPOperation soapOperation = (SOAPOperation)elem;
                this.push (bindOp);
                xPos = yPos = 12;
                this.visitSOAPOperation(soapOperation);
                this.pop();
            }
        }

        Operation op = bindingOperation.getOperation();
        // The current BindingOperation that is being visited.  Used by the
        // Binding* functions to retrieve otherwise impossible to retrieve
        // information.
        this.currOp = op;
        Model operationRefModel = this.operMap.get(op);

        // Create the OperationRef
        Reference operationRef
            = this.createGmeReference (op.getName(),
                                       "OperationRef", "OperationRef");
        xPos += 168;
        partregs = this.createPartRegs(xPos, yPos);
        operationRef.getRegnodeOrConstraintOrAttribute().add(partregs);
        operationRef.setReferred(operationRefModel);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(operationRef);

        // Create the BindsOperation connection
        Connection bindsOperation = this.createGmeConnection ("BindsOperation",
                                                              "BindsOperation",
                                                              "BindsOperation");
        Regnode autoRouter = this.createAutoRouterPref ("Ew");
        bindsOperation.getRegnodeOrConstraintOrConnpoint().add(autoRouter);

        Connpoint src = this.createGmeConnpoint ("src");
        src.setTarget(bindOp);
        bindsOperation.getRegnodeOrConstraintOrConnpoint().add(src);
        Connpoint dst = this.createGmeConnpoint ("dst");
        dst.setTarget(operationRefModel);
        bindsOperation.getRegnodeOrConstraintOrConnpoint().add(dst);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(bindsOperation);


        BindingInput bindInput = bindingOperation.getBindingInput();
        if (bindInput != null) {
            this.push(bindOp);
            this.visitBindingInput (bindInput);
            this.pop();
        }
        BindingOutput bindOutput = bindingOperation.getBindingOutput();
        if (bindOutput != null) {
            this.push(bindOp);
            this.visitBindingOutput (bindOutput);
            this.pop();
        }
        Map bindingFaults = bindingOperation.getBindingFaults();
        iterator = bindingFaults.values.iterator();
        while (iterator.hasNext()) {
            BindingFault bindFault = (BindingFault)iterator.next();
            this.push(bindOp);
            this.visitBindingFault(bindFault);
            this.pop();
        }
    }

    public void visitBindingOutput (BindingOutput bindingOutput)
    {}

    public void visitDefinition (Definition definition) {

        // Create the Definitions model
        String defName = definition.getQName().getLocalPart();
        this.pushNamespace(definition.getTargetNamespace());
        Model def = this.createGmeModel(defName, "Definitions", null);
        this.typeMap.put (definition.getQName(), def);
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

        Map imports = definition.getImports();
        Iterator iter = imports.values().iterator();
        while (iter.hasNext()) {
            Import imp = (Import)iter.next();
            this.visitImport (imp);
        }

        Types types = definition.getTypes();
        this.visitTypes (types);

        xPos += 84;
        // Wrap around to the next row (based on a screen of width
        // 1600x1200 with GME maximized)
        if (xPos > 1084) {
            xPos = 12;
            yPos += 84;
        }

        Map messages = definition.getMessages();
        iter = messages.values().iterator();
        while (iter.hasNext()) {
            Message msg = (Message)iter.next();
            this.visitMessage (msg);
            xPos += 84;
            // Wrap around to the next row (based on a screen of width
            // 1600x1200 with GME maximized)
            if (xPos > 1084) {
                xPos = 12;
                yPos += 84;
            }
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

    public void visitFault (Fault fault) {
        String localName = fault.getName();
        Model faultModel = this.createGmeModel (localName, "Fault", "Fault");
        Regnode partregs = this.createPartRegs(xPos, yPos);
        faultModel.getRegnodeOrConstraintOrAttribute().add(partregs);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(faultModel);
        this.faultMap.put (fault, faultModel);
        // Create the message reference
        Message refMessage = fault.getMessage();
        Model refMsgModel = this.messageMap.get (refMessage.getQName());
        Reference faultMsgRef
            = this.createGmeReference (refMessage.getQName().getLocalPart(),
                                       "MessageRef", "MessageRef");
        xPos += 168;
        partregs = this.createPartRegs(xPos, yPos);
        faultMsgRef.getRegnodeOrConstraintOrAttribute().add(partregs);
        faultMsgRef.setReferred(refMsgModel);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(faultMsgRef);

        Connection faultMsgConn = this.createGmeConnection ("FaultMessage",
                                                             "FaultMessage",
                                                             "FaultMessage");
        Regnode autoRouter = this.createAutoRouterPref("Ew");
        faultMsgConn.getRegnodeOrConstraintOrConnpoint().add(autoRouter);

        Connpoint src = this.createGmeConnpoint ("src");
        src.setTarget(faultModel);
        faultMsgConn.getRegnodeOrConstraintOrConnpoint().add(src);
        Connpoint dst = this.createGmeConnpoint ("dst");
        dst.setTarget(faultMsgRef);
        faultMsgConn.getRegnodeOrConstraintOrConnpoint().add(dst);

        this.currModel.getRegnodeOrConstraintOrAttribute().add(faultMsgConn);

    }

    public void visitImport (Import imp)
    {}

    public void visitInput (Input input) {
        String localName = input.getName();
        Model inputModel = this.createGmeModel (localName, "Input", "Input");
        Regnode partregs = this.createPartRegs(xPos, yPos);
        inputModel.getRegnodeOrConstraintOrAttribute().add(partregs);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(inputModel);
        this.inputMap(input, inputModel);
        // Create the message reference
        Message refMessage = input.getMessage();
        Model refMsgModel = this.messageMap.get (refMessage.getQName());
        Reference inputMsgRef
            = this.createGmeReference (refMessage.getQName().getLocalPart(),
                                       "MessageRef", "MessageRef");
        xPos += 168;
        partregs = this.createPartRegs(xPos, yPos);
        inputMsgRef.getRegnodeOrConstraintOrAttribute().add(partregs);
        inputMsgRef.setReferred(refMsgModel);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(inputMsgRef);

        Connection inputMsgConn = this.createGmeConnection ("InputMessage",
                                                            "InputMessage",
                                                            "InputMessage");
        Regnode autoRouter = this.createAutoRouterPref("Ew");
        inputMsgConn.getRegnodeOrConstraintOrConnpoint().add(autoRouter);
        Connpoint src = this.createGmeConnpoint ("src");
        src.setTarget(inputModel);
        inputMsgConn.getRegnodeOrConstraintOrConnpoint().add(src);
        Connpoint dst = this.createGmeConnpoint ("dst");
        dst.setTarget(inputMsgRef);
        inputMsgConn.getRegnodeOrConstraintOrConnpoint().add(dst);

        this.currModel.getRegnodeOrConstraintOrAttribute().add(inputMsgConn);

    }

    public void visitMessage (Message message) {
        String localName = message.getQName().getLocalPart();
        Model msgModel = this.createGmeModel(localName, "Message", "Message");
        Regnode partregs = this.createPartRegs(xPos, yPos);
        msgModel.getRegnodeOrConstraintOrAttribute().add(partregs);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(msgModel);
        this.messageMap.put (message.getQName(), msgModel);
        Map parts = message.getParts();
        Iterator partIter = parts.values().iterator();
        xPos = yPos = 12;
        while (partIter.hasNext()) {
            Part part = (Part)partIter.next();
            this.push(msgModel);
            this.visitPart (part);
            this.pop();
        }
    }

    public void visitOperation (Operation oper) {
        String localName = oper.getName();
        OperationType style = oper.getStyle();
        String kind = null;
        String role = null;
        if (style.equals (OperationType.ONE_WAY)) {
            kind = role = "OneWayOperation";
        } else if (style.equals(OperationType.REQUEST_RESPONSE)) {
            kind = role = "RequestResponseOperation";
        } else if (style.equals(OperationType.SOLICIT_RESPONSE)) {
            kind = role = "SolicitResponseOperation";
        } else if (style.equals(OperationType.NOTIFICATION)) {
            kind = role = "NotificationOperation";
        } else {
            System.out.println ("Error: Unknown OperationStyle for operation"
                                + localName);
            System.exit(1);
        }
        Model operModel = this.createGmeModel(localName, kind, role);
        Regnode partregs = this.createPartRegs(xPos, yPos);
        operModel.getRegnodeOrConstraintOrAttribute().add(partregs);
        String params = "";
        if (style.equals(OperationType.REQUEST_RESPONSE)
            || style.equals(OperationType.SOLICIT_RESPONSE)) {
            List parameterOrdering = oper.getParameterOrdering();
            if (parameterOrdering != null) {
                Iterator paramIter = parameterOrdering.iterator();
                while (paramIter.hasNext()) {
                    params = params + (String)paramIter.next() + " ";
                }
            }
        }
        Attribute parameterOrder = this.createGmeAttribute("parameterOrder",
                                                           null,
                                                           params);
        operModel.getRegnodeOrConstraintOrAttribute().add(parameterOrder);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(operModel);
        this.operMap.put(oper, operModel);
        Input input = oper.getInput();
        Output output = oper.getOutput();
        Map faults = oper.getFaults();
        if (style.equals (OperationType.ONE_WAY)) {
            this.push(operModel);
            if (input.getName() == null) {
                input.setName (localName);
            }
            this.visitInput(input);
            this.pop();
        } else if (style.equals(OperationType.NOTIFICATION)) {
            this.push(operModel);
            if (output.getName() == null) {
                output.setName (localName);
            }
            this.visitOutput(output);
            this.pop();
        } else {
            this.push(operModel);
            if (style.equals(OperationType.REQUEST_RESPONSE)) {
                if (input.getName() == null)
                    input.setName (localName+"Request");
                if (output.getName() == null)
                    output.setName (localName+"Response");
            } else if (style.equals(OperationType.SOLICIT_RESPONSE)) {
                if (output.getName() == null)
                    output.setName (localName+"Solicit");
                if (input.getName() == null)
                    input.setName (localName+"Response");
            }
            this.visitInput(input);
            this.visitOutput(output);
            Iterator faultIter = faults.values().iterator();
            while (faultIter.hasNext()) {
                Fault fault = (Fault)faultIter.next();
                this.visitFault (fault);
            }
            this.pop();
        }
    }

    public void visitOutput (Output output) {
        String localName = output.getName();
        Model outputModel = this.createGmeModel (localName, "Output", "Output");
        Regnode partregs = this.createPartRegs(xPos, yPos);
        outputModel.getRegnodeOrConstraintOrAttribute().add(partregs);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(outputModel);
        this.outputMap.put(output, outputModel);
        // Create the message reference
        Message refMessage = output.getMessage();
        Model refMsgModel = this.messageMap.get (refMessage.getQName());
        Reference outputMsgRef
            = this.createGmeReference (refMessage.getQName().getLocalPart(),
                                       "MessageRef", "MessageRef");
        xPos += 168;
        partregs = this.createPartRegs(xPos, yPos);
        outputMsgRef.getRegnodeOrConstraintOrAttribute().add(partregs);
        outputMsgRef.setReferred(refMsgModel);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(outputMsgRef);

        Connection outputMsgConn = this.createGmeConnection ("OutputMessage",
                                                            "OutputMessage",
                                                            "OutputMessage");
        Regnode autoRouter = this.createAutoRouterPref("Ew");
        outputMsgConn.getRegnodeOrConstraintOrConnpoint().add(autoRouter);

        Connpoint src = this.createGmeConnpoint ("src");
        src.setTarget(outputModel);
        outputMsgConn.getRegnodeOrConstraintOrConnpoint().add(src);
        Connpoint dst = this.createGmeConnpoint ("dst");
        dst.setTarget(outputMsgRef);
        outputMsgConn.getRegnodeOrConstraintOrConnpoint().add(dst);

        this.currModel.getRegnodeOrConstraintOrAttribute().add(outputMsgConn);

    }

    public void visitPart (Part part) {
        String localName = part.getName();
        Reference ref = this.createGmeReference (localName, "Part", "Part");
        Regnode partregs = this.createPartRegs(xPos, yPos);
        ref.getRegnodeOrConstraintOrAttribute().add(partregs);
        QName referredName = part.getTypeName();
        if (referredName == null) {
            referredName = part.getElementName();
            if (referredName == null) {
                System.out.println ("Warning: part" + localName
                                    + "is a null reference");
            }
        }
        Object referred = this.typeMap.get(referredName);
        if (referred == null) {
            System.out.println ("Error: Unknown type referred by part"
                                + localName);
            System.exit(1);
        }
        ref.setReferred(referred);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(ref);
        String messageName = this.currModel.getName().getContent();
        QName msgPartQName = new QName (this.currNs, messageName + localName);
        this.partMap.put (msgPartQName, ref);
    }

    public void visitPort (Port port)
    {}

    public void visitPortType (PortType portType) {
        String localName = portType.getQName().getLocalPart();
        Model portTypeModel = this.createGmeModel (localName, "PortType",
                                                   "PortType");
        Regnode partregs = this.createPartRegs(xPos, yPos);
        portTypeModel.getRegnodeOrConstraintOrAttribute().add(partregs);
        this.currModel.getRegnodeOrConstraintOrAttribute().add(portTypeModel);
        this.portTypeMap.put (portType.getQName(), portTypeModel);
        List operations = portType.getOperations();
        Iterator opIter = operations.iterator();
        xPos = yPos = 12;
        while (opIter.hasNext()) {
            Operation op = (Operation)opIter.next();
            this.push(portTypeModel);
            this.visitOperation(op);
            this.pop();
        }
    }


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
            if (elem instanceof Schema) {
                Schema schema = (Schema)elem;
                this.push (typeModel);
                this.visitSchema(schema);
                this.pop();
            }
        }
    }

    public void visitSOAPAddress (SOAPAddress soapAddress)
    {}

    public void visitSOAPBinding (SOAPBinding soapBinding) {
        String name = soapBinding.getElementType().toString();
        Atom binding = this.createGmeAtom (name, "SOAPBinding", "SOAPBinding");
        this.currModel.getRegnodeOrConstraintOrAttribute().add(binding);
        Regnode partregs = this.createPartRegs (xPos, yPos);
        binding.getRegnodeOrConstraintOrAttribute().add(partregs);

        Boolean req = soapBinding.getRequired();
        Attribute required = this.createGmeAttribute("required",null,
                                                     req.toString());
        this.binding.getRegnodeOrConstraintOrAttribute().add(required);

        Attribute style = this.createGmeAttribute("style", null,
                                                  binding.getStyle());
        this.binding.getRegnodeOrConstraintOrAttribute().add(style);

        Attribute transport
            = this.createGmeAttribute ("transport", null,
                                       binding.getTransportURI());
        this.binding.getRegnodeOrConstraintOrAttribute().add(transport);
    }

    public void visitSOAPBody (SOAPBody soapBody)
    {}

    public void visitSOAPFault (SOAPFault soapFault)
    {}

    public void visitSOAPHeader (SOAPHeader soapHeader)
    {}

    public void visitSOAPHeaderFault (SOAPHeaderFault soapHeaderFault)
    {}

    public void visitSOAPOperation (SOAPOperation soapOperation) {

        String name = soapOperation.getElementType().toString();
        Atom operation = this.createGmeAtom (name, "SOAPOperation",
                                           "SOAPOperation");
        this.currModel.getRegnodeOrConstraintOrAttribute().add(operation);
        Regnode partregs = this.createPartRegs (xPos, yPos);
        operation.getRegnodeOrConstraintOrAttribute().add(partregs);

        Boolean req = soapOperation.getRequired();
        Attribute required = this.createGmeAttribute("required", null,
                                                     req.toString());
        this.operation.getRegnodeOrConstraintOrAttribute().add(required);

        Attribute style = this.createGmeAttribute("style", null,
                                                  operation.getStyle());
        this.operation.getRegnodeOrConstraintOrAttribute().add(style);

        Attribute transport
            = this.createGmeAttribute ("soapAction", null,
                                       operation.getSoapActionURI());
        this.operation.getRegnodeOrConstraintOrAttribute().add(transport);
    }

    public void visitElement (org.w3c.dom.Element visitedEle, Model parent,
                              int level) {
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
        QName qname = new QName (namespaceURI, localName);
        if (qname.equals (COMPLEXTYPE)
            || qname.equals (SIMPLETYPE)
            || qname.equals (ELEMENT)
            || qname.equals (ATTRIBUTE)
            || qname.equals (GROUP)
            || qname.equals (ATTRIBUTEGROUP)
            || qname.equals (KEY)
            || qname.equals (KEYREF)
            || qname.equals (UNIQUE)
            || qname.equals (NOTATION)) {
            Attribute attr = this.createGmeAttribute ("schemaType",
                                                      null, localName);
            model.getRegnodeOrConstraintOrAttribute().add(attr);
            if (visitedEle.getAttributeNode("name") != null) {
                String name = visitedEle.getAttribute ("name");
                model.setName(this.setElementName(name));
                // Add top-level elements of schema to the list of types that
                // can be reference d
                if (level == 0) {
                    QName eleQName = new QName (this.currNs, name);
                    this.typeMap.put (eleQName, model);
                }
            }
        } else if (qname.equals (ANY) || qname.equals (ANYATTRIBUTE)
                   || qname.equals (ANNOTATION)
                   || qname.equals (DOCUMENTATION)
                   || qname.equals (APPINFO)
                   || qname.equals (INCLUDE)
                   || qname.equals (IMPORT)
                   || qname.equals (REDEFINE)) {
            Attribute attr = this.createGmeAttribute ("schemaType",
                                                      null, localName);
            model.getRegnodeOrConstraintOrAttribute().add(attr);
        } else {
            Attribute attr = this.createGmeAttribute ("schemaType",
                                                      null, "local");
            model.getRegnodeOrConstraintOrAttribute().add(attr);
        }

        int newLevel = level + 1;
        NodeList children = visitedEle.getChildNodes();
        for (int i = 0; i < children.getLength(); ++i) {
            Node child = children.item (i);
            if (child instanceof Element) {
                org.w3c.dom.Element childEle = (org.w3c.dom.Element)child;
                this.visitElement (childEle, model, newLevel);
            }
        }
    }

    public void visitSchema (Schema schema) {
        boolean popNamespace = false;
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
                popNamespace = true;
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

        NodeList children = schemaEle.getChildNodes();
        for (int i = 0; i < children.getLength(); ++i) {
            Node child = children.item(i);
            if (child instanceof Element) {
                org.w3c.dom.Element childEle = (org.w3c.dom.Element)child;
                this.visitElement (childEle, schemaModel, 0);
            }
        }

        if (popNamespace)
            this.popNamespace();
    }

    public void visitSchemaImport (SchemaImport schemaImport)
    {}

    public void visitSchemaReference (SchemaReference schemaReference)
    {}

}
