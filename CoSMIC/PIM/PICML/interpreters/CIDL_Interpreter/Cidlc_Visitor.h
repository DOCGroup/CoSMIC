// $Id$

#include <iterator>

#include "PICML/PICML.h"
#include "UdmBase.h"
#include "Uml.h"
#include "UmlExt.h"

#include "IDLStream.h"
#include <fstream>
#include <queue>
#include <stack>

namespace PICML

#include "CIDL_Interpreter/CIDL_Export.h"
{
  class Cidlc_Visitor: public Visitor
  {
    /// Type definition for the set of ComponentFactory objects.
    typedef std::set <PICML::ComponentFactory> ComponentFactory_Set;

  public:
    CIDL_Export Cidlc_Visitor (const std::string& outputPath);
    CIDL_Export ~Cidlc_Visitor();

	  // Visit File
	  CIDL_Export void Visit_File(const File&);
	  CIDL_Export void Visit_ComponentFactory (const ComponentFactory &factory);
	  CIDL_Export void Visit_ComponentRef (const ComponentRef&);
	  CIDL_Export void Visit_Component (const Component&);
	  CIDL_Export void Visit_Package (const Package &);

	  CIDL_Export void process_Factory_decl (ComponentFactory_Set &factory);

  private:
    /// Output directory for the cidl files.
    std::string outputPath_;

    /// Names of the packages that do not contain factories.
    std::queue <std::string> package_names_;
	  
    /// Name of the object managed by the factory.
    std::string managed_name_;

    /// Output stream for the cidl file.
    std::ofstream cidl_file_;

    /// IDL stream writer for the cidl file.
  	IDLStream cidl_writer_;

    /// Flag to help with formatting.
    bool last_package_;
  };
}
