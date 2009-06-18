//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	MONImpl.cpp
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
#include "MONImpl.h"

#include "Utils.h"
#include "Exceptions.h"

inline std::string _ref2str( long lRef )
{
	char chBuffer[ 50 ];
	sprintf( chBuffer, "%d", lRef );
	return chBuffer;
}

inline std::string _slashes( const std::string& str )
{
	std::string str2 = str;
	for ( int i = 0 ; i < str2.size() ; i++ )
		if ( str2[ i ] == '\\' )
			str2[ i ] = '/';
	return str2;
}

inline MON::ProjectImpl* _getProject( IMgaMetaBase* spObject,  MON::ProjectImpl* pProject )
{
	if ( pProject )
		return pProject;
	MON::ProjectPtr spProject;
	COMTHROW( spObject->get_MetaProject( spProject.Addr() ) );
	return MON::ProjectImpl::attach( spProject );
}

namespace MON
{

//###############################################################################################################################################
//
// 	C L A S S : MON::ProjectImpl
//
//###############################################################################################################################################

	ProjectImpl::ProjectMap ProjectImpl::mapProjects;

	ProjectImpl::ProjectImpl( IMgaMetaProject* spProject )
		: Util::GenRefCounted( true, NULL ), m_spProject( spProject )
	{
		for ( int iType = OT_Model ; iType <= OT_Part ; iType++ )
			m_mapObjectsByType.insert( Type2ObjectsMap::value_type( iType, ProjectImpl::ObjectSet() ) );

		mapProjects.insert( ProjectMap::value_type( spProject, this ) );
	}

	ProjectImpl* ProjectImpl::attach( IMgaMetaProject* spProject )
	{
		ProjectImpl::ProjectMap::iterator it = mapProjects.find( spProject );
		if ( it != mapProjects.end() )
			return it->second;

		ProjectImpl* pProject = new ProjectImpl( spProject );

		FolderPtr spRootFolder;
		COMTHROW( spProject->get_RootFolder( spRootFolder.Addr() ) );
		pProject->m_pRootFolder = pProject->processFolder( spRootFolder );

		const ProjectImpl::ObjectSet& setRefs = pProject->getObjects( OT_Reference );
		for ( ProjectImpl::ObjectSet::const_iterator itRef = setRefs.begin() ; itRef != setRefs.end() ; ++itRef )
			pProject->processReference( (ReferenceImpl*) *itRef );

		const ProjectImpl::ObjectSet& setSets = pProject->getObjects( OT_Set );
		for ( ProjectImpl::ObjectSet::const_iterator itSet = setSets.begin() ; itSet != setSets.end() ; ++itSet )
			pProject->processSet( (SetImpl*) *itSet );

		const ProjectImpl::ObjectSet& setConns = pProject->getObjects( OT_Connection );
		for ( ProjectImpl::ObjectSet::const_iterator itConn = setConns.begin() ; itConn != setConns.end() ; ++itConn )
			pProject->processConnection( (ConnectionImpl*) *itConn );

		const ProjectImpl::ObjectSet& setMods = pProject->getObjects( OT_Model );
		for ( ProjectImpl::ObjectSet::const_iterator itMod = setMods.begin() ; itMod != setMods.end() ; ++itMod )
			pProject->processModel( (ModelImpl*) *itMod );

		return pProject;
	}

	FolderImpl* ProjectImpl::processFolder( const FolderPtr& spFolder )
	{
		long lRef;
		COMTHROW( spFolder->get_MetaRef( &lRef ) );
		if ( m_mapObjectsByRef.find( lRef ) != m_mapObjectsByRef.end() )
			return ( FolderImpl* ) m_mapObjectsByRef[ lRef ];

		FolderImpl* pFolder = FolderImpl::attachI( spFolder, this );
		insertObject( pFolder );

		Util::ComPtr<IMgaMetaFolders> spFolders;
		COMTHROW( spFolder->get_LegalChildFolders( spFolders.Addr() ) );
		MGACOLL_ITERATE( IMgaMetaFolder, spFolders.p ) {
			FolderImpl* pChild = processFolder( MGACOLL_ITER.p );
			m_setFolderContainments.insert( new FolderContainmentImpl( pFolder, pChild ) );
		} MGACOLL_ITERATE_END;

		Util::ComPtr<IMgaMetaFCOs> spFCOs;
		COMTHROW( spFolder->get_LegalRootObjects( spFCOs.Addr() ) );
		MGACOLL_ITERATE( IMgaMetaFCO, spFCOs.p ) {
			FCOImpl* pChild = processFCO( MGACOLL_ITER.p );
			m_setFolderContainments.insert( new FolderContainmentImpl( pFolder, pChild ) );
		} MGACOLL_ITERATE_END;

		return pFolder;
	}

	FCOImpl* ProjectImpl::processFCO( const FCOPtr& spFCO )
	{
		long lRef;
		COMTHROW( spFCO->get_MetaRef( &lRef ) );
		if ( m_mapObjectsByRef.find( lRef ) != m_mapObjectsByRef.end() )
			return ( FCOImpl* ) m_mapObjectsByRef[ lRef ];

		objtype_enum eType;
		COMTHROW( spFCO->get_ObjType( &eType ) );
		FCOImpl* pFCO;
		switch ( eType ) {
			case OBJTYPE_MODEL : {
				CComQIPtr<IMgaMetaModel> spModel = spFCO.p;
				pFCO = processModel( spModel.p );
				break;
			 }
			case OBJTYPE_ATOM : {
				CComQIPtr<IMgaMetaAtom> spAtom = spFCO.p;
				pFCO = processAtom( spAtom.p );
				break;
			}
			case OBJTYPE_CONNECTION : {
				CComQIPtr<IMgaMetaConnection> spConnection = spFCO.p;
				pFCO = processConnection( spConnection.p );
				break;
			}
			case OBJTYPE_REFERENCE : {
				CComQIPtr<IMgaMetaReference> spReference = spFCO.p;
				pFCO = processReference( spReference.p );
				break;
			}
			case OBJTYPE_SET : {
				CComQIPtr<IMgaMetaSet> spSet = spFCO.p;
				pFCO = processSet( spSet.p );
				break;
			}
		}

		Util::ComPtr<IMgaMetaAttributes> spAttributes;
		COMTHROW( spFCO->get_Attributes( spAttributes.Addr() ) );
		MGACOLL_ITERATE( IMgaMetaAttribute, spAttributes.p ) {
			Util::ComPtr<IMgaMetaFCOs> spFCOs;
			COMTHROW( MGACOLL_ITER->get_UsedIn( spFCOs.Addr() ) );
			long lCount = 0;
			COMTHROW( spFCOs->get_Count( &lCount ) );
			AttributeImpl* pAttribute = processAttribute( MGACOLL_ITER.p, ( lCount == 1 ) ? pFCO : NULL );
			if ( lCount == 1 )
				pFCO->m_setAttributes.insert( pAttribute );
			else
				m_setAttributeAggregations.insert( new AttributeAggregationImpl( pFCO, pAttribute ) );
		} MGACOLL_ITERATE_END;

		return pFCO;
	}

	AtomImpl* ProjectImpl::processAtom( const AtomPtr& spAtom )
	{
		AtomImpl* pAtom = AtomImpl::attachI( spAtom, this );
		insertObject( pAtom );
		return pAtom;
	}

	ModelImpl* ProjectImpl::processModel( const ModelPtr& spModel )
	{
		ModelImpl* pModel = ModelImpl::attachI( spModel, this );
		insertObject( pModel );

		Util::ComPtr<IMgaMetaRoles> spRoles;
		COMTHROW( spModel->get_Roles( spRoles.Addr() ) );
		MGACOLL_ITERATE( IMgaMetaRole, spRoles.p ) {
			FCOPtr spFCO;
			COMTHROW( MGACOLL_ITER->get_Kind( spFCO.Addr() ) );
			FCOImpl* pFCO = processFCO( spFCO );
			ContainmentImpl* pContainment = ContainmentImpl::attachI( MGACOLL_ITER, this );
			pContainment->m_pParent = pModel;
			pContainment->m_pChild = pFCO;
			insertObject( pContainment );
		} MGACOLL_ITERATE_END;

		return pModel;
	}

	void ProjectImpl::processModel( ModelImpl* pModel )
	{
		Util::ComPtr<IMgaMetaAspects> spAspects;
		COMTHROW( pModel->getModelI()->get_Aspects( spAspects.Addr() ) );
		MGACOLL_ITERATE( IMgaMetaAspect, spAspects.p ) {
			AspectImpl* pAspect = processAspect( MGACOLL_ITER );
			ModelInAspectImpl* pModelInAspect = new ModelInAspectImpl( pAspect, pModel );
			m_setModelInAspects.insert( pModelInAspect );
		} MGACOLL_ITERATE_END;
	}

