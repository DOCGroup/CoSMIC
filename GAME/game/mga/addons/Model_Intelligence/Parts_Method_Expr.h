// -*- C++ -*-

//=============================================================================
/**
 * @file          Parts_Method_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_PARTS_METHOD_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_PARTS_METHOD_EXPR_H_

#include "Collection_Expr.h"

/**
 * @class Parts_Method_Expr
 *
 * Class derived from Collection_Expr. This class deals
 * with all the parts that a particular metarole/metatype
 * has i.e. with the childrens present in the model
 */
class Parts_Method_Expr : public Collection_Expr
{
public:
  ///Constructor
  Parts_Method_Expr (std::string role);

  ///Destructor
  ~Parts_Method_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[out]    parts     Vector containing the children of a MetaFCO
   * @param[in]     res       Object of model intelligence context
   */
  void evaluate (std::vector <GAME::Mga::FCO> &parts, 
                 Ocl_Context &res);

private:
  std::string role_;
};

#endif