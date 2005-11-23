// $Id$

#include <iterator>
#include "PICML/PICML.h"
#include "CIDL_Interpreter/IDLStream.h"
#include "UdmBase.h"
#include "Uml.h"
#include "UmlExt.h"
#include <fstream>

namespace PICML

#include "CIDL_Interpreter/CIDL_Export.h"
{
  class Cidlc_Visitor: public Visitor
  {
  public:
    CIDL_Export Cidlc_Visitor (const std::string& outputPath);
    CIDL_Export ~Cidlc_Visitor();

	// Visit File
	CIDL_Export void Visit_File(const File&);
	CIDL_Export void Visit_ComponentFactory (const ComponentFactory &factory);
	CIDL_Export void Visit_ComponentRef(const ComponentRef&);
	CIDL_Export void Visit_Component(const Component&);
	CIDL_Export void process_Factory_decl (std::set<PICML::ComponentFactory> &factory);

  private:
    std::string         outputPath_;
	std::string         idl_file_name_;
	std::string         package_name_;
	std::string         home_name_;

	// Table of Components along with their Factories
	std::map <PICML::Component, std::vector<std::string> > table_;
  };
}
