// UdmApp.h: interface for the CUdmApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UDMAPP_H__296A93EB_6DB6_4179_AA0B_A3D799FB3A1C__INCLUDED_)
#define AFX_UDMAPP_H__296A93EB_6DB6_4179_AA0B_A3D799FB3A1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

// Udm includes
#include "UdmBase.h"
#include "Uml.h"
#include "UmlExt.h"

#ifdef _USE_DOM
  #include "UdmDOM.h"
#endif

#include "UdmGme.h"
#include "UdmStatic.h"

#include "cuts/be/BE_Manager_Factory_Repo.h"

//=============================================================================
/**
 * @class CUdmApp
 */
//=============================================================================

class CUdmApp
{
public:
  static int Initialize (void);

  static void UdmMain (Udm::DataNetwork * p_backend,
                       Udm::Object currentObject,
                       set <Udm::Object> selectedObjects,
                       long param);

private:
  /// Repository of backend generators.
  static CUTS_BE_Manager_Factory_Repo repo_;
};

#endif // !defined(AFX_UDMAPP_H__296A93EB_6DB6_4179_AA0B_A3D799FB3A1C__INCLUDED_)
