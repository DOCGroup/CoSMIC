//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	MONImpl.h
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

#ifndef MONImpl_h
#define MONImpl_h

#pragma warning( disable : 4786 )

#include "StdAfx.h"
#include <string>
#include <map>
#include <set>
#include <vector>
#include "ComponentLib.h"
#include "Utils.h"
#include "Common.h"

namespace MON
{
	class ProjectImpl;
	class ObjectImpl;
	class FolderImpl;
	class FCOImpl;
	class AtomImpl;
	class ModelImpl;
	class SetImpl;
	class ReferenceImpl;
	class ConnectionImpl;
	class AspectImpl;
	class RegistryNodeImpl;
	class ConstraintImpl;

	typedef Util::ComPtr<IMgaMetaProject> ProjectPtr;
	typedef Util::ComPtr<IMgaMetaBase> ObjectPtr;
	typedef Util::ComPtr<IMgaMetaFolder> FolderPtr;
	typedef Util::ComPtr<IMgaMetaFCO> FCOPtr;
	typedef Util::ComPtr<IMgaMetaAtom> AtomPtr;
	typedef Util::ComPtr<IMgaMetaModel> ModelPtr;
	typedef Util::ComPtr<IMgaMetaSet> SetPtr;
	typedef Util::ComPtr<IMgaMetaReference> ReferencePtr;
	typedef Util::ComPtr<IMgaMetaConnection> ConnectionPtr;

	class FolderContainmentImpl;
	class ContainmentImpl;
	class AttributeImpl;
	class AttributeAggregationImpl;
	class ReferenceAssocImpl;
	class SetMembershipImpl;
	class ConnectionSpecImpl;
	class ConnectionRoleImpl;
	class ConnectionEndImpl;
	class ContainmentPartImpl;
	class ModelInAspectImpl;

	typedef Util::ComPtr<IMgaMetaRole> ContainmentPtr;
	typedef Util::ComPtr<IMgaMetaAttribute> AttributePtr;
	typedef Util::ComPtr<IMgaMetaPart> PartPtr;
	typedef Util::ComPtr<IMgaMetaAspect> AspectPtr;
	typedef Util::ComPtr<IMgaMetaRegNode> RegNodePtr;
	typedef Util::ComPtr<IMgaConstraint> ConstraintPtr;

//###############################################################################################################################################
//
// 	C L A S S : MON::ProjectImpl
//
//###############################################################################################################################################

