//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON2Component.cpp
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

#include "stdafx.h"
#include "BON2Component.h"
#include "ECLGenerator.h"
#include "KindAggregator.h"
#include "kindDialog.h"
#include "DeploymentPlanner.h"

#include <list>

namespace  // anonymous
{
	void display (KindDialog & kind_dialog, BON::Project & project)
{
		std::list <std::string> comp_kinds =
				kind_dialog.get_component_kinds ();
		
		std::string comp_sequence ("Components: ");
//		for (std::list <std::string>::const_iterator i (comp_kinds.begin());
//			 i != comp_kinds.end();
//			 ++i)
		{
			CQML::KindAggregator<CQML::AbstractComponent>
				aggregator (project, comp_kinds);
			CQML::KindAggregator<CQML::AbstractComponent>::KindMap
				map = aggregator.aggregate ();
			
			for (CQML::KindAggregator<CQML::AbstractComponent>::KindMap::iterator i = map.begin();
				 i != map.end();
				++i)
			{
				comp_sequence += i->first;
				comp_sequence += " ";
			}
		}
		AfxMessageBox (comp_sequence.c_str());

		std::list <std::string> node_kinds =
				kind_dialog.get_node_kinds ();
		std::string node_sequence ("Nodes: ");
		
  //  for (std::list <std::string>::const_iterator i (node_kinds.begin());
		//	 i != node_kinds.end();
		//	 ++i)
		{
			CQML::KindAggregator<CQML::AbstractNode>
				aggregator (project, node_kinds);
			CQML::KindAggregator<CQML::AbstractNode>::KindMap
				map = aggregator.aggregate ();
			
			for (CQML::KindAggregator<CQML::AbstractNode>::KindMap::iterator i = map.begin();
				 i != map.end();
				++i)
			{	
				node_sequence += i->first;
				node_sequence += " ";
			}
		}
		AfxMessageBox (node_sequence.c_str());
}

} // anonymous namespace

namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Component
//
//###############################################################################################################################################

Component::Component()
	: m_bIsInteractive( false )
{
}

Component::~Component()
{
	if ( m_project ) {
		m_project->finalizeObjects();
		finalize( m_project );
		m_project = NULL;
	}
}

// ====================================================
// This method is called after all the generic initialization is done
// This should be empty unless application-specific initialization is needed

void Component::initialize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This method is called before the whole BON2 project released and disposed
// This should be empty unless application-specific finalization is needed

void Component::finalize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This is the obsolete component interface
// This present implementation either tries to call InvokeEx, or does nothing except of a notification

void Component::invoke( Project& project, const std::set<FCO>& setModels, long lParam )
{
	#ifdef SUPPORT_OLD_INVOKE
		Object focus;
		invokeEx( project, focus, setModels, lParam );
	#else
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support the obsolete invoke mechanism!");
	#endif
}


// ====================================================
// This is the main component method for Interpereters and Plugins.
// May also be used in case of invokeable Add-Ons

void Component::invokeEx( Project& project, FCO& currentFCO, const std::set<FCO>& setSelectedFCOs, long lParam )
{
#ifdef GME_ADDON
	project->setAutoCommit( false);
#endif
	// ======================
	// Insert application specific code here
	try
	{
		KindDialog kind_dialog (::AfxGetMainWnd ());
		if (kind_dialog.DoModal() != IDOK)
			return;
        //display (kind_dialog, project);
		std::list <std::string> comp_kinds =
			kind_dialog.get_component_kinds ();
		CQML::KindAggregator<CQML::AbstractComponent>
			comp_aggr (project, comp_kinds);

		std::list <std::string> node_kinds =
			kind_dialog.get_node_kinds ();
		CQML::KindAggregator<CQML::AbstractNode>
			node_aggr (project, node_kinds);

		DeploymentPlanner planner (comp_aggr.aggregate (), node_aggr.aggregate());

		NodeToCompMapping node2comp;
 	    CompToNodeMapping comp2node;

		planner.get_placement (node2comp, comp2node);
		//ECLGenerator::get_sample_mapping (node2comp, comp2node);

		ECLGenerator generator (project, comp_aggr.aggregate ());
		generator.generate (node2comp, comp2node, kind_dialog.get_planname());
	}
	catch (...)
	{
		std::string ex = "ECLGenerator: An exception was thrown!";
	  AfxMessageBox (ex.c_str());
	  project->consoleMsg (ex.c_str(), MSG_ERROR);	
	}
}

// ====================================================
// GME currently does not use this function
// You only need to implement it if other invokation mechanisms are used

void Component::objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam )
	{
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support objectInvokeEx method!");
	}

// ====================================================
// Implement application specific parameter-mechanism in these functions

Util::Variant Component::getParameter( const std::string& strName )
{
	// ======================
	// Insert application specific code here

	return Util::Variant();
}

void Component::setParameter( const std::string& strName, const Util::Variant& varValue )
{
	// ======================
	// Insert application specific code here
}

#ifdef GME_ADDON

// ====================================================
// If the component is an Add-On, then this method is called for every Global Event

void Component::globalEventPerformed( globalevent_enum event )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// If the component is an Add-On, then this method is called for every Object Event

void Component::objectEventPerformed( Object& object, unsigned long event, VARIANT v )
{
	// ======================
	// Insert application specific code here
}

#endif // GME_ADDON

}; // namespace BON

