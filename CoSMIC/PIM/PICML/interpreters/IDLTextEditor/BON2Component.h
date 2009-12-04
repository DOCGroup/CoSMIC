//###############################################################################################################################################
//
//  Meta and Builder Object Network V2.0 for GME
//  BON2Component.h
//
//###############################################################################################################################################

/*
  Copyright (c) Vanderbilt University, 2000-2004
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

#ifndef BON2Component_h
#define BON2Component_h

#include "IDMLBonExtension.h"

// Forward decl.
class DSL_DocTemplate;

namespace BON
{
/**
 * @class Component
 */
class Component
{
public:
  /// Default constructor.
  Component (void);

  /// Destructor.
  ~Component (void);

  void initialize (Project& project);

  void finalize (Project& project);

  void invoke (Project& project, const std::set<FCO>& setModels, long lParam);

  void invokeEx (Project& project, FCO& currentFCO, const std::set<FCO>& setSelectedFCOs, long lParam);

  void objectInvokeEx (Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam);

  Util::Variant getParameter (const std::string& strName);

  void setParameter (const std::string& strName, const Util::Variant& varValue);

  Project   m_project;

  bool    m_bIsInteractive;

private:
  /// Helper method for processing the IDML::File.
  void processFile (const IDML::File & file);

  /// Editor for the component.
  std::auto_ptr <DSL_DocTemplate> template_;
};

}; // namespace BON

#endif // Bon2Component_H
