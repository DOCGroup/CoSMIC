
namespace T3
{
inline
Auto_Model::Auto_Model (void)
: impl_ (0)
{

}

inline
Auto_Model::Auto_Model (const ::GAME::Object & model)
: impl_ (0)
{
  this->attach (model);
}

inline
::GAME::Object & Auto_Model::model (void)
{
  return this->impl_->model ();
}

inline
const ::GAME::Object & Auto_Model::model (void) const
{
  return this->impl_->model ();
}

}
