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
  this->project_->consoleMsg ("In Reactor create_init_file",msgtype_enum (1));
  std::ofstream ini_file;
  std::string file_name = this->model_->getName ();
  file_name = file_name + ".ini";
  ini_file.open (file_name.c_str ());
  ini_file<<"[General]"<<std::endl
	<<"preload-ned-files=*.ned"<<std::endl
	<<"network=reactor_block"<<std::endl
	<<"sim-time-limit=10000s"<<std::endl
	<<"output-scalar-file=mu1_sensitivity.sca"<<std::endl;
  ini_file<<"[Parameters]"<<std::endl;
  std::set<BON::FCO> handlers = this->model_->findByKind ("EventHandler");
  ini_file<<"reactor_block.num_handlers = "<<handlers.size ()<<std::endl;

  std::set<BON::Set> handle_set = this->model_->getChildSets();
  std::set<BON::FCO> handles = (*handle_set.begin ())->getMembers ();
  //this->project_->consoleMsg ((*handles.begin ())->getName (), msgtype_enum(1));
  std::set<BON::FCO>::iterator handle_it;
  int i;
  for (i = 0, handle_it = handles.begin (); handle_it != handles.end (); handle_it++, i++)
	ini_file<<"reactor_block.generator["<<i<<"].lambda = "<<(*handle_it)->getAttribute ("ActiveRate")->getRealValue()<<std::endl;
  ini_file.close ();
  return 0;
}
