// -*- C++ -*-

//=============================================================================
/**
 * @file        ComponentDLL.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_COMPONENT_DLL_H_
#define _GME_COMPONENT_DLL_H_

namespace GME
{
  /**
   * @class ComponentDLL
   *
   * Base class for all GME component modules
   */
  class ComponentDLL : public CWinApp
  {
  public:
    /**
     * Initializing constructor
     *
     * @param[in]       name        Name of the application/module
     */
    ComponentDLL (const char * name);

    /// Destructor
    virtual ~ComponentDLL (void);

    /// Initialize the module/appication.
    virtual BOOL InitInstance (void);

    /// Exit the module/application.
    virtual int ExitInstance (void);

    /// Declare the message map for the application.
    DECLARE_MESSAGE_MAP ()
  };
}

/**
 * Macro for declaring a GME component. This should appear in the
 * source file for all GME components so the framework can properly
 * initialize itself.
 */
#define GME_COMPONENT_DECLARE(T, NAME, LIBID) \
  class T##ComponentDLL : public GME::ComponentDLL \
  { \
  public: \
    T##ComponentDLL (void) \
    : GME::ComponentDLL (NAME) { } \
    virtual ~T##ComponentDLL (void) { } \
  }; \
  class T##Module : public ATL::CAtlDllModuleT < T##Module > \
  { \
  public: \
    DECLARE_LIBID (LIBID) \
  }; \
  T##Module _AtlModule; \
  STDAPI DllCanUnloadNow (void) \
  { \
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ()); \
    return (::AfxDllCanUnloadNow () == S_OK && _AtlModule.GetLockCount () == 0) ? S_OK : S_FALSE; \
  } \
  STDAPI DllRegisterServer (void) \
  { \
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ()); \
    return _AtlModule.DllRegisterServer (); \
  } \
  STDAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, void ** ppv) \
  { \
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ()); \
    return _AtlModule.DllGetClassObject (rclsid, riid, ppv); \
  } \
  STDAPI DllUnregisterServer (void) \
  { \
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ()); \
    return _AtlModule.DllUnregisterServer (); \
  } \
  static T##ComponentDLL theApp

#endif  // !defined _GME_COMPONENT_DLL_H_
