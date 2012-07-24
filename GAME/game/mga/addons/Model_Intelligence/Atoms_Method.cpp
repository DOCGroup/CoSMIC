// $Id:  $

#include "StdAfx.h"

#include "Atoms_Method.h"
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
Atoms_Method::Atoms_Method (void)
{
  flag = 1;
}

//
// Constructor
//
Atoms_Method::Atoms_Method (std::string &kind)
: kind_ (kind)
{
  flag = 2;
}

//
// Destructor
//
Atoms_Method::~Atoms_Method (void)
{
}

//
// evaluate
//
Value * Atoms_Method::evaluate (Ocl_Context & res, 
                                GAME::Mga::Object caller)
{
  GAME::Mga::Folder fld = GAME::Mga::Folder::_narrow (caller);
	std::vector <GAME::Mga::Atom> atoms;

  // Collecting the Atoms contained in the Folder
  if (flag == 1)
    fld->children (atoms);
  else if (flag == 2)
    fld->children (this->kind_, atoms);

  // Collecting the Atoms contained by Subfolders
  std::vector <GAME::Mga::Folder> kids;
  fld->folders (kids);

  std::vector <GAME::Mga::Folder>::iterator
    it = kids.begin (), it_end = kids.end ();

  for (; it != it_end; ++it)
  {
    std::vector <GAME::Mga::Atom> temp;
    (*it)->children (this->kind_, temp);

    std::vector <GAME::Mga::Atom>::iterator
      mit = temp.begin (), mit_end = temp.end ();

    for (; mit != mit_end; ++mit)
      atoms.push_back ((*mit));
  }

  return new Collection_Value_T <GAME::Mga::Atom> (atoms);
}

//
// evaluate
//
Value * Atoms_Method::evaluate (Ocl_Context & res, 
                                Value * caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
  std::vector <GAME::Mga::Atom> atoms;

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();
    GAME::Mga::Folder fld = GAME::Mga::Folder::_narrow (obj);

    // Collecting the Atoms contained in the Folder
    if (flag == 1)
      fld->children (atoms);
    else if (flag == 2)
      fld->children (this->kind_, atoms);

    // Collecting the Atoms contained by Subfolders
    std::vector <GAME::Mga::Folder> kids;
    fld->folders (kids);

    std::vector <GAME::Mga::Folder>::iterator
      it = kids.begin (), it_end = kids.end ();

    for (; it != it_end; ++it)
    {
      std::vector <GAME::Mga::Atom> temp;
      if (flag == 1)
        (*it)->children (temp);
      else if (flag == 2)
        (*it)->children (this->kind_, temp);

      std::vector <GAME::Mga::Atom>::iterator
        mit = temp.begin (), mit_end = temp.end ();

      for (; mit != mit_end; ++mit)
        atoms.push_back ((*mit));
    }
  }

  return new Collection_Value_T <GAME::Mga::Atom> (atoms);
}

//
// is_filter
//
bool Atoms_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Atoms_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Atoms_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Atoms_Method::is_reference (void)
{
  return false;
}