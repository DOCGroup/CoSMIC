// $Id$

#include "stdafx.h"
#include "Console_Service.h"

#if !defined (__GAME_INLINE__)
#include "Console_Service.inl"
#endif

namespace GAME
{
namespace Mga
{

//
// initialize
//
void Console_Service::initialize (const Project & proj)
{
  if (this->is_initialized ())
    return;

  // Locate the GME application for the project.
  ATL::CComPtr <IMgaClient> client;
  VERIFY_HRESULT (proj.impl ()->GetClientByName (L"GME.Application", &client));

  if (0 == client)
    return;

  ATL::CComPtr <IDispatch> dispatch;
  VERIFY_HRESULT (client->get_OLEServer (&dispatch));
  VERIFY_HRESULT (dispatch->QueryInterface (&this->gmeapp_));
}

//
// log
//
void Console_Service::log (msgtype_enum type, const std::string & message)
{
  if (this->is_initialized ())
  {
    ATL::CComBSTR bstr (message.size (), message.c_str ());
    VERIFY_HRESULT (this->gmeapp_->ConsoleMessage (bstr, type));
  }
}

//
// clear
//
void Console_Service::clear (void)
{
  if (this->is_initialized ())
    VERIFY_HRESULT (this->gmeapp_->ConsoleClear ());
}

}
}
