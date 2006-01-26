#ifndef _CUTS_PICML_VISITOR_H_
#define _CUTS_PICML_VISITOR_H_

#include "cuts/fe/PICML/PICMLVisitor.h"

namespace CUTS_PIR
{
  class Component;
  class Event;
  class File;
  class Module;
}

namespace PICML_BON
{
  class CUTS_PICMLVisitor :
    public PICML_BON::PICMLVisitor
  {
  public:
    CUTS_PICMLVisitor (void);

    virtual ~CUTS_PICMLVisitor (void);

    bool visitFile (const File & object);

    bool visitPackage (const Package & object);

    bool visitComponent (const Component & object);

    bool visitComponentFactory (const ComponentFactory & object);

    bool visitManagesComponent (const ManagesComponent & object);

    bool visitInterfaceDefinitions (const InterfaceDefinitions & object);

    bool visitEvent (const Event & object);

    bool visitInEventPort (const InEventPort & object);

  private:
    void visitPackageContents (const BON::Model & object);

    CUTS_PIR::File * file_;

    CUTS_PIR::Module * module_;

    CUTS_PIR::Component * component_;

    CUTS_PIR::Event * event_;
  };
}

#endif  // !defined _CUTS_PICML_VISITOR_H_
