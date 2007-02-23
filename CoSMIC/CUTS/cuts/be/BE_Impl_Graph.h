// -*- C++ -*-

#ifndef _CUTS_BE_IMPL_GRAPH_H_
#define _CUTS_BE_IMPL_GRAPH_H_

#include "BE_Depend_Graph_T.h"
#include "BE_Impl_Node.h"
#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_BE_Impl_Graph
 */
//=============================================================================

class CUTS_BE_Impl_Graph :
  public PICML::Visitor,
  public CUTS_BE_Depend_Graph_T <CUTS_BE_Impl_Node>
{
public:
  CUTS_BE_Impl_Graph (void);

  ~CUTS_BE_Impl_Graph (void);

protected:
  void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer & container);

  void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation & monoimpl);

  void Visit_MonolithprimaryArtifact (
    const PICML::MonolithprimaryArtifact & primary);

  void Visit_Component (
    const PICML::Component & component);

  void Visit_WorkerType (
    const PICML::WorkerType & worker_type);

  void Visit_Worker (
    const PICML::Worker & worker);

  void Visit_WorkerFile (
    const PICML::WorkerFile & file);

  void Visit_WorkerLibrary (
    const PICML::WorkerLibrary & library);

private:
  CUTS_BE_Impl_Node * current_impl_;
};

#endif
