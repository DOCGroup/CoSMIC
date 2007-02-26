#include "stdafx.h"
#include "AOP.h"

CAOP::CAOP()
{
}

CAOP::CAOP(BON::Project &project)
{
  this->initialize(project);
}

CAOP::~CAOP()
{
  if ( m_project ) 
  {
    m_project->finalizeObjects();
		m_project = NULL;
  }
}

void CAOP::initialize(BON::Project &project)
{
  this->m_project = project;
}

BOOL CAOP::iterate_model(std::set<BON::Model> &model_set)
{
  bool in_aspect = false;
  int len = model_set.size();
  if(len < 0)
  {
    m_project->consoleMsg("Could not get any Models",MSG_INFO);
    return false;
  }
  if( len == 0)
    return false;
        
  for (std::set<BON::Model>::iterator iter = model_set.begin();
		iter != model_set.end();
		++iter)
  {
    BON::Model model = (*iter);
                   
    std::string modelType = model->getObjectMeta().name();
    std::set<BON::Model> inner_model_set = model->getChildModels();
    this->m_model_ = model;
    if (modelType == "AspectFeature")
    {
      in_aspect = true;
      std::string modelName = (*iter)->getName();  
      m_project->consoleMsg(modelName,MSG_INFO);
      
      if(this->setup_aspect_file(modelName))
      {
        this->process_aspect_feature(modelName);
        this->close_aspect_file();      
      }
  
    }
    else 
        this->iterate_model(inner_model_set);
  }
  return true;
}

BOOL CAOP::setup_aspect_file(std::string aspect_name)
{
  std::string file_name = "c:\\" + aspect_name + ".ah";
  this->file_ = new CFILE::CFile(file_name);
  if(this->file_->open_file())
  {
    this->file_->add_include();
    this->file_->add_aspect_key_name(aspect_name);
    this->file_->add_left_brace();
    return true;
  }
  return false;
}

void CAOP::close_aspect_file()
{
  this->file_->add_right_brace();
  this->file_->close_file();
}


void CAOP::process_aspect(MON::Aspect &aspect)
{
  std::set<BON::Model> set_model = this->m_model_->getChildModels(aspect);
  int size = set_model.size();
  if(set_model.size() == 0)
  {
      AfxMessageBox("No Pointcuts defined");
      return;
  }

  for (std::set<BON::Model>::iterator iterFCO = set_model.begin();
    iterFCO != set_model.end();
     ++iterFCO)
  {
    BON::Model iterObj(*iterFCO);
    ASSERT(iterObj);
    std::string pointcutName = iterObj->getName ();
    this->process_individual_pointcut(pointcutName, iterObj);
    this->add_pointcut(pointcutName);
    this->process_advice (aspect, pointcutName);  
  }
  return;
}
void CAOP::process_individual_pointcut(std::string pointcutName, BON::Model &model)
{
  MON::Model sub_meta_model = model->getModelMeta();
  
  std::set<MON::Aspect> my_aspects = model->getModelMeta().aspects();

  for (std::set<MON::Aspect>::iterator iterAspect = my_aspects.begin();
	     iterAspect != my_aspects.end();
	     ++iterAspect)
  {
    MON::Aspect aspect = (*iterAspect);
    std::string aspect_name = aspect.name();
    if(aspect_name == "Pointcut_Aspect")
    {
      this->process_main_pointcut( model);
    }
  }
}

void CAOP::add_pointcut(std::string pointcutName)
{
  std::string pointcut = "\n     pointcut " + pointcutName + "() = ";
  pointcut.append(this->jointPoint_);
  this->file_->add_content(pointcut);
  this->jointPoint_.clear();
  this->file_->semi_colon_;
}

void CAOP::add_advice(std::string pointcutName, std::string adviceType, std::string definitionAdvice)
{
  std::string advice = "\n\n    advice ";
  advice.append(pointcutName);
  advice.append("() :");
  advice.append(adviceType);
  advice.append("{\n    ");
  advice.append(definitionAdvice);
  advice.append("\n    }");
  this->file_->add_content(advice);
}

