// $Id$

#include "stdafx.h"
#include "Patron.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "Library/Visitor.h"
#include "Library/Library/Borrow.h"
#include "Library/Library/Library.h"

namespace Library
{
  //
  // metaname
  //
  const std::string Patron_Impl::metaname = "Patron";

  //
  // Patron_Impl
  //
  Patron_Impl::Patron_Impl (void)
  {
  }

  //
  // Patron_Impl
  //
  Patron_Impl::Patron_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Patron_Impl
  //
  Patron_Impl::~Patron_Impl (void)
  {
  }

  //
  // accept
  //
  void Patron_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Patron (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // _create
  //
  Patron Patron_Impl::_create (const Library_in parent)
  {
    return ::GAME::Mga::create_object <Patron> (parent, Patron_Impl::metaname);
  }

  //
  // HomeAddress
  //
  void Patron_Impl::HomeAddress (const std::string & val)
  {
    static const std::string attr_HomeAddress ("HomeAddress");
    this->attribute (attr_HomeAddress)->string_value (val);
  }

  //
  // HomeAddress
  //
  std::string Patron_Impl::HomeAddress (void) const
  {
    static const std::string attr_HomeAddress ("HomeAddress");
    return this->attribute (attr_HomeAddress)->string_value ();
  }

  //
  // Gender
  //
  void Patron_Impl::Gender (const std::string & val)
  {
    static const std::string attr_Gender ("Gender");
    this->attribute (attr_Gender)->string_value (val);
  }

  //
  // Gender
  //
  std::string Patron_Impl::Gender (void) const
  {
    static const std::string attr_Gender ("Gender");
    return this->attribute (attr_Gender)->string_value ();
  }

  //
  // Age
  //
  void Patron_Impl::Age (long val)
  {
    static const std::string attr_Age ("Age");
    this->attribute (attr_Age)->int_value (val);
  }

  //
  // Age
  //
  long Patron_Impl::Age (void) const
  {
    static const std::string attr_Age ("Age");
    return this->attribute (attr_Age)->int_value ();
  }

  //
  // SSN
  //
  void Patron_Impl::SSN (double val)
  {
    static const std::string attr_SSN ("SSN");
    this->attribute (attr_SSN)->double_value (val);
  }

  //
  // SSN
  //
  double Patron_Impl::SSN (void) const
  {
    static const std::string attr_SSN ("SSN");
    return this->attribute (attr_SSN)->double_value ();
  }

  //
  // Name
  //
  void Patron_Impl::Name (const std::string & val)
  {
    static const std::string attr_Name ("Name");
    this->attribute (attr_Name)->string_value (val);
  }

  //
  // Name
  //
  std::string Patron_Impl::Name (void) const
  {
    static const std::string attr_Name ("Name");
    return this->attribute (attr_Name)->string_value ();
  }

  //
  // in_Borrow_connections
  //
  size_t Patron_Impl::in_Borrow_connections (std::vector <Borrow> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_Library
  //
  Library Patron_Impl::parent_Library (void) const
  {
    return ::GAME::Mga::get_parent <Library> (this->object_.p);
  }
}

