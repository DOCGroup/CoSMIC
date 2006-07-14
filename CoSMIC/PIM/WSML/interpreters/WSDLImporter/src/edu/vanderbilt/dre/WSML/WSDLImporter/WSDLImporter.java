package edu.vanderbilt.dre.WSML.WSDLImporter;

import javax.wsdl.*;
import javax.wsdl.factory.*;
import javax.wsdl.xml.*;
import edu.vanderbilt.isis.gme.xme.*;
import javax.xml.bind.*;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import org.w3c.dom.ls.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;

public class WSDLImporter
{

  public static void main (String[] args)
  {
    if (args == null)
      {
        System.out.println("Specify a input WSDL file!");
        return;
      }
    String wsdlURI = new String (args[0]);

    try
      {
        WSDLFactory factory = WSDLFactory.newInstance();
        WSDLReader reader = factory.newWSDLReader();

        reader.setFeature("javax.wsdl.verbose", true);
        reader.setFeature("javax.wsdl.importDocuments", true);

        Definition def = reader.readWSDL(wsdlURI);

        ObjectFactory objFactory = new ObjectFactory();

        Folder folder = objFactory.createFolder();
        folder.setKind("RootFolder");

        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        DOMImplementation dbimpl = db.getDOMImplementation();
        DOMImplementationLS dbimplLS
          = (DOMImplementationLS)dbimpl.getFeature ("LS", "3.0");

        DocumentType docType = dbimpl.createDocumentType("project",
                                                         null,
                                                         "mga.dtd");
        Document doc = dbimpl.createDocument (null, "project", docType);
        org.w3c.dom.Element docElement = doc.getDocumentElement();
        docElement.setAttribute ("name", "GoogleApi");
        docElement.setAttribute ("comment", "First try at generating xme");
        docElement.setAttribute ("metaname", "WSML");
        docElement.setAttribute ("author", "Lord of the Rings!");

        DocumentFragment docFragment = doc.createDocumentFragment();
        JAXBContext jc = JAXBContext.newInstance("edu.vanderbilt.isis.gme.xme");
        Marshaller myMarshaller = jc.createMarshaller();
        myMarshaller.marshal (folder, docFragment);
        docElement.appendChild (docFragment);

        //         TransformerFactory transformerFactory = TransformerFactory.newInstance();
        //         Transformer transformer = transformerFactory.newTransformer();
        //         transformer.setOutputProperty("indent", "yes");
        //         transformer.transform(new DOMSource(doc),
        //                               new StreamResult(System.out));


        LSSerializer writer = dbimplLS.createLSSerializer();
        LSOutput output = dbimplLS.createLSOutput();
        output.setEncoding ("UTF-8");
        output.setByteStream (System.out);
        writer.write (doc, output);
      }
    catch (WSDLException e)
      {
        e.printStackTrace();
      }
    catch (ParserConfigurationException e)
      {
        e.printStackTrace();
      }
    catch (LSException e)
      {
        e.printStackTrace();
      }
    catch (DOMException e)
      {
        e.printStackTrace();
      }
    catch (MarshalException e)
      {
        e.printStackTrace();
      }
    catch (JAXBException e)
      {
        e.printStackTrace();
      }
//     catch (TransformerException e)
//       {
//         e.printStackTrace();
//       }

  }
}
