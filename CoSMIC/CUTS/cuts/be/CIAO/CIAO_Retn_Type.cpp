// $Id$

#include "CIAO_Retn_Type.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Retn_Type.inl"
#endif

#include "Uml.h"

//
// <PICML::MemberType> write
//
void CUTS_CIAO_Retn_Type_T <PICML::MemberType>::
write (std::ostream & out) const
{
  try
  {
    CUTS_CIAO_Retn_Type_T <PICML::PredefinedType> (
      PICML::PredefinedType::Cast (this->element_)).write (out);
  }
  catch (...)
  {
    CUTS_CIAO_Retn_Type_T <PICML::NamedType> (
      PICML::NamedType::Cast (this->element_)).write (out);
  }
}

//
// <PICML::PredefinedType> write
//
void CUTS_CIAO_Retn_Type_T <PICML::PredefinedType>::
write (std::ostream & out) const
{
  Uml::Class metatype = this->element_.type ();

  if (metatype == PICML::String::meta)
    CUTS_CIAO_Retn_Type_T <PICML::String>::write (out);

  else if (metatype == PICML::Byte::meta)
    CUTS_CIAO_Retn_Type_T <PICML::Byte>::write (out);

  else if (metatype == PICML::ShortInteger::meta)
    CUTS_CIAO_Retn_Type_T <PICML::ShortInteger>::write (out);

  else if (metatype == PICML::LongInteger::meta)
    CUTS_CIAO_Retn_Type_T <PICML::LongInteger>::write (out);

  else if (metatype == PICML::Boolean::meta)
    CUTS_CIAO_Retn_Type_T <PICML::Boolean>::write (out);

  else if (metatype == PICML::RealNumber::meta)
    CUTS_CIAO_Retn_Type_T <PICML::RealNumber>::write (out);

  else if (metatype == PICML::GenericObject::meta)
    CUTS_CIAO_Retn_Type_T <PICML::GenericObject>::write (out);

  else if (metatype == PICML::GenericValue::meta)
    CUTS_CIAO_Retn_Type_T <PICML::GenericValue>::write (out);

  else if (metatype == PICML::TypeKind::meta)
    CUTS_CIAO_Retn_Type_T <PICML::TypeKind>::write (out);

  else if (metatype == PICML::TypeEncoding::meta)
    CUTS_CIAO_Retn_Type_T <PICML::TypeEncoding>::write (out);

  else
    out << "/* unsupported type [" << metatype.name () << "] */";
}
