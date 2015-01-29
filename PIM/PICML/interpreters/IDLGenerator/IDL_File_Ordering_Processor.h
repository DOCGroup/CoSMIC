//=============================================================================
/**
 *  @file       IDL_File_Ordering_Processor.h
 *
 *  File contains the class IDL_File_Ordering_Processor.
 *
 *  $Id:$
 *
 *  @author     Harold Owens II <owensh@cs.iupui.edu>
 */
//=============================================================================

#ifndef _IDL_FILE_ORDERING_PROCESSOR_H_
#define _IDL_FILE_ORDERING_PROCESSOR_H_

#include <map>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/shared_ptr.hpp>

#include "PICML/PICML.h"
#include "PICML/Visitor.h"

/**
 * @class IDL_File_Ordering_Processor
 *
 * @brief Implementation of the IDL_File_Ordering_Processor that is responsible for
 * preprocessing file elements to determine the ordering between elements within a
 * file.
 */
class IDL_File_Ordering_Processor  : public PICML::Visitor
{
public:
  /**
   * @class Udm_Object
   *
   * @brief Struct used by boost to add properties to vertices.
   */
  struct Object
  {
    typedef boost::vertex_property_tag kind;
  };

  /// Type definitions
  typedef boost::property<Object, GAME::Mga::Object> VERTEX_PROPERTY;
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, VERTEX_PROPERTY> GRAPH;
  typedef boost::graph_traits<GRAPH>::vertex_descriptor VERTEX;
  typedef boost::graph_traits<GRAPH>::edge_descriptor EDGE;
  typedef boost::graph_traits<GRAPH>::vertex_iterator VERTEX_ITER;
  typedef boost::property_map<GRAPH, Object>::type OBJECT_ACCESSOR;
  typedef std::vector<VERTEX> CONTAINER;
  typedef std::vector<EDGE> EDGE_CONTAINER;
  typedef std::vector<VERTEX>::const_reverse_iterator VECTOR_IT;
  typedef std::vector<EDGE>::iterator EDGE_IT;
  typedef std::map<GAME::Mga::Object, bool> MAP;
  typedef boost::shared_ptr<GRAPH> GRAPH_PTR;
  typedef std::list<std::pair<GAME::Mga::Object, GRAPH_PTR> > LIST;
  typedef std::list<std::pair<VERTEX, GRAPH_PTR> > VERTEX_GRAPH;
  typedef std::list<std::pair<VERTEX, GRAPH_PTR> >::iterator FORWARD_IT;

public:
  /// Default constructor.
  IDL_File_Ordering_Processor (void);

  /// Destructor.
  virtual ~IDL_File_Ordering_Processor (void);

  /**
   * Visitor methods used to visit the package type
   *
   * @param[in]      p      A package to visit
   */
  virtual void visit_Package (PICML::Package_in p);
  void visit_package (PICML::Package_in p, PICML::Visitor * v);

  /**
   * Visitor methods used to visit the aggregate type
   *
   * @param[in]      a      An aggregate to visit
   */
  virtual void visit_Aggregate (const PICML::Aggregate & a);

  /**
   * Visitor methods used to visit the switched aggregate type
   *
   * @param[in]      s      A switched aggregate to visit
   */
  virtual void visit_SwitchedAggregate (const PICML::SwitchedAggregate & s);

  /**
   * Visitor methods used to visit the array member type
   *
   * @param[in]      m      An array member to visit
   */
  virtual void visit_ArrayMember (PICML::ArrayMember_in m);

  /**
   * Visitor methods used to visit the boxed type
   *
   * @param[in]      b      A boxed to visit
   */
  virtual void visit_Boxed (PICML::Boxed_in b);

  /**
  * Visitor methods used to visit the member type
  *
  * @param[in]      a      An array member to visit
  */
  virtual void visit_Member (PICML::Member_in a);

  /**
  * Visitor methods used to visit the enum type
  *
  * @param[in]      e      An enum to visit
  */
  virtual void visit_Enum (PICML::Enum_in e);

  /**
  * Visitor methods used to visit the constant type
  *
  * @param[in]      c      A constant to visit
  */
  virtual void visit_Constant (PICML::Constant_in c);

  /**
  * Visitor methods used to visit the alias type
  *
  * @param[in]      a      An alias to visit
  */
  virtual void visit_Alias (PICML::Alias_in a);

  /**
  * Visitor methods used to visit the collection type
  *
  * @param[in]      c      A collection to visit
  */
  virtual void visit_Collection (PICML::Collection_in c);

  /**
  * Visitor methods used to visit the exception type
  *
  * @param[in]      e      An exception to visit
  */
  virtual void visit_Exception (PICML::Exception_in e);

  /**
  * Visitor methods used to visit the template package instance type
  *
  * @param[in]      t      A template package instance to visit
  */
  virtual void visit_TemplatePackageInstance (const PICML::TemplatePackageInstance & t);

  /**
  * Visitor methods used to visit the one way operation type
  *
  * @param[in]      o      A one way operation instance to visit
  */
  virtual void visit_OnewayOperation (const PICML::OnewayOperation & o);

  /**
  * Visitor methods used to visit the two way operation type
  *
  * @param[in]      t      A two way operation instance to visit
  */
  virtual void visit_TwowayOperation (const PICML::TwowayOperation & t);

