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
void Console_Service::initialize (Project project)
{
  // Locate the GME application for the project.
  ATL::CComPtr <IMgaClient> client;
  VERIFY_HRESULT (project.impl ()->GetClientByName (L"GME.Application", &client));

  // We are going to store the project regardless of whether or not
  // we are able to locate the GME application.
  this->project_ = project;

  if (0 == client)
    return;

  ATL::CComPtr <IDispatch> dispatch;
  VERIFY_HRESULT (client->get_OLEServer (&dispatch));
  VERIFY_HRESULT (dispatch->QueryInterface (&this->gmeapp_));
}

//
// log
//
void Console_Service::log (int type, const std::string & message)
{
  // There is no need to continue if we do not have access to
  // the application.
  if (0 == this->gmeapp_)
    return;

  ATL::CComBSTR bstr (message.size (), message.c_str ());
  VERIFY_HRESULT (this->gmeapp_->ConsoleMessage (bstr, (msgtype_enum)type));
}

//
// clear
//
void Console_Service::clear (void)
{
  if (0 != this->gmeapp_)
    VERIFY_HRESULT (this->gmeapp_->ConsoleClear ());
}

}
}
