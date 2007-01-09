// $Id$

//
// write_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Exec_Source_Traits::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  this->_super::write_method_begin (facet);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Source_Traits::
write_method_end (const PICML::InEventPort & sink)
{
  this->_super::write_method_end (sink);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Source_Traits::
write_method_end (const PICML::PeriodicEvent & periodic)
{
  this->_super::write_method_end (periodic);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Source_Traits::
write_method_end (const PICML::ReadonlyAttribute & attr)
{
  this->_super::write_method_end (attr);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Exec_Source_Traits::
write_method_end (const PICML::Attribute & attr)
{
  this->_super::write_method_end (attr);
}

