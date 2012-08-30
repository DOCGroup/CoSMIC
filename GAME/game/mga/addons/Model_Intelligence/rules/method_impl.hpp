#ifndef _METHOD_IMPL_H_
#define _METHOD_IMPL_H_

#include "method.hpp"


template <typename IteratorT>
method <IteratorT>::method (void)
: method::base_type (method_)
{ 
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->method_ %= this->parts_method_ | this->size_method_ | this->refers_to_method_ |
	  this->name_method_ | this->kindname_method_ | this->parent_method_ | this->childfolders_method_ |
	  this->rolename_method_ | this->connectedfcos_method_ | this->atomparts_method_ | this->modelparts_method_ |
    this->referenceparts_method_ | this->connectionparts_method_ | this->connectionpoints_method_ |
    this->connectionpoint_method_ | this->attachingconnpoints_method_ | this->attachingconnections_method_ |
    this->isconnectedto_method_ | this->subtypes_method_ | this->instances_method_ | this->type_method_ |
    this->basetype_method_ | this->isinstance_method_ | this->istype_method_ | this->folder_method_ |
    this->referencedby_method_ | this->models_method_ | this->atoms_method_ | this->usedbyconnpoints_method_ |
    this->target_method_ | this->owner_method_ | this->isfco_method_;

  // GME Model specific methods

  this->parts_method_ = qi::lit("parts") >>
	  qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <Parts_Method> (qi::_a)];

  this->atomparts_method_ = (qi::lit("atomParts") | qi::lit("atoms")) >>
	  qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <AtomParts_Method> (qi::_a)];

  this->modelparts_method_ = (qi::lit("modelParts") | qi::lit("models")) >>
	  qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <ModelParts_Method> (qi::_a)];

  this->referenceparts_method_ = qi::lit("referenceParts") >>
	  qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <ReferenceParts_Method> (qi::_a)];

  this->connectionparts_method_ = qi::lit("connectionParts") >>
	  qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <ConnectionParts_Method> (qi::_a)];

  this->size_method_ = qi::lit("size")[qi::_val = phoenix::new_ <Size_Method> ()];

  // GME Reference specific methods

  this->refers_to_method_ = qi::lit ("refersTo") >>
	  qi::lit ("(") >>
	  qi::lit (")")[qi::_val = phoenix::new_ <Refers_to_Method> ()];

  this->usedbyconnpoints_method_ = qi::lit ("usedByConnPoints") >>
	  (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <UsedByConnPoints_Method> ()] ) |
    (qi::lit ("(") >> 
       this->id_ [qi::_val = phoenix::new_<UsedByConnPoints_Method> (qi::_1)] >>
       qi::lit (")"));

  // GME Object specific methods

  this->name_method_ = qi::lit ("name") >> -(qi::lit ("(") >> qi::lit (")"))
	  [qi::_val = phoenix::new_ <Name_Method> ()];

  this->kindname_method_ = qi::lit ("kindName") >> -(qi::lit ("(") >> qi::lit (")"))
	  [qi::_val = phoenix::new_ <KindName_Method> ()];

  this->parent_method_ = qi::lit ("parent") >> (qi::lit ("(") >> qi::lit (")"))
	  [qi::_val = phoenix::new_ <Parent_Method> ()];

  this->isfco_method_ = qi::lit ("isFCO") >> (qi::lit ("(") >> qi::lit (")"))
	  [qi::_val = phoenix::new_ <IsFCO_Method> ()];

  // GME Folder specific methods
  this->childfolders_method_ = qi::lit ("childFolders") >> (qi::lit ("(") >> qi::lit (")"))
	  [qi::_val = phoenix::new_ <ChildFolders_Method> ()];

  this->models_method_ = qi::lit ("models") >>
    ( (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <Models_Method> ()]) |
      (qi::lit ("(") >> this->id_[qi::_val = phoenix::new_<Models_Method> (qi::_1)] >>
       qi::lit (")")) );

  this->atoms_method_ = qi::lit ("atoms") >>
    ( (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <Atoms_Method> ()]) |
      (qi::lit ("(") >> this->id_[qi::_val = phoenix::new_<Atoms_Method> (qi::_1)] >>
       qi::lit (")")) );        

  // GME FCO specific methods

  this->rolename_method_ = qi::lit ("roleName") >> -(qi::lit ("(") >> qi::lit (")"))
	  [qi::_val = phoenix::new_ <RoleName_Method> ()];

  this->connectedfcos_method_ = qi::lit("connectedFCOs") >>
    ((qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <ConnectedFCOs_Method> ()]) |
    (qi::lit ("(") >> this->qs_[qi::_val = phoenix::new_<ConnectedFCOs_Method> (qi::_1)] >>
     qi::lit (")")) |
    (qi::lit ("(") >> this->id_[qi::_val = phoenix::new_<ConnectedFCOs_Method> (qi::_1)] >>
     qi::lit (")")) |
     (qi::lit ("(") >> this->qs_[qi::_a = qi::_1] >>
     this->id_[qi::_val = phoenix::new_<ConnectedFCOs_Method> (qi::_a, qi::_1)] >>
     qi::lit (")")) );

  this->attachingconnpoints_method_ = qi::lit ("attachingConnPoints") >>
    ((qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <AttachingConnPoints_Method> ()]) |
    (qi::lit ("(") >> this->qs_[qi::_val = phoenix::new_<AttachingConnPoints_Method> (qi::_1)] >>
     qi::lit (")")) |
    (qi::lit ("(") >> this->id_[qi::_val = phoenix::new_<AttachingConnPoints_Method> (qi::_1)] >>
     qi::lit (")")) |
     (qi::lit ("(") >> this->qs_[qi::_a = qi::_1] >>
     this->id_[qi::_val = phoenix::new_<AttachingConnPoints_Method> (qi::_a, qi::_1)] >>
     qi::lit (")")) );

  this->attachingconnections_method_ = qi::lit ("attachingConnections") >>
    ((qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <AttachingConnections_Method> ()]) |
    (qi::lit ("(") >> this->qs_[qi::_val = phoenix::new_<AttachingConnections_Method> (qi::_1)] >>
     qi::lit (")")) |
    (qi::lit ("(") >> this->id_[qi::_val = phoenix::new_<AttachingConnections_Method> (qi::_1)] >>
     qi::lit (")")) |
     (qi::lit ("(") >> this->qs_[qi::_a = qi::_1] >>
     this->id_[qi::_val = phoenix::new_<AttachingConnections_Method> (qi::_a, qi::_1)] >>
     qi::lit (")")) );

  this->isconnectedto_method_ = qi::lit ("isConnectedTo") >>
    ( (qi::lit ("(") >> this->id_[qi::_val = phoenix::new_<IsConnectedTo_Method> (qi::_1)] >>
        qi::lit (")")) | 
      (qi::lit ("(") >> this->id_[qi::_a = qi::_1] >>
        this->qs_[qi::_val = phoenix::new_<IsConnectedTo_Method> (qi::_a, qi::_1)] >>
        qi::lit (")")) |
      (qi::lit ("(") >> this->id_[qi::_a = qi::_1] >>
        this->id_[qi::_val = phoenix::new_<IsConnectedTo_Method> (qi::_a, qi::_1)] >>
        qi::lit (")")) |
      (qi::lit ("(") >> this->id_[qi::_a = qi::_1] >>
        this->qs_[qi::_b = qi::_1] >>
        this->id_[qi::_val = phoenix::new_<IsConnectedTo_Method> (qi::_a, qi::_b, qi::_1)] >>
        qi::lit (")")) );

  this->subtypes_method_ = qi::lit ("subTypes") >>
	  qi::lit ("(") >>
	  qi::lit (")")[qi::_val = phoenix::new_ <Subtypes_Method> ()];

  this->instances_method_ = qi::lit ("instances") >>
	  qi::lit ("(") >>
	  qi::lit (")")[qi::_val = phoenix::new_ <Instances_Method> ()];

  this->type_method_ = qi::lit ("type") >>
	  qi::lit ("(") >>
	  qi::lit (")")[qi::_val = phoenix::new_ <Type_Method> ()];

  this->basetype_method_ = qi::lit ("baseType") >>
	  qi::lit ("(") >>
	  qi::lit (")")[qi::_val = phoenix::new_ <Basetype_Method> ()];

  this->istype_method_ = qi::lit ("isType") >>
	  qi::lit ("(") >>
	  qi::lit (")")[qi::_val = phoenix::new_ <IsType_Method> ()];

  this->isinstance_method_ = qi::lit ("isInstance") >>
	  qi::lit ("(") >>
	  qi::lit (")")[qi::_val = phoenix::new_ <IsInstance_Method> ()];

  this->folder_method_ = qi::lit ("folder") >>
	  qi::lit ("(") >>
	  qi::lit (")")[qi::_val = phoenix::new_ <Folder_Method> ()];

  this->referencedby_method_ = qi::lit ("referencedBy") >>
	  (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <ReferencedBy_Method> ()] ) |
    (qi::lit ("(") >> 
       this->id_ [qi::_val = phoenix::new_<ReferencedBy_Method> (qi::_1)] >>
       qi::lit (")"));

  // GME Connection specific methods

  this->connectionpoints_method_ = qi::lit ("connectionPoints") >>
    ( (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <ConnectionPoints_Method> ()]) |
    (qi::lit ("(") >> this->qs_[qi::_val = phoenix::new_<ConnectionPoints_Method> (qi::_1)] >>
     qi::lit (")")) );

  this->connectionpoint_method_ = qi::lit ("connectionPoint") >>
    qi::lit ("(") >> 
    this->qs_[qi::_val = phoenix::new_<ConnectionPoint_Method> (qi::_1)] >>
    qi::lit (")");

  // GME ConnectionPoint specific methods

  this->target_method_ = qi::lit ("target") >> (qi::lit ("(") >> qi::lit (")"))
	  [qi::_val = phoenix::new_ <Target_Method> ()];

  this->owner_method_ = qi::lit ("owner") >> (qi::lit ("(") >> qi::lit (")"))
	  [qi::_val = phoenix::new_ <Owner_Method> ()];
}

#endif