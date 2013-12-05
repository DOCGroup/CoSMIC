// -*- C++ -*-
// $Id:$
#ifndef RTSCHEDULABILITY_DUMPER_H
#define RTSCHEDULABILITY_DUMPER_H

#include <memory>
#include <stack>
#include <map>

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

#include "CQML/CQML.h"
#include "RTSchedulability_Export.h"
#include "RTSchedulabilityAdder.h"
#include "common.h"

namespace CQML
  {
    using xercesc::DOMImplementation;
    using xercesc::DOMDocument;
    using xercesc::DOMElement;
    using xercesc::DOMLSSerializer;
    using xercesc::XMLFormatTarget;
    using xercesc::LocalFileFormatTarget;


    class RTSchedulabilityDumper : public DOMBuilder
      {

      public:
        RTSchedulabilityDumper(const std::string& outputPath);

      private:

      };

  }
#endif /* RTSCHEDULABILITY_DUMPER_H */