	ConnectionImpl* ProjectImpl::processConnection( const ConnectionPtr& spConnection )
	{
		ConnectionImpl* pConnection = ConnectionImpl::attachI( spConnection, this );
		insertObject( pConnection );
		return pConnection;
	}

	void ProjectImpl::processConnection( ConnectionImpl* pConnection )
	{
		Util::ComPtr<IMgaMetaConnJoints> spJoints;
		COMTHROW( pConnection->getConnectionI()->get_Joints( spJoints.Addr() ) );

		long lJointNum;
		COMTHROW( spJoints->get_Count( &lJointNum ) );
		pConnection->m_bBidirectional = lJointNum == 2;	// WARNING

		int i = 0;
		MGACOLL_ITERATE( IMgaMetaConnJoint, spJoints.p ) {
			Util::ComPtr<IMgaMetaConnJoint> spJoint = MGACOLL_ITER.p;

			ConnectionSpecImpl* pSpec = new ConnectionSpecImpl( pConnection, i++ );
			pConnection->m_setConnSpecs.insert( pSpec );

			Util::ComPtr<IMgaMetaPointerSpecs> spSpecs;
			COMTHROW( spJoint->get_PointerSpecs( spSpecs.Addr() ) );

			MGACOLL_ITERATE( IMgaMetaPointerSpec, spSpecs.p ) {
				Util::ComPtr<IMgaMetaPointerSpec> spSpec = MGACOLL_ITER.p;
				CComBSTR bstrSpecName;
				COMTHROW( spSpec->get_Name( &bstrSpecName ) );

				ConnectionRoleImpl* pRole = new ConnectionRoleImpl( pSpec, Util::Copy( bstrSpecName ) );
				pSpec->m_setRoles.insert( pRole );

				Util::ComPtr<IMgaMetaPointerItems> spItems;
				COMTHROW( spSpec->get_Items( spItems.Addr() ) );

				std::set<ContainmentImpl*> setRolesFull;

				MGACOLL_ITERATE( IMgaMetaPointerItem, spItems.p ) {
					CComBSTR bstrDesc;
					COMTHROW( MGACOLL_ITER->get_Desc( &bstrDesc ) );
					std::set<ContainmentImpl*> setRoles = getLocalRoles( pConnection, Util::Copy( bstrDesc ) );
					for ( std::set<ContainmentImpl*>::iterator it = setRoles.begin() ; it != setRoles.end() ; ++it )
						setRolesFull.insert( *it );
				} MGACOLL_ITERATE_END;

				for ( std::set<ContainmentImpl*>::iterator it = setRolesFull.begin() ; it != setRolesFull.end() ; ++it ) {
					m_setConnectionEnds.insert( new ConnectionEndImpl( pRole, *it ) );
				}

			} MGACOLL_ITERATE_END;

		} MGACOLL_ITERATE_END;
	}

	ReferenceImpl* ProjectImpl::processReference( const ReferencePtr& spReference )
	{
		ReferenceImpl* pReference = ReferenceImpl::attachI( spReference, this );
		insertObject( pReference );
		return pReference;
	}

	void ProjectImpl::processReference( ReferenceImpl* pReference )
	{
		Util::ComPtr<IMgaMetaPointerSpec> spSpec;
		COMTHROW( pReference->getReferenceI()->get_RefSpec( spSpec.Addr() ) );
		Util::ComPtr<IMgaMetaPointerItems> spItems;
		COMTHROW( spSpec->get_Items( spItems.Addr() ) );
		MGACOLL_ITERATE( IMgaMetaPointerItem, spItems.p ) {
			CComBSTR bstrDesc;
			COMTHROW( MGACOLL_ITER->get_Desc( &bstrDesc ) );
			FCOImpl * refd = (FCOImpl *) findByName( Util::Copy( bstrDesc));//m_mapObjectsByName.find( name );
			if ( refd)
				m_setReferenceAssocs.insert( new ReferenceAssocImpl( pReference, refd) );
		} MGACOLL_ITERATE_END;
	}

	SetImpl* ProjectImpl::processSet( const SetPtr& spSet )
	{
		SetImpl* pSet = SetImpl::attachI( spSet, this );
		insertObject( pSet );
		return pSet;
	}

	void ProjectImpl::processSet( SetImpl* pSet )
	{
		Util::ComPtr<IMgaMetaPointerSpec> spSpec;
		COMTHROW( pSet->getSetI()->get_MemberSpec( spSpec.Addr() ) );
		Util::ComPtr<IMgaMetaPointerItems> spItems;
		COMTHROW( spSpec->get_Items( spItems.Addr() ) );
		MGACOLL_ITERATE( IMgaMetaPointerItem, spItems.p ) {
			CComBSTR bstrDesc;
			COMTHROW( MGACOLL_ITER->get_Desc( &bstrDesc ) );
			std::set<ContainmentImpl*> setRoles = getLocalRoles( pSet, Util::Copy( bstrDesc ) );
			for ( std::set<ContainmentImpl*>::iterator it = setRoles.begin() ; it != setRoles.end() ; it++ )
				m_setSetMemberships.insert( new SetMembershipImpl( pSet, *it ) );
		} MGACOLL_ITERATE_END;
	}

	AttributeImpl*	ProjectImpl::processAttribute( const AttributePtr& spAttribute, FCOImpl* pOwner )
	{
		long lRef;
		COMTHROW( spAttribute->get_MetaRef( &lRef ) );
		if ( m_mapObjectsByRef.find( lRef ) != m_mapObjectsByRef.end() )
			return ( AttributeImpl* ) m_mapObjectsByRef[ lRef ];

		AttributeImpl* pAttribute = AttributeImpl::attachI( spAttribute, this, pOwner );
		insertObject( pAttribute );
		return pAttribute;
	}

	AspectImpl* ProjectImpl::processAspect( const AspectPtr& spAspect )
	{
		long lRef;
		COMTHROW( spAspect->get_MetaRef( &lRef ) );
		if ( m_mapObjectsByRef.find( lRef ) != m_mapObjectsByRef.end() )
			return ( AspectImpl* ) m_mapObjectsByRef[ lRef ];

		AspectImpl* pAspect = AspectImpl::attachI( spAspect, this );
		insertObject( pAspect );

		Util::ComPtr<IMgaMetaParts> spParts;
		COMTHROW( spAspect->get_Parts( spParts.Addr() ) );
		MGACOLL_ITERATE( IMgaMetaPart, spParts.p ) {
			ContainmentPartImpl* pPart = ContainmentPartImpl::attachI( MGACOLL_ITER, this );
			ContainmentPtr spRole;
			COMTHROW( MGACOLL_ITER->get_Role( spRole.Addr() ) );
			pPart->m_pContainment = ContainmentImpl::attachI( spRole, this );
			pPart->m_pAspect = pAspect;
			insertObject( pPart );
		} MGACOLL_ITERATE_END;

		return pAspect;
	}

	void ProjectImpl::insertObject( ObjectImpl* pObject )
	{
		m_mapObjectsByRef[ pObject->getRef() ] = pObject;
		ObjectType eType = pObject->getType();
		m_mapObjectsByType[ eType ].insert( pObject );

		if ( eType >= OT_Model && eType <= OT_Folder || eType == OT_Aspect )
			m_mapObjectsByName[ pObject->getName() ] = pObject;
	}

