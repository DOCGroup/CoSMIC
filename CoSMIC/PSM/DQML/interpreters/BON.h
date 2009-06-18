//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON.h
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

#ifndef BON_h
#define BON_h

#include "Utils.h"
#include "ComponentLib.h"
#include "Common.h"
#include "MON.h"

namespace BON
{
	class Project;

	class Object;
	class Folder;
	class FCO;
	class Atom;
	class Model;
	class Set;
	class Reference;
	class Connection;

	class Attribute;
	class RegistryNode;
	class FCORegistryNode;
	class FCOExRegistryNode;
	class ModelRegistryNode;
	class ConnectionRegistryNode;

	class ConnectionEnd;
	class ReferencePort;

	class ReferencePortContainer;

	class TypeInhObject;
	class Type;
	class Instance;

	class Visitor;

	class ProjectImpl;

	class ObjectImpl;
	class FolderImpl;
	class FCOImpl;
	class AtomImpl;
	class ModelImpl;
	class SetImpl;
	class ReferenceImpl;
	class ConnectionImpl;

	class AttributeImpl;
	class RegistryNodeImpl;
	class FCORegistryNodeImpl;
	class FCOExRegistryNodeImpl;
	class ModelRegistryNodeImpl;
	class ConnectionRegistryNodeImpl;

	class ConnectionEndImpl;
	class ReferencePortImpl;

	class ReferencePortContainerImpl;

	class TypeInhObjectImpl;
	class TypeImpl;
	class InstanceImpl;


//###############################################################################################################################################
//
// 	C L A S S : BON::Project
//
//###############################################################################################################################################

	class Project
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			Project() { }
			Project( const Project& project );
			Project( ProjectImpl* pProject );
			Project& operator = ( const Project& project );

			static Project 	attach( IMgaProject* spProject );

		// Implementation access
		public :
			ProjectImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Object
//
//###############################################################################################################################################

	class Object
		: virtual public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			Object() { }
			Object( ObjectImpl* pObject );
			Object( const Object& object );
			Object& operator = ( const Object& object );

			static Object attach( IMgaObject* spObject );

		// Helper methods
		protected :
			bool castObjectImpl( ObjectType eType, ObjectType eType2 = OT_Null );

		// Implementation access
		public :
			ObjectImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::RegistryNode
//
//###############################################################################################################################################

	class RegistryNode
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			RegistryNode() { }
			RegistryNode( const RegistryNode& node );
			RegistryNode( RegistryNodeImpl* pRegistryNode );
			RegistryNode& operator = ( const RegistryNode& node );

		// Implementation access
		public :
			RegistryNodeImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Folder
//
//###############################################################################################################################################

