//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	MON.h
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

#ifndef MON_h
#define MON_h

#pragma warning( disable : 4786 )

#include "MONImpl.h"
#include "Exceptions.h"

namespace MON
{
	class Project;
	class MetaObject;
	class Object;
	class Folder;
	class FCO;
	class Atom;
	class Model;
	class Set;
	class Reference;
	class Connection;

	class FolderContainment;
	class ReferenceAssociation;
	class SetMembership;
	class Containment;
	class Attribute;
	class Constraint;
	class Aspect;
	class RegistryNode;
	class ContainmentPart;
	class ConnectionSpecification;
	class ConnectionRole;
	class ConnectionEnd;
	class ModelInAspect;
	class AttributeAggregation;

//###############################################################################################################################################
//
// 	C L A S S : MON::Project
//
//###############################################################################################################################################

	class Project
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			Project();
			Project( ProjectImpl* pProject );
			Project( IMgaMetaProject* spProject );
			Project( const Project& project );
			Project& operator = ( const Project& project );

		// Attributes
		public :
			ProjectPtr	getProjectI() const;
			std::string	name() const;
			std::string	displayedName() const;
			std::string author() const;
			std::string comment() const;
			std::string creationTime() const;
			std::string infoString( bool bWithIdentifiers = false ) const;

		// Relations
		public :
			Folder 								rootFolder() const;
			std::set<Folder>					folders() const;
			std::set<Atom>					atoms() const;
			std::set<Model>					models() const;
			std::set<Set>						sets() const;
			std::set<Reference>				references() const;
			std::set<Connection>			connections() const;
			std::set<Aspect>					aspects() const;
			std::set<Attribute>				attributes() const;
			std::set<FolderContainment>	folderContainments() const;
			std::set<ReferenceAssociation>	referenceAssociations() const;
			std::set<SetMembership>		setMemberships() const;
			std::set<Containment>			containments() const;
			std::set<ConnectionEnd>		connectionEnds() const;
			std::set<ModelInAspect>			modelInAspects() const;
			std::set<ContainmentPart> 		containmentParts() const;
			std::set<AttributeAggregation>	attributeAggregations() const;

