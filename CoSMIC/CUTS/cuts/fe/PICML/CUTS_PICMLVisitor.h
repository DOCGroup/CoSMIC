#ifndef _CUTS_PICML_VISITOR_H_
#define _CUTS_PICML_VISITOR_H_

#include "cuts/fe/PICML/PICMLVisitor.h"

namespace CUTS_PIR
{
  class Component;
  class File;
  class Module;

  class Element;
  class Reference_Element;
}

namespace PICML_BON
{
  //===========================================================================
  /**
   * @class CUTS_PICMLVisitor
   */
  //===========================================================================

  class CUTS_PICMLVisitor :
    public PICML_BON::PICMLVisitor
  {
  public:
    /// Constructor.
    CUTS_PICMLVisitor (void);

    /// Destructor.
    virtual ~CUTS_PICMLVisitor (void);

    /// Visit a BON project.
    void visitProject (const BON::Project & project);

    /// Visit a PICML file.
    bool visitFile (const File & object);

    /// Visit a PICML package.
    bool visitPackage (const Package & object);

    /// Visit a PICML component.
    bool visitComponent (const Component & object);

    /// Visit a PICML interface definitions folder.
    bool visitInterfaceDefinitions (const InterfaceDefinitions & object);

    /// Visit a PICML event.
    bool visitEvent (const Event & object);

    /// Visit a PICML event in port.
    bool visitInEventPort (const InEventPort & object);

    /// Visit a PICML object.
    bool visitObject (const Object & object);

    /// Visit a PICML provided request port.
    bool visitProvidedRequestPort (const ProvidedRequestPort & prp);

    /// Visit a PICML worker type.
    bool visitWorkerType (const WorkerType &object);

    bool visitWorker (const Worker & worker);

  private:
    /// Type definition for mapping IDs to elements.
    typedef std::map <std::string, CUTS_PIR::Element *> Reference_Map;

    /// Type definition for mapping IDs to elements.
    typedef std::map <
      std::string, CUTS_PIR::Reference_Element *> Unresolved_References;

    /// Visit the contents of a package/file.
    void visitPackageContents (const BON::Model & object);

    /// Resolve the home for the specified component.
    bool resolveComponentHome (const BON::FCO & component);

    /// The current file.
    CUTS_PIR::File * file_;

    /// The current module.
    CUTS_PIR::Module * module_;

    /// The current component.
    CUTS_PIR::Component * component_;

    /// Collection of elements that can be referenced.
    Reference_Map ref_elements_;

    /// Collection of unresolved references.
    Unresolved_References unresolved_references_;
  };
}

#endif  // !defined _CUTS_PICML_VISITOR_H_
