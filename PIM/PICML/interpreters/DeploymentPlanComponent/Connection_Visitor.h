// -*- C++ -*-

//=============================================================================
/**
 * @file        Connection_Visitor.h
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_DEPLOYMENT_CONNECTION_VISITOR_H_
#define _PICML_DEPLOYMENT_CONNECTION_VISITOR_H_

#include "PIM/PICML/ext/PICML/PICML.h"
#include "PIM/PICML/ext/PICML/Visitor.h"

#include "game/xml/Document.h"

namespace PICML
{
namespace Deployment
{

/**
 * @class DeploymentPlanVisitor
 */
class Connection_Visitor : public Visitor
{
public:
  typedef std::map <ComponentInstance, GAME::Xml::Fragment> instance_map_type;

  /**
   * Initializing constructor.
   */
  Connection_Visitor (GAME::Xml::Document document, const instance_map_type & insts);

  /// Destructor.
  virtual ~Connection_Visitor (void);

  virtual void visit_ComponentInstance (ComponentInstance_in);

  virtual void visit_ProvidedRequestPortInstance (ProvidedRequestPortInstance_in);

  virtual void visit_RequiredRequestPortInstance (RequiredRequestPortInstance_in);

  virtual void visit_OutEventPortInstance (OutEventPortInstance_in );

  virtual void visit_InEventPortInstance (InEventPortInstance_in sink);

  virtual void visit_Invoke (Invoke_in);

  virtual void visit_SendsTo (SendsTo_in sends);

  virtual void visit_ReceptacleDelegate (ReceptacleDelegate_in);

  virtual void visit_RequiredRequestPortDelegate (RequiredRequestPortDelegate_in);

  virtual void visit_FacetDelegate (FacetDelegate_in);

  virtual void visit_ProvidedRequestPortDelegate (ProvidedRequestPortDelegate_in);

  virtual void visit_EventSourceDelegate (EventSourceDelegate_in);

  virtual void visit_OutEventPortDelegate (OutEventPortDelegate_in);

  virtual void visit_EventSinkDelegate (EventSinkDelegate_in);

  virtual void visit_InEventPortDelegate (InEventPortDelegate_in);

  const std::vector <GAME::Xml::Fragment> & connections (void) const;

private:
  /// Helper method for creating a connection.
  void create_connection (const std::string & name,
                          GAME::Xml::Fragment ep1,
                          GAME::Xml::Fragment ep2,
                          bool is_local);

  void make_local_connection (GAME::Xml::Fragment conn);

  /// The target document/parent for the connection.
  GAME::Xml::Document doc_;

  /// Set of connection gathered.
  std::vector <GAME::Xml::Fragment> conns_;

  /// Set of deployed instances.
  const instance_map_type & insts_;

  ComponentInstance inst_;

  std::string name_;

  GAME::Xml::Fragment endpoint_;
};

}
}

#endif  // !defined _PICML_DEPLOYMENT_CONNECTION_VISITOR_H_
