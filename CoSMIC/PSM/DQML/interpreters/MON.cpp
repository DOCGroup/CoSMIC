//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	MON.cpp
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
#include "MON.h"

namespace MON
{

#define FILTER_BEGIN( filterClass, filterVar )	\
	{ {																									\
		const std::set<filterClass>& setFilter = filterVar;											\
		for ( std::set<filterClass>::const_iterator it = setFilter.begin() ; it != setFilter.end() ; it++ )

#define FILTER_END } }

#define FULLFILTER( filteredClass, filteredVar, filterClass, cond, value )	\
	{ {																					\
		std::set<filterClass> setResult;												\
		FILTER_BEGIN( filteredClass, filteredVar ) {									\
			if ( cond )																	\
				setResult.insert( value );												\
		} FILTER_END;																\
		return setResult;																\
	} }

#define FINDRELATION( filteredClass, filteredVar, cond )	\
	{ {																					\
		FILTER_BEGIN( filteredClass, filteredVar ) {									\
			if ( cond )																	\
				return true;															\
		} FILTER_END;																\
		return false;																	\
	} }

//###############################################################################################################################################
//
// 	C L A S S : MON::Project
//
//###############################################################################################################################################

	Project::Project()
		: Util::GenRefCounter( NULL )
	{
	}

	Project::Project( ProjectImpl* pProject )
		: Util::GenRefCounter( pProject )
	{
	}

	Project::Project( IMgaMetaProject* spProject )
		: Util::GenRefCounter( ProjectImpl::attach( spProject ) )
	{
	}

	Project::Project( const Project& project )
		: Util::GenRefCounter( project )
	{
	}

	Project& Project::operator = ( const Project& project )
	{
		using namespace Util;
		GenRefCounter::operator=( project );
		return *this;
	}

	ProjectPtr Project::getProjectI() const
	{
		return ( (ProjectImpl*) getCounted() )->getProjectI();
	}

	std::string Project::name() const
	{
		return ( (ProjectImpl*) getCounted() )->getName();
	}

	std::string	Project::displayedName() const
	{
		return ( (ProjectImpl*) getCounted() )->getDisplayedName();
	}

	std::string Project::author() const
	{
		return ( (ProjectImpl*) getCounted() )->getAuthor();
	}

	std::string Project::comment() const
	{
		return ( (ProjectImpl*) getCounted() )->getComment();
	}

	std::string Project::creationTime() const
	{
		return ( (ProjectImpl*) getCounted() )->getCreationTime();
	}

	Folder Project::rootFolder() const
	{
		return ( (ProjectImpl*) getCounted() )->getRootFolder();
	}

	std::string Project::infoString( bool bWithIdentifiers ) const
	{
		return ( (ProjectImpl*) getCounted() )->getInfoString( bWithIdentifiers );
	}

	std::set<Folder> Project::folders() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Folder ), Folder, true, *it );
	}

	std::set<Atom> Project::atoms() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Atom ), Atom, true, *it );
	}

	std::set<Model> Project::models() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Model ), Model, true, *it );
	}

	std::set<Set> Project::sets() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Set ), Set, true, *it );
	}

	std::set<Reference> Project::references() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Reference ), Reference, true, *it );
	}

	std::set<Connection> Project::connections() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Connection ), Connection, true, *it );
	}

	std::set<Aspect> Project::aspects() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Aspect ), Aspect, true, *it );
	}

	std::set<Attribute> Project::attributes() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Attribute ), Attribute, true, *it );
	}

	std::set<FolderContainment> Project::folderContainments() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) getCounted() )->getFolderContainments(), FolderContainment, true, *it );
	}

	std::set<ReferenceAssociation> Project::referenceAssociations() const
	{
		FULLFILTER( ReferenceAssocImpl*, ( (ProjectImpl*) getCounted() )->getReferenceAssocs(), ReferenceAssociation, true, *it );
	}

	std::set<SetMembership> Project::setMemberships() const
	{
		FULLFILTER( SetMembershipImpl*, ( (ProjectImpl*) getCounted() )->getSetMemberships(), SetMembership, true, *it );
	}

	std::set<Containment> Project::containments() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Role ), Containment, true, *it );
	}

	std::set<ContainmentPart> Project::containmentParts() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) getCounted() )->getObjects( OT_Part ), ContainmentPart, true, *it );
	}

	std::set<ConnectionEnd> Project::connectionEnds() const
	{
		FULLFILTER( ConnectionEndImpl*, ( (ProjectImpl*) getCounted() )->getConnectionEnds(), ConnectionEnd, true, *it );
	}

	std::set<ModelInAspect> Project::modelInAspects() const
	{
		FULLFILTER( ModelInAspectImpl*, ( (ProjectImpl*) getCounted() )->getModelInAspects(), ModelInAspect, true, *it );
	}

	std::set<AttributeAggregation> Project::attributeAggregations() const
	{
		FULLFILTER( AttributeAggregationImpl*, ( (ProjectImpl*) getCounted() )->getAttributeAggregations(), AttributeAggregation, true, *it );
	}

	MetaObject Project::findByRef( long lRef ) const
	{
		return ( (ProjectImpl*) getCounted() )->findByRef( lRef );
	}

	MetaObject Project::findByName( const std::string strName ) const
	{
		return ( (ProjectImpl*) getCounted() )->findByName( strName );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::MetaObject
//
//###############################################################################################################################################

	MetaObject::MetaObject()
		: Util::GenRefCounter( NULL )
	{
	}

	MetaObject::MetaObject( ObjectImpl* pObject )
		: Util::GenRefCounter( pObject )
	{
	}

	MetaObject::MetaObject( const MetaObject& object )
		: Util::GenRefCounter( object )
	{
	}

	MetaObject& MetaObject::operator = ( const MetaObject& object )
	{
		using namespace Util;
		GenRefCounter::operator =( object );
		return *this;
	}

	void MetaObject::castObjectImpl( ObjectType eType, ObjectType eType2 )
	{
		if ( getCounted( false ) ) {
			ObjectType oType = ( (ObjectImpl*) getCounted() )->getType();
			if ( eType2 == OT_Null && oType != eType || eType2 != OT_Null && ( oType < eType || oType > eType2 ) )
				setCounted( NULL );
		}
	}

	ObjectPtr MetaObject::getObjectI() const
	{
		return ( (ObjectImpl*) getCounted() )->getObjectI();
	}

	long MetaObject::ref() const
	{
		return ( (ObjectImpl*) getCounted() )->getRef();
	}

	std::string MetaObject::name() const
	{
		return ( (ObjectImpl*) getCounted() )->getName();
	}

	std::string MetaObject::displayedName() const
	{
		return ( (ObjectImpl*) getCounted() )->getName();
	}

	ObjectType MetaObject::type() const
	{
		return ( (ObjectImpl*) getCounted() )->getType();
	}

	Project MetaObject::project() const
	{
		return ( (ObjectImpl*) getCounted() )->getProject();
	}

	std::string MetaObject::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (ObjectImpl*) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

	RegistryNode MetaObject::registry() const
	{
		return ( (ObjectImpl*) getCounted() )->getRegistryNode( "/" );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Object
//
//###############################################################################################################################################

	Object::Object()
		: MetaObject()
	{
	}

	Object::Object( ObjectImpl* pObject )
		: MetaObject( pObject )
	{
		castObjectImpl( OT_Model, OT_Folder );
	}

	Object::Object( const MetaObject& object )
		: MetaObject( object )
	{
		castObjectImpl( OT_Model, OT_Folder );
	}

	Object& Object::operator = ( const MetaObject& object )
	{
		MetaObject::operator=( object );
		castObjectImpl( OT_Model, OT_Folder );
		return *this;
	}

	std::set<FolderContainment> Object::parentFolderContainments() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), FolderContainment, (*it)->getChild() == getCounted(), *it );
	}

	std::set<Folder> Object::parentFolders() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), Folder, (*it)->getChild() == getCounted(), (*it)->getParent() );
	}

	bool Object::isFolderParent( const Folder& folder ) const
	{
		FINDRELATION( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), (*it)->getChild() == getCounted() && (*it)->getParent() == folder.getCounted( false ) );
	}

	std::set<Constraint> Object::constraints() const
	{
		if ( ( (ObjectImpl*) getCounted() )->getType() == OT_Folder ) {
			FULLFILTER( ConstraintImpl*, ( (FolderImpl*) getCounted() )->getConstraints(), Constraint, true, *it );
		}
		else {
			FULLFILTER( ConstraintImpl*, ( (FCOImpl*) getCounted() )->getConstraints(), Constraint, true, *it );
		}
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Folder
//
//###############################################################################################################################################

	Folder::Folder( ObjectImpl* pObject )
		: Object( pObject )
	{
		castObjectImpl( OT_Folder );
	}

	Folder::Folder( const MetaObject& object )
		: Object( object  )
	{
		castObjectImpl( OT_Folder );
	}

	Folder::Folder( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaFolder> spFolder = spObject;
		setCounted( FolderImpl::attach( spFolder ) );
	}

	Folder& Folder::operator = ( const MetaObject& object )
	{
		Object::operator=( object );
		castObjectImpl( OT_Folder );
		return *this;
	}

	FolderPtr Folder::getFolderI() const
	{
		return ( (FolderImpl*) getCounted() )->getFolderI();
	}

	std::set<FolderContainment> Folder::childFolderContainments() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), FolderContainment, (*it)->getParent() == getCounted(), *it );
	}

	std::set<Object> Folder::childObjects() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), Object, (*it)->getParent() == getCounted(), (*it)->getChild() );
	}

	std::set<Folder> Folder::childFolders() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), Folder, (*it)->getParent() == getCounted() && (*it)->getChild() ->getType() == OT_Folder, (*it)->getChild() );
	}

	std::set<FCO> Folder::childFCOs() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), FCO, (*it)->getParent() == getCounted() && (*it)->getChild() ->getType() != OT_Folder, (*it)->getChild() );
	}

	std::set<Atom> Folder::childAtoms() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), Atom, (*it)->getParent() == getCounted() && (*it)->getChild() ->getType() == OT_Atom, (*it)->getChild() );
	}

	std::set<Model> Folder::childModels() const
	{
		FULLFILTER( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), Model, (*it)->getParent() == getCounted() && (*it)->getChild() ->getType() == OT_Model, (*it)->getChild() );
	}

	bool Folder::isObjectChild( const Object& object ) const
	{
		FINDRELATION( FolderContainmentImpl*, ( (ProjectImpl*) project().getCounted() )->getFolderContainments(), (*it)->getParent() == getCounted() && (*it)->getChild() == object.getCounted( false ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::FCO
//
//###############################################################################################################################################

	FCO::FCO( ObjectImpl* pObject )
		: Object( pObject )
	{
		castObjectImpl( OT_Model, OT_Set );
	}

	FCO::FCO( const MetaObject& object )
		: Object( object )
	{
		castObjectImpl( OT_Model, OT_Set );
	}

	FCO& FCO::operator = ( const MetaObject& object )
	{
		Object::operator=( object );
		castObjectImpl( OT_Model, OT_Set );
		return *this;
	}

	FCOPtr FCO::getFCOI() const
	{
		return ( (FCOImpl*) getCounted() )->getFCOI();
	}

	std::set<Containment> FCO::parentContainments() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), Containment, ( (ContainmentImpl*) (*it) )->getChild() == getCounted(), *it );
	}

	std::set<Model> FCO::parentModels() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), Model, ( (ContainmentImpl*) (*it) )->getChild() == getCounted(), ( (ContainmentImpl*) (*it) )->getParent() );
	}

	bool FCO::isModelParent( const Model& model ) const
	{
		FINDRELATION( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), ( (ContainmentImpl*) (*it) )->getChild() == getCounted() && ( (ContainmentImpl*) (*it) )->getParent() == model.getCounted( false ) );
	}

	std::set<ConnectionEnd> FCO::connectionEnds() const
	{
		FULLFILTER( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), ConnectionEnd, (*it)->getEnd()->getChild() == getCounted(), *it );
	}

	std::set<ConnectionRole> FCO::targetOf() const
	{
		FULLFILTER( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), ConnectionRole, (*it)->getEnd()->getChild() == getCounted(), (*it)->getConnectionRole() );
	}

	bool FCO::isTargetOf( const ConnectionRole& role ) const
	{
		FINDRELATION( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), (*it)->getEnd()->getChild() == getCounted() && (*it)->getConnectionRole() == role.getCounted( false ) );
	}

	std::set<ReferenceAssociation> FCO::referenceAssociations() const
	{
		FULLFILTER( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), ReferenceAssociation, (*it)->getTarget() == getCounted(), *it );
	}

	std::set<Reference> FCO::referencedBy() const
	{
		FULLFILTER( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), Reference, (*it)->getTarget() == getCounted(), (*it)->getReference() );
	}

	bool FCO::isReferencedBy( const Reference& reference ) const
	{
		FINDRELATION( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), (*it)->getTarget() == getCounted() && (*it)->getReference() == reference.getCounted( false ) );
	}

	std::set<SetMembership> FCO::setMemberships() const
	{
		FULLFILTER( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), SetMembership, (*it)->getMember()->getChild() == getCounted(), *it );
	}

	std::set<Set> FCO::memberOf() const
	{
		FULLFILTER( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), Set, (*it)->getMember()->getChild() == getCounted(), (*it)->getSet() );
	}

	bool FCO::isMemberOf( const Set& set ) const
	{
		FINDRELATION( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), (*it)->getMember()->getChild() == getCounted() && (*it)->getSet() == set.getCounted( false ) );
	}

	std::set<AttributeAggregation> FCO::attributeAggregations() const
	{
		FULLFILTER( AttributeAggregationImpl*, ( (ProjectImpl*) project().getCounted() )->getAttributeAggregations(), AttributeAggregation, (*it)->getFCO() == getCounted(), *it );
	}

	std::set<Attribute> FCO::attributes( bool bLocalsAlso ) const
	{
		std::set<Attribute> setAttributes;
		const std::set<AttributeAggregationImpl*>& setAggregations = ( (ProjectImpl*) project().getCounted() )->getAttributeAggregations();
		for ( std::set<AttributeAggregationImpl*>::const_iterator it = setAggregations.begin() ; it != setAggregations.end() ; it++ )
			if ( (*it)->getFCO() == getCounted() )
				setAttributes.insert( (*it)->getAttribute() );
		if ( bLocalsAlso ) {
			const std::set<AttributeImpl*>& setLocals = ( (FCOImpl*) getCounted() )->getAttributes();
			setAttributes.insert( setLocals.begin(), setLocals.end() );
		}
		return setAttributes;
	}

	std::set<Attribute> FCO::localAttributes() const
	{
		FULLFILTER( AttributeImpl*, ( (FCOImpl*) getCounted() )->getAttributes(), Attribute, true, *it );
	}

	bool FCO::hasAttribute( const Attribute& attribute, bool bLocalsAlso ) const
	{
		const std::set<AttributeAggregationImpl*>& setAggregations = ( (ProjectImpl*) project().getCounted() )->getAttributeAggregations();
		std::set<AttributeAggregationImpl*>::const_iterator it;
		for ( it = setAggregations.begin() ; it != setAggregations.end() ; it++ )
			if ( (*it)->getFCO() == getCounted() && (*it)->getAttribute() == attribute.getCounted( false ) )
				return true;
		if ( bLocalsAlso ) {
			const std::set<AttributeImpl*>& setLocals = ( (FCOImpl*) getCounted() )->getAttributes();
			for ( std::set<AttributeImpl*>::const_iterator ita = setLocals.begin() ; ita != setLocals.end() ; ita++ )
				if ( *ita == attribute.getCounted( false ) )
					return true;
		}
		return false;
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Atom
//
//###############################################################################################################################################

	Atom::Atom( ObjectImpl* pObject )
		: FCO( pObject )
	{
		castObjectImpl( OT_Atom );
	}

	Atom::Atom( const MetaObject& object )
		: FCO( object )
	{
		castObjectImpl( OT_Atom );
	}

	Atom::Atom( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaAtom> spAtom = spObject;
		setCounted( AtomImpl::attach( spAtom ) );
	}

	Atom& Atom::operator = ( const MetaObject& object )
	{
		FCO::operator=( object );
		castObjectImpl( OT_Atom );
		return *this;
	}

	AtomPtr Atom::getAtomI() const
	{
		return ( (AtomImpl*) getCounted() )->getAtomI();
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Model
//
//###############################################################################################################################################

	Model::Model( ObjectImpl* pObject )
		: FCO( pObject )
	{
		castObjectImpl( OT_Model );
	}

	Model::Model( const MetaObject& object )
		: FCO( object )
	{
		castObjectImpl( OT_Model );
	}

	Model::Model( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaModel> spModel = spObject;
		setCounted( ModelImpl::attach( spModel ) );
	}

	Model& Model::operator = ( const MetaObject& object )
	{
		FCO::operator=( object );
		castObjectImpl( OT_Model );
		return *this;
	}

	ModelPtr Model::getModelI() const
	{
		return ( (ModelImpl*) getCounted() )->getModelI();
	}

	std::set<Containment> Model::childContainments() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), Containment, ( (ContainmentImpl*) (*it) )->getParent() == getCounted(), *it );
	}

	std::set<FCO> Model::childFCOs() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), FCO, ( (ContainmentImpl*) (*it) )->getParent() == getCounted(), ( (ContainmentImpl*) (*it) )->getChild() );
	}

	std::set<Atom> Model::childAtoms() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), Atom, ( (ContainmentImpl*) (*it) )->getParent() == getCounted() && ( (ContainmentImpl*) (*it) )->getChild()->getType() == OT_Atom, ( (ContainmentImpl*) (*it) )->getChild() );
	}

	std::set<Model> Model::childModels() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), Model, ( (ContainmentImpl*) (*it) )->getParent() == getCounted() && ( (ContainmentImpl*) (*it) )->getChild()->getType() == OT_Model, ( (ContainmentImpl*) (*it) )->getChild() );
	}

	std::set<Connection> Model::childConnections() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), Connection, ( (ContainmentImpl*) (*it) )->getParent() == getCounted() && ( (ContainmentImpl*) (*it) )->getChild()->getType() == OT_Connection, ( (ContainmentImpl*) (*it) )->getChild() );
	}

	std::set<Set> Model::childSets() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), Set, ( (ContainmentImpl*) (*it) )->getParent() == getCounted() && ( (ContainmentImpl*) (*it) )->getChild()->getType() == OT_Set, ( (ContainmentImpl*) (*it) )->getChild() );
	}

	std::set<Reference> Model::childReferences() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), Reference, ( (ContainmentImpl*) (*it) )->getParent() == getCounted() && ( (ContainmentImpl*) (*it) )->getChild()->getType() == OT_Reference, ( (ContainmentImpl*) (*it) )->getChild() );
	}

	bool Model::isFCOChild( const FCO& fco ) const
	{
		FINDRELATION( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Role ), ( (ContainmentImpl*) (*it) )->getParent() == getCounted() && ( (ContainmentImpl*) (*it) )->getChild() == fco.getCounted( false ) );
	}

	std::set<ModelInAspect> Model::modelInAspects() const
	{
		FULLFILTER( ModelInAspectImpl*, ( (ProjectImpl*) project().getCounted() )->getModelInAspects(), ModelInAspect, (*it)->getModel() == getCounted(), *it );
	}

	std::set<Aspect> Model::aspects() const
	{
		FULLFILTER( ModelInAspectImpl*, ( (ProjectImpl*) project().getCounted() )->getModelInAspects(), Aspect, (*it)->getModel() == getCounted(), (*it)->getAspect() );
	}

	bool Model::hasAspect( const Aspect& aspect ) const
	{
		FINDRELATION( ModelInAspectImpl*, ( (ProjectImpl*) project().getCounted() )->getModelInAspects(), (*it)->getModel() == getCounted() && (*it)->getAspect() == aspect.getCounted( false ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionRole
//
//###############################################################################################################################################

	ConnectionRole::ConnectionRole()
		: Util::GenRefCounter( NULL )
	{
	}

	ConnectionRole::ConnectionRole( ConnectionRoleImpl* pConnectionRole )
		: Util::GenRefCounter( pConnectionRole )
	{
	}

	ConnectionRole::ConnectionRole( const ConnectionRole& connectionRole )
		: Util::GenRefCounter( connectionRole )
	{
	}

	ConnectionRole& ConnectionRole::operator = ( const ConnectionRole&  connectionRole )
	{
		using namespace Util;
		GenRefCounter::operator=( connectionRole );
		return *this;
	}

	Project ConnectionRole::project() const
	{
		return ( (ConnectionRoleImpl*) getCounted() )->getProject();
	}

	ConnectionSpecification ConnectionRole::specification() const
	{
		return ( (ConnectionRoleImpl*) getCounted() )->getConnectionSpec();
	}

	std::string	ConnectionRole::name() const
	{
		return ( (ConnectionRoleImpl*) getCounted() )->getName();
	}

	std::set<ConnectionEnd> ConnectionRole::connectionEnds() const
	{
		FULLFILTER( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), ConnectionEnd, (*it)->getConnectionRole() == getCounted(), *it );
	}

	std::set<Containment> ConnectionRole::targetRoles() const
	{
		FULLFILTER( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), Containment, (*it)->getConnectionRole() == getCounted(), (*it)->getEnd() );
	}

	std::set<FCO> ConnectionRole::targets() const
	{
		FULLFILTER( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), FCO, (*it)->getConnectionRole() == getCounted(), (*it)->getEnd()->getChild() );
	}

	bool ConnectionRole::isTarget( const FCO& fco ) const
	{
		FINDRELATION( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), (*it)->getConnectionRole() == getCounted() && (*it)->getEnd()->getChild() == fco.getCounted( false ) );
	}

	bool ConnectionRole::isTarget( const Containment& containment ) const
	{
		FINDRELATION( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), (*it)->getConnectionRole() == getCounted() && (*it)->getEnd() == containment.getCounted( false ) );
	}

	std::string ConnectionRole::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (ConnectionRoleImpl*) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionSpecification
