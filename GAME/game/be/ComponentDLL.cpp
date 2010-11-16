// $Id$

#include "StdAfx.h"
#include "ComponentDLL.h"

//
// MESSAGE_MAP
//
BEGIN_MESSAGE_MAP (GME::ComponentDLL, CWinApp)

END_MESSAGE_MAP()

//
// ComponentDLL
//
GME::ComponentDLL::ComponentDLL (const char * name)
: CWinApp (name)
{

}

//
// ~ComponentDLL
//
GME::ComponentDLL::~ComponentDLL (void)
{

}

//
// InitInstance
//
BOOL GME::ComponentDLL::InitInstance (void)
{
  return CWinApp::InitInstance ();
}

//
// ExitInstance
//
int GME::ComponentDLL::ExitInstance (void)
{
  return CWinApp::ExitInstance ();
}
