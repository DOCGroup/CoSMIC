// $Id$

#include "StdAfx.h"
#include "IteratorCall_Expr.h"
#include "boost/bind.hpp"
#include "Object_Value.h"
#include "Boolean_Value.h"
#include "Collection_Value_T.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/FCO.h"


//
// Constructor
//
IteratorCall_Expr::IteratorCall_Expr (Value_Expr * obj,
                                      Iterator * name,
                                      Boolean_Expr * expr)
:obj_ (obj),
 name_ (name),
 expr_ (expr)
{
  flag = 1;
}

//
// Constructor
//
IteratorCall_Expr::IteratorCall_Expr (Value_Expr * obj,
                                      Iterator * name,
                                      Value_Expr * valexpr)
:obj_ (obj),
 name_ (name),
 valexpr_ (valexpr)
{
  flag = 2;
}

//
// Destructor
//
IteratorCall_Expr::~IteratorCall_Expr (void)
{
}

//
// evaluate
//
bool IteratorCall_Expr::evaluate (Ocl_Context & res)
{ 
  Value * result;

  // Collect the value for the invoking collection
  Collection_Value_T <GAME::Mga::FCO> * cv = 
    dynamic_cast <Collection_Value_T<GAME::Mga::FCO> *> (this->obj_->evaluate (res));

  if (cv != 0)
  {
    std::vector <GAME::Mga::FCO> collection = cv->value ();

    if (flag == 1)
      result = this->name_->evaluate (res, collection, this->next_, this->dec_type_, this->expr_);
    else if (flag == 2)
      result = this->name_->evaluate (res, collection, this->next_, this->dec_type_, this->valexpr_);
  }

  Boolean_Value * iv = dynamic_cast <Boolean_Value *> (result);

  return iv->value ();
}

//
// filter_evaluate
//
bool IteratorCall_Expr::filter_evaluate (Ocl_Context & res, 
                                         GAME::Mga::FCO &current)
{ 
  bool result = false;

  std::string name = current->name ();

  switch (this->next_.size ()) {
    case 0:
    {
      result = this->expr_->filter_evaluate (res, current);
      break;
    }
    case 1:
    {
      result = this->expr_->filter_evaluate (res, current);
      break;
    }
    default:
      result = false;
  }
          
  return result;
}

//
// set_declarators
//
void IteratorCall_Expr::set_declarators (std::vector <std::string> & next)
{
  this->next_ = next;
}

//
// set_dec_type
//
void IteratorCall_Expr::set_dec_type (std::string & type)
{
  this->dec_type_ = type;
}

//
// is_association
//
bool IteratorCall_Expr::is_association (void)
{
  if (this->expr_->is_association ())
    return true;

  return false;
}

//
// is_containment
//
bool IteratorCall_Expr::is_containment (void)
{
  if (this->expr_->is_containment ())
    return true;

  return false;
}

//
// is_reference
//
bool IteratorCall_Expr::is_reference (void)
{
  if (this->expr_->is_reference ())
    return true;

  return false;
}