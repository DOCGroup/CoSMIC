#include "stdafx.h"
#include "ECLGenerator.h"

#include "MON.h"

#include <queue>

namespace /// anonymous
{ 

bool Compound::operator < (Compound const & c) const
{
	return this->name < c.name;
}

bool BFS (ContainmentGraph & graph,
          std::string const & start,
          std::string const & end,
          std::map<std::string, std::string> & parent)
{
  std::queue <std::string> next;
  parent.clear ();
  parent[start] = "";
  next.push(start);
  while (!next.empty())
  {
    std::string u = next.front();
    next.pop();
    // Here is the point where you can examine the u th vertex of graph
    // For example:
    if (u == end)
    {
        return true;
    }

    for (std::set <Compound>::const_iterator iter = graph[u].begin();
         iter != graph[u].end();
         ++iter)
    {
      // Look through neighbors.
	  std::string v = iter->name;
      if (parent.count(v) == 0)
      {
        // If v is unvisited.
        parent[v] = u;
        next.push(v);
      }
    }
  }
  return false;
}



} /// namespace anonymous 

ECLGenerator::ECLGenerator(const MON::Project& project)
: mon_project_ (& project)
{
}

ECLGenerator::~ECLGenerator(void)
{
}

void ECLGenerator::generate ()
{
	parse_containement ();
	std::map <std::string, std::string> parent;
	BFS (con_graph_, "rootFolder", "DeploymentPlan", parent);
    
	std::string str_sequence;
	std::string str = "DeploymentPlan";
    while (str != "RootFolder")
    {
	  str_sequence += (str + " ");
	  str  = parent[str];
    }
    str_sequence += (str + " ");
	AfxMessageBox(str_sequence.c_str());
}

void ECLGenerator::parse_containement ()
{
	MON::Folder rootFolder = mon_project_->rootFolder ();
	Compound rf_compound = { rootFolder, rootFolder.type(), "rootFolder" };
	compound_queue_.push (rf_compound);
	while (! compound_queue_.empty ())
	{
		Compound c = compound_queue_.front ();
		compound_queue_.pop();
		if (con_graph_.find (c.name) == con_graph_.end())
		{
			/// Compound c not yet visited. So visit it.
			parse_compound (c);
		}
	}
}

void ECLGenerator::parse_compound (Compound const & comp)
{
	switch (comp.type)
	{
		case MON::OT_Folder:
			push_folder_adj (dynamic_cast <MON::Folder const &> 
							(comp.obj), comp.name);
			break;
		case MON::OT_Model:
			push_model_adj (dynamic_cast <MON::Model const &> 
							(comp.obj), comp.name);
			break;
	}
}

template <class Comp>
void ECLGenerator::push_adj (std::set <Comp> const & set, 
							 std::string const & name)
{
	for (std::set<Comp>::const_iterator it = set.begin(); 
		 it != set.end(); 
		 ++it ) 
	{
		if (is_compound (*it))
		{
			Compound c = { *it, it->type(), it->name() };
			con_graph_[name].insert (c); 
			compound_queue_.push (c);
		}
	}
}

bool ECLGenerator::is_compound (MON::Object obj)
{
	switch (obj.type())
	{
	    case MON::OT_Folder:	
		case MON::OT_Model:
			return true;
		default:
			return false;
	}
}

void ECLGenerator::push_folder_adj (MON::Folder folder, std::string const & name)
{
	std::set<MON::Folder> fset = folder.childFolders();
	push_adj (fset, name);
	
	std::set<MON::Model> mset = folder.childModels();
    push_adj (mset, name);
}

void ECLGenerator::push_model_adj (MON::Model model, std::string const & name)
{
	std::set<MON::Model> mset = model.childModels();
    push_adj (mset, name);
}
