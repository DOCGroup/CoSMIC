// $Id$ 

#include <iterator>
#include "PICML.h"
#include "MPCStream.h"

namespace PICML
{
  class MPC_Visitor: public Visitor
  {
  public:
    MPC_Visitor (const std::string& outputPath);
    ~MPC_Visitor();

    // 
    virtual void Visit_MPC (const MPC& );

	// Visit Operations for each of the projects
	virtual void Visit_StubProject(const StubProject&);
	virtual void Visit_ServantProject (const ServantProject& );
	virtual void Visit_ExecutorProject (const ExecutorProject& );
    
  private:
    std::string         outputPath_;
  };
}