	class Folder
		: public Object
	{
		public :
		// Type definitions
			typedef FolderImpl implementation_type;
			static const ObjectType type;
			static const std::string string_type;
			static const int inheritance_level;

		// Extension
		private :
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static void addDerivedKinds( const std::vector<std::string>& vecKinds );

		// Construction and Destruction
		public :
			Folder() { }
			Folder( FolderImpl* pObject );
			Folder( const Object& object );
			Folder& operator = ( const Object& object );

			static Folder attach( IMgaObject* spObject );
			static Folder create( const Folder& parent, const MON::Folder& meta = MON::Folder() );
			static Folder create( const Folder& parent, const std::string& strFolder );

		// Implementation access
		public :
			FolderImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionEnd
//
//###############################################################################################################################################

	class ConnectionEnd
		: virtual public Util::GenRefCounter
	{
		// Type Definitions
		public :
			typedef std::pair<std::string,Connection> Pair;

		// Construction and Destruction
		public :
			ConnectionEnd() { }
			ConnectionEnd( ConnectionEndImpl* pObject );
			ConnectionEnd( const ConnectionEnd& object );
			ConnectionEnd& operator = ( const ConnectionEnd& object );

		// Implementation access
		public :
			ConnectionEndImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferencePort
//
//###############################################################################################################################################

	class ReferencePort
		: public ConnectionEnd
	{
		// Construction and Destruction
		public :
			ReferencePort() { }
			ReferencePort( ReferencePortImpl* pObject );
			ReferencePort( const ConnectionEnd& object );
			ReferencePort& operator = ( const ConnectionEnd& object );

		// Implementation access
		public :
			ReferencePortImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::FCO
//
//###############################################################################################################################################

	class FCO
		: public Object, public ConnectionEnd
	{
		public :
		// Type definitions
			typedef FolderImpl implementation_type;
			static const ObjectType type;
			static const std::string string_type;
			static const int inheritance_level;
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static void addDerivedKinds( const std::vector<std::string>& vecKinds );

		// Construction and Destruction
		public :
			FCO() { }
			FCO( FCOImpl* pObject );
			FCO( const Object& object );
			FCO( const ConnectionEnd& object );
			FCO( const FCO& object );
			FCO& operator = ( const Object& object );
			FCO& operator = ( const ConnectionEnd& object );
			FCO& operator = ( const FCO& object );

			static FCO attach( IMgaObject* spObject );

		// Operators
		public :
			operator bool () const;
			bool operator ! () const;

		// Implementation access
		public :
			FCOImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Attribute
//
//###############################################################################################################################################

	class Attribute
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			Attribute();
			Attribute( AttributeImpl* pObject );
			Attribute( const Attribute& object );
			Attribute& operator = ( const Attribute& object );

		// Implementation access
		public :
			AttributeImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Atom
//
//###############################################################################################################################################

	class Atom
		: virtual public FCO
	{
		public :
		// Type definitions
			typedef AtomImpl implementation_type;
			static const ObjectType type;
			static const std::string string_type;
			static const int inheritance_level;

		// Extension
		private :
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static void addDerivedKinds( const std::vector<std::string>& vecKinds );

		// Construction and Destruction
		public :
			Atom() { }
			Atom( AtomImpl* pObject );
			Atom( const Object& object );
			Atom( const ConnectionEnd& object );
			Atom( const FCO& object );
			Atom& operator = ( const Object& object );
			Atom& operator = ( const ConnectionEnd& object );
			Atom& operator = ( const FCO& object );

			static Atom attach( IMgaObject* spObject );
			static Atom create( const Folder& parent, const MON::Atom& meta = MON::Atom() );
			static Atom create( const Folder& parent, const std::string& strAtom );
			static Atom create( const Folder& parent, const Atom& baseType, bool bAsInstance = true );
			static Atom create( const Model& parent, const MON::Atom& meta = MON::Atom(), const std::string& strRole = "" );
			static Atom create( const Model& parent, const std::string& strAtom, const std::string& strRole = "" );
			static Atom create( const Model& parent, const Atom& baseType, bool bAsInstance = true, const std::string& strRole = "" );
			static Atom createAs( const Model& parent, const std::string& strRole );

		// Implementation access
		public :
			AtomImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Model
//
//###############################################################################################################################################

	class Model
		: virtual public FCO
	{
		public :
		// Type definitions
			typedef ModelImpl implementation_type;
			static const ObjectType type;
			static const std::string string_type;
			static const int inheritance_level;

		// Extension
		private :
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static void addDerivedKinds( const std::vector<std::string>& vecKinds );

		// Construction and Destruction
		public :
			Model() { }
			Model( ModelImpl* pObject );
			Model( const Object& object );
			Model( const ConnectionEnd& object );
			Model( const FCO& object );
			Model& operator = ( const Object& object );
			Model& operator = ( const ConnectionEnd& object );
			Model& operator = ( const FCO& object );

			static Model attach( IMgaObject* spObject );
			static Model create( const Folder& parent, const MON::Model& meta = MON::Model() );
			static Model create( const Folder& parent, const std::string& strModel );
			static Model create( const Folder& parent, const Model& baseType, bool bAsInstance = true );
			static Model create( const Model& parent, const MON::Model& meta = MON::Model(), const std::string& strRole = "" );
			static Model create( const Model& parent, const std::string& strModel, const std::string& strRole = "" );
			static Model create( const Model& parent, const Model& baseType, bool bAsInstance = true, const std::string& strRole = "" );
			static Model createAs( const Model& parent, const std::string& strRole );

		// Implementation access
		public :
			ModelImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Set
//
//###############################################################################################################################################

	class Set
		: virtual public FCO
	{
		public :
		// Type definitions
			typedef SetImpl implementation_type;
			static const ObjectType type;
			static const std::string string_type;
			static const int inheritance_level;

		// Extension
		private :
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static void addDerivedKinds( const std::vector<std::string>& vecKinds );

		// Costruction and Destruction
		public :
			Set() { }
			Set( SetImpl* pObject );
			Set( const Object& object );
			Set( const ConnectionEnd& object );
			Set( const FCO& object );
			Set& operator = ( const Object& object );
			Set& operator = ( const ConnectionEnd& object );
			Set& operator = ( const FCO& object );

			static Set attach( IMgaObject* spObject );
			static Set create( const Folder& parent, const MON::Set& meta = MON::Set() );
			static Set create( const Folder& parent, const std::string& strSet );
			static Set create( const Folder& parent, const Set& baseType, bool bAsInstance = true );
			static Set create( const Model& parent, const MON::Set& meta = MON::Set(), const std::string& strRole = "" );
			static Set create( const Model& parent, const std::string& strSet, const std::string& strRole = "" );
			static Set create( const Model& parent, const Set& baseType, bool bAsInstance = true, const std::string& strRole = "" );
			static Set createAs( const Model& parent, const std::string& strRole );

		// Implementation access
		public :
			SetImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Reference
//
//###############################################################################################################################################

	class Reference
		: virtual public FCO
	{
		public :
		// Type definitions
			typedef ReferenceImpl implementation_type;
			static const ObjectType type;
			static const std::string string_type;
			static const int inheritance_level;

		// Extension
		private :
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static void addDerivedKinds( const std::vector<std::string>& vecKinds );

		// Construction and Destruction
		public :
			Reference() { }
			Reference( ReferenceImpl* pObject );
			Reference( const Object& object );
			Reference( const ConnectionEnd& object );
			Reference( const FCO& object );
			Reference& operator = ( const Object& object );
			Reference& operator = ( const ConnectionEnd& object );
			Reference& operator = ( const FCO& object );

			static Reference attach( IMgaObject* spObject );
			static Reference create( const Folder& parent, const MON::Reference& meta = MON::Reference() );
			static Reference create( const Folder& parent, const std::string& strReference );
			static Reference create( const Folder& parent, const Reference& baseType, bool bAsInstance = true );
			static Reference create( const Model& parent, const MON::Reference& meta = MON::Reference(), const std::string& strRole = "" );
			static Reference create( const Model& parent, const std::string& strReference, const std::string& strRole = "" );
			static Reference create( const Model& parent, const Reference& baseType, bool bAsInstance = true, const std::string& strRole = "" );
			static Reference createAs( const Model& parent, const std::string& strRole );

		// Implementation access
		public :
			ReferenceImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Connection
//
//###############################################################################################################################################

	class Connection
		: virtual public FCO
	{
		// Type definitions
		public :
			typedef std::pair<std::string,ConnectionEnd> Pair;
			typedef ConnectionImpl implementation_type;
			static const ObjectType type;
			static const std::string string_type;
			static const int inheritance_level;

		// Extension
		private :
			static std::vector<std::string> vecDerivedKinds;
		protected :
			static void addDerivedKinds( const std::vector<std::string>& vecKinds );

		// Construction and Destruction
		public :
			Connection() { }
			Connection( ConnectionImpl* pObject );
			Connection( const Object& object );
			Connection( const ConnectionEnd& object );
			Connection( const FCO& object );
			Connection& operator = ( const Object& object );
			Connection& operator = ( const ConnectionEnd& object );
			Connection& operator = ( const FCO& object );

			static Connection attach( IMgaObject* spObject );
			static Connection create( const Model& parent, const std::set<Pair>& ends, const MON::Connection& meta = MON::Connection(), const std::string& strRole = "" );
			static Connection create( const Model& parent, const std::set<Pair>& ends, const std::string& strConnection, const std::string& strRole = "" );
			static Connection create( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const MON::Connection& meta = MON::Connection(), const std::string& strRole = "" );
			static Connection create( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const std::string& strConnection, const std::string& strRole = "" );
			static Connection createAs( const Model& parent, const std::set<Pair>& ends, const std::string& strRole );
			static Connection createAs( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const std::string& strRole );

		// Implementation access
		public :
			ConnectionImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferencePortContainer
//
//###############################################################################################################################################

	class ReferencePortContainer
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			ReferencePortContainer() { }
			ReferencePortContainer( const ReferencePortContainer& object );
			ReferencePortContainer( ReferencePortContainerImpl* pContainer );
			ReferencePortContainer& operator = ( const ReferencePortContainer& object );

		// Implementation access
		public :
			ReferencePortContainerImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::TypeInhObject
//
//###############################################################################################################################################

	class TypeInhObject
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			TypeInhObject() { }
			TypeInhObject( const TypeInhObject& object );
			TypeInhObject( TypeInhObjectImpl* pObject );
			TypeInhObject& operator = ( const TypeInhObject& object );

		// Implementation access
		public :
			TypeInhObjectImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Type
//
//###############################################################################################################################################

	class Type
		: public TypeInhObject
	{
		// Construction and Destruction
		public :
			Type() { }
			Type( const TypeInhObject& object );
			Type( TypeImpl* pObject );
			Type& operator = ( const TypeInhObject& object );

		// Implementation access
		public :
			TypeImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Instance
//
//###############################################################################################################################################

	class Instance
		: public TypeInhObject
	{
		// Construction and Destruction
		public :
			Instance() { }
			Instance( const TypeInhObject& object );
			Instance( InstanceImpl* pObject );
			Instance& operator = ( const TypeInhObject& object );

		// Implementation access
		public :
			InstanceImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::FCORegistryNode
//
//###############################################################################################################################################

	class FCORegistryNode
		: public RegistryNode
	{
		// Construction and Destruction
		public :
			FCORegistryNode();
			FCORegistryNode( const RegistryNode& node );
			FCORegistryNode( RegistryNodeImpl* pRegistryNode );
			FCORegistryNode& operator = ( const RegistryNode& node );

		// Implementation access
		public :
			FCORegistryNodeImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::FCOExRegistryNode
//
//###############################################################################################################################################

	class FCOExRegistryNode
		: public FCORegistryNode
	{
		// Construction and Destruction
		public :
			FCOExRegistryNode();
			FCOExRegistryNode( const RegistryNode& node );
			FCOExRegistryNode( RegistryNodeImpl* pRegistryNode );
			FCOExRegistryNode& operator = ( const RegistryNode& node );

		// Implementation access
		public :
			FCOExRegistryNodeImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ModelRegistryNode
//
//###############################################################################################################################################

	class ModelRegistryNode
		: public FCOExRegistryNode
	{
		// Construction and Destruction
		public :
			ModelRegistryNode();
			ModelRegistryNode( const RegistryNode& node );
			ModelRegistryNode( RegistryNodeImpl* pRegistryNode );
			ModelRegistryNode& operator = ( const RegistryNode& node );

		// Implementation access
		public :
			ModelRegistryNodeImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionRegistryNode
//
//###############################################################################################################################################

	class ConnectionRegistryNode
		: public FCORegistryNode
	{
		// Construction and Destruction
		public :
			ConnectionRegistryNode();
			ConnectionRegistryNode( const RegistryNode& node );
			ConnectionRegistryNode( RegistryNodeImpl* pRegistryNode );
			ConnectionRegistryNode& operator = ( const RegistryNode& node );

		// Implementation access
		public :
			ConnectionRegistryNodeImpl* operator -> () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::Visitor
//
//###############################################################################################################################################

	class Visitor
	{
		// Construction and Destruction
		public :
			Visitor() { }
			virtual ~Visitor() { }

		// Standard visitor operations
		public :
			void visitFolder( const Folder& folder );
			void visitAtom( const Atom& atom );
			void visitModel( const Model& model );
			void visitConnection( const Connection& connection );
			void visitSet( const Set& set );
			void visitReference( const Reference& reference );
			void visitReferencePort( const ReferencePort& port );

		// Overridable operations
		protected :
			virtual void visitObjectImpl( const Object& object ) { }
			virtual void visitConnectionEndImpl( const ConnectionEnd& end ) { }
			virtual void visitFCOImpl( const FCO& fco ) { }
			virtual void visitFolderImpl( const Folder& folder ) { }
			virtual void visitAtomImpl( const Atom& atom ) { }
			virtual void visitModelImpl( const Model& model ) { }
			virtual void visitConnectionImpl( const Connection& connection ) { }
			virtual void visitSetImpl( const Set& set ) { }
			virtual void visitReferenceImpl( const Reference& reference ) { }
			virtual void visitReferencePortImpl( const ReferencePort& port ) { }
	};

}; // namespace BON

#endif // BON_h
\