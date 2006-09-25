// $Id$

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::String>::
write (std::ostream & out)
{
  out << "ACE_CString";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::LongInteger>::
write (std::ostream & out)
{
  out << "long";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::ShortInteger>::
write (std::ostream & out)
{
  out << "short";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::Boolean>::
write (std::ostream & out)
{
  out << "bool";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::Byte>::
write (std::ostream & out)
{
  out << "::CORBA::Octet";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::RealNumber>::
write (std::ostream & out)
{
  out << "double";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::GenericObject>::
write (std::ostream & out)
{
  out << "::CORBA::Object::_var_type";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::GenericValue>::
write (std::ostream & out)
{
  out << "::CORBA::Any";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::TypeKind>::
write (std::ostream & out)
{
  out << "::CORBA::TCKind";
}

CUTS_INLINE
void CUTS_CIAO_Var_Type_T <PICML::TypeEncoding>::
write (std::ostream & out)
{
  out << "::CORBA::TypeCode::_var_type";
}
