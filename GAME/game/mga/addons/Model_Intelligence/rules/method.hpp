#ifndef _RULE_METHOD_H_
#define _RULE_METHOD_H_

#include <fstream>

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include <string>
#include <stack>
#include <functional>

#include "../Method.h"
#include "../Parts_Method.h"
#include "../AtomParts_Method.h"
#include "../ModelParts_Method.h"
#include "../ReferenceParts_Method.h"
#include "../ConnectionParts_Method.h"
#include "../Size_Method.h"
#include "../Refers_to_Method.h"
#include "../Name_Method.h"
#include "../KindName_Method.h"
#include "../Parent_Method.h"
#include "../ChildFolders_Method.h"
#include "../RoleName_Method.h"
#include "../ConnectedFCOs_Method.h"
#include "../AttachingConnPoints_Method.h"
#include "../AttachingConnections_Method.h"
#include "../IsConnectedTo_Method.h"
#include "../Subtypes_Method.h"
#include "../Instances_Method.h"
#include "../Type_Method.h"
#include "../Basetype_Method.h"
#include "../IsType_Method.h"
#include "../IsInstance_Method.h"
#include "../Folder_Method.h"
#include "../Models_Method.h"
#include "../Atoms_Method.h"
#include "../ReferencedBy_Method.h"
#include "../ConnectionPoints_Method.h"
#include "../ConnectionPoint_Method.h"
#include "../Target_Method.h"
#include "../Owner_Method.h"
#include "../UsedByConnPoints_Method.h"
#include "../IsFCO_Method.h"

#include "ident.hpp"
#include "connection_method.hpp"
#include "folder_method.hpp"
#include "model_method.hpp"
#include "object_method.hpp"
#include "reference_method.hpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/**
 * @class method
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class method : public qi::grammar <IteratorT,
                                   Method * (),
                                   ascii::space_type>
{
public:
    method ();

private:
  qi::rule <IteratorT,
            Method * (),
            ascii::space_type> method_;

  ::model_method <IteratorT> model_methods_;

  ::reference_method <IteratorT> reference_methods_;

  ::object_method <IteratorT> object_methods_;

  ::connection_method <IteratorT> connection_methods_;

  ::folder_method <IteratorT> folder_methods_;

  qi::rule <IteratorT,
            AttachingConnPoints_Method * (),
            ascii::space_type,
            qi::locals <std::string>> attachingconnpoints_method_;

  qi::rule <IteratorT,
            AttachingConnections_Method * (),
            ascii::space_type,
            qi::locals <std::string>> attachingconnections_method_;

  qi::rule <IteratorT,
            IsConnectedTo_Method * (),
            ascii::space_type,
            qi::locals <std::string,
                        std::string>> isconnectedto_method_;

  qi::rule <IteratorT,
            Subtypes_Method * (),
            ascii::space_type> subtypes_method_;

  qi::rule <IteratorT,
            Instances_Method * (),
            ascii::space_type> instances_method_;

  qi::rule <IteratorT,
            Type_Method * (),
            ascii::space_type> type_method_;

  qi::rule <IteratorT,
            IsType_Method * (),
            ascii::space_type> istype_method_;

  qi::rule <IteratorT,
            IsInstance_Method * (),
            ascii::space_type> isinstance_method_;

  qi::rule <IteratorT,
            Basetype_Method * (),
            ascii::space_type> basetype_method_;

  qi::rule <IteratorT,
            Folder_Method * (),
            ascii::space_type> folder_method_;

  qi::rule <IteratorT,
            ReferencedBy_Method * (),
            ascii::space_type> referencedby_method_;

  qi::rule <IteratorT,
            ConnectedFCOs_Method * (),
            ascii::space_type,
            qi::locals <std::string>> connectedfcos_method_;

  qi::rule <IteratorT,
            RoleName_Method * (),
            ascii::space_type> rolename_method_;

  ident <IteratorT> id_;

  quoted_string <IteratorT> qs_;
};

#endif
