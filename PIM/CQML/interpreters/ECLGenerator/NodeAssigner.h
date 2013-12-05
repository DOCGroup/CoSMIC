#ifndef __NODE_ASSIGNER_H
#define __NODE_ASSIGNER_H

#include "PlacementMaps.h"

#include <set>
#include <vector>
#include <map>
#include <string>

class NodeAssigner 
{
  public:
    virtual ~NodeAssigner () {};
    virtual void compute_assignment (const CompToNodeMapping &known_mapping) = 0;
	virtual NodeToCompMapping  get_node2comp (void) const = 0;
	virtual CompToNodeMapping get_comp2node (void) const = 0;
};

class RandomNodeAssigner : public NodeAssigner
{
  public:
	
	RandomNodeAssigner (std::vector <std::string> const & nodes, 
	                    std::set <std::string> const & components);
    ~RandomNodeAssigner();
    virtual void compute_assignment (const std::map <std::string, std::string> &known_mapping);
	virtual NodeToCompMapping get_node2comp (void) const;
	virtual CompToNodeMapping get_comp2node (void) const;

    private:
	  std::set <std::string> components_;
	  std::vector <std::string> nodes_;
	  CompToNodeMapping comp2node_map_;
	  NodeToCompMapping node2comp_map_;
};

#endif // __NODE_ASSIGNER_H
