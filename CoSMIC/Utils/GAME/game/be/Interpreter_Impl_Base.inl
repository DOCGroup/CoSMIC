// $Id$

//
// Interpreter_Impl_Base
//
GME_INLINE
GME::Interpreter_Impl_Base::Interpreter_Impl_Base (bool is_managed)
: name_ ("Interpreter"),
  paradigm_ ("*"),
  is_managed_ (is_managed)
{

}

//
// Interpreter_Impl_Base
//
GME_INLINE
GME::Interpreter_Impl_Base::
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
GME_INLINE
GME::Interpreter_Impl_Base::~Interpreter_Impl_Base (void)
{

}

//
// initialize
//
GME_INLINE
int GME::Interpreter_Impl_Base::initialize (GME::Project & project)
{
  return 0;
}

//
// invoke
//
GME_INLINE
int GME::Interpreter_Impl_Base::
invoke (GME::Project & project,
        GME::Collection_T <GME::FCO> & selected,
        long flags)
{
  return 0;
}

//
// invoke
//
GME_INLINE
int GME::Interpreter_Impl_Base::
invoke_ex (GME::Project & project,
           GME::FCO & fco,
           GME::Collection_T <GME::FCO> & selected,
           long flags)
{
  return 0;
}

//
// invoke
//
GME_INLINE
int GME::Interpreter_Impl_Base::
invoke_object_ex (GME::Project & project,
                  GME::Object & obj,
                  GME::Collection_T <GME::Object> & selected,
                  long flags)
{
  return 0;
}

//
// interactive
//
GME_INLINE
void GME::Interpreter_Impl_Base::interactive (bool mode)
{
  this->is_interactive_ = mode;
}

//
// interactive
//
GME_INLINE
bool GME::Interpreter_Impl_Base::interactive (void) const
{
  return this->is_interactive_;
}

//
// interactive
//
GME_INLINE
void GME::Interpreter_Impl_Base::enable (bool mode)
{
  this->is_enabled_ = mode;
}

//
// paradigm
//
GME_INLINE
const std::string & GME::Interpreter_Impl_Base::paradigm (void) const
{
  return this->paradigm_;
}

//
// name
//
GME_INLINE
const std::string & GME::Interpreter_Impl_Base::name (void) const
{
  return this->name_;
}

//
// paradigm
//
GME_INLINE
const std::string & GME::Interpreter_Impl_Base::progid (void) const
{
  return this->progid_;
}

//
// paradigm
//
GME_INLINE
bool GME::Interpreter_Impl_Base::is_managed (void) const
{
  return this->is_managed_;
}
