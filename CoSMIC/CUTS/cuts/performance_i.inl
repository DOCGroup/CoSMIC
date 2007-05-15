// -*- C++ -*-
// $Id$

///////////////////////////////////////////////////////////////////////////////
// @@ extraction operators

//
// operator >>=
//
CUTS_INLINE
void operator >>= (const CUTS::Time_Stamp & ts, ACE_Time_Value & tm)
{
  tm.sec (ts.sec);
  tm.usec (ts.usec);
}

///////////////////////////////////////////////////////////////////////////////
// @@ insertion operators

//
// operator <<=
//
CUTS_INLINE
void operator <<= (CUTS::Endpoint_Time_Info & eti,
                   CUTS_Port_Measurement_Endpoint_Map::ENTRY & entry)
{
  eti.uid = entry.key ();
  eti.info <<= *entry.item ();
}

//
// operator <<=
//
CUTS_INLINE
void operator <<= (CUTS::Time_Stamp & ts, const ACE_Time_Value & tv)
{
  ts.sec = tv.sec ();
  ts.usec = tv.usec ();
}
