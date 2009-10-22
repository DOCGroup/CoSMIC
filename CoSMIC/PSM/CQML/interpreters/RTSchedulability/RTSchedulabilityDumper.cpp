// $Id$

#include "Utils/xercesc/XercesString.h"
#include "Utils/Utils.h"

#include "RTSchedulabilityDumper.h"

#include <algorithm>
#include <functional>
#include <sstream>

#include "UmlExt.h"
#include "common.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

using Utils::XStr;
using Utils::CreateUuid;

namespace CQML
  {
    RTSchedulabilityDumper::RTSchedulabilityDumper (const std::string& output_path)
      : DOMBuilder (output_path)
      { }

  }
