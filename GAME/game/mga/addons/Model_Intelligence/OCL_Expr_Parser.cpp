// $Id: OCL_Expr_Parser.cpp 2908 2012-06-10 18:21:53Z tpati $

#include "StdAfx.h"
#include "rules/grammar.hpp"
#include "OCL_Expr_Parser.h"
#include <fstream>

OCL_Expr_Parser::OCL_Expr_Parser(void)
{
}

OCL_Expr_Parser::~OCL_Expr_Parser(void)
{
}

bool OCL_Expr_Parser::
parse_string (std::string str, std::vector <Boolean_Expr*> &ocl)
{
  namespace spirit = boost::spirit;

  std::string::const_iterator begin_iter = str.begin();
  std::string::const_iterator end_iter = str.end();

	OCL_Expression_Parser_Grammar <std::string::const_iterator> g;

  bool retval = qi::phrase_parse (begin_iter,
                                  end_iter,
                                  g,
                                  ascii::space,
                                  ocl);
  return retval;
}

