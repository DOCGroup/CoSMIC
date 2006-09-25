// $Id$

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::String>::
write (std::ostream & out)
{
  out << "char *";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::LongInteger>::
write (std::ostream & out)
{
  out << "::CORBA::Long";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::ShortInteger>::
write (std::ostream & out)
{
  out << "::CORBA::Short";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::Boolean>::
write (std::ostream & out)
{
  out << "::CORBA::Boolean";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::Byte>::
write (std::ostream & out)
{
  out << "::CORBA::Octet";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::RealNumber>::
write (std::ostream & out)
{
  out << "::CORBA::Double";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::GenericObject>::
write (std::ostream & out)
{
  out << "::CORBA::Object::_ptr_type";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::GenericValue>::
write (std::ostream & out)
{
  out << "::CORBA::Any::_ptr_type";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::TypeKind>::
write (std::ostream & out)
{
  out << "::CORBA::TCKind";
}

CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::TypeEncoding>::
write (std::ostream & out)
{
  out << "::CORBA::TypeCode::_ptr_type";
}
