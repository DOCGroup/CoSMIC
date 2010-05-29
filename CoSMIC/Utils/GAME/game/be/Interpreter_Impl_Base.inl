// $Id$

//
// Interpreter_Impl_Base
//
GAME_INLINE
GAME::Interpreter_Impl_Base::Interpreter_Impl_Base (bool is_managed)
: name_ ("Interpreter"),
  paradigm_ ("*"),
  is_managed_ (is_managed)
{

}

//
// Interpreter_Impl_Base
//
GAME_INLINE
GAME::Interpreter_Impl_Base::
Interpreter_Impl_Base (const std::string & name,
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
// ~Interpreter_Impl_Base
//
GAME_INLINE
GAME::Interpreter_Impl_Base::~Interpreter_Impl_Base (void)
{

}

//
// initialize
//
GAME_INLINE
int GAME::Interpreter_Impl_Base::initialize (GAME::Project & project)
{
  return 0;
}

//
// invoke
//
GAME_INLINE
int GAME::Interpreter_Impl_Base::
invoke (GAME::Project & project,
        std::vector <GAME::FCO> & selected,
        long flags)
{
  return 0;
}

//
// invoke
//
GAME_INLINE
int GAME::Interpreter_Impl_Base::
invoke_ex (GAME::Project & project,
           GAME::FCO & fco,
           std::vector <GAME::FCO> & selected,
           long flags)
{
  return 0;
}

//
// invoke
//
GAME_INLINE
int GAME::Interpreter_Impl_Base::
invoke_object_ex (GAME::Project & project,
                  GAME::Object & obj,
                  std::vector <GAME::Object> & selected,
                  long flags)
{
  return 0;
}

//
// interactive
//
GAME_INLINE
void GAME::Interpreter_Impl_Base::interactive (bool mode)
{
  this->is_interactive_ = mode;
}

//
// interactive
//
GAME_INLINE
bool GAME::Interpreter_Impl_Base::interactive (void) const
{
  return this->is_interactive_;
}

//
// interactive
//
GAME_INLINE
void GAME::Interpreter_Impl_Base::enable (bool mode)
{
  this->is_enabled_ = mode;
}

//
// paradigm
//
GAME_INLINE
const std::string & GAME::Interpreter_Impl_Base::paradigm (void) const
{
  return this->paradigm_;
}

//
// name
//
GAME_INLINE
const std::string & GAME::Interpreter_Impl_Base::name (void) const
{
  return this->name_;
}

//
// paradigm
//
GAME_INLINE
const std::string & GAME::Interpreter_Impl_Base::progid (void) const
{
  return this->progid_;
}

//
// paradigm
//
GAME_INLINE
bool GAME::Interpreter_Impl_Base::is_managed (void) const
{
  return this->is_managed_;
}
