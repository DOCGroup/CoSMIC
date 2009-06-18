//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	Extensions.cpp
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

#pragma warning ( disable : 4503 )

#include "stdafx.h"
#include "Extensions.h"
#include "BONImpl.h"

namespace BON
{
	void splitKinds( const std::string& strKinds, std::vector<std::string>& vecKinds )
	{
		CString str( strKinds.c_str() );
		str.TrimLeft();
		str.TrimRight();
		if ( str.IsEmpty() )
			vecKinds.push_back( "gme::Object" );
		else {
			while ( true ) {
				int iPos = str.Find( ' ' );
				if ( iPos == -1 ) {
					vecKinds.push_back( str.GetBuffer( str.GetLength() ) );
					str.ReleaseBuffer();
					break;
				}
				CString str2 = str.Left( iPos );
				vecKinds.push_back( str2.GetBuffer( str2.GetLength() ) );
				str2.ReleaseBuffer();
				str = str.Right( str.GetLength() - iPos );
				str.TrimLeft();
				if ( str.IsEmpty() )
					break;
			}
		}
	}

	bool isMetaKindMatched( const std::string& strUserKind, const std::string& strBaseType )
	{
		if ( strBaseType == FCO::string_type && ( strUserKind == Atom::string_type || strUserKind == Model::string_type ||
			strUserKind == Reference::string_type || strUserKind == Set::string_type || strUserKind== Connection::string_type ) )
			return true;
		return strUserKind == strBaseType;
	}

	ObjectImpl* castObjectImpl( ObjectImpl* pObject, const std::string& strBEType, ObjectType eType, const std::vector<std::string>& vecKinds, const std::vector<std::string>& vecDerivedKinds )
	{
		if ( ! pObject )
			return NULL;
		if ( strBEType.empty() )
		{
			Util::Exception exc( "Invalid BON Extension Class! Check meta-kind compatibility for ?!");
			exc << pObject->getObjectMeta().name().c_str();
			ASSERTTHROW( exc);
		}
		if ( eType == OT_Null && pObject->getStereotype() == OT_Folder || eType != OT_Null && pObject->getStereotype() != eType )
			return NULL;

		std::string strKind = pObject->getObjectMeta().name();
		std::string strRole;
		if ( eType != OT_Folder ) {
			MON::Containment role = ( (FCOImpl*) pObject )->getRole();
			if ( role )
				strRole = role.name();
		}

		int i;
		for ( i = 0 ; i < vecKinds.size() ; i++ ) {
			if ( isMetaKindMatched( vecKinds[ i ], strBEType ) || vecKinds[ i ] == strKind || ! strRole.empty() && vecKinds[ i ] == strRole )
				return pObject;
		}
		for ( i = 0 ; i < vecDerivedKinds.size() ; i++ ) {
			if ( isMetaKindMatched( vecDerivedKinds[ i ], strBEType ) || vecDerivedKinds[ i ] == strKind || ! strRole.empty() && vecDerivedKinds[ i ] == strRole )
				return pObject;
		}
		return NULL;
	}

