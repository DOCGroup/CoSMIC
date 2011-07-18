// $Id$

#include "Template_Parameter_Manager.h"

#include "boost/bind.hpp"
#include <algorithm>
#include <functional>
#include <iostream>

//
// Template_Parameter_Manager
//
Template_Parameter_Manager::Template_Parameter_Manager (void)
: active_ (0)
{

}

//
// ~Template_Parameter_Manager
//
Template_Parameter_Manager::~Template_Parameter_Manager (void)
{

}

//
// push_back
//
int Template_Parameter_Manager::
push_back (const FE_Utils::T_Param_Info * info, GAME::XME::FCO fco)
{
  if (0 == this->active_.get ())
    return -1;

  this->active_->push_back (std::make_pair (info, fco));
  return 0;
}

//
// begin_parameter_set
//
int Template_Parameter_Manager::begin_parameter_set (void)
{
  if (0 != this->active_.get ())
    this->entries_.push (this->active_.release ());

  this->active_.reset (new PARAMETER_SET ());
  return 0;
}

//
// end_parameter_set
//
int Template_Parameter_Manager::end_parameter_set (void)
{
  // Delete the current parameter set.
  if (0 != this->active_.get ())
    this->active_.reset ();

  if (!this->entries_.is_empty ())
  {
    // Restore the previous parameter set.
    PARAMETER_SET * entry = 0;
    this->entries_.pop (entry);

    if (0 != entry)
      this->active_.reset (entry);
  }

  return 0;
}

//
// end_parameter_set
//
int Template_Parameter_Manager::end_parameter_set (AST_Decl * decl)
{
  // Store the active parameter set for later retrieval.
  this->cached_[decl] = this->active_.release ();

  if (!this->entries_.is_empty ())
  {
    // Restore the previous parameter set.
    PARAMETER_SET * entry = 0;
    this->entries_.pop (entry);

    if (0 != entry)
      this->active_.reset (entry);
  }

  return 0;
}

//
// begin_parameter_set
//
int Template_Parameter_Manager::begin_parameter_set (AST_Decl * decl)
{
  // Store the current parameter set.
  if (0 != this->active_.get ())
    this->entries_.push (this->active_.release ());

  // Use the parameter set for the declaration.
  std::map <AST_Decl *, PARAMETER_SET * >::
    iterator iter = this->cached_.find (decl);

  if (iter == this->cached_.end ())
    return -1;

  this->active_.reset (iter->second);
  return 0;
}

//
// has_parameters
//
bool Template_Parameter_Manager::has_parameters (void) const
{
  return 0 != this->active_.get ();
}

//
// active_parameter_set
//
const Template_Parameter_Manager::PARAMETER_SET *
Template_Parameter_Manager::active_parameter_set (void) const
{
  return this->active_.get ();
}

//
// find
//
bool Template_Parameter_Manager::
find (const char * name, GAME::XME::FCO & fco) const
{
  if (this->find_i (this->active_.get (), name, fco))
    return true;

  // Search the previous set of parameters.
  ACE_Unbounded_Stack < PARAMETER_SET * >::
    ITERATOR iter (const_cast <ACE_Unbounded_Stack < PARAMETER_SET * > &> (this->entries_));

  for (; !iter.done (); iter.advance ())
  {
    PARAMETER_SET ** params = 0;
    iter.next (params);

    if (this->find_i (*params, name, fco))
      return true;
  }

  return false;
}

//
// find
//
bool Template_Parameter_Manager::
find (const FE_Utils::T_Param_Info * info, GAME::XME::FCO & fco) const
{
  return this->find (info->name_.c_str (), fco);
}

//
// find
//
bool Template_Parameter_Manager::
find (const char * name, const FE_Utils::T_Param_Info * & info) const
{
  if (this->find_i (this->active_.get (), name, info))
    return true;

  // Search the previous set of parameters.
  ACE_Unbounded_Stack < PARAMETER_SET * >::
    ITERATOR iter (const_cast <ACE_Unbounded_Stack < PARAMETER_SET * > &> (this->entries_));

  for (; !iter.done (); iter.advance ())
  {
    PARAMETER_SET ** params = 0;
    iter.next (params);

    if (this->find_i (*params, name, info))
      return true;
  }

  return false;
}

//
// find
//
bool Template_Parameter_Manager::
find_i (PARAMETER_SET * params, const char * name, const FE_Utils::T_Param_Info * & info) const
{
  if (0 == params)
    return false;

  PARAMETER_SET::const_iterator iter =
    std::find_if (params->begin (),
                  params->end (),
                  boost::bind (std::equal_to <ACE_CString> (),
                               name,
                               boost::bind (&FE_Utils::T_Param_Info::name_,
                                            boost::bind (&PARAMETER::first, _1))));

  if (iter == params->end ())
    return false;

  info = iter->first;
  return true;
}

//
// find
//
bool Template_Parameter_Manager::
find_i (PARAMETER_SET * params, const char * name, GAME::XME::FCO & fco) const
{
  if (0 == params)
    return false;

  PARAMETER_SET::const_iterator iter =
    std::find_if (params->begin (),
                  params->end (),
                  boost::bind (std::equal_to <ACE_CString> (),
                               name,
                               boost::bind (&FE_Utils::T_Param_Info::name_,
                                            boost::bind (&PARAMETER::first, _1))));

  if (iter == params->end ())
    return false;

  fco = iter->second;
  return true;
}
