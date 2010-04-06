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

#include "Folder.h"

namespace GME
{
namespace XME
{
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
  static Project _create (const std::string & xmefile,
                          const std::string & paradigm,
                          const std::string & guid);

  /**
   * Open an existing file.
   *
   * @paramp[in]
   */
  static Project _open (const ::Utils::XStr & location,
                        const ::Utils::XStr & schema);

  /// Default constructor.
  Project (void);

  /**
   * Initializing constructor
   *
   * @param[in]     proj          Root element of the project.
   */
  Project (xercesc::DOMDocument * proj, bool validate);

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
  bool save (const std::string & xmefile);

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
  void name (const ::Utils::XStr & n);

  /**
   * Set the comment of the project.
   *
   * @param[in]     n         Name of the element.
   */
  void comment (const ::Utils::XStr & c);
  const XMLCh * comment (void) const;

  /**
   * Set the author of the project.
   *
   * @param[in]     n         Name of the element.
   */
  void author (const ::Utils::XStr & a);
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

  /// Release control of the wrapped DOMElement.
  xercesc::DOMDocument * release (void);

  /**
   * Attach to an existing XML document.
   *
   * @param[in]     proj        Target project
   * @param[in]     validate    Validate XML document is project
   */
  void attach (xercesc::DOMDocument * proj, bool validate);

  /**
   * Get the root folder for the project.
   *
   * @return        The root folder.
   */
  Folder root_folder (void) const;

private:
  static const ::Utils::XStr TAGNAME;
  static const ::Utils::XStr DTD;
  static const ::Utils::XStr XML_VERSION;
  static const ::Utils::XStr ELEMENT_NAME;
  static const ::Utils::XStr ELEMENT_AUTHOR;
  static const ::Utils::XStr ELEMENT_COMMENT;

  // Implementation of the save method.
  bool save_i (const std::string & xmefile) const;

  /// The XML document for the project.
  xercesc::DOMDocument * doc_;

  /// Location of the project.
  std::string xmefile_;
};

}
}

#if defined (__GME_INLINE__)
#include "Project.inl"
#endif

#endif  // !defined _GAME_XME_PROJECT_H_
