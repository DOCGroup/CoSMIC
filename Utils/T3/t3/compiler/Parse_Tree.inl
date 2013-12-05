// -*- C++ -*-
// $Id$

//
// T3_Parse_Tree
//
inline
T3_Parse_Tree::T3_Parse_Tree (void)
{

}

//
// ~T3_Parse_Tree
//
inline
T3_Parse_Tree::~T3_Parse_Tree (void)
{

}

//
// start_rule
//
inline
const T3_Rule_Node * T3_Parse_Tree::start_rule (void) const
{
  return this->root_;
}

//
// start_rule
//
inline
void T3_Parse_Tree::start_rule (const char * rule_name)
{
  this->node_mgr_.lookup_rule (rule_name, this->root_);
}

//
// node_manager
//
inline
T3_Node_Manager & T3_Parse_Tree::node_manager (void)
{
  return this->node_mgr_;
}

//
// node_manager
//
inline
const T3_Node_Manager & T3_Parse_Tree::node_manager (void) const
{
  return this->node_mgr_;
}

//
// operator->
//
inline
T3_Node_Manager * T3_Parse_Tree::operator -> (void)
{
  return &this->node_mgr_;
}

//
// operator ->
//
inline
const T3_Node_Manager * T3_Parse_Tree::operator -> (void) const
{
  return &this->node_mgr_;
}

//
// name
//
inline
void T3_Parse_Tree::name (const ACE_CString & name)
{
  this->name_ = name;
}

//
// name
//
inline
const ACE_CString & T3_Parse_Tree::name (void) const
{
  return this->name_;
}

//
// string_literals
//
inline
const T3_Parse_Tree::STRING_LIT_SET &
T3_Parse_Tree::string_literals (void) const
{
  return this->strlits_;
}
