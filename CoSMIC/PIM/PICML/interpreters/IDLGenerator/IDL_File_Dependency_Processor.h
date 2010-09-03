// $Id$

/**
 * @file IDL_File_Dependency_Processor.h
 * @author Harold Owens II <owensh@cs.iupui.edu>
 *
 *  File contains the class IDL_File_Dependency_Processor.
 */
#ifndef _IDL_FILE_DEPENDENCY_PROCESSOR_H_
#define _IDL_FILE_DEPENDENCY_PROCESSOR_H_

#include "IDL_File_Ordering_Processor.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "PICML/PICML.h"

namespace IDL_GENERATOR
{
/**
 * @class IDL_File_Dependency_Processor
 *
 * @brief Implementation of the IDL_File_Dependency_Processor that is responsible for 
 * preprocessing file elements to determine the dependency between 
 * elements.
 */
class IDL_File_Dependency_Processor
{
public:
  /// Default constructor.
  IDL_File_Dependency_Processor (void);
  /// Destructor.
  ~IDL_File_Dependency_Processor (void);
  /**
  * Visits the file
  *
  * @param[in]      o      A object to visit
  * @param[in]      v      Visitor used to visit the object o
  * module
  */
  void visit_file (const Udm::Object & o, 
                   PICML::Visitor & v);
  /**
  * Visit all childrems in object o
  *
  * @param[in]      o      A object to visit
  * @param[in]      v      Visitor used to visit the object o
  */
  void visit_all (const Udm::Object & o, 
                  PICML::Visitor & v);
  /**
  * Visit all childrems in object o
  *
  * @return      bool      true if template modules should be
  * visited false otherwise
  */
  bool visit_template_module (void);
  /**
  * Sets the visit template module state
  *
  * @param      bool      true if template modules should be
  * visited false otherwise
  */
  void visit_template_module (bool v);
  /**
  * Does the file has children
  */
  bool has_children (void);
  /**
  * Clears the state of file order processor.
  */
  void clear (void);

private:
  /// visit_file_package
  void visit_file_package (const Udm::Object & o, 
                           PICML::Visitor & v);
 /// visit_file_package
  void visit_file_package (const IDL_File_Ordering_Processor::CONTAINER & c,
                           PICML::Visitor & v);
                          
  IDL_File_Ordering_Processor   idl_order_proc_;///< visitor that visits file and determines order of elements
};
  typedef ACE_Singleton<IDL_File_Dependency_Processor, ACE_Null_Mutex> GLOBAL_IDL_DEPEND_PROCESSOR;
}; // namespace IDL_GENERATOR

#endif  /* _IDL_FILE_DEPENDENCY_PROCESSOR_H_ */
