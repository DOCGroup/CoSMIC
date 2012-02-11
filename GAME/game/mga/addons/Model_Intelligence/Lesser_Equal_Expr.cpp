// $Id$

#include "StdAfx.h"
#include "Lesser_Equal_Expr.h"
#include "game/mga/Atom.h"
#include "MetaAtom.h"
#include "game/mga/Model.h"
#include "MetaModel.h"
#include "MetaFCO.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include <string>

//
// Constructor
//
Lesser_Equal_Expr::Lesser_Equal_Expr (Value_Expr *left, Value_Expr *right)
: lhs_ (left),
  rhs_ (right)
{
}

//
// Destructor
//
Lesser_Equal_Expr::~Lesser_Equal_Expr ()
{
}

//
// evaluate
//
bool Lesser_Equal_Expr::evaluate (Ocl_Context & res)
{
  // flag to decide the case
  size_t flag = 0;
  bool ret_ = false;

  // Checking if the local variables are mutable/non-mutable
  if ((this->lhs_->ismutable () == true) && (this->rhs_->ismutable () == false))
    flag = 1;
  else if ((this->lhs_->ismutable () == false) && (this->rhs_->ismutable () == true))
    flag = 2;
  else if ((this->lhs_->ismutable () == true) && (this->rhs_->ismutable () == true))
    flag = 3;

  switch (flag) {

    case 1:
      {
        if (this->lhs_->evaluate (res) > this->rhs_->evaluate (res))
         {
           // Counting the number of objects to be deleted
           size_t count = this->rhs_->evaluate (res) - this->lhs_->evaluate (res);
           // Calling the delete command
         }
        break;
      }
    case 2:
      {
        if (this->lhs_->evaluate (res) < this->rhs_->evaluate (res))
        {
          // Counting the number of objects to be deleted
          size_t count = this->lhs_->evaluate (res) - this->rhs_->evaluate (res);
          // Calling the delete command
        }
        break;
      }
    case 3:
      {
        // user is given a choice in dialog 
      }
    default:
      {
        //throw an exception
      }
  }

  return ret_;
}

//
// list_add
//
bool Lesser_Equal_Expr::list_add (GAME::Mga::Model &obj, 
                                  size_t count, 
                                  GAME::Mga::Meta::FCO &metatype, 
                                  GAME::Mga::Meta::Role &metarole)
{
  if (metatype->type () == OBJTYPE_MODEL)
    {
      for (; count != 0; -- count)
        {
          GAME::Mga::Model new_model = GAME::Mga::Model_Impl::_create (obj, metarole);
          char c = '0' + count;
          new_model->name (metarole->name() + c);
        }
    }
  else if (metatype->type () == OBJTYPE_ATOM)
    {
      for (; count != 0; -- count)
        {
          GAME::Mga::Atom new_atom = GAME::Mga::Atom_Impl::_create (obj, metarole);
          char c = '0' + count;
          new_atom->name (metarole->name() + c);
        }
    }

  return true;
}

//
// list delete
//
bool Lesser_Equal_Expr::list_delete (GAME::Mga::Model &obj, 
                                     size_t count, 
                                     GAME::Mga::Meta::FCO &metatype, 
                                     GAME::Mga::Meta::Role &metarole)
{
  return true;
}
