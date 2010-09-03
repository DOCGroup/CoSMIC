// $Id$

/**
 * @file IDL_File_Ordering_Processor.h
 * @author Harold Owens II <owensh@cs.iupui.edu>
 *
 *  File contains the class IDL_File_Ordering_Processor.
 */
 
#ifndef _IDL_FILE_ORDERING_PROCESSOR_H_
#define _IDL_FILE_ORDERING_PROCESSOR_H_

#include <map>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>

#include "PICML/PICML.h"

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
  struct Udm_Object 
  {
    typedef boost::vertex_property_tag kind;
  };
  
  /// Type definitions
  typedef boost::property<Udm_Object, Udm::Object> VERTEX_PROPERTY;
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, VERTEX_PROPERTY> GRAPH;
  typedef boost::graph_traits<GRAPH>::vertex_descriptor VERTEX;
  typedef boost::graph_traits<IDL_File_Ordering_Processor::GRAPH>::vertex_iterator VERTEX_ITER;
  typedef boost::property_map<GRAPH, Udm_Object>::type ACCESSOR;
  typedef std::vector<VERTEX> CONTAINER;
  typedef std::vector<VERTEX>::const_reverse_iterator VECTOR_IT;
  typedef std::map<UDM_NAMESPACE::ObjectImpl::uniqueId_type, bool> MAP;
  
public:
  /// Default constructor.
  IDL_File_Ordering_Processor (void);
  /// Destructor.
  ~IDL_File_Ordering_Processor (void);
  /**
  * Visitor methods used to visit the package type
  *
  * @param[in]      p      A package to visit
  */
  virtual void Visit_Package (const PICML::Package & p);
  /**
  * Visitor methods used to visit the aggregate type
  *
  * @param[in]      a      An aggregate to visit
  */
  virtual void Visit_Aggregate (const PICML::Aggregate & a);
  /**
  * Visitor methods used to visit the switched aggregate type
  *
  * @param[in]      s      A switched aggregate to visit
  */
  virtual void Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s);
  /**
  * Visitor methods used to visit the array member type
  *
  * @param[in]      m      An array member to visit
  */
  virtual void Visit_ArrayMember (const PICML::ArrayMember & m);
  /**
  * Visitor methods used to visit the member type
  *
  * @param[in]      a      An array member to visit
  */
  virtual void Visit_Member (const PICML::Member & a);
  /**
  * Visitor methods used to visit the enum type
  *
  * @param[in]      e      An enum to visit
  */
  virtual void Visit_Enum (const PICML::Enum & e);
  /**
  * Visitor methods used to visit the constant type
  *
  * @param[in]      c      A constant to visit
  */
  virtual void Visit_Constant (const PICML::Constant & c);
  /**
  * Visitor methods used to visit the alias type
  *
  * @param[in]      a      An alias to visit
  */
  virtual void Visit_Alias (const PICML::Alias & a);
  /**
  * Visitor methods used to visit the collection type
  *
  * @param[in]      c      A collection to visit
  */
  virtual void Visit_Collection (const PICML::Collection & c);
  /**
  * Visitor methods used to visit the exception type
  *
  * @param[in]      e      An exception to visit
  */
  virtual void Visit_Exception (const PICML::Exception & e);
  /**
  * Visitor methods used to visit the template package instance type
  *
  * @param[in]      t      A template package instance to visit
  */
  virtual void Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance & t);
  /**
  * Visitor methods used to visit the object type
  *
  * @param[in]      t      A template package instance to visit
  */
  virtual void Visit_Object (const PICML::Object & o);
  /**
  * Visitor methods used to visit the port type
  *
  * @param[in]      p      A port to visit
  */
  virtual void Visit_PortType (const PICML::PortType & p);
  /**
  * Visitor methods used to visit the value object type
  *
  * @param[in]      o      A value object to visit
  */
  virtual void Visit_ValueObject (const PICML::ValueObject & o);
  /**
  * Visitor methods used to visit the event type
  *
  * @param[in]      e      An event to visit
  */
  virtual void Visit_Event (const PICML::Event & e);
  /**
  * Visitor methods used to visit the component type
  *
  * @param[in]      c      A component to visit
  */
  virtual void Visit_Component (const PICML::Component & c);
  /**
  * Visitor methods used to visit the connector object type
  *
  * @param[in]      c      A connector object to visit
  */
  virtual void Visit_ConnectorObject (const PICML::ConnectorObject & c);
  /**
  * Visitor methods used to visit the component factory type
  *
  * @param[in]      c      A component factory to visit
  */
  virtual void Visit_ComponentFactory (const PICML::ComponentFactory & c);
  /**
  * Visits the file object
  *
  * @param[in]      o      A object to visit
  */
  void visit_file (const Udm::Object & o);
  /**
  * Visits all the children within an object
  *
  * @param[in]      o      A object to visit
  * @param[in]      v      Visitor used to visit the object o
  */
  void visit_all (const Udm::Object & o, PICML::Visitor & v);
  /**
  * Gets the objects processed by this in topological order
  *
  * @param[in]      c      A container that holds the object
  */
  void topological_sort (CONTAINER & c);
  /**
  * Clears the state of file order processor.
  */
  void clear (void);
  /**
  * Gets the graph created by file order processor
  *
  * @returns      GRAPH      a directed graph that is a topology of the 
  * objects dependencies
  */
  const GRAPH & graph (void) const;
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
  * @param      bool      true if template modules should be
  * visited false otherwise
  */
  void visit_template_module (bool v);
  
private:
  /// visit_file_package
  void visit_file_package (const Udm::Object & o);
  /// add_node
  void add_node (const Udm::Object & o);
  /// add_edge 
  void add_edge (const Udm::Object & o);
  /// topological_sort_i
  void topological_sort_i (void);
  /// find_vertex
  VERTEX find_vertex (const Udm::Object & o);

  GRAPH                       graph_;///< contains a directed graph of the elements for the file package
  CONTAINER                   container_;///< holds the elements in topological order
  MAP                         map_;///< holds the objects unique ids used for look up
  bool                        visit_template_module_;///< visit template module
};

#endif   /* _IDL_FILE_ORDERING_PROCESSOR_H_ */
