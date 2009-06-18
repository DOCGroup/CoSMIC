//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	Utils.cpp
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
#include "Utils.h"

namespace Util
{

//###############################################################################################################################################
//
// 	F U N C T I O N S
//
//###############################################################################################################################################

	CComBSTR	Copy( const std::string& str )
	{
		return ( str.empty() ) ? CComBSTR() : CComBSTR( str.c_str() );
	}

	std::string	Copy( const CComBSTR& bstr )
	{
		CString str( bstr );
		std::string strResult( str.GetBuffer( str.GetLength() ) );
		str.ReleaseBuffer();
		return strResult;
	}

//###############################################################################################################################################
//
// 	C L A S S :  Util::Variant
//
//###############################################################################################################################################

	Variant::Variant()
		: m_bUndefined( true ), m_eType( Variant::VT_Boolean )
	{
	}

	Variant::Variant( bool bValue )
		: m_bUndefined( false ), m_eType( Variant::VT_Boolean )
	{
		m_uValue.bVal = bValue;
	}

	Variant::Variant( long lValue )
		: m_bUndefined( false ), m_eType( Variant::VT_Integer )
	{
		m_uValue.lVal = lValue;
	}

	Variant::Variant( double dValue )
		: m_bUndefined( false ), m_eType( Variant::VT_Double )
	{
		m_uValue.dVal = dValue;
	}

	Variant::Variant( const std::string& strValue )
		: m_bUndefined( false ), m_eType( Variant::VT_String )
	{
		m_uValue.pstrVal = new std::string( strValue );
	}

	Variant::Variant( const Variant& vValue )
		: m_bUndefined( vValue.m_bUndefined ), m_eType( vValue.m_eType )
	{
		if ( ! m_bUndefined ) {
			m_uValue = vValue.m_uValue;
			if ( m_eType == Variant::VT_String )
				m_uValue.pstrVal = new std::string( *m_uValue.pstrVal );
		}
	}

	Variant::~Variant()
	{
		if ( ! m_bUndefined && m_eType == Variant::VT_String )
			delete m_uValue.pstrVal;
	}

	Variant::Type Variant::type() const
	{
		return m_eType;
	}

	bool Variant::isUndefined() const
	{
		return m_bUndefined;
	}

	Variant& Variant::operator=( const Variant& vValue )
	{
		if ( this != &vValue ) {
			if ( ! m_bUndefined && m_eType == Variant::VT_String )
				delete m_uValue.pstrVal;
			m_eType = vValue.m_eType;
			m_bUndefined = vValue.m_bUndefined;
			m_uValue = vValue.m_uValue;
			if ( m_eType == Variant::VT_String )
				m_uValue.pstrVal = new std::string( *m_uValue.pstrVal );
		}
		return *this;
	}

	Variant::operator bool () const
	{
		if ( m_bUndefined )
			return false;
		switch ( m_eType ) {
			case Variant::VT_Boolean :
				return m_uValue.bVal;
			case Variant::VT_String :
				return ! m_uValue.pstrVal->empty();
			case Variant::VT_Integer :
				return m_uValue.lVal != 0;
			default :
				return m_uValue.dVal != 0.0;
		}
	}

	Variant::operator long () const
	{
		if ( m_bUndefined )
			return 0;
		switch ( m_eType ) {
			case Variant::VT_Boolean :
				return ( m_uValue.bVal ) ? 1 : 0;
			case Variant::VT_String :
				return atol( m_uValue.pstrVal->c_str() );
			case Variant::VT_Integer :
				return m_uValue.lVal;
			default :
				return (long) m_uValue.dVal;
		}
	}

	Variant::operator double () const
	{
		if ( m_bUndefined )
			return 0.0;
		switch ( m_eType ) {
			case Variant::VT_Boolean :
				return ( m_uValue.bVal ) ? 1.0 : 0.0;
			case Variant::VT_String :
				return atof( m_uValue.pstrVal->c_str() );
			case Variant::VT_Integer :
				return (double) m_uValue.lVal;
			default :
				return m_uValue.dVal;
		}
	}

	Variant::operator std::string () const
	{
		if ( m_bUndefined )
			return "";
		switch ( m_eType ) {
			case Variant::VT_Boolean :
				return ( m_uValue.bVal ) ? "true" : "false";
			case Variant::VT_String :
				return *m_uValue.pstrVal;
			case Variant::VT_Integer : {
				char chBuffer[ 100 ];
				sprintf( chBuffer, "%d", m_uValue.lVal );
				return chBuffer;
			}
			default : {
				char chBuffer[ 100 ];
				sprintf( chBuffer, "%f", m_uValue.dVal );
				return chBuffer;
			}
		}
	}

}; // namespace Util

//###############################################################################################################################################
//
//	E N U M E R A T I O N : Util::InfoOption
//
//###############################################################################################################################################

	Util::InfoOption& operator ++ ( Util::InfoOption& eOption, int )
	{
		switch ( eOption ) {
			case Util::IO_None :			eOption = Util::IO_Identifiers; break;
			case Util::IO_Identifiers :   	eOption = Util::IO_ID; break;
			case Util::IO_ID :            		eOption = Util::IO_Meta; break;
			case Util::IO_Meta :          	eOption = Util::IO_Path; break;
			case Util::IO_Path :          		eOption = Util::IO_Specific; break;
			case Util::IO_Specific :      	eOption = Util::IO_NewLine; break;
			case Util::IO_NewLine :  		eOption = Util::IO_All; break;
			case Util::IO_All :            		eOption = Util::IO_None; break;
		}
		return eOption= Util::IO_None;
	}

	Util::InfoOption& operator ++ ( Util::InfoOption& eOption )
	{
		return eOption++;
	}

	bool isAll( const std::set<Util::InfoOption>&  setOptions )
	{
		if ( setOptions.find( Util::IO_All ) != setOptions.end() )
			return true;

		for ( Util::InfoOption eOption = Util::IO_Identifiers; eOption != Util::IO_All ; eOption++ )
			if ( setOptions.find( eOption ) == setOptions.end() )
				return false;
		return true;
	}

	bool isNone( const std::set<Util::InfoOption>&  setOptions )
	{
		if ( setOptions.find( Util::IO_All ) != setOptions.end() )
			return true;

		for ( Util::InfoOption eOption = Util::IO_Identifiers; eOption != Util::IO_All ; eOption++ )
			if ( setOptions.find( eOption ) != setOptions.end() )
				return false;
		return true;
	}

	unsigned short copy( const std::set<Util::InfoOption>&  setOptions )
	{
		unsigned short usOption = 0;
		for ( Util::InfoOption eOption = Util::IO_Identifiers; eOption != Util::IO_All ; eOption++ )
			if ( setOptions.find( eOption ) != setOptions.end() )
				usOption |= eOption;
		return usOption;
	}

	std::set<Util::InfoOption> copy( unsigned short usOptions )
	{
		std::set<Util::InfoOption> setOptions;
		for ( Util::InfoOption eOption = Util::IO_Identifiers; eOption != Util::IO_All ; eOption++ )
			if ( usOptions & eOption )
				setOptions.insert( eOption );
		return setOptions;
	}
