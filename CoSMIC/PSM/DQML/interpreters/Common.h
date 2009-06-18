//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	Common.h
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

#ifndef Common_h
#define Common_h

#include <set>
#include <string>

namespace MON
{

//###############################################################################################################################################
//
//	E N U M E R A T I O N : MON::ObjectType
//
//###############################################################################################################################################

	enum ObjectType
	{
		OT_Null = 0,
		OT_Model = 1,
		OT_Atom = 2,
		OT_Reference = 3,
		OT_Connection = 4,
		OT_Set = 5,
		OT_Folder = 6,
		OT_Aspect,
		OT_Role,
		OT_Attribute,
		OT_Part
	};

//###############################################################################################################################################
//
//	E N U M E R A T I O N : MON::AttributeType
//
//###############################################################################################################################################

	enum AttributeType
	{
		AT_String = 1,
		AT_Integer = 2,
		AT_Real = 3,
		AT_Boolean = 4,
		AT_Enumeration = 6
	};

//###############################################################################################################################################
//
//	E N U M E R A T I O N : MON::ObjectEventType
//
//###############################################################################################################################################

	enum ObjectEventType
	{
		OET_None					= 0x00000000,
		OET_ObjectCreated 		= 0x80000000,
		OET_ObjectDestroyed 	= 0x40000000,
		OET_ObjectMoved		= 0x00000100,
		OET_AttributeChanged 	= 0x00000001,
		OET_RegistryChanged 	= 0x00000002,
		OET_RelationChanged 	= 0x00000008,
		OET_PropertyChanged	= 0x00000010,
		OET_ChildAdded			= 0x00000004,
		OET_ChildLost				= 0x00000200,
		OET_ObjectReferenced	= 0x00000400,
		OET_ObjectReleased		= 0x00002000,
		OET_ObjectIncluded		= 0x00001000,
		OET_ObjectExcluded		= 0x00008000,
		OET_ObjectConnected	= 0x00000800,
		OET_ObjectDisconnected	= 0x00004000,
		OET_DescendantCreated	= 0x00000020,
		OET_ModelClosed			= 0x00800000,
		OET_All					= 0xFFFFFFFF
	};

	typedef unsigned long ObjectEventTypes;

//###############################################################################################################################################
//
//	E N U M E R A T I O N : MON::ConstraintDepth
//
//###############################################################################################################################################

	enum ConstraintDepth
	{
		CD_Zero,
		CD_One,
		CD_Any
	};

//###############################################################################################################################################
//
//	E N U M E R A T I O N : MON::ConstraintPriority
//
//###############################################################################################################################################

	typedef unsigned short ConstraintPriority;

}; // namespace MON

	MON::ObjectEventType& operator ++( MON::ObjectEventType& eType, int );
	MON::ObjectEventType& operator ++( MON::ObjectEventType& eType );
	bool isAll( const std::set<MON::ObjectEventType>&  setEvents );
	bool isNone( const std::set<MON::ObjectEventType>&  setEvents );
	std::string toString( const MON::ObjectEventType& eType );
	MON::ObjectEventTypes copy( const std::set<MON::ObjectEventType>& setEvents );
	std::set<MON::ObjectEventType> copy( MON::ObjectEventTypes ulEvents );

	std::string toString( MON::ObjectType eType, bool bWithNameSpace = true );

namespace BON
{

//###############################################################################################################################################
//
//	E N U M E R A T I O N : BON::ObjectStatus
//
//###############################################################################################################################################

	enum ObjectStatus
	{
		OST_Exists = 0,
		OST_Deleted,
		OST_Zombie,
		OST_Null
	};

//###############################################################################################################################################
//
//	E N U M E R A T I O N : BON::ObjectType
//
//###############################################################################################################################################

	enum ObjectType
	{
		OT_Null = 0,
		OT_Model = 1,
		OT_Atom = 2,
		OT_Reference = 3,
		OT_Connection = 4,
		OT_Set = 5,
		OT_Folder = 6
	};

//###############################################################################################################################################
//
//	E N U M E R A T I O N : BON::AttributeStatus
//
//###############################################################################################################################################

	typedef long AttributeStatus;

	const long AS_Here = 0;
	const long AS_Meta = -1;
	const long AS_Undefined= -2;

//###############################################################################################################################################
//
//	E N U M E R A T I O N : BON::RegistryNodeStatus
//
//###############################################################################################################################################

	typedef long RegistryNodeStatus;

	const long RNS_Here = 0;
	const long RNS_Meta = -1;
	const long RNS_Undefined = -2;

//###############################################################################################################################################
//
//	C L A S S : BON::Point
//
//###############################################################################################################################################

	typedef unsigned long ULong;
	typedef std::pair<ULong, ULong> Point;

//###############################################################################################################################################
//
//	E N U M E R A T I O N : BON::NamePosition
//
//###############################################################################################################################################

	enum NamePosition
	{
		NP_North = 0,
		NP_NorthEast,
		NP_East,
		NP_SouthEast,
		NP_South,
		NP_SouthWest,
		NP_West,
		NP_NorthWest,
		NP_Center
	};

//###############################################################################################################################################
//
//	E N U M E R A T I O N : BON::AutoRouterPref
//
//###############################################################################################################################################

	enum AutoRouterPref
	{
		ARP_North,
		ARP_South,
		ARP_West,
		ARP_East
	};

//###############################################################################################################################################
//
//	E N U M E R A T I O N : BON::LineType
//
//###############################################################################################################################################

	enum LineType
	{
		LT_Solid,
		LT_Dash
	};

//###############################################################################################################################################
//
//	E N U M E R A T I O N : BON::LineEndType
//
//###############################################################################################################################################

	enum LineEndType
	{
		LET_Butt,
		LET_Arrow,
		LET_Diamond,
		LET_Apex,
		LET_Bullet,
		LET_EmptyDiamond,
		LET_EmptyApex,
		LET_EmptyBullet
	};

}; // namespace BON

	std::string toString( BON::ObjectType eType, bool bWithNameSpace = true );

#endif // Common_h