#ifndef _PICML_DOMAIN_VISITOR_H_
#define _PICML_DOMAIN_VISITOR_H_

#include "PICML/Visitor.h"
#include "game/xml/Fragment.h"

class Domain_Visitor : public PICML::Visitor
{
public:
  Domain_Visitor (const std::string & output_path);

  virtual ~Domain_Visitor (void);

  virtual void visit_RootFolder (PICML::RootFolder_in folder);
  virtual void visit_Targets (PICML::Targets_in targets);
  virtual void visit_Domain (PICML::Domain_in domain);
  virtual void visit_Node (PICML::Node_in node);
  virtual void visit_Interconnect (PICML::Interconnect_in ic);
  virtual void visit_Bridge (PICML::Bridge_in br);
  virtual void visit_SharedResource (PICML::SharedResource_in sr);
  virtual void visit_InstanceMapping (PICML::InstanceMapping_in ins_map);
  virtual void visit_Resource (PICML::Resource_in res);
  virtual void visit_SatisfierProperty (PICML::SatisfierProperty_in prop);

private:
  std::string output_path_;

  GAME::Xml::Fragment fragment_;
};

#endif /* DOMAIN_VISITOR_H */
