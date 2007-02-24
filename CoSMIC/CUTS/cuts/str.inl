// -*- C++ -*-

//
// CUTS_str
//
CUTS_INLINE
CUTS_str::CUTS_str (void)
{

}

//
// CUTS_str
//
CUTS_INLINE
CUTS_str::CUTS_str (const char * str)
: str_ (str)
{

}

//
// CUTS_str
//
CUTS_INLINE
CUTS_str::CUTS_str (const CUTS_str & str)
: str_ (str.str_)
{

}

//
// ~CUTS_str
//
CUTS_INLINE
CUTS_str::~CUTS_str (void)
{

}

//
// operator const char *
//
CUTS_INLINE
CUTS_str::operator const char * (void) const
{
  return this->str_.c_str ();
}

//
// operator =
//
CUTS_INLINE
const CUTS_str & CUTS_str::operator = (const CUTS_str & str)
{
  if (this != &str)
    this->str_ = str.str_;
  return *this;
}
