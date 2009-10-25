#include <stdafx.h>
#include "Patterns.h"
#include "BON2Component.h"


Reactor::Reactor (const BON::Project &project, const BON::Model &model)
: project_(project),
  model_(model)
{
}

int
Reactor::create_init_file ()
{
  std::ofstream ini_file;
  std::string file_name = this->model_->getName ();
  file_name = file_name + ".ini";
  ini_file.open (file_name.c_str ());
 
  ini_file<<"[General]"<<std::endl
	<<"preload-ned-files=*.ned"<<std::endl
	<<"network=reactor_block"<<std::endl;

  MON::MetaObject sim_aspect = this->project_->getProjectMeta ().findByName ("Simulation_Aspect");
  std::set<BON::Atom> sim_atoms = this->model_->getChildAtoms (sim_aspect);
  std::set<BON::Atom>::iterator sim_iter;
  int no_runs;
  for (sim_iter = sim_atoms.begin (); sim_iter != sim_atoms.end (); sim_iter++)
  {
	if ((*sim_iter)->getObjectMeta ().name () == "Simulation")
	{
	  ini_file<<"sim-time-limit="<<
		(*sim_iter)->getAttribute ("Sim_Time_Limit")->
		  getIntegerValue ()<<"s"<<std::endl;
	  ini_file<<"output-scalar-file="<<
		(*sim_iter)->getAttribute ("Output_Scalar_File")->getStringValue ()<<std::endl;
	  no_runs = (*sim_iter)->getAttribute ("No_Of_Runs")->getIntegerValue ();
	  break;
	}
  }
  
  ini_file<<"[Parameters]"<<std::endl;
 
  std::multimap <int, BON::Atom> const_params, var_params;
  std::set<BON::Set> handle_set = this->model_->getChildSets();
  std::set<BON::FCO> handles = (*handle_set.begin ())->getMembers ();
  ini_file<<"reactor_block.num_handlers = "<<handles.size ()<<std::endl;
  
  std::set<BON::FCO>::iterator handle_it;
  int i;
  for (i = 0, handle_it = handles.begin (); handle_it != handles.end (); handle_it++, i++)
  {

	std::multiset <BON::ConnectionEnd> active_rate_conn = (*handle_it)->getInConnEnds ("Active_Rate_Handle_Connection");
	BON::Atom active_rate = (BON::Atom)(*active_rate_conn.begin ());
	if (active_rate->getAttribute ("param_type")->getStringValue () == "Constant")
	  const_params.insert (std::pair<int, BON::Atom>(i, active_rate));
	else
	  var_params.insert (std::pair<int, BON::Atom>(i, active_rate));

	std::multiset <BON::ConnectionEnd> event_handler_conn = (*handle_it)->getInConnEnds ("owns");
	BON::Atom event_handler = (BON::Atom)(*event_handler_conn.begin ());

	std::multiset <BON::ConnectionEnd> service_rate_conn = event_handler->getInConnEnds ("Service_Rate_EventHandler_Connection");
	BON::Atom service_rate = (BON::Atom)(*service_rate_conn.begin ());
	if (service_rate->getAttribute ("param_type")->getStringValue () == "Constant")
	  const_params.insert (std::pair<int, BON::Atom>(i, service_rate));
	else
	  var_params.insert (std::pair<int, BON::Atom>(i, service_rate));

	std::multiset <BON::ConnectionEnd> q_size_conn = event_handler->getInConnEnds ("Queue_EventHandler_Connection");
	BON::Atom q_size = (BON::Atom)(*q_size_conn.begin ());
	if (q_size->getAttribute ("param_type")->getStringValue () == "Constant")
	  const_params.insert (std::pair<int, BON::Atom>(i, q_size));
	else
	  var_params.insert (std::pair<int, BON::Atom>(i, q_size));
  }

  std::multimap <int,BON::Atom>::iterator map_it;
  for (map_it = const_params.begin (); map_it!=const_params.end ();map_it++)
  {
	if ((map_it->second)->getObjectMeta ().name () == "Active_Rate")
	  ini_file<<"reactor_block.generator["<<
		(map_it->first)<<"].lambda=";
	else if ((map_it->second)->getObjectMeta ().name () == "Service_Rate")
	  ini_file<<"reactor_block.handler["<<
		(map_it->first)<<"].mu=";
	else if ((map_it->second)->getObjectMeta ().name () == "Queue")
	  ini_file<<"reactor_block.handler["<<
		(map_it->first)<<"].queue_size=";
	
	ini_file<<(map_it->second)->getAttribute("param_value")->getRealValue ()<<std::endl;
  }

  for (i = 0; i < no_runs; i++)
  {
	ini_file<<"[Run "<<i<<"]"<<std::endl;
	for (map_it = var_params.begin (); map_it!=var_params.end (); map_it++)
	{
	  double base = (map_it->second)->getAttribute("min_param_value")->getRealValue ();
	  double diff = ((map_it->second)->getAttribute("max_param_value")->getRealValue () 
	  				- (map_it->second)->getAttribute("min_param_value")->getRealValue ())
					/ no_runs;
	  
	  if ((map_it->second)->getObjectMeta ().name () == "Active_Rate")
		ini_file<<"reactor_block.generator["<<
		  (map_it->first)<<"].lambda=";
	  else if ((map_it->second)->getObjectMeta ().name () == "Service_Rate")
		ini_file<<"reactor_block.handler["<<
		  (map_it->first)<<"].mu=";
	  else if ((map_it->second)->getObjectMeta ().name () == "Queue")
		ini_file<<"reactor_block.handler["<<
		  (map_it->first)<<"].queue_size=";

	  ini_file<<base + i * diff<<std::endl;
	}
  }
  ini_file.close ();
  return 0;
}