//
//###############################################################################################################################################

	ConnectionSpecification::ConnectionSpecification()
		: Util::GenRefCounter( NULL )
	{
	}

	ConnectionSpecification::ConnectionSpecification( ConnectionSpecImpl* pConnectionSpec )
		: Util::GenRefCounter( pConnectionSpec )
	{
	}

	ConnectionSpecification::ConnectionSpecification( const ConnectionSpecification& connectionSpec )
		: Util::GenRefCounter( connectionSpec )
	{
	}

	ConnectionSpecification& ConnectionSpecification::operator = ( const ConnectionSpecification&  connectionSpec )
	{
		using namespace Util;
		GenRefCounter::operator=( connectionSpec );
		return *this;
	}

	Project ConnectionSpecification::project() const
	{
		return ( (ConnectionSpecImpl*) getCounted() )->getProject();
	}

	Connection ConnectionSpecification::connection() const
	{
		return ( (ConnectionSpecImpl*) getCounted() )->getConnection();
	}

	int ConnectionSpecification::number() const
	{
		return ( (ConnectionSpecImpl*) getCounted() )->getNumber();
	}

	std::set<ConnectionRole> ConnectionSpecification::roles() const
	{
		FULLFILTER( ConnectionRoleImpl*, ( (ConnectionSpecImpl*) getCounted() )->getRoles(), ConnectionRole, true, *it );
	}

	ConnectionRole ConnectionSpecification::role( const std::string& strRoleName ) const
	{
		const std::set<ConnectionRoleImpl*>& setRoles = ( (ConnectionSpecImpl*) getCounted() )->getRoles();
		for ( std::set<ConnectionRoleImpl*>::const_iterator it = setRoles.begin() ; it != setRoles.end() ; it++ )
			if ( (*it)->getName() == strRoleName )
				return *it;
		return NULL;
	}

	std::string ConnectionSpecification::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (ConnectionSpecImpl*) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Connection
