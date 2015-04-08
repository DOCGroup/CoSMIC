#include <iterator>
#include "PICML/PICML.h"
#include "PICML/Visitor.h"
#include "MPCStream.h"

namespace PICML
{
class MPC_Visitor
: public PICML::Visitor
{
public:
  MPC_Visitor (const std::string & outputPath);
  ~MPC_Visitor();

  //
  virtual void Visit_MPC (const PICML::MPC_in);

  // Visit Operations for each of the projects
  virtual void Visit_StubProject(const PICML::StubProject_in );
  virtual void Visit_ServantProject (const PICML::ServantProject_in );
  virtual void Visit_ExecutorProject (const PICML::ExecutorProject_in );

private:
  std::string outputPath_;
};
}
