#include "NodeAssigner.h"

#include <ctime>
#include <cmath>
#include <cstdlib>

RandomNodeAssigner::
RandomNodeAssigner (std::vector <std::string> const & nodes,
                    std::set <std::string> const & components)
: nodes_ (nodes),
  components_ (components)
{
}

RandomNodeAssigner::~RandomNodeAssigner()
{
}

void RandomNodeAssigner::
compute_assignment (const CompToNodeMapping &)
{
      time_t t;
      t = time (0);
      srand (static_cast <unsigned int> (t));

      for (std::set <std::string>::const_iterator itr =
            components_.begin ();
           itr != components_.end();
           ++itr)
        {
          int r = rand () % nodes_.size ();
          this->comp2node_map_.insert (std::make_pair (*itr, nodes_[r]));
		  this->node2comp_map_[nodes_[r]].insert (*itr);
        }
}

NodeToCompMapping RandomNodeAssigner::
get_node2comp (void) const
{
	return this->node2comp_map_;
}

CompToNodeMapping RandomNodeAssigner::
get_comp2node (void) const
{
	return this->comp2node_map_;
}
