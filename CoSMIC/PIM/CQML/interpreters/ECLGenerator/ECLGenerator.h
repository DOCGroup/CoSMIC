#pragma once

#include "MON.h"

#include <map>
#include <set>
#include <string>
#include <queue>

namespace { /// anonymous

struct Compound
{
	MON::Object obj;
	MON::ObjectType type;
	std::string name;	

	bool operator < (Compound const & c) const;
};

typedef std::map <std::string, std::set <Compound> > ContainmentGraph;

}

class ECLGenerator
{
public:
	ECLGenerator(const MON::Project& project);
	~ECLGenerator(void);

	void generate ();

private:

    void push_folder_adj (MON::Folder folder, std::string const & name);
    void push_model_adj (MON::Model model, std::string const & name);
    template <class Comp>
    void push_adj (std::set <Comp> const & set, 
	               std::string const & name);
	bool is_compound (MON::Object);
	void parse_containement ();
	void parse_compound (Compound const & comp);


	const MON::Project * mon_project_;
	ContainmentGraph con_graph_;
	std::queue <Compound> compound_queue_;
};