		// Find and Search
		public :
			MetaObject	findByRef( long lRef ) const;
			MetaObject 	findByName( const std::string strName ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::MetaObject
//
//###############################################################################################################################################

	class MetaObject
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			MetaObject();
			MetaObject( ObjectImpl* pObject );
			MetaObject( const MetaObject& object );
			MetaObject& operator = ( const MetaObject& object );

		// Helper operations
		protected :
			void castObjectImpl( ObjectType eType, ObjectType eType2 = OT_Null );

		// Attributes
		public :
			ObjectPtr		getObjectI() const;
			long			ref() const;
			std::string		name() const;
			std::string		displayedName() const;
			ObjectType	type() const;
			std::string		infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

			RegistryNode	registry() const;

		// Relations
		public :
			Project project() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Object
//
//###############################################################################################################################################

	class Object
		: public MetaObject
	{
		// Construction and Destruction
		public :
			Object();
			Object( ObjectImpl* pObject );
			Object( const MetaObject& object );
			Object& operator = ( const MetaObject& object );

		// Relations
		public :
			std::set<FolderContainment>	parentFolderContainments() const;
			std::set<Folder>					parentFolders() const;
			bool								isFolderParent( const Folder& folder ) const;

			std::set<Constraint>				constraints() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Folder
//
//###############################################################################################################################################

	class Folder
		: public Object
	{
		// Construction and Destruction
		public :
			Folder() { }
			Folder( ObjectImpl* pObject );
			Folder( const MetaObject& object );
			Folder( IMgaMetaBase* spObject );
			Folder& operator = ( const MetaObject& object );

		// Attributes
		public :
			FolderPtr	getFolderI() const;

		// Relations
		public :
			std::set<FolderContainment>	childFolderContainments() const;
			std::set<Object>					childObjects() const;
			std::set<Folder>					childFolders() const;
			std::set<FCO>					childFCOs() const;
			std::set<Atom>					childAtoms() const;
			std::set<Model>					childModels() const;
			bool								isObjectChild( const Object& object ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::FCO
//
//###############################################################################################################################################

	class FCO
		: public Object
	{
		// Construction and Destruction
		public :
			FCO() { }
			FCO( ObjectImpl* pObject );
			FCO( const MetaObject& object );
			FCO& operator = ( const MetaObject& object );

		// Attributes
		public :
			FCOPtr		getFCOI() const;

		// Relations
		public :
			std::set<Containment>			parentContainments() const;
			std::set<Model>					parentModels() const;
			bool								isModelParent( const Model& model ) const;

			std::set<ConnectionEnd>		connectionEnds() const;
			std::set<ConnectionRole>		targetOf() const;
			bool								isTargetOf( const ConnectionRole& role ) const;

			std::set<ReferenceAssociation>	referenceAssociations() const;
			std::set<Reference>				referencedBy() const;
			bool								isReferencedBy( const Reference& reference ) const;

			std::set<SetMembership>		setMemberships() const;
			std::set<Set>						memberOf() const;
			bool								isMemberOf( const Set& reference ) const;

			std::set<AttributeAggregation>	attributeAggregations() const;
			std::set<Attribute>				attributes( bool bLocalsAlso = true ) const;
			std::set<Attribute>				localAttributes() const;
			bool								hasAttribute( const Attribute& attribute, bool bLocalsAlso = true ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Atom
//
//###############################################################################################################################################

	class Atom
		: public FCO
	{
		// Construction and Destruction
		public :
			Atom() { }
			Atom( ObjectImpl* pObject );
			Atom( const MetaObject& object );
			Atom( IMgaMetaBase* spObject );
			Atom& operator = ( const MetaObject& object );

		// Attributes
		public :
			AtomPtr	getAtomI() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Model
//
//###############################################################################################################################################

	class Model
		: public FCO
	{
		// Construction and Destruction
		public :
			Model() { }
			Model( ObjectImpl* pObject );
			Model( const MetaObject& object );
			Model( IMgaMetaBase* spObject );
			Model& operator = ( const MetaObject& object );

		// Attributes
		public :
			ModelPtr	getModelI() const;

		// Relations
		public :
			std::set<Containment>	childContainments() const;
			std::set<FCO>			childFCOs() const;
			std::set<Atom>			childAtoms() const;
			std::set<Model>			childModels() const;
			std::set<Connection>	childConnections() const;
			std::set<Set>				childSets() const;
			std::set<Reference>		childReferences() const;
			bool						isFCOChild( const FCO& fco ) const;

			std::set<ModelInAspect>	modelInAspects() const;
			std::set<Aspect>			aspects() const;
			bool						hasAspect( const Aspect& aspect ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionRole
//
//###############################################################################################################################################

	class ConnectionRole
		: public Util::GenRefCounter
	{
		// Type definitions
		public :
			typedef std::pair<std::string, FCO> KindPair;
			typedef std::pair<std::string, Containment> RolePair;

		// Construction and Destruction
		public :
			ConnectionRole();
			ConnectionRole( ConnectionRoleImpl* pConnectionRole );
			ConnectionRole( const ConnectionRole& connectionRole );
			ConnectionRole& operator = ( const ConnectionRole& connectionRole );

		// Relations
		public :
			Project							project() const;
			ConnectionSpecification		specification() const;
			std::string						name() const;
			std::string						infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

			std::set<ConnectionEnd>	connectionEnds() const;
			std::set<Containment>		targetRoles() const;
			std::set<FCO>				targets() const;
			bool							isTarget( const FCO& fco ) const;
			bool							isTarget( const Containment& containment ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionSpecification
//
//###############################################################################################################################################

	class ConnectionSpecification
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			ConnectionSpecification();
			ConnectionSpecification( ConnectionSpecImpl* pConnectionSpec );
			ConnectionSpecification( const ConnectionSpecification& connectionSpec );
			ConnectionSpecification& operator = ( const ConnectionSpecification& connectionSpec );

		// Relations
		public :
			Project							project() const;
			Connection					connection() const;
			int								number() const;
			std::string						infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

			std::set<ConnectionRole>	roles() const;
			ConnectionRole				role( const std::string& strRoleName ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Connection
//
//###############################################################################################################################################

	class Connection
		: public FCO
	{
		// Type Definitions
		public :
			typedef std::pair<std::string,FCO> Pair;

		// Construction and Destruction
		public :
			Connection() { }
			Connection( ObjectImpl* pObject );
			Connection( const MetaObject& object );
			Connection( IMgaMetaBase* spObject );
			Connection& operator = ( const MetaObject& object );

		// Attributes
		public :
			ConnectionPtr	getConnectionI() const;

		// Relations
		public :
			bool									isSimple() const;
			bool									isBidirectional() const;

			std::set<ConnectionSpecification>	specifications() const;
			int										specificationCount() const;
			ConnectionSpecification				specification( int iNum ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Set
//
//###############################################################################################################################################

	class Set
		: public FCO
	{
		// Construction and Destruction
		public :
			Set() { }
			Set( ObjectImpl* pObject );
			Set( const MetaObject& object );
			Set( IMgaMetaBase* spObject );
			Set& operator = ( const MetaObject& object );

		// Attributes
		public :
			SetPtr		getSetI() const;

		// Relations
		public :
			std::set<SetMembership>		memberships() const;
			std::set<Containment>			memberRoles() const;
			bool 								isMember( const Containment& role ) const;
			bool 								isMember( const FCO& fco ) const; //added by ZolMol
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Reference
//
//###############################################################################################################################################

	class Reference
		: public FCO
	{
		// Construction and Destruction
		public :
			Reference() { }
			Reference( ObjectImpl* pObject );
			Reference( const MetaObject& object );
			Reference( IMgaMetaBase* spObject );
			Reference& operator = ( const MetaObject& object );

		// Attributes
		public :
			ReferencePtr	getReferenceI() const;

		// Relations
		public :
			std::set<ReferenceAssociation>	refAssociations() const;
			std::set<FCO>					targetFCOs() const; // ZolMol changed Containment to FCO and renamed targetRoles to targetFCOs
			bool							isReferenced( const FCO& fco ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Containment
//
//###############################################################################################################################################

	class Containment
		: public MetaObject
	{
		// Construction and Destruction
		public :
			Containment() { }
			Containment( ObjectImpl* pObject ); // still dangerous
		private: //ZolMol
			Containment( const MetaObject& object ); 
			Containment( const FCO& object ); 
		public:
			Containment( IMgaMetaBase* spObject );
		private: //ZolMol
			Containment& operator = ( const MetaObject& object );

		// Attributes
		public :
			ContainmentPtr	getContainmentI() const;

		// Relations
		public :
			Model	parent() const;
			FCO	child() const;

			std::set<ConnectionEnd>		connectionEnds() const;
			std::set<ConnectionRole>		targetOf() const;
			bool								isTargetOf( const ConnectionRole& role ) const;

			std::set<ContainmentPart>		parts() const;
			std::set<Aspect>					aspects() const;
			bool								isVisibleIn( const Aspect& aspect ) const;

			std::set<ReferenceAssociation>	referenceAssociations() const;
			std::set<Reference>				referencedBy() const;
			bool								isReferencedBy( const Reference& reference ) const;

			std::set<SetMembership>		setMemberships() const;
			std::set<Set>						memberOf() const;
			bool								isMemberOf( const Set& set ) const;

	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Attribute

//###############################################################################################################################################

	class Attribute
		: public MetaObject
	{
		// Type Definitions
		public :
			typedef std::pair<std::string,std::string> NameValue;

		// Construction and Destruction
		public :
			Attribute() { }
			Attribute( ObjectImpl* pObject );
			Attribute( const MetaObject& object );
			Attribute( IMgaMetaBase* spObject );
			Attribute& operator = ( const MetaObject& object );

		// Attributes
		public :
			AttributePtr				getAttributeI() const;
			Util::Variant				defaultValue() const;
			AttributeType				valueType() const;
			std::vector<NameValue>	enumItems() const;
			FCO						owner() const;

		// Relations
		public :
			std::set<AttributeAggregation>	attributeAggregations() const;
			std::set<FCO>					FCOs() const;
			bool								isContainedBy( const FCO& fco ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Aspect
//
//###############################################################################################################################################

	class Aspect
		: public MetaObject
	{
		// Construction and Destruction
		public :
			Aspect() { }
			Aspect( ObjectImpl* pObject );
			Aspect( const MetaObject& object );
			Aspect( IMgaMetaBase* spObject );
			Aspect& operator = ( const MetaObject& object );

		// Attributes
		public :
			AspectPtr			getAspectI() const;

		// Relations
		public :
			std::set<ModelInAspect>		modelInAspects() const;
			std::set<Model>				models() const;
			bool							isContainedBy( const Model& model ) const;

			std::set<ContainmentPart>	parts() const;
			std::set<Containment>		containments() const;
			bool							hasContainment( const Containment& containment ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ContainmentPart
//
//###############################################################################################################################################

	class ContainmentPart
		: public MetaObject
	{
		// Construction and Destruction
		public :
			ContainmentPart() { }
			ContainmentPart( ObjectImpl* pObject );
			ContainmentPart( const MetaObject& object );
			ContainmentPart( IMgaMetaBase* spObject );
			ContainmentPart& operator = ( const MetaObject& object );

		// Attributes
		public :
			PartPtr			getPartI() const;
			bool			isLinked() const;
			bool			isPrimary() const;

		// Relations
		public :
			Containment	containment() const;
			Aspect			aspect() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::FolderContainment
//
//###############################################################################################################################################

	class FolderContainment
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			FolderContainment();
			FolderContainment( FolderContainmentImpl* pFolderContainment );
			FolderContainment( const FolderContainment& folderContainment );
			FolderContainment& operator=( const FolderContainment& folderContainment );

		// Attributes
		public :
			std::string		infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Relations
		public :
			Project		project() const;
			Folder		parent() const;
			Object		child() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ReferenceAssociation
//
//###############################################################################################################################################

	class ReferenceAssociation
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			ReferenceAssociation();
			ReferenceAssociation( ReferenceAssocImpl* pReferenceAssoc );
			ReferenceAssociation( const ReferenceAssociation& referenceAssoc );
			ReferenceAssociation& operator=( const ReferenceAssociation& referenceAssoc );

		// Attributes
		public :
			std::string		infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Relations
		public :
			Project			project() const;
			Reference		reference() const;
			FCO				target() const; //ZolMol changed from Containmnent to FCO
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::SetMembership
//
//###############################################################################################################################################

	class SetMembership
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			SetMembership();
			SetMembership( SetMembershipImpl* pSetMembership );
			SetMembership( const SetMembership& setMembership );
			SetMembership& operator=( const SetMembership& setMembership );

		// Attributes
		public :
			std::string		infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Relations
		public :
			Project			project() const;
			Set				set() const;
			Containment	member() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionEnd
//
//###############################################################################################################################################

	class ConnectionEnd
		: public Util::GenRefCounter
	{
		// Type Definitions
		public :
			typedef std::pair<std::string,Connection> Pair;

		// Construction and Destruction
		public :
			ConnectionEnd();
			ConnectionEnd( ConnectionEndImpl* pConnectionEnd );
			ConnectionEnd( const ConnectionEnd& connectionEnd );
			ConnectionEnd& operator=( const ConnectionEnd& connectionEnd );

		// Attributes
		public :
			std::string			infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Relations
		public :
			Project				project() const;
			ConnectionRole	role() const;
			Containment		target() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ModelInAspect
//
//###############################################################################################################################################

	class ModelInAspect
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			ModelInAspect();
			ModelInAspect( ModelInAspectImpl* pModelInAspect);
			ModelInAspect( const ModelInAspect& modelInAspect );
			ModelInAspect& operator=( const ModelInAspect& modelInAspect );

		// Attributes
		public :
			std::string		infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Relations
		public :
			Project		project() const;
			Aspect		aspect() const;
			Model		model() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::AttributeAggregation
//
//###############################################################################################################################################

	class AttributeAggregation
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			AttributeAggregation();
			AttributeAggregation( AttributeAggregationImpl* pAttributeAggr );
			AttributeAggregation( const AttributeAggregation& attributeAggr );
			AttributeAggregation& operator=( const AttributeAggregation& attributeAggr );

		// Attributes
		public :
			std::string		infoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Relations
		public :
			Project		project() const;
			FCO		fco() const;
			Attribute 	attribute() const;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::RegistryNode
//
//###############################################################################################################################################

	class RegistryNode
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			RegistryNode();
			RegistryNode( const RegistryNode& node );
			RegistryNode( RegistryNodeImpl* pRegistryNode );
			RegistryNode& operator = ( const RegistryNode& node );

		// Attributes
		public :
			RegNodePtr				getRegNodeI() const;
			Project						project() const;
			MetaObject				object() const;
			bool						isRoot() const;

			std::string					name() const;
			std::string					path() const;

			std::string					value() const;
			long						integerValue() const;
			double						realValue() const;
			bool						boolValue() const;

			std::string					valueByPath( const std::string& strPath ) const;

			RegistryNode				parent() const;
			std::set<RegistryNode>	children() const;
			RegistryNode				child( const std::string& strName ) const;
			RegistryNode				childByPath( const std::string& strPath ) const;   // descendant
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::Constraint
//
//###############################################################################################################################################

	class Constraint
		: public Util::GenRefCounter
	{
		// Construction and Destruction
		public :
			Constraint();
			Constraint( const Constraint& constraint );
			Constraint( ConstraintImpl* pConstraint );
			Constraint& operator = ( const Constraint& constraint );

		// Attributes
		public :
			Project									project() const;
			Object									object() const;
			ConstraintPtr							getConstraintI() const;

			std::string								name() const;
			std::string								description() const;
			std::vector<std::string>				equation() const;
			std::set<ObjectEventType>			events() const;
			ConstraintPriority						priority() const;
			ConstraintDepth						depth() const;
	};

}; // namespace MON

#endif // MON_h