	ExtensionType castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole, const std::string& strBEType, ObjectType eType, const std::vector<std::string>& vecKinds )
	{
		if ( strBEType.empty() )
		{
			Util::Exception exc( "Invalid BON Extension Class! Check meta-kind compatibility for ?!");//, "s", 
			exc << strKind.c_str();
			ASSERTTHROW( exc);
		}
		ExtensionType exType = ET_None;
		if ( eType != OT_Null && eOType != eType || eType == OT_Null && eOType == OT_Folder )
			return exType;
		for ( int i = 0 ; i < vecKinds.size() ; i++ ) {
			 if ( ! strRole.empty() && vecKinds[ i ] == strRole ) {
			 	return ET_Role;
			 }
			 else if ( vecKinds[ i ] == strKind ) {
				if ( exType <= ET_MetaKind )
					exType = ET_Kind;
			}
			else if ( isMetaKindMatched( vecKinds[ i ], strBEType )  ) {
				if ( exType == ET_None )
					exType = ET_MetaKind;
			}
		}
		return exType;
	}

	void mergeTypes( const std::string& strType1, ObjectType eType1, const std::string& strType2, ObjectType eType2, std::string& strType, ObjectType& eType )
	{
		if ( strType1.empty() || strType2.empty() ) {
			strType = "";
			eType = OT_Null;
			return;
		}

		if ( eType2 == OT_Null ) {
			if (eType1 == OT_Null) {
				strType = strType2;
				eType = OT_Null;
				return;
			}
			mergeTypes( strType2, eType2, strType1, eType1, strType, eType );
			return;
		}

		if ( eType1 == OT_Null && eType2 == OT_Folder || eType1 != OT_Null && eType1 != eType2 ) {
			strType = "";
			eType = OT_Null;
			return;
		}

		strType = strType2;
		eType = eType2;
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ExtensionManager
//
//###############################################################################################################################################

	ExtensionManager::FunctionVector vecKindCopy();

	ExtensionManager::FunctionVector ExtensionManager::vecKindFunctions( vecKindCopy() );

	ExtensionManager::FunctionVector vecKindCopy()
	{
		if ( ! ExtensionManager::vecKindFunctions.empty() ) {
			ExtensionManager::FunctionVector vec = ExtensionManager::vecKindFunctions;
			return vec;
		}
		return ExtensionManager::FunctionVector();
	}

	ExtensionManager::ExtensionManager( const std::vector<std::string>& vecKinds, CastFunction pFnCast, CreateFunction pFnCreate )
	{
		// Removed by PETER 
		// for ( int i = 0 ; i < vecKinds.size() ; i++ ) {
			ExtensionManager::vecKindFunctions.push_back( FunctionPair( pFnCast, pFnCreate ) );
		// }
	}

	ObjectImpl* ExtensionManager::createImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
	{
		ExtensionType eType = ET_None;
		int iLevel = 0;
		int iCnt = 0;
		int iFuncNum = 0;
		for ( int i = 0 ; i < ExtensionManager::vecKindFunctions.size() ; i++ ) {
			ExtensionInfo eInfo = (*vecKindFunctions[ i ].first)( eOType, strKind, strRole );
			int iDo = 0; // 0 - Do Nothing, 1 - Type Change, 2 - Type Equal
			switch ( eInfo.first ) {
				case ET_Role : {
					if ( eType != ET_Role )
						iDo = 1;
					else
						iDo = 2;
					break;
				}
				case ET_Kind : {
					if ( eType < ET_Kind )
						iDo = 1;
					else
						if ( eType == ET_Kind )
							iDo = 2;
					break;
				}
				case ET_MetaKind : {
					if ( eType < ET_MetaKind )
						iDo = 1;
					else
						if ( eType == ET_MetaKind )
							iDo = 2;
					break;
				}
			}
			if ( iDo == 1 )
				eType = eInfo.first;
			if ( iDo > 0 ) {
				if ( iDo == 1 || iLevel < eInfo.second ) {
					iFuncNum = i;
					iCnt = 1;
					iLevel = eInfo.second;
				}
				else
					if ( iDo == 2 && iLevel == eInfo.second )
						iCnt++;
			}
		}


		if ( eType != ET_None ) {
			if ( iCnt != 1 ) {
				switch ( eType ) {
					case ET_Role : {
						Util::Exception exc( "Implementations are ambiguous for Role [?]!");//, "s", 
						exc << strRole.c_str();
						ASSERTTHROW( exc);
						break;
					}
					case ET_Kind : {
						Util::Exception exc( "Implementations are ambiguous for Kind [?]!");// "s", 
						exc << strKind.c_str();
						ASSERTTHROW( exc);
						break;
					}
					case ET_MetaKind : {
						Util::Exception exc( "Implementations are ambiguous for MetaKind [?]!");//, "s", 
						exc << toString( eOType ).c_str();
						ASSERTTHROW( exc );
						break;
					}
				}
			}
			return (*vecKindFunctions[ iFuncNum ].second)();
		}
		return NULL;
	}

}; // namespace BON 