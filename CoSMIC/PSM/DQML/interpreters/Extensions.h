//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	Extensions.h
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

#ifndef Extensions_h
#define Extensions_h

#pragma warning ( disable : 4503 )
#pragma warning ( disable : 4250 ) // Dominant Inhertiance Methods

#include "BON.h"
#include <map>

namespace BON
{
	enum ExtensionType { ET_None = 0, ET_MetaKind = 1, ET_Kind = 2, ET_Role = 3 };
	typedef std::pair<ExtensionType,int> ExtensionInfo;

	void				splitKinds( const std::string& strKinds, std::vector<std::string>& vecKinds );

	ObjectImpl* 		castObjectImpl( ObjectImpl* pObject, const std::string& strBEType, ObjectType eType, const std::vector<std::string>& vecKinds, const std::vector<std::string>& vecDerivedKinds );
	ExtensionType 	castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole, const std::string& strBEType, ObjectType eType, const std::vector<std::string>& vecKinds );

	void				mergeTypes( const std::string& strType1, ObjectType eType1, const std::string& strType2, ObjectType eType2, std::string& strType, ObjectType& eType );

	template <class TBON,class TUserI> class Extension;
	template <class TBON1,class TBON2,class TUserI> class Extension2;
	template <class TBON1,class TBON2,class TBON3,class TUserI> class Extension3;
	template <class TBON1,class TBON2,class TBON3,class TBON4,class TUserI> class Extension4;
	template <class TBON1,class TBON2,class TBON3,class TBON4,class TBON5,class TUserI> class Extension5;
	template <class TBON1,class TBON2,class TBON3,class TBON4,class TBON5,class TBON6,class TUserI> class Extension6;

	class ExtensionManager;

	#define DECLARE_BONEXTENSION( TBON, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::Extension<TBON,TUserI> TUser;

	#define DECLARE_BONEXTENSION2( TBON1, TBON2, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::Extension2<TBON1,TBON2,TUserI> TUser;

	#define DECLARE_BONEXTENSION3( TBON1, TBON2, TBON3, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::Extension3<TBON1,TBON2,TBON3,TUserI> TUser;

	#define DECLARE_BONEXTENSION4( TBON1, TBON2, TBON3, TBON4, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::Extension4<TBON1,TBON2,TBON3, TBON4, TUserI> TUser;

	#define DECLARE_BONEXTENSION5( TBON1, TBON2, TBON3, TBON4, TBON5, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::Extension5<TBON1,TBON2,TBON3, TBON4, TBON5, TUserI> TUser;

	#define DECLARE_BONEXTENSION6( TBON1, TBON2, TBON3, TBON4, TBON5, TBON6, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::Extension6<TBON1,TBON2,TBON3, TBON4, TBON5, TBON6, TUserI> TUser;

	#define DECLARE_ABSTRACT_BONEXTENSION( TBON, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::ExtensionA<TBON,TUserI> TUser;

	#define DECLARE_ABSTRACT_BONEXTENSION2( TBON1, TBON2, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::ExtensionA2<TBON1,TBON2,TUserI> TUser;

	#define DECLARE_ABSTRACT_BONEXTENSION3( TBON1, TBON2, TBON3, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::ExtensionA3<TBON1,TBON2,TBON3,TUserI> TUser;

	#define DECLARE_ABSTRACT_BONEXTENSION4( TBON1, TBON2, TBON3, TBON4, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI> TUser;

	#define DECLARE_ABSTRACT_BONEXTENSION5( TBON1, TBON2, TBON3, TBON4, TBON5, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI> TUser;

	#define DECLARE_ABSTRACT_BONEXTENSION6( TBON1, TBON2, TBON3, TBON4, TBON5, TBON6, TUserI, TUser )							\
		class TUserI;																									\
		typedef BON::ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI> TUser;

	#define IMPLEMENT_BONEXTENSIONBASE( TUser, SKinds )																						\
		int TUser::inheritance_level = 0;																											\
		std::string TUser::string_type;																												\
		BON::ObjectType TUser::type = BON::OT_Null;																												\
		std::vector<std::string> TUser::vecKinds = TUser::setKinds( SKinds );																	\
		std::vector<std::string> TUser::vecDerivedKinds;																						\
		const BON::ExtensionManager TUser::extensionFactory = BON::ExtensionManager( TUser::vecKinds, TUser::castImpl, TUser::createImpl );

	#define IMPLEMENT_BONEXTENSION( TUser, SKinds )																						\
		IMPLEMENT_BONEXTENSIONBASE( TUser, SKinds )

	#define IMPLEMENT_ABSTRACT_BONEXTENSION( TUser )																						\
		IMPLEMENT_BONEXTENSIONBASE( TUser, "" )