	std::set<ContainmentImpl*> ProjectImpl::getGlobalRoles( const std::string& strDescIn ) const
	{
		std::set<ContainmentImpl*> setRoles;
		int iPos = strDescIn.find( " " );
		std::string strDesc = ( iPos == std::string::npos ) ? strDescIn : strDescIn.substr( 0, iPos );
		for ( std::set<ObjectImpl*>::const_iterator it = ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].begin() ; it != ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].end() ; ++it ) {
			if ( ( ( ContainmentImpl*) (*it) )->getChild()->getName() == strDesc )
				setRoles.insert( (ContainmentImpl*) *it );
		}
		return getRoles( setRoles, ( iPos == std::string::npos ) ? "" : strDescIn.substr( iPos + 1 ), false );
	}

	std::set<ContainmentImpl*> ProjectImpl::getLocalRoles( FCOImpl* pKind, const std::string& strDescIn ) const
	{
		//if invoked from processConnection
		// pKind is a connection so it may be contained (usually-normally) by models only
		//       since it doesn't have too much sense to have a connection in a folder
		// strDescIn is an 
		//       "src_fco" or
		//       a pair like "model port"
		//       a pair like "modelreference port"
		//       a pair like "transitivemodelreference port"

		// "setModels" will contain the models pKind may be part of 
		std::set<ModelImpl*> setModels;
		std::set<ObjectImpl*>::const_iterator it;
		for ( it = ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].begin() ; it != ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].end() ; ++it )
			if ( ( ( ContainmentImpl*) (*it) )->getChild() == pKind )
				setModels.insert( ( ( ContainmentImpl*) (*it) )->getParent() );

		
		std::set<ContainmentImpl*> setRoles;
		if ( setModels.empty() )
			return setRoles;

		int iPos = strDescIn.find( " " );
		// strDesc to store the first token
		std::string strDesc = ( iPos == std::string::npos ) ? strDescIn : strDescIn.substr( 0, iPos );
		
		// for all roles 
		for ( it = ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].begin() ; it != ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].end() ; ++it ) {
			// filter with "strDesc"
			if ( (*it)->getName() == strDesc ) {
				bool bFound = false;
				// test if role's (*it) parent is in "setModels"
				for ( std::set<ModelImpl*>::iterator it2 = setModels.begin() ; it2 != setModels.end() ; it2++ )
					if ( ( ( ContainmentImpl*) (*it) )->getParent() == *it2 ) {
						bFound = true;
						break;
					}
				if ( bFound )
				{
					// insert such role into "setRoles"
					setRoles.insert( (ContainmentImpl*) *it );
				}
			}
		}
		// pass the collected roles and the remaining rolelist ("2nd_token 3rd_token" substr of the strDescIn)
		std::set<ContainmentImpl*> res = getRoles( setRoles, ( iPos == std::string::npos ) ? "" : strDescIn.substr( iPos + 1 ), true );

		return res;
	}

	std::set<ContainmentImpl*> ProjectImpl::getRoles( const std::set<ContainmentImpl*>& setIn, const std::string& strDescIn, bool bResolveReference ) const
	{
		// setIn has the roles conforming to the 1st_token of the original string passed to getLocalRoles
		//       these roles are part of the model the pKind (a connection, set, ...) is part of as well
		//
		// strDescIn has the remaining rolelist (usually the "port")

		if ( strDescIn.empty() )
			return setIn;

		int iPos = strDescIn.find( " " );
		// the next token (usually a "port")
		std::string strDesc = ( iPos == std::string::npos ) ? strDescIn : strDescIn.substr( 0, iPos );

		// these will store output from getRolesResolved
		std::set<ContainmentImpl*> setRolesResolved;
		std::set<FolderContainmentImpl*> setFolderRolesResolved;

		// selects from setIn 
		//		-modelroles contained by setIn
		//		-modelroles which are referred by referenceroles in setIn ( for such references it returns all of their role)
		// it returns all roles of these (roles, and folderroles)
		getRolesResolved( setIn, bResolveReference, setRolesResolved, setFolderRolesResolved );

		std::set<ContainmentImpl*> setRolesOut;
		if ( setRolesResolved.empty() && setFolderRolesResolved.empty())
			return setRolesOut;

		// for all roles
		for ( std::set<ObjectImpl*>::const_iterator it = ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].begin() ; it != ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].end() ; ++it ) {
			// filter based on "strDesc"
			if ( ( ( ContainmentImpl*) (*it) )->getName() == strDesc ) {
				bool bFound = false;
				// 
				// test if any of resolved role's (*it2) child equals with the role's (*it) parent 
				// like M<>----resolved_role--A1<>---------it--P2 (port)
				for ( std::set<ContainmentImpl*>::iterator it2 = setRolesResolved.begin() ; it2 != setRolesResolved.end() ; ++it2 )
					if ( ( ( ContainmentImpl*) (*it) )->getParent() == (*it2)->getChild() ) {
						bFound = true;
						break;
					}
				// 
				// if not found test if any of the resolved folder_role's (*it3) child equals with the role's (*it) parent 
				// like Folder<>----resolved_role--M1<>---------it--P2 (port)
				for ( std::set<FolderContainmentImpl*>::iterator it3 = setFolderRolesResolved.begin() ; !bFound && it3 != setFolderRolesResolved.end() ; ++it3 )
					if ( ( ( ContainmentImpl*) (*it) )->getParent() == (*it3)->getChild() ) {
						bFound = true;
						break;
					}
				
				// if role (*it) is a role inside any of the resolvedroles then insert into setRolesOut
				// M/F<>---------resolvedrole-M<>-----role-P
				if ( bFound )
				{
					setRolesOut.insert( (ContainmentImpl*) *it );
					std::string pn = ((ContainmentImpl*) *it)->getParent()->getName();
					std::string cn = ((ContainmentImpl*) *it)->getChild()->getName();
				}
			}
		}

		// invoke with the collected roles, with the remaining part of strDescIn (usually "" which returns the "setRolesOut" )
		return getRoles( setRolesOut, ( iPos == std::string::npos ) ? "" : strDescIn.substr( iPos + 1 ), bResolveReference );
	}

	void ProjectImpl::getRolesResolved( 
			const std::set<ContainmentImpl*>& setIn, 
			bool bResolveReference,
			std::set<ContainmentImpl*>& setRolesRes,            // return value
			std::set<FolderContainmentImpl*>& setFolderRolesRes // return value
		) const
	{
		if ( setIn.empty() )
			return;

		// for all roles in setIn
		for ( std::set<ContainmentImpl*>::const_iterator it = setIn.begin() ; it != setIn.end() ; ++it ) 
		{
			std::string rolrname = (*it)->getChild()->getName();
			if ( (*it)->getChild()->getType() == OT_Model ) // if contained model
				setRolesRes.insert( *it ); 
			else if ( bResolveReference && (*it)->getChild()->getType() == OT_Reference ) // if contained reference
			{
				// the remaining part is not depending on *it so
				// all roles of the referred models are returned
				//
				// for all reference assocs
				for ( std::set<ReferenceAssocImpl*>::const_iterator itr = m_setReferenceAssocs.begin() ; itr != m_setReferenceAssocs.end() ; ++itr )
				{
					// filter with (*it)->getChild()		because we are interested in the targets of this reference only
					if ((*itr)->getReference() == (*it)->getChild())
					{
						// take the reference's target
						FCOImpl * referee = (*itr)->getTarget();
						// if ( referee gettype == OT_reference - a transitive modelreference
						if ( referee->getType() == OT_Model ) // if a modelreference
						{
							//std::string refereename = referee->getName();//t
							
							// will contain the roles of the refererred model
							std::set<ContainmentImpl*> the_roles_of_referee;
							
							// for all roles
							for ( std::set<ObjectImpl*>::const_iterator role_it = ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].begin() ; role_it != ( (ProjectImpl* ) this )->m_mapObjectsByType[ OT_Role ].end() ; ++role_it )
							{
								//std::string name1 = ( ( ContainmentImpl*) (*role_it) )->getChild()->getName();
								//if ( name1 == refereename ) // is a role of referee
								{
									// if a role of referee
									if ( ( ( ContainmentImpl*) (*role_it) )->getChild() == referee )
									{
										the_roles_of_referee.insert( ( ContainmentImpl*) (*role_it) );
									}
								}
							}

							// will contain the folder_roles of the referred model
							std::set<FolderContainmentImpl *> the_folder_roles_of_referee;
							// for all folder_roles
							for ( std::set<FolderContainmentImpl*>::const_iterator fold_cont_it = m_setFolderContainments.begin(); fold_cont_it !=  m_setFolderContainments.end(); ++fold_cont_it)
							{
								//std::string name1 = ( *fold_cont_it )->getChild()->getName();//t
								//if ( name1 == refereename ) // a role of referee//t
								{
									// if a folder_role of referee
									if ( ( *fold_cont_it )->getChild() == referee )
									{
										the_folder_roles_of_referee.insert( *fold_cont_it );
									}
								}
							}

						//if ( referee->getType() == OT_Model )
						
							// copy into setRolesRes
							for ( std::set<ContainmentImpl*>::iterator the_it = the_roles_of_referee.begin(); the_it != the_roles_of_referee.end(); ++the_it )
								setRolesRes.insert( *the_it );
							// copy into setFolderRolesRes
							for ( std::set<FolderContainmentImpl*>::iterator the_it2 = the_folder_roles_of_referee.begin(); the_it2 != the_folder_roles_of_referee.end(); ++the_it2 )
								setFolderRolesRes.insert( *the_it2 );
						}
					}
				}
			}
		}
		return;
	}


	ProjectImpl::~ProjectImpl()
	{
		mapProjects.erase( m_spProject );
		m_spProject = NULL;
		for ( int iType = OT_Model ; iType <= OT_Part ; iType++ )
			for ( ObjectSet::iterator it = m_mapObjectsByType[ iType ].begin() ; it != m_mapObjectsByType[ iType ].end() ; ++it )
				delete *it;
		for ( std::set<FolderContainmentImpl*>::iterator fciI = m_setFolderContainments.begin() ; fciI != m_setFolderContainments.end() ; ++fciI )
			delete *fciI;
		for ( std::set<ReferenceAssocImpl*>::iterator raiI = m_setReferenceAssocs.begin() ; raiI != m_setReferenceAssocs.end() ; ++raiI )
			delete *raiI;
		for ( std::set<SetMembershipImpl*>::iterator smiI = m_setSetMemberships.begin() ; smiI != m_setSetMemberships.end() ; ++smiI )
			delete *smiI;
		for ( std::set<AttributeAggregationImpl*>::iterator aaiI = m_setAttributeAggregations.begin() ; aaiI != m_setAttributeAggregations.end() ; ++aaiI )
			delete *aaiI;
		for ( std::set<ConnectionEndImpl*>::iterator ceriI = m_setConnectionEnds.begin() ; ceriI != m_setConnectionEnds.end() ; ++ceriI )
			delete *ceriI;
		for ( std::set<ModelInAspectImpl*>::iterator miaI = m_setModelInAspects.begin() ; miaI != m_setModelInAspects.end() ; ++miaI )
			delete *miaI;
	}

	bool ProjectImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectPtr ProjectImpl::getProjectI() const
	{
		return m_spProject;
	}

	std::string ProjectImpl::getName() const
	{
		CComBSTR bstrName;
		COMTHROW( m_spProject->get_Name( &bstrName ) );
		return Util::Copy( bstrName );
	}

	std::string	ProjectImpl::getDisplayedName() const
	{
		CComBSTR bstrDName;
		COMTHROW( m_spProject->get_DisplayedName( &bstrDName ) );
		return Util::Copy( bstrDName );
	}

	std::string ProjectImpl::getAuthor() const
	{
		CComBSTR bstrAuthor;
		COMTHROW( m_spProject->get_Author( &bstrAuthor ) );
		return Util::Copy( bstrAuthor );
	}

	std::string ProjectImpl::getComment() const
	{
		CComBSTR bstrComment;
		COMTHROW( m_spProject->get_Comment( &bstrComment ) );
		return Util::Copy( bstrComment );
	}

	std::string ProjectImpl::getCreationTime() const
	{
		CComBSTR bstrTime;
		COMTHROW( m_spProject->get_CreatedAt( &bstrTime ) );
		return Util::Copy( bstrTime );
	}

	FolderImpl* ProjectImpl::getRootFolder() const
	{
		return m_pRootFolder;
	}

	std::string ProjectImpl::getInfoString( bool bWithIdentifiers ) const
	{
		std::string strInfo( "MON::Project [" );
		if ( bWithIdentifiers )
			strInfo += "name: ";
		return strInfo + getName() + "]";
	}

	const ProjectImpl::ObjectSet& ProjectImpl::getObjects( ObjectType eType ) const
	{
		return ( (ProjectImpl*) this )->m_mapObjectsByType[ (int) eType ];
	}

	const std::set<FolderContainmentImpl*>& ProjectImpl::getFolderContainments() const
	{
		return m_setFolderContainments;
	}

	const std::set<AttributeAggregationImpl*>& ProjectImpl::getAttributeAggregations() const
	{
		return m_setAttributeAggregations;
	}

	const std::set<ReferenceAssocImpl*>& ProjectImpl::getReferenceAssocs() const
	{
		return m_setReferenceAssocs;
	}

	const std::set<SetMembershipImpl*>& ProjectImpl::getSetMemberships() const
	{
		return m_setSetMemberships;
	}

	const std::set<ConnectionEndImpl*>& ProjectImpl::getConnectionEnds() const
	{
		return m_setConnectionEnds;
	}

	const std::set<ModelInAspectImpl*>& ProjectImpl::getModelInAspects() const
	{
		return m_setModelInAspects;
	}

	ObjectImpl* ProjectImpl::findByRef( long lRef ) const
	{
		return ( m_mapObjectsByRef.find( lRef )  != m_mapObjectsByRef.end() ) ? ( (ProjectImpl*) this )->m_mapObjectsByRef[ lRef ] : NULL;
	}

	ObjectImpl* ProjectImpl::findByName( const std::string& strName ) const
	{
		return ( m_mapObjectsByName.find( strName ) != m_mapObjectsByName.end() ) ? ( (ProjectImpl*) this )->m_mapObjectsByName[ strName ] : NULL;
	}


