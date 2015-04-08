#include "stdafx.h"
#include "ECLGenerator.h"
#include "ECLDialog.h"

#include "MON.h"
#include <BONImpl.h>

#include <queue>
#include <sstream>
#include <iostream>

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



std::string make_string (int number)
{
	std::ostringstream ostream;
	ostream << number;
	return ostream.str();
}

struct MGAInstance
{
	MON::ObjectType type;
	std::string kind;
	std::string name;
	std::set <MGAInstance> children;

	MGAInstance ();
	MGAInstance (MON::ObjectType type,
		         std::string const & kind,
		         std::string const & name);
	void add_child (MGAInstance const & child);
	bool operator < (MGAInstance const & m) const;
		
};

MGAInstance::
MGAInstance ()
: type (MON::OT_Null)
{}

MGAInstance::
MGAInstance (MON::ObjectType t,
	         std::string const & k,
	         std::string const & n)
			 : type (t),
			   kind (k),
			   name (n)
{
}

void MGAInstance::
add_child (MGAInstance const & child)
{
	this->children.insert (child);
}

bool MGAInstance::operator < (MGAInstance const & m) const
{
	return this->kind < m.kind;
}

struct MGAInstanceTree
{
	MGAInstance root;
};

} /// namespace anonymous

ECLGenerator::ECLGenerator(
	const BON::Project& project,
	const CQML::KindAggregator<CQML::AbstractComponent>::KindMap & comp_kind_map)
:  bon_project_ (project),
   mon_project_ (project->getProjectMeta()),
   comp_kind_map_ (comp_kind_map)
{
}

ECLGenerator::~ECLGenerator(void)
{
}

void ECLGenerator::
get_sample_mapping (NodeToCompMapping & node2comp, CompToNodeMapping & comp2node)
{
	char * n1[] = { "C1" , "C2", "C3" };
	char * n2[] = { "C4" , "C5" };
	char * n3[] = { "C6" };
	char * n4[] = { "C7" , "C8", "C9" };

	node2comp["n1"].insert (n1, n1 + 3);
	node2comp["n2"].insert (n2, n2 + 2);
	node2comp["n3"].insert (n3, n3 + 1);
	node2comp["n4"].insert (n4, n4 + 3);

	for(NodeToCompMapping::const_iterator i = node2comp.begin ();
		i != node2comp.end();
		++i)
	{
		for(std::set <std::string>::const_iterator j = i->second.begin ();
			j != i->second.end();
			++j)
		{
			comp2node [*j] = i->first;
		}
	}
}

void ECLGenerator::generate (NodeToCompMapping const & node2comp,
					         CompToNodeMapping const & comp2node,
							 std::string const & plan_name)
{
	std::string ecl = gen_ECL (node2comp, comp2node, plan_name);
	std::string ecl_for_dialog = add_slash_r(ecl);
    ECLDialog dialog (ecl_for_dialog, ::AfxGetMainWnd ());
	dialog.DoModal();
}

std::string ECLGenerator::add_slash_r (std::string const & s)
{
	std::string retval;
	for (std::string::const_iterator i (s.begin());
		 i != s.end();
		 ++i)
	{
		if (*i == '\n')
			retval += '\r';
		retval += *i;
	}
	return retval;
}

