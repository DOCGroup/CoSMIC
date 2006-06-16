// $Id: UDM_Utility_T.cpp,v 1.1.2.1 2006/06/07 03:41:20 hillj Exp $

//
// UDM_Accept_Functor
//
template <typename VISITOR, typename ELEMENT>
UDM_Accept_Functor <VISITOR, ELEMENT>::UDM_Accept_Functor (VISITOR & visitor)
: visitor_ (visitor)
{

}

//
// operator ()
//
template <typename VISITOR, typename ELEMENT>
void UDM_Accept_Functor <VISITOR, ELEMENT>::operator () (ELEMENT & element)
{
  element.Accept (this->visitor_);
}
