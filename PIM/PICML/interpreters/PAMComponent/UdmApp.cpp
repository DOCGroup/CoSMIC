/*
  Copyright (c) Vanderbilt University, 2000-2001
  ALL RIGHTS RESERVED
  Vanderbilt University disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall Vanderbilt University be liable for
  any special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/


// UdmApp.cpp: implementation of the CUdmApp class.
// This file was automatically generated as UdmApp.cpp
// by UDM Interpreter Wizard on Monday, May 13, 2002 13:45:42

// Tihamér Levendovszky 05-13-02

#include "stdafx.h"
#pragma warning( disable : 4290 )

#include <windows.h>
#include <shlobj.h>
#include "resource.h"
#include <stdlib.h>
#include <sstream>

#include "UdmStatic.h"
#include "UmlExt.h"
#include "UdmUtil.h"

#include "UdmApp.h"
#include "UdmConfig.h"

#include "Utils/Utils.h"
#include "PAM/PAMVisitor.h"

extern void dummy(void); // Dummy function for UDM meta initialization

// Initialization function. The framework calls it before preparing the
// backend. Initialize here the settings in the config static object.
// Return 0 if successful.
int CUdmApp::Initialize()
{
  return 0;
}
/*
  Remarks to CUdmApp::UdmMain(...):
  0. The p_backend points to an already open backend, and the framework
  closes it automatically. DO NOT OPEN OR CLOSE IT! To commit changes
  use p_backend->CommitEditSequence(). To abort changes use
  p_backend->AbortEditSequence(). To save changes to a different file
  use p_backend->SaveAs() or p_backend->CloseAs().

  1. Focus is the currently open model.

  2. The possible values for param (from GME DecoratorLib.h
  component_startmode_enum):
  GME_MAIN_START    =   0,
  GME_BROWSER_START    =   1,
  GME_CONTEXT_START    =   2,
  GME_EMBEDDED_START    =   3,
  GME_MENU_START    =  16,
  GME_BGCONTEXT_START  =  18,
  GME_ICON_START    =  32,
  METAMODEL_CHECK_SYNTAX  = 101

  3. The framework catches all the exceptions and reports the error in a
  message box, clean up and close the transactions aborting the changes.
  You can override this behavior by catching udm_exception. Use
  udm_exception::what() to form an error message.
*/

/***********************************************/
/* Main entry point for Udm-based Interpreter  */
/***********************************************/

void CUdmApp::UdmMain (Udm::DataNetwork* p_backend,        // Backend pointer
                       Udm::Object focusObject,            // Focus object
                       set <Udm::Object> selectedObjects,  // Selected objects
                       long param)                         // Parameters
{
  using std::string;
  using PICML::CompCliques;
  using PICML::Component;
  using PICML::PAMVisitor;
  using PICML::RootFolder;
 
  try
    {
      PAMVisitor visitor (focusObject, selectedObjects);

      RootFolder
        start = RootFolder::Cast (p_backend->GetRootObject());

      start.Accept (visitor);

      AfxMessageBox ("Successfully generated physical assembly!",
                     MB_OK| MB_ICONINFORMATION);
    }
  catch (const udm_exception &e)
    {
      AfxMessageBox ("Interpretation Failed. Caught UDM Exception: "
                     + CString (e.what()));
    }
  catch (const CompCliques& cliqueSets)
    {
      CompCliques::const_iterator begin, end;
      boost::tie (begin, end) = make_pair (cliqueSets.begin(),
                                           cliqueSets.end());
      for (; begin != end; ++begin)
        {
          set<Component> clique (begin->begin(), begin->end());
          set<Component>::iterator cBegin, cEnd;
          boost::tie (cBegin, cEnd) = make_pair (clique.begin(),
                                                 clique.end());

          stringstream ss;
          ss << "Clique contains: (";
          if (cBegin != cEnd)
            {
              string name (cBegin->name());
              ss << name;
              ++cBegin;
              while (cBegin != cEnd)
                {
                  name = cBegin->name();
                  ss << "," << name;
                  ++cBegin;
                }
              ss << ")\n";
            }
          AfxMessageBox (CString(ss.str().c_str()), MB_OK| MB_ICONINFORMATION);
        }
    }
  return;
}
