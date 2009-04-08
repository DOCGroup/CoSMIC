// -*- C++ -*-
// $Id:$
#ifndef __COMMON_H_
#define __COMMON_H_

#include "CQML/CQML.h"
#include <set>
#include <string>
#include <fstream>
#include <stack>

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

#include "UmlExt.h"
#include "Utils/Utils.h"
#include "Utils/XercesString.h"

namespace CQML
  {
    using xercesc::DOMImplementation;
    using xercesc::DOMDocument;
    using xercesc::DOMElement;
    using xercesc::DOMLSSerializer;
    using xercesc::XMLFormatTarget;
    using xercesc::LocalFileFormatTarget;

    using Utils::XStr;
    using Utils::CreateUuid;
  
    extern std::ofstream outfile;         

    template<class T, class Comp>
    bool member(T x, std::set<T,Comp>& s)
      {
        return (s.count(x)==1 ? true : false);
      }

    class DOMBuilder
      {
        public:
          DOMBuilder(const std::string& outputPath);
          virtual ~DOMBuilder ();
          inline virtual void push();
          inline virtual void pop();
          inline virtual DOMDocument *doc ();    
          inline virtual DOMElement *curr ();
          inline virtual void curr (DOMElement *elem);
          virtual void init();
          inline virtual void initTarget (const std::string& fileName);
          inline virtual void initDocument (const std::string& rootName);
          virtual void initRootAttributes();
          inline virtual void dumpDocument();

        protected:
          DOMImplementation*  impl_;
          DOMDocument*        doc_;
          DOMElement*         root_;
          DOMElement*         curr_;
          DOMLSSerializer*          serializer_;
          XMLFormatTarget*    target_;
          std::string         outputPath_;
          std::stack<DOMElement*> curr_stack_;
      };

    class Auto_DOM
      {
      public:
        Auto_DOM (DOMBuilder& b, std::string tag);
        Auto_DOM (DOMBuilder& b, DOMElement *e);
        ~Auto_DOM ();
  
        DOMElement* curr ();

    private:
      DOMBuilder *dom_builder_;
    };

  struct ConnectionInfo
    {
      std::string connection_name;
      std::string client, client_port_name;
      std::string server, server_port_name;
    };

  struct SharedSecurityQoS
    {
      CQML::SecurityQoS securityqos;
      std::set <ConnectionInfo> conn_set;
    };

  struct HostPair
    {
      std::string src;
      std::string dest;
    };
  
  //typedef std::multimap <SecurityQoS, ConnectionInfo> SecurityQoSRequirements;
  
  }

#endif  // __COMMON_H_

