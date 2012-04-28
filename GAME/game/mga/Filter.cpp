// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Filter.h"
#include "Folder.h"
#include "Model.h"
#include "FCO.h"
#include "Collection_T.h"

#include "MetaFCO.h"

#include "boost/bind.hpp"

#include <sstream>
#include <algorithm>

namespace GAME
{
namespace Mga
{

template <typename F>
struct append_t
{
  append_t (std::ostream & ostr, F & func)
    : ostr_ (ostr),
      func_ (func)
  {

  }

  template <typename T>
  void operator () (T t) const
  {
    this->ostr_ << this->func_ (t) << " ";
  }

private:
  /// The target output stream.
  std::ostream & ostr_;

  F & func_;
};

template <typename F>
append_t <F> append (std::ostream & ostr, F & func)
{
  return append_t <F> (ostr, func);
}

//
// Filter
//
Filter::Filter (Project project)
: project_ (project)
{
  this->project_.impl ()->CreateFilter (&this->filter_);
}

//
// ~Filter
//
Filter::~Filter (void)
{

}

//
// kind
//
void Filter::kind (const std::string & value)
{
  CComBSTR bstr (value.length (), value.c_str ());
  VERIFY_HRESULT (this->filter_->put_Kind (bstr));
}

//
// kind
//
void Filter::kind (std::vector <std::string> & value)
{
  std::ostringstream ostr;
  std::for_each (value.begin (),
                 value.end (),
                 append (ostr, boost::bind (&std::string::c_str, _1)));

  this->kind (ostr.str ());
}

//
// kind
//
void Filter::kind (std::vector <Meta::FCO> & fcos)
{
  std::ostringstream ostr;
  std::for_each (fcos.begin (),
                 fcos.end (),
                 append (ostr,
                         boost::bind (&Meta::FCO::impl_type::name,
                                      boost::bind (&Meta::FCO::get, _1))));

  this->kind (ostr.str ());
}

//
// name
//
void Filter::name (const std::string & value)
{
  CComBSTR bstr (value.length (), value.c_str ());
  VERIFY_HRESULT (this->filter_->put_Name (bstr));
}

//
// name
//
void Filter::name (std::vector <std::string> & value)
{
  std::ostringstream ostr;
  std::for_each (value.begin (),
                 value.end (),
                 append (ostr, boost::bind (&std::string::c_str, _1)));

  this->name (ostr.str ());
}

}
}
