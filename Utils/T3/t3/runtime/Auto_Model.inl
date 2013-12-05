
namespace T3
{
//
// Auto_Model
//
inline
Auto_Model::Auto_Model (void)
: impl_ (0)
{

}

//
// Auto_Model
//
inline
Auto_Model::Auto_Model (const GAME::Mga::Object_in obj)
: impl_ (0)
{
  this->attach (obj);
}

//
// model
//
inline
GAME::Mga::Object Auto_Model::model (void)
{
  return this->impl_->model ();
}

//
// model
//
inline
const GAME::Mga::Object Auto_Model::model (void) const
{
  return this->impl_->model ();
}

}
