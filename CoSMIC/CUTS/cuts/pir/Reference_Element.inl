namespace CUTS_PIR
{
  //
  // reference
  //
  CUTS_INLINE
  Element * Reference_Element::reference (void) const
  {
    return this->reference_;
  }

  CUTS_INLINE
  void Reference_Element::reference (Element * reference)
  {
    this->reference_ = reference;
  }
}
