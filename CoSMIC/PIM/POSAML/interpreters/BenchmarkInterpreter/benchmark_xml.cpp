#include "benchmark_xml.h"
bool XML_Writer::write_file(const String &xml_file)
{
  DOMImplementation *impl=DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));
  DOMDocument *doc=impl->createDocument(); 
  DOMElement *root=doc->createElement(XMLString::transcode("benchmark_inputs"));
  doc->appendChild(root);
  DOMElement *child=doc->createElement(XMLString::transcode("iterations"));
  root->appendChild(child);
  /*DOMElement *child=doc->createElement(XMLString::transcode("connections"));
  root->appendChild(child);
  DOMElement *child=doc->createElement(XMLString::transcode("data));
  root->appendChild(child);
  DOMElement *child=doc->createElement(XMLString::transcode("data_exchanges"));
  root->appendChild(child);
  DOMElement *child=doc->createElement(XMLString::transcode("reactor_inputs"));
  root->appendChild(child);
  DOMElement *reactor_child=doc->createElement(XMLString::transcode("reactor_type"));
  child->appendChild(reactor_child);*/
  DOMWriter *writer=impl->createDOMWriter();
  XMLFormatTarget *myFormTarget = new LocalFileFormatTarget(xml_file.c_str());
  DOMElement *serialize_doc=doc->getDocumentElement(); 
  writer->writeNode(myFormTarget,*serialize_doc); 
  return true;

}