// $Id$

#include "CIAO_Var_Type.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Var_Type.inl"
#endif

#include "Uml.h"

//
// write
//
void CUTS_CIAO_Var_Type_T <PICML::MemberType>::
write (std::ostream & out, const PICML::MemberType & type)
{
  try
  {
    PICML::PredefinedType ptype = PICML::PredefinedType::Cast (type);
    CUTS_CIAO_Var_Type_T <PICML::PredefinedType>::write (out, ptype);
  }
  catch (...)
  {
    PICML::NamedType ntype = PICML::NamedType::Cast (type);
    CUTS_CIAO_Var_Type_T <PICML::NamedType>::write (out, ntype);
  }
}

//
// write
//
void CUTS_CIAO_Var_Type_T <PICML::PredefinedType>::
write (std::ostream & out, const PICML::PredefinedType & type)
{
  std::string metaname = type.type ().name ();

  if (metaname == (std::string)PICML::String::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::String>::write (out);

  else if (metaname == (std::string)PICML::Byte::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::Byte>::write (out);

  else if (metaname == (std::string)PICML::ShortInteger::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::ShortInteger>::write (out);

  else if (metaname == (std::string)PICML::LongInteger::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::LongInteger>::write (out);

  else if (metaname == (std::string)PICML::Boolean::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::Boolean>::write (out);

  else if (metaname == (std::string)PICML::RealNumber::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::RealNumber>::write (out);

  else if (metaname == (std::string)PICML::GenericObject::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::GenericObject>::write (out);

  else if (metaname == (std::string)PICML::GenericValue::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::GenericValue>::write (out);

  else if (metaname == (std::string)PICML::TypeKind::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::TypeKind>::write (out);

  else if (metaname == (std::string)PICML::TypeEncoding::meta.name ())
    CUTS_CIAO_Var_Type_T <PICML::TypeEncoding>::write (out);

  else
    out << "/* unsupported type [" << metaname << "] */";
}
