//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BONImpl.h
//
//###############################################################################################################################################

/*
	Copyright (c) Vanderbilt University, 2000-2003
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

#ifndef BONImpl_h
#define BONImpl_h

#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )

#include "StdAfx.h"
#include "MON.h"
#include "BON.h"
#include "Events.h"

class CEventSink;

namespace BON
{
	class Factory;

	class ProjectImpl;

	class ObjectImpl;
	class FolderImpl;
	class FCOImpl;
	class AtomImpl;
	class ModelImpl;
	class ConnectionImpl;
	class SetImpl;
	class ReferenceImpl;

	class AttributeImpl;

	class RegistryNodeImpl;
	class FCORegsitryNodeImpl;
	class FCOExRegsitryNodeImpl;
	class ModelRegsitryNodeImpl;
	class ConnectionRegsitryNodeImpl;

	class ConnectionEndImpl;
	class ReferencePortImpl;

	class ReferencePortContainerImpl;

	class TypeInhObjectImpl;
	class TypeImpl;
	class InstanceImpl;

	typedef Util::ComPtr<IMgaProject> 		ProjectPtr;
	typedef Util::ComPtr<IMgaTerritory>		TerritoryPtr;
	typedef Util::ComPtr<IMgaObject>		ObjectPtr;
	typedef Util::ComPtr<IMgaFolder>		FolderPtr;
	typedef Util::ComPtr<IMgaFCO>			FCOPtr;
	typedef Util::ComPtr<IMgaAtom>		AtomPtr;
	typedef Util::ComPtr<IMgaModel>		ModelPtr;
	typedef Util::ComPtr<IMgaConnection>	ConnectionPtr;
	typedef Util::ComPtr<IMgaSet>			SetPtr;
	typedef Util::ComPtr<IMgaReference>	ReferencePtr;
	typedef Util::ComPtr<IMgaAttribute>	AttributePtr;
	typedef Util::ComPtr<IMgaRegNode>	RegNodePtr;
	typedef Util::ComPtr<IMgaConnPoint>	ConnPointPtr;
	typedef Util::ComPtr<IMgaFCOs> 		FCOsPtr;

	typedef Util::ComPtr<IGMEOLEApp> 		GMEAppPtr;

	typedef std::set<ObjectImpl*>				ObjectSet;
	typedef std::pair<bool,ObjectSet>			ObjectSetPair;
	typedef std::set<FolderImpl*>				FolderSet;
	typedef std::pair<bool,FolderSet>			FolderSetPair;
	typedef std::set<FCOImpl*>					FCOSet;
	typedef std::pair<bool,FCOSet>				FCOSetPair;
	typedef std::set<SetImpl*>					SetSet;
	typedef std::pair<bool,SetSet>				SetSetPair;
	typedef std::set<ReferenceImpl*>			ReferenceSet;
	typedef std::pair<bool,ReferenceSet>		ReferenceSetPair;
	typedef std::set<ConnectionImpl*>			ConnectionSet;
	typedef std::pair<bool,ConnectionSet>		ConnectionSetPair;
	typedef std::set<ConnectionEndImpl*>		ConnectionEndSet;
	typedef std::pair<bool,ConnectionEndSet>	ConnectionEndSetPair;
	typedef std::set<ReferencePortImpl*>		ReferencePortSet;

//###############################################################################################################################################
//
// 	C L A S S : BON::ProjectImpl
//
//###############################################################################################################################################

	class ProjectImpl
		: public Util::GenRefCounted, public EventListenerPool
	{
		// Type Definitions
		private :
			typedef std::map<ProjectPtr, ProjectImpl*>						ProjectMap;
			typedef std::map<std::string, ObjectImpl*> 					ObjectMapByID;
			typedef std::map<MON::Object, ObjectSetPair> 				ObjectMapByKind;
			typedef std::map<ObjectPtr, ObjectImpl*>						ObjectMap;
			typedef std::set<Factory*>										FactorySet;

		// Member variables
		private :
			static ProjectMap		mapProjects;
			ProjectPtr				m_spProject;
			TerritoryPtr			m_spTerritory;
			MON::Project			m_meta;

			GMEAppPtr				m_gme;

			bool					m_bAutoCommit;
			bool 					m_bIsDestructionActive;
			ObjectMap				m_mapObjects;
			ObjectMapByID		m_mapObjectsByID;
			ObjectMapByKind		m_mapObjectsByKind;
			FolderImpl*			m_pRootFolder;

		// Construction and Destruction
		private :
			ProjectImpl( IMgaProject* spProject );
		public :
			~ProjectImpl();
			bool 					setDeleted();
			void					finalizeObjects();
			static Project 			attach( IMgaProject* spProject );

		// Set and Get operations // ----> Interface Methods
		public :
			bool					isAutoCommit() const;
			void					setAutoCommit( bool bAutoCommit );
			void 					commit();
			void					abort();
			bool 					isDestructionActive() const;

			ProjectPtr				getProjectI() const;
			const MON::Project&	getProjectMeta() const;

			std::string				getName() const;
			std::string 				getAuthor() const;
			std::string 				getComment() const;
			std::string 				getCreationTime() const;
			std::string				getChangeTime() const;
			std::string				getGUID() const;
			std::string				getVersion() const;
			void 					setName( const std::string& strName );
			void 					setAuthor( const std::string& strAuthor );
			void 					setComment( const std::string& strComment );

			std::string				getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;
			std::string				getInfoString( const std::set<Util::InfoOption>& setOptions ) const;

			void					assignTerritory(TerritoryPtr terr);

			void					consoleMsg(const std::string& msg, msgtype_enum type);
			std::string 				getConsoleContents();
			void 					putConsoleContents(const std::string& htmlMsg);

			std::string				getGMEVersion();
			int						getGMEVersionMajor();
			int						getGMEVersionMinor();
			int						getGMEVersionPatchLevel();

			void					saveProject();
			void					saveProjectAs(const std::string& connstr);
			void					exportProject(const std::string& connstr);
			void					importProject(const std::string& connstr);

			void					checkConstraints();
			void					runComponent(const std::string& progID);

			void					showFCO(FCO fco);


		// Relations // ----> Interface Methods
		public :
			Folder					getRootFolder();
			std::set<Folder>		getLibraries();		// CHANGED LINE

			Object					findByID( const std::string& strID, bool bExc_IfNotExist = false );
			std::set<Object>		findByKind( const MON::Object& meta );
			std::set<Object>		findByKind( const std::string& strKind );

		// Find and Search
		private :
			ObjectImpl*			findByCOMI( IMgaObject* spObject ) const;
			ObjectImpl*			findByIDI( const std::string& strID );
			ObjectSet				findByKindI( const MON::FCO& meta );
			ObjectSet				findByKindI( const MON::Folder& meta );
			void					findByKindI( FolderPtr spFolder, const MON::Folder& meta );

			GMEAppPtr				getGME();

		// Event Handlers
		private :
			void					onObjectRetrieved( ObjectImpl* pObject );
			void					onObjectReleased( ObjectImpl* pObject, bool bOnlyMemoryFree );

		// Prohibited operations
		private :
			ProjectImpl( const ProjectImpl& pI ) { }
			ProjectImpl& operator = ( const ProjectImpl& pI ) { return *this; }

		// Friends
			friend class ObjectImpl;
			friend class ConnectionEndImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ObjectImpl
//
//###############################################################################################################################################

	class ObjectImpl
		: virtual public Util::GenRefCounted, public EventListenerPool
	{
		// Type definitions
		private :
			typedef std::pair<MON::Folder,FolderImpl*>				OneFolderLink;
			typedef std::map<RegNodePtr,RegistryNodeImpl*>		RegistryMap;

		// Member variables
		private :
			ObjectPtr			m_spObject;
			ProjectImpl*		m_pProject;
			MON::Object 		m_meta;
			OneFolderLink		m_parentFolder;
			bool				m_bAllParentFolders;
			RegistryMap		m_mapNodes;
			bool 				m_bIsDestructionActive;

		// Construction and Destruction
		protected :
			ObjectImpl();
			static ObjectImpl* attachI( IMgaObject* spObject, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
			static ObjectImpl* find( ProjectImpl* pProject, IMgaObject* spObject );
			static ObjectImpl* getEx( IMgaObject* spObject, ObjectType eType, const MON::Object& meta = MON::Object() );
			void				doInitialize( IMgaObject* spObject, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
		public :
			virtual ~ObjectImpl();
			bool			setDeleted();
			static Object 	attach( IMgaObject* spObject );
			void			destroy();

		// Get and Set operations // ----> Interface Methods
		public :
			Project					getProject() const;
			ObjectPtr				getObjectI() const;
			const MON::Object&	getObjectMeta() const;

			bool 					isDestructionActive() const;
			std::string				getID() const;
			virtual ObjectType 	getStereotype() const = 0;
			ObjectStatus			getStatus() const;
			bool					isReadOnly() const;
			bool					isInLibrary() const;

			std::string				getName() const;
			void					setName( const std::string& strName );
			std::string 				getPath( const std::string& strDelimiter = "/", bool bReverseOrder = false, bool bNeedRootFolder = false ) const;

			virtual std::string		getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const = 0;
			std::string				getInfoString( const std::set<Util::InfoOption>& setOptions ) const;

		// Relations // ----> Interface Methods
		public :
			RegistryNode			getRegistry() const;

			Folder		 			getParentFolder( const MON::Folder& meta = MON::Folder() );
			Folder					getParentFolder( const std::string& strFolder );
			virtual Object			getParent();

		// Extensions
		public :
			virtual void 			accept( Visitor* pVisitor );
			virtual void			initialize() { }
			virtual void 			finalize() { }

		// Relations
		private :
			FolderImpl*		 	getParentFolderI( const MON::Folder& meta = MON::Folder() );

		// Helper Methods
		private :
			std::string 				getInfoStringHelper( Util::InfoOptions usOptions, const std::string& strStereo ) const;

		// Event Handlers
		private :
			bool 					onRetrievedAsFolderChild( FolderImpl* pFolder, bool bCheckAll );
			void 					onReleasedAsFolderChild( FolderImpl* pFolder, bool bOnlyMemoryFree );
		// GME Event Handlers
		public :
			virtual void 			eventPerformedI( const Event& event );
		private :
			void					onObjectCreated();
			void					onRegistryChanged();
			void					onObjectMoved( ObjectImpl* pOldParent, ObjectImpl* pNewParent );

		// Prohibited operations
		private :
			ObjectImpl( const ObjectImpl& oI ) { }
			ObjectImpl& operator = ( const ObjectImpl& oI ) { return *this; }

		// Friends
			friend class ProjectImpl;
			friend class FolderImpl;
			friend class FCOImpl;
			friend class ModelImpl;
			friend class FCOImpl;
			friend class ModelImpl;
			friend class AtomImpl;
			friend class SetImpl;
			friend class ReferenceImpl;
			friend class ConnectionImpl;
			friend class RegistryNodeImpl;
			friend class ConnectionEndImpl;
			friend class CEventSink;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::RegistryNodeImpl
//
//###############################################################################################################################################

	class RegistryNodeImpl
		: public Util::GenRefCounted
	{
		// Member variables
		private :
			ObjectImpl*	m_pObject;
			RegNodePtr	m_spNode;

		// Construction and Destruction
		private :
			RegistryNodeImpl( IMgaRegNode* spNode, ObjectImpl* pObject );
			static RegistryNodeImpl* attachI( IMgaRegNode* spNode, ObjectImpl* pObject );
		public :
			virtual ~RegistryNodeImpl();
			bool								setDeleted();

		// Get and Set operations // ---> Interface Methods
		public :
			Project								getProject() const;
			Object								getObject() const;
			RegNodePtr						getRegNodeI() const;
			bool								isRootNode() const;

			std::string							getName() const;
			std::string							getPath() const;
			RegistryNodeStatus				getStatus() const;
			std::string							getValue() const;
			void								setValue( const std::string& strValue );
			long								getIntegerValue() const;
			void								setIntegerValue( long lValue );
			double								getRealValue() const;
			void								setRealValue( double dValue );
			bool								getBoolValue() const;
			void								setBoolValue( bool bValue );
			void								clear();

			std::string							getValueByPath( const std::string& strPath ) const;
			void								setValueByPath( const std::string& strPath, const std::string& strValue );

		// Relations // ---> Interface Methods
		public :
			RegistryNode						getParent() const;
			std::set<RegistryNode>			getChildren( bool bVirtualsAlso = false ) const;
			RegistryNode						getChild( const std::string& strName ) const;
			void								removeTree();

			RegistryNode						getDescendantByPath( const std::string& strPath ) const;

		// Prohibited operations
		private :
			RegistryNodeImpl( const RegistryNodeImpl& oI );
			RegistryNodeImpl& operator = ( const RegistryNodeImpl& oI ) { return *this; }

		// Friends
			friend class ObjectImpl;
			friend class FCORegistryNodeImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::FolderImpl
//
//###############################################################################################################################################

	class FolderImpl
		: public ObjectImpl
	{
		// Type definitions
		private :
			typedef std::map<MON::Object,ObjectSetPair>		ManyObjectLink;

		// Member variables
		private :
			ManyObjectLink	m_childObjects;
			bool 				m_bAllChildObjects;

		// Costruction and Destruction
		protected :
			FolderImpl();
			static FolderImpl* attachI( IMgaFolder* spFolder, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
			static FolderImpl* createI( FolderImpl* pParentFolder, const MON::Folder& meta );
		public :
			~FolderImpl();
			bool 			setDeleted();
			static Folder attach( IMgaFolder* spFolder );
			static Folder create( const Folder& parent, const MON::Folder& meta = MON::Folder() );
			static Folder create( const Folder& parent, const std::string& strFolder );

		// Get and Set operations // ---> Interface Methods
		public :
			ObjectType		getStereotype() const;
			FolderPtr			getFolderI() const;
			MON::Folder		getFolderMeta() const;

			std::string			getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;

		// Relations // ---> Interface Methods
		public :
			std::set<Object>	getChildObjects( const MON::Object& meta = MON::Object() );
			std::set<Object>	getChildObjects( const std::string& strObject );
			std::set<Folder>	getChildFolders();
			std::set<FCO>	getRootFCOs();
			std::set<Atom>	getChildAtoms();
			std::set<Model>	getChildModels();

			Object				findByPath( const std::string& strPath, const std::string& strDelimiter = "/", bool bReverseOrder = false );

		// Extensions
		public :
			virtual void 		accept( Visitor* pVisitor );

		// Relations
		private :
			ObjectSet 			getChildObjectsI( const MON::Object& meta = MON::Object() );

			ObjectImpl* 		createChildObjectI( const MON::Object& meta, MON::ObjectType eType );
			FCOImpl* 			createChildFCOI( const FCO& fco, bool bAsInstance, MON::ObjectType eType );

		// Helper methods
		private :
			bool 				isChildObjectsRetrieved( const MON::Object& meta );
			void 				getChildFolders( std::set<ObjectPtr>& setSPFolders );
			void 				getRootFCOs( std::set<ObjectPtr>& setSPFCOs );
			void 				getChildObjects( const MON::Object& meta, std::set<ObjectPtr>& setSPObjects, bool bErase );

		// Event Handlers
		private :
			bool 				onRetrievedAsObjectParent( ObjectImpl* pObject, bool bCheckAll );
			void 				onReleasedAsObjectParent( ObjectImpl* pObject, bool bOnlyMemoryFree );
		// GME Event Handlers
			void 				eventPerformedI( const Event& event );
			void				onChildAdded( ObjectImpl* pChild );
			void				onChildRemoved( ObjectImpl* pChild );

		// Prohibited operations
		private :
			FolderImpl( const FolderImpl& oI ) : ObjectImpl() { }
			FolderImpl& operator = ( const FolderImpl& oI ) { return *this; }

		// Friends
			friend class ObjectImpl;
			friend class FCOImpl;
			friend class AtomImpl;
			friend class ModelImpl;
			friend class SetImpl;
			friend class ReferenceImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionEndImpl
//
//###############################################################################################################################################

	class ConnectionEndImpl
		: virtual public Util::GenRefCounted
	{
		// Type Definitions
		private :
			typedef std::map<MON::ConnectionEnd::Pair,ConnectionSetPair>		ManyConnectionLink;

		// Member variables
		private :
			ProjectImpl* 			m_pProject;
			ManyConnectionLink	m_connections;
			bool					m_bAllConnections;

		// Construction and Destruction
		protected :
			ConnectionEndImpl();
			static ConnectionEndImpl* attachI( IMgaConnPoint* spCP, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
		public :
			virtual ~ConnectionEndImpl();
			bool	setDeleted();

		// Set and Get operations
		private :
			void setProject( ProjectImpl* pProject );

		// Set and Get operations // ---> Interface Methods
		public :
			Project getProject() const;
			virtual bool isReferencePort() const = 0;

			virtual std::string		getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const = 0;
			std::string				getInfoString( const std::set<Util::InfoOption>& setOptions ) const;

		// Relations // ---> Interface Methods
		public :
			std::set<Connection>			getConnLinks( const MON::Connection& meta = MON::Connection(), const std::string& strRole = "", bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::set<Connection>			getConnLinks( const std::string& strConnection, const std::string& strRole = "", bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::set<Connection>			getInConnLinks( const MON::Connection& meta = MON::Connection(), bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::set<Connection>			getInConnLinks( const std::string& strConnection, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::set<Connection>			getOutConnLinks( const MON::Connection& meta = MON::Connection(), bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::set<Connection>			getOutConnLinks( const std::string& strConnection, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );

			std::multiset<ConnectionEnd>	getConnEndsAs( const MON::Connection& meta = MON::Connection(), const std::string& strRole = "", bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getConnEndsAs( const std::string& strConnection, const std::string& strRole = "", bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getInConnEnds( const MON::Connection& meta = MON::Connection(), bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getInConnEnds( const std::string& strConnection, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getOutConnEnds( const MON::Connection& meta = MON::Connection(), bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getOutConnEnds( const std::string& strConnection, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );

			std::multiset<ConnectionEnd>	getDirectConnEnds( const MON::Connection& meta, const std::string& strRole, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getDirectConnEnds( const std::string& strConnection, const std::string& strRole, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getDirectInConnEnds( const MON::Connection& meta, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getDirectInConnEnds( const std::string& strConnection, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getDirectOutConnEnds( const MON::Connection& meta, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getDirectOutConnEnds( const std::string& strConnection, bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );

			std::multiset<ConnectionEnd>	getConnEnds( const MON::Connection& meta = MON::Connection(), const std::string& strRole = "", bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );
			std::multiset<ConnectionEnd>	getConnEnds( const std::string& strConnection, const std::string& strRole = "", bool bIncludeRefs = true, const MON::Aspect& aspect = MON::Aspect() );

		// Extensions
		public :
			virtual void 	accept( Visitor* pVisitor );

		// Relations
		private :
			ConnectionSet	getConnectionsI( const std::string& strRole = "", const MON::Connection& meta = MON::Connection(), bool bOnlyCE = false );

		// Helper methods
		private :
			bool 			isConnectionsRetrieved( const MON::ConnectionEnd::Pair& meta );
			void			getConnections( std::set<ConnPointPtr>& setSPConnPoints );
			void			getConnections( const MON::ConnectionEnd::Pair& meta, std::set<ConnPointPtr>& setSPConnPoints, bool bErase );
			FCOImpl*		getFCOHelper() const;
			void			getDirectConnEndsRec( ConnectionEnd& ce, const MON::Connection& meta, const std::string& strRole, bool bIncludeRefs, std::multiset<ConnectionEnd>& setResult );

		// Event Handlers
		private :
			bool			onRetrievedAsConnectionEnd( ConnectionImpl* pConnection, const std::string& strRole, bool bCheck );
			void 			onReleasedAsConnectionEnd( ConnectionImpl* pConnection, const std::string& strRole, bool bOnlyMemoryFree );

		// Prohibited operations
		private :
			ConnectionEndImpl( const ConnectionEndImpl& pI ) { }
			ConnectionEndImpl& operator = ( const ConnectionEndImpl& pI ) { return *this; }

		// Friends
			friend class ConnectionImpl;
			friend class FCOImpl;
			friend class ReferencePortImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferencePortImpl
//
//###############################################################################################################################################

	class ReferencePortImpl
		: public ConnectionEndImpl
	{
		// Member Vairables
		private :
			FCOImpl* 					m_pFCO;
			ReferenceImpl*			m_pContainer;

		// Construction and Destruction
		private :
			ReferencePortImpl( ReferenceImpl* pContainer, FCOImpl* pFCO );
		public :
			~ReferencePortImpl();
			bool setDeleted();

		// Set and Get operations // ---> Interface Methods
		public :
			bool 							isReferencePort() const;
			FCO							getFCO() const;
			ReferencePortContainer 		getContainer() const;

			std::string						getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;

		// Relations // ---> Interface Methods
		public :
			ReferencePort					getParentPort() const;
			std::set<ReferencePort>		getChildPorts() const;
			std::set<ReferencePort>		getDescendantPorts() const;

		// Relations
		private :
			void							getDescendantPortsI( std::set<Reference>& setVisited, std::set<ReferencePort>& setPorts ) const;

		// Extensions
		public :
			virtual void 					accept( Visitor* pVisitor );

		// Prohibited operations
		private :
			ReferencePortImpl( const ReferencePortImpl& pI ) { }
			ReferencePortImpl& operator = ( const ReferencePortImpl& pI ) { return *this; }

		// Friends
			friend class ReferenceImpl;
			friend class ConnectionEndImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::FCOImpl
//
//###############################################################################################################################################

	class FCOImpl
		: public ObjectImpl, public ConnectionEndImpl
	{
		// Type definitions
		private :
			typedef std::pair<MON::Model,ModelImpl*>					OneModelLink;
			typedef std::map<MON::Set,SetSetPair>					ManySetLink;
			typedef std::map<MON::Reference,ReferenceSetPair>		ManyReferenceLink;
			typedef std::map<MON::Attribute,AttributeImpl*>			ManyAttributeLink;
			typedef std::set< Reference>       REFWRAPPERS;

		// Member variables
		private :
			OneModelLink			m_parentModel;
			bool					m_bAllParentModels;
			FCOImpl*				m_pType;
			bool					m_bAllTypeFCOs;
			FCOSet				m_setInstances;
			bool					m_bAllInstanceFCOs;
			FCOSet				m_setSubTypes;
			bool					m_bAllSubTypeFCOs;
			ManySetLink			m_sets;
			bool					m_bAllSets;
			ManyReferenceLink	m_references;
			bool					m_bAllReferences;
			ManyAttributeLink		m_attributes;
			bool					m_bAllAttributes;
			ReferencePortSet		m_refPorts;
			bool					m_bAllRefPorts;
			TypeInhObjectImpl*	m_pTIObject;

		// Costruction and Destruction
		protected :
			FCOImpl();
			static FCOImpl* 	attachI( IMgaFCO* spFCO, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
			static void         attachIPost( FCOImpl* pFCO );
			void				doInitialize( ProjectImpl* pProject );
		public :
			virtual 		~FCOImpl();
			bool 		setDeleted();
			static FCO attach( IMgaFCO* spFCO );

		// Get and Set operations // ---> Interface Methods
		public :
			Project		 			getProject() const;
			FCOPtr					getFCOI() const;
			MON::FCO 			getFCOMeta() const;

			virtual bool			isReferencePort() const;

			MON::Containment	getRole();
			bool					isPort( const MON::Aspect& meta = MON::Aspect() );
			bool					isPort( const std::string& strAspect );
			bool 					isVisible( const MON::Aspect& meta, bool bAsContained = false );
			bool					isVisible( const std::string& strAspect, bool bAsContained = false );

			virtual std::string		getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const = 0;
			std::string				getInfoString( const std::set<Util::InfoOption>& setOptions ) const;


		// Relations // ---> Interface Methods
		public :
			std::set<ReferencePort>	getReferencePorts( const MON::Aspect& meta = MON::Aspect() );

			std::set<Attribute>		getAttributes();
			Attribute					getAttribute( const MON::Attribute& meta );
			Attribute 					getAttribute( const std::string& strName );

			Object						getParent();
			Model						getParentModel( const MON::Model& meta = MON::Model() );
			Model						getParentModel( const std::string& strModel );
			Model						getParentModelAs( const std::string& strRole );

			std::set<Set>				getMemberOf( const MON::Set& meta = MON::Set(), const MON::Aspect& aspect = MON::Aspect() );
			std::set<Set>				getMemberOf( const std::string& strSet, const MON::Aspect& aspect = MON::Aspect() );

			std::set<Reference>		getReferredBy( const MON::Reference& meta = MON::Reference() );
			std::set<Reference>		getReferredBy( const std::string& strReference );

			TypeInhObject			getTypeInhObject() const;

			FCO						copy( const Folder& parent );
			FCO						move( const Folder& parent );
			FCO						copy( const Model& parent, const std::string strRole = "" );
			FCO						move( const Model& parent, const std::string strRole = "" );

		// Relations
		private :
			AttributeImpl*			getAttributeI( const MON::Attribute& meta );

			ModelImpl* 			getParentModelI( const MON::Model& meta = MON::Model() );

			bool					isInstance() const;
			FCOImpl*				getType();
			FCOSet				getDerivedFCOs( bool bInstance );

			ReferencePortSet	getRefPortRefsI();
			REFWRAPPERS  m_storedRefWrappers;

			SetSet					getSetsI( const MON::Set& meta = MON::Set() );
			ReferenceSet			getReferencesI( const MON::Reference& meta = MON::Reference() );

		// Helper methods
		private :
			bool					isSetsRetrieved( const MON::Set& meta );
			void					getSets( std::set<SetPtr>& setSPSets );
			void					getSets( const MON::Set& meta, std::set<SetPtr>& setSPSets, bool bErase );
			bool					isReferencesRetrieved( const MON::Reference& meta );
			void					getReferences( std::set<ReferencePtr>& setSPReferences );
			void					getReferences( const MON::Reference& meta, std::set<ReferencePtr>& setSPReferences, bool bErase );

		// Event Handlers
		private :
			bool 					onRetrievedAsModelChild( ModelImpl* pModel, bool bCheckAll );
			void 					onReleasedAsModelChild( ModelImpl* pModel, bool bOnlyMemoryFree );
			bool					onRetrievedAsType( FCOImpl* pFCO, bool bCheckAll );
			void 					onReleasedAsType( FCOImpl* pFCO, bool bOnlyMemoryFree );
			bool					onRetrievedAsDerived( FCOImpl* pFCO, bool bCheckAll );
			void 					onReleasedAsDerived( FCOImpl* pFCO, bool bOnlyMemoryFree );
			bool					onRetrievedAsMember( SetImpl* pSet, bool bCheckAll );
			void 					onReleasedAsMember( SetImpl* pSet, bool bOnlyMemoryFree );
			bool					onRetrievedAsReferred( ReferenceImpl* pReference, bool bCheckAll );
			void 					onReleasedAsReferred( ReferenceImpl* pReference, bool bOnlyMemoryFree );
			bool					onRetrievedAsReferencePort( ReferencePortImpl* pPort, bool bCheckAll );
			void 					onReleasedAsReferencePort( ReferencePortImpl* pPort, bool bOnlyMemoryFree );
		// GME Event Handlers
		public :
			void 					eventPerformedI( const Event& event );
		private :
			void					onObjectCreated();
			void					onObjectMoved( ObjectImpl* pOldParent, ObjectImpl* pNewParent );
			void					onFCOReferenced( ReferenceImpl* pReference );
			void					onFCOUnreferenced( ReferenceImpl* pReference );
			void					onFCOIncluded( SetImpl* pSet );
			void					onFCOExcluded( SetImpl* pSet );
			void 					onObjectDerived( FCOImpl* pFCO );

		// Extensions
		public :
			virtual void 			accept( Visitor* pVisitor );
			FCORegistryNode		getRegistry() const;

		// Prohibited operations
		private :
			FCOImpl( const FCOImpl& oI ) : ObjectImpl() { }
			FCOImpl& operator = ( const FCOImpl& oI ) { return *this; }

		// Friends
			friend class ObjectImpl;
			friend class AtomImpl;
			friend class FolderImpl;
			friend class ModelImpl;
			friend class SetImpl;
			friend class ConnectionImpl;
			friend class ReferenceImpl;
			friend class ConnectionEndImpl;
			friend class ReferencePortImpl;
			friend class AttributeImpl;
			friend class TypeInhObjectImpl;
			friend class TypeImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::AttributeImpl
//
//###############################################################################################################################################

	class AttributeImpl
		: public Util::GenRefCounted
	{
		// Type definitions
		private :

		// Member variables
		private :
			FCOImpl*			m_pFCO;
			AttributePtr		m_spAttribute;
			MON::Attribute	m_meta;

		// Construction and Destruction
		protected :
			AttributeImpl( IMgaAttribute* spAttribute, FCOImpl* pFCO, const MON::Attribute& meta );
			static AttributeImpl* attachI( IMgaAttribute* spAttribute, FCOImpl* pFCO, const MON::Attribute& meta );
		public :
			~AttributeImpl();
			bool setDeleted();

		// Get and Set operations // ---> Interface Methods
		public :
			Project						getProject() const;
			FCO						getFCO() const;
			AttributePtr				getAttributeI() const;
			const MON::Attribute&	getAttributeMeta() const;

			AttributeStatus			getStatus() const;

			Util::Variant				getValue() const;
			void						setValue( const Util::Variant& value, bool bTypeTolerant = true );
			long						getIntegerValue( bool bTypeTolerant = true ) const;
			void						setIntegerValue( long lValue, bool bTypeTolerant = true );
			bool						getBooleanValue( bool bTypeTolerant = true ) const;
			void						setBooleanValue( bool bValue, bool bTypeTolerant = true );
			double						getRealValue( bool bTypeTolerant = true ) const;
			void						setRealValue( double dValue, bool bTypeTolerant = true );
			std::string 					getStringValue( bool bTypeTolerant = true ) const;
			void						setStringValue( const std::string& strValue, bool bTypeTolerant = true );
			bool						isUndefined() const;
			void						clear();

		// Helper methods
		private :
			void 						checkTypes( const Util::Variant& value, bool bExc ) const;
			Util::Variant				checkTypes( Util::Variant::Type eType, const Util::Variant& value, bool bExc ) const;

		// Prohibited operations
		private :
			AttributeImpl( const AttributeImpl& oI );
			AttributeImpl& operator = ( const AttributeImpl& oI ) { return *this; }

		// Friends
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::AtomImpl
//
//###############################################################################################################################################

	class AtomImpl
		: virtual public FCOImpl
	{
		// Costruction and Destruction
		protected :
			AtomImpl();
			static AtomImpl* attachI( IMgaAtom* spAtom, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
		public :
			~AtomImpl();
			static Atom attach( IMgaAtom* spAtom );
			static Atom create( const Folder& parent, const MON::Atom& meta = MON::Atom() );
			static Atom create( const Folder& parent, const std::string& strAtom );
			static Atom create( const Folder& parent, const Atom& baseType, bool bAsInstance = true );
			static Atom create( const Model& parent, const MON::Atom& meta = MON::Atom(), const std::string& strRole = "" );
			static Atom create( const Model& parent, const std::string& strAtom, const std::string& strRole = "" );
			static Atom create( const Model& parent, const Atom& baseType, bool bAsInstance = true, const std::string& strRole = "" );
			static Atom createAs( const Model& parent, const std::string& strRole );

		// Get and Set operations // ---> Interface Methods
		public :
			ObjectType		getStereotype() const;
			AtomPtr			getAtomI() const;
			MON::Atom		getAtomMeta() const;

			std::string			getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;

		// Extensions
		public :
			virtual void 				accept( Visitor* pVisitor );
			FCOExRegistryNode		getRegistry() const;

		// Prohibited Operations
		private :
			AtomImpl( const AtomImpl& oI ) : FCOImpl() { }
			AtomImpl& operator = ( const AtomImpl& oI ) { return *this; }

		// Friends
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ModelImpl
//
//###############################################################################################################################################

	class ModelImpl
		: virtual public FCOImpl
	{
		// Type definitions
		private :
			typedef std::map<MON::FCO,FCOSetPair>		ManyFCOLink;

		// Member variables
		private :
			ManyFCOLink		m_childFCOs;
			bool				m_bAllChildFCOs;

		// Costruction and Destruction
		protected :
			ModelImpl();
			static ModelImpl* attachI( IMgaModel* spModel, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
		public :
			~ModelImpl();
			bool			setDeleted();
			static Model 	attach( IMgaModel* spModel );
			static Model 	create( const Folder& parent, const MON::Model& meta = MON::Model() );
			static Model 	create( const Folder& parent, const std::string& strModel );
			static Model 	create( const Folder& parent, const Model& baseType, bool bAsInstance = true );
			static Model 	create( const Model& parent, const MON::Model& meta = MON::Model(), const std::string& strRole = "" );
			static Model 	create( const Model& parent, const std::string& strModel, const std::string& strRole = "" );
			static Model 	create( const Model& parent, const Model& baseType, bool bAsInstance = true, const std::string& strRole = "" );
			static Model 	createAs( const Model& parent, const std::string& strRole );

		// Get and Set operations // ---> Interface Methods
		public :
			ObjectType		getStereotype() const;
			ModelPtr			getModelI() const;
			MON::Model		getModelMeta() const;

			std::string			getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;

		// Relations // ---> Interface Methods
		public :
			std::set<FCO>			getChildFCOs( const MON::FCO& meta = MON::FCO(), const MON::Aspect& aspect = MON::Aspect() );
			std::set<FCO> 			getChildFCOs( const std::string& strFCO, const MON::Aspect& aspect = MON::Aspect() );
			std::set<FCO> 			getChildFCOsAs( const std::string& strRole, const MON::Aspect& aspect = MON::Aspect() );
			std::set<Atom>			getChildAtoms( const MON::Aspect& aspect = MON::Aspect() );
			std::set<Model>			getChildModels( const MON::Aspect& aspect = MON::Aspect() );
			std::set<Set>				getChildSets( const MON::Aspect& aspect = MON::Aspect() );
			std::set<Reference>		getChildReferences( const MON::Aspect& aspect = MON::Aspect() );
			std::set<Connection>	getChildConnections( const MON::Aspect& aspect = MON::Aspect() );

			FCO						findByPath( const std::string& strPath, const std::string& strDelimiter = "/", bool bReverseOrder = false );
			std::set<FCO>			findByKind( const MON::Object& meta );
			std::set<FCO>			findByKind( const std::string& strKind );

		// Extensions
		public :
			virtual void 				accept( Visitor* pVisitor );
			ModelRegistryNode		getRegistry() const;

		// Relations
		private :
			FCOSet	 	getChildFCOsI( const MON::FCO& meta = MON::FCO() );

			FCOImpl* 		createChildFCOI( const std::string& strRole, MON::ObjectType eType );
			FCOImpl* 		createChildFCOI( const MON::FCO& meta, const std::string& strRole, MON::ObjectType eType );
			FCOImpl* 		createChildFCOI( const BON::FCO& fco, bool bAsInstance, const std::string& strRole, MON::ObjectType eType );
			std::set<FCO>	findByKindHlp( const MON::FCO& meta );

		// Helper methods
		private :
			bool			isChildFCOsRetrieved( const MON::FCO& meta );
			void			getChildFCOs( std::set<FCOPtr>& setSPFCOs );
			void			getChildFCOs( const MON::FCO& meta, std::set<FCOPtr>& setSPFCOs, bool bErase );

		// Event Handlers
		private :
			bool			onRetrievedAsFCOParent( FCOImpl* pFCO, bool bCheckAll );
			void			onReleasedAsFCOParent( FCOImpl* pFCO, bool bOnlyMemoryFree );
		// GME Event Handlers
		public :
			void 			eventPerformedI( const Event& event );
		private :
			void			onChildAdded( FCOImpl* pChild );
			void			onChildRemoved( FCOImpl* pChild );
			void 			onObjectDerived( FCOImpl* pFCO );

		// Prohibited operations
		private :
			ModelImpl( const ModelImpl& oI ) : FCOImpl() { }
			ModelImpl& operator = ( const ModelImpl& oI ) { return *this; }

		// Friends
			friend class FCOImpl;
			friend class AtomImpl;
			friend class ModelImpl;
			friend class SetImpl;
			friend class ReferenceImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::SetImpl
//
//###############################################################################################################################################

	class SetImpl
		: virtual public FCOImpl
	{
		// Type definitions
		private :
			typedef std::map<MON::FCO,FCOSetPair>		ManyFCOLink;

		// Member variables
		private :
			ManyFCOLink		m_memberFCOs;
			bool				m_bAllMemberFCOs;

		// Costruction and Destruction
		protected :
			SetImpl();
			static SetImpl* attachI( IMgaSet* spSet, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
		public :
			~SetImpl();
			bool setDeleted();
			static Set attach( IMgaSet* spSet );
			static Set create( const Folder& parent, const MON::Set& meta = MON::Set() );
			static Set create( const Folder& parent, const std::string& strSet );
			static Set create( const Folder& parent, const Set& baseType, bool bAsInstance = true );
			static Set create( const Model& parent, const MON::Set& meta = MON::Set(), const std::string& strRole = "" );
			static Set create( const Model& parent, const std::string& strSet, const std::string& strRole = "" );
			static Set create( const Model& parent, const Set& baseType, bool bAsInstance = true, const std::string& strRole = "" );
			static Set createAs( const Model& parent, const std::string& strRole );

		// Get and Set operations // ---> Interface Methods
		public :
			ObjectType	getStereotype() const;
			SetPtr			getSetI() const;
			MON::Set		getSetMeta() const;

			std::string		getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;

		// Relations // ---> Interface Methods
		public :
			std::set<FCO>	getMembers( const MON::FCO& meta = MON::FCO(), const MON::Aspect& aspect = MON::Aspect() );
			std::set<FCO>	getMembers( const std::string& strFCO, const MON::Aspect& aspect = MON::Aspect() );

			void				addMember( const BON::FCO& fco );
			void				removeMember( const BON::FCO& fco );

		// Extensions
		public :
			virtual void 				accept( Visitor* pVisitor );
			FCOExRegistryNode		getRegistry() const;

		// Relations
		private :
			FCOSet	 	getMemberFCOsI( const MON::FCO& meta = MON::FCO() );

			void			addMemberI( const BON::FCO& fco );
			void			removeMemberI( const BON::FCO& fco );

		// Helper methods
		private :
			bool			isMemberFCOsRetrieved( const MON::FCO& meta );
			void			getMemberFCOs( std::set<FCOPtr>& setSPFCOs );
			void			getMemberFCOs( const MON::FCO& meta, std::set<FCOPtr>& setSPFCOs, bool bErase );

		// Event Handlers
		private :
			bool			onRetrievedAsSet( FCOImpl* pFCO, bool bCheckAll );
			void			onReleasedAsSet( FCOImpl* pFCO, bool bOnlyMemoryFree );
		// GME Event Handlers
		public :
			virtual void 			eventPerformedI( const Event& event );
		private :
			void			onRelationChanged();

		// Prohibited operations
		private :
			SetImpl( const SetImpl& oI ) : FCOImpl() { }
			SetImpl& operator = ( const SetImpl& oI ) { return *this; }

		// Friends
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferenceImpl
//
//###############################################################################################################################################

	class ReferenceImpl
		: virtual public FCOImpl
	{
		// Type definitions
		private :
			typedef std::pair<MON::FCO,FCOImpl*>		OneFCOLink;
			typedef std::map<FCOImpl*,ReferencePortImpl*>	ManyPortLink;

		// Member variables
		private :
			OneFCOLink						m_referredFCO;
			bool								m_bAllReferredFCOs;
			ManyPortLink						m_childPorts;
			bool								m_bAllChildPorts;
			ReferencePortContainerImpl*		m_pContainer;

		// Costruction and Destruction
		protected :
			ReferenceImpl();
			static ReferenceImpl* attachI( IMgaReference* spReference, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
		public :
			~ReferenceImpl();
			bool setDeleted();
			static Reference attach( IMgaReference* spReference );
			static Reference create( const Folder& parent, const MON::Reference& meta = MON::Reference() );
			static Reference create( const Folder& parent, const std::string& strReference );
			static Reference create( const Folder& parent, const Reference& baseType, bool bAsInstance = true );
			static Reference create( const Model& parent, const MON::Reference& meta = MON::Reference(), const std::string& strRole = "" );
			static Reference create( const Model& parent, const std::string& strReference, const std::string& strRole = "" );
			static Reference create( const Model& parent, const Reference& baseType, bool bAsInstance = true, const std::string& strRole = "" );
			static Reference createAs( const Model& parent, const std::string& strRole );

		// Get and Set operations // --->Interface Methods
		public :
			ObjectType			getStereotype() const;
			ReferencePtr			getReferenceI() const;
			MON::Reference		getReferenceMeta() const;

			std::string				getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;

		// Relations // --->Interface Methods
		public :
			FCO						getReferred( const MON::FCO& meta = MON::FCO() );
			FCO						getReferred( const std::string& strFCO );
			void						setReferred( const FCO& fco );

			ReferencePortContainer	getRefPortContainer();

		// Extensions
		public :
			virtual void 				accept( Visitor* pVisitor );
			FCOExRegistryNode		getRegistry() const;

		// Relations
		private :
			FCOImpl*				getReferredFCOI( const MON::FCO& meta = MON::FCO() );
			void					setReferredFCOI( const BON::FCO& fco );

			ReferencePortSet		getRefPorts();
			ReferencePortImpl*	getRefPort( FCOImpl* pFCO );

		// Helper methods
		private :
			bool					createRefPort( FCOImpl* pFCO );

		// Event Handlers
		private :
			bool					onRetrievedAsReference( FCOImpl* pFCO, bool bCheckAll );
			void					onReleasedAsReference( FCOImpl* pFCO, bool bOnlyMemoryFree );
			void					onReleasedAsPortContainer( FCOImpl* pFCO, bool bOnlyMemoryFree );
		// GME Event Handlers
		public :
			virtual void 			eventPerformedI( const Event& event );
		private :
			void					onRelationChanged();

		// Prohibited operations
		private :
			ReferenceImpl( const ReferenceImpl& oI ) : FCOImpl() { }
			ReferenceImpl& operator = ( const ReferenceImpl& oI ) { return *this; }

		// Friends
			friend class FCOImpl;
			friend class ConnectionEndImpl;
			friend class ReferencePortContainerImpl;
			friend class ReferencePortImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionImpl
//
//###############################################################################################################################################

	class ConnectionImpl
		: virtual public FCOImpl
	{
		// Type definitions
		private :
			typedef std::map<MON::Connection::Pair,ConnectionEndImpl*>	ManyFCOLink;

		// Member variables
		private :
			ManyFCOLink	m_ends;
			bool 			m_bAllEnds;
			typedef std::set< Reference>    REFWRAPPERS;
			typedef std::set< FCO>          FCOWRAPPERS;
			REFWRAPPERS                     m_refWrappers;
			FCOWRAPPERS                     m_fcoWrappers;

		// Costruction and Destruction
		protected :
			ConnectionImpl();
			static ConnectionImpl* attachI( IMgaConnection* spConnection, ProjectImpl* pProject = NULL, const MON::Object& meta = MON::Object() );
		public :
			~ConnectionImpl();
			bool setDeleted();
			static Connection attach( IMgaConnection* spConnection);
			static Connection create( const Model& parent, const std::set<Connection::Pair>& ends, const MON::Connection& meta = MON::Connection(), const std::string& strRole = "" );
			static Connection create( const Model& parent, const std::set<Connection::Pair>& ends, const std::string& strConnection, const std::string& strRole = "" );
			static Connection create( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const MON::Connection& meta = MON::Connection(), const std::string& strRole = "" );
			static Connection create( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const std::string& strConnection, const std::string& strRole = "" );
			static Connection createAs( const Model& parent, const std::set<Connection::Pair>& ends, const std::string& strRole );
			static Connection createAs( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const std::string& strRole );
		// Get and Set operations // ---> Interface Methods
		public :
			ObjectType			getStereotype() const;
			ConnectionPtr			getConnectionI() const;
			MON::Connection		getConnectionMeta() const;

			std::string				getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;

		// Relations // ---> Interface Methods
		public :
			std::multiset<ConnectionEnd> 	getConnEnds( const MON::FCO& meta = MON::FCO() );
			std::multiset<ConnectionEnd> 	getConnEnds( const std::string& strFCO );
			ConnectionEnd					getConnEnd( const std::string& strRole, const MON::FCO& meta = MON::FCO() );
			ConnectionEnd					getConnEnd( const std::string& strRole, const std::string& strFCO );
			ConnectionEnd					getSrc( const MON::FCO& meta = MON::FCO() );
			ConnectionEnd					getSrc( const std::string& strFCO );
			ConnectionEnd					getDst( const MON::FCO& meta = MON::FCO() );
			ConnectionEnd					getDst( const std::string& strFCO );

		// Extensions
		public :
			virtual void 					accept( Visitor* pVisitor );
			ConnectionRegistryNode		getRegistry() const;

		// Relations
		private :
			ConnectionEndImpl*		getConnectionEndI( const std::string& strRole = "", const MON::FCO& meta = MON::FCO() );
			static ConnectionImpl*	createI( const Model& parent, const MON::Containment& meta, const std::set<Connection::Pair>& ends );

		// Event Handlers
		private :
			bool					onRetrievedAsConnection( ConnectionEndImpl* pCE, const std::string& strRole, bool bCheckAll );
			void					onReleasedAsConnection( ConnectionEndImpl* pCE, const std::string& strRole, bool bOnlyFreeMemory );
		// GME Event Handlers
		public :
			virtual void 			eventPerformedI( const Event& event );
		private :
			void					onObjectCreated();

		// Prohibited operations
		private :
			ConnectionImpl( const ConnectionImpl& oI ) : FCOImpl() { }
			ConnectionImpl& operator = ( const ConnectionImpl& oI ) { return *this; }

		// Friends
			friend class ConnectionEndImpl;
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferencePortContainerImpl
//
//###############################################################################################################################################

	class ReferencePortContainerImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			ReferenceImpl* m_pReference;

		// Construction and Destruction
		private :
			ReferencePortContainerImpl( ReferenceImpl* pReference );

		// Relations // ---> Interface Methods
		public :
			Project 					getProject() const;
			Reference					getReference() const;

			std::set<ReferencePort>	getReferencePorts();
			ReferencePort				getReferencePort( const FCO& fco );

		// Friends
			friend class ReferenceImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::TypeInhObjectImpl
//
//###############################################################################################################################################

	class TypeInhObjectImpl
		: public Util::GenRefCounted
	{
		// Member Variables
		private :
			FCOImpl* m_pFCO;

		// Construction and Destruction
		private :
			TypeInhObjectImpl( FCOImpl* pFCO );
		public :
			bool setDeleted();

		// Get and Set Operations // ---> Interface Methods
		public :
			Project 					getProject() const;
			FCO						getFCO() const;

			bool						isInstance() const;

		// Relations // ---> Interface Methods
		public :
			Type						getType();

		// Friends
			friend class TypeImpl;
			friend class InstanceImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::InstanceImpl
//
//###############################################################################################################################################

	class InstanceImpl
		: public TypeInhObjectImpl
	{
		// Construction and Destruction
		private :
			InstanceImpl( FCOImpl* pFCO );

		// Friends
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::TypeImpl
//
//###############################################################################################################################################

	class TypeImpl
		: public TypeInhObjectImpl
	{
		// Construction and Destruction
		private :
			TypeImpl( FCOImpl* pFCO );

		// Relations // ---> Interface Methods
		public :
			std::set<Type>				getSubTypes();
			std::set<Instance>			getInstance();
			std::set<TypeInhObject>	getDerivedObjects();

		// Friends
			friend class FCOImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::FCORegistryNodeImpl
//
//###############################################################################################################################################

	class FCORegistryNodeImpl
		: public RegistryNodeImpl
	{
		// Construction and Destruction
		private :
			FCORegistryNodeImpl( FCOImpl* pObject );

		// Members
		public :
			COLORREF					getColor() const;
			void							setColor( COLORREF color );

			COLORREF					getNameColor() const;
			void							setNameColor( COLORREF color );

			bool							getNameEnabled() const;
			void							setNameEnabled( bool bEnabled );

			std::string						getHelpURL() const;
			void 							setHelpURL( const std::string& strURL );

			std::set<AutoRouterPref>	getInAutoRouterPref() const;
			void							setInAutoRouterPref( const std::set<AutoRouterPref>& setPrefs );

			std::set<AutoRouterPref>	getOutAutoRouterPref() const;
			void							setOutAutoRouterPref( const std::set<AutoRouterPref>& setPrefs );

		// Friends
			friend class RegistryNodeImpl;
			friend class FCOExRegistryNodeImpl;
			friend class ConnectionRegistryNodeImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::FCOExRegistryNodeImpl
//
//###############################################################################################################################################

	class FCOExRegistryNodeImpl
		: public FCORegistryNodeImpl
	{
		// Construction and Destruction
		private :
			FCOExRegistryNodeImpl( FCOImpl* pObject );

		// Members
		public :
			Point							getLocation( const MON::Aspect& aspect = MON::Aspect() ) const;
			void							setLocation( const Point& point, const MON::Aspect& aspect = MON::Aspect() );
			Point							getLocation( const std::string& strAspect ) const;
			void							setLocation( const Point& point, const std::string& strAspect );

			NamePosition					getNamePosition() const;
			void							setNamePosition( NamePosition pos );

			unsigned short				getNameWrap() const;
			void							setNameWrap( unsigned short usWrap );

			bool							getHotspotEnabled() const;
			void							setHotspotEnabled( bool bEnabled );

			bool							getTypeNameEnabled() const;
			void							setTypeNameEnabled( bool bEnabled );

			bool							getTypeInfoEnabled() const;
			void							setTypeInfoEnabled( bool bEnabled );

			std::string						getDecorator() const;
			void							setDecorator( const std::string& strName );

			std::string						getIcon() const;
			void							setIcon( const std::string& strName ) const;

			std::string						getPortIcon() const;
			void							setPortIcon( const std::string& strName ) const;

			std::string						getSubTypeIcon() const;
			void							setSubTypeIcon( const std::string& strName ) const;

			std::string						getInstanceIcon() const;
			void							setInstanceIcon( const std::string& strName ) const;

		// Friends
			friend class RegistryNodeImpl;
			friend class ModelRegistryNodeImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ModelRegistryNodeImpl
//
//###############################################################################################################################################

	class ModelRegistryNodeImpl
		: public FCOExRegistryNodeImpl
	{
		// Construction and Destruction
		private :
			ModelRegistryNodeImpl( ModelImpl* pObject );

		// Members
		public :
			COLORREF		getBorderColor() const;
			void				setBorderColor( COLORREF color );

			COLORREF		getBackgroundColor() const;
			void				setBackgroundColor( COLORREF color );

			COLORREF		getPortNameColor() const;
			void 				setPortNameColor( COLORREF color );

		// Friends
			friend class RegistryNodeImpl;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionRegistryNodeImpl
//
//###############################################################################################################################################

	class ConnectionRegistryNodeImpl
		: public FCORegistryNodeImpl
	{
		// Construction and Destruction
		private :
			ConnectionRegistryNodeImpl( ConnectionImpl* pObject );

		// Members
		public :
			LineType			getLineType() const;
			void				setLineType( LineType eType );

			LineEndType		getSrcLineEndType() const;
			void				setSrcLineEndType( LineEndType eType );

			LineEndType		getDstLineEndType() const;
			void				setDstLineEndType( LineEndType eType );

			std::string			getLabel() const;
			void 				setLabel( const std::string& strFormat );

			std::string			getSrcLabel1() const;
			void 				setSrcLabel1( const std::string& strFormat );

			std::string			getSrcLabel2() const;
			void 				setSrcLabel2( const std::string& strFormat );

			std::string			getDstLabel1() const;
			void 				setDstLabel1( const std::string& strFormat );

			std::string			getDstLabel2() const;
			void 				setDstLabel2( const std::string& strFormat );

		// Friends
			friend class RegistryNodeImpl;
	};

} // namespace BON

#endif // BONImpl_h