void CAOP::getLinkedJointPointSet(BON::FCO &iterObj, BON::Model &model)
{
  std::string elementType = iterObj->getObjectMeta().name();
  std::string elementName = iterObj->getName();

  std::multiset<BON::ConnectionEnd> in_ends 
        = BON::ConnectionEnd(iterObj)->getConnEnds("AddJointPointsConnection");
  int len = in_ends.size();
  if(in_ends.size() < 1)
  {
    m_project->consoleMsg("Jointpoint set not connected",MSG_ERROR);
    return;
  } 
  
  bool relationset = false;
  for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; 
    cit != in_ends.end() ; 
      ++cit )
	{
		BON::FCO dst( *cit );
    ASSERT(dst);
    std::string elementType = dst->getObjectMeta().name();
    std::string elementName = dst->getName();
    
    getMembersOfSet(dst, model);
    if((len > 1)&& (!relationset))
    {
      relationset = getRelationBetweenSets(dst, "JPAndOr_Connection1");
    }
  }
}

BOOL CAOP::getRelationBetweenSets(BON::FCO &iterObj, std::string connection)
{
  std::multiset<BON::ConnectionEnd> in_ends 
        = BON::ConnectionEnd(iterObj)->getConnEnds(connection);
  int len = in_ends.size();
  if(len < 1)
  {
    m_project->consoleMsg("Jointpoint set not connected",MSG_ERROR);
    return false;
  } 
  std::string relation;
  for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; 
    cit != in_ends.end() ; 
      ++cit )
	{
		BON::FCO dst( *cit );
    ASSERT(dst);
    relation = dst->getName();
    if(dst->getName() == "or")
      relation = " || ";
    else if (dst->getName() == "and")
      relation = " && ";
    this->jointPoint_.append(relation);
  }
  if(!relation.empty())
    return true;
  return false;
}


BOOL CAOP::getMembersOfSet(BON::FCO &dst, BON::Model &model)
{
  std::string set_name = dst->getName();
  std::string set_type = dst->getObjectMeta().name();

  std::set<BON::Set> handle_set = model->getChildSets();
  
  for (std::set<BON::Set>::iterator iterSet = handle_set.begin();
    iterSet != handle_set.end();
     ++iterSet)
  {
    BON::Set setObj(*iterSet);
    ASSERT(setObj);
    std::string elementType = setObj->getObjectMeta().name();
    std::string elementName = setObj->getName();
    if(elementName == set_name)
    {
      std::set<BON::FCO> fcoset_atom = setObj->getMembers();
      int count = 0;
      int len = fcoset_atom.size();
      if(len < 1)
        return false;
      
      for (std::set<BON::FCO>::iterator iterFCO = fcoset_atom.begin();
        iterFCO != fcoset_atom.end();
        ++iterFCO)
      {
        
        BON::FCO iterObj(*iterFCO);
        ASSERT(iterObj);
        std::string elementType = iterObj->getObjectMeta().name();
        std::string elementName = iterObj->getName();
        if(elementType == "Jointpoint")
        {
          if(count == 0)
            this->jointPoint_.append("(");
          count++;
          std::string pointcutType= iterObj->getAttribute("TypeOfJointPoint")->getStringValue();
          std::string setOfJointPoint = iterObj->getAttribute("SetOfJointPoint")->getStringValue();
          this->jointPoint_.append(pointcutType);
          this->jointPoint_.append("(");
          this->jointPoint_.append(setOfJointPoint);
          this->jointPoint_.append(")");
          std::string relation;
          if((set_type == "JointPointOrSet")||(set_type == "PointcutOrSet"))
            relation = " || ";
          else if ((set_type == "JointPointAndSet")||(set_type == "PointcutAndSet"))
            relation = " && ";
          if(count != len) 
            this->jointPoint_.append(relation);
          else
            this->jointPoint_.append(")");
        }
        if(elementType == "FinalJointPoint")
        {
          getLinkedJointPointSet(iterObj, model);
        }
      }
    }
  }
  return true;
}

