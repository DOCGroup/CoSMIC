// $Id: UUID.inl,v 1.1.4.2 2006/03/12 01:48:06 hillj Exp $

CUTS_INLINE
bool CUTS_UUID::operator != (const CUTS_UUID & uuid) const
{
  return !(*this == uuid);
}
