// DOM2.cpp
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <iostream>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/dom/impl/DOMWriterImpl.hpp>

#include "XercesString.h"

#ifdef XERCES_CPP_NAMESPACE_USE
XERCES_CPP_NAMESPACE_USE
#endif

// objectives:
// 1. synthesize an XML document
// 2. traverse/explore an XML document
// 3. modify an XML document

int main(int argc, char *argv[])
{
  DOMDocumentType* pDoctype = NULL;
  DOMDocument* pDoc = NULL;
  DOMNode *pNode = NULL;
  DOMImplementation *pImplement = NULL;
  // these two are needed to display DOM output.
  DOMWriter *pSerializer = NULL;
  XMLFormatTarget *pTarget = NULL;

  // initialize the XML library
  XMLPlatformUtils::Initialize();

  // get a serializer, an instance of DOMWriter (the "LS" stands for load-save).
  pImplement = DOMImplementationRegistry::getDOMImplementation(XercesString("LS"));
  pSerializer = ( (DOMImplementationLS*)pImplement )->createDOMWriter();
  pTarget = new StdOutFormatTarget();
  // set user specified end of line sequence and output encoding
  pSerializer->setNewLine( XercesString("\n") );

  // set feature if the serializer supports the feature/mode
  if ( pSerializer->canSetFeature(XMLUni::fgDOMWRTSplitCdataSections, false) )
    pSerializer->setFeature(XMLUni::fgDOMWRTSplitCdataSections, false);

  if ( pSerializer->canSetFeature(XMLUni::fgDOMWRTDiscardDefaultContent, false) )
    pSerializer->setFeature(XMLUni::fgDOMWRTDiscardDefaultContent, false);

  if ( pSerializer->canSetFeature(XMLUni::fgDOMWRTFormatPrettyPrint, false) )
    pSerializer->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, false);

  if ( pSerializer->canSetFeature(XMLUni::fgDOMWRTBOM, false) )
    pSerializer->setFeature(XMLUni::fgDOMWRTBOM, false);

  // create a document
  pDoctype = pImplement->createDocumentType( XercesString("XHTML"), NULL, NULL );
  pDoc = pImplement->createDocument( XercesString("XHTML"), XercesString("XHTML"),
                                     pDoctype );
  if (pDoc)
    {
      // output related nodes are prefixed with "svg"
      // to distinguish them from input nodes.
      pDoc->setEncoding( XercesString("UTF-8") );
      pDoc->setStandalone(true);
      pDoc->setVersion( XercesString("1.0") );
      DOMElement *pRoot = pDoc->getDocumentElement();

      // Create a root element
      //DOMElement root = pDoc->createElement("XHTML") );
      //pDoc->appendChild(root);
      //Creating the siblings of root
      DOMElement* pHead = pDoc->createElement( XercesString("HEAD") );
      pRoot->appendChild(pHead);
      DOMElement* pBody = pDoc->createElement( XercesString("BODY") );
      pRoot->appendChild(pBody);
      DOMElement* pTitle = pDoc->createElement( XercesString("TITLE") );
      pHead->appendChild(pTitle);
      DOMText*  pHeading = pDoc->createTextNode( XercesString("Document Title") );
      pTitle->appendChild(pHeading);
      //Attaching texts to few siblings
      DOMElement* pParagraph = pDoc->createElement( XercesString("p") );
      pBody->appendChild(pParagraph);
      DOMText*  pFragment = pDoc->createTextNode(
                                                 XercesString("The quick & brown fox jumped over the lazy dog") );
      pParagraph->appendChild(pFragment);
      DOMText* pTextnode =
        pDoc->createTextNode( XercesString("some <random> text goes here") );
      pBody->appendChild(pTextnode);

      DOMElement* pTable = pDoc->createElement( XercesString("table") );
      pBody->appendChild(pTable);

      DOMAttr* pAnnotate    = pDoc->createAttribute( XercesString("width") );
      pAnnotate->setValue( XercesString("100%") );
      pTable->setAttributeNode(pAnnotate);

      DOMElement* pRow = pDoc->createElement( XercesString("tr") );
      pTable->appendChild(pRow);
      DOMElement* pData = pDoc->createElement( XercesString("td") );
      pRow->appendChild(pData);
      DOMText* pContent = pDoc->createTextNode( XercesString("Highlights") );
      pData->appendChild(pContent);

      fflush(stdout);
      pSerializer->writeNode(pTarget, *pDoc);

      // create a walker to visit all text nodes.
      DOMNode* pCurrent = NULL;
      DOMTreeWalker* walker = pDoc->createTreeWalker(pRoot,
                                                     DOMNodeFilter::SHOW_TEXT, NULL, true);
      // use the tree walker to print out the text nodes.
      std::cout<< "walker:\n";
      for ( pCurrent = walker->nextNode();
            pCurrent != 0; pCurrent = walker->nextNode() )
        {
          char *strValue = XMLString::transcode( pCurrent->getNodeValue() );
          std::cout << strValue;
          XMLString::release(&strValue);
        }
      std::cout<< '\n';

      // create an iterator to visit all text nodes.
      DOMNodeIterator* iterator = pDoc->createNodeIterator(pRoot,
                                                           DOMNodeFilter::SHOW_TEXT, NULL, true);
      // use the tree walker to print out the text nodes.
      std::cout<< "iterator:\n";
      for ( pCurrent = iterator->nextNode();
            pCurrent != 0; pCurrent = iterator->nextNode() )
        {
          char *strValue = XMLString::transcode( pCurrent->getNodeValue() );
          std::cout << strValue;
          XMLString::release(&strValue);
        }
      std::cout<< '\n';

      // use the cloneNode to add a duplicate row to the table.
      DOMNode* pClone = pRow->cloneNode(true);
      pTable->appendChild(pClone);
      // add another cloned row to the table.
      pClone = pRow->cloneNode(true);
      pTable->appendChild(pClone);
      // dump out the modified result.
      pSerializer->writeNode(pTarget, *pDoc);

      // make another clone of the first row but this time we'll
      // use an iterator to locate the row's text node, replace
      // the text, and then swap out the entire row in the table.
      pClone = pRow->cloneNode(true);
      DOMNodeIterator* pZap = pDoc->createNodeIterator(pClone,
                                                       DOMNodeFilter::SHOW_TEXT, NULL, true);
      // I can get away with the typecast here since I know
      // the SHOW_TEXT filtering will only return text nodes.
      DOMText* pChange = static_cast<DOMText*>( pZap->nextNode() );
      pChange->setData( XercesString("replacement row") );
      pTable->replaceChild(pClone, pRow);
      // dump out the modified result.
      pSerializer->writeNode(pTarget, *pDoc);

      // blow away the first row altogether and remove
      // the width attribute from the table.
      pTable->removeAttribute( XercesString("width") );
      pTable->removeChild(pClone);
      // dump out the modified result.
      pSerializer->writeNode(pTarget, *pDoc);
      std::cout<< "\n";

      //delete walker;
      //delete iterator;

    }
  getchar();

  delete pTarget;
  delete pSerializer;
  delete pDoc;
  delete pDoctype;

  // terminate the XML library
  XMLPlatformUtils::Terminate();
  return 0;
}