BOOL CAOP::process_main_pointcut(BON::Model &model)
{
  std::set<BON::FCO> fco_elements = model->getChildFCOs();
  
  for (std::set<BON::FCO>::iterator iterFCO = fco_elements.begin();
    iterFCO != fco_elements.end();
     ++iterFCO)
  {
    BON::FCO iterObj(*iterFCO);
    ASSERT(iterObj);
    std::string elementType1 = iterObj->getObjectMeta().name();
    std::string elementName1 = iterObj->getName();
       
    if(elementType1 == "MainPointcut")
    {
      std::multiset<BON::ConnectionEnd> in_ends 
        = BON::ConnectionEnd(iterObj)->getConnEnds("AddPointCutConnection");
      if(in_ends.size() < 1)
      {
        m_project->consoleMsg("Jointpoint set not connected",MSG_ERROR);
        return false;
      }
      int len = in_ends.size();
      int count = 0;
      bool pointcutrelation = false;
      for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; 
        cit != in_ends.end() ; 
          ++cit )
		  {
        count++;
        this->jointPoint_.append("(");
			  BON::FCO dst( *cit );
        ASSERT(dst);
        std::string pointcut_set_name = dst->getName();
        getMembersOfSet(dst, model);
        this->jointPoint_.append(")");
        if((len > 1 ) && !pointcutrelation)
        {
          pointcutrelation = this->getRelationBetweenSets(dst,"PointCutAndOrConnection1" );
        }
      }
    }
  }
  return true;
}



BOOL CAOP::is_pointcut_connected_to_advice (BON::Atom &iterObj, 
                                           std::string pointcutName)
{
  std::string adviceName = iterObj->getName ();

  std::multiset<BON::ConnectionEnd> in_ends 
        = BON::ConnectionEnd(iterObj)->getConnEnds("Advice_Pointcut_Connection");
  int len = in_ends.size();
  if(in_ends.size() < 1)
  {
    std::string temp = "Poincut "+pointcutName+" is not connected to advice";
    m_project->consoleMsg(temp.c_str(),MSG_WARNING);
    return false;
  } 
  
  for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; 
    cit != in_ends.end() ; 
      ++cit )
	{
		BON::FCO dst( *cit );
    ASSERT(dst);
    std::string elementName = dst->getName();
    std::string elementType = dst->getObjectMeta().name();
    if(elementName == pointcutName)
      return true;
  }
  return false;
}


BOOL CAOP::process_advice(MON::Aspect &aspect, std::string pointcutName)
{
  std::set<BON::Atom> set_atom = this->m_model_->getChildAtoms(aspect);
  for (std::set<BON::Atom>::iterator iterFCO = set_atom.begin();
    iterFCO != set_atom.end();
     ++iterFCO)
  {
    BON::Atom iterObj(*iterFCO);
    ASSERT(iterObj);
    std::string elementType = iterObj->getObjectMeta().name();
    if(elementType == "Advice")
    {
      std::string adviceName = iterObj->getName();
      if(this->is_pointcut_connected_to_advice(iterObj, pointcutName))
      {
        m_project->consoleMsg(adviceName,MSG_WARNING);
        std::string adviceType= iterObj->getAttribute("TypeOfAdvice")->getStringValue();
        std::string definitionAdvice= iterObj->getAttribute("AdviceDefinition")->getStringValue();
        this->add_advice(pointcutName, adviceType, definitionAdvice);
      }
    }
  }
  return true;
}

BOOL CAOP::process_aspect_feature(std::string aspect_name)
{
  MON::Model sub_meta_model = this->m_model_->getModelMeta();
  
  std::set<MON::Aspect> my_aspects = this->m_model_->getModelMeta().aspects();

  for (std::set<MON::Aspect>::iterator iterAspect = my_aspects.begin();
	     iterAspect != my_aspects.end();
	     ++iterAspect)
  {
    MON::Aspect aspect = (*iterAspect);
    std::string aspect_name = aspect.name();
    if(aspect_name == "AOP")
    {
      this->process_aspect(aspect);
      break;
    }
  }
  return true;
}

BOOL CAOP::process_root_model()
{
  BON::Folder root = m_project->getRootFolder( ); // Get the root folder
  if (!root ) 
  {
    AfxMessageBox("Could not find RootFolder" );
    return false;
  }
  if(this->iterate_model(root->getChildModels()))
    return true;
  return false;
}
