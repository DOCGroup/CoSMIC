namespace PICML
{
namespace Deployment
{

//
// External_Reference_Visitor
//
inline
External_Reference_Visitor::
External_Reference_Visitor (GAME::Xml::Document doc, std::vector <GAME::Xml::Fragment> & conns)
: doc_ (doc),
  conns_ (conns)
{

}

//
// ~External_Reference_Visitor
//
inline
External_Reference_Visitor::~External_Reference_Visitor (void)
{

}

}
}
