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

namespace PICML
{
  // Forward decl.
  class Visitor;
}

/**
 * @class CUdmApp
 *
 * Main application class for the UDM interpreter.
 */
class CUdmApp
{

public:
  static int Initialize();
  static void UdmMain(Udm::DataNetwork* p_backend,
                      Udm::Object currentObject,
                      set <Udm::Object> selectedObjects,
                      long param);

  static void SetParameter (const std::string & name,
                            const std::string & value);

#ifdef _DEBUG
  static string ExtractName(Udm::Object ob);
#endif

private:
  /**
   * Generate the deployment plan for the specified object. If
   * the object is not a PICML::DeploymentPlan object, then
   * it will be ignored.
   *
   * @param[in]         obj           Target object.
   * @param[in]         visitor       Deployment plan visitor.
   */
  static void generate_deployment_plan (const Udm::Object & obj,
                                        PICML::Visitor & visitor);

  /// Output path for the deployment plan files.
  static std::string output_path_;

  static bool interactive_;
};

#endif // !defined(AFX_UDMAPP_H__296A93EB_6DB6_4179_AA0B_A3D799FB3A1C__INCLUDED_)
