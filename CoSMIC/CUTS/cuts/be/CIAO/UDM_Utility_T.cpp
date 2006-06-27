// $Id$

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
