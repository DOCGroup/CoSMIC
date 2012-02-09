// $Id$

#include "StdAfx.h"

#include "Parts_Method_Expr.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFCO.h"
#include "FCO.h"

//
// Default Constructor
//
Parts_Method_Expr::Parts_Method_Expr (std::string role)
: role_ (role)
{
}

//
// Destructor
//
Parts_Method_Expr::~Parts_Method_Expr ()
{
}

//
// evaluate
//
void Parts_Method_Expr::evaluate (std::vector<GAME::Mga::FCO> &parts, 
                                  Ocl_Context &res)
{
  // Setting the target metarole in the model intelligence context
  res.target_metarole = res.model_object->meta ()->role (this->role_);
  
  GAME::Mga::Meta::FCO temp = res.target_metarole->kind ();

  res.model_object->children (temp->name(), parts);
}