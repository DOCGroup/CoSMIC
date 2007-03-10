// $Id$

#include "BE_Scope_Manager.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Scope_Manager.inl"
#endif

#include <stack>
#include "Uml.h"

//
// instance_
//
CUTS_BE_Scope_Manager * CUTS_BE_Scope_Manager::instance_ = 0;

//
// instance
//
CUTS_BE_Scope_Manager * CUTS_BE_Scope_Manager::instance (void)
{
  if (CUTS_BE_Scope_Manager::instance_ == 0)
    CUTS_BE_Scope_Manager::instance_ = new CUTS_BE_Scope_Manager ();

  return CUTS_BE_Scope_Manager::instance_;
}

//
// close_singleton
//
void CUTS_BE_Scope_Manager::close_singleton (void)
{
  if (CUTS_BE_Scope_Manager::instance_)
  {
    delete CUTS_BE_Scope_Manager::instance_;
    CUTS_BE_Scope_Manager::instance_ = 0;
  }
}

//
// generator_scope
//
std::string CUTS_BE_Scope_Manager::
generate_scope (const PICML::NamedType & type,
                const std::string & separator,
                bool cache)
{
  std::string scope;

  if (!this->find (type, separator, scope))
  {
    std::stack <PICML::MgaObject> level;

    // Move up the hierarchy to the <PICML::File> object. We are going
    // to push each onto a stack so we generate the scope later.
    PICML::MgaObject parent = type.parent ();

    while (parent.type () != PICML::File::meta)
    {
      level.push (parent);
      parent = PICML::MgaObject::Cast (parent.parent ());
    }

    while (!level.empty ())
    {
      // Get the next scope level.
      parent = level.top ();
      scope += (std::string) parent.name () + separator;

      // Remove the scope from the list.
      level.pop ();
    }

    if (cache)
      this->scopes_[type][separator] = scope;
  }

  return scope;
}

//
// find
//
bool CUTS_BE_Scope_Manager::find (const PICML::NamedType & type,
                                  const std::string & separator,
                                  std::string & scope)
{
  Scope_Map::iterator type_iter = this->scopes_.find (type);
  if (type_iter == this->scopes_.end ())
    return false;

  Separator_Map::iterator separator_iter = type_iter->second.find (separator);
  if (separator_iter == type_iter->second.end ())
    return false;

  scope = separator_iter->second;
  return true;
}