//###############################################################################################################################################
//
// 	C L A S S : BON::ExtensionManager
//
//###############################################################################################################################################

	class ExtensionManager
	{
		// Type Definitions
		public :
			typedef ObjectImpl* (*CreateFunction)();
			typedef ExtensionInfo (*CastFunction)( ObjectType eType, const std::string& strKind, const std::string& strRole );

			typedef std::pair<CastFunction,CreateFunction> 		FunctionPair;
			typedef std::vector<FunctionPair> 						FunctionVector;

		// Member Variables
		public :
			static FunctionVector vecKindFunctions;

		// Construction and Destruction
		public :
			ExtensionManager( const std::vector<std::string>& vecKinds, CastFunction pFnCast, CreateFunction pFnCreate );

		// Object methods
		public :
			static ObjectImpl* createImpl( ObjectType eType, const std::string& strKind, const std::string& strRole );

		// Friends
			friend ObjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Extension
//
//###############################################################################################################################################

	template < class TBON , class TUserI>
	class Extension
		: virtual public TBON
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;
		public :

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				return new TUserI();
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				splitKinds( strKinds, _vecKinds );
				TBON::addDerivedKinds( _vecKinds );
				inheritance_level = TBON::inheritance_level + 1;
				string_type = TBON::string_type;
				type = TBON::type;
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			Extension()
				: TBON()
			{
			}

			Extension( TUserI* pObject )
				: TBON( pObject )
			{
				// Line added by Peter
				setCounted( pObject );
			}

			Extension( const Object& object )
				: TBON()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension( const FCO& object )
				: TBON()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension( const ConnectionEnd& object )
				: TBON()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			//	VOLGY: Copy constructor
			Extension( const Extension<TBON,TUserI>& object )
				: TBON()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}


			Extension<TBON,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension<TBON,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension<TBON,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Extension2
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TUserI>
	class Extension2
		: virtual public TBON1, virtual public TBON2
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				return new TUserI();
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					inheritance_level = max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 );
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			Extension2()
				: TBON1(), TBON2()
			{
			}

			Extension2( TUserI* pObject )
				: TBON1(), TBON2()
			{
				setCounted( pObject );
			}

			Extension2( const Object& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension2( const FCO& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension2( const ConnectionEnd& object )
				: TBON1(), TBON2()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			Extension2( const TBON1& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension2( const TBON2& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension2( const Extension2<TBON1,TBON2,TUserI>& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension2<TBON1,TBON2,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension2<TBON1,TBON2,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension2<TBON1,TBON2,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			Extension2<TBON1,TBON2,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension2<TBON1,TBON2,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension2<TBON1,TBON2,TUserI>& operator = ( const Extension2<TBON1,TBON2,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Extension3
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TBON3, class TUserI>
	class Extension3
		: virtual public TBON1, virtual public TBON2, virtual public TBON3
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				return new TUserI();
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				mergeTypes( string_type, type, TBON3::string_type, TBON3::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					TBON3::addDerivedKinds( _vecKinds );
					inheritance_level = max( max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 ), TBON3::inheritance_level + 1);
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
				TBON3::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			Extension3()
				: TBON1(), TBON2(), TBON3()
			{
			}

			Extension3( TUserI* pObject )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( pObject );
			}

			Extension3( const Object& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension3( const FCO& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension3( const ConnectionEnd& object )
				: TBON1(), TBON2(), TBON3()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			Extension3( const TBON1& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension3( const TBON2& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension3( const TBON3& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension3( const Extension3<TBON1,TBON2,TBON3,TUserI>& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension3<TBON1,TBON2,TBON3,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension3<TBON1,TBON2,TBON3,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension3<TBON1,TBON2,TBON3,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			Extension3<TBON1,TBON2,TBON3,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension3<TBON1,TBON2,TBON3,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension3<TBON1,TBON2,TBON3,TUserI>& operator = ( const TBON3& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension3<TBON1,TBON2,TBON3,TUserI>& operator = ( const Extension3<TBON1,TBON2,TBON3,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Extension4
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TBON3, class TBON4, class TUserI>
	class Extension4
		: virtual public TBON1, virtual public TBON2, virtual public TBON3, virtual public TBON4
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				return new TUserI();
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				mergeTypes( string_type, type, TBON3::string_type, TBON3::type, string_type, type );
				mergeTypes( string_type, type, TBON4::string_type, TBON4::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					TBON3::addDerivedKinds( _vecKinds );
					TBON4::addDerivedKinds( _vecKinds );
					inheritance_level = max( max( max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 ), TBON3::inheritance_level + 1), TBON4::inheritance_level + 1);
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
				TBON3::addDerivedKinds( _vecKinds );
				TBON4::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			Extension4()
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
			}

			Extension4( TUserI* pObject )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( pObject );
			}

			Extension4( const Object& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension4( const FCO& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension4( const ConnectionEnd& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			Extension4( const TBON1& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension4( const TBON2& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension4( const TBON3& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension4( const TBON4& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension4( const Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const TBON3& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const TBON4& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const Extension4<TBON1,TBON2,TBON3,TBON4,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Extension5
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TBON3, class TBON4, class TBON5, class TUserI>
	class Extension5
		: virtual public TBON1, virtual public TBON2, virtual public TBON3, virtual public TBON4, virtual public TBON5
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				return new TUserI();
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				mergeTypes( string_type, type, TBON3::string_type, TBON3::type, string_type, type );
				mergeTypes( string_type, type, TBON4::string_type, TBON4::type, string_type, type );
				mergeTypes( string_type, type, TBON5::string_type, TBON5::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					TBON3::addDerivedKinds( _vecKinds );
					TBON4::addDerivedKinds( _vecKinds );
					TBON5::addDerivedKinds( _vecKinds );
					inheritance_level = max( max( max( max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 ), TBON3::inheritance_level + 1), TBON4::inheritance_level + 1), TBON5::inheritance_level + 1);
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
				TBON3::addDerivedKinds( _vecKinds );
				TBON4::addDerivedKinds( _vecKinds );
				TBON5::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			Extension5()
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
			}

			Extension5( TUserI* pObject )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( pObject );
			}

			Extension5( const Object& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension5( const FCO& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension5( const ConnectionEnd& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			Extension5( const TBON1& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension5( const TBON2& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension5( const TBON3& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension5( const TBON4& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension5( const TBON5& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension5( const Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON3& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON4& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON5& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const Extension5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Extension6
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TBON3, class TBON4, class TBON5, class TBON6, class TUserI>
	class Extension6
		: virtual public TBON1, virtual public TBON2, virtual public TBON3, virtual public TBON4, virtual public TBON5, virtual public TBON6
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				return new TUserI();
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				mergeTypes( string_type, type, TBON3::string_type, TBON3::type, string_type, type );
				mergeTypes( string_type, type, TBON4::string_type, TBON4::type, string_type, type );
				mergeTypes( string_type, type, TBON5::string_type, TBON5::type, string_type, type );
				mergeTypes( string_type, type, TBON6::string_type, TBON6::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					TBON3::addDerivedKinds( _vecKinds );
					TBON4::addDerivedKinds( _vecKinds );
					TBON5::addDerivedKinds( _vecKinds );
					TBON6::addDerivedKinds( _vecKinds );
					inheritance_level = max( max( max( max( max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 ), TBON3::inheritance_level + 1), TBON4::inheritance_level + 1), TBON5::inheritance_level + 1), TBON6::inheritance_level + 1);
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
				TBON3::addDerivedKinds( _vecKinds );
				TBON4::addDerivedKinds( _vecKinds );
				TBON5::addDerivedKinds( _vecKinds );
				TBON6::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			Extension6()
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
			}

			Extension6( TUserI* pObject )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( pObject );
			}

			Extension6( const Object& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6( const FCO& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6( const ConnectionEnd& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			Extension6( const TBON1& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6( const TBON2& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6( const TBON3& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6( const TBON4& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6( const TBON5& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6( const TBON6& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6( const Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON3& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON4& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON5& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON6& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const Extension6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ExtensionA
//
//###############################################################################################################################################

	template < class TBON , class TUserI>
	class ExtensionA
		: virtual public TBON
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;
		public :

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				ASSERTTHROW( BON::Exception( "Class is abstract!, It cannot be instantiated!" ) );
				return NULL;
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				splitKinds( strKinds, _vecKinds );
				TBON::addDerivedKinds( _vecKinds );
				inheritance_level = TBON::inheritance_level + 1;
				string_type = TBON::string_type;
				type = TBON::type;
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			ExtensionA()
				: TBON()
			{
			}

			ExtensionA( TUserI* pObject )
				: TBON( pObject )
			{
			}

			ExtensionA( const Object& object )
				: TBON()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA( const FCO& object )
				: TBON()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA( const ConnectionEnd& object )
				: TBON()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			//	VOLGY: Copy constructor
			ExtensionA( const ExtensionA<TBON,TUserI>& object )
				: TBON()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA<TBON,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA<TBON,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA<TBON,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ExtensionA2
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TUserI>
	class ExtensionA2
		: virtual public TBON1, virtual public TBON2
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				ASSERTTHROW( BON::Exception( "Class is abstract!, It cannot be instantiated!" ) );
				return NULL;
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					inheritance_level = max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 );
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			ExtensionA2()
				: TBON1(), TBON2()
			{
			}

			ExtensionA2( TUserI* pObject )
				: TBON1(), TBON2()
			{
				setCounted( pObject );
			}

			ExtensionA2( const Object& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA2( const FCO& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA2( const ConnectionEnd& object )
				: TBON1(), TBON2()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			ExtensionA2( const TBON1& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA2( const TBON2& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA2( const ExtensionA2<TBON1,TBON2,TUserI>& object )
				: TBON1(), TBON2()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA2<TBON1,TBON2,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA2<TBON1,TBON2,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA2<TBON1,TBON2,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			ExtensionA2<TBON1,TBON2,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA2<TBON1,TBON2,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA2<TBON1,TBON2,TUserI>& operator = ( const ExtensionA2<TBON1,TBON2,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ExtensionA3
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TBON3, class TUserI>
	class ExtensionA3
		: virtual public TBON1, virtual public TBON2, virtual public TBON3
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				ASSERTTHROW( BON::Exception( "Class is abstract!, It cannot be instantiated!" ) );
				return NULL;
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				mergeTypes( string_type, type, TBON3::string_type, TBON3::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					TBON3::addDerivedKinds( _vecKinds );
					inheritance_level = max( max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 ), TBON3::inheritance_level + 1);
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
				TBON3::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			ExtensionA3()
				: TBON1(), TBON2(), TBON3()
			{
			}

			ExtensionA3( TUserI* pObject )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( pObject );
			}

			ExtensionA3( const Object& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA3( const FCO& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA3( const ConnectionEnd& object )
				: TBON1(), TBON2(), TBON3()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			ExtensionA3( const TBON1& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA3( const TBON2& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA3( const TBON3& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA3( const ExtensionA3<TBON1,TBON2,TBON3,TUserI>& object )
				: TBON1(), TBON2(), TBON3()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA3<TBON1,TBON2,TBON3,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA3<TBON1,TBON2,TBON3,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA3<TBON1,TBON2,TBON3,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			ExtensionA3<TBON1,TBON2,TBON3,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA3<TBON1,TBON2,TBON3,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA3<TBON1,TBON2,TBON3,TUserI>& operator = ( const TBON3& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA3<TBON1,TBON2,TBON3,TUserI>& operator = ( const ExtensionA3<TBON1,TBON2,TBON3,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ExtensionA4
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TBON3, class TBON4, class TUserI>
	class ExtensionA4
		: virtual public TBON1, virtual public TBON2, virtual public TBON3, virtual public TBON4
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				ASSERTTHROW( BON::Exception( "Class is abstract!, It cannot be instantiated!" ) );
				return NULL;
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				mergeTypes( string_type, type, TBON3::string_type, TBON3::type, string_type, type );
				mergeTypes( string_type, type, TBON4::string_type, TBON4::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					TBON3::addDerivedKinds( _vecKinds );
					TBON4::addDerivedKinds( _vecKinds );
					inheritance_level = max( max( max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 ), TBON3::inheritance_level + 1), TBON4::inheritance_level + 1);
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
				TBON3::addDerivedKinds( _vecKinds );
				TBON4::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			ExtensionA4()
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
			}

			ExtensionA4( TUserI* pObject )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( pObject );
			}

			ExtensionA4( const Object& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA4( const FCO& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA4( const ConnectionEnd& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			ExtensionA4( const TBON1& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA4( const TBON2& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA4( const TBON3& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA4( const TBON4& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA4( const ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& object )
				: TBON1(), TBON2(), TBON3(), TBON4()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const TBON3& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const TBON4& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& operator = ( const ExtensionA4<TBON1,TBON2,TBON3,TBON4,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ExtensionA5
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TBON3, class TBON4, class TBON5, class TUserI>
	class ExtensionA5
		: virtual public TBON1, virtual public TBON2, virtual public TBON3, virtual public TBON4, virtual public TBON5
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				ASSERTTHROW( BON::Exception( "Class is abstract!, It cannot be instantiated!" ) );
				return NULL;
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				mergeTypes( string_type, type, TBON3::string_type, TBON3::type, string_type, type );
				mergeTypes( string_type, type, TBON4::string_type, TBON4::type, string_type, type );
				mergeTypes( string_type, type, TBON5::string_type, TBON5::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					TBON3::addDerivedKinds( _vecKinds );
					TBON4::addDerivedKinds( _vecKinds );
					TBON5::addDerivedKinds( _vecKinds );
					inheritance_level = max( max( max( max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 ), TBON3::inheritance_level + 1), TBON4::inheritance_level + 1), TBON5::inheritance_level + 1);
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
				TBON3::addDerivedKinds( _vecKinds );
				TBON4::addDerivedKinds( _vecKinds );
				TBON5::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			ExtensionA5()
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
			}

			ExtensionA5( TUserI* pObject )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( pObject );
			}

			ExtensionA5( const Object& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA5( const FCO& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA5( const ConnectionEnd& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			ExtensionA5( const TBON1& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA5( const TBON2& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA5( const TBON3& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA5( const TBON4& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA5( const TBON5& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA5( const ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON3& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON4& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const TBON5& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& operator = ( const ExtensionA5<TBON1,TBON2,TBON3,TBON4,TBON5,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ExtensionA6
//
//###############################################################################################################################################

	template < class TBON1, class TBON2, class TBON3, class TBON4, class TBON5, class TBON6, class TUserI>
	class ExtensionA6
		: virtual public TBON1, virtual public TBON2, virtual public TBON3, virtual public TBON4, virtual public TBON5, virtual public TBON6
	{
		// Member variables
		public :
			static std::vector<std::string> vecKinds;
			static const ExtensionManager extensionFactory;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static int inheritance_level;
			static std::string string_type;
			static ObjectType type;

		// Helper methods
		public :
			static ObjectImpl* castObjectImpl( ObjectImpl* pObject )
			{
				return BON::castObjectImpl( pObject, string_type, type, vecKinds, vecDerivedKinds );
			}

			static ExtensionInfo castImpl( ObjectType eOType, const std::string& strKind, const std::string& strRole )
			{
				return ExtensionInfo( BON::castImpl( eOType, strKind, strRole, string_type, type, vecKinds ), inheritance_level );
			}

			static ObjectImpl* createImpl()
			{
				ASSERTTHROW( BON::Exception( "Class is abstract!, It cannot be instantiated!" ) );
				return NULL;
			}

			static std::vector<std::string> setKinds( const std::string& strKinds )
			{
				std::vector<std::string> _vecKinds;
				mergeTypes( TBON1::string_type, TBON1::type, TBON2::string_type, TBON2::type, string_type, type );
				mergeTypes( string_type, type, TBON3::string_type, TBON3::type, string_type, type );
				mergeTypes( string_type, type, TBON4::string_type, TBON4::type, string_type, type );
				mergeTypes( string_type, type, TBON5::string_type, TBON5::type, string_type, type );
				mergeTypes( string_type, type, TBON6::string_type, TBON6::type, string_type, type );
				if ( ! string_type.empty() ) {
					splitKinds( strKinds, _vecKinds );
					TBON1::addDerivedKinds( _vecKinds );
					TBON2::addDerivedKinds( _vecKinds );
					TBON3::addDerivedKinds( _vecKinds );
					TBON4::addDerivedKinds( _vecKinds );
					TBON5::addDerivedKinds( _vecKinds );
					TBON6::addDerivedKinds( _vecKinds );
					inheritance_level = max( max( max( max( max( TBON1::inheritance_level + 1, TBON2::inheritance_level + 1 ), TBON3::inheritance_level + 1), TBON4::inheritance_level + 1), TBON5::inheritance_level + 1), TBON6::inheritance_level + 1);
				}
				return _vecKinds;
			}

		protected :
			static void addDerivedKinds( const std::vector<std::string>& _vecKinds )
			{
				for ( std::vector<std::string>::const_iterator it = _vecKinds.begin() ; it != _vecKinds.end() ; it++ )
					vecDerivedKinds.push_back( *it );
				TBON1::addDerivedKinds( _vecKinds );
				TBON2::addDerivedKinds( _vecKinds );
				TBON3::addDerivedKinds( _vecKinds );
				TBON4::addDerivedKinds( _vecKinds );
				TBON5::addDerivedKinds( _vecKinds );
				TBON6::addDerivedKinds( _vecKinds );
			}

		// Construction and Destruction
		public :
			ExtensionA6()
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
			}

			ExtensionA6( TUserI* pObject )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( pObject );
			}

			ExtensionA6( const Object& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6( const FCO& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6( const ConnectionEnd& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				if ( object && ! object->isReferencePort() )
					setCounted( object.getCounted( false ) );
				if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
					setCounted( NULL );
			}

			ExtensionA6( const TBON1& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6( const TBON2& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6( const TBON3& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6( const TBON4& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6( const TBON5& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6( const TBON6& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6( const ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& object )
				: TBON1(), TBON2(), TBON3(), TBON4(), TBON5(), TBON6()
			{
				setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const Object& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const FCO& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const ConnectionEnd& object )
			{
				if ( this != &object ) {
					if ( object && ! object->isReferencePort() )
						setCounted( object.getCounted( false ) );
					if ( ! castObjectImpl( dynamic_cast<ObjectImpl*>( getCounted( false ) ) ) )
						setCounted( NULL );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON1& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON2& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON3& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON4& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON5& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const TBON6& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& operator = ( const ExtensionA6<TBON1,TBON2,TBON3,TBON4,TBON5,TBON6,TUserI>& object )
			{
				if ( this != &object ) {
					setCounted( castObjectImpl( dynamic_cast<ObjectImpl*>( object.getCounted( false ) ) ) );
				}
				return *this;
			}

			operator bool () const
			{
				return getCounted( false ) != NULL;
			}

			TUserI* operator -> () const
			{
				return dynamic_cast<TUserI*>( getCounted() );
			}

		// Friends
			friend ExtensionManager;
	};

}; // namespace BON

#endif // Extensions_h