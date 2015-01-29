namespace PICML
{
namespace Deployment
{

//
// External_Reference_Visitor
//
inline
External_Reference_Visitor::
External_Reference_Visitor (GAME::Xml::Fragment document, std::vector <GAME::Xml::Fragment> & conns)
: document_ (document),
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
