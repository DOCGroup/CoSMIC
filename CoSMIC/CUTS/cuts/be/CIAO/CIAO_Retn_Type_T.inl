// $Id$


//
// CUTS_CIAO_Retn_Type_T
//
template <typename T>
CUTS_INLINE
CUTS_CIAO_Retn_Type_T <T>::
CUTS_CIAO_Retn_Type_T (const T & element)
{

}

//
// write
//
template <typename T>
CUTS_INLINE
void CUTS_CIAO_Retn_Type_T <T>::
write (std::ostream & out) const
{
  out << "/* unsupported type */";
}