//
//###############################################################################################################################################

	Connection::Connection( ObjectImpl* pObject )
		: FCO( pObject )
	{
		castObjectImpl( OT_Connection );
	}

	Connection::Connection( const MetaObject& object )
		: FCO( object )
	{
		castObjectImpl( OT_Connection );
	}

	Connection::Connection( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaConnection> spConnection = spObject;
		setCounted( ConnectionImpl::attach( spConnection ) );
	}

	Connection& Connection::operator = ( const MetaObject& object )
	{
		FCO::operator=( object );
		castObjectImpl( OT_Connection );
		return *this;
	}

	ConnectionPtr Connection::getConnectionI() const
	{
		return ( (ConnectionImpl*) getCounted() )->getConnectionI();
	}

	bool Connection::isSimple() const
	{
		return ( (ConnectionImpl*) getCounted() )->isSimple();
	}

	bool Connection::isBidirectional() const
	{
		return ( (ConnectionImpl*) getCounted() )->isBidirectional();
	}

	std::set<ConnectionSpecification> Connection::specifications() const
	{
		FULLFILTER( ConnectionSpecImpl*, ( (ConnectionImpl*) getCounted() )->getConnectionSpecs(), ConnectionSpecification, true, *it );
	}

	int Connection::specificationCount() const
	{
		return ( (ConnectionImpl*) getCounted() )->getConnectionSpecs().size();
	}

	ConnectionSpecification Connection::specification( int iNum ) const
	{
		const std::set<ConnectionSpecImpl*>& setSpecs = ( (ConnectionImpl*) getCounted() )->getConnectionSpecs();
		for ( std::set<ConnectionSpecImpl*>::const_iterator it = setSpecs.begin() ; it != setSpecs.end() ; it++ )
			if ( (*it)->getNumber() == iNum )
				return *it;
		return NULL;
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Set
//
//###############################################################################################################################################

	Set::Set( ObjectImpl* pObject )
		: FCO( pObject )
	{
		castObjectImpl( OT_Set );
	}

	Set::Set( const MetaObject& object )
		: FCO( object )
	{
		castObjectImpl( OT_Set );
	}

	Set::Set( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaSet> spSet = spObject;
		setCounted( SetImpl::attach( spSet ) );
	}

	Set& Set::operator = ( const MetaObject& object )
	{
		FCO::operator=( object );
		castObjectImpl( OT_Set );
		return *this;
	}

	SetPtr Set::getSetI() const
	{
		return ( (SetImpl*) getCounted() )->getSetI();
	}

	std::set<SetMembership> Set::memberships() const
	{
		FULLFILTER( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), SetMembership, (*it)->getSet() == getCounted(), *it );
	}

	std::set<Containment> Set::memberRoles() const
	{
		FULLFILTER( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), Containment, (*it)->getSet() == getCounted(), (*it)->getMember() );
	}

	// method used by the BON::SetImpl::addMember and BON::SetImpl::removeMember
	bool Set::isMember( const Containment& role ) const
	{
		FINDRELATION( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), (*it)->getSet() == getCounted() && (*it)->getMember()== role.getCounted( false ) );
	}

	// method added by ZolMol
	// because the BON::SetImpl::getMembers() method uses MON::FCO
	// instead of MON::Containment to inquire Set::isMember
	bool Set::isMember( const FCO& fco ) const
	{
		FINDRELATION( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), (*it)->getSet() == getCounted() && (*it)->getMember()->getChild() == fco.getCounted( false ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Reference
//
//###############################################################################################################################################

	Reference::Reference( ObjectImpl* pObject )
		: FCO( pObject )
	{
		castObjectImpl( OT_Reference );
	}

	Reference::Reference( const MetaObject& object )
		: FCO( object )
	{
		castObjectImpl( OT_Reference );
	}

	Reference::Reference( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaReference> spReference = spObject;
		setCounted ( ReferenceImpl::attach( spReference ) );
	}

	Reference& Reference::operator = ( const MetaObject& object )
	{
		FCO::operator=( object );
		castObjectImpl( OT_Reference );
		return *this;
	}

	ReferencePtr Reference::getReferenceI() const
	{
		return ( (ReferenceImpl*) getCounted() )->getReferenceI();
	}

	std::set<ReferenceAssociation> Reference::refAssociations() const
	{
		FULLFILTER( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), ReferenceAssociation, (*it)->getReference() == getCounted(), *it );
	}

	std::set<FCO> Reference::targetFCOs() const // changed from Containment to FCO by ZolMol
	{
		FULLFILTER( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), FCO, (*it)->getReference() == getCounted(), (*it)->getTarget() );
		// old: FULLFILTER( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), Containment, (*it)->getReference() == getCounted(), (*it)->getTarget() ); 
	}

	bool Reference::isReferenced( const FCO& fco ) const
	{
		FINDRELATION( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), (*it)->getReference() == getCounted() && (*it)->getTarget() == fco.getCounted( false ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Containment
//
//###############################################################################################################################################

	Containment::Containment( ObjectImpl* pObject )
		: MetaObject( pObject )
	{
		castObjectImpl( OT_Role );
	}

	/*Containment::Containment( const MetaObject& object )
		: MetaObject( object )
	{
		castObjectImpl( OT_Role );
	} Commented out by ZolMol */

	Containment::Containment( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaRole> spRole = spObject;
		setCounted( ContainmentImpl::attach( spRole ) );
	}

	Containment& Containment::operator = ( const MetaObject& object )
	{
		MetaObject::operator=( object );
		castObjectImpl( OT_Role );
		return *this;
	}

	ContainmentPtr Containment::getContainmentI() const
	{
		return ( (ContainmentImpl*) getCounted() )->getContainmentI();
	}

	Model Containment::parent() const
	{
		return ( (ContainmentImpl*) getCounted() )->getParent();
	}

	FCO Containment::child() const
	{
		return ( (ContainmentImpl*) getCounted() )->getChild();
	}

	std::set<ConnectionEnd> Containment::connectionEnds() const
	{
		FULLFILTER( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), ConnectionEnd, (*it)->getEnd() == getCounted(), *it );
	}

	std::set<ConnectionRole> Containment::targetOf() const
	{
		FULLFILTER( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), ConnectionRole, (*it)->getEnd() == getCounted(), (*it)->getConnectionRole() );
	}

	bool Containment::isTargetOf( const ConnectionRole& role ) const
	{
		FINDRELATION( ConnectionEndImpl*, ( (ProjectImpl*) project().getCounted() )->getConnectionEnds(), (*it)->getEnd() == getCounted() && (*it)->getConnectionRole() == role.getCounted( false ) );
	}

	std::set<ContainmentPart> Containment::parts() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Part ), ContainmentPart, ( (ContainmentPartImpl*) (*it) )->getContainment() == getCounted(), *it );
	}

	std::set<Aspect> Containment::aspects() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Part ), Aspect, ( (ContainmentPartImpl*) (*it) )->getContainment() == getCounted(), ( (ContainmentPartImpl*) (*it) )->getAspect() );
	}

	bool Containment::isVisibleIn( const Aspect& aspect ) const
	{
		FINDRELATION( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Part ), ( (ContainmentPartImpl*) (*it) )->getContainment() == getCounted() && ( (ContainmentPartImpl*) (*it) )->getAspect() == aspect.getCounted( false ) );
	}

	std::set<ReferenceAssociation> Containment::referenceAssociations() const
	{
		FULLFILTER( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), ReferenceAssociation, (*it)->getTarget() == getCounted(), *it );
	}

	std::set<Reference> Containment::referencedBy() const
	{
		FULLFILTER( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), Reference, (*it)->getTarget() == getCounted(), (*it)->getReference() );
	}

	bool Containment::isReferencedBy( const Reference& reference ) const
	{
		FINDRELATION( ReferenceAssocImpl*, ( (ProjectImpl*) project().getCounted() )->getReferenceAssocs(), (*it)->getTarget() == getCounted() && (*it)->getReference() == reference.getCounted( false ) );
	}

	std::set<SetMembership> Containment::setMemberships() const
	{
		FULLFILTER( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), SetMembership, (*it)->getMember() == getCounted(), *it );
	}

	std::set<Set> Containment::memberOf() const
	{
		FULLFILTER( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), Set, (*it)->getMember() == getCounted(), (*it)->getSet() );
	}

	bool Containment::isMemberOf( const Set& set ) const
	{
		FINDRELATION( SetMembershipImpl*, ( (ProjectImpl*) project().getCounted() )->getSetMemberships(), (*it)->getMember() == getCounted() && (*it)->getSet() == set.getCounted( false ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Attribute
//
//###############################################################################################################################################

	Attribute::Attribute( ObjectImpl* pObject )
		: MetaObject( pObject )
	{
		castObjectImpl( OT_Attribute );
	}

	Attribute::Attribute( const MetaObject& object )
		: MetaObject( object )
	{
		castObjectImpl( OT_Attribute );
	}

	Attribute::Attribute( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaAttribute> spAttribute = spObject;
		setCounted( AttributeImpl::attach( spAttribute ) );
	}

	Attribute& Attribute::operator = ( const MetaObject& object )
	{
		MetaObject::operator=( object );
		castObjectImpl( OT_Attribute );
		return *this;
	}

	AttributePtr Attribute::getAttributeI() const
	{
		return ( (AttributeImpl*) getCounted() )->getAttributeI();
	}

	Util::Variant Attribute::defaultValue() const
	{
		return ( (AttributeImpl*) getCounted() )->getDefaultValue();
	}

	AttributeType Attribute::valueType() const
	{
		return ( (AttributeImpl*) getCounted() )->getValueType();
	}

	std::vector<Attribute::NameValue> Attribute::enumItems() const
	{
		return ( (AttributeImpl*) getCounted() )->getEnumItems();
	}

	FCO Attribute::owner() const
	{
		return ( (AttributeImpl*) getCounted() )->getOwner();
	}

	std::set<AttributeAggregation> Attribute::attributeAggregations() const
	{
		FULLFILTER( AttributeAggregationImpl*, ( (ProjectImpl*) project().getCounted() )->getAttributeAggregations(), AttributeAggregation, (*it)->getAttribute() == getCounted(), *it );
	}

	std::set<FCO> Attribute::FCOs() const
	{
		FULLFILTER( AttributeAggregationImpl*, ( (ProjectImpl*) project().getCounted() )->getAttributeAggregations(), FCO, (*it)->getAttribute() == getCounted(), (*it)->getFCO() );
	}

	bool Attribute::isContainedBy( const FCO& fco ) const
	{
		FINDRELATION( AttributeAggregationImpl*, ( (ProjectImpl*) project().getCounted() )->getAttributeAggregations(), (*it)->getAttribute() == getCounted() && (*it)->getFCO() == fco.getCounted( false ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Aspect
//
//###############################################################################################################################################

	Aspect::Aspect( ObjectImpl* pObject )
		: MetaObject( pObject )
	{
		castObjectImpl( OT_Aspect );
	}

	Aspect::Aspect( const MetaObject& object )
		: MetaObject( object )
	{
		castObjectImpl( OT_Aspect );
	}

	Aspect::Aspect( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaAspect> spAspect = spObject;
		setCounted( AspectImpl::attach( spAspect ) );
	}

	Aspect& Aspect::operator = ( const MetaObject& object )
	{
		MetaObject::operator=( object );
		castObjectImpl( OT_Aspect );
		return *this;
	}

	AspectPtr Aspect::getAspectI() const
	{
		return ( (AspectImpl*) getCounted() )->getAspectI();
	}

	std::set<ModelInAspect> Aspect::modelInAspects() const
	{
		FULLFILTER( ModelInAspectImpl*, ( (ProjectImpl*) project().getCounted() )->getModelInAspects(), ModelInAspect, (*it)->getAspect() == getCounted(), *it );
	}

	std::set<Model> Aspect::models() const
	{
		FULLFILTER( ModelInAspectImpl*, ( (ProjectImpl*) project().getCounted() )->getModelInAspects(), Model, (*it)->getAspect() == getCounted(), (*it)->getModel() );
	}

	bool Aspect::isContainedBy( const Model& model ) const
	{
		FINDRELATION( ModelInAspectImpl*, ( (ProjectImpl*) project().getCounted() )->getModelInAspects(), (*it)->getAspect() == getCounted() && (*it)->getModel() == model.getCounted( false ) );
	}

	std::set<ContainmentPart> Aspect::parts() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Part ), ContainmentPart, ( (ContainmentPartImpl*) (*it) )->getAspect() == getCounted(), *it );
	}

	std::set<Containment> Aspect::containments() const
	{
		FULLFILTER( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Part ), Containment, ( (ContainmentPartImpl*) (*it) )->getAspect() == getCounted(), ( (ContainmentPartImpl*) (*it) )->getContainment() );
	}

	bool Aspect::hasContainment( const Containment& containment ) const
	{
		FINDRELATION( ObjectImpl*, ( (ProjectImpl*) project().getCounted() )->getObjects( OT_Part ), ( (ContainmentPartImpl*) (*it) )->getAspect() == getCounted() && ( (ContainmentPartImpl*) (*it) )->getContainment() == containment.getCounted( false ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ContainmentPart
//
//###############################################################################################################################################

	ContainmentPart::ContainmentPart( ObjectImpl* pObject )
		: MetaObject( pObject )
	{
		castObjectImpl( OT_Part );
	}

	ContainmentPart::ContainmentPart( const MetaObject& object )
		: MetaObject( object )
	{
		castObjectImpl( OT_Aspect );
	}

	ContainmentPart::ContainmentPart( IMgaMetaBase* spObject )
	{
		CComQIPtr<IMgaMetaPart> spPart = spObject;
		setCounted( ContainmentPartImpl::attach( spPart ) );
	}

	ContainmentPart& ContainmentPart::operator = ( const MetaObject& object )
	{
		MetaObject::operator=( object );
		castObjectImpl( OT_Part );
		return *this;
	}

	PartPtr ContainmentPart::getPartI() const
	{
		return ( (ContainmentPartImpl*) getCounted() )->getPartI();
	}

	bool ContainmentPart::isLinked() const
	{
		return ( (ContainmentPartImpl*) getCounted() )->isLinked();
	}

	bool ContainmentPart::isPrimary() const
	{
		return ( (ContainmentPartImpl*) getCounted() )->isPrimary();
	}

	Containment ContainmentPart::containment() const
	{
		return ( (ContainmentPartImpl*) getCounted() )->getContainment();
	}

	Aspect ContainmentPart::aspect() const
	{
		return ( (ContainmentPartImpl*) getCounted() )->getAspect();
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::FolderContainment
//
//###############################################################################################################################################

	FolderContainment::FolderContainment()
		: Util::GenRefCounter( NULL )
	{
	}

	FolderContainment::FolderContainment( FolderContainmentImpl* pFolderContainment )
		: Util::GenRefCounter( pFolderContainment )
	{
	}

	FolderContainment::FolderContainment( const FolderContainment& folderContainment )
		: Util::GenRefCounter( folderContainment )
	{
	}

	FolderContainment& FolderContainment::operator=( const FolderContainment& folderContainment )
	{
		using namespace Util;
		GenRefCounter::operator =( folderContainment );
		return *this;
	}

	Project FolderContainment::project() const
	{
		return ( (FolderContainmentImpl*) getCounted() )->getProject();
	}

	Folder FolderContainment::parent() const
	{
		return ( (FolderContainmentImpl*) getCounted() )->getParent();
	}

	Object FolderContainment::child() const
	{
		return ( (FolderContainmentImpl*) getCounted() )->getChild();
	}

	std::string FolderContainment::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (FolderContainmentImpl*) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ReferenceAssociation
//
//###############################################################################################################################################

	ReferenceAssociation::ReferenceAssociation()
		: Util::GenRefCounter( NULL )
	{
	}

	ReferenceAssociation::ReferenceAssociation( ReferenceAssocImpl* pReferenceAssoc )
		: Util::GenRefCounter( pReferenceAssoc )
	{
	}

	ReferenceAssociation::ReferenceAssociation( const ReferenceAssociation& referenceAssoc )
		: Util::GenRefCounter( referenceAssoc )
	{
	}

	ReferenceAssociation& ReferenceAssociation::operator=( const ReferenceAssociation& referenceAssoc )
	{
		using namespace Util;
		GenRefCounter::operator=( referenceAssoc );
		return *this;
	}

	Project ReferenceAssociation::project() const
	{
		return ( (ReferenceAssocImpl* ) getCounted() )->getProject();
	}

	Reference ReferenceAssociation::reference() const
	{
		return ( (ReferenceAssocImpl* ) getCounted() )->getReference();
	}

	FCO ReferenceAssociation::target() const //ZolMol changed Containment to FCO
	{
		return ( (ReferenceAssocImpl* ) getCounted() )->getTarget();
	}

	std::string ReferenceAssociation::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (ReferenceAssocImpl* ) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::SetMembership
//
//###############################################################################################################################################

	SetMembership::SetMembership()
		: Util::GenRefCounter( NULL )
	{
	}

	SetMembership::SetMembership( SetMembershipImpl* pSetMembership )
		: Util::GenRefCounter( pSetMembership )
	{
	}

	SetMembership::SetMembership( const SetMembership& setMembership )
		: Util::GenRefCounter( setMembership )
	{

	}

	SetMembership& SetMembership::operator=( const SetMembership& setMembership )
	{
		using namespace Util;
		GenRefCounter::operator=( setMembership );
		return *this;
	}

	Project SetMembership::project() const
	{
		return ( (SetMembershipImpl*) getCounted() )->getProject();
	}

	Set SetMembership::set() const
	{
		return ( (SetMembershipImpl*) getCounted() )->getSet();
	}

	Containment SetMembership::member() const
	{
		return ( (SetMembershipImpl*) getCounted() )->getMember();
	}

	std::string SetMembership::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (SetMembershipImpl*) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ConnectionEnd
//
//###############################################################################################################################################

	ConnectionEnd::ConnectionEnd()
		: Util::GenRefCounter( NULL )
	{
	}

	ConnectionEnd::ConnectionEnd( ConnectionEndImpl* pConnectionEnd)
		: Util::GenRefCounter( pConnectionEnd )
	{
	}

	ConnectionEnd::ConnectionEnd( const ConnectionEnd& connectionEnd )
		: Util::GenRefCounter( connectionEnd )
	{
	}

	ConnectionEnd& ConnectionEnd::operator=( const ConnectionEnd& connectionEnd )
	{
		using namespace Util;
		GenRefCounter::operator=( connectionEnd );
		return *this;
	}

	Project ConnectionEnd::project() const
	{
		return ( (ConnectionEndImpl*) getCounted() )->getProject();
	}

	ConnectionRole ConnectionEnd::role() const
	{
		return ( (ConnectionEndImpl*) getCounted() )->getConnectionRole();
	}

	Containment ConnectionEnd::target() const
	{
		return ( (ConnectionEndImpl*) getCounted() )->getEnd();
	}

	std::string ConnectionEnd::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (ConnectionEndImpl*) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::ModelInAspect
//
//###############################################################################################################################################

	ModelInAspect::ModelInAspect()
		: Util::GenRefCounter( NULL )
	{
	}

	ModelInAspect::ModelInAspect( ModelInAspectImpl* pModelInAspect )
		: Util::GenRefCounter( pModelInAspect )
	{
	}

	ModelInAspect::ModelInAspect( const ModelInAspect& modelInAspect )
		: Util::GenRefCounter( modelInAspect )
	{
	}

	ModelInAspect& ModelInAspect::operator=( const ModelInAspect& modelInAspect )
	{
		using namespace Util;
		GenRefCounter::operator=( modelInAspect );
		return *this;
	}

	Project ModelInAspect::project() const
	{
		return ( (ModelInAspectImpl*) getCounted() )->getProject();
	}

	Aspect ModelInAspect::aspect() const
	{
		return ( (ModelInAspectImpl*) getCounted() )->getAspect();
	}

	Model ModelInAspect::model() const
	{
		return ( (ModelInAspectImpl*) getCounted() )->getModel();
	}

	std::string ModelInAspect::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (ModelInAspectImpl*) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::AttributeAggregation
//
//###############################################################################################################################################

	AttributeAggregation::AttributeAggregation()
		: Util::GenRefCounter( NULL )
	{
	}

	AttributeAggregation::AttributeAggregation( AttributeAggregationImpl* pAttributeAggr )
		: Util::GenRefCounter( pAttributeAggr )
	{
	}

	AttributeAggregation::AttributeAggregation( const AttributeAggregation& attributeAggr )
		: Util::GenRefCounter( attributeAggr )
	{
	}

	AttributeAggregation& AttributeAggregation::operator=( const AttributeAggregation& attributeAggr )
	{
		using namespace Util;
		GenRefCounter::operator=( attributeAggr );
		return *this;
	}

	Project AttributeAggregation::project() const
	{
		return ( (AttributeAggregationImpl*) getCounted() )->getProject();
	}

	FCO AttributeAggregation::fco() const
	{
		return ( (AttributeAggregationImpl*) getCounted() )->getFCO();
	}

	Attribute AttributeAggregation::attribute() const
	{
		return ( (AttributeAggregationImpl*) getCounted() )->getAttribute();
	}

	std::string AttributeAggregation::infoString( bool bWithIdentifiers, bool bWithRef ) const
	{
		return ( (AttributeAggregationImpl*) getCounted() )->getInfoString( bWithIdentifiers, bWithRef );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::RegistryNode
//
//###############################################################################################################################################

	RegistryNode::RegistryNode()
		: Util::GenRefCounter( NULL )
	{
	}

	RegistryNode::RegistryNode( const RegistryNode& node )
		: Util::GenRefCounter( node )
	{
	}

	RegistryNode::RegistryNode( RegistryNodeImpl* pRegistryNode )
		: Util::GenRefCounter( pRegistryNode )
	{
	}

	RegistryNode& RegistryNode::operator = ( const RegistryNode& node )
	{
		using namespace Util;
		GenRefCounter::operator=( node );
		return *this;
	}

	Project RegistryNode::project() const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getProject();
	}

	MetaObject RegistryNode::object() const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getObject();
	}

	RegNodePtr RegistryNode::getRegNodeI() const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getRegNodeI();
	}

	bool RegistryNode::isRoot() const
	{
		return ( (RegistryNodeImpl*) getCounted() )->isRootNode();
	}

	std::string RegistryNode::name() const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getName();
	}

	std::string RegistryNode::path() const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getPath();
	}

	std::string RegistryNode::value() const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getValue();
	}

	long RegistryNode::integerValue() const
	{
		return (long) Util::Variant( ( (RegistryNodeImpl*) getCounted() )->getValue() );
	}

	double RegistryNode::realValue() const
	{
		return (double) Util::Variant( ( (RegistryNodeImpl*) getCounted() )->getValue() );
	}

	bool RegistryNode::boolValue() const
	{
		return (bool) Util::Variant( ( (RegistryNodeImpl*) getCounted() )->getValue() );
	}

	std::string RegistryNode::valueByPath( const std::string& strPath ) const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getValueByPath( strPath );
	}

	RegistryNode RegistryNode::parent() const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getParent();
	}

	std::set<RegistryNode> RegistryNode::children() const
	{
		FULLFILTER( RegistryNodeImpl*, ( (RegistryNodeImpl*) getCounted() )->getChildren(), RegistryNode, true, *it );
	}

	RegistryNode RegistryNode::child( const std::string& strName ) const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getChild( strName );
	}

	RegistryNode RegistryNode::childByPath( const std::string& strPath ) const
	{
		return ( (RegistryNodeImpl*) getCounted() )->getChildByPath( strPath );
	}

