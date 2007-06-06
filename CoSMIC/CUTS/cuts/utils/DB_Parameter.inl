// $Id$

//
// type
//
CUTS_INLINE
CUTS_DB_Parameter::Parameter_Type
CUTS_DB_Parameter::type (void) const
{
  return this->type_;
}

//
// index
//
CUTS_INLINE
size_t CUTS_DB_Parameter::index (void) const
{
  return this->index_;
}

//
// bind
//
CUTS_INLINE
void CUTS_DB_Parameter::bind (char *, size_t)
{
  this->type_ = CUTS_DB_Parameter::PT_CHAR;
}

//
// bind
//
CUTS_INLINE
void CUTS_DB_Parameter::bind (short *)
{
  this->type_ = CUTS_DB_Parameter::PT_SHORT;
}

//
// bind
//
CUTS_INLINE
void CUTS_DB_Parameter::bind (u_short *)
{
  this->type_ = CUTS_DB_Parameter::PT_USHORT;
}

//
// bind
//
CUTS_INLINE
void CUTS_DB_Parameter::bind (long *)
{
  this->type_ = CUTS_DB_Parameter::PT_LONG;
}

//
// bind
//
CUTS_INLINE
void CUTS_DB_Parameter::bind (u_long *)
{
  this->type_ = CUTS_DB_Parameter::PT_ULONG;
}

//
// bind
//
CUTS_INLINE
void CUTS_DB_Parameter::bind (double *)
{
  this->type_ = CUTS_DB_Parameter::PT_DOUBLE;
}

//
// bind
//
CUTS_INLINE
void CUTS_DB_Parameter::bind (float *)
{
  this->type_ = CUTS_DB_Parameter::PT_FLOAT;
}

//
// bind
//
CUTS_INLINE
void CUTS_DB_Parameter::bind (CUTS_DB_Date_Time_Impl *)
{
  this->type_ = CUTS_DB_Parameter::PT_DATETIME;
}

//
// is_null
//
CUTS_INLINE
int CUTS_DB_Parameter::is_null (void) const
{
  return this->null_;
}

//
// null
//
CUTS_INLINE
void CUTS_DB_Parameter::null (void)
{
  this->null_ = 1;
}

//
// direction
//
CUTS_INLINE
CUTS_DB_Parameter::Direction_Type
CUTS_DB_Parameter::direction (void) const
{
  return this->direction_;
}
