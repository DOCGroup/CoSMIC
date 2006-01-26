//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON2Component.h
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

#include "BON.h"
#include "BONImpl.h"
#include <ComponentConfig.h>

namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Component
//
//###############################################################################################################################################

class Component
{
public :
  /// Project running the interpreter.
	Project 	m_project;

  /// Flag containing the iterative mode.
	bool		m_bIsInteractive;

  /// Constructor.
	Component (void);
	
  /// Destructor.
  ~Component (void);

	void initialize (Project & project);
	void finalize (Project & project);
	void invoke (Project& project, const std::set <FCO> & setModels, long lParam);
	void invokeEx (Project& project, FCO &currentFCO, const std::set<FCO> &setSelectedFCOs, long lParam );
	void objectInvokeEx (Project& project, Object & currentObject, const std::set<Object>& setSelectedObjects, long lParam );
	Util::Variant getParameter (const std::string & strName);
	void setParameter (const std::string& strName, const Util::Variant& varValue);

private:
  /// Initialize the event manager for the project.
  void initialize_event_manager (Project & project);

  /// Generate the event info header file.
  void generate_event_info_header (const Project & project, const std::string & outdir);
};

}; // namespace BON

#endif // Bon2Component_H