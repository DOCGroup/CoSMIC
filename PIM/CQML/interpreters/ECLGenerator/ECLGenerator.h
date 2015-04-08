#pragma once

#include "BON.h"
#include "MON.h"
#include "PlacementMaps.h"
#include "KindAggregator.h"

#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>

namespace { /// anonymous

struct Compound
{
	long obj_ref;
	std::string name;	

	bool operator < (Compound const & c) const;
};

typedef std::map <std::string, std::set <Compound> > ContainmentGraph;
}


class ECLGenerator : public CWnd
{
public:
	ECLGenerator(const BON::Project& project,
		         const CQML::KindAggregator<CQML::AbstractComponent>::KindMap &);
	~ECLGenerator(void);

	void generate (NodeToCompMapping const & node2comp,
				   CompToNodeMapping const & comp2node,
				   std::string const & plan_name);

	static void get_sample_mapping (NodeToCompMapping & node2comp,
		                            CompToNodeMapping & comp2node);

private:

    void push_folder_adj (MON::Folder folder, std::string const & name);
    void push_model_adj (MON::Model model, std::string const & name);
    template <class Comp>
    void push_adj (std::set <Comp> const & set,
	               std::string const & name);
	bool is_compound (MON::Object const &);
	void parse_containement ();
	void parse_compound (Compound const & comp);
	std::list <std::string> composition_sequence (std::string const & begin,
								                  std::string const & end);
	template <class Iter>
    void print_sequence (Iter begin, Iter end);
    std::string gen_ECL (NodeToCompMapping const & node2comp,
	    				 CompToNodeMapping const & comp2node,
						 std::string const & plan_name);
	std::string add_slash_r (std::string const & s);


	const BON::Project & bon_project_;
	const MON::Project & mon_project_;
	CQML::KindAggregator<CQML::AbstractComponent>::KindMap comp_kind_map_;
	ContainmentGraph con_graph_;
	std::queue <Compound> compound_queue_;
};