  /**
  * Visitor methods used to visit the object type
  *
  * @param[in]      t      A template package instance to visit
  */
  virtual void visit_Object (PICML::Object_in o);

  /**
  * Visitor methods used to visit the port type
  *
  * @param[in]      p      A port to visit
  */
  virtual void visit_PortType (PICML::PortType_in p);

  /**
  * Visitor methods used to visit the value object type
  *
  * @param[in]      o      A value object to visit
  */
  virtual void visit_ValueObject (PICML::ValueObject_in o);

  /**
  * Visitor methods used to visit the event type
  *
  * @param[in]      e      An event to visit
  */
  virtual void visit_Event (const PICML::Event & e);

  /**
  * Visitor methods used to visit the component type
  *
  * @param[in]      c      A component to visit
  */
  virtual void visit_Component (const PICML::Component & c);

  /**
  * Visitor methods used to visit the connector object type
  *
  * @param[in]      c      A connector object to visit
  */
  virtual void visit_ConnectorObject (PICML::ConnectorObject_in c);

  /**
  * Visitor methods used to visit the component factory type
  *
  * @param[in]      c      A component factory to visit
  */
  virtual void visit_ComponentFactory (PICML::ComponentFactory_in c);

  /**
  * Visitor methods used to visit the read only type
  *
  * @param[in]      r      A read only attribute to visit
  */
  virtual void visit_ReadonlyAttribute(const PICML::ReadonlyAttribute & r);

  /**
  * Visitor methods used to visit the attribute type
  *
  * @param[in]      a      An attribute to visit
  */
  virtual void visit_Attribute (const PICML::Attribute & a);

  /**
  * Visitor methods used to visit the aManagesComponent type
  *
  * @param[in]      m      A ManagesComponent to visit
  */
  virtual void visit_ManagesComponent (const PICML::ManagesComponent & m);

  /**
  * Visits the file object
  *
  * @param[in]      o      A object to visit
  * @param[in]      f      Is forward declaration
  */
  void visit_file (const PICML::File & o, bool f = false);

  /**
  * Gets the objects processed by this in topological order
  *
  * @param[in]      c      A container that holds the object
  */
  void topological_sort (CONTAINER & c);

  /**
  * Clears the state of file order processor.
  *
  * @param[in]      c      A bool that determines if the forward
  * declarations state should be cleared
  */
  void clear (bool c = false);

  /**
  * Gets the graph created by file order processor
  *
  * @returns      GRAPH      a directed graph that is a topology of the
  * objects dependencies
  */
  const GRAPH & graph (void);

  /**
   * Determines if template module should be visited
   *
   * @returns      bool      true if template module should be visited false
   * otherwise
   */
  bool visit_template_module (void);

  /**
   * Sets the visit template module state
   *
   * @param[in]      v      true template modules should be
   * visited false not visited
   */
  void visit_template_module (bool v);

  /**
   * Process a file forward declarations
   */
  void process_forward_declaration (void);

  /**
   * Determines if an element should be visited
   *
   * @param[in]      o      a udm object to check for forward declaration
   * @return      bool      true if object should be forward declared
   * otherwise false
   */
  bool no_forward_declaration (const GAME::Mga::Object_in o);

  /**
   * Determines if there are elements to forward declare
   *
   * @retval      true      There are forward declarable objects.
   */
  bool forward_declaration (void);

private:
  void visit_file_package (const GAME::Mga::Object_in o);
  void add_node (const GAME::Mga::Object & o);

  template <typename T, typename P>
  void add_edge (const GAME::Mga::Model & o);

  void add_edge (const GAME::Mga::Object_in o);

  void topological_sort_i (CONTAINER & container);

  VERTEX find_vertex (const GAME::Mga::Object_in o, GRAPH_PTR graph, bool & found);

  void remove_back_edges (GRAPH_PTR g);

  void forward_declaration_i (void);

  void insert (const GAME::Mga::Object_in o);

  void set_forward_declaration (VERTEX & v, GRAPH_PTR g);

  void insert (CONTAINER & c);

  void add_vertex (const GAME::Mga::FCO & o, GRAPH_PTR g);

  void add_vertices (const GAME::Mga::FCO & p1, const GAME::Mga::FCO & p2, GRAPH_PTR g);

  template <typename T>
  GAME::Mga::Object find_parent (const GAME::Mga::Object & o);

  bool same_parent_before_file (const GAME::Mga::Object_in o, const GAME::Mga::Object_in p);

  GAME::Mga::FCO parent_before_file (const GAME::Mga::Object_in o);

  bool parent_in_same_file (const GAME::Mga::Object_in o, const GAME::Mga::Object_in p);

  GAME::Mga::Object parent_file (const GAME::Mga::Object_in o);

  GRAPH_PTR                   current_graph_;///< contains current graph that is being processed
  VERTEX_GRAPH                forward_decl_;///< contains the elements that need to be foward declared
  EDGE_CONTAINER              edge_;///< contains the back edges in the graph
  MAP                         map_;///< holds the objects unique ids used for look up
  MAP                         forward_;///< holds the objects unique ids which should be forward declared
  bool                        visit_template_module_;///< visit template module
  bool                        forward_declaration_;///< processing forward declarations
  LIST                        list_;///< holds the packages with its associated graph of objects
};

#include "IDL_File_Ordering_Processor.inl"

#endif   /* _IDL_FILE_ORDERING_PROCESSOR_H_ */
