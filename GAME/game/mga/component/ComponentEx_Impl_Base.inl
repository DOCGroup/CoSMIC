// $Id$

#include "game/mga/Project.h"

namespace GAME
{
namespace Mga
{

//
// ComponentEx_Impl_Base
//
GAME_INLINE
ComponentEx_Impl_Base::
ComponentEx_Impl_Base (const std::string & name,
                       const std::string & paradigm,
                       const std::string & progid,
                       bool is_managed)
: name_ (name),
  paradigm_ (paradigm),
  progid_ (progid),
  is_managed_ (is_managed)
{

}

//
// ~ComponentEx_Impl_Base
//
GAME_INLINE
ComponentEx_Impl_Base::~ComponentEx_Impl_Base (void)
{

}

//
// initialize
//
GAME_INLINE
int ComponentEx_Impl_Base::initialize (Project project)
{
  return 0;
}

//
// invoke
//
GAME_INLINE
int ComponentEx_Impl_Base::
invoke (Project project,
        std::vector <FCO> & selected,
        long flags)
{
  return 0;
}

//
// invoke
//
GAME_INLINE
int ComponentEx_Impl_Base::
invoke_ex (Project project,
           FCO_in fco,
           std::vector <FCO> & selected,
           long flags)
{
  return 0;
}

//
// invoke
//
GAME_INLINE
int ComponentEx_Impl_Base::
invoke_object_ex (Project project,
                  Object_in obj,
                  std::vector <Object> & selected,
                  long flags)
{
  return 0;
}

//
// interactive
//
GAME_INLINE
void ComponentEx_Impl_Base::interactive (bool mode)
{
  this->is_interactive_ = mode;
}

//
// interactive
//
GAME_INLINE
bool ComponentEx_Impl_Base::interactive (void) const
{
  return this->is_interactive_;
}

//
// interactive
//
GAME_INLINE
void ComponentEx_Impl_Base::enable (bool mode)
{
  this->is_enabled_ = mode;
}

//
// paradigm
//
GAME_INLINE
const std::string & ComponentEx_Impl_Base::paradigm (void) const
{
  return this->paradigm_;
}

//
// name
//
GAME_INLINE
const std::string & ComponentEx_Impl_Base::name (void) const
{
  return this->name_;
}

//
// paradigm
//
GAME_INLINE
const std::string & ComponentEx_Impl_Base::progid (void) const
{
  return this->progid_;
}

//
// paradigm
//
GAME_INLINE
bool ComponentEx_Impl_Base::is_managed (void) const
{
  return this->is_managed_;
}

//
// set_parameter
//
GAME_INLINE
int ComponentEx_Impl_Base::
set_parameter (const std::string & name, const std::string & value)
{
  return 0;
}

//
// get_parameter
//
GAME_INLINE
int ComponentEx_Impl_Base::
get_parameter (const std::string & name, std::string & value)
{
  return 0;
}

}
}
