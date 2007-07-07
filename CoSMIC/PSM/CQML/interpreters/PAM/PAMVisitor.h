// $Id$

#ifndef PAM_VISITOR_H
#define PAM_VISITOR_H

#include <memory>
#include <stack>
#include <map>
#include "CQML/CQML.h"

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "Utils/XercesString.h"
#include "Utils/Utils.h"
#include "PAM/PAM_Export.h"

namespace CQML
{
  using xercesc::DOMImplementation;
  using xercesc::DOMDocument;
  using xercesc::DOMElement;
  using xercesc::DOMWriter;
  using xercesc::XMLFormatTarget;
  using xercesc::LocalFileFormatTarget;

  using std::set;
  using std::vector;
  using std::string;
  using std::map;

  class PAM_Export PAMVisitor: public Visitor
  {
    public:
    PAMVisitor (const std::string& outputPath);
    ~PAMVisitor();

    virtual void Visit_RootFolder(const RootFolder&);

    private:

    void init();
    void initTarget (const string& fileName);
    void initDocument (const string& rootName);
    void initRootAttributes();
    void dumpDocument();

    void push();
    void pop();
    string ExtractName (Udm::Object obj);

    private:

    DOMImplementation*  impl_;
    DOMDocument*        doc_;
    DOMElement*         root_;
    DOMElement*         curr_;
    DOMWriter*          serializer_;
    XMLFormatTarget*    target_;
    string              outputPath_;
    stack<DOMElement*> curr_stack_;

  };
}

#endif /* PAM_VISITOR_H */
