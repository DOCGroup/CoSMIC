// $Id$

//
// write_environment_begin
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_environment_begin (const PICML::Component & component)
{
  this->_super::write_environment_begin (component);
}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_begin (const PICML::InEventPort & sink)
{
  this->_super::write_method_begin (sink);
}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_begin (const PICML::PeriodicEvent & periodic)
{
  this->_super::write_method_begin (periodic);
}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  this->_super::write_method_begin (facet);
}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_begin (const PICML::ReadonlyAttribute & attr)
{
  this->_super::write_method_begin (attr);
}

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_begin (const PICML::Attribute & attr)
{
  this->_super::write_method_begin (attr);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_end (const PICML::ReadonlyAttribute & attr)
{
  this->_super::write_method_end (attr);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_end (const PICML::PeriodicEvent & periodic)
{
  this->_super::write_method_end (periodic);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_end (const PICML::ProvidedRequestPort & facet)
{
  this->_super::write_method_end (facet);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_end (const PICML::Attribute & attr)
{
  this->_super::write_method_end (attr);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Header_Traits::
write_method_end (const PICML::InEventPort & sink)
{
  this->_super::write_method_end (sink);
}
