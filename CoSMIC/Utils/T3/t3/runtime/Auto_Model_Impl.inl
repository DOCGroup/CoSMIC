// $Id$

namespace T3
{
inline
Auto_Model_Impl::Auto_Model_Impl (void)
: ref_count_ (1)
{

}

inline
Auto_Model_Impl::Auto_Model_Impl (const ::GME::Object & model)
: ref_count_ (1)
{
  this->store (model);
}

inline
Auto_Model_Impl::~Auto_Model_Impl (void)
{
  this->cleanup ();
}

inline
::GME::Object & Auto_Model_Impl::model (void)
{
  return this->model_;
}

inline
const ::GME::Object & Auto_Model_Impl::model (void) const
{
  return this->model_;
}

inline
void Auto_Model_Impl::inc_refcount (void)
{
  ++ this->ref_count_;
}

inline
size_t Auto_Model_Impl::refcount (void) const
{
  return this->ref_count_;
}
}
