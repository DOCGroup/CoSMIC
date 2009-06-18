//###############################################################################################################################################
//
//	Builder and Meta Object Network V2.0 for GME
//	Exceptions.cpp
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
#include "Exceptions.h"

#include "stdarg.h"


#define ADDPARAMETERS() \
		va_list vList;																			\
		va_start( vList, strFormat );															\
		for ( int i = 0 ; i < strFormat.size() ; i++ ) {											\
			switch( strFormat[ i ] ) {															\
				case Exception::PM_CHAR : {													\
					addParameter( "" + va_arg( vList, char ) );				\
					break;																		\
				}																				\
				case Exception::PM_STRING : {												\
					addParameter( std::string( va_arg( vList, char* ) ) );	\
					break;																		\
				}																				\
				case Exception::PM_INTEGER : {												\
					char chBuffer[ 100 ];														\
					sprintf( chBuffer, "%d", va_arg( vList, int ) );							\
					addParameter( std::string( chBuffer ) );					\
					break;																		\
				}																				\
				case Exception::PM_LONG : {													\
					char chBuffer[ 100 ];														\
					sprintf( chBuffer, "%d", va_arg( vList, long ) );							\
					addParameter( std::string( chBuffer ) );					\
					break;																		\
				}																				\
				case Exception::PM_FLOAT : {												\
					char chBuffer[ 100 ];														\
					sprintf( chBuffer, "%f", va_arg( vList, float ) );							\
					addParameter( std::string( chBuffer ) );					\
					break;																		\
				}																				\
				case Exception::PM_DOUBLE : {												\
					char chBuffer[ 100 ];														\
					sprintf( chBuffer, "%f", va_arg( vList, double ) );						\
					addParameter( std::string( chBuffer ) );					\
					break;																		\
				}																				\
				default : {																		\
					addParameter( "..." );										\
				}																				\
			}																					\
		}																						\
		va_end( vList );																		\


namespace Util
{
	Exception& Exception::operator << ( char pch)
	{
		addParameter( "" + pch);
		return *this;
	}

	Exception& Exception::operator << ( int  pint)
	{
		char chBuffer[ 100 ];
		sprintf( chBuffer, "%d", pint);
		addParameter( std::string( chBuffer ) );
		return *this;
	}

	Exception& Exception::operator << ( long plong)
	{
		char chBuffer[ 100 ];
		sprintf( chBuffer, "%d", plong);
		addParameter( std::string( chBuffer ) );
		return *this;
	}

	Exception& Exception::operator << ( const std::string& pstr)
	{
		addParameter( pstr );
		return *this;
	}

	Exception& Exception::operator << ( float pfloat)
	{
		char chBuffer[ 100 ];
		sprintf( chBuffer, "%f", pfloat );
		addParameter( std::string( chBuffer ) );
		return *this;
	}

	Exception& Exception::operator << ( double pdoub)
	{
		char chBuffer[ 100 ];
		sprintf( chBuffer, "%f", pdoub );
		addParameter( std::string( chBuffer ) );
		return *this;
	}

//###############################################################################################################################################
//
// 	C L A S S : Util::Exception
//
//###############################################################################################################################################

	const char Exception::PM_CHAR = 'c';
	const char Exception::PM_STRING = 's';
	const char Exception::PM_INTEGER = 'i';
	const char Exception::PM_LONG = 'l';
	const char Exception::PM_FLOAT = 'f';
	const char Exception::PM_DOUBLE = 'd';

	Exception::Exception()
	{
	}

	//Exception::Exception( std::string strMessage)//, std::string strFormat, ... )
	//	: m_strMessage( strMessage )
	//{
	//	//ADDPARAMETERS();
	//}

	Exception::Exception( std::string strMessage, const StringVector& vecParameters )
		: m_strMessage( strMessage ), m_vecParameters( vecParameters )
	{
	}

