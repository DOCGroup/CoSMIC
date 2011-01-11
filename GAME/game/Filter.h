// -*- C++ -*-

//=============================================================================
/**
 * @file      Filter.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_FILTER_H_
#define _GME_FILTER_H_

#include "Project.h"

namespace GAME
{
// Forward decl.
class Project;

/**
 * @class Filter
 *
 * Help class for filter objects in a project. The main goal of the
 * filter to the perform a recursive search based on where it starts,
 * which can be the project, model, or folder.
 */
class GAME_Export Filter
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       project         Owner of the filter.
   */
  Filter (Project project);

  /// Destructor.
  ~Filter (void);

  /**
   * Apply the filter. The elements that match the filter are
   * returned in \a result. This perform a recursive search of the
   * entire project.
   *
   * @param[in]     result        Number of elements in result.
   */
  size_t apply (std::vector <FCO> & result) const;

  /**
   * @overloaded
   *
   * Performs a recursive search starting at the specified model.
   */
  size_t apply (const Model_in & model, std::vector <FCO> & result);

  /**
   * @overloaded
   *
   * Performs a recursive search starting at the specified folder.
   */
  size_t apply (const Folder_in & folder, std::vector <FCO> & result);

  /**
   * Set the kind attribute for the filter.
   *
   * @param[in]       name        The kind value
   */
  void kind (const std::string & value);
  void kind (std::vector <std::string> & value);
  void kind (std::vector <Meta::FCO> & fcos);

  void name (const std::string & value);
  void name (std::vector <std::string> & value);

private:
  /// Reference to the project.
  GAME::Project project_;

  /// Pointer to the actual filter.
  ATL::CComPtr <IMgaFilter> filter_;
};

}

#endif  // !defined _GME_FILTER_H_
