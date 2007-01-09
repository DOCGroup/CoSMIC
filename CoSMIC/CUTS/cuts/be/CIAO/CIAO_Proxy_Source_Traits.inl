// $Id$

//
// write_environment_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_environment_begin (const PICML::Component & component)
{
  this->write_set_session_context (component);
}

//
// write_environment_method_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_environment_method_begin (const PICML::InputAction & action)
{

}

//
// write_environment_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_environment_method_end (const PICML::InputAction & action)
{

}

//
// write_environment_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_environment_end (const PICML::Component & component)
{

}

//
// write_action_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_action_begin (const PICML::Worker & parent,
                    const PICML::Action & action)
{

}

//
// write_action_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_action_end (void)
{

}

//
// write_action_property
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_action_property (const PICML::Property & property)
{

}

//
// write_action_begin
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_action_begin (const PICML::OutputAction & action)
{

}

//
// write_precondition
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_precondition (const std::string & precondition)
{

}

//
// write_precondition
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_postcondition (const std::string & postcondition)
{

}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_method_end (const PICML::ProvidedRequestPort & facet)
{
  this->_super::write_method_end (facet);
}


//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_method_end (const PICML::ReadonlyAttribute & attr)
{
  this->_super::write_method_end (attr);
}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_method_begin (const PICML::PeriodicEvent & periodic)
{

}

//
// write_method_end
//
CUTS_INLINE
void CUTS_CIAO_Proxy_Source_Traits::
write_method_end (const PICML::PeriodicEvent & periodic)
{

}
