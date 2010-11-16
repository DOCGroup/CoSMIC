// -*- C++ -*-

//=============================================================================
/**
 * @file      Project.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_PROJECT_H_
#define _GAME_XME_PROJECT_H_

#include <map>
#include <utility>
#include <memory>

#include "Library.h"
#include "Configuration.h"

namespace GAME
{
namespace XME
{
// Forward decl.
class GME_ID_Generator;

/**
 * @class Project
 *
 * Base class for all the objects
 */
class GAME_XME_Export Project
{
public:
  /**
   * Create a new project.
   *
   * @param[in]     paradigm      Name of the project's paradigm.
   * @param[in]     guid          Version guid of the paradigm
   */
  static Project _create (const GAME::Xml::String & xmefile,
                          const GAME::Xml::String & paradigm,
                          const GAME::Xml::String & guid,
                          const Configuration * config = GLOBAL_CONFIG::instance ());

  /**
   * Open an existing file.
   *
   * @paramp[in]
   */
  static Project _open (const GAME::Xml::String & location,
                        const Configuration * config = GLOBAL_CONFIG::instance ());

  /// Default constructor.
  Project (void);

  /**
   * Copy constructor
   *
   * @param[in]     obj           Source project
   */
  Project (const Project & proj);

  /// Destructor.
  ~Project (void);

  /**
   * Save the project to the specified XME file name. If a
   * target file already existed, then it will be replaced by
   * this XME file.
   *
   * @param[in]     xmefile       Name of the XME file.
   */
  bool save (const GAME::Xml::String & xmefile);

  /// Save the file at the current location.
  bool save (void) const;

  /// Close the project.
  void close (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Project & operator = (const Project & proj);

  /**
   * Get the name of the object.
   *
   * @return        The name of the object.
   */
  const XMLCh * name (void) const;

  /**
   * Set the name of the project.
   *
   * @param[in]     n         Name of the element.
   */
  void name (const GAME::Xml::String & n);

  /**
   * Set the comment of the project.
   *
   * @param[in]     n         Name of the element.
   */
  void comment (const GAME::Xml::String & c);
  const XMLCh * comment (void) const;

  /**
   * Set the author of the project.
   *
   * @param[in]     n         Name of the element.
   */
  void author (const GAME::Xml::String & a);
  const XMLCh * author (void) const;

  /**
   * Test objects for equality.
   *
   * @param[in]     rhs       Right-hand side of operator
   * @retval        true      Objects are equal
   * @retval        false     Objects are not equal
   */
  bool operator == (const Project & rhs) const;

  /**
   * Test objects for inequality.
   *
   * @param[in]     rhs       Right-hand side of operator
   * @retval        true      Objects are not equal
   * @retval        false     Objects are equal
   */
  bool operator != (const Project & rhs) const;

  /**
   * Get the root folder for the project.
   *
   * @return        The root folder.
   */
  Folder root_folder (void) const;

  /**
   * Test if the project is NIL.
   *
   * @return        true          Project is NIL
   * @return        false         Project is not NIL.
   */
  bool is_nil (void) const;

  Library attach_library (const GAME::Xml::String & library);

  Library attach_library (const GAME::Xml::String & as_name,
                          const GAME::Xml::String & library);

  size_t attached_libraries (std::vector <Library> & libs);

  const Configuration * configuration (void) const;

private:
  static const GAME::Xml::String TAGNAME;
  static const GAME::Xml::String DTD;
  static const GAME::Xml::String XML_VERSION;
  static const GAME::Xml::String ELEMENT_NAME;
  static const GAME::Xml::String ELEMENT_AUTHOR;
  static const GAME::Xml::String ELEMENT_COMMENT;
  static const GAME::Xml::String ROOT_FOLDER;
  static const GAME::Xml::String ATTR_LIBREF;

  /**
   * Initializing constructor
   *
   * @param[in]     proj          Root element of the project.
   */
  Project (xercesc::DOMDocument * proj,
           const Configuration * config = GLOBAL_CONFIG::instance ());

  // Implementation of the save method.
  bool save_i (const GAME::Xml::String & xmefile) const;

  /// The XML document for the project.
  xercesc::DOMDocument * doc_;

  /// Location of the project.
  GAME::Xml::String xmefile_;

  /// The project's configuration.
  const Configuration * config_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Project.inl"
#endif

#endif  // !defined _GAME_XME_PROJECT_H_
