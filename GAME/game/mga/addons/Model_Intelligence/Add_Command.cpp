// $Id$

#include "StdAfx.h"
#include "Add_Command.h"

//
// Constructor
//
Add_Command::Add_Command (GAME::Mga::Model parent_model,
                          GAME::Mga::Meta::Role target_metarole,
                          GAME::Mga::Meta::FCO target_metatype,
                          size_t count)
: parent_model_ (parent_model),
  target_metarole_ (target_metarole),
  target_metatype_ (target_metatype),
  count_ (count)
{
}

//
// Destructor
//
Add_Command::~Add_Command (void)
{
}

//
// execute
//
bool Add_Command::execute (void)
{
  try
  {
    if (this->target_metatype_->type () == OBJTYPE_MODEL)
    {
      for (; this->count_ != 0; -- this->count_)
        {
          GAME::Mga::Model new_model = GAME::Mga::Model_Impl::_create (this->parent_model_, 
                                                                       this->target_metarole_);
          char c = '0' + this->count_;
          new_model->name (this->target_metarole_->name () + c);
        }
    }
    else if (this->target_metatype_->type () == OBJTYPE_ATOM)
    {
      for (; this->count_ != 0; -- this->count_)
        {
          GAME::Mga::Atom new_atom = GAME::Mga::Atom_Impl::_create (this->parent_model_, 
                                                                    this->target_metarole_);
          char c = '0' + this->count_;
          new_atom->name (this->target_metarole_->name () + c);
        }
    }
  return true;
  }
  catch (std::exception)
	{
		return false;
	}
}