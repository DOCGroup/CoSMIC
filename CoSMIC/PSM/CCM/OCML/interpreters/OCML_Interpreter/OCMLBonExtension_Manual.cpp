#include "OCMLBonExtension.h"
#include "OCMLUtils.h"
#include <algorithm>

namespace OCML_BON {

  xercesc::DOMElement*
  Described_ItemImpl::xml_export(xercesc::DOMDocument* doc)
  {
    xercesc::DOMElement* node = doc->createElement(XStr(get_kind_name()));
    node->setAttribute(XStr("name"), XStr(getName()));
    node->setAttribute(XStr("description"), XStr(getDescription()));
    node->setAttribute(XStr("title"), XStr(getTitle()));

    return node;
  }

  xercesc::DOMElement*
  Option_CategoryImpl::xml_export(xercesc::DOMDocument* doc)
  {
    xercesc::DOMElement* node = Described_ItemImpl::xml_export(doc);

    children_xml_exporter(getOption_Category(), doc, node);
    children_xml_exporter(getOption(), doc, node);

    return node;
  }

  xercesc::DOMElement*
  OptionImpl::xml_export(xercesc::DOMDocument* doc)
  {
    xercesc::DOMElement* node = Described_ItemImpl::xml_export(doc);

    node->setAttribute(XStr("param-name"), XStr(getParameter_Name()));

    return node;
  }

  xercesc::DOMElement*
  Enum_OptionImpl::xml_export(xercesc::DOMDocument* doc)
  {
    xercesc::DOMElement* node = OptionImpl::xml_export(doc);
    children_xml_exporter(getEnum_Item(), doc, node);
    return node;
  }

} // namespace OCML_BON
