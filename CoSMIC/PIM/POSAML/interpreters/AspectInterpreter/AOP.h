#ifndef AOP_H
#define AOP_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"
#include "File.h"

class CAOP{

public:
  CAOP();
  CAOP(BON::Project &project);
  ~CAOP();
  BOOL process_root_model();

private:
  
  void initialize(BON::Project &project);
  BOOL iterate_model(std::set<BON::Model> &model_set);
  BOOL process_aspect_feature(std::string aspect_name);
  BOOL process_advice(MON::Aspect &aspect, std::string pointcutName);
  void process_aspect(MON::Aspect & aspect );
  BOOL setup_aspect_file(std::string aspect_name);
  void add_pointcut(std::string pointcutName);
  void add_advice(std::string pointcutName, std::string adviceType, std::string definitionAdvice);

  std::set<std::string> getElements(BON::Set setObj);
  void process_individual_pointcut(std::string pointcutName, BON::Model &model);

  void getLinkedJointPointSet(BON::FCO &iterObj, BON::Model &model);
  BOOL getMembersOfSet(BON::FCO &dst, BON::Model &model);
  BOOL process_main_pointcut(BON::Model &model);
  BOOL getRelationBetweenSets(BON::FCO &dst, std::string connection);
  BOOL is_pointcut_connected_to_advice (BON::Atom &iterObj, 
                                           std::string pointcutName);

  void close_aspect_file();

  BON::Project m_project;
  std::string jointPoint_;
  BON::Model m_model_;
  CFILE::CFile *file_;
protected:

};

#endif // AOP_H
