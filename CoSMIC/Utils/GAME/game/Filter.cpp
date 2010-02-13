// $Id$

#include "Filter.h"
#include "Project.h"
#include "FCO.h"

namespace GME
{
//
// Filter
//
Filter::Filter (Project & project)
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
void Filter::name (const std::string & value)
{
  CComBSTR bstr (value.length (), value.c_str ());
  VERIFY_HRESULT (this->filter_->put_Name (bstr));
}

//
// apply
//
size_t Filter::apply (GME::Collection_T <FCO> & result) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->project_.impl ()->AllFCOs (this->filter_, &fcos));

  result.attach (fcos.Detach ());
  return result.size ();
}

}
