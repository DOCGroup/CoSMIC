// $Id:  $

#include "StdAfx.h"

#include "Models_Method.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Collection_Value_T.h"
#include "Object_Value.h"
#include "game/mga/Folder.h"


//
// Default constructor
//
Models_Method::Models_Method (void)
{
  flag = 1;
}

//
// Constructor
//
Models_Method::Models_Method (std::string & kind)
: kind_ (kind)
{
  flag = 2;
}

//
// Destructor
//
Models_Method::~Models_Method (void)
{
}

//
// evaluate
//
Value * Models_Method::evaluate (Ocl_Context & res, 
                                 GAME::Mga::Object caller)
{
  GAME::Mga::Folder fld = GAME::Mga::Folder::_narrow (caller);
	std::vector <GAME::Mga::Model> models;

  // Collecting the Models contained in the Folder
  if (flag == 1)
    fld->children (models);
  else if (flag == 2)
    fld->children (this->kind_, models);

  // Collecting the Models contained by Subfolders
  std::vector <GAME::Mga::Folder> kids;
  fld->folders (kids);

  std::vector <GAME::Mga::Folder>::iterator
    it = kids.begin (), it_end = kids.end ();

  for (; it != it_end; ++it)
  {
    std::vector <GAME::Mga::Model> temp;
    (*it)->children (this->kind_, temp);

    std::vector <GAME::Mga::Model>::iterator
      mit = temp.begin (), mit_end = temp.end ();

    for (; mit != mit_end; ++mit)
      models.push_back ((*mit));
  }

  return new Collection_Value_T <GAME::Mga::Model> (models);
}

//
// evaluate
//
Value * Models_Method::evaluate (Ocl_Context & res, 
                                 Value * caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
  std::vector <GAME::Mga::Model> models;

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();
    GAME::Mga::Folder fld = GAME::Mga::Folder::_narrow (obj);

    // Collecting the Models contained in the Folder
    if (flag == 1)
      fld->children (models);
    else if (flag == 2)
      fld->children (this->kind_, models);

    // Collecting the Models contained by Subfolders
    std::vector <GAME::Mga::Folder> kids;
    fld->folders (kids);

    std::vector<GAME::Mga::Folder>::iterator
      it = kids.begin (), it_end = kids.end ();

    for (; it!=it_end; ++it)
    {
      std::vector <GAME::Mga::Model> temp;

      if (flag == 1)
        (*it)->children (temp);
      else if (flag == 2)
        (*it)->children (this->kind_, temp);

      std::vector <GAME::Mga::Model>::iterator
        mit = temp.begin (), mit_end = temp.end ();

      for (; mit != mit_end; ++mit)
        models.push_back ((*mit));
    }
  }

  return new Collection_Value_T <GAME::Mga::Model> (models);
}

//
// is_filter
//
bool Models_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Models_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Models_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Models_Method::is_reference (void)
{
  return false;
}