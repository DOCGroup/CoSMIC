// $Id$

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_begin (const PICML::Attribute & attr)
{
  this->_super::write_method_begin (attr);
}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_begin (const PICML::ReadonlyAttribute & attr)
{
  this->_super::write_method_begin (attr);
}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  this->_super::write_method_begin (facet);
}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_begin (const PICML::PeriodicEvent & periodic)
{

}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_begin (const PICML::InEventPort & sink)
{
  this->_super::write_method_begin (sink);
}

//
// write_method
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method (const PICML::OutEventPort & source)
{
  this->_super::write_method (source);
}

//
// write_method
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method (const PICML::RequiredRequestPort & receptacle)
{
  this->_super::write_method (receptacle);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_end (const PICML::ProvidedRequestPort & facet)
{
  this->_super::write_method_end (facet);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_end (const PICML::InEventPort & sink)
{
  this->_super::write_method_end (sink);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_end (const PICML::PeriodicEvent & periodic)
{

}

//
// write_environment_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_environment_begin (const PICML::Component & component)
{
  this->_super::write_environment_begin (component);
}

//
// write_environment_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_environment_method_begin (const PICML::InputAction & action)
{

}

//
// write_environment_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_environment_method_end (const PICML::InputAction & action)
{

}

//
// write_environment_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_environment_end (const PICML::Component & component)
{

}


//
// write_variable
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_variable (const PICML::Variable & variable)
{

}

//
// write_variable
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_variable (const PICML::PeriodicEvent & periodic)
{

}

//
// write_variable
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_variable (const PICML::ReadonlyAttribute & readonly)
{

}

//
// write_variable
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_variable (const PICML::WorkerType & var,
                const PICML::Worker & worker)
{

}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_end (const PICML::ReadonlyAttribute & attr)
{
  this->_super::write_method_end (attr);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Header_Traits::
write_method_end (const PICML::Attribute & attr)
{
  this->_super::write_method_end (attr);
}