std::string ECLGenerator::gen_ECL (NodeToCompMapping const & node2comp,
					               CompToNodeMapping const & comp2node,
								   std::string const & plan_name)
{
	std::string SPACE3 = "   ";
	std::ostringstream 	outputECL;
    outputECL << "defines Deploy, Placement, Association;"
		      << std::endl;
	outputECL << "strategy Association "
	          << "(dp, host, comp : model) {"
			  << std::endl;
    outputECL << SPACE3
		      << "dp.addConnection (\"PlacementConn\", comp, host);"
		      << std::endl << "}" << std::endl;
	outputECL << "strategy Placement () {" << std::endl;
	outputECL << SPACE3
		      << "declare dp : model;" << std::endl;
	outputECL << SPACE3
		      << "dp := rootFolder().findModel (\""
			  << plan_name
			  << "\");"
			  << std::endl;

	for (NodeToCompMapping::const_iterator i (node2comp.begin());
		 i != node2comp.end();
		 ++i)
	{
		bool node_created = true;
		for (std::set <std::string>::const_iterator j (i->second.begin());
			 j != i->second.end();
			 ++j)
		{
			std::string kind_name = "NOT_FOUND";
			CQML::KindAggregator<CQML::AbstractComponent>::KindMap::const_iterator
				kind_iter = comp_kind_map_.find (*j);
			if (kind_iter != comp_kind_map_.end())
				kind_name = kind_iter->second.kind();

			if (node_created == false)
			{
				outputECL << SPACE3
					      << "Association (dp, dp.addModel (\"Host\",\""
						  << i->first
						  << "\"), dp.addModel (\""
						  << kind_name
						  << "\",\""
						  << *j
						  << "\"));" << std::endl;
				node_created = true;
			}
			else
			{
				outputECL << SPACE3
					      << "Association (dp, dp.findModel (\""
						  << i->first
					   	  << "\"), dp.addModel (\""
						  << kind_name
						  << "\",\""
						  << *j
						  << "\"));" << std::endl;
			}
		}
	}

	outputECL << "}" << std::endl << std::endl;
	outputECL << "aspect Deploy () {" << std::endl;
	outputECL << SPACE3 << "Placement();" << std::endl;
	outputECL << "}" << std::endl;

	return outputECL.str();
}

template <class Iter>
void ECLGenerator::print_sequence (Iter begin, Iter end)
{
	for (Iter itr = begin;
		 itr != end;
		 ++itr)
	{
		bon_project_->consoleMsg (itr->c_str(), MSG_ERROR);		
	}
	bon_project_->consoleMsg ("\n", MSG_ERROR);		
}

std::list <std::string> ECLGenerator::
composition_sequence (std::string const & begin,
                      std::string const & end)
{
	std::map <std::string, std::string> parent;
	std::list <std::string> ret_sequence;

	BFS (con_graph_, begin, end, parent);
	//AfxMessageBox("done BFS!");
	std::string str = end;
    while (str != begin)
    {
	  ret_sequence.push_front (str);
	  if (parent.find (str) != parent.end())
	  {
		  str = parent[str];
	  }
	  else
	  {
		  str = "NOTFOUND";
		  break;
	  }
    }
    ret_sequence.push_front (str);
	return ret_sequence;
}

void ECLGenerator::parse_containement ()
{
	MON::Folder rootFolder = mon_project_.rootFolder ();
	Compound rf_compound = { rootFolder.ref(), rootFolder.name() };
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
	MON::MetaObject object = mon_project_.findByRef (comp.obj_ref);
	switch (object.type())
	{
		case MON::OT_Folder:
		{
			push_folder_adj (MON::Folder (object), comp.name);
			break;
		}
		case MON::OT_Model:
		{
			push_model_adj (MON::Model (object), comp.name);
			break;
		}
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
		Compound c = { it->ref(), it->name() };
		con_graph_[name].insert (c);
		if (is_compound (*it) &&
			(con_graph_.find (it->name()) == con_graph_.end()))
		{
			compound_queue_.push (c);
		}
	}
}

bool ECLGenerator::is_compound (MON::Object const & obj)
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

	std::set<MON::Atom> aset = folder.childAtoms();
    push_adj (aset, name);
}

void ECLGenerator::push_model_adj (MON::Model model, std::string const & name)
{
	std::set<MON::Model> mset = model.childModels();
    push_adj (mset, name);

	std::set<MON::Atom> aset = model.childAtoms();
    push_adj (aset, name);

	std::set<MON::Set> sset = model.childSets();
    push_adj (sset, name);

	std::set<MON::Reference> rset = model.childReferences();
    push_adj (rset, name);
}

	/*
	bon_project_->consoleMsg ("************************************", MSG_ERROR);
	for (ContainmentGraph::iterator i = con_graph_.begin();
		 i != con_graph_.end ();
		 ++i)
	{
		std::string vertex = "vertex = " + i->first + ":";
		bon_project_->consoleMsg (vertex, MSG_ERROR);
		for (std::set <Compound>::const_iterator iter
			  = con_graph_[i->first].begin ();
			 iter != con_graph_[i->first].end ();
			++iter)
		{
			bon_project_->consoleMsg (iter->name.c_str(), MSG_ERROR);
		}
		bon_project_->consoleMsg ("\n", MSG_ERROR);
	}
	*/