	Exception::Exception( const Exception& ex )
		: m_strMessage( ex.m_strMessage ), m_vecParameters( ex.m_vecParameters )
	{
	}

	std::string Exception::getErrorMessage( bool bSubstitute ) const
	{
		if ( ! bSubstitute )
			return m_strMessage;
		else {
			std::string strMessage = m_strMessage;
			int iCnt = 0;
			int iPos = m_strMessage.find( '?' );
			while ( iPos != std::string::npos && iCnt < m_vecParameters.size() ) {
				strMessage = strMessage.substr( 0, iPos ) + m_vecParameters[ iCnt++ ] + strMessage.substr( iPos + 1, strMessage.length() - iPos - 1 );
				iPos = strMessage.find( '?' );
			}
			return strMessage;
		}
	}

	std::string	Exception::getParameter( int iPos ) const
	{
		return ( iPos < 0 || iPos >= m_vecParameters.size() ) ? "" : m_vecParameters[ iPos ];
	}

	int Exception::getParameterCount() const
	{
		return m_vecParameters.size();
	}

	void Exception::addParameter( const std::string& strParameter )
	{
		m_vecParameters.push_back( strParameter );
	}

	std::string Exception::getKind() const
	{
		return "Util::Exception";
	}

}; // namespace Util

namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Exception
//
//###############################################################################################################################################

	Exception::Exception( HRESULT hResult )
		: Util::Exception(), m_hResult( hResult )
	{
	}

	//Exception::Exception( HRESULT hResult, std::string strMessage, std::string strFormat, ... )
	//	: Util::Exception( strMessage ), m_hResult( hResult )
	//{
	//	ADDPARAMETERS();
	//}

	Exception::Exception( HRESULT hResult, std::string strMessage, const StringVector& vecParameters )
		: Util::Exception( strMessage, vecParameters ), m_hResult( hResult )
	{
	}

	//Exception::Exception( std::string strMessage, std::string strFormat, ... )
	//	: Util::Exception( strMessage ), m_hResult( -1 )
	//{
	//	ADDPARAMETERS();
	//}

	Exception::Exception( std::string strMessage, const StringVector& vecParameters )
		: Util::Exception( strMessage, vecParameters ), m_hResult( -1 )
	{
	}

	Exception::Exception( const Exception& ex )
		: Util::Exception( ex ), m_hResult( ex.m_hResult )
	{
	}

	HRESULT Exception::getHResult() const
	{
		return m_hResult;
	}

	std::string Exception::getKind() const
	{
		return "BON::Exception";
	}

}; // namespace BON
 
namespace MON
{

//###############################################################################################################################################
//
// 	C L A S S : MON::Exception
//
//###############################################################################################################################################

	Exception::Exception( HRESULT hResult )
		: Util::Exception(), m_hResult( hResult )
	{
	}

	//Exception::Exception( HRESULT hResult, std::string strMessage, std::string strFormat, ... )
	//	: Util::Exception( strMessage ), m_hResult( hResult )
	//{
	//	ADDPARAMETERS();
	//}

	Exception::Exception( HRESULT hResult, std::string strMessage, const StringVector& vecParameters )
		: Util::Exception( strMessage, vecParameters ), m_hResult( hResult )
	{
	}

	//Exception::Exception( std::string strMessage, std::string strFormat, ... )
	//	: Util::Exception( strMessage ), m_hResult( -1 )
	//{
	//	ADDPARAMETERS();
	//}

	Exception::Exception( std::string strMessage, const StringVector& vecParameters )
		: Util::Exception( strMessage, vecParameters ), m_hResult( -1 )
	{
	}

	Exception::Exception( const Exception& ex )
		: Util::Exception( ex ), m_hResult( ex.m_hResult )
	{
	}

	HRESULT Exception::getHResult() const
	{
		return m_hResult;
	}

	std::string Exception::getKind() const
	{
		return "MON::Exception";
	}

}; // namespace MON