//###############################################################################################################################################
//
// 	C L A S S : MON::ObjectImpl
//
//###############################################################################################################################################

	ObjectImpl::ObjectMap ObjectImpl::mapObjects;

	ObjectImpl::ObjectImpl( IMgaMetaBase* spObject, ProjectImpl* pProject )
		: Util::GenRefCounted( false, pProject ), m_pProject( pProject ), m_spObject( spObject )
	{
		mapObjects.insert( ObjectImpl::ObjectMap::value_type( spObject, this ) );
	}

	ObjectImpl* ObjectImpl::attachI( IMgaMetaBase* spObject, ProjectImpl* pProject )
	{
		CComQIPtr<IMgaMetaFCO> spFCO = spObject;
		if ( spFCO )
			return FCOImpl::attachI( spFCO, pProject );
		CComQIPtr<IMgaMetaFolder> spFolder = spObject;
		if ( spFolder )
			return FolderImpl::attachI( spFolder, pProject );
		CComQIPtr<IMgaMetaAttribute> spAttribute = spObject;
		if ( spAttribute )
			return AttributeImpl::attachI( spAttribute, pProject );
		CComQIPtr<IMgaMetaAspect> spAspect = spObject;
		if ( spAspect )
			return AspectImpl::attachI( spAspect, pProject );
		CComQIPtr<IMgaMetaRole> spRole = spObject;
		if ( spRole )
			return ContainmentImpl::attachI( spRole, pProject );
		CComQIPtr<IMgaMetaPart> spPart = spObject;
		if ( spPart )
			return ContainmentPartImpl::attachI( spPart, pProject );
		ASSERTTHROW( Util::Exception( "Unprocessed Object Type" ) );
	}

	ObjectImpl* ObjectImpl::attach( IMgaMetaBase* spObject )
	{
		return attachI( spObject );
	}

	ObjectImpl* ObjectImpl::find( IMgaMetaBase* spObject )
	{
		ObjectImpl::ObjectMap::iterator it = mapObjects.find( spObject );
		return ( it == mapObjects.end() ) ? NULL : it->second;
	}

	ObjectImpl::~ObjectImpl()
	{
		for ( RegistryMap::iterator it = m_mapRegistry.begin() ; it != m_mapRegistry.end() ; ++it )
			delete it->second;
		m_mapRegistry.clear();

		mapObjects.erase( ObjectPtr( m_spObject ) );
		m_spObject = NULL;

	}

	bool ObjectImpl::setDeleted()
	{
		return isDeleted();
	}

	ObjectPtr ObjectImpl::getObjectI() const
	{
		return m_spObject;
	}

	ProjectImpl* ObjectImpl::getProject() const
	{
		return m_pProject;
	}

	long ObjectImpl::getRef() const
	{
		long lRef;
		COMTHROW( m_spObject->get_MetaRef( &lRef ) );
		return lRef;
	}

	std::string ObjectImpl::getName() const
	{
		CComBSTR bstrName;
		COMTHROW( m_spObject->get_Name( &bstrName ) );
		return Util::Copy( bstrName );
	}

	std::string	ObjectImpl::getDisplayedName() const
	{
		CComBSTR bstrDName;
		COMTHROW( m_spObject->get_DisplayedName( &bstrDName ) );
		return Util::Copy( bstrDName );
	}

	ObjectType ObjectImpl::getType() const
	{
		objtype_enum eType;
		COMTHROW( m_spObject->get_ObjType( &eType ) );
		return ( ObjectType ) eType;
	}

	std::string ObjectImpl::getInfoStringHelper( const std::string& strStereotype, bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::" + strStereotype + " [" );
		if ( bWithIdentifiers )
			strInfo += "name: ";
		strInfo += getName();
		if ( bWithRef ) {
			strInfo += ", ";
			if ( bWithIdentifiers )
				strInfo += "ref: ";
			strInfo += _ref2str( getRef() );
		}
		return strInfo + "]";
	}

	RegistryNodeImpl* ObjectImpl::getRegistryNode( const std::string& strPath )
	{
		std::string strPath2 = _slashes( strPath );
		if ( strPath2.empty() || strPath2 == "/" )
			strPath2 = "/";
		else
			if ( strPath2[ strPath2.size() - 1 ] == '/' )
				strPath2 = strPath2.substr( 0, strPath2.size() - 1 );

		RegistryMap::iterator it = m_mapRegistry.find( strPath2 );
		if ( it != m_mapRegistry.end() )
			return it->second;

		RegistryNodeImpl* pNode = NULL;
		if ( strPath2 == "/" )
			pNode = new RegistryNodeImpl( NULL, this, strPath2 );
		else {
			strPath2 = strPath2.substr( 1 );
			RegNodePtr spNode;
			COMTHROW( m_spObject->get_RegistryNode( Util::Copy( strPath2 ), spNode.Addr() ) );
			pNode = new RegistryNodeImpl( spNode, this, strPath2.substr( 0, strPath.rfind( '/' ) + 1 ) );
		}
		m_mapRegistry.insert( RegistryMap::value_type( strPath2, pNode ) );
		return pNode;
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::FolderImpl <<< + MON::ObjectImpl
//
//###############################################################################################################################################

	FolderImpl::FolderImpl( IMgaMetaFolder* spFolder, ProjectImpl* pProject )
		: ObjectImpl( spFolder, pProject )
	{
		Util::ComPtr<IMgaConstraints> spConstraints;
		COMTHROW( spFolder->get_Constraints( spConstraints.Addr() ) );
		MGACOLL_ITERATE( IMgaConstraint, spConstraints.p ) {
			constraint_type_enum eType;
			COMTHROW( MGACOLL_ITER->get_Type( &eType ) );
			if ( eType != CONSTRAINT_TYPE_FUNCTION )
				m_setConstraints.insert( new ConstraintImpl( MGACOLL_ITER, this ) );
		} MGACOLL_ITERATE_END;
	}

	FolderImpl* FolderImpl::attachI( IMgaMetaFolder* spFolder, ProjectImpl* pProject )
	{
		if ( ! spFolder )
			return NULL;
		ObjectImpl* pObject = find( spFolder );
		if ( pObject )
			return (FolderImpl*) pObject;
		pProject = _getProject( spFolder, pProject );
		return new FolderImpl( spFolder, pProject );
	}

	FolderImpl* FolderImpl::attach( IMgaMetaFolder* spFolder )
	{
		return attachI( spFolder );
	}

	FolderImpl::~FolderImpl()
	{
		for ( std::set<ConstraintImpl*>::iterator it = m_setConstraints.begin() ; it != m_setConstraints.end() ; ++it )
			delete *it;
	}

	std::string FolderImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return getInfoStringHelper( "Folder", bWithIdentifiers, bWithRef );
	}

	FolderPtr FolderImpl::getFolderI() const
	{
		CComQIPtr<IMgaMetaFolder> spFolder = getObjectI().p;
		return spFolder.p;
	}

	std::set<ConstraintImpl*> FolderImpl::getConstraints() const
	{
		return m_setConstraints;
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::FCOImpl <<< + MON::ObjectImpl
//
//###############################################################################################################################################

	FCOImpl::FCOImpl( IMgaMetaFCO* spFCO, ProjectImpl* pProject )
		: ObjectImpl( spFCO, pProject )
	{
		Util::ComPtr<IMgaConstraints> spConstraints;
		COMTHROW( spFCO->get_Constraints( spConstraints.Addr() ) );
		MGACOLL_ITERATE( IMgaConstraint, spConstraints.p ) {
			constraint_type_enum eType;
			COMTHROW( MGACOLL_ITER->get_Type( &eType ) );
			if ( eType != CONSTRAINT_TYPE_FUNCTION )
				m_setConstraints.insert( new ConstraintImpl( MGACOLL_ITER, this ) );
		} MGACOLL_ITERATE_END;
	}

	FCOImpl* FCOImpl::attachI( IMgaMetaFCO* spFCO, ProjectImpl* pProject )
	{
		CComQIPtr<IMgaMetaAtom> spAtom = spFCO;
		if ( spAtom )
			return AtomImpl::attachI( spAtom, pProject );
		CComQIPtr<IMgaMetaModel> spModel = spFCO;
		if ( spModel )
			return ModelImpl::attachI( spModel, pProject );
		CComQIPtr<IMgaMetaConnection> spConnection = spFCO;
		if ( spConnection )
			return ConnectionImpl::attachI( spConnection, pProject );
		CComQIPtr<IMgaMetaReference> spReference = spFCO;
		if ( spReference )
			return ReferenceImpl::attachI( spReference, pProject );
		CComQIPtr<IMgaMetaSet> spSet = spFCO;
		if ( spSet )
			return SetImpl::attachI( spSet, pProject );
		ASSERTTHROW( Util::Exception( "Unprocessed FCO type!" ) );
	}

	FCOImpl* FCOImpl::attach( IMgaMetaFCO* spFCO )
	{
		return attachI( spFCO );
	}

	FCOImpl* FCOImpl::find( IMgaMetaFCO* spFCO )
	{
		return (FCOImpl*) ObjectImpl::find( spFCO );
	}

	FCOImpl::~FCOImpl()
	{
		for ( std::set<ConstraintImpl*>::iterator it = m_setConstraints.begin() ; it != m_setConstraints.end() ; ++it )
			delete *it;
	}

	FCOPtr FCOImpl::getFCOI() const
	{
		CComQIPtr<IMgaMetaFCO> spFCO = getObjectI().p;
		return spFCO.p;
	}

	std::set<ConstraintImpl*> FCOImpl::getConstraints() const
	{
		return m_setConstraints;
	}

	const std::set<AttributeImpl*>& FCOImpl::getAttributes() const
	{
		return m_setAttributes;
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::AtomImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	AtomImpl::AtomImpl( IMgaMetaAtom* spAtom, ProjectImpl* pProject )
		: FCOImpl( spAtom, pProject )
	{
	}

	AtomImpl* AtomImpl::attachI( IMgaMetaAtom* spAtom, ProjectImpl* pProject )
	{
		if ( ! spAtom )
			return NULL;
		FCOImpl* pFCO = FCOImpl::find( spAtom );
		if ( pFCO )
			return (AtomImpl*) pFCO;
		pProject = _getProject( spAtom, pProject );
		return new AtomImpl( spAtom, pProject );
	}

	AtomImpl* AtomImpl::attach( IMgaMetaAtom* spAtom )
	{
		return attachI( spAtom );
	}

	AtomImpl::~AtomImpl()
	{
	}

	AtomPtr AtomImpl::getAtomI() const
	{
		CComQIPtr<IMgaMetaAtom> spAtom = getObjectI().p;
		return spAtom.p;
	}

	std::string AtomImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return getInfoStringHelper( "Atom", bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ModelImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	ModelImpl::ModelImpl( IMgaMetaModel* spModel, ProjectImpl* pProject )
		: FCOImpl( spModel, pProject )
	{
	}

	ModelImpl* ModelImpl::attachI( IMgaMetaModel* spModel, ProjectImpl* pProject )
	{
		if ( ! spModel )
			return NULL;
		FCOImpl* pFCO = FCOImpl::find( spModel );
		if ( pFCO )
			return (ModelImpl*) pFCO;
		pProject = _getProject( spModel, pProject );
		return new ModelImpl( spModel, pProject );
	}

	ModelImpl* ModelImpl::attach( IMgaMetaModel* spModel )
	{
		return attachI( spModel );
	}

	ModelImpl::~ModelImpl()
	{
	}

	ModelPtr ModelImpl::getModelI() const
	{
		CComQIPtr<IMgaMetaModel> spModel = getObjectI().p;
		return spModel.p;
	}

	std::string ModelImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return getInfoStringHelper( "Model", bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::SetImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	SetImpl::SetImpl( IMgaMetaSet* spSet, ProjectImpl* pProject )
		: FCOImpl( spSet, pProject )
	{
	}

	SetImpl* SetImpl::attachI( IMgaMetaSet* spSet, ProjectImpl* pProject )
	{
		if ( ! spSet )
			return NULL;
		FCOImpl* pFCO = FCOImpl::find( spSet );
		if ( pFCO )
			return (SetImpl*) pFCO;
		pProject = _getProject( spSet, pProject );
		return new SetImpl( spSet, pProject );
	}

	SetImpl* SetImpl::attach( IMgaMetaSet* spSet )
	{
		return attachI( spSet );
	}

	SetImpl::~SetImpl()
	{
	}

	SetPtr SetImpl::getSetI() const
	{
		CComQIPtr<IMgaMetaSet> spSet = getObjectI().p;
		return spSet.p;
	}

	std::string SetImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return getInfoStringHelper( "Set", bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ReferenceImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	ReferenceImpl::ReferenceImpl( IMgaMetaReference* spReference, ProjectImpl* pProject )
		: FCOImpl( spReference, pProject )
	{
	}

	ReferenceImpl* ReferenceImpl::attachI( IMgaMetaReference* spReference, ProjectImpl* pProject )
	{
		if ( ! spReference )
			return NULL;
		FCOImpl* pFCO = FCOImpl::find( spReference );
		if ( pFCO )
			return (ReferenceImpl*) pFCO;
		pProject = _getProject( spReference, pProject );
		return new ReferenceImpl( spReference, pProject );
	}

	ReferenceImpl* ReferenceImpl::attach( IMgaMetaReference* spReference )
	{
		return attachI( spReference );
	}

	ReferenceImpl::~ReferenceImpl()
	{
	}

	ReferencePtr ReferenceImpl::getReferenceI() const
	{
		CComQIPtr<IMgaMetaReference> spReference = getObjectI().p;
		return spReference.p;
	}

	std::string ReferenceImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return getInfoStringHelper( "Reference", bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionImpl <<< + MON::FCOImpl
//
//###############################################################################################################################################

	ConnectionImpl::ConnectionImpl( IMgaMetaConnection* spConnection, ProjectImpl* pProject )
		: FCOImpl( spConnection, pProject )
	{
	}

	ConnectionImpl* ConnectionImpl::attachI( IMgaMetaConnection* spConnection, ProjectImpl* pProject )
	{
		if ( ! spConnection )
			return NULL;
		FCOImpl* pFCO = FCOImpl::find( spConnection );
		if ( pFCO )
			return (ConnectionImpl*) pFCO;
		pProject = _getProject( spConnection, pProject );
		return new ConnectionImpl( spConnection, pProject );
	}

	ConnectionImpl* ConnectionImpl::attach( IMgaMetaConnection* spConnection )
	{
		return attachI( spConnection );
	}

	ConnectionImpl::~ConnectionImpl()
	{
		for ( std::set<ConnectionSpecImpl*>::iterator it = m_setConnSpecs.begin() ; it != m_setConnSpecs.end() ; ++it )
			delete *it;
	}

	ConnectionPtr ConnectionImpl::getConnectionI() const
	{
		CComQIPtr<IMgaMetaConnection> spConnection = getObjectI().p;
		return spConnection.p;
	}

	const std::set<ConnectionSpecImpl*>& ConnectionImpl::getConnectionSpecs() const
	{
		return m_setConnSpecs;
	}

	bool ConnectionImpl::isSimple() const
	{
		VARIANT_BOOL vbSimple;
		COMTHROW( getConnectionI()->get_IsSimple( &vbSimple ) );
		return vbSimple == VARIANT_TRUE;
	}

	bool ConnectionImpl::isBidirectional() const
	{
		return m_bBidirectional;
	}

	std::string ConnectionImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return getInfoStringHelper( "Connection", bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ContainmentImpl <<< + MON::ObjectImpl
//
//###############################################################################################################################################

	ContainmentImpl::ContainmentImpl( IMgaMetaRole* spRole, ProjectImpl* pProject )
		: ObjectImpl( spRole, pProject ), m_pParent( NULL ), m_pChild( NULL )
	{
	}

	ContainmentImpl* ContainmentImpl::attachI( IMgaMetaRole* spRole, ProjectImpl* pProject )
	{
		if ( ! spRole )
			return NULL;
		ObjectImpl* pObject = find( spRole );
		if ( pObject )
			return (ContainmentImpl*) pObject;
		pProject = _getProject( spRole, pProject );
		return new ContainmentImpl( spRole, pProject );
	}

	ContainmentImpl* ContainmentImpl::attach( IMgaMetaRole* spRole )
	{
		return attachI( spRole );
	}

	ContainmentImpl::~ContainmentImpl()
	{
	}

	ContainmentPtr ContainmentImpl::getContainmentI() const
	{
		CComQIPtr<IMgaMetaRole> spContainment = getObjectI().p;
		return spContainment.p;
	}

	ModelImpl* ContainmentImpl::getParent() const
	{
		if ( ! m_pParent ) {
			ModelPtr spModel;
			COMTHROW( getContainmentI()->get_ParentModel( spModel.Addr() ) );
			( (ContainmentImpl*) this )->m_pParent = ModelImpl::attachI( spModel, getProject() );
		}
		return m_pParent;
	}

	FCOImpl* ContainmentImpl::getChild() const
	{
		if ( ! m_pChild ) {
			FCOPtr spFCO;
			COMTHROW( getContainmentI()->get_Kind( spFCO.Addr() ) );
			( (ContainmentImpl*) this )->m_pChild = (FCOImpl*) find( spFCO );
		}
		return m_pChild;
	}

	std::string ContainmentImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::Containment [" );
		if ( bWithIdentifiers )
			strInfo += "model: ";
		strInfo += getParent()->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "name: ";
		strInfo += getName();
		if ( bWithRef ) {
			strInfo += ", ";
			if ( bWithIdentifiers )
				strInfo += "ref: ";
			strInfo += _ref2str( getRef() );
		}
		return strInfo + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::AttributeImpl <<< + MON::ObjectImpl
//
//###############################################################################################################################################

	AttributeImpl::AttributeImpl( IMgaMetaAttribute* spAttribute, ProjectImpl* pProject, FCOImpl* pOwner )
		: ObjectImpl( spAttribute, pProject ), m_pOwner( pOwner )
	{
	}

	AttributeImpl* AttributeImpl::attachI( IMgaMetaAttribute* spAttribute, ProjectImpl* pProject, FCOImpl* pFCO )
	{
		if ( ! spAttribute )
			return NULL;
		ObjectImpl* pObject = find( spAttribute );
		if ( pObject )
			return (AttributeImpl*) pObject;
		pProject = _getProject( spAttribute, pProject );
		return new AttributeImpl( spAttribute, pProject, pFCO );
	}

	AttributeImpl* AttributeImpl::attach( IMgaMetaAttribute* spAttribute )
	{
		return attachI( spAttribute );
	}

	AttributeImpl::~AttributeImpl()
	{
	}

	AttributePtr AttributeImpl::getAttributeI() const
	{
		CComQIPtr<IMgaMetaAttribute> spAttribute = getObjectI().p;
		return spAttribute.p;
	}

	FCOImpl* AttributeImpl::getOwner() const
	{
		return m_pOwner;
	}

	Util::Variant AttributeImpl::getDefaultValue() const
	{
		CComVariant varValue;
		COMTHROW( getAttributeI()->get_DefaultValue( &varValue ) );
		switch ( varValue.vt ) {
			case VT_EMPTY :
				return Util::Variant();
			case VT_I4 :
				return varValue.lVal;
			case VT_R8 :
				return varValue.dblVal;
			case VT_BSTR :
				return Util::Copy( CComBSTR( varValue.bstrVal ) );
			case VT_BOOL :
				return varValue.boolVal == VARIANT_TRUE;
			default :
				ASSERTTHROW( Util::Exception( "Unprocessed Attribute Default Value!" ) );
		}
	}

	AttributeType AttributeImpl::getValueType() const
	{
		attval_enum eType;
		COMTHROW( getAttributeI()->get_ValueType( &eType ) );
		if ( eType == ATTVAL_REFERENCE || eType == ATTVAL_DYNAMIC || eType == ATTVAL_NULL )
			ASSERTTHROW( Util::Exception( "Unprocessed Attribute Type!" ) );
		return (AttributeType) eType;
	}

	std::vector<AttributeImpl::NameValue> AttributeImpl::getEnumItems() const
	{
		if ( getValueType() != AT_Enumeration )
			ASSERTTHROW( Util::Exception( "Only Enumeration Attribute has EnumerationItems!" ) );

		std::vector<AttributeImpl::NameValue> vecResult;
		Util::ComPtr<IMgaMetaEnumItems> spItems;
		COMTHROW( getAttributeI()->get_EnumItems( spItems.Addr() ) );

		MGACOLL_ITERATE( IMgaMetaEnumItem, spItems.p ) {
			CComBSTR bstrName;
			COMTHROW( MGACOLL_ITER->get_DisplayedName( &bstrName ) );
			CComBSTR bstrValue;
			COMTHROW( MGACOLL_ITER->get_Value( &bstrValue ) );
			vecResult.push_back( AttributeImpl::NameValue( Util::Copy( bstrName ), Util::Copy( bstrValue ) ) );
		} MGACOLL_ITERATE_END;

		return vecResult;
	}

	std::string AttributeImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return getInfoStringHelper( "Attribute", bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::AspectImpl
//
//###############################################################################################################################################

	AspectImpl::AspectImpl( IMgaMetaAspect* spAspect, ProjectImpl* pProject )
		: ObjectImpl( spAspect, pProject )
	{
	}

	AspectImpl* AspectImpl::attachI( IMgaMetaAspect* spAspect, ProjectImpl* pProject )
	{
		if ( ! spAspect )
			return NULL;
		ObjectImpl* pObject = find( spAspect );
		if ( pObject )
			return (AspectImpl*) pObject;
		pProject = _getProject( spAspect, pProject );
		return new AspectImpl( spAspect, pProject );
	}

	AspectImpl* AspectImpl::attach( IMgaMetaAspect* spAspect )
	{
		return attachI( spAspect );
	}

	AspectImpl::~AspectImpl()
	{
	}

	AspectPtr AspectImpl::getAspectI() const
	{
		CComQIPtr<IMgaMetaAspect> spAspect = getObjectI().p;
		return spAspect.p;
	}

	std::string AspectImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return getInfoStringHelper( "Aspect", bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ContainmentPartImpl
//
//###############################################################################################################################################

	ContainmentPartImpl::ContainmentPartImpl( IMgaMetaPart* spPart, ProjectImpl* pProject )
		: ObjectImpl( spPart, pProject )
	{
	}

	ContainmentPartImpl* ContainmentPartImpl::attachI( IMgaMetaPart* spPart, ProjectImpl* pProject )
	{
		if ( ! spPart )
			return NULL;
		ObjectImpl* pObject = find( spPart );
		if ( pObject )
			return (ContainmentPartImpl*) pObject;
		pProject = _getProject( spPart, pProject );
		return new ContainmentPartImpl( spPart, pProject );
	}

	ContainmentPartImpl::~ContainmentPartImpl()
	{
	}

	ContainmentPartImpl* ContainmentPartImpl::attach( IMgaMetaPart* spPart )
	{
		return attachI( spPart );
	}

	PartPtr	ContainmentPartImpl::getPartI() const
	{
		CComQIPtr<IMgaMetaPart> spPart = getObjectI().p;
		return spPart.p;
	}

	bool ContainmentPartImpl::isPrimary() const
	{
		VARIANT_BOOL vbPrimary;
		COMTHROW( getPartI()->get_IsPrimary( &vbPrimary ) );
		return vbPrimary == VARIANT_TRUE;
	}

	bool ContainmentPartImpl::isLinked() const
	{
		VARIANT_BOOL vbLinked;
		COMTHROW( getPartI()->get_IsLinked( &vbLinked ) );
		return vbLinked == VARIANT_TRUE;
	}

	ContainmentImpl* ContainmentPartImpl::getContainment() const
	{
		if ( ! m_pContainment ) {
			ContainmentPtr spRole;
			COMTHROW( getPartI()->get_Role( spRole.Addr() ) );
			( (ContainmentPartImpl*) this )->m_pContainment = ContainmentImpl::attachI( spRole, getProject() );
		}
		return m_pContainment;
	}

	AspectImpl* ContainmentPartImpl::getAspect() const
	{
		if ( ! m_pAspect ) {
			AspectPtr spAspect;
			COMTHROW( getPartI()->get_ParentAspect( spAspect.Addr() ) );
			( (ContainmentPartImpl*) this )->m_pAspect = AspectImpl::attachI( spAspect, getProject() );
		}
		return m_pAspect;
	}

	std::string ContainmentPartImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::ContainmentPart [" );
		if ( bWithIdentifiers )
			strInfo += "containment: ";
		strInfo += getContainment()->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "aspect: ";
		strInfo += getAspect()->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithRef ) {
			strInfo += ", ";
			if ( bWithIdentifiers )
				strInfo += "ref: ";
			strInfo += _ref2str( getRef() );
		}
		return strInfo + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::FolderContainmentImpl
//
//###############################################################################################################################################

	FolderContainmentImpl::FolderContainmentImpl( FolderImpl* pParent, ObjectImpl* pChild )
		: m_pParent( pParent ), m_pChild( pChild )
	{
	}

	FolderContainmentImpl::~FolderContainmentImpl()
	{
	}

	bool FolderContainmentImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* FolderContainmentImpl::getProject() const
	{
		return m_pParent->getProject();
	}

	FolderImpl* FolderContainmentImpl::getParent() const
	{
		return m_pParent;
	}

	ObjectImpl* FolderContainmentImpl::getChild() const
	{
		return m_pChild;
	}

	std::string FolderContainmentImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::FolderContainment [" );
		if ( bWithIdentifiers )
			strInfo += "folder: ";
		strInfo += m_pParent->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "child: ";
		return strInfo + m_pChild->getInfoString( bWithIdentifiers, bWithRef ) + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::AttributeAggregationImpl
//
//###############################################################################################################################################

	AttributeAggregationImpl::AttributeAggregationImpl( FCOImpl* pFCO, AttributeImpl* pAttribute )
		: Util::GenRefCounted( false, pFCO->getProject() ), m_pFCO( pFCO ), m_pAttribute( pAttribute )
	{
	}

	AttributeAggregationImpl::~AttributeAggregationImpl()
	{
	}

	bool AttributeAggregationImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* AttributeAggregationImpl::getProject() const
	{
		return m_pFCO->getProject();
	}

	FCOImpl* AttributeAggregationImpl::getFCO() const
	{
		return m_pFCO;
	}

	AttributeImpl* AttributeAggregationImpl::getAttribute() const
	{
		return m_pAttribute;
	}

	std::string AttributeAggregationImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::AttributeAggregation [" );
		if ( bWithIdentifiers )
			strInfo += "fco: ";
		strInfo += m_pFCO->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "attribute: ";
		return strInfo + m_pAttribute->getInfoString( bWithIdentifiers, bWithRef ) + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ReferenceAssocImpl
//
//###############################################################################################################################################

	ReferenceAssocImpl::ReferenceAssocImpl( ReferenceImpl* pReference, FCOImpl* pTarget )
		: Util::GenRefCounted( false, pReference->getProject() ), m_pReference( pReference ), m_pTarget( pTarget )
	{
	}

	ReferenceAssocImpl::~ReferenceAssocImpl()
	{
	}

	bool ReferenceAssocImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* ReferenceAssocImpl::getProject() const
	{
		return m_pReference->getProject();
	}

	ReferenceImpl* ReferenceAssocImpl::getReference() const
	{
		return m_pReference;
	}

	FCOImpl* ReferenceAssocImpl::getTarget() const
	{
		return m_pTarget;
	}

	std::string ReferenceAssocImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::ReferenceAssociation [" );
		if ( bWithIdentifiers )
			strInfo += "reference: ";
		strInfo += m_pReference->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "target: ";
		return strInfo + m_pTarget->getInfoString( bWithIdentifiers, bWithRef ) + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::SetMembershipImpl
//
//###############################################################################################################################################

	SetMembershipImpl::SetMembershipImpl( SetImpl* pSet, ContainmentImpl* pMember )
		: Util::GenRefCounted( false, pSet->getProject() ), m_pSet( pSet ), m_pMember( pMember )
	{
	}

	SetMembershipImpl::~SetMembershipImpl()
	{
	}

	bool SetMembershipImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* SetMembershipImpl::getProject() const
	{
		return m_pSet->getProject();
	}

	SetImpl* SetMembershipImpl::getSet() const
	{
		return m_pSet;
	}

	ContainmentImpl* SetMembershipImpl::getMember() const
	{
		return m_pMember;
	}

	std::string SetMembershipImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::SetMembership [" );
		if ( bWithIdentifiers )
			strInfo += "set: ";
		strInfo += m_pSet->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "member: ";
		return strInfo + m_pMember->getInfoString( bWithIdentifiers, bWithRef ) + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionSpecImpl
//
//###############################################################################################################################################

	ConnectionSpecImpl::ConnectionSpecImpl( ConnectionImpl* pConnection, int iNum )
		: Util::GenRefCounted( false, pConnection ), m_pConnection( pConnection ), m_iNum( iNum )
	{
	}

	ConnectionSpecImpl::~ConnectionSpecImpl()
	{
		for ( std::set<ConnectionRoleImpl*>::iterator it = m_setRoles.begin() ; it != m_setRoles.end() ; it++ )
			delete *it;
	}

	bool ConnectionSpecImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* ConnectionSpecImpl::getProject() const
	{
		return m_pConnection->getProject();
	}

	ConnectionImpl* ConnectionSpecImpl::getConnection() const
	{
		return m_pConnection;
	}

	int ConnectionSpecImpl::getNumber() const
	{
		return m_iNum;
	}

	const std::set<ConnectionRoleImpl*>& ConnectionSpecImpl::getRoles() const
	{
		return m_setRoles;
	}

	std::string ConnectionSpecImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::ConnectionSpec [" );
		if ( bWithIdentifiers )
			strInfo += "connection: ";
		strInfo += m_pConnection->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "number: ";
		return strInfo + _ref2str( (long) m_iNum ) + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionRoleImpl
//
//###############################################################################################################################################

	ConnectionRoleImpl::ConnectionRoleImpl( ConnectionSpecImpl* pConnection, const std::string& strRole )
		: Util::GenRefCounted( false, pConnection ), m_pSpec( pConnection ), m_strRole( strRole )
	{
	}

	ConnectionRoleImpl::~ConnectionRoleImpl()
	{
	}

	bool ConnectionRoleImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* ConnectionRoleImpl::getProject() const
	{
		return m_pSpec->getConnection()->getProject();
	}

	ConnectionSpecImpl* ConnectionRoleImpl::getConnectionSpec() const
	{
		return m_pSpec;
	}

	std::string	ConnectionRoleImpl::getName() const
	{
		return m_strRole;
	}

	std::string ConnectionRoleImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::ConnectionRole [" );
		if ( bWithIdentifiers )
			strInfo += "connectionSpec: ";
		strInfo += m_pSpec->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "name: ";
		return strInfo + m_strRole + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionEndImpl
//
//###############################################################################################################################################

	ConnectionEndImpl::ConnectionEndImpl( ConnectionRoleImpl* pConnectionRole, ContainmentImpl* pRole )
		: Util::GenRefCounted( false, pRole->getProject() ), m_pConnRole( pConnectionRole ), m_pRole( pRole )
	{
	}

	ConnectionEndImpl::~ConnectionEndImpl()
	{
	}

	bool ConnectionEndImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* ConnectionEndImpl::getProject() const
	{
		return m_pRole->getProject();
	}

	ConnectionRoleImpl* ConnectionEndImpl::getConnectionRole() const
	{
		return m_pConnRole;
	}

	ContainmentImpl* ConnectionEndImpl::getEnd() const
	{
		return m_pRole;
	}

	std::string ConnectionEndImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::ConnectionEnd [" );
		if ( bWithIdentifiers )
			strInfo += "connection: ";
		strInfo += m_pConnRole->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "containment: ";
		return strInfo + m_pRole->getInfoString( bWithIdentifiers, bWithRef )  + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ModelInAspectImpl
//
//###############################################################################################################################################

	ModelInAspectImpl::ModelInAspectImpl( AspectImpl* pAspect, ModelImpl* pModel )
		: Util::GenRefCounted( false, pAspect->getProject() ), m_pAspect( pAspect ), m_pModel( pModel )
	{
	}

	ModelInAspectImpl::~ModelInAspectImpl()
	{
	}

	bool ModelInAspectImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* ModelInAspectImpl::getProject() const
	{
		return m_pAspect->getProject();
	}

	AspectImpl* ModelInAspectImpl::getAspect() const
	{
		return m_pAspect;
	}

	ModelImpl* ModelInAspectImpl::getModel() const
	{
		return m_pModel;
	}

	std::string ModelInAspectImpl::getInfoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		std::string strInfo( "MON::ModelInAspects [" );
		if ( bWithIdentifiers )
			strInfo += "aspect: ";
		strInfo += m_pAspect->getInfoString( bWithIdentifiers, bWithRef ) + ", ";
		if ( bWithIdentifiers )
			strInfo += "model: ";
		return strInfo + m_pModel->getInfoString( bWithIdentifiers, bWithRef ) + "]";
	}

//###############################################################################################################################################
//
// 	C L A S S :MON::RegistryNodeImpl
//
//###############################################################################################################################################

	RegistryNodeImpl::RegistryNodeImpl( IMgaMetaRegNode* spNode, ObjectImpl* pObject, const std::string& strPath )
		: Util::GenRefCounted( false, pObject ), m_spNode( spNode ), m_pObject( pObject ), m_strPath( strPath )
	{
	}

	RegistryNodeImpl::~RegistryNodeImpl()
	{
		m_pObject = NULL;
		m_spNode = NULL;
	}

	bool RegistryNodeImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* RegistryNodeImpl::getProject() const
	{
		return m_pObject->getProject();
	}

	ObjectImpl* RegistryNodeImpl::getObject() const
	{
		return m_pObject;
	}

	RegNodePtr RegistryNodeImpl::getRegNodeI() const
	{
		return m_spNode;
	}

	bool RegistryNodeImpl::isRootNode() const
	{
		return ( m_spNode ) ? false : true;
	}

	std::string RegistryNodeImpl::getName() const
	{
		if ( m_spNode ) {
			CComBSTR bstrName;
			COMTHROW( m_spNode->get_Name( &bstrName ) );
			return Util::Copy( bstrName );
		}
		return "";
	}

	std::string RegistryNodeImpl::getPath() const
	{
		return m_strPath;
	}

	std::string RegistryNodeImpl::getValue() const
	{
		if ( m_spNode ) {
			CComBSTR bstrValue;
			COMTHROW( m_spNode->get_Value( &bstrValue ) );
			return Util::Copy( bstrValue );
		}
		return "";
	}

	RegistryNodeImpl* RegistryNodeImpl::getParent() const
	{
		return ( m_spNode ) ? m_pObject->getRegistryNode( m_strPath ) : NULL;
	}

	std::set<RegistryNodeImpl*> RegistryNodeImpl::getChildren() const
	{
		std::set<RegistryNodeImpl*> setNodes;
		Util::ComPtr<IMgaMetaRegNodes> spNodes;

		if ( m_spNode ) {
			COMTHROW( m_spNode->get_RegistryNodes( spNodes.Addr() ) );
		}
		else {
			COMTHROW( m_pObject->getObjectI()->get_RegistryNodes( spNodes.Addr() ) );
		}

		MGACOLL_ITERATE( IMgaMetaRegNode, spNodes.p ) {
			CComBSTR bstrName;
			COMTHROW( MGACOLL_ITER->get_Name( &bstrName ) );
			setNodes.insert( m_pObject->getRegistryNode( m_strPath + Util::Copy( bstrName ) ) );
		} MGACOLL_ITERATE_END;

		return setNodes;
	}

	RegistryNodeImpl* RegistryNodeImpl::getChild( const std::string& strName ) const
	{
		return m_pObject->getRegistryNode( m_strPath + strName );
	}

	std::string	RegistryNodeImpl::getValueByPath( const std::string& strPath ) const
	{
		return getChildByPath( strPath )->getValue();
	}

	RegistryNodeImpl* RegistryNodeImpl::getChildByPath( const std::string& strPath ) const
	{
		std::string strPath2 = _slashes( strPath );
		if ( strPath2.empty() )
			return (RegistryNodeImpl*) this;
		if ( strPath2[ 0 ] == '/' )
			strPath2 = strPath2.substr( 1 );
		if ( strPath2.empty() )
			return (RegistryNodeImpl*) this;
		return m_pObject->getRegistryNode( m_strPath + strPath2 );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ConstraintImpl
//
//###############################################################################################################################################

	ConstraintImpl::ConstraintImpl( IMgaConstraint* spConstraint, ObjectImpl* pObject )
		: Util::GenRefCounted( false, pObject ), m_spConstraint( spConstraint ), m_pObject( pObject )
	{
	}

	ConstraintImpl::~ConstraintImpl()
	{
		m_spConstraint = NULL;
		m_pObject = NULL;
	}

	bool ConstraintImpl::setDeleted()
	{
		return isDeleted();
	}

	ProjectImpl* ConstraintImpl::getProject() const
	{
		return m_pObject->getProject();
	}

	ObjectImpl* ConstraintImpl::getObject() const
	{
		return m_pObject;
	}

	ConstraintPtr ConstraintImpl::getConstraintI() const
	{
		return m_spConstraint;
	}

	std::string	ConstraintImpl::getName() const
	{
		CComBSTR bstrName;
		COMTHROW( m_spConstraint->get_Name( &bstrName ) );
		return Util::Copy( bstrName );
	}

	std::string ConstraintImpl::getDescription() const
	{
		CComBSTR bstrName;
		COMTHROW( m_spConstraint->get_DisplayedName( &bstrName ) );
		return Util::Copy( bstrName );
	}

	std::vector<std::string> ConstraintImpl::getEquation() const
	{
		CComBSTR bstrExpr;
		COMTHROW( m_spConstraint->get_Expression( &bstrExpr ) );
		std::string strExpr = Util::Copy( bstrExpr );
		std::vector<std::string> vecExpr;

		while ( ! strExpr.empty() ) {
			int iPos = strExpr.find( '\n' );
			if ( iPos != std::string::npos ) {
				CString strLine = strExpr.substr( 0, iPos ).c_str();
				strLine.TrimLeft();
				strLine.TrimRight();
				if ( ! strLine.IsEmpty() )
					vecExpr.push_back( strExpr.substr( 0, iPos ) );
				strExpr = strExpr.substr( iPos + 1 );
			}
			else {
				vecExpr.push_back( strExpr );
				strExpr = "";
			}
		}
		return vecExpr;
	}

	std::set<ObjectEventType> ConstraintImpl::getEvents() const
	{
		std::set<ObjectEventType> setEvents;
		unsigned long ulEventMask;
		COMTHROW( m_spConstraint->get_EventMask( &ulEventMask ) );

		for ( ObjectEventType eType = OET_None ; eType != OET_All ; eType++ )
			if ( ulEventMask & eType )
				setEvents.insert( eType );
		return setEvents;
	}

	ConstraintPriority ConstraintImpl::getPriority() const
	{
		long lPriority;
		COMTHROW( m_spConstraint->get_Priority( &lPriority ) );
		return (ConstraintPriority) lPriority;
	}

	ConstraintDepth ConstraintImpl::getDepth() const
	{
		constraint_depth_enum eDepth;
		COMTHROW( m_spConstraint->get_Depth( &eDepth ) );
		return (ConstraintDepth) eDepth;
	}

}; // namespace MON