	class ProjectImpl
		: public Util::GenRefCounted
	{
		// Type Definitions
		public :
			typedef std::map<long,ObjectImpl*>					Ref2ObjectMap;
			typedef std::map<std::string,ObjectImpl*>				Name2ObjectMap;
			typedef std::set<ObjectImpl*>							ObjectSet;
			typedef std::map<int,ObjectSet>						Type2ObjectsMap;
			typedef std::map<ProjectPtr,ProjectImpl*>				ProjectMap;

		// Member Variables
		private :
			static ProjectMap							mapProjects;

			ProjectPtr									m_spProject;

			Ref2ObjectMap							m_mapObjectsByRef;
			Name2ObjectMap							m_mapObjectsByName;

			Type2ObjectsMap							m_mapObjectsByType;
			std::set<FolderContainmentImpl*>		m_setFolderContainments;
			std::set<AttributeAggregationImpl*>		m_setAttributeAggregations;
			std::set<ReferenceAssocImpl*>			m_setReferenceAssocs;
			std::set<SetMembershipImpl*>			m_setSetMemberships;
			std::set<ConnectionEndImpl*>			m_setConnectionEnds;
			std::set<ModelInAspectImpl*>			m_setModelInAspects;

			FolderImpl*								m_pRootFolder;

		// Construction and Destruction
		private :
			ProjectImpl( IMgaMetaProject* pProject );
		public :
			static ProjectImpl* attach( IMgaMetaProject* pProject );
			~ProjectImpl();
			bool setDeleted();

		// Attributes
		public :
			ProjectPtr	getProjectI() const;
			std::string	getName() const;
			std::string	getDisplayedName() const;
			std::string getAuthor() const;
			std::string getComment() const;
			std::string getCreationTime() const;
			std::string getInfoString( bool bWithIdentifiers = false ) const;

		// Relations
		public :
			FolderImpl*										getRootFolder() const;
			const ObjectSet&									getObjects( ObjectType eType ) const;
			const std::set<FolderContainmentImpl*>& 		getFolderContainments() const;
			const std::set<AttributeAggregationImpl*>& 	getAttributeAggregations() const;
			const std::set<ReferenceAssocImpl*>&			getReferenceAssocs() const;
			const std::set<SetMembershipImpl*>&			getSetMemberships() const;
			const std::set<ConnectionEndImpl*>&			getConnectionEnds() const;
			const std::set<ModelInAspectImpl*>&			getModelInAspects() const;

		// Find and Search
		public :
			ObjectImpl*	findByRef( long lRelID ) const;
			ObjectImpl*	findByName( const std::string& strName ) const;

		// Initialization
		private :
			FolderImpl*					processFolder( const FolderPtr& spFolder );
			FCOImpl*						processFCO( const FCOPtr& spFCO );
			AtomImpl*						processAtom( const AtomPtr& spAtom );
			ModelImpl*					processModel( const ModelPtr& spModel );
			void							processModel( ModelImpl* pModel );
			ReferenceImpl*				processReference( const ReferencePtr& spReference );
			void							processReference( ReferenceImpl* pReference );
			ConnectionImpl*				processConnection( const ConnectionPtr& spConnection );
			void							processConnection( ConnectionImpl* pConnection );
			SetImpl*						processSet( const SetPtr& spSet );
			void							processSet( SetImpl* pSet );
			AttributeImpl*					processAttribute( const AttributePtr& spAttribute, FCOImpl* pOwner );
			AspectImpl*					processAspect( const AspectPtr& spAspect );
			void							insertObject( ObjectImpl* pObject );
			void						getRolesResolved( const std::set<ContainmentImpl*>& setIn, bool bResolveReference, std::set<ContainmentImpl*>& roles, std::set<FolderContainmentImpl*>& foldroles  ) const;
			std::set<ContainmentImpl*>	getRoles( const std::set<ContainmentImpl*>& setIn, const std::string& strDescIn, bool bResolveReference ) const;
			std::set<ContainmentImpl*>	getLocalRoles( FCOImpl* pKind, const std::string& strDescIn ) const;
			std::set<ContainmentImpl*>	getGlobalRoles( const std::string& strDescIn ) const;

		// Prohibited operations
		private :
			ProjectImpl( const ProjectImpl& pI ) { }
			ProjectImpl& operator = ( const ProjectImpl& pI ) { return *this; }
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ObjectImpl
//
//###############################################################################################################################################

	class ObjectImpl
		: public Util::GenRefCounted
	{
		// Type Definitions
		protected :
			typedef std::map<ObjectPtr,ObjectImpl*>			ObjectMap;
			typedef std::map<std::string, RegistryNodeImpl*>	RegistryMap;

		// Member Variables
		private :
			static ObjectMap	mapObjects;

			ProjectImpl*		m_pProject;
			ObjectPtr			m_spObject;
			RegistryMap		m_mapRegistry;

		// Construction and Destruction
		private :
			ObjectImpl( IMgaMetaBase* spObject, ProjectImpl* pProject );
			static ObjectImpl* find( IMgaMetaBase* spObject );
			static ObjectImpl* attachI( IMgaMetaBase* spObject, ProjectImpl* pProject = NULL );
		public :
			static ObjectImpl* attach( IMgaMetaBase* spObject );
			virtual ~ObjectImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ObjectPtr		getObjectI() const;
			ProjectImpl*	getProject() const;

		// Attributes
		public :
			long 					getRef() const;
			std::string				getName() const;
			std::string				getDisplayedName() const;
			ObjectType			getType() const;

			virtual std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const = 0;

			RegistryNodeImpl*	getRegistryNode( const std::string& strPath );

		// Helper methods
		protected :
			std::string				getInfoStringHelper( const std::string& strStereotype, bool bWithIdentifiers, bool bWithRef ) const;

		// Prohibited operations
		protected :
			ObjectImpl() { };
		private :
			ObjectImpl( const ObjectImpl& oI ) { }
			ObjectImpl& operator = ( const ObjectImpl& oI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class FolderImpl;
			friend class FCOImpl;
			friend class AttributeImpl;
			friend class AspectImpl;
			friend class ContainmentImpl;
			friend class ContainmentPartImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::FolderImpl <<< + MON::ObjectImpl
//
//###############################################################################################################################################

	class FolderImpl
		: public ObjectImpl
	{
		// Member Variables
		private :
			std::set<ConstraintImpl*> m_setConstraints;

		// Construction and Destruction
		private :
			FolderImpl( IMgaMetaFolder* spFolder, ProjectImpl* pProject );
			static FolderImpl* attachI( IMgaMetaFolder* spFolder, ProjectImpl* pProject = NULL );
		public :
			static FolderImpl* attach( IMgaMetaFolder* spFolder );
			~FolderImpl();

		// Get and Set operations
		public:
			FolderPtr				getFolderI() const;
			virtual std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Relations
		public :
			std::set<ConstraintImpl*>	getConstraints() const;

		// Prohibited operations
		private :
			FolderImpl( const FolderImpl& fI ) { }
			FolderImpl& operator = ( const FolderImpl& fI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class ObjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::FCOImpl <<< + MON::ObjectImpl
//
//###############################################################################################################################################

	class FCOImpl
		: public ObjectImpl
	{
		// Member Variables
		private :
			std::set<ConstraintImpl*> 	m_setConstraints;
			std::set<AttributeImpl*>		m_setAttributes;

		// Construction and Destruction
		private :
			FCOImpl( IMgaMetaFCO* spFCO, ProjectImpl* pProject );
			static FCOImpl* find( IMgaMetaFCO* spFCO );
			static FCOImpl* attachI( IMgaMetaFCO* spFCO, ProjectImpl* pProject = NULL );
		public :
			static FCOImpl* attach( IMgaMetaFCO* spFCO );
			virtual ~FCOImpl();

		// Get and Set operations
		public :
			FCOPtr		getFCOI() const;

		// Relations
		public :
			std::set<ConstraintImpl*>			getConstraints() const;
			const std::set<AttributeImpl*>&		getAttributes() const;

		// Prohibited operations
		private :
			FCOImpl() { }
			FCOImpl( const FCOImpl& fI ) { }
			FCOImpl& operator = ( const FCOImpl& fI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class ObjectImpl;
			friend class AtomImpl;
			friend class ModelImpl;
			friend class ReferenceImpl;
			friend class ConnectionImpl;
			friend class SetImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::AtomImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	class AtomImpl
		: public FCOImpl
	{
		// Member Variables
		private :

		// Construction and Destruction
		private :
			AtomImpl( IMgaMetaAtom* spAtom, ProjectImpl* pProject );
			static AtomImpl* attachI( IMgaMetaAtom* spAtom, ProjectImpl* pProject = NULL );
		public :
			static AtomImpl* attach( IMgaMetaAtom* spAtom );
			~AtomImpl();

		// Get and Set operations
		public :
			AtomPtr		getAtomI() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			AtomImpl( const AtomImpl& aI ) { }
			AtomImpl& operator = ( const AtomImpl& aI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ModelImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	class ModelImpl
		: public FCOImpl
	{
		// Member Variables
		private :

		// Construction and Destruction
		private :
			ModelImpl( IMgaMetaModel* spModel, ProjectImpl* pProject );
			static ModelImpl* attachI( IMgaMetaModel* spModel, ProjectImpl* pProject = NULL );
		public :
			static ModelImpl* attach( IMgaMetaModel* spModel );
			~ModelImpl();

		// Get and Set operations
		public :
			ModelPtr		getModelI() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ModelImpl( const ModelImpl& mI ) { }
			ModelImpl& operator = ( const ModelImpl& mI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class FCOImpl;
			friend class ContainmentImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::SetImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	class SetImpl
		: public FCOImpl
	{
		// Member Variables
		private :

		// Construction and Destruction
		private :
			SetImpl( IMgaMetaSet* spSet, ProjectImpl* pProject );
			static SetImpl* attachI( IMgaMetaSet* spSet, ProjectImpl* pProject = NULL );
		public :
			static SetImpl* attach( IMgaMetaSet* spSet );
			~SetImpl();

		// Get and Set operations
		public :
			SetPtr			getSetI() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			SetImpl( const SetImpl& sI ) { }
			SetImpl& operator = ( const SetImpl& sI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ReferenceImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	class ReferenceImpl
		: public FCOImpl
	{
		// Member Variables
		private :

		// Construction and Destruction
		private :
			ReferenceImpl( IMgaMetaReference* spReference, ProjectImpl* pProject );
			static ReferenceImpl* attachI( IMgaMetaReference* spReference, ProjectImpl* pProject = NULL );
		public :
			static ReferenceImpl* attach( IMgaMetaReference* spReference );
			~ReferenceImpl();

		// Get and Set operations
		public :
			ReferencePtr		getReferenceI() const;
			std::string 			getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ReferenceImpl( const ReferenceImpl& rI ) { }
			ReferenceImpl& operator = ( const ReferenceImpl& rI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	class ConnectionImpl
		: public FCOImpl
	{
		// Member Variables
		private :
			std::set<ConnectionSpecImpl*> 	m_setConnSpecs;
			bool								m_bBidirectional;

		// Construction and Destruction
		private :
			ConnectionImpl( IMgaMetaConnection* spConnection, ProjectImpl* pProject );
			static ConnectionImpl* attachI( IMgaMetaConnection* spConnection, ProjectImpl* pProject = NULL );
		public :
			static ConnectionImpl* attach( IMgaMetaConnection* spConnection );
			~ConnectionImpl();

		// Get and Set operations
		public :
			ConnectionPtr									getConnectionI() const;
			const std::set<ConnectionSpecImpl*>&		getConnectionSpecs() const;
			bool											isSimple() const;
			bool											isBidirectional() const;
			std::string 										getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ConnectionImpl( const ConnectionImpl& cI ) { }
			ConnectionImpl& operator = ( const ConnectionImpl& cI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ContainmentImpl <<< + MON::ObjectImpl
//
//###############################################################################################################################################

	class ContainmentImpl
		: public ObjectImpl
	{
		// Member Variables
		private :
			ModelImpl*	m_pParent;
			FCOImpl*		m_pChild;

		// Construction and Destruction
		private :
			ContainmentImpl( IMgaMetaRole* spRole, ProjectImpl* pProject );
			static ContainmentImpl* attachI( IMgaMetaRole* spRole, ProjectImpl* pProject = NULL );
		public :
			static ContainmentImpl* attach( IMgaMetaRole* spRole );
			~ContainmentImpl();

		// Get and Set operations
		public :
			ContainmentPtr 	getContainmentI() const;
			ModelImpl*		getParent() const;
			FCOImpl*			getChild() const;
			std::string 			getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ContainmentImpl( const ContainmentImpl& cI ) { }
			ContainmentImpl& operator = ( const ContainmentImpl& cI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class ObjectImpl;
			friend class ContainmentPartImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::AttributeImpl
//
//###############################################################################################################################################

	class AttributeImpl
		: public ObjectImpl
	{
		// Type Definitions
		public :
			typedef std::pair<std::string,std::string> NameValue;

		// Member Variables
		private :
			FCOImpl* m_pOwner;

		// Construction and Destruction
		private :
			AttributeImpl( IMgaMetaAttribute* spAttribute, ProjectImpl* pProject, FCOImpl* pFCO );
			static AttributeImpl* attachI( IMgaMetaAttribute* spAttribute, ProjectImpl* pProject = NULL, FCOImpl* pFCO = NULL );
		public :
			static AttributeImpl* attach( IMgaMetaAttribute* spAttribute );
			~AttributeImpl();

		// Get and Set operations
		public :
			AttributePtr				getAttributeI() const;
			Util::Variant				getDefaultValue() const;
			AttributeType				getValueType() const;
			std::vector<NameValue>	getEnumItems() const;
			std::string 					getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;
			FCOImpl*					getOwner() const;

		// Prohibited operations
		private :
			AttributeImpl( const AttributeImpl& cI ) { }
			AttributeImpl& operator = ( const AttributeImpl& cI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class ObjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::AspectImpl
//
//###############################################################################################################################################

	class AspectImpl
		: public ObjectImpl
	{
		// Construction and Destruction
		private :
			AspectImpl( IMgaMetaAspect* spAspect, ProjectImpl* pProject );
			static AspectImpl* attachI( IMgaMetaAspect* spAspect, ProjectImpl* pProject = NULL );
		public :
			static AspectImpl* attach( IMgaMetaAspect* spAspect );
			~AspectImpl();

		// Get and Set operations
		public :
			AspectPtr		getAspectI() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			AspectImpl( const AspectImpl& cI ) { }
			AspectImpl& operator = ( const AspectImpl& cI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class ObjectImpl;
			friend class ContainmentPartImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ContainmentPartImpl
//
//###############################################################################################################################################

	class ContainmentPartImpl
		: public ObjectImpl
	{
		// Member Variables
		private :
			ContainmentImpl*	m_pContainment;
			AspectImpl*		m_pAspect;

		// Construction and Destruction
		private :
			ContainmentPartImpl( IMgaMetaPart* spPart, ProjectImpl* pProject );
			static ContainmentPartImpl* attachI( IMgaMetaPart* spPart, ProjectImpl* pProject = NULL );
		public :
			static ContainmentPartImpl* attach( IMgaMetaPart* spPart );
			~ContainmentPartImpl();

		// Get and Set operations
		public :
			PartPtr					getPartI() const;
			bool					isPrimary() const;
			bool					isLinked() const;
			ContainmentImpl*		getContainment() const;
			AspectImpl*			getAspect() const;
			std::string 				getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ContainmentPartImpl( const ContainmentPartImpl& cI ) { }
			ContainmentPartImpl& operator = ( const ContainmentPartImpl& cI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class ObjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::FolderContainmentImpl
//
//###############################################################################################################################################

	class FolderContainmentImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			FolderImpl*	m_pParent;
			ObjectImpl*	m_pChild;

		// Construction and Destruction
		private :
			FolderContainmentImpl( FolderImpl* pParent, ObjectImpl* pChild );
		public :
			~FolderContainmentImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*		getProject() const;
			FolderImpl*		getParent() const;
			ObjectImpl*		getChild() const;
			std::string 			getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			FolderContainmentImpl( const FolderContainmentImpl& fcI ) { }
			FolderContainmentImpl& operator = ( const FolderContainmentImpl& fcI ) { return *this; }

		// Friends
			friend class ProjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::AttributeAggregationImpl
//
//###############################################################################################################################################

	class AttributeAggregationImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			FCOImpl*			m_pFCO;
			AttributeImpl*		m_pAttribute;

		// Construction and Destruction
		private :
			AttributeAggregationImpl( FCOImpl* pFCO, AttributeImpl* pAttribute );
		public :
			~AttributeAggregationImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*		getProject() const;
			FCOImpl*			getFCO() const;
			AttributeImpl*		getAttribute() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			AttributeAggregationImpl( const AttributeAggregationImpl& aaI ) { }
			AttributeAggregationImpl& operator = ( const AttributeAggregationImpl& aaI ) { return *this; }

		// Friends
			friend class ProjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ReferenceAssocImpl
//
//###############################################################################################################################################
	class ReferenceAssocImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			ReferenceImpl*		m_pReference;
			FCOImpl*			m_pTarget;

		// Construction and Destruction
		private :
			ReferenceAssocImpl( ReferenceImpl* pReference, FCOImpl* pTarget );
		public :
			~ReferenceAssocImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*		getProject() const;
			ReferenceImpl*		getReference() const;
			FCOImpl*			getTarget() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ReferenceAssocImpl( const ReferenceAssocImpl& raI ) { }
			ReferenceAssocImpl& operator = ( const ReferenceAssocImpl& raI ) { return *this; }

		// Friends
			friend class ProjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::SetMembershipImpl
//
//###############################################################################################################################################

	class SetMembershipImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			SetImpl*			m_pSet;
			ContainmentImpl*	m_pMember;

		// Construction and Destruction
		private :
			SetMembershipImpl( SetImpl* pSet, ContainmentImpl* pMember );
		public :
			~SetMembershipImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*			getProject() const;
			SetImpl*				getSet() const;
			ContainmentImpl*		getMember() const;
			std::string 				getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			SetMembershipImpl( const SetMembershipImpl& smI ) { }
			SetMembershipImpl& operator = ( const SetMembershipImpl& smI ) { return *this; }

		// Friends
			friend class ProjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionSpecImpl
//
//###############################################################################################################################################

	class ConnectionSpecImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			ConnectionImpl*					m_pConnection;
			std::set<ConnectionRoleImpl*>	m_setRoles;
			int									m_iNum;

		// Construction and Destruction
		private :
			ConnectionSpecImpl( ConnectionImpl* pConnection, int iNum );
		public :
			~ConnectionSpecImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*								getProject() const;
			ConnectionImpl*							getConnection() const;
			const std::set<ConnectionRoleImpl*>&	getRoles() const;
			int											getNumber() const;
			std::string 									getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ConnectionSpecImpl( const ConnectionSpecImpl& smI ) { }
			ConnectionSpecImpl& operator = ( const ConnectionSpecImpl& smI ) { return *this; }

		// Friends
			friend class ProjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionRoleImpl
//
//###############################################################################################################################################

	class ConnectionRoleImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			std::string				m_strRole;
			ConnectionSpecImpl*	m_pSpec;

		// Construction and Destruction
		private :
			ConnectionRoleImpl( ConnectionSpecImpl* pConnection, const std::string& strRole );
		public :
			~ConnectionRoleImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*			getProject() const;
			ConnectionSpecImpl*	getConnectionSpec() const;
			std::string				getName() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ConnectionRoleImpl( const ConnectionRoleImpl& smI ) { }
			ConnectionRoleImpl& operator = ( const ConnectionRoleImpl& smI ) { return *this; }

		// Friends
			friend class ProjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionEndImpl
//
//###############################################################################################################################################

	class ConnectionEndImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			ConnectionRoleImpl* 	m_pConnRole;
			ContainmentImpl*		m_pRole;

		// Construction and Destruction
		private :
			ConnectionEndImpl( ConnectionRoleImpl* pConnectionRole, ContainmentImpl* pRole );
		public :
			~ConnectionEndImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*			getProject() const;
			ConnectionRoleImpl*	getConnectionRole() const;
			ContainmentImpl*		getEnd() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ConnectionEndImpl( const ConnectionEndImpl& smI ) { }
			ConnectionEndImpl& operator = ( const ConnectionRoleImpl& smI ) { return *this; }

		// Friends
			friend class ProjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ModelInAspectImpl
//
//###############################################################################################################################################

	class ModelInAspectImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			AspectImpl*	m_pAspect;
			ModelImpl*	m_pModel;

		// Construction and Destruction
		private :
			ModelInAspectImpl( AspectImpl* pAspect, ModelImpl* pModel );
		public :
			~ModelInAspectImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*	getProject() const;
			AspectImpl*	getAspect() const;
			ModelImpl*	getModel() const;
			std::string 		getInfoString( bool bWithIdentifiers = false, bool bWithRef = false ) const;

		// Prohibited operations
		private :
			ModelInAspectImpl( const ModelInAspectImpl& smI ) { }
			ModelInAspectImpl& operator = ( const ModelInAspectImpl& smI ) { return *this; }

		// Friends
			friend class ProjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::RegistryNodeImpl
//
//###############################################################################################################################################

	class RegistryNodeImpl
		: public Util::GenRefCounted
	{
		// Member variables
		private :
			ObjectImpl*			m_pObject;
			RegNodePtr			m_spNode;
			std::string				m_strPath;

		// Construction and Destruction
		protected :
			RegistryNodeImpl( IMgaMetaRegNode* spNode, ObjectImpl* pObject, const std::string& strPath  );
		public :
			~RegistryNodeImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*						getProject() const;
			ObjectImpl*						getObject() const;
			RegNodePtr						getRegNodeI() const;
			bool								isRootNode() const;

			std::string							getName() const;
			std::string							getPath() const;
			std::string							getValue() const;

			std::string							getValueByPath( const std::string& strPath ) const;

			RegistryNodeImpl*				getParent() const;
			std::set<RegistryNodeImpl*>	getChildren() const;
			RegistryNodeImpl*				getChild( const std::string& strName ) const;

			RegistryNodeImpl*				getChildByPath( const std::string& strPath ) const;

		// Prohibited operations
		private :
			RegistryNodeImpl( const RegistryNodeImpl& oI ) { }
			RegistryNodeImpl& operator = ( const RegistryNodeImpl& oI ) { return *this; }

		// Friends
			friend class ObjectImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : MON::ConstraintImpl
//
//###############################################################################################################################################

	class ConstraintImpl
		: public Util::GenRefCounted
	{
		// Member variables
		private :
			ObjectImpl*			m_pObject;
			ConstraintPtr			m_spConstraint;

		// Construction and Destruction
		protected :
			ConstraintImpl( IMgaConstraint* spConstraint, ObjectImpl* pObject );
		public :
			~ConstraintImpl();
			bool setDeleted();

		// Get and Set operations
		public :
			ProjectImpl*							getProject() const;
			ObjectImpl*							getObject() const;
			ConstraintPtr							getConstraintI() const;

			std::string								getName() const;
			std::string								getDescription() const;
			std::vector<std::string>				getEquation() const;
			std::set<ObjectEventType>			getEvents() const;
			ConstraintPriority						getPriority() const;
			ConstraintDepth						getDepth() const;

		// Prohibited operations
		private :
			ConstraintImpl( const ConstraintImpl& oI ) { }
			ConstraintImpl& operator = ( const ConstraintImpl& oI ) { return *this; }

		// Friends
			friend class FCOImpl;
			friend class FolderImpl;
	};

}; // namespace MON

#endif // MONImpl_h
