//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	Common.cpp
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

#pragma warning( disable : 4786 )

#include "stdafx.h"
#include "Common.h"

//###############################################################################################################################################
//
//	E N U M E R A T I O N : MON::ObjectEventType
//
//###############################################################################################################################################

	MON::ObjectEventType& operator ++ ( MON::ObjectEventType& eType, int )
	{
		switch ( eType ) {
			case MON::OET_None 					: return eType = MON::OET_ObjectCreated;
			case MON::OET_ObjectCreated			: return eType = MON::OET_ObjectDestroyed;
			case MON::OET_ObjectDestroyed	  	: return eType = MON::OET_ObjectMoved;
			case MON::OET_ObjectMoved			: return eType = MON::OET_AttributeChanged;
			case MON::OET_AttributeChanged 		: return eType = MON::OET_RegistryChanged;
			case MON::OET_RegistryChanged 		: return eType = MON::OET_RelationChanged;
			case MON::OET_RelationChanged 		: return eType = MON::OET_PropertyChanged;
			case MON::OET_PropertyChanged		: return eType = MON::OET_ChildAdded;
			case MON::OET_ChildAdded				: return eType = MON::OET_ChildLost;
			case MON::OET_ChildLost					: return eType = MON::OET_ObjectReferenced;
			case MON::OET_ObjectReferenced		: return eType = MON::OET_ObjectReleased;
			case MON::OET_ObjectReleased			: return eType = MON::OET_ObjectIncluded;
			case MON::OET_ObjectIncluded			: return eType = MON::OET_ObjectExcluded;
			case MON::OET_ObjectExcluded			: return eType = MON::OET_ObjectConnected;
			case MON::OET_ObjectConnected		: return eType = MON::OET_ObjectDisconnected;
			case MON::OET_ObjectDisconnected		: return eType = MON::OET_DescendantCreated;
			case MON::OET_DescendantCreated		: return eType = MON::OET_ModelClosed;
			case MON::OET_ModelClosed				: return eType = MON::OET_All;
			case MON::OET_All						: return eType = MON::OET_None;
		}
		return eType = MON::OET_None;
	}

	MON::ObjectEventType& operator ++ ( MON::ObjectEventType& eType )
	{
		return eType++;
	}

	bool isAll( const std::set<MON::ObjectEventType>&  setEvents )
	{
		if ( setEvents.find( MON::OET_All ) != setEvents.end() )
			return true;

		for ( MON::ObjectEventType eType = MON::OET_ObjectCreated; eType != MON::OET_All ; eType++ )
			if ( setEvents.find( eType ) == setEvents.end() )
				return false;
		return true;
	}

	bool isNone( const std::set<MON::ObjectEventType>&  setEvents )
	{
		if ( setEvents.find( MON::OET_None ) != setEvents.end() )
			return true;

		for ( MON::ObjectEventType eType = MON::OET_None ; eType != MON::OET_All ; eType++ )
			if ( setEvents.find( eType ) != setEvents.end() )
				return false;
		return true;
	}

	std::string toString( const MON::ObjectEventType& eType )
	{
		switch ( eType ) {
			case MON::OET_None 					: return "None";
			case MON::OET_ObjectCreated			: return "ObjectCreated";
			case MON::OET_ObjectDestroyed	  	: return "ObjectDestroyed";
			case MON::OET_ObjectMoved			: return "ObjectMoved";
			case MON::OET_AttributeChanged 		: return "AttributeChanged";
			case MON::OET_RegistryChanged 		: return "RegistryChanged";
			case MON::OET_RelationChanged 		: return "RelationChanged";
			case MON::OET_PropertyChanged		: return "PropertyChanged";
			case MON::OET_ChildAdded				: return "ChildAdded";
			case MON::OET_ChildLost					: return "ChildLost";
			case MON::OET_ObjectReferenced		: return "ObjectReferenced";
			case MON::OET_ObjectReleased			: return "ObjectReleased";
			case MON::OET_ObjectIncluded			: return "ObjectIncluded";
			case MON::OET_ObjectExcluded			: return "ObjectExcluded";
			case MON::OET_ObjectConnected		: return "ObjectConnected";
			case MON::OET_ObjectDisconnected		: return "ObjectDisconnected";
			case MON::OET_DescendantCreated		: return "DescendantCreated";
			case MON::OET_ModelClosed				: return "ModelClosed";
			case MON::OET_All						: return "All";
		}
		return "None";
	}

	MON::ObjectEventTypes copy( const std::set<MON::ObjectEventType>& setEvents )
	{
		MON::ObjectEventTypes ulEvents = 0;
		for ( MON::ObjectEventType eType = MON::OET_None ; eType != MON::OET_All ; eType++ )
			if ( setEvents.find( eType ) != setEvents.end() )
				ulEvents |= eType;
		return ulEvents;
	}

	std::set<MON::ObjectEventType> copy( MON::ObjectEventTypes ulEvents )
	{
		std::set<MON::ObjectEventType> setEvents;
		for ( MON::ObjectEventType eType = MON::OET_None ; eType != MON::OET_All ; eType++ )
			if ( ulEvents & eType )
				setEvents.insert( eType );
		return setEvents;
	}

	std::string toString( MON::ObjectType eType, bool bWithNameSpace )
	{
		std::string str;
		switch ( eType ) {
			case MON::OT_Model : str = "Model"; break;
			case MON::OT_Atom : str = "Atom"; break;
			case MON::OT_Reference : str = "Reference"; break;
			case MON::OT_Connection : str = "Connection"; break;
			case MON::OT_Set : str = "Set"; break;
			case MON::OT_Folder : str = "Folder"; break;
			case MON::OT_Aspect : str = "Aspect"; break;
			case MON::OT_Role : str = "Containment"; break;
			case MON::OT_Attribute : str = "Attribute"; break;
			case MON::OT_Part : str = "ContainmentPart"; break;
			default : return "Null";
		}
		return ( bWithNameSpace ) ? "MON::" + str : str;
	}

	std::string toString( BON::ObjectType eType, bool bWithNameSpace )
	{
		std::string str;
		switch ( eType ) {
			case BON::OT_Model : str = "Model"; break;
			case BON::OT_Atom : str = "Atom"; break;
			case BON::OT_Reference : str = "Reference"; break;
			case BON::OT_Connection : str = "Connection"; break;
			case BON::OT_Set : str = "Set"; break;
			case BON::OT_Folder : str = "Folder"; break;
			default : return "Null";
		}
		return ( bWithNameSpace ) ? "BON::" + str : str;
	}