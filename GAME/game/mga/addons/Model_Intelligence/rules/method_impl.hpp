#ifndef _METHOD_IMPL_H_
#define _METHOD_IMPL_H_

#include "method.hpp"

//
// method
//
template <typename IteratorT>
method <IteratorT>::method (void)
: method::base_type (method_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->method_ %=
    this->model_methods_ |
    this->reference_methods_ |
    this->object_methods_ |
    this->connection_methods_ |
    this->folder_methods_ |
    this->rolename_method_ | this->connectedfcos_method_ |
    this->attachingconnpoints_method_ | this->attachingconnections_method_ |
    this->isconnectedto_method_ | this->subtypes_method_ | this->instances_method_ | this->type_method_ |
    this->basetype_method_ | this->isinstance_method_ | this->istype_method_ | this->folder_method_ |
    this->referencedby_method_;

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
}

#endif