//###############################################################################################################################################
//
// 	C L A S S : MON::Constraint
//
//###############################################################################################################################################

	Constraint::Constraint()
		: Util::GenRefCounter( NULL )
	{
	}

	Constraint::Constraint( const Constraint& constraint )
		: Util::GenRefCounter( constraint )
	{
	}

	Constraint::Constraint( ConstraintImpl* pConstraint )
		: Util::GenRefCounter( pConstraint )
	{
	}

	Constraint& Constraint::operator = ( const Constraint& constraint )
	{
		using namespace Util;
		GenRefCounter::operator=( constraint );
		return *this;
	}

	Project Constraint::project() const
	{
		return ( (ConstraintImpl*) getCounted() )->getProject();
	}

	Object Constraint::object() const
	{
		return ( (ConstraintImpl*) getCounted() )->getObject();
	}

	ConstraintPtr Constraint::getConstraintI() const
	{
		return ( (ConstraintImpl*) getCounted() )->getConstraintI();
	}

	std::string Constraint::name() const
	{
		return ( (ConstraintImpl*) getCounted() )->getName();
	}

	std::string	Constraint::description() const
	{
		return ( (ConstraintImpl*) getCounted() )->getDescription();
	}

	std::vector<std::string> Constraint::equation() const
	{
		return ( (ConstraintImpl*) getCounted() )->getEquation();
	}

	std::set<ObjectEventType> Constraint::events() const
	{
		return ( (ConstraintImpl*) getCounted() )->getEvents();
	}

	ConstraintPriority Constraint::priority() const
	{
		return ( (ConstraintImpl*) getCounted() )->getPriority();
	}

	ConstraintDepth Constraint::depth() const
	{
		return ( (ConstraintImpl*) getCounted() )->getDepth();
	}

}; // namespace MON
