// $Id$

//
// CUTS_CIAO_Retn_Type_T <PICML::MemberType>
//
CUTS_INLINE
CUTS_CIAO_Retn_Type_T <PICML::MemberType>::
CUTS_CIAO_Retn_Type_T (const PICML::MemberType & element)
: element_ (element)
{

}

//
// CUTS_CIAO_Retn_Type_T <PICML::PredefinedType>
//
CUTS_INLINE
CUTS_CIAO_Retn_Type_T <PICML::PredefinedType>::
CUTS_CIAO_Retn_Type_T (const PICML::PredefinedType & element)
: element_ (element)
{

}

//
// write <PICML::String>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::String>::
write (std::ostream & out)
{
  out << "char *";
}

//
// write <PICML::LongInteger>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::LongInteger>::
write (std::ostream & out)
{
  out << "::CORBA::Long";
}

//
// write <PICML::ShortInteger>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::ShortInteger>::
write (std::ostream & out)
{
  out << "::CORBA::Short";
}

//
// write <PICML::Boolean>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::Boolean>::
write (std::ostream & out)
{
  out << "::CORBA::Boolean";
}

//
// write <PICML::Byte>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::Byte>::
write (std::ostream & out)
{
  out << "::CORBA::Octet";
}

//
// write <PICML::RealNumber>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::RealNumber>::
write (std::ostream & out)
{
  out << "::CORBA::Double";
}

//
// write <PICML::GenericObject>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::GenericObject>::
write (std::ostream & out)
{
  out << "::CORBA::Object::_ptr_type";
}

//
// write <PICML::GenericValue>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::GenericValue>::
write (std::ostream & out)
{
  out << "::CORBA::Any::_ptr_type";
}

//
// write <PICML::TypeKind>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::TypeKind>::
write (std::ostream & out)
{
  out << "::CORBA::TCKind";
}

//
// write <PICML::TypeEncoding>
//
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <PICML::TypeEncoding>::
write (std::ostream & out)
{
  out << "::CORBA::TypeCode::_ptr_type";
}
