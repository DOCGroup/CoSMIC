
namespace T3
{
inline
Auto_Model::Auto_Model (void)
: impl_ (0)
{

}

inline
Auto_Model::Auto_Model (const ::GME::Object & model)
: impl_ (new Auto_Model_Impl (model))
{

}

inline
::GME::Object & Auto_Model::model (void)
{
  return this->impl_->model ();
}

inline
const ::GME::Object & Auto_Model::model (void) const
{
  return this->impl_->model ();
}

}
